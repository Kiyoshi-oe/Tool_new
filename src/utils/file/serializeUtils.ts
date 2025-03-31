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
  if (!fileData || !fileData.items || !Array.isArray(fileData.items)) {
    console.warn("Keine validen Dateidaten für serializeWithNameReplacement");
    return originalContent;
  }
  
  console.log(`Serialisiere mit Namensersetzung für ${fileData.items.length} Items`);
  
  // Sammle die Änderungen zur Übersicht
  const itemsWithChanges = fileData.items.filter(item => 
    item.displayName !== undefined || item.description !== undefined
  );
  
  if (itemsWithChanges.length === 0) {
    console.log("Keine Änderungen an Namen oder Beschreibungen gefunden");
    return originalContent;
  }
  
  console.log(`${itemsWithChanges.length} Items mit Namens-/Beschreibungsänderungen gefunden`);
  
  // Hier könnten wir explizit debuggen
  itemsWithChanges.slice(0, 3).forEach(item => {
    console.log(`- Item ${item.name || item.id || 'unbekannt'}`);
    if (item.displayName !== undefined) console.log(`  Neuer Name: "${item.displayName}"`);
    if (item.description !== undefined) console.log(`  Neue Beschreibung: "${item.description.substring(0, 30)}..."`);
  });
  
  // Starte mit dem Original-Content
  let updatedContent = originalContent;
  
  // Für jedes Item mit Änderungen
  for (const item of itemsWithChanges) {
    if (!item.name && !item.id) continue;
    
    // Wir benötigen einen Namen oder eine ID für die Suche im Text
    const searchName = item.name || item.id;
    
    // Für die Suche nach Namen im Text verwenden wir eine Heuristik:
    // Namen stehen meist nach '\t' (Tab) oder ähnlichen Begrenzern
    try {
      // Wir wissen, dass der Name in einer bestimmten Formatierung im Text steht
      // Da jeder Item-Eintrag anders strukturiert sein kann, müssen wir ggf. mehrere Ansätze probieren
      
      // Ansatz 1: Name steht nach einem Tab und vor einem Zeilenumbruch
      if (item.displayName !== undefined && item.oldName) {
        // Wenn wir den alten Namen kennen, ist die Ersetzung einfacher
        const pattern = new RegExp(`(\\t|\\s+)${escapeRegExp(item.oldName)}(\\s*$|\\r?\\n)`, 'gm');
        updatedContent = updatedContent.replace(pattern, `$1${item.displayName}$2`);
      } else if (item.displayName !== undefined) {
        // Wenn wir item.name oder eine andere Kennung haben, versuchen wir, den Namen zu finden
        // Dies ist weniger präzise, aber wir können es versuchen
        const possiblePatterns = [
          new RegExp(`^(.*${escapeRegExp(searchName)}.*?\\t)([^\\t\\r\\n]+)(\\s*$|\\r?\\n)`, 'gm'),
          new RegExp(`(\\t)([^\\t\\r\\n]+)(\\s*\\t${escapeRegExp(searchName)})`, 'gm')
        ];
        
        for (const pattern of possiblePatterns) {
          const beforeReplace = updatedContent;
          updatedContent = updatedContent.replace(pattern, (match, p1, p2, p3) => {
            return `${p1}${item.displayName}${p3}`;
          });
          
          if (beforeReplace !== updatedContent) {
            console.log(`Name für "${searchName}" erfolgreich ersetzt zu "${item.displayName}"`);
            break;
          }
        }
      }
      
      // Beschreibungen folgen oft einem ähnlichen Muster
      if (item.description !== undefined) {
        // Ähnliche Ansätze wie bei Namen, aber für Beschreibungen
        // Dies kann je nach Dateiformat angepasst werden
        const possiblePatterns = [
          new RegExp(`^(.*${escapeRegExp(searchName)}.*?\\t)([^\\t]*\\t)([^\\t\\r\\n]+)(\\s*$|\\r?\\n)`, 'gm'),
          new RegExp(`(\\t)([^\\t\\r\\n]+)(\\s*\\t${escapeRegExp(searchName)})`, 'gm')
        ];
        
        for (const pattern of possiblePatterns) {
          const beforeReplace = updatedContent;
          updatedContent = updatedContent.replace(pattern, (match, p1, p2, p3, p4) => {
            // Bei Beschreibungen ist p3 meist die Beschreibung
            return `${p1}${p2}${item.description}${p4 || ''}`;
          });
          
          if (beforeReplace !== updatedContent) {
            console.log(`Beschreibung für "${searchName}" erfolgreich ersetzt`);
            break;
          }
        }
      }
    } catch (error) {
      console.warn(`Fehler beim Ersetzen von Name/Beschreibung für ${searchName}:`, error);
    }
  }
  
  // Als Fallback, wenn keine Ersetzungen funktioniert haben: Verwende die generierte Version
  if (updatedContent === originalContent && itemsWithChanges.length > 0) {
    console.warn("Keine Änderungen im Text gefunden, generiere neuen Text");
    
    // Header-Zeile finden
    const firstLineEnd = originalContent.indexOf('\n');
    const header = firstLineEnd > 0 ? originalContent.substring(0, firstLineEnd) : '';
    
    if (header) {
      const headerColumns = header.split('\t');
      
      // Generiere Zeilen für jedes Item
      const dataLines = fileData.items.map((item: any) => {
        // Stelle sicher, dass wir alle Spalten in der richtigen Reihenfolge ausgeben
        const values = headerColumns.map((col: string) => {
          return item.data && item.data[col] !== undefined ? item.data[col] : "=";
        });
        
        return values.join('\t');
      });
      
      // Setze den neuen Inhalt zusammen
      updatedContent = [header, ...dataLines].join('\n');
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
export const serializePropItems = (items: any[]): string => {
  const lines: string[] = [];
  
  // Only include items that have been modified
  const modifiedItems = items.filter(item => 
    item.displayName !== undefined || 
    item.description !== undefined
  );
  
  console.log(`Serialisiere ${modifiedItems.length} modifizierte propItem-Einträge von ${items.length} Items`);
  
  modifiedItems.forEach(item => {
    if (!item.data?.szName && !item.id) {
      console.warn("Item ohne szName oder id gefunden:", item);
      return;
    }
    
    // Get the ID from the item's propItem ID
    const propItemId = (item.data?.szName || item.id) as string;
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
      lines.push(`${nameId}\t${entryName}`);
      console.log(`PropItem Name: ${nameId} = "${entryName}"`);
    }
    
    // Füge Beschreibung hinzu, wenn vorhanden
    if (item.description !== undefined) {
      const descId = `IDS_PROPITEM_TXT_${(baseId + 1).toString().padStart(6, '0')}`;
      lines.push(`${descId}\t${item.description || ''}`);
      console.log(`PropItem Beschreibung: ${descId} = "${item.description?.substring(0, 30)}..."`);
    }
  });
  
  // Für Windows-Kompatibilität CRLF-Zeilenenden verwenden
  return lines.join('\r\n');
}; 