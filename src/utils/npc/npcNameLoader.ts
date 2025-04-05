import { toast } from 'sonner';

// Typdefinition für das Ergebnis
export interface NpcNameMap {
  [id: string]: { name: string };
}

// Hilfsfunktion zum Laden einer Datei mittels fetch
const loadFile = async (filePath: string): Promise<string> => {
  try {
    const response = await fetch(filePath);
    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status} for ${filePath}`);
    }
    const buffer = await response.arrayBuffer();
    const decoder = new TextDecoder('windows-1252'); 
    const text = decoder.decode(buffer);
    if (text.charCodeAt(0) === 0xFEFF) {
        return text.substring(1);
    }
    return text;
  } catch (error) {
    console.error(`Error loading file ${filePath}:`, error);
    toast.error(`Failed to load resource file: ${filePath}`);
    throw error; // Re-throw error to be caught by the caller
  }
};

// Parsen von propMover.txt
const parsePropMover = (content: string): { [id: string]: { reference: string } } => {
  const npcs: { [id: string]: { reference: string } } = {};
  const lines = content.split(/\r?\n/);
  // Verwende eine weniger strenge Regex, die IDS_PROPMOVER_TXT_ + Zahlen findet,
  // aber nicht unbedingt am Anfang der Zeile
  const idRegex = /(IDS_PROPMOVER_TXT_\d+)/;

  lines.forEach(line => {
    const trimmedLine = line.trim();
    if (trimmedLine && !trimmedLine.startsWith('//')) {
      const parts = trimmedLine.split(/\t+/);
      if (parts.length >= 2) {
        const npcId = parts[0].trim();
        const potentialRef = parts[1].trim(); 
        const match = potentialRef.match(idRegex);
        const npcNameRef = match ? match[0] : null;
        if (npcId && npcNameRef) {
          npcs[npcId] = { reference: npcNameRef };
        }
      }
    }
  });
  return npcs;
};

// Parsen von propMover.txt.txt (Übersetzungen)
const parsePropMoverNames = (content: string): { [reference: string]: string } => {
  const names: { [reference: string]: string } = {};
  const lines = content.split(/\r?\n/);
  
  console.log(`Processing ${lines.length} lines from propMover.txt.txt`);
  
  // Verarbeitungsstrategie: Jede zweite Zeile enthält einen Namen, dazwischen sind Beschreibungen
  // Wir interessieren uns nur für die Namen (gerade IDs)
  
  lines.forEach((line, index) => {
    if (!line || line.trim().startsWith('//')) {
      return; // Überspringe Kommentare und leere Zeilen
    }
    
    // Teile die Zeile anhand von Tabs
    const parts = line.split('\t').map(p => p.trim());
    
    if (parts.length >= 1) {
      const key = parts[0];
      
      // Überprüfe, ob es sich um eine ID-Schlüssel handelt
      if (key.includes("IDS_PROPMOVER_TXT_")) {
        // Extrahiere die ID-Nummer aus dem Schlüssel
        const idMatch = key.match(/IDS_PROPMOVER_TXT_(\d+)/);
        
        if (idMatch && idMatch[1]) {
          const idNumber = parseInt(idMatch[1], 10);
          
          // Nur gerade IDs enthalten Namen (0, 2, 4, ...)
          // Ungerade IDs sind Beschreibungen (1, 3, 5, ...)
          if (idNumber % 2 === 0) {
            const name = parts.length >= 2 ? parts[1] : "";
            
            // Speichere den Namen mit dem originalen Schlüssel (wichtig für das Mapping)
            names[key] = name;
            
            if (Object.keys(names).length <= 5) {
              console.log(`Added name mapping: "${key}" -> "${name}"`);
            }
          }
        }
      }
    }
  });
  
  const namesCount = Object.keys(names).length;
  console.log(`Parsed ${namesCount} name mappings from propMover.txt.txt`);
  
  return names;
};

// Laden & Kombinieren der Daten - Debugging-Logs hinzufügen
export const loadNpcNamesAndIds = async (): Promise<NpcNameMap> => {
  try {
    // Debug vor dem Laden
    console.log("Starting to load propMover files...");
    
    const [propMoverContent, propMoverNamesContent] = await Promise.all([
      loadFile('/resource/propMover.txt'),
      loadFile('/resource/propMover.txt.txt')
    ]);
    
    // Debug nach dem Laden
    console.log(`propMover.txt: ${propMoverContent.length} bytes loaded`);
    console.log(`propMover.txt.txt: ${propMoverNamesContent.length} bytes loaded`);

    const npcDataTemp = parsePropMover(propMoverContent);
    const nameData = parsePropMoverNames(propMoverNamesContent);

    // Prüfen, ob wir Daten haben
    console.log(`NPC references from propMover.txt: ${Object.keys(npcDataTemp).length}`);
    console.log(`Names from propMover.txt.txt: ${Object.keys(nameData).length}`);
    
    // Erste paar Einträge anzeigen
    const npcKeys = Object.keys(npcDataTemp);
    if (npcKeys.length > 0) {
      console.log("Sample NPC references:");
      for (let i = 0; i < Math.min(3, npcKeys.length); i++) {
        const key = npcKeys[i];
        console.log(`${key} -> ${npcDataTemp[key].reference}`);
      }
    }
    
    const nameKeys = Object.keys(nameData);
    if (nameKeys.length > 0) {
      console.log("Sample name mappings:");
      for (let i = 0; i < Math.min(3, nameKeys.length); i++) {
        const key = nameKeys[i];
        console.log(`${key} -> "${nameData[key]}"`);
      }
    }

    const finalNpcData: NpcNameMap = {};

    // Optional: Überprüfen, ob die Referenzen übereinstimmen
    let matchCount = 0;
    Object.keys(npcDataTemp).forEach(npcId => {
      const nameReference = npcDataTemp[npcId].reference;
      const foundName = nameData[nameReference];
      
      if (foundName !== undefined) {
        matchCount++;
      } else if (matchCount < 5) { // Log nur die ersten paar Fehler
        console.log(`No match found for "${nameReference}" from NPC "${npcId}"`);
      }
      
      finalNpcData[npcId] = {
          name: (foundName !== undefined) ? foundName : `_MISSING_NAME_(${nameReference || 'NO_REF'})`
      };
    });
    
    console.log(`Found ${matchCount} matching names out of ${Object.keys(npcDataTemp).length} NPCs`);

    if (Object.keys(finalNpcData).length === 0) {
      console.warn("No NPC names could be loaded or mapped.");
      toast.info("Could not load any NPC names.");
    } else {
      console.log(`Loaded ${Object.keys(finalNpcData).length} NPC names.`);
    }

    return finalNpcData;

  } catch (error) {
    console.error("Error loading or processing NPC name files:", error);
    toast.error("Failed to load NPC names. Check resource files and console.");
    return {};
  }
};

// Exportiere die Funktion, um die Namen direkt zu erhalten
export const getPropMoverNameMap = async (): Promise<{ [reference: string]: string }> => {
  try {
    const propMoverNamesContent = await loadFile('public/resource/propMover.txt.txt');
    console.log("=== propMover.txt.txt Debug ===");
    
    // Zeige die ersten 30 Zeichen für Diagnose
    console.log(`Raw content first 30 chars: "${propMoverNamesContent.substring(0, 30)}"`);
    console.log(`Character codes: ${Array.from(propMoverNamesContent.substring(0, 10)).map(c => c.charCodeAt(0).toString(16)).join(' ')}`);
    
    // Erkenne Trennzeichen
    const hasTab = propMoverNamesContent.includes('\t');
    const separator = hasTab ? '\t' : ' ';
    console.log(`Detected separator: ${hasTab ? 'TAB' : 'SPACE'}`);
    
    // Teste ein direktes Parsing einer Beispielzeile
    const firstLine = propMoverNamesContent.split(/\r?\n/)[0];
    const parts = firstLine.split(separator);
    console.log(`First line has ${parts.length} parts when split by "${separator}"`);
    if (parts.length >= 2) {
      console.log(`First line ID: "${parts[0]}", Name: "${parts[1]}"`);
    }
    
    // Temporäre Mapping-Tabelle mit bekannten Einträgen
    const tempNames = parsePropMoverNames(propMoverNamesContent);
    
    // Zeige genau, was im nameMap ist
    console.log("=== Debugging nameMap content ===");
    const specialIds = ['IDS_PROPMOVER_TXT_000000', 'IDS_PROPMOVER_TXT_000002', 'IDS_PROPMOVER_TXT_000004', 'IDS_PROPMOVER_TXT_000006'];
    specialIds.forEach(id => {
      console.log(`Checking key "${id}": ${tempNames[id] !== undefined ? `"${tempNames[id]}"` : 'NOT FOUND'}`);
    });
    
    // Erstelle ein zweites Mapping ohne die IDS_-Präfixe, nur für den Fall
    const simplifiedMap: { [key: string]: string } = {};
    Object.entries(tempNames).forEach(([key, value]) => {
      // Extrahiere die ID-Nummer ohne Präfix
      const match = key.match(/IDS_PROPMOVER_TXT_(\d+)/);
      if (match && match[1]) {
        // Speichere sowohl mit als auch ohne führende Nullen
        simplifiedMap[match[1]] = value;
        simplifiedMap[parseInt(match[1], 10).toString()] = value;
      }
    });
    
    console.log(`Created simplified mapping with ${Object.keys(simplifiedMap).length} entries`);
    console.log(`Sample: "6" -> "${simplifiedMap["6"] || 'NOT FOUND'}"`);
    
    // Kombiniere beide Maps
    return {
      ...tempNames,
      ...simplifiedMap
    };
    
  } catch (error) {
    console.error('Error loading propMover.txt.txt:', error);
    return {};
  }
}; 