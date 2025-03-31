import path from 'path';

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
  // Check if this is a spec_item.txt file with original content
  let finalContent = content;
  
  // Check if this is a Spec_item.txt file (case insensitive)
  const isSpecItemFile = fileName.toLowerCase().includes('spec_item') || fileName.toLowerCase().includes('specitem');
  
  // If the content is a JSON string, try to parse it
  if (content.startsWith('{') && content.includes('originalContent')) {
    try {
      const parsedContent = JSON.parse(content);
      
      // If this is a spec_item.txt file with original content, use that instead
      if ((parsedContent.isSpecItemFile || isSpecItemFile) && parsedContent.originalContent) {
        console.log(`Using original content for ${fileName} to preserve exact format`);
        finalContent = parsedContent.originalContent;
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
  // Statt einen Platzhalter zu speichern, erstellen wir ein temporäres Item, das die Änderungen enthält
  const tempItem = {
    name: itemName,
    data: { szName: itemId },
    displayName: displayName,
    description: description
  };
  
  // Protokolliere die Änderungen ausführlich
  console.log(`PropItem Änderung verfolgt: ID=${itemId}, Name=${itemName}`);
  console.log(`  Neuer Anzeigename: "${displayName}"`);
  console.log(`  Neue Beschreibung: "${description.substring(0, 30)}${description.length > 30 ? '...' : ''}"`);
  
  // Serialisiere sofort die Änderung
  try {
    const content = serializePropItemData([tempItem]);
    console.log(`Generierter propItem-Inhalt: ${content}`);
    
    // Speichere die tatsächlichen Änderungen
    // Neues Flag hinzufügen, um beide Dateien als zusammengehörig zu markieren
    trackModifiedFile("propItem.txt.txt", content, {
      isRelatedToSpecItem: true,
      relatedItemId: itemId
    });
  } catch (error) {
    console.error(`Fehler beim Serialisieren von PropItem-Änderungen:`, error);
    console.error(`ItemId: ${itemId}, Name: ${itemName}`);
    // Fehler für Debugging-Zwecke protokollieren, aber nicht werfen
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
          autoSynced: true
        });
        
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
      const response = await fetch('/public/resource/propItem.txt.txt');
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
      return true;
    } else {
      console.error("Fehler beim Speichern von propItem.txt.txt");
      
      // Bei Fehlern versuchen, eine lokale Datei herunterzuladen
      console.log("Versuche, eine lokale Kopie zu speichern...");
      try {
        const blob = new Blob([finalContent], { type: 'text/plain' });
        const url = URL.createObjectURL(blob);
        
        const link = document.createElement('a');
        link.href = url;
        link.download = "propItem.txt.txt";
        link.click();
        
        URL.revokeObjectURL(url);
        
        console.log("Lokale Kopie als Download bereitgestellt");
      } catch (downloadError) {
        console.error("Fehler beim Versuch, eine lokale Kopie zu speichern:", downloadError);
      }
      
      return false;
    }
  } catch (error) {
    console.error("Fehler beim Serialisieren von propItem-Änderungen:", error);
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

// Save a single file
export const saveTextFile = (content: string, fileName: string): Promise<boolean> => {
  return new Promise(async (resolve) => {
    // Check if this is a Spec_item.txt file (case insensitive)
    const isSpecItemFile = fileName.toLowerCase().includes('spec_item') || fileName.toLowerCase().includes('specitem');
    
    // For Spec_item.txt files, ensure we're preserving the exact content
    let finalContent = content;
    if (isSpecItemFile && content.startsWith('{')) {
      try {
        const parsedContent = JSON.parse(content);
        if (parsedContent.originalContent) {
          console.log(`Using original content for ${fileName} to preserve exact format`);
          finalContent = parsedContent.originalContent;
        }
      } catch (error) {
        console.warn(`Failed to parse content as JSON for ${fileName}:`, error);
        // Continue with the original content
      }
    }
    
    // Track the file modification
    trackModifiedFile(fileName, finalContent);
    
    // Check if we're in Electron environment
    const isElectron = window.navigator.userAgent.toLowerCase().indexOf('electron') > -1 || 
                       (window as any).electronAPI !== undefined;
    
    console.log("Erkennungswerte:", {
      userAgent: window.navigator.userAgent.toLowerCase(),
      hasElectronInUA: window.navigator.userAgent.toLowerCase().indexOf('electron') > -1,
      hasElectronAPI: !!(window as any).electronAPI,
      isElectron
    });

    if (isElectron) {
      try {
        console.log("Electron environment detected, attempting direct save");
        
        // First try to save via the electronAPI
        if ((window as any).electronAPI) {
          console.log("Using electronAPI.saveFile");
          
          // Ensure content is a string (not an object)
          if (typeof finalContent !== 'string') {
            console.warn("Content is not a string, converting to string");
            finalContent = JSON.stringify(finalContent);
          }
          
          // Log content length for debugging
          console.log(`File content length: ${finalContent.length} characters`);
          
          // Use absolute path for resource folder to avoid path issues
          const result = await (window as any).electronAPI.saveFile(fileName, finalContent, path.join(process.cwd(), 'public', 'resource'));
          
          if (result.success) {
            console.log(`File saved directly to resource folder via Electron API: ${result.path}`);
            resolve(true);
            return;
          } else {
            console.error("Error saving via Electron API:", result.error);
            // Fall back to download if electron API fails
            downloadTextFile(finalContent, fileName);
            resolve(false);
            return;
          }
        } else {
          // Fallback to custom event for older versions
          console.log("Fallback to custom event for Electron");
          
          // Ensure content is a string
          if (typeof finalContent !== 'string') {
            finalContent = JSON.stringify(finalContent);
          }
          
          const event = new CustomEvent('save-file', { 
            detail: { 
              fileName, 
              content: finalContent, 
              path: path.join(process.cwd(), 'public', 'resource')
            }
          });
          window.dispatchEvent(event);
          
          // Listen for the response from Electron
          const responseHandler = (event: any) => {
            const response = event.detail;
            console.log("Save response from Electron:", response);
            if (response.success) {
              console.log(`File saved directly to resource folder via Electron: ${fileName}`);
              window.removeEventListener('save-file-response', responseHandler);
              resolve(true);
            } else {
              console.error("Error saving via Electron:", response.error);
              window.removeEventListener('save-file-response', responseHandler);
              // Fall back to download
              downloadTextFile(finalContent, fileName);
              resolve(false);
            }
          };
          
          window.addEventListener('save-file-response', responseHandler, { once: true });
          
          // Set a timeout in case Electron doesn't respond
          setTimeout(() => {
            console.warn("No response from Electron after 2 seconds, falling back to download");
            window.removeEventListener('save-file-response', responseHandler);
            downloadTextFile(finalContent, fileName);
            resolve(false);
          }, 2000);
          
          return;
        }
      } catch (error) {
        console.error("Error using Electron save API:", error);
        // Fall back to download if Electron API fails
        downloadTextFile(finalContent, fileName);
        resolve(false);
        return;
      }
    }
    
    // If not in Electron, always fall back to download
    console.warn("Not in Electron environment, falling back to download");
    downloadTextFile(finalContent, fileName);
    resolve(false);
  });
};

// Save all modified files at once
export const saveAllModifiedFiles = async (): Promise<boolean> => {
  console.log("Saving all modified files:", modifiedFiles.length);
  
  try {
    if (modifiedFiles.length === 0) {
      console.log("No modified files to save");
      return true;
    }
    
    // Überprüfe, ob beide Dateien (Spec_Item.txt und propItem.txt.txt) geändert wurden
    // Wenn nur Spec_Item.txt geändert wurde, aber propItem.txt.txt-Änderungen vorhanden sind,
    // stelle sicher, dass beide gespeichert werden
    const hasSpecItemChanges = modifiedFiles.some(file => 
      file.name.toLowerCase().includes('spec_item') || file.name.toLowerCase().includes('specitem')
    );
    
    const hasPropItemChanges = modifiedFiles.some(file => 
      file.name.toLowerCase().includes('propitem')
    );
    
    // Wenn Spec_Item.txt geändert wurde, aber keine entsprechenden PropItem-Änderungen vorhanden sind,
    // überprüfe ob es Item-Änderungen gibt und synchronisiere sie mit propItem.txt.txt
    if (hasSpecItemChanges && !hasPropItemChanges) {
      const specItemFile = modifiedFiles.find(file => 
        file.name.toLowerCase().includes('spec_item') || file.name.toLowerCase().includes('specitem')
      );
      
      if (specItemFile && specItemFile.content) {
        console.log("Sync check: Spec_Item.txt was modified, checking for name/description changes");
        
        try {
          // Versuche die Datei zu parsen, um zu sehen, ob es Änderungen an displayName/description gibt
          // Dieses ist vereinfacht, da die tatsächliche Implementierung vom Format abhängt
          const specItemData = JSON.parse(specItemFile.content);
          
          if (specItemData.items && Array.isArray(specItemData.items)) {
            // Finde Items mit displayName/description, die sich geändert haben könnten
            const itemsWithNameChanges = specItemData.items.filter(
              item => item.displayName !== undefined || item.description !== undefined
            );
            
            if (itemsWithNameChanges.length > 0) {
              console.log(`Found ${itemsWithNameChanges.length} items with potential name/description changes`);
              
              // Erstelle PropItem-Änderungen für alle geänderten Items
              const propItemContent = serializePropItemData(itemsWithNameChanges);
              
              // Füge propItem.txt.txt zu den zu speichernden Dateien hinzu
              trackModifiedFile("propItem.txt.txt", propItemContent, {
                isRelatedToSpecItem: true,
                autoSynced: true
              });
              
              console.log("Added propItem.txt.txt to modified files for synchronized saving");
            }
          }
        } catch (error) {
          console.warn("Failed to parse Spec_Item.txt for auto-synchronization:", error);
          // Continue without syncing
        }
      }
    }
    
    // Save to resource folder
    return await saveMultipleFilesToResourceFolder(modifiedFiles);
  } catch (error) {
    console.error("Error saving all modified files:", error);
    return false;
  } finally {
    // Clear the modified files after saving
    clearModifiedFiles();
  }
};

// Improved server-side save function with better error handling and retry logic
const saveToResourceFolder = async (content: string, fileName: string): Promise<boolean> => {
  try {
    console.log(`Attempting to save ${fileName} to resource folder via server API`);
    
    // Check if the file is a JSON file or not
    const isJsonFile = fileName.toLowerCase().endsWith('.json');
    const isTextFile = fileName.toLowerCase().endsWith('.txt') || 
                      fileName.toLowerCase().endsWith('.h') || 
                      fileName.toLowerCase().endsWith('.inc');
    
    console.log(`File type detection: ${fileName} - JSON: ${isJsonFile}, Text: ${isTextFile}`);
    
    // Attempt to save the file to the server's resource folder
    // Use a retry mechanism in case of temporary issues
    let attempts = 3;
    let lastError = null;
    
    while (attempts > 0) {
      try {
        const response = await fetch('/api/save-resource', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({
            fileName,
            content,
          }),
        });

        if (!response.ok) {
          const errorData = await response.json().catch(() => ({}));
          console.error(`Server responded with ${response.status}:`, errorData);
          throw new Error(`Server error: ${errorData.error || response.statusText}`);
        }

        const result = await response.json();
        if (result.success === true) {
          console.log(`Successfully saved ${fileName} to resource folder`);
          return true;
        } else {
          throw new Error(`Save operation reported failure: ${result.error || 'Unknown error'}`);
        }
      } catch (error) {
        console.error(`Attempt ${4 - attempts} failed:`, error);
        lastError = error;
        attempts--;
        
        if (attempts > 0) {
          console.log(`Retrying save operation for ${fileName}... (${attempts} attempts left)`);
          // Wait a short time before retrying
          await new Promise(resolve => setTimeout(resolve, 500));
        }
      }
    }
    
    console.error(`All save attempts failed for ${fileName}:`, lastError);
    return false;
  } catch (error) {
    console.error("Failed to save file to resource folder:", error);
    return false;
  }
};

