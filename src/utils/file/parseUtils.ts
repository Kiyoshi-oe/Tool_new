import { FileData, ResourceItem, ItemData, EffectData } from "../../types/fileTypes";

// Interface for propItem data mapping
interface PropItemMapping {
  [key: string]: { name: string; displayName: string; description: string };
}

// Global variable to store propItem mappings for use in parsing
let propItemMappings: PropItemMapping = {};

// Globale Variable für defineItem Mappings
let defineItemEffectMappings: { [key: string]: EffectData[] } = {};

/**
 * Setzt das Mapping für die propItem.txt.txt-Datei
 * @param mappings Das Mapping-Objekt mit den Zuordnungen
 */
export const setPropItemMappings = (mappings: PropItemMapping) => {
  propItemMappings = mappings;
  console.log(`PropItem-Mappings gesetzt mit ${Object.keys(mappings).length} Einträgen`);
};

/**
 * Setzt das Mapping für die defineItem.h-Datei
 * @param mappings Das Mapping-Objekt mit den Zuordnungen von defineItems zu effects
 */
export const setDefineItemEffectMappings = (mappings: { [key: string]: EffectData[] }) => {
  defineItemEffectMappings = mappings;
  console.log(`DefineItem-Effect-Mappings gesetzt mit ${Object.keys(mappings).length} Einträgen`);
};

/**
 * Parst eine txt- oder csv-Datei und gibt die extrahierten Daten zurück
 * @param data Der Inhalt der Datei
 * @returns Ein Objekt mit Header und Items
 */
export const parseFileContent = (data: string): FileData => {
  if (!data) {
    console.error("Leerer Dateiinhalt wurde zum Parsen übergeben");
    return { header: [], items: [] };
  }
  
  // Bestimme den Dateityp
  const isTabSeparated = data.includes('\t');
  const isCommaSeparated = data.includes(',');
  
  // Entferne BOM (Byte Order Mark) falls vorhanden
  let cleanedData = data;
  if (data.charCodeAt(0) === 0xFEFF) {
    cleanedData = data.slice(1);
  }
  
  // Teile den Inhalt in Zeilen auf
  const lines = cleanedData.split(/\r?\n/);
  
  console.log(`Datei hat ${lines.length} Zeilen, prüfe Format...`);
  
  // Prüfe, ob es sich um das Format aus einer propItem.txt.txt handelt
  if (lines.length > 0 && lines[0].includes('IDS_PROPITEM_TXT_')) {
    return parsePropItemFormat(lines);
  }
  
  // Prüfe, ob es sich um das Format aus einer Spec_item.txt handelt
  const firstLine = lines[0];
  if (firstLine && firstLine.includes('dwID') && firstLine.includes('szName')) {
    return parseSpecItemFormat(lines);
  }
  
  // Fallback auf allgemeines Format
  if (isTabSeparated) {
    return parseTabSeparated(lines);
  } else if (isCommaSeparated) {
    return parseCommaSeparated(lines);
  }
  
  // Wenn kein spezifisches Format erkannt wurde, als Tab-getrennt behandeln
  console.warn("Kein spezifisches Format erkannt, versuche Tab-getrenntes Format");
  return parseTabSeparated(lines);
};

/**
 * Extrahiert den Display-Namen aus einem propItem.txt.txt-Eintrag
 * @param id Die ID des propItem-Eintrags
 * @returns Der extrahierte Name oder die ursprüngliche ID, falls nicht gefunden
 */
export const getPropItemDisplayName = (id: string): string => {
  // Überprüfe, ob das Mapping vorhanden und die ID enthalten ist
  if (propItemMappings && propItemMappings[id]) {
    return propItemMappings[id].displayName || id;
  }
  
  // Wenn nicht gefunden, gebe die ursprüngliche ID zurück
  return id;
};

/**
 * Extrahiert die Beschreibung aus einem propItem.txt.txt-Eintrag
 * @param id Die ID des propItem-Eintrags
 * @returns Die extrahierte Beschreibung oder eine leere Zeichenkette, falls nicht gefunden
 */
