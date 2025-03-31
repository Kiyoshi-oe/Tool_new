import { setPropItemMappings } from './parseUtils';
import { trackPropItemChanges, savePropItemChanges } from './fileOperations';
import path from 'path';

// Interface for propItem data mapping
interface PropItemMapping {
  [key: string]: { name: string; description: string; displayName: string };
}

export const parsePropItemFile = (content: string): PropItemMapping => {
  console.log("parsePropItemFile called with content length:", content.length);
  
  // Überprüfe auf nicht-standardmäßige Codierungen nur bei den ersten 1000 Zeichen
  const hasNonASCII = /[^\x00-\x7F]/.test(content.substring(0, 1000));
  if (hasNonASCII) {
    console.warn("Non-ASCII characters detected in propItem.txt.txt file. This may indicate an encoding issue.");
  }
  
  // Versuche verschiedene Zeilenenden und wähle das effektivste
  let lines;
  if (content.indexOf('\r\n') !== -1) {
    lines = content.split('\r\n');
    console.log("Using CRLF line endings, found", lines.length, "lines");
  } else if (content.indexOf('\n') !== -1) {
    lines = content.split('\n');
    console.log("Using LF line endings, found", lines.length, "lines");
  } else if (content.indexOf('\r') !== -1) {
    lines = content.split('\r');
    console.log("Using CR line endings, found", lines.length, "lines");
  } else {
    // Fallback für den unwahrscheinlichen Fall, dass keine Zeilenumbrüche gefunden werden
    lines = [content];
    console.warn("No line breaks found, treating entire content as single line");
  }
  
  // Begrenzte Beispielausgabe nur für Diagnose
  if (lines.length > 0) {
    console.log("First line sample:", lines[0].substring(0, 100) + (lines[0].length > 100 ? '...' : ''));
  }
  
  const mappings: PropItemMapping = {};
  
  // BOM entfernen, wenn vorhanden
  let startIndex = 0;
  if (lines.length > 0 && (lines[0].charCodeAt(0) === 0xFEFF || lines[0].startsWith("\uFEFF"))) {
    console.log("BOM detected, removing...");
    lines[0] = lines[0].substring(1);
  }
  
  // Verarbeitung in Chunks
  const chunkSize = 5000;
  const totalChunks = Math.ceil(lines.length / chunkSize);
  
  for (let chunkIndex = 0; chunkIndex < totalChunks; chunkIndex++) {
    const startLine = chunkIndex * chunkSize;
    const endLine = Math.min(startLine + chunkSize, lines.length);
    
    if (chunkIndex === 0 || chunkIndex === totalChunks - 1 || chunkIndex % 5 === 0) {
      console.log(`Processing chunk ${chunkIndex + 1}/${totalChunks} (lines ${startLine}-${endLine})`);
    }
    
    for (let i = startLine; i < endLine; i++) {
      const line = lines[i].trim();
      if (!line) continue;
      
      // Problematische Zeichen entfernen
      const cleanedLine = line.replace(/[\uFEFF\u0000-\u0008\u000B\u000C\u000E-\u001F]/g, "");
      
      // Teile die Zeile nach Tab-Zeichen oder Leerzeichen
      let parts: string[] = [];
      
      // Entferne zusätzliche Leerzeichen am Anfang und Ende
      const trimmedLine = cleanedLine.trim();
      
      // Versuche verschiedene Parsing-Methoden
      if (trimmedLine.includes('\t')) {
        // Tab-getrennte Werte
        parts = trimmedLine.split('\t');
      } else {
        // Suche nach der ID und dem Rest mit regulärem Ausdruck
        // Berücksichtige verschiedene Textformate (mit und ohne Klammern)
        const match = trimmedLine.match(/^(IDS_PROPITEM_TXT_\d+)\s+(.+)$/);
        if (match) {
          const [, id, rest] = match;
          parts = [id.trim(), rest.trim()];
          
          // Debug-Ausgabe für problematische IDs
          if (id.includes("007342")) {
            console.log("Found problematic ID:", {
              originalLine: trimmedLine,
              parsedId: id,
              parsedValue: rest,
              parts
            });
          }
        }
      }
      
      if (parts.length < 2) continue;
      
      const id = parts[0].trim();
      const value = parts[1].trim();
      
      if (!value) continue;
      
      // Extrahiere den numerischen Teil der ID
      if (id.includes("IDS_PROPITEM_TXT_")) {
        const numericPart = id.replace(/.*IDS_PROPITEM_TXT_/, "");
        const idNumber = parseInt(numericPart, 10);
        
        if (isNaN(idNumber)) {
          console.warn(`Invalid numeric part in ID: ${id}`);
          continue;
        }
        
        // Prüfe, ob dies ein Name (gerade) oder eine Beschreibung (ungerade) ist
        if (idNumber % 2 === 0) { // Gerade Zahl - Name
          // Stelle sicher, dass die ID im korrekten Format ist
          const formattedId = `IDS_PROPITEM_TXT_${idNumber.toString().padStart(6, '0')}`;
          
          // Speichere das Mapping
          mappings[formattedId] = {
            name: formattedId,
            displayName: value,
            description: ""
          };
          
          // Speichere auch die ursprüngliche ID als Mapping
          if (id !== formattedId) {
            mappings[id] = {
              name: id,
              displayName: value,
              description: ""
            };
          }
        } else { // Ungerade Zahl - Beschreibung
          // Finde die zugehörige ID (vorherige gerade Zahl)
          const nameId = `IDS_PROPITEM_TXT_${(idNumber - 1).toString().padStart(6, '0')}`;
          
          if (mappings[nameId]) {
            mappings[nameId].description = value;
          } else {
            // Erstelle einen Platzhalter-Eintrag für die Beschreibung
            mappings[id] = {
              name: id,
              displayName: id, // Verwende ID als Fallback
              description: value
            };
          }
        }
      }
    }
    
    // Gib dem Browser Zeit zum Atmen nach jedem Chunk
    if (chunkIndex % 3 === 2 && chunkIndex < totalChunks - 1) {
      console.log(`Processed ${Object.keys(mappings).length} mappings so far...`);
    }
  }
  
  const mappingCount = Object.keys(mappings).length;
  console.log(`✅ PropItem Mappings loaded: ${mappingCount}`);
  
  // Stichprobenartige Überprüfung wichtiger Mappings
  const criticalItems = [
    "IDS_PROPITEM_TXT_000124",
    "IDS_PROPITEM_TXT_007342",
    "IDS_PROPITEM_TXT_011634"
  ];
  
  console.log("Checking critical items in mappings:");
  criticalItems.forEach(id => {
    if (mappings[id]) {
      console.log(`Found critical item ${id}: ${mappings[id].displayName}`);
    } else {
      console.warn(`❌ Critical item not found: ${id}`);
      // Versuche alternative Formatierung
      const altId = id.replace(/IDS_PROPITEM_TXT_(\d+)/, (_, num) => 
        `IDS_PROPITEM_TXT_${parseInt(num).toString().padStart(6, '0')}`
      );
      if (mappings[altId]) {
        console.log(`Found critical item with alternative format ${altId}: ${mappings[altId].displayName}`);
      } else {
        console.warn(`❌ Critical item not found with alternative format: ${altId}`);
      }
    }
  });
  
  // Cache the mappings for future use
  setPropItemMappings(mappings);
  return mappings;
};

