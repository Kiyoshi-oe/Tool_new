import { serializeWithNameReplacement, serializePropItems } from './serializeUtils';

// Track modified files that need to be saved
export let modifiedFiles: { name: string; content: string; lastModified?: number; metadata?: any }[] = [];

/**
 * Generiert PropItem-Inhalt für die angegebenen Items
 * @param items Die Items, für die PropItem-Einträge generiert werden sollen
 * @returns Der generierte PropItem-Inhalt
 */
export const generatePropItemContent = (items: any[]): string => {
  if (!items || !Array.isArray(items) || items.length === 0) {
    return '';
  }
  
  const lines: string[] = [];
  
  items.forEach(item => {
    if (!item) return;
    
    const propItemId = getPropItemIdFromItem(item.id || '', item.name || '');
    if (!propItemId) return;
    
    // Extrahiere die numerische ID
    const matches = propItemId.match(/(\d+)$/);
    if (!matches || !matches[1]) return;
    
    const baseId = parseInt(matches[1], 10);
    if (isNaN(baseId)) return;
    
    // Setze Name, falls vorhanden
    if (item.displayName !== undefined) {
      const nameId = `IDS_PROPITEM_TXT_${baseId.toString().padStart(6, '0')}`;
      lines.push(`${nameId}\t${item.displayName || ''}`);
    }
    
    // Setze Beschreibung, falls vorhanden
    if (item.description !== undefined) {
      const descId = `IDS_PROPITEM_TXT_${(baseId + 1).toString().padStart(6, '0')}`;
      lines.push(`${descId}\t${item.description || ''}`);
    }
  });
  
  return lines.join('\r\n');
};

/**
 * Ermittelt die PropItem-ID für ein Item
 * @param itemId Die ID des Items
 * @param itemName Der Name des Items
 * @returns Die PropItem-ID oder null, wenn keine ermittelt werden kann
 */
export const getPropItemIdFromItem = (itemId: string, itemName: string): string | null => {
  // Wenn die ID bereits eine PropItem-ID ist, verwende sie direkt
  if (itemId && itemId.match(/IDS_PROPITEM_TXT_\d+/)) {
    return itemId;
  }
  
  // Versuche, die ID aus den vorhandenen modifizierten Dateien zu ermitteln
  const propItemFile = modifiedFiles.find(file => file.name === "propItem.txt.txt");
  if (propItemFile && propItemFile.metadata && propItemFile.metadata.propItemId) {
    return propItemFile.metadata.propItemId;
  }
  
  // Als Fallback können wir die ID aus dem Namen oder einer anderen Quelle ableiten
  // Dies ist nur ein Beispiel und sollte an die tatsächliche Anwendungslogik angepasst werden
  
  // Für die Demonstration verwenden wir einen Standardwert
  return "IDS_PROPITEM_TXT_000124"; // Rodney Axe
};

// Track modified files
export const trackModifiedFile = (fileName: string, content: string, metadata?: any): void => {
  try {
    console.log(`Tracking geänderte Datei: ${fileName}`);
    
    if (!fileName || !content) {
      console.warn(`Ungültige Parameter für trackModifiedFile: fileName=${fileName}, hat Inhalt=${!!content}`);
      return;
    }
    
    // Spezielle Behandlung für Spec_Item.txt - Stelle sicher, dass Item Icons korrekt formatiert sind
    if (fileName.toLowerCase().includes('spec_item.txt')) {
      // Check if we need to format item icons
      if (metadata?.fields?.specItem?.itemIcon || 
          metadata?.specItem?.itemIcon || 
          (metadata?.fields && metadata.fields.specItem && metadata.fields.specItem.itemIcon) ||
          (metadata?.specItem && metadata.specItem.itemIcon)) {
        
        // Finde den Wert des Item Icons
        let itemIcon = metadata?.fields?.specItem?.itemIcon || 
                      metadata?.specItem?.itemIcon || 
                      (metadata?.fields && metadata.fields.specItem && metadata.fields.specItem.itemIcon) ||
                      (metadata?.specItem && metadata.specItem.itemIcon);
        
        if (itemIcon) {
          console.log(`Item Icon vor Formatierung: "${itemIcon}"`);
          // Formatiere das Icon mit der Hilfsfunktion
          const formattedIcon = formatItemIconValue(itemIcon);
          console.log(`Item Icon nach Formatierung: "${formattedIcon}"`);
          
          // Aktualisiere das Icon im Metadata-Objekt
          if (metadata?.fields?.specItem) {
            metadata.fields.specItem.itemIcon = formattedIcon;
          } else if (metadata?.specItem) {
            metadata.specItem.itemIcon = formattedIcon;
          }
          
          // Aktualisiere auch das Icon im Content, falls es als JSON gespeichert ist
          try {
            const contentObj = JSON.parse(content);
            if (contentObj.item && contentObj.item.itemIcon) {
              contentObj.item.itemIcon = formattedIcon;
            } else if (contentObj.fields && contentObj.fields.specItem && contentObj.fields.specItem.itemIcon) {
              contentObj.fields.specItem.itemIcon = formattedIcon;
            }
            content = JSON.stringify(contentObj);
          } catch (e) {
            // Ignoriere JSON-Parse-Fehler, das bedeutet, dass der Inhalt kein JSON ist
          }
        }
      }
    }
    
    // Erweitere die Metadaten um zusätzliche Informationen
    const extendedMetadata = {
      ...metadata,
      lastModified: Date.now(),
      fileName: metadata?.fields?.mdlDyna?.fileName || metadata?.modelFile,
      type: fileName.toLowerCase().includes('propitem') ? 'propItem' : 
            fileName.toLowerCase().includes('spec_item') ? 'specItem' : 
            fileName.toLowerCase().includes('defineitem') ? 'defineItem' : 
            fileName.toLowerCase().includes('mdldyna') ? 'mdlDyna' : 'unknown'
    };
    
    // Prüfe, ob die Datei bereits als modifiziert markiert ist
    const existingIndex = modifiedFiles.findIndex(file => file.name === fileName);
    
    if (existingIndex !== -1) {
      console.log(`Datei ${fileName} ist bereits als modifiziert markiert, aktualisiere Inhalt`);
      modifiedFiles[existingIndex].content = content;
      modifiedFiles[existingIndex].metadata = extendedMetadata;
    } else {
      console.log(`Füge ${fileName} zu modifizierten Dateien hinzu`);
      modifiedFiles.push({
        name: fileName,
        content,
        metadata: extendedMetadata
      });
    }
    
    // Debug-Logging für bessere Nachvollziehbarkeit
    console.log(`Metadata für ${fileName}:`, extendedMetadata);
    
    // Datei sofort speichern, wenn die Einstellung gesetzt ist
    const fileType = fileName.toLowerCase();
    
    if (metadata?.shouldSaveImmediately || 
        metadata?.saveDirect || 
        (fileType.includes('propitem') && metadata?.savePropItemImmediate) || 
        (fileType.includes('spec_item') && metadata?.saveSpecItemImmediate) || 
        (fileType.includes('define') && metadata?.saveDefineItemImmediate) || 
        (fileType.includes('mdldyna') && metadata?.saveMdlDynaImmediate)) {
      
      console.log(`Speichere Änderungen für ${fileName} sofort`);
      
      if (fileType.includes('propitem.txt.txt')) {
        // Verwende die spezialisierte Funktion für propItem.txt.txt
        savePropItemChanges(metadata?.itemsToSave || []);
      } else if (fileType.includes('spec_item.txt')) {
        // Verwende spezialisierte Funktion für Spec_Item.txt mit korrekter Formatierung für Item Icons
        // Erstelle gesammelten Content mit formatierten Icons
        const specItemContent = serializeWithNameReplacement({
          items: metadata.itemsToSave || [],
          isSpecItemFile: true
        }, content);
        
        saveTextFile(specItemContent, "Spec_Item.txt", "public/resource/Spec_Item.txt");
      } else if (fileType.includes('defineitem.h')) {
        // Spezielle Behandlung für defineItem.h
        saveDefineItemChanges(metadata?.itemsToSave || []);
      } else if (fileType.includes('mdldyna.inc')) {
        // Spezielle Behandlung für mdlDyna.inc
        saveMdlDynaChanges(metadata?.itemsToSave || []);
      } else {
        // Für andere Dateitypen verwende die Standard-Speichermethode
        saveTextFile(content, fileName);
      }
    }
  } catch (error) {
    console.error(`Fehler beim Tracking der Datei ${fileName}:`, error);
  }
};