export const getPropItemDescription = (id: string): string => {
  // Überprüfe, ob das Mapping vorhanden und die ID enthalten ist
  if (propItemMappings && propItemMappings[id]) {
    return propItemMappings[id].description || '';
  }
  
  // Wenn nicht gefunden, gebe eine leere Zeichenkette zurück
  return '';
};

/**
 * Extrahiert Effekte aus den Spalten dwDestParam1-6 und nAdjParamVal1-6
 * @param data Die ItemData mit den dwDestParam und nAdjParamVal Spalten
 * @returns Array von EffectData Objekten
 */
export const extractEffectsFromData = (data: any): EffectData[] => {
  if (!data) return [];
  
  const effects: EffectData[] = [];
  
  // Extrahiere bis zu 6 Effekte aus den dwDestParam und nAdjParamVal Spalten
  for (let i = 1; i <= 6; i++) {
    const typeKey = `dwDestParam${i}`;
    const valueKey = `nAdjParamVal${i}`;
    
    // Prüfe ob der Typ vorhanden und nicht '_NONE' ist
    if (data[typeKey] && data[typeKey] !== '_NONE' && data[typeKey] !== '=' && data[typeKey] !== '-') {
      effects.push({
        type: data[typeKey],
        value: data[valueKey] || '0'
      });
    }
  }
  
  console.log(`Extrahierte ${effects.length} Effekte aus dwDestParam/nAdjParamVal`);
  return effects;
}

/**
 * Parst Daten im propItem.txt.txt Format
 */
function parsePropItemFormat(lines: string[]): FileData {
  console.log("Detected propItem.txt.txt format");
  
  if (lines.length === 0) {
    return { header: ["ID", "Value"], items: [] };
  }
  
  const items: ResourceItem[] = [];
  const propItemMap: { [key: string]: { name: string; description: string } } = {};
  
  // Gruppiere die Einträge nach ID
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();
    if (!line) continue;
    
    const parts = line.split('\t');
    if (parts.length < 2) continue;
    
    const id = parts[0].trim();
    const value = parts[1].trim();
    
    if (id.startsWith('IDS_PROPITEM_TXT_')) {
      // Extrahiere die Basis-ID (Nummer ohne führende Nullen)
      const idMatch = id.match(/IDS_PROPITEM_TXT_(\d+)/);
      if (!idMatch) continue;
      
      const baseId = parseInt(idMatch[1], 10);
      
      // Gerade Zahlen sind Namen, ungerade sind Beschreibungen
      if (baseId % 2 === 0) {
        // Name (gerade ID)
        propItemMap[id] = propItemMap[id] || { name: value, description: "" };
        propItemMap[id].name = value;
      } else {
        // Beschreibung (ungerade ID = baseId - 1 + 1)
        const nameId = `IDS_PROPITEM_TXT_${(baseId - 1).toString().padStart(6, '0')}`;
        propItemMap[nameId] = propItemMap[nameId] || { name: "", description: value };
        propItemMap[nameId].description = value;
      }
    }
  }
  
  // Konvertiere das Map in ResourceItem-Objekte
  Object.entries(propItemMap).forEach(([id, { name, description }]) => {
    items.push({
      id,
      name,
      displayName: name,
      description,
      idPropItem: id,
      data: { dwID: id },
      effects: []
    });
  });
  
  console.log(`Parsed ${items.length} items from propItem.txt.txt format`);
  return { header: ["ID", "Value"], items };
}

/**
 * Parst Daten im Tab-getrennten Format
 */
function parseTabSeparated(lines: string[]): FileData {
  console.log("Parsing generic tab-separated format");
  
  if (lines.length === 0) {
    return { header: [], items: [] };
  }
  
  // Erste Zeile ist der Header
  const header = lines[0].split('\t').map(h => h.trim());
  console.log(`Header columns: ${header.length}`);
  
  const items: ResourceItem[] = [];
  
  // Verarbeite die Datenzeilen
  for (let i = 1; i < lines.length; i++) {
    const line = lines[i].trim();
    if (!line) continue;
    
    const values = line.split('\t');
    if (values.length < 1) continue;
    
    const data: ItemData = {};
    
    // Weise Werte den Header-Spalten zu
    for (let j = 0; j < Math.min(header.length, values.length); j++) {
      const columnName = header[j];
      const value = values[j].trim();
      data[columnName] = value;
    }
    
    // Versuche, ID und Name aus den Daten zu extrahieren
    const id = data.id || data.ID || data.dwID || `item_${i}`;
    const name = data.name || data.NAME || data.szName || id;
    
    items.push({
      id: String(id),
      name: String(name),
      displayName: String(name),
      description: data.description ? String(data.description) : (data.DESCRIPTION ? String(data.DESCRIPTION) : ''),
      data,
      effects: []
    });
  }
  
  console.log(`Parsed ${items.length} items from tab-separated format`);
  return { header, items };
}