/**
 * Aktualisiert die Eigenschaften eines propItem-Eintrags
 * @param item Das zu aktualisierende Item
 * @param displayName Der neue Anzeigename
 * @param description Die neue Beschreibung
 * @returns Das aktualisierte Item
 */
export const updatePropItemProperties = (
  item: any,
  displayName: string,
  description: string
): any => {
  if (!item || !item.data || !item.data.szName) {
    console.error("Ungültiges Item für UpdatePropItemProperties:", item);
    throw new Error("Item enthält keine gültige szName-Eigenschaft");
  }

  const itemId = item.data.szName;
  const itemName = item.name || "Unknown Item";

  console.log(`PropItemUtils: Aktualisiere Item ${itemName} (${itemId})`);
  console.log(`  Neuer Name: "${displayName}"`);
  console.log(`  Neue Beschreibung: "${description.substring(0, 30)}${description.length > 30 ? '...' : ''}"`);

  // Format-Check für ID
  if (!itemId.match(/IDS_PROPITEM_TXT_\d+/)) {
    console.error(`Ungültiges ID-Format: ${itemId}`);
  }

  // Stelle sicher, dass die ID korrekt formatiert ist
  const idMatch = itemId.match(/IDS_PROPITEM_TXT_(\d+)/);
  if (idMatch) {
    const baseId = parseInt(idMatch[1], 10);
    if (!isNaN(baseId)) {
      const paddedId = baseId.toString().padStart(6, '0');
      const expectedId = `IDS_PROPITEM_TXT_${paddedId}`;
      if (itemId !== expectedId) {
        console.warn(`ID Format könnte Probleme verursachen: ${itemId} vs erwartet ${expectedId}`);
      }
    }
  }

  // Aktualisiere die lokalen Item-Eigenschaften
  const updatedItem = {
    ...item,
    displayName,
    description
  };

  // Verfolge die Änderungen für späteres Speichern
  try {
    // Verbesserte Version mit Fehlerprotokollierung und Rückfallmechanismus
    trackPropItemChanges(itemId, itemName, displayName, description);
    
    // Markiere explizit, dass dieses Item als modifiziert betrachtet werden soll,
    // auch wenn es nicht im aktuellen Tab geöffnet ist
    markItemAsModified(itemId, displayName, description);
    
    // Markiere auch die Spec_Item.txt als modifiziert, falls sie es noch nicht ist
    try {
      const { trackModifiedFile } = require('./fileOperations');
      
      // Erstelle einfachen Platzhalter für Spec_Item.txt, der anzeigt, dass eine Änderung vorgenommen wurde
      const specItemPlaceholder = JSON.stringify({
        item: {
          id: itemId,
          name: itemName,
          displayName: displayName,
          description: description
        },
        isSpecItemModification: true,
        modificationTime: Date.now()
      });
      
      trackModifiedFile("Spec_Item.txt", specItemPlaceholder, {
        containsDisplayNameChanges: true,
        relatedItemId: itemId,
        modifiedTimestamp: Date.now()
      });
      
      console.log(`Spec_Item.txt wurde ebenfalls als modifiziert markiert für Item ${itemId}`);
    } catch (trackError) {
      console.error("Fehler beim Markieren von Spec_Item.txt als modifiziert:", trackError);
      // Fortfahren, auch wenn das Tracking fehlschlägt
    }
  } catch (error) {
    console.error("Fehler beim Tracking von PropItem-Änderungen:", error);
    // Fahre fort, auch wenn Tracking fehlschlägt
  }

  return updatedItem;
};

