import path from 'path';
import fs from 'fs';
import { serializeWithNameReplacement, serializePropItems } from './serializeUtils';

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

// Track modified files that need to be saved
let modifiedFiles: { name: string; content: string; metadata?: { [key: string]: any } }[] = [];

// Add or update a file in the modified files list
export const trackModifiedFile = (fileName: string, content: string, metadata?: { [key: string]: any }) => {
  // Der Inhalt bleibt unverändert, keine originalContent-Ersetzung mehr
  let finalContent = content;
  
  // Check if this is a Spec_item.txt file (case insensitive)
  const isSpecItemFile = fileName.toLowerCase().includes('spec_item') || fileName.toLowerCase().includes('specitem');
  
  // Prüfe auf JSON-Inhalte, aber ohne originalContent-Ersetzung
  if (content.startsWith('{') && content.includes('originalContent')) {
    try {
      const parsedContent = JSON.parse(content);
      
      // Kommentiere die Ersetzung durch originalContent aus
      // Wir behalten stattdessen den neuen, geänderten Inhalt bei
      /*
      if ((parsedContent.isSpecItemFile || isSpecItemFile) && parsedContent.originalContent) {
        console.log(`Using original content for ${fileName} to preserve exact format`);
        finalContent = parsedContent.originalContent;
      }
      */
      
      // Log, dass wir den neuen Inhalt verwenden
      if ((parsedContent.isSpecItemFile || isSpecItemFile) && parsedContent.originalContent) {
        console.log(`Behalte geänderten Inhalt für ${fileName} bei (statt originalContent)`);
      }
    } catch (error) {
      console.warn(`Failed to parse content as JSON for ${fileName}:`, error);
      // Continue with the original content
    }
  }
  
  const existingIndex = modifiedFiles.findIndex(file => file.name === fileName);
  
  if (existingIndex >= 0) {
    modifiedFiles[existingIndex].content = finalContent;
    // Füge Metadaten hinzu, wenn sie übergeben wurden
    if (metadata) {
      modifiedFiles[existingIndex].metadata = {
        ...modifiedFiles[existingIndex].metadata,
        ...metadata
      };
    }
  } else {
    modifiedFiles.push({ 
      name: fileName, 
      content: finalContent,
      metadata: metadata || {}
    });
  }
  
  console.log(`Tracked modified file: ${fileName}`, metadata ? `with metadata: ${JSON.stringify(metadata)}` : '');
  return modifiedFiles;
};

// Track changes to propItem entries (names and descriptions)
export const trackPropItemChanges = (itemId: string, itemName: string, displayName: string, description: string) => {
  // Ein temporäres Item erstellen, das die Änderungen enthält
  const tempItem = {
    name: itemName,
    data: { szName: itemId },
    displayName: displayName,
    description: description
  };
  
  // Ausführliche Protokollierung der Änderungen für Debugging-Zwecke
  console.log(`PropItem Änderung verfolgt: ID=${itemId}, Name=${itemName}`);
  console.log(`  Neuer Anzeigename: "${displayName}"`);
  console.log(`  Neue Beschreibung: "${description.substring(0, 30)}${description.length > 30 ? '...' : ''}"`);
  
  try {
    // Serialisiere sofort die Änderung
    const content = serializePropItemData([tempItem]);
    console.log(`Generierter propItem-Inhalt: ${content}`);
    
    // Speichere die tatsächlichen Änderungen mit Metadaten, die anzeigen, dass dies mit Spec_Item verknüpft ist
    trackModifiedFile("propItem.txt.txt", content, {
      isRelatedToSpecItem: true,
      relatedItemId: itemId,
      modifiedTimestamp: Date.now()
    });
    
    // Importiere und rufe die markItemAsModified-Funktion auf, um sicherzustellen,
    // dass das Item im Cache als modifiziert markiert wird, selbst wenn es nicht im aktuellen Tab ist
    try {
      const { markItemAsModified } = require('./propItemUtils');
      markItemAsModified(itemId, displayName, description);
      console.log(`Item ${itemId} auch im modifiedItems-Cache markiert`);
    } catch (importError) {
      console.warn(`Konnte markItemAsModified nicht importieren:`, importError);
      // Wir fahren fort, selbst wenn der Import fehlschlägt
    }
  } catch (error) {
    console.error(`Fehler beim Serialisieren von PropItem-Änderungen:`, error);
    console.error(`ItemId: ${itemId}, Name: ${itemName}`);
    // Fehler protokollieren, aber fortfahren
  }
};