/**
 * Parst Daten im Komma-getrennten Format (CSV)
 */
function parseCommaSeparated(lines: string[]): FileData {
  console.log("Parsing comma-separated (CSV) format");
  
  if (lines.length === 0) {
    return { header: [], items: [] };
  }
  
  // Erste Zeile ist der Header
  const header = lines[0].split(',').map(h => h.trim());
  console.log(`Header columns: ${header.length}`);
  
  const items: ResourceItem[] = [];
  
  // Verarbeite die Datenzeilen
  for (let i = 1; i < lines.length; i++) {
    const line = lines[i].trim();
    if (!line) continue;
    
    // Einfache CSV-Verarbeitung (keine Berücksichtigung von Anführungszeichen oder Escape-Sequenzen)
    const values = line.split(',');
    if (values.length < 1) continue;
    
    const data: ItemData = {};
    
    // Weise Werte den Header-Spalten zu
    for (let j = 0; j < Math.min(header.length, values.length); j++) {
      const columnName = header[j];
      const value = values[j].trim();
      data[columnName] = value;
    }
    
    // Versuche, ID und Name aus den Daten zu extrahieren
    const id = data.id || data.ID || data.dwID || `item_${i}`;
    const name = data.name || data.NAME || data.szName || id;
    
    items.push({
      id: String(id),
      name: String(name),
      displayName: String(name),
      description: data.description ? String(data.description) : (data.DESCRIPTION ? String(data.DESCRIPTION) : ''),
      data,
      effects: []
    });
  }
  
  console.log(`Parsed ${items.length} items from comma-separated format`);
  return { header, items };
}

/**
 * Spezielle Parsing-Funktion für Spec_item.txt Format
 */