/**
 * Markiert ein Item als modifiziert, sodass es bei der nächsten Speicheroperation berücksichtigt wird
 * @param itemId Die ID des Items (IDS_PROPITEM_TXT_XXXXXX)
 * @param displayName Der Anzeigename des Items
 * @param description Die Beschreibung des Items
 */
export const markItemAsModified = (
  itemId: string,
  displayName: string,
  description: string
): void => {
  // Füge das Item zur Liste der modifizierten Items hinzu
  const modifiedItems = getModifiedItems();
  
  // Überprüfe, ob das Item bereits in der Liste ist
  const existingItemIndex = modifiedItems.findIndex(item => item.id === itemId);
  
  if (existingItemIndex >= 0) {
    // Aktualisiere das vorhandene Item
    modifiedItems[existingItemIndex].displayName = displayName;
    modifiedItems[existingItemIndex].description = description;
  } else {
    // Füge ein neues Item hinzu
    modifiedItems.push({
      id: itemId,
      displayName,
      description
    });
  }
  
  // Speichere die aktualisierte Liste
  saveModifiedItems(modifiedItems);
  
  console.log(`Item ${itemId} als modifiziert markiert, ${modifiedItems.length} Items insgesamt modifiziert`);
};

// Speicher für modifizierte Items zwischen Sitzungen
let modifiedItemsCache: Array<{id: string; displayName: string; description: string}> = [];