/**
 * Stellt sicher, dass alle Änderungen an Item-Namen und Beschreibungen in beiden Dateien konsistent sind
 * Diese Funktion sollte vor dem Speichern aufgerufen werden
 * @param fileData Die aktuellen Dateidaten
 * @returns True, wenn Änderungen vorgenommen wurden, sonst false
 */
export const ensurePropItemConsistency = (fileData: any): boolean => {
  if (!fileData || !fileData.items || !Array.isArray(fileData.items)) {
    console.warn("ensurePropItemConsistency: Ungültige Dateidaten übergeben");
    return false;
  }
  
  console.log("Konsistenzprüfung für Item-Namen und Beschreibungen gestartet");
  
  try {
    // Überprüfe, ob modifiedFiles sowohl Spec_Item.txt als auch propItem.txt.txt enthält
    const hasSpecItemChanges = modifiedFiles.some(file => 
      file.name.toLowerCase().includes('spec_item') || file.name.toLowerCase().includes('specitem')
    );
    
    const hasPropItemChanges = modifiedFiles.some(file => 
      file.name.toLowerCase().includes('propitem')
    );
    
    // Wenn beide Dateien bereits als modifiziert markiert sind, ist keine weitere Aktion erforderlich
    if (hasSpecItemChanges && hasPropItemChanges) {
      console.log("Beide Dateien sind bereits als modifiziert markiert, keine weitere Aktion erforderlich");
      return false;
    }
    
    // Wenn nur Spec_Item.txt modifiziert wurde, überprüfe, ob es Änderungen an displayName/description gibt
    if (hasSpecItemChanges && !hasPropItemChanges) {
      console.log("Spec_Item.txt wurde modifiziert, aber propItem.txt.txt nicht");
      
      // Finde Items mit Änderungen an displayName/description
      const itemsWithNameChanges = fileData.items.filter((item: any) => 
        (item.displayName !== undefined && item.displayName !== null) || 
        (item.description !== undefined && item.description !== null)
      );
      
      if (itemsWithNameChanges.length > 0) {
        console.log(`${itemsWithNameChanges.length} Items mit Änderungen an Namen/Beschreibungen gefunden`);
        
        // Erstelle PropItem-Änderungen für alle geänderten Items
        const propItemContent = serializePropItemData(itemsWithNameChanges);
        
        // Füge propItem.txt.txt zu den zu speichernden Dateien hinzu
        trackModifiedFile("propItem.txt.txt", propItemContent, {
          isRelatedToSpecItem: true,
          autoSynced: true,
          modifiedTimestamp: Date.now()
        });
        
        // Zusätzlich für jedes geänderte Item markItemAsModified aufrufen
        try {
          const { markItemAsModified } = require('./propItemUtils');
          for (const item of itemsWithNameChanges) {
            if (item.data && item.data.szName) {
              markItemAsModified(
                item.data.szName,
                item.displayName || '',
                item.description || ''
              );
              console.log(`Item ${item.data.szName} im modifiedItems-Cache als geändert markiert`);
            }
          }
        } catch (importError) {
          console.warn(`Konnte markItemAsModified nicht importieren:`, importError);
          // Wir fahren fort, selbst wenn der Import fehlschlägt
        }
        
        console.log("propItem.txt.txt wurde automatisch als modifiziert markiert, um Konsistenz zu gewährleisten");
        return true;
      } else {
        console.log("Keine Änderungen an Namen/Beschreibungen gefunden, keine Aktion erforderlich");
      }
    }
    
    return false;
  } catch (error) {
    console.error("Fehler bei der Konsistenzprüfung:", error);
    return false;
  }
};

