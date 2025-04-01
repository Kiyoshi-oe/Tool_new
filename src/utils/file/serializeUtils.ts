/**
 * Verbesserte Serialisierungsfunktionen für Dateien
 * Diese stellen sicher, dass Änderungen an Namen und Beschreibungen in den Dateien landen
 */

/**
 * Serialisiert für Spec_Item.txt unter Beibehaltung des Formats, aber mit Ersetzung von Namen und Beschreibungen
 * @param fileData Die Dateidaten mit items, die displayName und description enthalten können
 * @param originalContent Der ursprüngliche Textinhalt der Datei
 * @returns Der neue Textinhalt mit geänderten Namen und Beschreibungen
 */
export const serializeWithNameReplacement = (fileData: any, originalContent: string): string => {
  if (!fileData) {
    console.warn("Keine validen Dateidaten für serializeWithNameReplacement");
    return originalContent || "";
  }
  
  if (!fileData.items || !Array.isArray(fileData.items)) {
    console.warn("Keine validen Dateidaten für serializeWithNameReplacement: items fehlt oder ist kein Array");
    return originalContent || "";
  }
  
  console.log(`Serialisiere mit Namensersetzung für ${fileData.items.length} Items`);
  
  // Sammle die Änderungen zur Übersicht
  const itemsWithChanges = fileData.items.filter(item => 
    item && (item.displayName !== undefined || item.description !== undefined)
  );
  
  if (itemsWithChanges.length === 0) {
    console.log("Keine Änderungen an Namen oder Beschreibungen gefunden");
    return originalContent || "";
  }
  
  // Stelle sicher, dass originalContent ein String ist
  const validOriginalContent = (typeof originalContent === 'string' && originalContent.length > 0) 
    ? originalContent 
    : "";
  
  console.log(`${itemsWithChanges.length} Items mit Namens-/Beschreibungsänderungen gefunden`);
  
  // Hier könnten wir explizit debuggen
  itemsWithChanges.slice(0, 3).forEach(item => {
    const itemId = item.name || item.id || 'unbekannt';
    console.log(`- Item ${itemId}`);
    if (item.displayName !== undefined) console.log(`  Neuer Name: "${item.displayName}"`);
    if (item.description !== undefined) console.log(`  Neue Beschreibung: "${item.description?.substring(0, 30) || ''}..."`);
  });
  
  // Wenn kein gültiger originalContent vorhanden ist, können wir keinen Text erzeugen
  if (!validOriginalContent) {
    console.warn("Kein gültiger originalContent für Ersetzung vorhanden, erstelle neuen Inhalt");
    
    // Versuche einen minimalen Text zu erzeugen basierend auf den vorhandenen Items
    if (fileData.header && Array.isArray(fileData.header)) {
      // Erstelle einen Header und Items-Text, falls header vorhanden ist
      const headerLine = fileData.header.join("\t");
      
      const lines = [headerLine];
      fileData.items.forEach(item => {
        if (item && item.data) {
          const values = fileData.header.map((col: string) => {
            return item.data[col] !== undefined ? item.data[col] : "=";
          });
          lines.push(values.join("\t"));
        }
      });
      
      return lines.join("\n");
    }
    
    // Fallback, wenn auch kein Header vorhanden ist
    return "";
  }
  
  // Starte mit dem Original-Content und bearbeite nur Zeilen, die wirklich geändert werden sollen
  let updatedContent = validOriginalContent;
  
  // Erstelle ein Mapping von Item-IDs zu den tatsächlichen Zeilen und Positionen in der Datei
  const lines = updatedContent.split(/\r?\n/);
  const itemIdToLineMap = new Map<string, number>();
  const namePositionMap = new Map<string, { lineIndex: number, startPos: number, endPos: number, line: string }>();
  const descPositionMap = new Map<string, { lineIndex: number, startPos: number, endPos: number, line: string }>();
  
  // Analysiere die Datei, um Item-IDs den tatsächlichen Zeilen zuzuordnen
  console.log("Analysiere Original-Datei nach Item-IDs und Positionen...");
  lines.forEach((line, index) => {
    const parts = line.split('\t');
    if (parts.length >= 2) {
      // Identifiziere Zeilen, die zum Item gehören könnten
      for (const item of itemsWithChanges) {
        if (!item || !item.id) continue;
        
        const itemId = item.id;
        
        // Prüfe ob diese Zeile das spezifische Item enthält
        if (line.includes(itemId)) {
          itemIdToLineMap.set(itemId, index);
          console.log(`Item ${itemId} gefunden in Zeile ${index + 1}`);
          
          // Versuche auch, Name und Beschreibung Positionen zu identifizieren
          // Dies ist abhängig vom genauen Format der Datei und muss angepasst werden
          const columns = line.split('\t');
          
          // Beispiel für ein Format: Wir suchen nach der Spalte, die den Namen enthält
          // Hier müssen wir die Position in der Zeile finden, an der der Name steht
          for (let i = 0; i < columns.length; i++) {
            // Für Namen (oft in der 2. oder 3. Spalte)
            if (i === 1 || i === 2) {
              let currentPos = 0;
              for (let j = 0; j < i; j++) {
                currentPos += columns[j].length + 1; // +1 für den Tab
              }
              
              namePositionMap.set(itemId, {
                lineIndex: index,
                startPos: currentPos,
                endPos: currentPos + columns[i].length,
                line: line
              });
              
              console.log(`Name für ${itemId} in Spalte ${i+1}, Position ${currentPos}-${currentPos + columns[i].length}`);
            }
            
            // Für Beschreibungen (oft in der 3. oder 4. Spalte)
            if (i === 2 || i === 3) {
              let currentPos = 0;
              for (let j = 0; j < i; j++) {
                currentPos += columns[j].length + 1; // +1 für den Tab
              }
              
              descPositionMap.set(itemId, {
                lineIndex: index,
                startPos: currentPos,
                endPos: currentPos + columns[i].length,
                line: line
              });
              
              console.log(`Beschreibung für ${itemId} in Spalte ${i+1}, Position ${currentPos}-${currentPos + columns[i].length}`);
            }
          }
        }
      }
    }
  });
  
  console.log(`${itemIdToLineMap.size} Items in der Datei lokalisiert`);
  
  // Jetzt machen wir selektive Änderungen nur an den Zeilen, die wirklich geändert werden müssen
  const updatedLines = [...lines];
  
  // Für jedes Item mit Änderungen
  for (const item of itemsWithChanges) {
    if (!item || !item.id) continue;
    
    const itemId = item.id;
    console.log(`Verarbeite Änderungen für Item ${itemId}`);
    
    // Wenn wir das Item in der Datei gefunden haben
    if (itemIdToLineMap.has(itemId)) {
      // Namensänderung
      if (item.displayName !== undefined && namePositionMap.has(itemId)) {
        const nameInfo = namePositionMap.get(itemId)!;
        console.log(`Ändere Namen in Zeile ${nameInfo.lineIndex + 1} von "${nameInfo.line.substring(nameInfo.startPos, nameInfo.endPos)}" zu "${item.displayName}"`);
        
        // Teile die Zeile in Spalten auf
        const columns = updatedLines[nameInfo.lineIndex].split('\t');
        
        // Ersetze die entsprechende Spalte
        for (let i = 0; i < columns.length; i++) {
          if (i === 1 || i === 2) {
            columns[i] = item.displayName;
            break;
          }
        }
        
        // Setze die Zeile wieder zusammen
        updatedLines[nameInfo.lineIndex] = columns.join('\t');
      }
      
      // Beschreibungsänderung
      if (item.description !== undefined && descPositionMap.has(itemId)) {
        const descInfo = descPositionMap.get(itemId)!;
        console.log(`Ändere Beschreibung in Zeile ${descInfo.lineIndex + 1}`);
        
        // Teile die Zeile in Spalten auf
        const columns = updatedLines[descInfo.lineIndex].split('\t');
        
        // Ersetze die entsprechende Spalte
        for (let i = 0; i < columns.length; i++) {
          if (i === 2 || i === 3) {
            columns[i] = item.description;
            break;
          }
        }
        
        // Setze die Zeile wieder zusammen
        updatedLines[descInfo.lineIndex] = columns.join('\t');
      }
    } else {
      console.warn(`Item ${itemId} nicht in der Original-Datei gefunden, Änderungen werden nicht angewendet`);
    }
  }
  
  // Setze die aktualisierten Zeilen wieder zu einem String zusammen
  updatedContent = updatedLines.join('\n');
  
  // Alternative Methode: Verwende reguläre Ausdrücke für gezielte Ersetzungen
  // Dies ist eine Fallback-Methode, falls die Zeilennummerierung nicht funktioniert
  if (updatedContent === validOriginalContent && itemsWithChanges.length > 0) {
    console.log("Keine Änderungen durch direktes Ersetzen gefunden, versuche alternative Methode...");
    
    // Für jedes Item mit Änderungen versuchen wir, den Namen und die Beschreibung zu ersetzen
    for (const item of itemsWithChanges) {
      if (!item || !item.id) continue;
      
      try {
        const itemId = item.id;
        const escItemId = escapeRegExp(itemId);
        
        // Für Namen: Wir suchen Zeilen mit der Item-ID und ersetzen den Namen
        if (item.displayName !== undefined) {
          // Passen Sie diesen regulären Ausdruck je nach Dateiformat an
          const nameRegex = new RegExp(`(.*${escItemId}.*?\\t)([^\\t]+)(\\t.*)`, 'gm');
          
          const beforeReplace = updatedContent;
          updatedContent = updatedContent.replace(nameRegex, (match, before, oldName, after) => {
            console.log(`RegEx: Ändere Namen für ${itemId} von "${oldName}" zu "${item.displayName}"`);
            return `${before}${item.displayName}${after}`;
          });
          
          if (beforeReplace === updatedContent) {
            console.warn(`RegEx: Konnte keinen Namen für Item ${itemId} ersetzen`);
          }
        }
        
        // Für Beschreibungen: Ähnlich wie bei Namen, aber angepasst für Beschreibungen
        if (item.description !== undefined) {
          // Passen Sie diesen regulären Ausdruck je nach Dateiformat an
          const descRegex = new RegExp(`(.*${escItemId}.*?\\t[^\\t]+\\t)([^\\t]*)(\\t.*)`, 'gm');
          
          const beforeReplace = updatedContent;
          updatedContent = updatedContent.replace(descRegex, (match, before, oldDesc, after) => {
            console.log(`RegEx: Ändere Beschreibung für ${itemId}`);
            return `${before}${item.description}${after}`;
          });
          
          if (beforeReplace === updatedContent) {
            console.warn(`RegEx: Konnte keine Beschreibung für Item ${itemId} ersetzen`);
          }
        }
      } catch (error) {
        console.error(`Fehler beim RegEx-Ersetzen für Item ${item.id}:`, error);
      }
    }
  }
  
  // Überprüfung, ob die wichtigsten Änderungen im Text enthalten sind
  let allChangesIncluded = true;
  for (const item of itemsWithChanges.slice(0, 5)) { // Prüfe die ersten 5 Änderungen
    if (item.displayName && !updatedContent.includes(item.displayName)) {
      console.warn(`Warnung: Name "${item.displayName}" nicht im serialisierten Text gefunden!`);
      allChangesIncluded = false;
    }
  }
  
  if (!allChangesIncluded) {
    console.warn("Nicht alle Änderungen wurden in den Text übernommen. Überprüfe das Ergebnis.");
  } else {
    console.log("Alle überprüften Änderungen wurden erfolgreich in den Text übernommen.");
  }
  
  return updatedContent;
};