/**
 * Holt die Liste der modifizierten Items
 * @returns Liste der modifizierten Items
 */
export const getModifiedItems = (): Array<{id: string; displayName: string; description: string}> => {
  if (modifiedItemsCache.length > 0) {
    return [...modifiedItemsCache]; // Kopie zurückgeben, um unbeabsichtigte Änderungen zu vermeiden
  }
  
  try {
    // Versuche, aus dem localStorage zu laden
    const storedItems = localStorage.getItem('modifiedPropItems');
    if (storedItems) {
      modifiedItemsCache = JSON.parse(storedItems);
      return [...modifiedItemsCache];
    }
  } catch (error) {
    console.warn("Fehler beim Laden der modifizierten Items aus localStorage:", error);
  }
  
  return [];
};

/**
 * Speichert die Liste der modifizierten Items
 * @param items Liste der modifizierten Items
 */
export const saveModifiedItems = (items: Array<{id: string; displayName: string; description: string}>): void => {
  modifiedItemsCache = [...items]; // Kopie speichern
  
  try {
    // Im localStorage speichern für Persistenz zwischen Sitzungen
    localStorage.setItem('modifiedPropItems', JSON.stringify(modifiedItemsCache));
  } catch (error) {
    console.warn("Fehler beim Speichern der modifizierten Items im localStorage:", error);
  }
};

/**
 * Prüft, ob ein Item als modifiziert markiert ist
 * @param itemId Die ID des Items
 * @returns true, wenn das Item modifiziert wurde, sonst false
 */
export const isItemModified = (itemId: string): boolean => {
  const modifiedItems = getModifiedItems();
  return modifiedItems.some(item => item.id === itemId);
};

/**
 * Löscht alle modifizierten Items nach erfolgreicher Speicherung
 */
export const clearModifiedItems = (): void => {
  modifiedItemsCache = [];
  
  try {
    localStorage.removeItem('modifiedPropItems');
  } catch (error) {
    console.warn("Fehler beim Löschen der modifizierten Items aus localStorage:", error);
  }
};

/**
 * Speichert alle PropItem-Änderungen in die Datei propItem.txt.txt
 * @param items Das Array aller Items
 * @returns true bei Erfolg, false bei Fehler
 */
