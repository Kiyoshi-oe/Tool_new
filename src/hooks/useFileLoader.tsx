import { useState, useEffect } from "react";
import { FileData, LogEntry, ResourceItem } from "../types/fileTypes";
import { parseTextFile } from "../utils/file/parseUtils";
import { parsePropItemFile } from "../utils/file/propItemUtils";
import { loadDefineItemFile } from "../utils/file/defineItemParser";
import { loadMdlDynaFile } from "../utils/file/mdlDynaParser";
import { toast } from "sonner";

// Definiere den LoadingStatus-Typ
type LoadingStatus = 'idle' | 'loading' | 'partial' | 'complete' | 'error';

// Objekt mit PropItem-Mappings (ID zu DisplayName und Description)
interface PropItemMapping {
  displayName: string;
  description: string;
}

// Singleton für PropItem-Mappings
let propItemMappings: Record<string, PropItemMapping> = {};

// Funktion zum Setzen der PropItem-Mappings
const setGlobalPropItemMappings = (mappings: Record<string, PropItemMapping>) => {
  propItemMappings = mappings;
};

// Funktion zum Abrufen der PropItem-Mappings
const getGlobalPropItemMappings = () => propItemMappings;

// Leeres FileData Objekt für Initialisierung
const emptyFileData: FileData = {
  header: [],
  items: []
};

// Konstanten für das Caching
const CACHE_VERSION = '1.0.0';
const CACHE_KEY_SPEC_ITEMS = 'cached_spec_items';
const CACHE_KEY_PROP_ITEMS = 'cached_prop_items';
const CACHE_MAX_AGE_MS = 24 * 60 * 60 * 1000; // 24 Stunden

// Funktion zum Laden von Daten aus dem Cache
const loadFromCache = (cacheKey: string): any | null => {
  try {
    const cachedDataStr = localStorage.getItem(cacheKey);
    if (!cachedDataStr) return null;
    
    const cachedData = JSON.parse(cachedDataStr);
    
    // Prüfe, ob die Daten gültig sind (Version und Timestamp)
    if (!cachedData.version || cachedData.version !== CACHE_VERSION) {
      console.log(`Cache-Version ungültig: ${cachedData.version} vs. ${CACHE_VERSION}`);
      return null;
    }
    
    // Prüfe, ob die Daten nicht zu alt sind
    if (!cachedData.timestamp || Date.now() - cachedData.timestamp > CACHE_MAX_AGE_MS) {
      console.log('Cache-Daten sind veraltet, werden aktualisiert');
      return null;
    }
    
    console.log(`Erfolgreich aus Cache geladen: ${cacheKey}, ${cachedData.data?.items?.length || 0} Items`);
    return cachedData.data;
  } catch (error) {
    console.warn(`Fehler beim Laden aus Cache (${cacheKey}):`, error);
    return null;
  }
};

// Funktion zum Speichern von Daten im Cache
const saveToCache = (cacheKey: string, data: any): void => {
  try {
    const cacheData = {
      version: CACHE_VERSION,
      timestamp: Date.now(),
      data
    };
    
    localStorage.setItem(cacheKey, JSON.stringify(cacheData));
    console.log(`Daten erfolgreich im Cache gespeichert: ${cacheKey}`);
  } catch (error) {
    console.warn(`Fehler beim Speichern im Cache (${cacheKey}):`, error);
    // Bei Fehlern wie QuotaExceededError versuchen wir, Platz zu schaffen
    if (error instanceof DOMException && error.name === 'QuotaExceededError') {
      try {
        // Versuche, alte Caches zu löschen
        localStorage.removeItem(CACHE_KEY_SPEC_ITEMS);
        localStorage.removeItem(CACHE_KEY_PROP_ITEMS);
        console.log('Cache geleert, um Platz zu schaffen');
      } catch (clearError) {
        console.error('Konnte Cache nicht leeren:', clearError);
      }
    }
  }
};