/**
 * Escapes special characters in a string for use in a regular expression.
 * @param string The string to escape
 * @returns The escaped string
 */
function escapeRegExp(string: string): string {
  return string.replace(/[.*+?^${}()|[\]\\]/g, '\\$&'); // $& means the whole matched string
}

/**
 * Serialisiert für propItem.txt.txt Dateien
 * @param items Items mit Name und Beschreibung
 * @returns String im propItem.txt.txt Format
 */
export const serializePropItems = (
  items: any[],
  existingContent?: string
): string => {
  if (!items || !Array.isArray(items)) {
    console.warn("Ungültige Items für serializePropItems: items fehlt oder ist kein Array");
    return existingContent || "";
  }
  
  // Extrahiere modifizierte Items (mit displayName oder description)
  const modifiedItems = items.filter(item => 
    item && (item.displayName !== undefined || item.description !== undefined)
  );
  
  console.log(`Serialisiere ${modifiedItems.length} propItem-Einträge von ${items.length} Items`);
  
  if (modifiedItems.length === 0) {
    console.warn("Keine Items für propItem.txt.txt gefunden");
    return existingContent || "";
  }
  
  // Sammle alle zu speichernden Entries
  const entries: Map<string, string> = new Map();
  
  // Wenn ein bestehender Inhalt übergeben wurde, verwenden wir diesen als Basis
  if (existingContent && typeof existingContent === 'string' && existingContent.length > 0) {
    // Parse bestehenden Inhalt
    const existingLines = existingContent.split(/\r?\n/);
    
    // Extrahiere alle bestehenden Einträge
    existingLines.forEach(line => {
      const parts = line.split('\t');
      if (parts.length >= 2) {
        entries.set(parts[0], parts[1]);
      }
    });
    
    console.log(`${entries.size} bestehende Einträge extrahiert`);
  }
  
  // Verarbeite alle Items
  modifiedItems.forEach(item => {
    if (!item) {
      console.warn("Ungültiges Item (null/undefined) gefunden");
      return;
    }
    
    // Get the ID from the item's propItem ID
    const propItemId = (item.data?.szName || item.id) as string;
    if (!propItemId) {
      console.warn("Item mit leerer ID gefunden");
      return;
    }
    
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
    
    // Füge Namen hinzu, wenn vorhanden
    if (item.displayName !== undefined) {
      const nameId = `IDS_PROPITEM_TXT_${baseId.toString().padStart(6, '0')}`;
      const entryName = item.displayName || item.name || '';
      
      // Immer den neuen Wert setzen, unabhängig vom alten Wert
      entries.set(nameId, entryName);
      console.log(`PropItem Name: ${nameId} = "${entryName}"`);
    }
    
    // Füge Beschreibung hinzu, wenn vorhanden
    if (item.description !== undefined) {
      const descId = `IDS_PROPITEM_TXT_${(baseId + 1).toString().padStart(6, '0')}`;
      const descriptionText = item.description || '';
      
      // Immer den neuen Wert setzen, unabhängig vom alten Wert
      entries.set(descId, descriptionText);
      console.log(`PropItem Beschreibung: ${descId} = "${descriptionText.substring(0, Math.min(30, descriptionText.length))}${descriptionText.length > 30 ? '...' : ''}"`);
    }
  });
  
  if (entries.size === 0) {
    console.warn("Keine Einträge für propItem.txt.txt gefunden");
    return "";
  }
  
  // Sortiere die Einträge nach ID
  const sortedEntries = Array.from(entries.entries()).sort((a, b) => {
    const idA = parseInt(a[0].match(/\d+/)?.[0] || "0", 10);
    const idB = parseInt(b[0].match(/\d+/)?.[0] || "0", 10);
    return idA - idB;
  });
  
  // Erzeuge den finalen Inhalt
  const lines = sortedEntries.map(([id, value]) => `${id}\t${value}`);
  
  console.log(`${lines.length} Zeilen für propItem.txt.txt erzeugt`);
  
  // Für Windows-Kompatibilität CRLF-Zeilenenden verwenden
  return lines.join('\r\n');
}; 