// Save multiple files to resource folder at once with retry logic
const saveMultipleFilesToResourceFolder = async (files: { name: string; content: string; metadata?: { [key: string]: any } }[]): Promise<boolean> => {
  console.log(`Trying to save ${files.length} files to resource folder`);
  
  // Check if we're in Electron environment
  const isElectron = window.navigator.userAgent.toLowerCase().indexOf('electron') > -1 || 
                    (window as any).electronAPI !== undefined;
  
  if (isElectron) {
    try {
      if ((window as any).electronAPI) {
        console.log("Using electronAPI.saveAllFiles");
        
        // Ensure all content is string
        const sanitizedFiles = files.map(file => ({
          name: file.name,
          content: typeof file.content === 'string' ? file.content : JSON.stringify(file.content)
        }));
        
        // Log file sizes for debugging
        sanitizedFiles.forEach(file => {
          console.log(`File ${file.name} content length: ${file.content.length} characters`);
        });
        
        const result = await (window as any).electronAPI.saveAllFiles(sanitizedFiles);
        
        if (result.success) {
          console.log(`All files saved successfully via Electron API`);
          
          // Versuche, clearModifiedItems aus propItemUtils zu importieren und aufzurufen
          try {
            const { clearModifiedItems } = require('./propItemUtils');
            clearModifiedItems();
            console.log("Cleared modified items in PropItem cache");
          } catch (error) {
            console.warn("Could not clear modified items:", error);
          }
          
          return true;
        } else {
          console.error("Error saving all files via Electron API:", result.error);
          // Fall back to individual downloads
          for (const file of files) {
            downloadTextFile(
              typeof file.content === 'string' ? file.content : JSON.stringify(file.content), 
              file.name
            );
          }
          return false;
        }
      } else {
        // Fallback to custom event
        console.log("Using custom event for saveAllFiles");
        
        // Ensure all content is string
        const sanitizedFiles = files.map(file => ({
          name: file.name,
          content: typeof file.content === 'string' ? file.content : JSON.stringify(file.content)
        }));
        
        const event = new CustomEvent('save-all-files', { 
          detail: { files: sanitizedFiles }
        });
        window.dispatchEvent(event);
        
        return new Promise((resolve) => {
          const responseHandler = (event: any) => {
            const response = event.detail;
            console.log("Save all files response:", response);
            if (response.success) {
              console.log(`All files saved successfully via Electron`);
              
              // Versuche, clearModifiedItems aus propItemUtils zu importieren und aufzurufen
              try {
                const { clearModifiedItems } = require('./propItemUtils');
                clearModifiedItems();
                console.log("Cleared modified items in PropItem cache");
              } catch (error) {
                console.warn("Could not clear modified items:", error);
              }
              
              window.removeEventListener('save-all-files-response', responseHandler);
              resolve(true);
            } else {
              console.error("Error saving all files via Electron:", response.error);
              window.removeEventListener('save-all-files-response', responseHandler);
              
              // Fall back to individual downloads
              for (const file of files) {
                downloadTextFile(
                  typeof file.content === 'string' ? file.content : JSON.stringify(file.content), 
                  file.name
                );
              }
              resolve(false);
            }
          };
          
          window.addEventListener('save-all-files-response', responseHandler, { once: true });
          
          // Set a timeout in case Electron doesn't respond
          setTimeout(() => {
            console.warn("No response from Electron after 2 seconds");
            window.removeEventListener('save-all-files-response', responseHandler);
            
            // Fall back to individual downloads
            for (const file of files) {
              downloadTextFile(
                typeof file.content === 'string' ? file.content : JSON.stringify(file.content), 
                file.name
              );
            }
            resolve(false);
          }, 2000);
        });
      }
    } catch (error) {
      console.error("Error using Electron saveAllFiles API:", error);
      
      // Fall back to individual downloads
      for (const file of files) {
        downloadTextFile(
          typeof file.content === 'string' ? file.content : JSON.stringify(file.content), 
          file.name
        );
      }
      return false;
    }
  }
  
  // If not in Electron, download all files
  console.warn("Not in Electron environment, falling back to individual downloads");
  for (const file of files) {
    downloadTextFile(
      typeof file.content === 'string' ? file.content : JSON.stringify(file.content), 
      file.name
    );
  }
  return false;
};

// Standard browser download method (fallback)
const downloadTextFile = (content: string, fileName: string): void => {
  console.log("Falling back to browser download for", fileName);
  const blob = new Blob([content], { type: 'text/plain' });
  const url = URL.createObjectURL(blob);
  
  const link = document.createElement('a');
  link.href = url;
  link.download = fileName;
  link.click();
  
  URL.revokeObjectURL(url);
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