export const useFileLoader = (
  settings: any = {},
  setLogEntries: React.Dispatch<React.SetStateAction<LogEntry[]>> = () => {}
) => {
  // Konstanten für das Caching
  const CACHE_VERSION = '1.0.0';
  const CACHE_KEY_SPEC_ITEMS = 'cached_spec_items';
  const CACHE_KEY_PROP_ITEMS = 'cached_prop_items';
  const CACHE_MAX_AGE_MS = 24 * 60 * 60 * 1000; // 24 Stunden
  
  const [fileData, setFileData] = useState<FileData | null>(null);
  const [loadingStatus, setLoadingStatus] = useState<LoadingStatus>('idle');
  const [loadProgress, setLoadProgress] = useState(0);
  const [fullSpecItemContent, setFullSpecItemContent] = useState<string | null>(null);
  const [fullPropItemContent, setFullPropItemContent] = useState<string | null>(null);
  const [specItemFullyLoaded, setSpecItemFullyLoaded] = useState(false);
  const [propItemFullyLoaded, setPropItemFullyLoaded] = useState(false);
  const [initialPropItemContent, setInitialPropItemContent] = useState<string | null>(null);
  
  // Load additional files when the component mounts
  useEffect(() => {
    loadAdditionalFiles();
  }, []);
  
  const loadAdditionalFiles = async () => {
    try {
      // Load defineItem.h
      await loadDefineItemFile();
      
      // Load mdlDyna.inc
      await loadMdlDynaFile();
    } catch (error) {
      console.error("Error loading additional files:", error);
    }
  };
  
  // Hilfsfunktion für einfachen Hash zur Inhaltsvergleich
  const computeSimpleHash = async (content: string): Promise<string> => {
    try {
      // Verwende nur einen Teil des Inhalts für Performance-Gründe
      const sampleContent = content.substring(0, 5000) + 
                          content.substring(content.length / 2, content.length / 2 + 5000) +
                          content.substring(content.length - 5000);
      
      // Verwende SubtleCrypto API für den Hash
      const encoder = new TextEncoder();
      const data = encoder.encode(sampleContent);
      const hashBuffer = await crypto.subtle.digest('SHA-1', data);
      
      // Konvertiere den Hash in einen Hex-String
      const hashArray = Array.from(new Uint8Array(hashBuffer));
      return hashArray.map(b => b.toString(16).padStart(2, '0')).join('');
    } catch (error) {
      // Fallback, wenn crypto nicht verfügbar ist
      console.warn("Hash-Berechnung fehlgeschlagen, verwende Fallback:", error);
      
      // Einfacher Fallback-Hash
      let hash = 0;
      for (let i = 0; i < Math.min(content.length, 10000); i++) {
        hash = ((hash << 5) - hash) + content.charCodeAt(i);
        hash |= 0; // Konvertiere zu 32-bit Integer
      }
      return hash.toString(16);
    }
  };

  // Hilfsfunktion zum Abschließen der Verarbeitung
  const finishProcessing = (data: FileData, hasPropItem: boolean) => {
    // Vorverarbeitung der Daten
    if (!data) {
      console.error("Fehler: Keine Daten zum Verarbeiten übergeben an finishProcessing");
      setLoadingStatus('error');
      toast.error("Fehler: Keine Daten zum Verarbeiten");
      return;
    }
    
    // Stelle sicher, dass data.items ein Array ist
    if (!data.items) {
      console.warn("Keine Items in den Daten gefunden, erstelle leeres Array");
      data.items = [];
    } else if (!Array.isArray(data.items)) {
      console.error("data.items ist kein Array:", data.items);
      data.items = [];
    }
    
    setLoadProgress(100);
    
    if (data.items.length > 0) {
      console.log("Items nach der Verarbeitung:", data.items.length);
      console.log("Erste Items:", data.items.slice(0, 3).map(
        item => `${item.id}: ${item.displayName || item.name} - ${item.description?.substring(0, 30) || 'Keine Beschreibung'}`
      ));
    } else {
      console.warn("Keine Items zum Anzeigen nach der Verarbeitung verfügbar");
      
      // Erstelle ein Dummy-Item, wenn keine Items vorhanden sind
      data.items = [{
        id: "no_items_found",
        name: "Keine Items gefunden",
        displayName: "Keine Items gefunden",
        description: "Die geladene Datei enthält keine gültigen Items",
        data: { dwItemKind1: "IK1_GENERAL" },
        effects: []
      }];
    }
    
    // Stelle sicher, dass jedes Item einen Kategorietyp hat
    data.items.forEach(item => {
      if (!item.data) {
        item.data = {};
      }
      
      // Wenn kein dwItemKind1 existiert, weise einen Standard-Wert zu
      if (!item.data.dwItemKind1) {
        // Fallback-Kategorisierung basierend auf ID
        const id = String(item.id || '').toLowerCase();
        const name = String(item.name || '').toLowerCase();
        
        if (id.includes("wea") || name.includes("sword") || name.includes("axe")) {
          item.data.dwItemKind1 = "IK1_WEAPON";
        } else if (id.includes("arm") || name.includes("armor")) {
          item.data.dwItemKind1 = "IK1_ARMOR";
        } else if (id.includes("chr") || name.includes("costume")) {
          item.data.dwItemKind1 = "IK1_PAPERDOLL";
        } else {
          // Default: Other Item
          item.data.dwItemKind1 = "IK1_GENERAL";
        }
      }
    });
    
    console.log("Setze Ladestatus auf 'complete' und aktualisiere Dateidaten mit", data.items.length, "Items");
    
    // Tiefer Klon der Daten erstellen, um Referenzprobleme zu vermeiden
    const clonedData = {
      ...data,
      items: JSON.parse(JSON.stringify(data.items))
    };
    
    // WICHTIG: ERST die Daten setzen, DANN den Ladestatus ändern!
    setFileData(clonedData);
    
    // Kurze Verzögerung, um sicherzustellen, dass die UI aktualisiert wird
    setTimeout(() => {
      // DANN den Ladestatus auf 'complete' setzen
      setLoadingStatus('complete');
      
      // Speichere die verarbeiteten Daten im Cache für zukünftige Verwendung
      saveToCache(CACHE_KEY_SPEC_ITEMS, clonedData);
      
      // Log-Eintrag erstellen
      if (settings.enableLogging) {
        const newLogEntry: LogEntry = {
          timestamp: Date.now(),
          itemId: "file-load",
          itemName: "File Load",
          field: "file",
          oldValue: "",
          newValue: `Loaded at ${new Date().toLocaleTimeString()}${hasPropItem ? ' with propItem mappings' : ''}`
        };
        setLogEntries(prev => [newLogEntry, ...prev]);
      }
      
      const itemCount = clonedData.items.length;
      toast.success(`Datei erfolgreich geladen mit ${itemCount} Einträgen${hasPropItem ? ' und Itemnamen aus propItem.txt.txt' : ''}`);
      
      // Load additional files after loading the main file
      loadAdditionalFiles();
    }, 0);
  };
  
  // Funktion zum Parsen und Laden der propItem.txt.txt Datei
  const parseAndLoadPropItem = (content: string) => {
    try {
      // Parse the propItem content
      const mappings = parsePropItemFile(content);
      setPropItemFullyLoaded(true);
      setFullPropItemContent(content);
      
      // Store the mappings for use in processLoadedContent
      setGlobalPropItemMappings(mappings);
    } catch (error) {
      console.error("Error parsing propItem file:", error);
      toast.error("Fehler beim Verarbeiten der propItem.txt.txt Datei");
    }
  };
  
  // Neue Funktion für die eigentliche Verarbeitung der geladenen Inhalte
  const processLoadedContent = (content: string, propItemContent: string | null) => {
    try {
      console.log("Processing loaded content with length:", content.length);
      
      // Begin der Fortschrittsanzeige
      setLoadProgress(10);
      
      // Performance-Optimierung: Threads blockieren nicht die UI
      // Verzögere die Verarbeitung für 100ms, damit die UI aktualisiert werden kann
      setTimeout(() => {
        try {
          setLoadProgress(30);
          
          // Hauptdaten verarbeiten
          const parsedData = parseTextFile(content);
          setLoadProgress(70);
          
          // Überprüfe, ob das Ergebnis der Datei-Analyse ein FileData-Objekt oder 
          // ein einfaches Header-Data-Objekt ist
          let data: FileData;
          
          if ('items' in parsedData) {
            // Es ist bereits ein FileData-Objekt
            data = parsedData as FileData;
            console.log("File data loaded:", data.items?.length || 0, "items");
          } else {
            // Es ist ein Header-Data-Objekt, konvertiere es zu FileData
            const { headers, data: rowData } = parsedData as { headers: string[], data: Record<string, string>[] };
            
            // Stelle sicher, dass mindestens ein Header existiert
            const safeHeaders = headers.length > 0 ? headers : ['Column1'];
            
            // Konvertiere das Format zu FileData mit sicheren Fallbacks
            data = {
              header: safeHeaders,
              items: rowData.map((row, index) => {
                // Sichere Default-Werte für wichtige Eigenschaften
                const firstColumn = safeHeaders[0];
                const itemName = row[firstColumn] || `Item_${index}`;
                
                const item: ResourceItem = {
                  id: `item_${index}`,
                  name: itemName,
                  displayName: itemName,
                  description: '',
                  data: row,
                  effects: []
                };
                return item;
              })
            };
            
            // Falls keine Items erstellt wurden, füge ein Dummy-Item hinzu
            if (data.items.length === 0 && rowData.length > 0) {
              console.warn("No items were created from data, adding a fallback item");
              data.items = [
                {
                  id: "fallback_1",
                  name: "Data Entry 1",
                  displayName: "Data Entry 1",
                  description: "Automatically created entry",
                  data: rowData[0] || {},
                  effects: []
                }
              ];
            }
          }
          
          setLoadProgress(80);
          
          // Verzögere den letzten Teil der Verarbeitung, um die UI zu aktualisieren
          setTimeout(() => {
            try {
              // Verarbeite die Items - sicher mit Nullchecks
              if (data.items && data.items.length > 0) {
                const propMappings = getGlobalPropItemMappings();
                const mappingCount = Object.keys(propMappings).length;
                console.log("Available mappings for items:", mappingCount);
                
                if (mappingCount > 0) {
                  // Performance-Optimierung: Vermeide Array-Neuallokation bei großen Arrays
                  const startTime = Date.now();
                  const itemCount = data.items.length;
                  
                  // Anwenden der Mappings auf Items
                  for (let i = 0; i < itemCount; i++) {
                    const item = data.items[i];
                    const idPropItem = item.data?.szName as string;
                    
                    if (idPropItem && propMappings[idPropItem]) {
                      item.displayName = propMappings[idPropItem].displayName || idPropItem;
                      item.description = propMappings[idPropItem].description || "";
                    }
                  }
                  
                  console.log(`Processed ${itemCount} items in ${Date.now() - startTime}ms`);
                }
              }
              
              finishProcessing(data, propItemContent !== null);
            } catch (error) {
              console.error("Error in final processing stage:", error);
              setLoadingStatus('error');
              toast.error("Fehler beim Verarbeiten der Datei");
            }
          }, 100);
        } catch (error) {
          console.error("Error processing file content:", error);
          setLoadingStatus('error');
          toast.error("Fehler beim Verarbeiten der Datei");
        }
      }, 100);
    } catch (error) {
      console.error("Error in processLoadedContent:", error);
      setLoadingStatus('error');
      toast.error("Fehler beim Verarbeiten der Datei");
    }
  };

  // Hauptfunktion zum Laden der Datei mit Caching-Unterstützung
  const handleLoadFile = async (content: string, propItemContent?: string) => {
    try {
      if (!content || content.trim() === '') {
        toast.error("Die Datei ist leer oder wurde nicht korrekt geladen");
        return;
      }
      
      // Beginne mit dem Ladezustand
      setLoadingStatus('loading');
      setLoadProgress(0);
      
      // Wichtig: Setze zuerst ein leeres FileData Objekt, damit die UI weiß, dass wir laden
      setFileData({
        header: [],
        items: [{
          id: "loading",
          name: "Lade...",
          displayName: "Lade Datei...",
          description: "Bitte warten während die Datei geladen wird",
          data: { dwItemKind1: "IK1_GENERAL" },
          effects: []
        }]
      });
      
      // Prüfe zunächst, ob wir einen Cache haben
      let cachedData = null;
      
      // Berechne einen Hash des Inhalts, um zu prüfen, ob die Datei sich geändert hat
      const contentHash = await computeSimpleHash(content);
      const currentCachedHash = localStorage.getItem(`${CACHE_KEY_SPEC_ITEMS}_hash`);
      
      // Wenn der Hash übereinstimmt, versuche den Cache zu verwenden
      if (contentHash === currentCachedHash) {
        console.log('Content-Hash stimmt überein, versuche Cache zu verwenden');
        cachedData = loadFromCache(CACHE_KEY_SPEC_ITEMS);
      } else {
        console.log('Content hat sich geändert oder wurde noch nie gecacht');
        localStorage.setItem(`${CACHE_KEY_SPEC_ITEMS}_hash`, contentHash);
      }
      
      if (cachedData) {
        console.log('Verwende gecachte Daten statt neuem Parsing', cachedData);
        setLoadProgress(50);
        
        // Aktualisiere den Zustand mit den Cache-Daten
        setFullSpecItemContent(content);
        setSpecItemFullyLoaded(true);
        
        // Wir verwenden den Cache für das Spec-Item, aber verarbeiten trotzdem propItemContent
        if (propItemContent) {
          setInitialPropItemContent(propItemContent);
          parseAndLoadPropItem(propItemContent);
        }
        
        // Verbesserte Fehlerprüfung für das gecachte Objekt
        if (!cachedData.items || !Array.isArray(cachedData.items)) {
          console.error("Ungültiges Cache-Objekt ohne Items-Array:", cachedData);
          toast.error("Cache-Daten ungültig, verarbeite Datei neu");
          
          // Setze den Status auf partial, damit die Verarbeitung neu gestartet wird
          setLoadingStatus('partial');
          processLoadedContent(content, propItemContent);
          return;
        }
        
        // Stelle sicher, dass jedes Item einen gültigen Typ hat (Nachbearbeitung)
        if (cachedData.items && cachedData.items.length > 0) {
          cachedData.items.forEach(item => {
            if (!item.data) item.data = {};
            if (!item.data.dwItemKind1) {
              // Setzen eines Standardtyps basierend auf der ID oder dem Namen
              const id = (item.id || '').toLowerCase();
              const name = (item.name || '').toLowerCase();
              
              if (id.includes('wea') || name.includes('sword')) {
                item.data.dwItemKind1 = "IK1_WEAPON";
              } else if (id.includes('arm') || name.includes('armor')) {
                item.data.dwItemKind1 = "IK1_ARMOR";
              } else {
                item.data.dwItemKind1 = "IK1_GENERAL";
              }
            }
          });
        }
        
        // Direkt die Daten setzen und dann den Status ändern
        setFileData(cachedData);
        setLoadingStatus('complete');
        setLoadProgress(100);
        
        console.log("Cache-Daten geladen und angezeigt:", cachedData.items?.length || 0, "Items");
        
        // Load additional files after loading the main file
        loadAdditionalFiles();
      } else {
        // Keine Cache-Daten vorhanden, verarbeite normal
        console.log('Keine Cache-Daten verfügbar, verarbeite Datei normal');
        setFullSpecItemContent(content);
        setSpecItemFullyLoaded(true);
        
        if (propItemContent) {
          setInitialPropItemContent(propItemContent);
          parseAndLoadPropItem(propItemContent);
        }
        
        // Setze den Status auf partial, damit die Verarbeitung gestartet wird
        setLoadingStatus('partial');
      }
    } catch (error) {
      console.error("Error in handleLoadFile:", error);
      setLoadingStatus('error');
      toast.error("Fehler beim Laden der Datei: " + (error instanceof Error ? error.message : String(error)));
    }
  };

  // Effekt zum Verarbeiten der Daten, wenn vollständig geladen
  useEffect(() => {
    // Überprüfe den Ladestatus und ob wir Daten haben
    if (loadingStatus === 'partial') {
      console.log("CheckingLoading Status - specItemFullyLoaded:", specItemFullyLoaded, 
                 "propItemFullyLoaded:", propItemFullyLoaded, 
                 "initialPropItemContent:", !!initialPropItemContent);
                 
      if (fullSpecItemContent) {
        // Wenn specItem vollständig geladen ist, verarbeiten wir es, unabhängig von propItem
        if (specItemFullyLoaded) {
          console.log("Spec item fully loaded - processing content");
          
          // Wir verarbeiten die Daten mit dem vorhandenen propItem-Inhalt, 
          // auch wenn dieser noch nicht vollständig geladen ist
          processLoadedContent(fullSpecItemContent, 
                             propItemFullyLoaded ? fullPropItemContent : null);
        }
      } else {
        console.log("No fullSpecItemContent available yet");
      }
    }
  }, [
    fullSpecItemContent, 
    fullPropItemContent, 
    specItemFullyLoaded, 
    propItemFullyLoaded, 
    loadingStatus,
    initialPropItemContent
  ]);

  // Implementierung der loadDefaultFiles-Funktion
  const loadDefaultFiles = async () => {
    try {
      console.log("Loading default files...");
      
      // Erzeuge Dummy-Daten für jeden Tab, die sofort angezeigt werden
      const dummyData: FileData = {
        header: ['ID', 'Name', 'Type'],
        items: [
          {
            id: "default_weapon_1",
            name: "Default Sword",
            displayName: "Default Sword",
            description: "A standard weapon",
            data: { dwItemKind1: "IK1_WEAPON", dwID: "default_1" },
            effects: []
          },
          {
            id: "default_armor_1",
            name: "Default Armor",
            displayName: "Default Armor",
            description: "A standard armor piece",
            data: { dwItemKind1: "IK1_ARMOR", dwID: "default_2" },
            effects: []
          },
          {
            id: "default_fashion_1",
            name: "Default Costume",
            displayName: "Default Costume",
            description: "A standard costume item",
            data: { dwItemKind1: "IK1_PAPERDOLL", dwID: "default_3" },
            effects: []
          },
          {
            id: "default_other_1",
            name: "Default Item",
            displayName: "Default Item",
            description: "A standard item",
            data: { dwItemKind1: "IK1_GENERAL", dwID: "default_4" },
            effects: []
          }
        ]
      };
      
      // Wichtig: ERST die Daten setzen, DANN den Status ändern
      console.log("Setze Standarddaten mit", dummyData.items.length, "Elementen");
      setFileData(dummyData);
      
      // Dann den Ladestatus setzen
      setLoadingStatus('complete');
      setLoadProgress(100);
      
      toast.success("Standarddateien erfolgreich geladen");
    } catch (error) {
      console.error("Error loading default files:", error);
      setLoadingStatus('error');
      toast.error("Fehler beim Laden der Standarddateien");
    }
  };

  return {
    fileData,
    handleLoadFile,
    loadDefaultFiles,
    loadingStatus,
    loadProgress,
    isLoading: loadingStatus === 'loading' || loadingStatus === 'partial'
  };
};