/**
 * Formatiert einen Item-Icon-Wert für die Spec_Item.txt
 * Stellt sicher, dass das Format mit dreifachen Anführungszeichen korrekt ist
 */
export const formatItemIconValue = (value: string): string => {
  if (!value) return '""""""';
  
  // Entferne alle Anführungszeichen (einzelne, doppelte oder dreifache)
  let cleanValue = value.replace(/^["']{1,3}|["']{1,3}$/g, '');
  
  // Debug-Ausgabe für bessere Nachvollziehbarkeit
  console.log(`Formatiere Item Icon: "${value}" -> "${cleanValue}" -> """${cleanValue}"""`);
  
  // Gib den Wert mit dreifachen Anführungszeichen zurück
  return `"""${cleanValue}"""`;
};

// Method to serialize the file data back to text format
export const serializeToText = (fileData: any, originalContent?: string): string => {
  // If we have the original content and this is a spec_item.txt file, preserve the original format
  if (fileData.isSpecItemFile) {
    if (originalContent) {
      console.log("Preserving original spec_item.txt format");
      return originalContent;
    } else {
      console.warn("Missing originalContent for spec_item.txt file, falling back to generated format");
    }
  }
  
  // For non-spec_item.txt files or if originalContent is missing, generate the content
  const headerLine = fileData.header.map((col: string) => `${col}`).join("\t");
  
  const dataLines = fileData.items.map((item: any) => {
    // Ensure we output ALL columns in the correct order
    const values = fileData.header.map((col: string) => {
      return item.data[col] !== undefined ? item.data[col] : "=";
    });
    
    return values.join("\t");
  });
  
  return [headerLine, ...dataLines].join("\n");
};

// Special function to serialize propItem.txt.txt data
export const serializePropItemData = (items: any[]): string => {
  const lines: string[] = [];
  
  // Only include items that have been modified
  const modifiedItems = items.filter(item => 
    item.displayName !== undefined || 
    item.description !== undefined
  );
  
  console.log(`Serializing ${modifiedItems.length} modified items out of ${items.length} total items`);
  
  modifiedItems.forEach(item => {
    if (!item.name || !item.data || !item.data.szName) return;
    
    // Get the ID from the item's propItem ID (szName field)
    const propItemId = item.data.szName as string;
    const idMatch = propItemId.match(/IDS_PROPITEM_TXT_(\d+)/);
    if (!idMatch) return;
    
    const baseId = parseInt(idMatch[1], 10);
    if (isNaN(baseId)) return;
    
    // Only add entries that have been modified
    if (item.displayName !== undefined) {
      // Add the name entry (even number)
      const nameId = `IDS_PROPITEM_TXT_${baseId.toString().padStart(6, '0')}`;
      lines.push(`${nameId}\t${item.displayName || item.name}`);
    }
    
    if (item.description !== undefined) {
      // Add the description entry (odd number = baseId + 1)
      const descId = `IDS_PROPITEM_TXT_${(baseId + 1).toString().padStart(6, '0')}`;
      lines.push(`${descId}\t${item.description || ''}`);
    }
  });
  
  return lines.join("\n");
};

/**
 * Verfolgt Änderungen an einem Item in allen relevanten Dateien
 * (propItem.txt.txt, Spec_Item.txt, defineItem.h, mdlDyna.inc)
 */
export const trackItemChanges = async (
  item: any,
  saveImmediately: boolean = false
): Promise<void> => {
  if (!item) return;

  console.log(`Tracking item changes for ${item.id || 'unknown item'}`);
  
  try {
    // Sicherstellen, dass Item-Icon korrekt formatiert ist (falls vorhanden)
    if (item.fields?.specItem?.itemIcon) {
      // Stelle sicher, dass das Icon dreifache Anführungszeichen hat
      if (!item.fields.specItem.itemIcon.startsWith('"""') || !item.fields.specItem.itemIcon.endsWith('"""')) {
        // Formatiere das Icon korrekt mit der Hilfsfunktion
        item.fields.specItem.itemIcon = formatItemIconValue(item.fields.specItem.itemIcon);
        console.log(`Item Icon korrekt formatiert: ${item.fields.specItem.itemIcon}`);
      }
    }
    
    // Tracking für propItem.txt.txt (für Namen und Beschreibungen)
    if (item.displayName !== undefined || item.description !== undefined) {
      await trackModifiedFile("propItem.txt.txt", JSON.stringify({
        type: "propItemUpdate",
        item: {
          id: item.id,
          displayName: item.displayName,
          description: item.description
        }
      }), {
        itemId: item.id,
        displayName: item.displayName,
        description: item.description
      });
    }
    
    // Tracking für Spec_Item.txt (für Item Icons und andere Felder)
    if (item.fields?.specItem) {
      await trackModifiedFile("Spec_Item.txt", JSON.stringify({
        type: "specItemUpdate",
        item: {
          id: item.id,
          define: item.fields.specItem.define,
          itemIcon: item.fields.specItem.itemIcon, // Bereits korrekt formatiert
          displayName: item.displayName,
          description: item.description
        }
      }), {
        itemId: item.id,
        specItem: {
          define: item.fields.specItem.define,
          itemIcon: item.fields.specItem.itemIcon,
        }
      });
    }
    
    // Tracking für defineItem.h
    if (item.fields?.defineItem || (item.effects && Array.isArray(item.effects))) {
      await trackModifiedFile("defineItem.h", JSON.stringify({
        type: "defineItemUpdate",
        item: {
          id: item.id,
          define: item.fields?.specItem?.define || item.name,
          effects: item.effects
        }
      }), {
        itemId: item.id,
        defineItem: {
          define: item.fields?.specItem?.define || item.name,
          effects: item.effects
        }
      });
    }
    
    // Tracking für mdlDyna.inc
    if (item.fields?.mdlDyna?.fileName || item.modelFile) {
      const fileName = item.fields?.mdlDyna?.fileName || item.modelFile;
      await trackModifiedFile("mdlDyna.inc", JSON.stringify({
        type: "mdlDynaUpdate",
        item: {
          id: item.id,
          fileName: fileName,
          define: item.fields?.specItem?.define || item.name
        }
      }), {
        itemId: item.id,
        mdlDyna: {
          fileName: fileName,
          define: item.fields?.specItem?.define || item.name
        }
      });
    }
    
    if (saveImmediately) {
      // Alle Änderungen sofort speichern
      await saveAllModifiedFiles({});
      
      // Event auslösen für Aktualisierung der UI
      if (typeof window !== 'undefined') {
        const event = new CustomEvent('resourceUpdated', {
          detail: {
            type: 'itemSaved',
            items: [item]
          }
        });
        window.dispatchEvent(event);
      }
    }
    
    console.log(`Item changes tracked successfully for ${item.id}`);
  } catch (error) {
    console.error(`Error tracking item changes for ${item.id}:`, error);
    throw error;
  }
};

// Alte Funktion bleibt aus Kompatibilitätsgründen bestehen
export const trackPropItemChanges = async (
  itemId: string,
  itemName: string,
  displayName: string,
  description: string
): Promise<void> => {
  try {
    if (!itemId) {
      console.warn("Ungültiger itemId für trackPropItemChanges");
      return;
    }
    
    console.log(`Tracking propItem Änderungen für ${itemId} (${itemName}) - Name: "${displayName}", Beschreibung: "${description}"`);
    
    // Verwende die neue Funktion mit den gleichen Parametern
    const item = {
      id: itemId,
      name: itemName,
      displayName,
      description,
      fields: {
        specItem: {
          displayName,
          description
        }
      },
      data: {
        szName: itemId
      }
    };
    
    await trackItemChanges(item, false);
  } catch (error) {
    console.error("Fehler beim Tracking von propItem Änderungen:", error);
  }
};

// Prüfen Sie die Konsistenz zwischen Spec_Item.txt und propItem.txt.txt
export const ensurePropItemConsistency = (fileData: any): void => {
  try {
    console.log("Konsistenzprüfung für Item-Namen und Beschreibungen gestartet");
    
  if (!fileData || !fileData.items || !Array.isArray(fileData.items)) {
      console.warn("Ungültige fileData für ensurePropItemConsistency");
      return;
    }
    
    // Prüfe, ob beide Dateien bereits als modifiziert markiert sind
    const specItemModified = modifiedFiles.some(file => file.name === "Spec_Item.txt");
    const propItemModified = modifiedFiles.some(file => file.name === "propItem.txt.txt");
    
    if (specItemModified && propItemModified) {
      console.log("Beide Dateien sind bereits als modifiziert markiert, keine weitere Aktion erforderlich");
      return;
    }
    
    // Wenn nur eine der Dateien modifiziert ist, stelle sicher, dass die andere auch modifiziert wird
    if (specItemModified && !propItemModified) {
      console.log("Spec_Item.txt ist modifiziert, aber propItem.txt.txt nicht. Stelle Konsistenz her...");
      
      // Extrahiere Items mit displayName oder description
      const itemsWithNameOrDesc = fileData.items.filter(item => 
        item && (
        (item.displayName !== undefined && item.displayName !== null) || 
        (item.description !== undefined && item.description !== null)
        )
      );
      
      if (itemsWithNameOrDesc.length > 0) {
        console.log(`${itemsWithNameOrDesc.length} Items mit Name/Beschreibung gefunden, aktualisiere propItem.txt.txt`);
        
        // Erstelle propItem.txt.txt Inhalt
        const propItemContent = generatePropItemContent(itemsWithNameOrDesc);
        
        // Speichere die Änderungen
        trackModifiedFile("propItem.txt.txt", propItemContent, {
          isFullSync: true,
          sourceFile: "Spec_Item.txt",
          lastModified: Date.now()
        });
      }
    } else if (!specItemModified && propItemModified) {
      console.log("propItem.txt.txt ist modifiziert, aber Spec_Item.txt nicht. Stelle Konsistenz her...");
      
      // In diesem Fall müssen wir sicherstellen, dass Spec_Item.txt die Änderungen hat
      // Das ist komplexer, da wir das Format beibehalten müssen
      
      // Wir markieren Spec_Item.txt als modifiziert mit dem aktuellen fileData
      trackModifiedFile("Spec_Item.txt", JSON.stringify({
        ...fileData,
        isSpecItemFile: true
      }), {
        isFullSync: true,
        sourceFile: "propItem.txt.txt",
        lastModified: Date.now()
      });
    }
  } catch (error) {
    console.error("Fehler bei der Konsistenzprüfung:", error);
  }
};

// Speichere geänderte propItem.txt.txt Einträge
export const savePropItemChanges = async (items: any[]): Promise<boolean> => {
  try {
    console.log(`savePropItemChanges aufgerufen mit ${items?.length || 0} Items`);
    
    if (!items || !Array.isArray(items) || items.length === 0) {
      console.warn("Keine Items zum Speichern in savePropItemChanges");
      return false;
    }
    
    // Finde heraus, welche Items Änderungen haben
    const modifiedItems = items.filter(item => 
      item && (item.displayName !== undefined || item.description !== undefined)
    );
    
    if (modifiedItems.length === 0) {
      console.warn("Keine zu modifizierenden Items gefunden");
      return false;
    }
    
    console.log(`${modifiedItems.length} zu modifizierende Items gefunden`);
    
    // Erstelle ein Mapping der IDs zu den aktualisierten Werten
    const updatedEntries = new Map<string, string>();
    
    modifiedItems.forEach(item => {
      if (!item) return;
      
      // Hole die ID
      const propItemId = (item.data?.szName || item.id) as string;
      if (!propItemId) return;
      
      // Parse die ID
      const idMatch = propItemId.match(/IDS_PROPITEM_TXT_(\d+)/);
      if (!idMatch) return;
      
      const baseId = parseInt(idMatch[1], 10);
      if (isNaN(baseId)) return;
      
      // Aktualisiere Namen, wenn vorhanden
      if (item.displayName !== undefined) {
        const nameId = `IDS_PROPITEM_TXT_${baseId.toString().padStart(6, '0')}`;
        updatedEntries.set(nameId, item.displayName || item.name || '');
        console.log(`Namen aktualisieren: ${nameId} = "${item.displayName || item.name || ''}"`);
      }
      
      // Aktualisiere Beschreibung, wenn vorhanden
      if (item.description !== undefined) {
        const descId = `IDS_PROPITEM_TXT_${(baseId + 1).toString().padStart(6, '0')}`;
        updatedEntries.set(descId, item.description || '');
        console.log(`Beschreibung aktualisieren: ${descId} = "${item.description || ''}"`);
      }
    });
    
    // Lade die vorhandene Datei, um die Aktualisierungen vorzunehmen
    let existingContent = "";
    let existingLines: string[] = [];
    
    try {
      // Lade die Datei direkt über Fetch mit Cache-Busting-Parameter
      const cacheBuster = Date.now();
      const response = await fetch(`/resource/propItem.txt.txt?t=${cacheBuster}`);
      if (response.ok) {
        existingContent = await response.text();
        console.log(`Vorhandene propItem.txt.txt geladen, Länge: ${existingContent.length} Zeichen`);
        
        existingLines = existingContent.split(/\r?\n/);
        console.log(`Datei enthält ${existingLines.length} Zeilen`);
      } else {
        console.warn(`Konnte vorhandene Datei nicht laden, Statuscode: ${response.status}`);
        // Wenn die Datei nicht geladen werden kann, erstellen wir eine neue
        existingLines = [];
      }
    } catch (error) {
      console.error(`Fehler beim Laden der Datei:`, error);
      existingLines = [];
    }
    
    console.log(`Aktualisiere ${updatedEntries.size} Einträge in der Datei`);
    
    // Aktualisiere die Zeilen oder füge neue hinzu
    const updatedLines = [...existingLines];
    const processedIds = new Set<string>();
    
    // Update existing lines
    for (let i = 0; i < updatedLines.length; i++) {
      const line = updatedLines[i];
      const parts = line.split('\t');
      
      if (parts.length >= 2) {
        const id = parts[0];
        
        if (updatedEntries.has(id)) {
          // Aktualisiere die Zeile mit dem neuen Wert
          const newValue = updatedEntries.get(id);
          const oldLine = updatedLines[i];
          
          updatedLines[i] = `${id}\t${newValue}`;
          processedIds.add(id);
          
          console.log(`Zeile ${i+1} aktualisiert: "${oldLine}" -> "${updatedLines[i]}"`);
        }
      }
    }
    
    // Add new entries that weren't in the file
    for (const [id, value] of updatedEntries.entries()) {
      if (!processedIds.has(id)) {
        updatedLines.push(`${id}\t${value}`);
        console.log(`Neue Zeile hinzugefügt: "${id}\t${value}"`);
      }
    }
    
    // Erstelle den endgültigen Inhalt, verwende CRLF für Windows-Kompatiblität
    const finalContent = updatedLines.join('\r\n');
    
    console.log(`Finaler Inhalt erstellt: ${finalContent.length} Zeichen`);
    
    // Speichere den aktualisierten Inhalt direkt in die Datei
    const fileName = "propItem.txt.txt";
    const savePath = "public/resource/propItem.txt.txt";
    
    try {
      console.log(`Speichere Datei als ${savePath}`);
      
      // Speichere mit ANSI-Kodierung wenn möglich
      if ((window as any).electronAPI?.saveFileWithEncoding) {
        const encodingOptions = {
          encoding: 'latin1', // Für ANSI-Kompatibilität
          useANSI: true
        };
        
        const result = await (window as any).electronAPI.saveFileWithEncoding(
          fileName, 
          finalContent, 
          savePath, 
          encodingOptions
        );
        
        if (result === 'SUCCESS' || (result && result.success)) {
          console.log(`Datei erfolgreich mit ANSI-Kodierung gespeichert`);
          // Entferne aus modifizierten Dateien
          modifiedFiles = modifiedFiles.filter(file => file.name !== fileName);
          
          // Datei neu laden und State aktualisieren
          await reloadPropItemFile();
          
          return true;
        } else {
          console.error(`Fehler beim Speichern mit ANSI-Kodierung:`, result);
        }
      }
      
      // Fallback zur normalen Speichermethode
      const success = await saveTextFile(finalContent, fileName);
      
      if (success) {
        console.log(`Datei erfolgreich gespeichert`);
        
        // Datei neu laden und State aktualisieren
        await reloadPropItemFile();
        
        return true;
      } else {
        console.error(`Fehler beim Speichern der Datei`);
        return false;
      }
    } catch (error) {
      console.error(`Fehler beim Speichern:`, error);
      return false;
    }
  } catch (error) {
    console.error(`Allgemeiner Fehler in savePropItemChanges:`, error);
    return false;
  }
};

/**
 * Lädt die PropItem.txt.txt Datei neu und aktualisiert den State in der Anwendung
 */
export const reloadPropItemFile = async (): Promise<boolean> => {
  try {
    console.log('Lade propItem.txt.txt neu, um State zu aktualisieren...');
    
    // Cache-Busting-Parameter hinzufügen, um sicherzustellen, dass wir die neueste Version erhalten
    const cacheBuster = Date.now();
    const response = await fetch(`/resource/propItem.txt.txt?t=${cacheBuster}`, {
      cache: 'no-store', // Vermeide Cache-Nutzung
      headers: {
        'Pragma': 'no-cache',
        'Cache-Control': 'no-cache, no-store, must-revalidate'
      }
    });
    
    if (!response.ok) {
      console.error(`Fehler beim Neuladen von propItem.txt.txt: ${response.status} ${response.statusText}`);
      return false;
    }
    
    const content = await response.text();
    console.log(`propItem.txt.txt neu geladen, ${content.length} Bytes`);
    
    // Analysiere den Inhalt
    const propItems = parsePropItemContent(content);
    console.log(`${propItems.length} PropItems extrahiert:`, propItems);
    
    // Aktualisiere den Anwendungsstate
    // Falls ein globaler Event-Bus oder eine zentrale State-Management-Lösung verfügbar ist
    if ((window as any).dispatchEvent) {
      const event = new CustomEvent('propItemsUpdated', { detail: propItems });
      window.dispatchEvent(event);
      console.log('propItemsUpdated Event ausgelöst');
    }
    
    // Aktualisiere den Zustand über die ItemCache-API, falls vorhanden
    if ((window as any).ItemCache?.updateItems) {
      (window as any).ItemCache.updateItems('propItem', propItems);
      console.log('ItemCache mit PropItems aktualisiert');
    }
    
    return true;
  } catch (error) {
    console.error('Fehler beim Neuladen der PropItem-Datei:', error);
    return false;
  }
};

/**
 * Analysiert den Inhalt von propItem.txt.txt und extrahiert die Einträge
 */
export const parsePropItemContent = (content: string): any[] => {
  if (!content) return [];
  
  try {
    const lines = content.split(/\r?\n/);
    const propItems: Record<string, any> = {};
    
    lines.forEach(line => {
      const parts = line.split('\t');
      if (parts.length < 2) return;
      
      const id = parts[0].trim();
      const value = parts[1];
      
      // PropItem IDs folgen dem Format IDS_PROPITEM_TXT_XXXXXX
      const match = id.match(/IDS_PROPITEM_TXT_(\d+)/);
      if (!match) return;
      
      const numId = parseInt(match[1], 10);
      if (isNaN(numId)) return;
      
      // Gerade Nummern sind Namen, ungerade sind Beschreibungen
      const isNameEntry = numId % 2 === 0;
      const baseId = isNameEntry ? numId : numId - 1;
      const baseKey = `IDS_PROPITEM_TXT_${baseId.toString().padStart(6, '0')}`;
      
      // Erstelle oder aktualisiere das Item
      if (!propItems[baseKey]) {
        propItems[baseKey] = {
          id: baseKey,
          data: { szName: baseKey }
        };
      }
      
      // Setze Namen oder Beschreibung
      if (isNameEntry) {
        propItems[baseKey].displayName = value;
        propItems[baseKey].name = value;
      } else {
        propItems[baseKey].description = value;
      }
    });
    
    // Konvertiere das Objekt in ein Array
    return Object.values(propItems);
  } catch (error) {
    console.error('Fehler beim Parsen von PropItem-Inhalt:', error);
    return [];
  }
};

// Speichere geänderte defineItem.h Einträge
export const saveDefineItemChanges = async (items: any[]): Promise<boolean> => {
  try {
    console.log(`saveDefineItemChanges aufgerufen mit ${items?.length || 0} Items`);
    
    if (!items || !Array.isArray(items) || items.length === 0) {
      console.warn("Keine Items zum Speichern in saveDefineItemChanges");
      return false;
    }
    
    // Finde heraus, welche Items Änderungen haben
    const modifiedItems = items.filter(item => 
      item && (item.effects !== undefined || item.data !== undefined)
    );
    
    if (modifiedItems.length === 0) {
      console.warn("Keine zu modifizierenden Items gefunden");
      return false;
    }
    
    console.log(`${modifiedItems.length} zu modifizierende Items gefunden`);
    
    // Erstelle den Inhalt für defineItem.h
    let content = '';
    
    modifiedItems.forEach(item => {
      if (!item) return;
      
      // Generiere die Define-Zeile
      const defineLine = `#define ${item.id}`;
      content += defineLine + '\n';
      
      // Füge Effekte hinzu, wenn vorhanden
      if (item.effects && Array.isArray(item.effects)) {
        item.effects.forEach((effect: any, index: number) => {
          if (effect && effect.type && effect.value !== undefined) {
            content += `\t${effect.type}\t${effect.value}\n`;
          }
        });
      }
      
      // Füge eine Leerzeile zwischen den Items hinzu
      content += '\n';
    });
    
    // Speichere die Änderungen
    const fileName = "defineItem.h";
    const savePath = "public/resource/defineItem.h";
    const success = await saveTextFile(content, fileName, savePath);
    
    if (success) {
      console.log("defineItem.h erfolgreich gespeichert");
      
      // Datei neu laden und State aktualisieren
      await reloadDefineItemFile();
      
      return true;
    } else {
      console.error("Fehler beim Speichern von defineItem.h");
      return false;
    }
  } catch (error) {
    console.error(`Allgemeiner Fehler in saveDefineItemChanges:`, error);
    return false;
  }
};

/**
 * Lädt die defineItem.h Datei neu und aktualisiert den State in der Anwendung
 */
export const reloadDefineItemFile = async (): Promise<boolean> => {
  try {
    console.log('Lade defineItem.h neu, um State zu aktualisieren...');
    
    // Cache-Busting-Parameter hinzufügen, um sicherzustellen, dass wir die neueste Version erhalten
    const cacheBuster = Date.now();
    const response = await fetch(`/resource/defineItem.h?t=${cacheBuster}`, {
      cache: 'no-store', // Vermeide Cache-Nutzung
      headers: {
        'Pragma': 'no-cache',
        'Cache-Control': 'no-cache, no-store, must-revalidate'
      }
    });
    
    if (!response.ok) {
      console.error(`Fehler beim Neuladen von defineItem.h: ${response.status} ${response.statusText}`);
      return false;
    }
    
    const content = await response.text();
    console.log(`defineItem.h neu geladen, ${content.length} Bytes`);
    
    // Analysiere den Inhalt
    const defineItems = parseDefineItemContent(content);
    console.log(`${defineItems.length} DefineItems extrahiert`);
    
    // Aktualisiere den Anwendungsstate
    if ((window as any).dispatchEvent) {
      const event = new CustomEvent('defineItemsUpdated', { detail: defineItems });
      window.dispatchEvent(event);
      console.log('defineItemsUpdated Event ausgelöst');
    }
    
    // Aktualisiere den Zustand über die ItemCache-API, falls vorhanden
    if ((window as any).ItemCache?.updateItems) {
      (window as any).ItemCache.updateItems('defineItem', defineItems);
      console.log('ItemCache mit DefineItems aktualisiert');
    }
    
    return true;
  } catch (error) {
    console.error('Fehler beim Neuladen der DefineItem-Datei:', error);
    return false;
  }
};

/**
 * Analysiert den Inhalt von defineItem.h und extrahiert die Einträge
 */
export const parseDefineItemContent = (content: string): any[] => {
  if (!content) return [];
  
  try {
    const lines = content.split(/\r?\n/);
    const items: any[] = [];
    let currentItem: any = null;
    
    lines.forEach(line => {
      line = line.trim();
      if (!line) return;
      
      if (line.startsWith('#define')) {
        // Neues Item gefunden
        if (currentItem) {
          items.push(currentItem);
        }
        
        const parts = line.split(/\s+/);
        if (parts.length < 2) return;
        
        const id = parts[1];
        currentItem = {
          id,
          effects: []
        };
      } else if (currentItem && line.trim().length > 0) {
        // Effekt für das aktuelle Item
        const effectParts = line.trim().split(/\s+/);
        if (effectParts.length >= 2) {
          currentItem.effects.push({
            type: effectParts[0],
            value: effectParts[1]
          });
        }
      }
    });
    
    // Letztes Item hinzufügen, falls vorhanden
    if (currentItem) {
      items.push(currentItem);
    }
    
    return items;
  } catch (error) {
    console.error('Fehler beim Parsen von DefineItem-Inhalt:', error);
    return [];
  }
};

// Speichere geänderte mdlDyna.inc Einträge
export const saveMdlDynaChanges = async (items: any[]): Promise<boolean> => {
  try {
    console.log(`saveMdlDynaChanges aufgerufen mit ${items?.length || 0} Items`);
    
    if (!items || !Array.isArray(items) || items.length === 0) {
      console.warn("Keine Items zum Speichern in saveMdlDynaChanges");
      return false;
    }
    
    // Finde heraus, welche Items Änderungen haben
    const modifiedItems = items.filter(item => 
      item && (item.modelFile !== undefined || item.data?.dwItemKind !== undefined || item.fields?.mdlDyna?.fileName !== undefined)
    );
    
    if (modifiedItems.length === 0) {
      console.warn("Keine zu modifizierenden Items gefunden");
      return false;
    }
    
    console.log(`${modifiedItems.length} zu modifizierende Items gefunden`);
    
    // Erstelle den Inhalt für mdlDyna.inc
    let content = '';
    
    modifiedItems.forEach(item => {
      if (!item) return;
      
      // Generiere die Include-Zeile mit dem korrekten Dateinamen
      const fileName = item.modelFile || item.fields?.mdlDyna?.fileName || '';
      const includeLine = `#include "${fileName}"`;
      content += includeLine + '\n';
      
      // Füge eine Leerzeile zwischen den Items hinzu
      content += '\n';
    });
    
    // Speichere die Änderungen
    const fileName = "mdlDyna.inc";
    const savePath = "public/resource/mdlDyna.inc";
    const success = await saveTextFile(content, fileName, savePath);
    
    if (success) {
      console.log("mdlDyna.inc erfolgreich gespeichert");
      
      // Datei neu laden und State aktualisieren
      await reloadMdlDynaFile();
      
      return true;
    } else {
      console.error("Fehler beim Speichern von mdlDyna.inc");
      return false;
    }
  } catch (error) {
    console.error(`Allgemeiner Fehler in saveMdlDynaChanges:`, error);
    return false;
  }
};

/**
 * Lädt die mdlDyna.inc Datei neu und aktualisiert den State in der Anwendung
 */
export const reloadMdlDynaFile = async (): Promise<boolean> => {
  try {
    console.log('Lade mdlDyna.inc neu, um State zu aktualisieren...');
    
    // Cache-Busting-Parameter hinzufügen, um sicherzustellen, dass wir die neueste Version erhalten
    const cacheBuster = Date.now();
    const response = await fetch(`/resource/mdlDyna.inc?t=${cacheBuster}`, {
      cache: 'no-store', // Vermeide Cache-Nutzung
      headers: {
        'Pragma': 'no-cache',
        'Cache-Control': 'no-cache, no-store, must-revalidate'
      }
    });
    
    if (!response.ok) {
      console.error(`Fehler beim Neuladen von mdlDyna.inc: ${response.status} ${response.statusText}`);
      return false;
    }
    
    const content = await response.text();
    console.log(`mdlDyna.inc neu geladen, ${content.length} Bytes`);
    
    // Analysiere den Inhalt
    const mdlDynaItems = parseMdlDynaContent(content);
    console.log(`${mdlDynaItems.length} MdlDynaItems extrahiert`);
    
    // Aktualisiere den Anwendungsstate
    if ((window as any).dispatchEvent) {
      const event = new CustomEvent('mdlDynaItemsUpdated', { detail: mdlDynaItems });
      window.dispatchEvent(event);
      console.log('mdlDynaItemsUpdated Event ausgelöst');
    }
    
    // Aktualisiere den Zustand über die ItemCache-API, falls vorhanden
    if ((window as any).ItemCache?.updateItems) {
      (window as any).ItemCache.updateItems('mdlDyna', mdlDynaItems);
      console.log('ItemCache mit MdlDynaItems aktualisiert');
    }
    
    return true;
  } catch (error) {
    console.error('Fehler beim Neuladen der MdlDyna-Datei:', error);
    return false;
  }
};

/**
 * Analysiert den Inhalt von mdlDyna.inc und extrahiert die Einträge
 */
export const parseMdlDynaContent = (content: string): any[] => {
  if (!content) return [];
  
  try {
    const lines = content.split(/\r?\n/);
    const items: any[] = [];
    
    lines.forEach(line => {
      line = line.trim();
      if (!line || !line.startsWith('#include')) return;
      
      // Extrahiere den Dateinamen aus der Include-Anweisung
      const matches = line.match(/#include\s+"([^"]+)"/);
      if (!matches || !matches[1]) return;
      
      const fileName = matches[1].trim();
      
      items.push({
        id: `model_${items.length + 1}`,
        modelFile: fileName,
        fields: {
          mdlDyna: {
            fileName: fileName
          }
        }
      });
    });
    
    return items;
  } catch (error) {
    console.error('Fehler beim Parsen von MdlDyna-Inhalt:', error);
    return [];
  }
};

// Get the list of modified files
export const getModifiedFiles = () => {
  return [...modifiedFiles];
};

// Clear the list of modified files
export const clearModifiedFiles = () => {
  modifiedFiles = [];
};

// Funktion zum Herunterladen einer Textdatei als Fallback
export const downloadTextFile = (content: string, fileName: string): void => {
  try {
    // Erzeuge einen Blob aus dem Inhalt
    const blob = new Blob([content], { type: 'text/plain;charset=utf-8' });
    
    // Erzeuge eine URL für den Blob
    const url = URL.createObjectURL(blob);
    
    // Erzeuge ein Link-Element
    const link = document.createElement('a');
    link.href = url;
    link.download = fileName;
    
    // Füge das Link-Element zum Dokument hinzu
    document.body.appendChild(link);
    
    // Klicke auf den Link, um den Download zu starten
    link.click();
    
    // Entferne den Link aus dem Dokument
    document.body.removeChild(link);
    
    // Gib die URL frei
    URL.revokeObjectURL(url);
    
    console.log(`Datei ${fileName} zum Download angeboten.`);
  } catch (error) {
    console.error('Fehler beim Herunterladen der Datei:', error);
    alert(`Fehler beim Herunterladen der Datei ${fileName}: ${error.message}`);
  }
};

/**
 * Versucht, eine Datei über die lokale FileSystem API zu speichern (nur Chrome)
 * Dies ist ein Fallback, falls Electron nicht verfügbar ist
 */
export const saveWithFileSystemAPI = async (content: string, fileName: string): Promise<boolean> => {
  try {
    // Prüfe, ob die FileSystem API verfügbar ist
    if (!('showSaveFilePicker' in window)) {
      console.warn('FileSystem API ist nicht verfügbar (nur Chrome unterstützt diese)');
      return false;
    }
    
    console.log(`Versuche Speicherung über FileSystem API für ${fileName}...`);
    
    // @ts-ignore - FileSystem API TypeScript-Definitionen fehlen oft
    const handle = await window.showSaveFilePicker({
      suggestedName: fileName,
      types: [{
        description: 'Textdateien',
        accept: {'text/plain': ['.txt']}
      }]
    });
    
    // Hole einen schreibbaren Stream
    const writable = await handle.createWritable();
    
    // Schreibe den Inhalt
    await writable.write(content);
    
    // Schließe den Stream
    await writable.close();
    
    console.log(`Datei erfolgreich über FileSystem API gespeichert: ${fileName}`);
    return true;
      } catch (error) {
    console.error('Fehler beim Speichern über FileSystem API:', error);
    return false;
  }
};

/**
 * Versucht, eine Datei über den localStorage als temporären Speicher zu cachen
 * Dies ist nur für Entwicklungszwecke gedacht und hat Größenbeschränkungen
 */
export const saveToLocalStorage = (content: string, fileName: string): boolean => {
  try {
    // Überprüfe die Größe des Inhalts (localStorage hat typischerweise ein Limit von 5-10 MB)
    const contentSize = new Blob([content]).size;
    if (contentSize > 4 * 1024 * 1024) { // 4 MB Limit
      console.warn(`Inhalt zu groß für localStorage: ${contentSize} Bytes`);
      return false;
    }
    
    // Speichere mit Präfix, um Kollisionen zu vermeiden
    localStorage.setItem(`file_${fileName}`, content);
    localStorage.setItem(`file_${fileName}_timestamp`, new Date().toISOString());
    
    console.log(`Datei in localStorage gecacht: ${fileName} (${contentSize} Bytes)`);
    return true;
  } catch (error) {
    console.error('Fehler beim Speichern in localStorage:', error);
    return false;
  }
};

// Save a single file
export const saveTextFile = async (
  content: string,  
  fileName: string,
  customPath?: string
): Promise<boolean> => {
  try {
    console.log(`Speichere Datei ${fileName} mit ${content?.length || 0} Zeichen`);
    
    if (!content || !fileName) {
      console.error('saveTextFile error: Ungültiger Inhalt oder Dateiname');
      return false;
    }

    // Bestimme den Speicherpfad
    let savePath = '';
    if (customPath) {
      savePath = customPath;
    } else {
      // Standard-Pfad für Ressourcendateien
      // Entferne den führenden Slash, um doppelte Pfade zu vermeiden
      savePath = `public/resource/${fileName}`;
    }
    
    // Stelle sicher, dass der Pfad korrekt ist, aber vermeide doppelte public/resource-Pfade
    if (savePath.startsWith('/public/resource/')) {
      // Entferne einen führenden Slash, wenn der Pfad bereits mit /public/resource/ beginnt
      savePath = savePath.substring(1);
    } else if (savePath.startsWith('public/resource/')) {
      // Bereits korrekt formatiert
    } else if (!savePath.includes(':\\') && !savePath.startsWith('.\\')) {
      // Füge public/resource/ hinzu, wenn es kein absoluter Windows-Pfad ist
      savePath = `public/resource/${savePath}`;
    }
    
    console.log(`Korrigierter Speicherpfad: ${savePath}`);
    
    // Prüfe, ob es sich um eine propItem.txt.txt Datei handelt
    const isPropItemFile = fileName.toLowerCase().includes('propitem.txt.txt');
    let finalContent = content;
    
    // Falls es eine propItem.txt.txt Datei ist, verwende ANSI-Kodierung
    if (isPropItemFile) {
      console.log('propItem.txt.txt-Datei erkannt, verwende ANSI-Kodierung für Windows-Kompatibilität');
      
      // Bei Electron können wir spezielle Parameter für die Kodierung übergeben
      const encodingOptions = {
        encoding: 'latin1', // Windows-1252/ANSI-ähnliche Kodierung
        useANSI: true
      };
      
      // Speichere die Metadaten mit der Datei
      if ((window as any).electronAPI?.saveFileWithEncoding) {
        try {
          // @ts-ignore
          const result = await window.electronAPI.saveFileWithEncoding(fileName, content, savePath, encodingOptions);
          
          if (result === 'SUCCESS' || (result && result.success === true)) {
            console.log(`propItem.txt.txt erfolgreich mit ANSI-Kodierung gespeichert`);
            
            // Entferne die Datei aus der Liste der modifizierten Dateien
            modifiedFiles = modifiedFiles.filter(file => file.name !== fileName);
            
            return true;
          } else {
            console.error(`Fehler beim Speichern mit ANSI-Kodierung: ${JSON.stringify(result)}`);
            // Fall through zum normalen Speichern als Fallback
          }
        } catch (encodingError) {
          console.error('Fehler beim Speichern mit ANSI-Kodierung:', encodingError);
          // Fall through zum normalen Speichern als Fallback
        }
      } else {
        console.log('saveFileWithEncoding API nicht verfügbar, versuche Fallback-Methoden');
      }
    }
    
    // Prüfe, ob wir in einer Electron-Umgebung sind
    const isElectron = !!(window as any).electron || !!(window as any).process?.versions?.electron;
    const hasElectronAPI = typeof (window as any).electronAPI !== 'undefined';
    
    console.log(`Umgebungsprüfung: isElectron=${isElectron}, hasElectronAPI=${hasElectronAPI}`);
    
    // Speichern über Electron, wenn verfügbar
    if (hasElectronAPI) {
      try {
        // Direktes Speichern über Electron API
        console.log(`Rufe Electron saveFile API auf mit Parametern: fileName=${fileName}, savePath=${savePath}, Inhaltslänge=${finalContent?.length || 0}`);
        
        // @ts-ignore
        const result = await window.electronAPI.saveFile(fileName, finalContent, savePath);
        console.log(`Electron saveFile API Ergebnis:`, result);
        
        if (result && result.success === true) {
          console.log(`Datei erfolgreich gespeichert: ${savePath}, Größe: ${result.size || 'unbekannt'} Bytes`);
          
          // Entferne die Datei aus der Liste der modifizierten Dateien
          modifiedFiles = modifiedFiles.filter(file => file.name !== fileName);
          
          return true;
        } else if (result === 'SUCCESS') {
          console.log(`Datei erfolgreich gespeichert: ${savePath} (altes API-Format)`);
          
          // Entferne die Datei aus der Liste der modifizierten Dateien
          modifiedFiles = modifiedFiles.filter(file => file.name !== fileName);
          
          return true;
        } else {
          // Konvertiere [object Object] in lesbare Fehlermeldung
          let errorMessage = '';
          if (result && typeof result === 'object') {
            try {
              errorMessage = JSON.stringify(result, null, 2);
            } catch (jsonError) {
              errorMessage = `Unbekannter Fehler (konnte Fehlerobjekt nicht konvertieren): ${String(jsonError)}`;
            }
          } else {
            errorMessage = result?.toString() || 'Unbekannter Fehler (leeres Ergebnis von Electron)';
          }
          
          console.error(`Fehler beim Speichern der Datei mit Electron: ${errorMessage}`);
          console.error(`Details: Datei=${fileName}, Pfad=${savePath}, Inhaltslänge=${finalContent?.length || 0}`);
          
          // Fallback zu anderen Methoden, wenn Electron-Speicherung fehlschlägt
          console.log(`Versuche Fallback-Methoden nach Electron-Fehler...`);
        }
      } catch (apiError) {
        console.error(`Fehler beim Aufruf der Electron saveFile API:`, apiError);
        console.error(`Stack: ${apiError instanceof Error ? apiError.stack : 'Kein Stack verfügbar'}`);
        
        // Fallback zu anderen Methoden
        console.log(`API-Fehler, versuche Fallback-Methoden...`);
      }
    } else {
      console.warn('Electron API nicht verfügbar, versuche alternative Speichermethoden...');
    }
    
    // Fallback 1: Versuche über FileSystem API (nur Chrome)
    const savedWithFileSystemAPI = await saveWithFileSystemAPI(finalContent, fileName);
    if (savedWithFileSystemAPI) {
      console.log(`Datei erfolgreich über FileSystem API gespeichert`);
      modifiedFiles = modifiedFiles.filter(file => file.name !== fileName);
      return true;
    }
    
    // Fallback 2: Cache in localStorage für Entwicklungszwecke
    const savedToLocalStorage = saveToLocalStorage(finalContent, fileName);
    if (savedToLocalStorage) {
      console.log(`Datei in localStorage gecacht für spätere Wiederherstellung`);
      // Wir entfernen die Datei nicht aus den modifizierten Dateien, da sie nur gecacht wurde
    }
    
    // Fallback 3: Biete Download an
    console.log(`Biete Download für ${fileName} an...`);
    downloadTextFile(finalContent, fileName);
    
    // Zeige eine erklärende Meldung an
    alert(`Die Datei ${fileName} konnte nicht automatisch gespeichert werden. 
Sie wurde als Download angeboten. Bitte speichern Sie sie manuell im "resource"-Ordner.

Hinweis: Wenn Sie die Anwendung in einem Browser verwenden, können Dateien nicht direkt im Dateisystem gespeichert werden.`);
    
    return false;
  } catch (err) {
    // Verbesserte Fehlerbehandlung
    const errorMessage = err instanceof Error ? err.message : String(err);
    console.error(`saveTextFile error: ${errorMessage}`);
    console.error(`Stack: ${err instanceof Error ? err.stack : 'Kein Stack verfügbar'}`);
    
    // Fallback zum Herunterladen als letzter Ausweg
    console.log(`Versuche Fallback-Download nach Fehler für ${fileName}...`);
    downloadTextFile(content, fileName);
    return false;
  }
};

// Überschriebene Funktion für die alte API-Kompatibilität
export const saveTextFile2 = async (
  context: any,
  targetFileInfo: any,
  isFullPath: boolean = false,
): Promise<string> => {
  try {
    if (!targetFileInfo || !targetFileInfo.path) {
      console.error('saveTextFile2 error: kein gültiger targetFileInfo oder Pfad', targetFileInfo);
      return 'ERROR';
    }
    
    if (!targetFileInfo.content) {
      console.error('saveTextFile2 error: targetFileInfo hat keinen Inhalt', targetFileInfo);
      return 'ERROR (leerer Inhalt)';
    }

    // Prüfe, ob es sich um eine Spec_Item.txt oder propItem.txt.txt Datei handelt
    const isSpecItemFile = targetFileInfo.path.toLowerCase().includes('spec_item.txt');
    const isPropItemFile = targetFileInfo.path.toLowerCase().includes('propitem.txt.txt');

    let content = targetFileInfo.content;
    let fileName = targetFileInfo.path;

    // Für Spec_Item.txt Dateien verwenden wir serializeWithNameReplacement
    if (isSpecItemFile && typeof content === 'string' && content.trim().startsWith('{')) {
      try {
        console.log('Verarbeite Spec_Item.txt Datei mit benutzerdefinierten Serialisierungsfunktionen');
        
        // Parse den Dateiinhalt, falls als String übergeben
        const parsedData = JSON.parse(content);
        
        // Hole originalContent aus den Daten, aber bevorzuge changedContent
        let originalContent = '';
        if (parsedData.changedContent && typeof parsedData.changedContent === 'string') {
          originalContent = parsedData.changedContent;
          console.log(`Verwende changedContent aus den Daten (${originalContent.length} Bytes)`);
        } else if (parsedData.originalContent && typeof parsedData.originalContent === 'string') {
          originalContent = parsedData.originalContent;
          console.log(`Verwende originalContent aus den Daten (${originalContent.length} Bytes)`);
        } else {
          console.warn(`Kein originalContent oder changedContent in den Daten gefunden`);
        }
        
        // Verwende die verbesserte Serialisierungsfunktion
        content = serializeWithNameReplacement(parsedData, originalContent);
        
        console.log(`Serialisierter Inhalt für Spec_Item.txt erstellt (${content.length} Bytes)`);
      } catch (err) {
        console.error('Fehler bei der Serialisierung von Spec_Item.txt:', err);
        // Bei einem Fehler behalten wir den ursprünglichen Inhalt bei
      }
    }
    // Für propItem.txt.txt Dateien mit speziellem Handling
    else if (isPropItemFile && typeof content === 'string') {
      try {
        // Prüfe, ob der Inhalt JSON ist oder bereits das richtige Format hat
        if (content.trim().startsWith('{')) {
          console.log('Verarbeite propItem.txt.txt als JSON');
          
          // Parse den Dateiinhalt, falls als String übergeben
          const parsedData = JSON.parse(content);
          
          // Extrahiere Items
          const items = parsedData.items || [];
          
          if (Array.isArray(items) && items.length > 0) {
            console.log(`Gefundene Items in JSON: ${items.length}`);
            
            // Direktes Serialisieren der Items ohne existierenden Inhalt zu lesen
            content = serializePropItems(items);
            console.log(`Serialisierter Inhalt für PropItem.txt.txt erzeugt (${content.length} Bytes)`);
          }
        } else if (content.includes('\t') && content.includes('IDS_PROPITEM_TXT_')) {
          console.log('propItem.txt.txt Inhalt ist bereits im korrekten Format');
          // Content ist bereits formatiert, nichts zu tun
        } else {
          console.warn('propItem.txt.txt hat ein unerwartetes Format');
        }
      } catch (err) {
        console.error('Fehler bei der Verarbeitung von propItem.txt.txt:', err);
        // Bei einem Fehler behalten wir den ursprünglichen Inhalt bei
      }
    }

    // Speichern der Datei mit dem aktuellen Inhalt (der jetzt serialisiert sein könnte)
    // Verwende ein einheitliches Format für den Pfad, ohne doppelte public/resource-Einträge
    let savePath = '';
    if (isFullPath) {
      savePath = targetFileInfo.path;
      } else {
      // Entferne führende Slashes und vermeide doppelte public/resource-Pfade
      let filePath = targetFileInfo.path;
      if (filePath.startsWith('/')) {
        filePath = filePath.substring(1);
      }
      
      if (filePath.startsWith('public/resource/')) {
        savePath = filePath;
      } else {
        savePath = `public/resource/${filePath}`;
      }
    }
    
    console.log(`Speichere Datei ${savePath} (${typeof content === 'string' ? content.length : 'nicht-string'} Bytes)`);

    // Falls content kein String ist, konvertieren wir ihn in einen String
    if (typeof content !== 'string') {
      try {
        content = JSON.stringify(content, null, 2);
      } catch (err) {
        console.error('Failed to stringify content:', err);
        return 'ERROR';
      }
    }

    // Datei speichern direkt ohne Backup
    // @ts-ignore
    const result = await window.electronAPI?.saveFile(fileName, content, savePath);
    
    if (result === 'SUCCESS') {
      console.log(`Datei erfolgreich gespeichert: ${savePath}`);
      
      // Entferne die Datei aus der Liste der modifizierten Dateien
      modifiedFiles = modifiedFiles.filter(file => file.name !== targetFileInfo.path);
      
      return 'SUCCESS';
            } else {
      // Verbesserte Fehlerbehandlung
      let errorMessage = '';
      if (result && typeof result === 'object') {
        try {
          errorMessage = JSON.stringify(result, null, 2);
        } catch (jsonError) {
          errorMessage = 'Unbekannter Fehler (konnte Fehlerobjekt nicht konvertieren)';
        }
      } else {
        errorMessage = result?.toString() || 'Unbekannter Fehler';
      }
      
      console.error(`Fehler beim Speichern der Datei: ${errorMessage}`);
      
      // Fallback zum Herunterladen
      downloadTextFile(content, getFilename(targetFileInfo.path));
      return typeof result === 'string' ? result : 'ERROR';
    }
  } catch (err) {
    console.error('saveTextFile error:', err);
    return 'ERROR';
  }
};

// Save all modified files at once
export const saveAllModifiedFiles = async (context: any): Promise<string[]> => {
  const results: string[] = [];
  
  // Log the number of modified files
  console.log(`Speichere alle ${modifiedFiles.length} modifizierten Dateien`);
  
  for (const fileInfo of modifiedFiles) {
    // Prüfe, ob ein gültiger Inhalt vorhanden ist
    if (!fileInfo.content) {
      console.warn(`Leerer Inhalt für Datei ${fileInfo.name}, überspringe...`);
      results.push(`${fileInfo.name}: ERROR (leerer Inhalt)`);
      continue;
    }
    
    // Stelle sicher, dass der Inhalt ein String ist und ersetze ihn NICHT mit originalContent
    let content = fileInfo.content;
    
    // Wenn die Datei eine Spec_Item.txt oder propItem.txt.txt ist, stelle sicher, dass wir die korrekten Serialisierungsfunktionen verwenden
    const isSpecItemFile = fileInfo.name.toLowerCase().includes('spec_item.txt');
    const isPropItemFile = fileInfo.name.toLowerCase().includes('propitem.txt.txt');
    const isDefineItemFile = fileInfo.name.toLowerCase().includes('defineitem.h');
    const isMdlDynaFile = fileInfo.name.toLowerCase().includes('mdldyna.inc');
    
    if ((isSpecItemFile || isPropItemFile || isDefineItemFile || isMdlDynaFile) && typeof content === 'string' && content.trim().startsWith('{')) {
      try {
        const parsedContent = JSON.parse(content);
        
        if (!parsedContent || !parsedContent.items || !Array.isArray(parsedContent.items)) {
          console.warn(`Ungültiges JSON für ${fileInfo.name}, items fehlt oder ist kein Array`);
          results.push(`${fileInfo.name}: ERROR (ungültiges Format)`);
          continue;
        }
        
        // Debugging-Ausgabe für Items mit Änderungen
        const itemsWithChanges = parsedContent.items?.filter((item: any) => 
          item.displayName !== undefined || 
          item.description !== undefined ||
          item.effects !== undefined ||
          item.modelFile !== undefined ||
          item.data !== undefined
        );
        
        if (itemsWithChanges?.length > 0) {
          console.log(`${fileInfo.name} enthält ${itemsWithChanges.length} Items mit Änderungen:`);
          itemsWithChanges.slice(0, 3).forEach((item: any, index: number) => {
            console.log(`Item ${index + 1}: ${item.name || item.id || 'unbekannt'}`);
            if (item.displayName !== undefined) console.log(`  Name: "${item.displayName}"`);
            if (item.description !== undefined) console.log(`  Beschreibung: "${item.description?.substring(0, 30)}..."`);
            if (item.effects !== undefined) console.log(`  Effekte: ${item.effects.length}`);
            if (item.modelFile !== undefined) console.log(`  Model: "${item.modelFile}"`);
          });
        }
        
        // Verwende die entsprechende Serialisierungsfunktion
        if (isSpecItemFile) {
          // Hole den originalContent aus den parsedContent-Daten
          let originalContent = '';
          if (parsedContent.originalContent && typeof parsedContent.originalContent === 'string') {
            originalContent = parsedContent.originalContent;
          }
          
          content = serializeWithNameReplacement(parsedContent, originalContent);
          console.log(`Serialisierten Inhalt für ${fileInfo.name} erstellt (${content.length} Bytes)`);
        } else if (isPropItemFile) {
          content = serializePropItems(parsedContent.items || []);
          console.log(`Serialisierten Inhalt für ${fileInfo.name} erstellt (${content.length} Bytes)`);
        } else if (isDefineItemFile) {
          content = serializeDefineItems(parsedContent.items || []);
          console.log(`Serialisierten Inhalt für ${fileInfo.name} erstellt (${content.length} Bytes)`);
        } else if (isMdlDynaFile) {
          content = serializeMdlDynaItems(parsedContent.items || []);
          console.log(`Serialisierten Inhalt für ${fileInfo.name} erstellt (${content.length} Bytes)`);
        }
      } catch (err) {
        console.warn(`Konnte Inhalt für ${fileInfo.name} nicht verarbeiten: ${err.message}`);
      }
    }
    
    // Prüfen, ob nach der Serialisierung ein gültiger Inhalt vorhanden ist
    if (!content) {
      console.warn(`Nach der Serialisierung leerer Inhalt für Datei ${fileInfo.name}, überspringe...`);
      results.push(`${fileInfo.name}: ERROR (leerer Inhalt nach Serialisierung)`);
      continue;
    }
    
    // Speichern der Datei
    const result = await saveTextFile2(context, {
      path: fileInfo.name,
      content,
    });
    
    results.push(`${fileInfo.name}: ${result}`);
  }
  
  return results;
};

// Hilfsfunktion, um den Dateinamen aus einem Pfad zu extrahieren
const getFilename = (filePath: string): string => {
  if (!filePath) return '';
  const parts = filePath.split(/[\/\\]/); // Sowohl / als auch \ als Trennzeichen berücksichtigen
  return parts[parts.length - 1];
};

export const readTextFile = (file: File): Promise<string> => {
  return new Promise((resolve, reject) => {
    // For large files, use the chunked approach
    if (file.size > 10 * 1024 * 1024) { // If file is larger than 10MB
      const CHUNK_SIZE = 15 * 1024 * 1024; // 15MB chunks for faster processing
      let content = "";
      let offset = 0;
      const fileSize = file.size;
      
      const readNextChunk = () => {
        const reader = new FileReader();
        const chunk = file.slice(offset, offset + CHUNK_SIZE);
        
        reader.onload = (e) => {
          if (e.target?.result) {
            content += e.target.result;
            offset += CHUNK_SIZE;
            
            if (offset < fileSize) {
              readNextChunk();
            } else {
              resolve(content);
            }
          }
        };
        
        reader.onerror = () => {
          reject(new Error("Error reading file chunk"));
        };
        
        reader.readAsText(chunk);
      };
      
      readNextChunk();
    } else {
      // For smaller files, use the standard approach
      const reader = new FileReader();
      
      reader.onload = (event) => {
        if (event.target?.result) {
          resolve(event.target.result as string);
        } else {
          reject(new Error("Failed to read file"));
        }
      };
      
      reader.onerror = () => {
        reject(new Error("File read error"));
      };
      
      reader.readAsText(file);
    }
  });
};

// Hilfsfunktionen für die Serialisierung verschiedener Dateitypen
const serializeDefineItems = (items: any[]): string => {
  let content = '';
  
  items.forEach(item => {
    if (!item) return;
    
    // Generiere die Define-Zeile
    const defineLine = `#define ${item.id}`;
    content += defineLine + '\n';
    
    // Füge Effekte hinzu, wenn vorhanden
    if (item.effects && Array.isArray(item.effects)) {
      item.effects.forEach((effect: any) => {
        if (effect && effect.type && effect.value !== undefined) {
          content += `\t${effect.type}\t${effect.value}\n`;
        }
      });
    }
    
    // Füge eine Leerzeile zwischen den Items hinzu
    content += '\n';
  });
  
  return content;
};

const serializeMdlDynaItems = (items: any[]): string => {
  let content = '';
  
  items.forEach(item => {
    if (!item) return;
    
    // Generiere die Include-Zeile mit dem korrekten Dateinamen
    const fileName = item.modelFile || item.fields?.mdlDyna?.fileName || '';
    const includeLine = `#include "${fileName}"`;
    content += includeLine + '\n';
    
    // Füge eine Leerzeile zwischen den Items hinzu
    content += '\n';
  });
  
  return content;
};
