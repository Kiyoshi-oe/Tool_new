/**
 * Verbesserte Serialisierungsfunktionen für Dateien
 * Diese stellen sicher, dass Änderungen an Namen und Beschreibungen in den Dateien landen
 */

// Importiere die formatItemIconValue-Funktion
import { formatItemIconValue } from './fileOperations';

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
    item && (
      item.displayName !== undefined || 
      item.description !== undefined ||
      item.fields?.specItem?.define !== undefined ||
      item.fields?.specItem?.itemIcon !== undefined ||
      item.fields?.mdlDyna?.fileName !== undefined ||
      (item.effects && item.effects.length > 0) // Hinzugefügt: Prüfe auf Effekte
    )
  );
  
  if (itemsWithChanges.length === 0) {
    console.log("Keine Änderungen gefunden");
    return originalContent || "";
  }
  
  // Stelle sicher, dass originalContent ein String ist
  const validOriginalContent = (typeof originalContent === 'string' && originalContent.length > 0) 
    ? originalContent 
    : "";
  
  console.log(`${itemsWithChanges.length} Items mit Änderungen gefunden`);
  
  // Debug-Ausgabe für die ersten 3 Items
  itemsWithChanges.slice(0, 3).forEach(item => {
    const itemId = item.name || item.id || 'unbekannt';
    console.log(`- Item ${itemId}`);
    if (item.displayName !== undefined) console.log(`  Neuer Name: "${item.displayName}"`);
    if (item.description !== undefined) console.log(`  Neue Beschreibung: "${item.description?.substring(0, 30) || ''}..."`);
    if (item.fields?.specItem?.define !== undefined) console.log(`  Neues Define: "${item.fields.specItem.define}"`);
    if (item.fields?.specItem?.itemIcon !== undefined) {
      console.log(`  Neues Item Icon: "${item.fields.specItem.itemIcon}"`);
      
      // Stelle sicher, dass das Item Icon korrekt formatiert ist
      if (item.fields.specItem.itemIcon && !item.fields.specItem.itemIcon.startsWith('"""')) {
        item.fields.specItem.itemIcon = formatItemIconValue(item.fields.specItem.itemIcon);
        console.log(`  Formatiertes Item Icon: "${item.fields.specItem.itemIcon}"`);
      }
    }
    if (item.fields?.mdlDyna?.fileName !== undefined) console.log(`  Neuer Dateiname: "${item.fields.mdlDyna.fileName}"`);
    
    // Hinzugefügt: Debug-Ausgabe für Effekte
    if (item.effects && item.effects.length > 0) {
      console.log(`  Item hat ${item.effects.length} Effekte`);
      item.effects.forEach((effect: any, index: number) => {
        console.log(`    Effect ${index + 1}: ${effect.type} = ${effect.value}`);
      });
    }
  });
  
  // Wenn kein gültiger originalContent vorhanden ist, erstelle einen neuen
  if (!validOriginalContent) {
    console.warn("Kein gültiger originalContent für Ersetzung vorhanden, erstelle neuen Inhalt");
    
    // Erstelle einen Header und Items-Text
    const header = [
      'ID',
      'Define',
      'Item Icon',
      'Display Name',
      'Description',
      'Effects'
    ];
    
    const lines = [header.join('\t')];
    fileData.items.forEach(item => {
      if (item) {
        // Stelle sicher, dass alle Werte korrekt formatiert sind
        let itemIcon = item.fields?.specItem?.itemIcon || '';
        if (itemIcon && !itemIcon.startsWith('"""')) {
          itemIcon = formatItemIconValue(itemIcon);
        }
        
        const values = [
          item.id || '',
          item.fields?.specItem?.define || '',
          itemIcon,
          item.fields?.specItem?.displayName || item.displayName || '',
          item.fields?.specItem?.description || item.description || '',
          item.effects ? JSON.stringify(item.effects) : ''
        ];
        lines.push(values.join('\t'));
      }
    });
    
    return lines.join('\n');
  }
  
  // Starte mit dem Original-Content und bearbeite nur Zeilen, die wirklich geändert werden sollen
  let updatedContent = validOriginalContent;
  
  // Erstelle ein Mapping von Item-IDs zu den tatsächlichen Zeilen und Positionen in der Datei
  const lines = updatedContent.split(/\r?\n/);
  const itemIdToLineMap = new Map<string, number>();
  const fieldPositionMap = new Map<string, Map<string, { lineIndex: number, startPos: number, endPos: number, line: string }>>();
  
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
          
          // Initialisiere das Field-Map für dieses Item, falls noch nicht vorhanden
          if (!fieldPositionMap.has(itemId)) {
            fieldPositionMap.set(itemId, new Map());
          }
          
          // Finde die Positionen für alle Felder
          const columns = line.split('\t');
          let currentPos = 0;
          
          columns.forEach((col, i) => {
            const fieldMap = fieldPositionMap.get(itemId)!;
            
            // Speichere die Position für jedes relevante Feld
            if (i === 1) fieldMap.set('define', { lineIndex: index, startPos: currentPos, endPos: currentPos + col.length, line });
            if (i === 2) fieldMap.set('itemIcon', { lineIndex: index, startPos: currentPos, endPos: currentPos + col.length, line });
            if (i === 3) fieldMap.set('displayName', { lineIndex: index, startPos: currentPos, endPos: currentPos + col.length, line });
            if (i === 4) fieldMap.set('description', { lineIndex: index, startPos: currentPos, endPos: currentPos + col.length, line });
            
            // Hinzugefügt: Speichere die Positionen für dwDestParam1-6 und nAdjParamVal1-6
            // Annahme: dwDestParam1 ist die 82. Spalte (0-indexiert) in der Spec_item.txt
            if (i >= 82 && i <= 87) {
              fieldMap.set(`dwDestParam${i - 81}`, { lineIndex: index, startPos: currentPos, endPos: currentPos + col.length, line });
            }
            
            // Annahme: nAdjParamVal1 ist die 88. Spalte (0-indexiert) in der Spec_item.txt
            if (i >= 88 && i <= 93) {
              fieldMap.set(`nAdjParamVal${i - 87}`, { lineIndex: index, startPos: currentPos, endPos: currentPos + col.length, line });
            }
            
            currentPos += col.length + 1; // +1 für den Tab
          });
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
      const fieldMap = fieldPositionMap.get(itemId);
      if (!fieldMap) continue;
      
      // Teile die Zeile in Spalten auf
      const columns = updatedLines[itemIdToLineMap.get(itemId)!].split('\t');
      
      // Aktualisiere die Felder
      if (item.fields?.specItem?.define !== undefined) {
        const fieldInfo = fieldMap.get('define');
        if (fieldInfo) {
          columns[1] = item.fields.specItem.define;
        }
      }
      
      if (item.fields?.specItem?.itemIcon !== undefined) {
        const fieldInfo = fieldMap.get('itemIcon');
        if (fieldInfo) {
          // Stelle sicher, dass das Item Icon korrekt formatiert ist (mit dreifachen Anführungszeichen)
          // Direkter Aufruf von formatItemIconValue
          const iconValue = item.fields.specItem.itemIcon;
          // Entferne alle Anführungszeichen und füge dreifache hinzu
          const cleanIcon = iconValue.replace(/^["']{0,3}|["']{0,3}$/g, '');
          const formattedIcon = `"""${cleanIcon}"""`;
          
          columns[2] = formattedIcon;
          console.log(`Item Icon formatiert: "${columns[2]}"`);
        }
      }
      
      if (item.fields?.specItem?.displayName !== undefined || item.displayName !== undefined) {
        const fieldInfo = fieldMap.get('displayName');
        if (fieldInfo) {
          columns[3] = item.fields?.specItem?.displayName || item.displayName;
        }
      }
      
      if (item.fields?.specItem?.description !== undefined || item.description !== undefined) {
        const fieldInfo = fieldMap.get('description');
        if (fieldInfo) {
          columns[4] = item.fields?.specItem?.description || item.description;
        }
      }
      
      // Hinzugefügt: Aktualisiere dwDestParam1-6 und nAdjParamVal1-6 basierend auf den Effekten
      if (item.effects && Array.isArray(item.effects)) {
        console.log(`Aktualisiere Effekte für Item ${itemId}: ${JSON.stringify(item.effects)}`);
        
        // Zuerst setze alle Effekt-Spalten auf NONE/_NONE oder leer, um alte Werte zu löschen
        for (let i = 0; i < 6; i++) {
          // Position in columns berechnen: dwDestParam1 ist in column 82 (0-indexiert)
          const dwDestParamIndex = 82 + i;
          // Position in columns berechnen: nAdjParamVal1 ist in column 88 (0-indexiert)
          const nAdjParamValIndex = 88 + i;
          
          // Stelle sicher, dass die Spalten-Arrays groß genug sind
          while (columns.length <= nAdjParamValIndex) {
            columns.push("=");
          }
          
          // Setze Standardwerte
          columns[dwDestParamIndex] = "_NONE";
          columns[nAdjParamValIndex] = "=";
        }
        
        // Durchlaufe alle vorhandenen Effekte (maximal 6)
        for (let i = 0; i < Math.min(item.effects.length, 6); i++) {
          const effect = item.effects[i];
          
          if (!effect || !effect.type || effect.type === '-' || effect.type === '_NONE') {
            continue; // Überspringe leere oder ungültige Effekte
          }
          
          // dwDestParam Feld aktualisieren (1-indexiert im Spaltennamen, aber 0-indexiert im Array)
          const dwDestParamIndex = 82 + i;
          // nAdjParamVal Feld aktualisieren
          const nAdjParamValIndex = 88 + i;
          
          // Stelle sicher, dass die Spalten-Arrays groß genug sind
          while (columns.length <= nAdjParamValIndex) {
            columns.push("=");
          }
          
          // Setze den Typ und Wert wenn vorhanden
          if (effect.type && effect.type !== '-') {
            columns[dwDestParamIndex] = effect.type;
            columns[nAdjParamValIndex] = effect.value !== undefined ? effect.value.toString() : "0";
            console.log(`Setze Effekt ${i+1} für Item ${itemId}: ${effect.type}=${effect.value}`);
          }
        }
      }
      
      // Setze die Zeile wieder zusammen
      updatedLines[itemIdToLineMap.get(itemId)!] = columns.join('\t');
    } else {
      console.warn(`Item ${itemId} nicht in der Original-Datei gefunden, Änderungen werden nicht angewendet`);
    }
  }
  
  // Setze die aktualisierten Zeilen wieder zu einem String zusammen
  updatedContent = updatedLines.join('\n');
  
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