function parseSpecItemFormat(lines: string[]): FileData {
  console.log("Detected spec_item.txt format with tabs as delimiters");
  
  if (lines.length === 0) {
    return { header: [], items: [] };
  }
  
  // Bei spec_item.txt ist die erste Zeile der Header
  const header = lines[0].split("\t").map(h => h.trim());
  console.log(`Header columns in spec_item.txt: ${header.length}`);
  
  const items: ResourceItem[] = [];
  
  // Performance-Optimierung: Verwende größere Batches für moderne Computer
  const totalLines = lines.length - 1;
  const isLargeFile = totalLines > 50000;
  
  // Dynamische Batch-Größe basierend auf Dateigroße
  const batchSize = isLargeFile ? 5000 : 2000;
  const totalBatches = Math.ceil(totalLines / batchSize);
  
  console.log(`Performance-Optimierung: ${isLargeFile ? 'Große' : 'Normale'} Datei erkannt, 
               verwende Batch-Größe von ${batchSize} (${totalBatches} Batches)`);
  
  // Performance-Optimierung: Webworker für Parallelverarbeitung nutzen (wenn verfügbar)
  const supportsWorkers = typeof Worker !== 'undefined';
  let useWorkers = isLargeFile && supportsWorkers && totalBatches > 4;
  
  // Cache für Spaltenindizes, um wiederholte header.indexOf-Aufrufe zu vermeiden
  const headerLength = header.length;
  
  // Webworker sind für diese Art von Daten oft langsamer wegen der Overhead-Kosten
  useWorkers = false;
  
  if (useWorkers) {
    console.log('Webworker-Unterstützung noch nicht implementiert, falle zurück auf sequentielles Parsen');
    // TODO: Implementiere Webworker-Unterstützung für paralleles Parsen
  }
  
  // Sequentielles Parsen
  {
    for (let batchIndex = 0; batchIndex < totalBatches; batchIndex++) {
      const startLine = 1 + batchIndex * batchSize;
      const endLine = Math.min(startLine + batchSize, lines.length);
      
      console.log(`Verarbeite Batch ${batchIndex + 1}/${totalBatches} (Zeilen ${startLine} bis ${endLine})`);
      
      for (let i = startLine; i < endLine; i++) {
        const line = lines[i].trim();
        if (!line) continue; // Skip empty lines
        
        const values = line.split("\t");
        if (values.length < 2) continue; // Skip invalid lines with less than 2 columns
        
        // Performance-Optimierung: Direktes Objekt-Literal statt wiederholter Zuweisung
        const data: ItemData = {};
        let id = "";
        let name = "";
        
        // Performance-Optimierung: Spezialfall für SpecItem Format mit festen Spalten
        if (headerLength === values.length) {
          // Schnellerer Pfad wenn Header und Werte genau übereinstimmen
          for (let j = 0; j < headerLength; j++) {
            const colName = header[j];
            if (!colName) continue;
            
            const value = values[j].trim();
            data[colName] = value;
            
            // Extract ID and name for reference
            if (colName === "//dwID" || colName === "dwID") {
              id = value;
              data["dwID"] = value;
            } else if (colName === "szName") {
              name = value;
            }
          }
        } else {
          // Fallback für unterschiedliche Längen
          // Map values to column names from the header
          for (let j = 0; j < Math.min(headerLength, values.length); j++) {
            const colName = header[j];
            if (!colName) continue;
            
            const value = values[j].trim();
            data[colName] = value;
            
            // Extract ID and name for reference
            if (colName === "//dwID" || colName === "dwID") {
              id = value;
              data["dwID"] = value;
            } else if (colName === "szName") {
              name = value;
            }
          }
        }
        
        // Performance-Optimierung: Minimiere propItemMappings Zugriffe
        // Nur bei vorhandener ID weitermachen
        if (id) {
          // Get the name and description from propItem mappings if available
          let displayName = name;
          let description = '';
          let idPropItem = name; // Store the original propItem ID 
          
          // Performance-Optimierung: Reduzieren der Lookup-Operationen
          const propItemCount = Object.keys(propItemMappings).length;
          
          // Only lookup in propItemMappings if we have entries and name is not empty
          if (propItemCount > 0 && name) {
            // Direkter Zugriff auf das Mapping, ohne mehrfache Prüfungen
            const mapping = propItemMappings[name];
            
            if (mapping) {
              displayName = mapping.displayName || name;
              description = mapping.description || '';
            } 
            // Nur komplexe Fallback-Logik verwenden, wenn nötig (IDS_PROPITEM)
            else if (name.includes("IDS_PROPITEM_TXT_")) {
              const propItemName = getPropItemDisplayName(name);
              if (propItemName !== name) {
                displayName = propItemName;
              }
            }
          }
          
          // Extrahiere Effekte aus den dwDestParam und nAdjParamVal Spalten
          const effects = extractEffectsFromData(data);
          
          // Performance-Optimierung: Direkt ins items-Array pushen statt über Zwischenbatch
          items.push({
            id,
            name,
            displayName,
            description,
            idPropItem,
            data,
            effects // Befülle effects statt leerem Array
          });
        } else if (name) {
          // Für Elemente ohne ID, aber mit Namen
          items.push({
            id: `auto_${i}`,
            name,
            displayName: name,
            description: '',
            idPropItem: '',
            data,
            effects: [], // Leeres Array, da keine vollständigen Daten vorhanden
          });
        }
        // Performance-Optimierung: Skip Items ohne ID und ohne Namen
      }
      
      // Performance-Optimierung: Batch nicht mehr verwenden, da direkt in items eingefügt wird
      
      // Versuche Speicher freizugeben bei großen Dateien
      if (isLargeFile && batchIndex % 4 === 3 && global.gc) {
        global.gc();
      }
    }
  }
  
  console.log(`Geparst: ${items.length} Items aus spec_item.txt Format`);
  
  // Für bessere Performance keine Effekte direkt laden sondern on-demand
  return { header, items };
}

// Exportiere parseTextFile als Alias für parseFileContent
export const parseTextFile = parseFileContent;

// ... Rest der Datei unverändert ...