// Save all propItem changes to the propItem.txt.txt file
export const savePropItemChanges = async (items: any[]): Promise<boolean> => {
  console.log("savePropItemChanges aufgerufen mit", items?.length || 0, "Items");
  
  if (!items || items.length === 0) {
    console.warn("Keine Items zum Speichern vorhanden!");
    return false;
  }
  
  // Only process if we have pending propItem changes
  const hasPropItemChanges = modifiedFiles.some(file => file.name === "propItem.txt.txt");
  if (!hasPropItemChanges) {
    console.warn("Keine propItem.txt.txt-Änderungen gefunden, obwohl die Funktion aufgerufen wurde");
    return true;
  }
  
  try {
    console.log("Serialisiere propItem-Änderungen für", items.length, "Items");
    
    // First load the existing propItem.txt.txt file to preserve existing entries
    let existingContent = "";
    let isUtf16 = false;
    
    try {
      console.log("Versuche, die vorhandene propItem.txt.txt zu laden");
      const response = await fetch('/resource/propItem.txt.txt');
      if (response.ok) {
        // Get the file as an ArrayBuffer to handle different encodings
        const buffer = await response.arrayBuffer();
        
        // Check for UTF-16LE BOM (FF FE)
        const firstBytes = new Uint8Array(buffer.slice(0, 2));
        
        if (firstBytes[0] === 0xFF && firstBytes[1] === 0xFE) {
          console.log("UTF-16LE-Kodierung in existierender propItem.txt.txt erkannt");
          existingContent = new TextDecoder('utf-16le').decode(buffer);
          isUtf16 = true;
        } else {
          // Fallback to UTF-8
          existingContent = new TextDecoder('utf-8').decode(buffer);
        }
        
        console.log("Existierende propItem.txt.txt geladen, Inhaltslänge:", existingContent.length);
      } else {
        console.warn("Konnte existierende propItem.txt.txt nicht laden, Status:", response.status);
        // Alternativer Pfad für die Suche
        const altResponse = await fetch('/public/resource/propItem.txt.txt');
        if (altResponse.ok) {
          existingContent = await altResponse.text();
          console.log("Existierende propItem.txt.txt vom alternativen Pfad geladen");
        }
      }
    } catch (error) {
      console.warn("Fehler beim Laden der existierenden propItem.txt.txt:", error);
    }
    
    // Parse existing content to create a map of IDs to values
    const existingEntries: { [key: string]: string } = {};
    if (existingContent) {
      const lines = existingContent.split(/\r?\n/);
      console.log(`Vorhandene propItem.txt.txt hat ${lines.length} Zeilen`);
      for (const line of lines) {
        if (!line.trim()) continue; // Skip empty lines
        
        const parts = line.split('\t');
        if (parts.length >= 2) {
          const id = parts[0].trim();
          // Only add if it's a valid ID format to avoid duplicating corrupted entries
          if (id.match(/IDS_PROPITEM_TXT_\d+/)) {
            existingEntries[id] = parts[1].trim();
          }
        }
      }
      console.log(`${Object.keys(existingEntries).length} existierende Einträge aus propItem.txt.txt geparst`);
    }
    
    // Finde zu aktualisierende Items
    // Wir betrachten auch bereits modifizierte Items, die noch nicht gespeichert wurden
    const modifiedItems = items.filter(item => 
      item.displayName !== undefined || 
      item.description !== undefined
    );
    
    console.log(`${modifiedItems.length} modifizierte Items aus ${items.length} Gesamtitems gefunden`);
    
    // Hole auch änderungen aus modifiedFiles für propItem.txt.txt
    const propItemFileEntries = modifiedFiles.find(f => f.name === "propItem.txt.txt");
    if (propItemFileEntries) {
      console.log("Füge Änderungen aus modifiedFiles hinzu");
      try {
        const pendingLines = propItemFileEntries.content.split(/\r?\n/);
        for (const line of pendingLines) {
          if (!line.trim()) continue;
          
          const parts = line.split('\t');
          if (parts.length >= 2) {
            const id = parts[0].trim();
            if (id.match(/IDS_PROPITEM_TXT_\d+/)) {
              console.log(`Aktualisiere ID aus modifiedFiles: ${id} = ${parts[1]}`);
              existingEntries[id] = parts[1].trim();
            }
          }
        }
      } catch (e) {
        console.warn("Fehler beim Verarbeiten der modifiedFiles:", e);
      }
    }
    
    // Directly update each modified item in the existing entries
    modifiedItems.forEach(item => {
      if (!item.name || !item.data || !item.data.szName) {
        console.warn("Ungültiges Item ohne Name oder szName:", item);
        return;
      }
      
      // Get the ID from the item's propItem ID (szName field)
      const propItemId = item.data.szName as string;
      const idMatch = propItemId.match(/IDS_PROPITEM_TXT_(\d+)/);
      if (!idMatch) {
        console.warn(`Ungültige PropItem ID: ${propItemId}`);
        return;
      }
      
      const baseId = parseInt(idMatch[1], 10);
      if (isNaN(baseId)) {
        console.warn(`Ungültige Basis-ID: ${idMatch[1]}`);
        return;
      }
      
      // WICHTIG: Stelle sicher, dass die ID korrekt formatiert ist!
      const paddedId = baseId.toString().padStart(6, '0');
      
      // Log each modification
      console.log(`Aktualisiere Item: ${item.name} (${propItemId})`);
      if (item.displayName !== undefined) {
        const nameId = `IDS_PROPITEM_TXT_${paddedId}`;
        console.log(`  Name-ID: ${nameId} = ${item.displayName}`);
        existingEntries[nameId] = item.displayName || item.name;
      }
      
      if (item.description !== undefined) {
        const descId = `IDS_PROPITEM_TXT_${(baseId + 1).toString().padStart(6, '0')}`;
        console.log(`  Beschreibungs-ID: ${descId} = ${item.description.substring(0, 30)}...`);
        existingEntries[descId] = item.description || '';
      }
    });
    
    // Rebuild the final content from the updated entries
    const finalLines = Object.entries(existingEntries)
      .sort((a, b) => {
        // Sort by numeric part of the ID
        const numA = parseInt(a[0].replace(/\D/g, ''), 10);
        const numB = parseInt(b[0].replace(/\D/g, ''), 10);
        return numA - numB;
      })
      .map(([id, value]) => `${id}\t${value}`);
    
    // Use Windows-style line endings (CRLF) for better compatibility
    const finalContent = finalLines.join('\r\n');
    
    console.log(`Finale propItem.txt.txt hat ${finalLines.length} Einträge`);
    
    // Direkte Debug-Ausgabe einiger Werte, um das Problem zu isolieren
    console.log(`Direkte Speicherprüfung für ID_000160:`);
    const debugEntry = existingEntries["IDS_PROPITEM_TXT_000160"];
    console.log(debugEntry ? `ID_000160 = ${debugEntry}` : "ID_000160 nicht gefunden");
    
    // Directly save the file using the improved Electron saving method
    console.log("Rufe saveTextFile auf...");
    const success = await saveTextFile(finalContent, "propItem.txt.txt");
    
    if (success) {
      console.log("propItem.txt.txt erfolgreich gespeichert");
      // Entferne die Datei aus der Liste der modifizierten Dateien
      modifiedFiles = modifiedFiles.filter(file => file.name !== "propItem.txt.txt");
      return true;
    } else {
      console.error("Fehler beim Speichern von propItem.txt.txt");
      // Zeige eine Fehlermeldung an
      alert("Fehler beim Speichern von propItem.txt.txt. Bitte versuchen Sie es erneut.");
      return false;
    }
  } catch (error) {
    console.error("Fehler beim Serialisieren von propItem-Änderungen:", error);
    alert(`Fehler beim Speichern von propItem.txt.txt: ${error.message}`);
    return false;
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
      savePath = `/resource/${fileName}`;
    }
    
    // Stelle sicher, dass der Pfad korrekt ist
    if (!savePath.startsWith('/') && !savePath.includes(':\\') && !savePath.startsWith('.\\')) {
      savePath = `/${savePath}`;
    }
    
    // Direktes Speichern über Electron API
    // @ts-ignore
    const result = await window.electronAPI?.saveFile(savePath, content);
    
    if (result === 'SUCCESS') {
      console.log(`Datei erfolgreich gespeichert: ${savePath}`);
      
      // Entferne die Datei aus der Liste der modifizierten Dateien
      modifiedFiles = modifiedFiles.filter(file => file.name !== fileName);
      
      return true;
    } else {
      console.error(`Fehler beim Speichern der Datei: ${result}`);
      // Fallback: Versuche den Download, wenn das Speichern fehlgeschlagen ist
      downloadTextFile(content, fileName);
      return false;
    }
  } catch (err) {
    console.error('saveTextFile error:', err);
    // Fallback zum Herunterladen als letzter Ausweg
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
    if (!targetFileInfo || !targetFileInfo.path || !targetFileInfo.content) {
      console.error('saveTextFile error: invalid targetFileInfo', targetFileInfo);
      return 'ERROR';
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
        
        // Hole die ursprüngliche Datei, um sie als Basis für die Serialisierung zu verwenden
        const originalFilePath = isFullPath ? targetFileInfo.path : path.join(context?.rootFolder || '', targetFileInfo.path);
        
        // Lese den ursprünglichen Inhalt, falls die Datei existiert
        let originalContent = '';
        try {
          originalContent = fs.existsSync(originalFilePath) 
            ? fs.readFileSync(originalFilePath, 'utf-8')
            : '';
            
          console.log(`Original-Inhalt von ${originalFilePath} gelesen (${originalContent.length} Bytes)`);
        } catch (err) {
          console.warn(`Konnte Original-Inhalt nicht lesen: ${err.message}`);
          // Wenn der Inhalt nicht gelesen werden kann, fahren wir mit leerem Inhalt fort
        }
        
        // Verwende die verbesserte Serialisierungsfunktion
        content = serializeWithNameReplacement(parsedData, originalContent);
        
        console.log(`Serialisierter Inhalt für Spec_Item.txt erstellt (${content.length} Bytes)`);
      } catch (err) {
        console.error('Fehler bei der Serialisierung von Spec_Item.txt:', err);
        // Bei einem Fehler behalten wir den ursprünglichen Inhalt bei
      }
    }
    // Für propItem.txt.txt Dateien verwenden wir serializePropItems
    else if (isPropItemFile && typeof content === 'string' && content.trim().startsWith('{')) {
      try {
        console.log('Verarbeite propItem.txt.txt Datei mit benutzerdefinierten Serialisierungsfunktionen');
        
        // Parse den Dateiinhalt, falls als String übergeben
        const parsedData = JSON.parse(content);
        
        // Verwende die spezielle Serialisierungsfunktion für propItem.txt.txt
        content = serializePropItems(parsedData.items || []);
        
        console.log(`Serialisierter Inhalt für propItem.txt.txt erstellt (${content.length} Bytes)`);
      } catch (err) {
        console.error('Fehler bei der Serialisierung von propItem.txt.txt:', err);
        // Bei einem Fehler behalten wir den ursprünglichen Inhalt bei
      }
    }

    // Speichern der Datei mit dem aktuellen Inhalt (der jetzt serialisiert sein könnte)
    const savePath = isFullPath ? targetFileInfo.path : (context?.rootFolder ? path.join(context.rootFolder, targetFileInfo.path) : targetFileInfo.path);
    
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

    // Datei speichern
    // @ts-ignore
    const result = await window.electronAPI?.saveFile(savePath, content);
    
    if (result === 'SUCCESS') {
      console.log(`Datei erfolgreich gespeichert: ${savePath}`);
      
      // Entferne die Datei aus der Liste der modifizierten Dateien
      modifiedFiles = modifiedFiles.filter(file => file.name !== targetFileInfo.path);
      
      return 'SUCCESS';
    } else {
      console.error(`Fehler beim Speichern der Datei: ${result}`);
      // Fallback zum Herunterladen
      downloadTextFile(content, path.basename(targetFileInfo.path));
      return result;
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
    // Stelle sicher, dass der Inhalt ein String ist und ersetze ihn NICHT mit originalContent
    let content = fileInfo.content;
    
    // Wenn die Datei eine Spec_Item.txt oder propItem.txt.txt ist, stelle sicher, dass wir die korrekten Serialisierungsfunktionen verwenden
    const isSpecItemFile = fileInfo.name.toLowerCase().includes('spec_item.txt');
    const isPropItemFile = fileInfo.name.toLowerCase().includes('propitem.txt.txt');
    
    if ((isSpecItemFile || isPropItemFile) && typeof content === 'string' && content.trim().startsWith('{')) {
      try {
        const parsedContent = JSON.parse(content);
        
        // Debugging-Ausgabe für Items mit Änderungen
        const itemsWithNameChanges = parsedContent.items?.filter((item: any) => 
          item.displayName !== undefined || item.description !== undefined
        );
        
        if (itemsWithNameChanges?.length > 0) {
          console.log(`${fileInfo.name} enthält ${itemsWithNameChanges.length} Items mit Namens-/Beschreibungsänderungen:`);
          itemsWithNameChanges.slice(0, 3).forEach((item: any, index: number) => {
            console.log(`Item ${index + 1}: ${item.name || item.id || 'unbekannt'}`);
            if (item.displayName !== undefined) console.log(`  Name: "${item.displayName}"`);
            if (item.description !== undefined) console.log(`  Beschreibung: "${item.description?.substring(0, 30)}..."`);
          });
        }
        
        // Verwende die entsprechende Serialisierungsfunktion
        if (isSpecItemFile) {
          // Hole den ursprünglichen Inhalt als Basis
          let originalContent = '';
          try {
            const originalFilePath = path.join(context?.rootFolder || '', fileInfo.name);
            originalContent = fs.existsSync(originalFilePath) 
              ? fs.readFileSync(originalFilePath, 'utf-8')
              : '';
          } catch (err) {
            console.warn(`Konnte Original-Inhalt nicht lesen: ${err.message}`);
          }
          
          content = serializeWithNameReplacement(parsedContent, originalContent);
          console.log(`Serialisierten Inhalt für ${fileInfo.name} erstellt (${content.length} Bytes)`);
        } else if (isPropItemFile) {
          content = serializePropItems(parsedContent.items || []);
          console.log(`Serialisierten Inhalt für ${fileInfo.name} erstellt (${content.length} Bytes)`);
        }
      } catch (err) {
        console.warn(`Konnte Inhalt für ${fileInfo.name} nicht verarbeiten: ${err.message}`);
      }
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