export const savePropItemsToFile = async (items: any[]): Promise<boolean> => {
  console.log("savePropItemsToFile aufgerufen mit", items?.length || 0, "Items");
  
  if (!items || items.length === 0) {
    console.warn("Keine Items zum Speichern vorhanden!");
    return false;
  }
  
  try {
    // Hole auch die Liste der manuell als modifiziert markierten Items
    const modifiedItems = getModifiedItems();
    console.log(`${modifiedItems.length} manuell als modifiziert markierte Items gefunden`);
    
    // Stelle sicher, dass alle manuell modifizierten Items berücksichtigt werden
    if (modifiedItems.length > 0) {
      // Für jedes modifizierte Item...
      for (const modifiedItem of modifiedItems) {
        // ...suche das entsprechende Item im items-Array
        const itemIndex = items.findIndex(item => 
          item.data && item.data.szName === modifiedItem.id
        );
        
        if (itemIndex >= 0) {
          // Wenn das Item gefunden wurde, aktualisiere die Werte
          items[itemIndex].displayName = modifiedItem.displayName;
          items[itemIndex].description = modifiedItem.description;
          console.log(`Item ${modifiedItem.id} in items-Array mit Werten aus modifiedItems aktualisiert`);
        } else {
          // Wenn das Item nicht gefunden wurde, füge ein temporäres Item hinzu
          console.log(`Item ${modifiedItem.id} nicht im items-Array gefunden, wird als temporäres Item hinzugefügt`);
          items.push({
            id: modifiedItem.id,
            name: modifiedItem.id,
            data: { szName: modifiedItem.id },
            displayName: modifiedItem.displayName,
            description: modifiedItem.description
          });
        }
      }
    }
    
    console.log("Serialisiere propItem-Änderungen für", items.length, "Items");
    
    // Importiere die benötigte Funktion aus fileOperations
    const { serializePropItemData, saveTextFile, trackModifiedFile } = await import('./fileOperations');
    const content = serializePropItemData(items);
    
    // Vor dem Speichern beide Dateien als modifiziert markieren
    trackModifiedFile("propItem.txt.txt", content, {
      isSaving: true,
      timestamp: Date.now()
    });
    
    // Speichere in die Datei propItem.txt.txt
    try {
      const success = await saveTextFile(content, "propItem.txt.txt");
      
      if (success) {
        console.log("PropItem.txt.txt erfolgreich gespeichert");
        // Lösche die modifizierten Items aus dem Cache
        clearModifiedItems();
        return true;
      } else {
        console.error("Fehler beim Speichern von PropItem.txt.txt");
        
        // Zeige eine Fehlermeldung an
        alert("Fehler beim Speichern von propItem.txt.txt. Ein weiterer Versuch wird unternommen.");
        
        // Bei Fehler trotzdem einen neuen Versuch mit saveToResourceFolder starten
        const retrySuccess = await saveToResourceFolder(content, "propItem.txt.txt");
        if (retrySuccess) {
          console.log("PropItem.txt.txt beim zweiten Versuch erfolgreich gespeichert");
          clearModifiedItems();
          return true;
        } else {
          alert("Das Speichern ist auch beim zweiten Versuch fehlgeschlagen. Bitte versuchen Sie es später erneut.");
        }
        
        return false;
      }
    } catch (saveError) {
      console.error("Fehler beim Speichern von PropItem.txt.txt:", saveError);
      
      // Zeige eine Fehlermeldung an
      alert(`Fehler beim Speichern: ${saveError.message}. Ein Wiederholungsversuch wird gestartet.`);
      
      // Versuche es mit der Backup-Methode
      try {
        const retrySuccess = await saveToResourceFolder(content, "propItem.txt.txt");
        if (retrySuccess) {
          console.log("PropItem.txt.txt über Backup-Methode erfolgreich gespeichert");
          clearModifiedItems();
          return true;
        } else {
          alert("Das Speichern ist auch über die Backup-Methode fehlgeschlagen. Bitte versuchen Sie es später erneut.");
        }
      } catch (retryError) {
        console.error("Auch Backup-Speichermethode fehlgeschlagen:", retryError);
        alert(`Beide Speichermethoden sind fehlgeschlagen: ${retryError.message}`);
      }
      
      return false;
    }
  } catch (error) {
    console.error("Fehler beim Serialisieren und Speichern der PropItem-Änderungen:", error);
    return false;
  }
};

// Helfer-Funktion, um PropItem-Änderungen zu speichern
const saveToResourceFolder = async (content: string, fileName: string): Promise<boolean> => {
  try {
    // Versuche direkt über die Electron-API zu speichern
    if ((window as any).electronAPI && (window as any).electronAPI.saveFile) {
      console.log("Versuche direktes Speichern über Electron API");
      
      const result = await (window as any).electronAPI.saveFile(
        fileName,
        content,
        path.join(process.cwd(), 'public', 'resource')
      );
      
      if (result.success) {
        console.log(`Datei ${fileName} erfolgreich gespeichert über Electron API`);
        return true;
      } else {
        console.error(`Fehler beim Speichern über Electron API: ${result.error}`);
      }
    }
    
    // Fallback auf den Import der saveTextFile-Funktion
    const { saveTextFile } = await import('./fileOperations');
    return await saveTextFile(content, fileName);
  } catch (error) {
    console.error(`Fehler beim Speichern von ${fileName}:`, error);
    alert(`Fehler beim Speichern von ${fileName}: ${error.message}`);
    return false;
  }
};
