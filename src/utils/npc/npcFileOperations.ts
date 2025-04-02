import { NPCItem, NPCFileData } from '../../types/npcTypes';

/**
 * Lade NPCs aus propMover.txt und zugehörigen Dateien
 */
export const getNPCsFromPropMover = async (): Promise<NPCItem[]> => {
  try {
    // In einer realen Implementierung würden hier die Dateien aus dem Ressourcenordner geladen werden
    // Für diese Implementierung laden wir die Dateien direkt aus dem public-Ordner
    
    // propMover.txt laden
    const propMoverResponse = await fetch('/resource/NPC/propMover.txt');
    if (!propMoverResponse.ok) throw new Error('Fehler beim Laden von propMover.txt');
    const propMoverContent = await propMoverResponse.text();
    
    // propMover.txt.txt laden (enthält Anzeigetexte)
    const propMoverTextResponse = await fetch('/resource/NPC/propMover.txt.txt');
    if (!propMoverTextResponse.ok) throw new Error('Fehler beim Laden von propMover.txt.txt');
    const propMoverTextContent = await propMoverTextResponse.text();
    
    // propMoverEx.inc laden (enthält erweiterte Eigenschaften)
    const propMoverExResponse = await fetch('/resource/NPC/propMoverEx.inc');
    if (!propMoverExResponse.ok) throw new Error('Fehler beim Laden von propMoverEx.inc');
    const propMoverExContent = await propMoverExResponse.text();
    
    // Parsen der Daten
    const npcItems = parseNPCFiles(propMoverContent, propMoverTextContent, propMoverExContent);
    
    return npcItems;
  } catch (error) {
    console.error('Fehler beim Laden der NPC-Dateien:', error);
    throw error;
  }
};

/**
 * Parst alle NPC-relevanten Dateien und kombiniert die Daten
 */
const parseNPCFiles = (
  propMoverContent: string,
  propMoverTextContent: string,
  propMoverExContent: string
): NPCItem[] => {
  const npcs: NPCItem[] = [];
  
  // 1. Basis-NPCs aus propMover.txt extrahieren
  const baseNPCs = parsePropMover(propMoverContent);
  
  // 2. Texte aus propMover.txt.txt extrahieren
  const npcTexts = parsePropMoverText(propMoverTextContent);
  
  // 3. Erweiterte Eigenschaften aus propMoverEx.inc extrahieren
  const npcExt = parsePropMoverEx(propMoverExContent);
  
  // 4. Daten kombinieren
  baseNPCs.forEach(baseNpc => {
    const id = baseNpc.id.toString();
    const texts = npcTexts[id] || { displayName: baseNpc.name, description: '' };
    const ext = npcExt[id] || {};
    
    npcs.push({
      id: id,
      name: baseNpc.name,
      displayName: texts.displayName,
      description: texts.description,
      type: getTypeFromJob(baseNpc.job || 0),
      level: baseNpc.level || 1,
      data: baseNpc.data || {},
      position: ext.position || { x: 0, y: 0, z: 0, angle: 0 },
      behavior: getBehaviorType(ext.behaviorType || 0),
      stats: {
        hp: baseNpc.hp || 0,
        mp: baseNpc.mp || 0,
        def: baseNpc.def || 0,
        atk: baseNpc.atk || 0,
        exp: baseNpc.exp || 0
      },
      appearance: {
        modelFile: baseNpc.modelFile || 'default.o3d',
      },
      dialogues: [],
      shop: { 
        isShop: ext.shopId ? true : false, 
        items: [] 
      }
    });
  });
  
  return npcs;
};

/**
 * Parst propMover.txt Datei
 */
const parsePropMover = (content: string): any[] => {
  const npcs: any[] = [];
  const lines = content.split('\n');
  
  let currentNPC: any = null;
  let isParsingNPC = false;
  
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();
    
    // Kommentarzeilen überspringen
    if (line.startsWith('//') || line === '') continue;
    
    // Beginn eines NPC-Blocks
    if (line.includes('=') && line.endsWith('{')) {
      const npcName = line.split('=')[0].trim();
      currentNPC = { name: npcName, data: {} };
      isParsingNPC = true;
      continue;
    }
    
    // Ende eines NPC-Blocks
    if (line === '};') {
      if (currentNPC) {
        npcs.push(currentNPC);
      }
      currentNPC = null;
      isParsingNPC = false;
      continue;
    }
    
    // Eigenschaften eines NPCs parsen
    if (isParsingNPC && currentNPC) {
      if (line.includes('=')) {
        const [key, value] = line.split('=').map(part => part.trim());
        // Kommas und Semikolons am Ende entfernen
        const cleanValue = value.replace(/[,;]$/, '').trim();
        
        // Spezielle Eigenschaften extrahieren
        if (key === 'dwID') {
          currentNPC.id = parseInt(cleanValue);
        } else if (key === 'szName') {
          currentNPC.name = cleanValue.replace(/"/g, '');
        } else if (key === 'dwLevel') {
          currentNPC.level = parseInt(cleanValue);
        } else if (key === 'dwNPCJob') {
          currentNPC.job = parseInt(cleanValue);
        } else if (key === 'dwHP') {
          currentNPC.hp = parseInt(cleanValue);
        } else if (key === 'dwMP') {
          currentNPC.mp = parseInt(cleanValue);
        } else if (key === 'dwNaturealArmor') {
          currentNPC.def = parseInt(cleanValue);
        } else if (key === 'dwAtkMin') {
          currentNPC.atk = parseInt(cleanValue);
        } else if (key === 'dwExpToGive') {
          currentNPC.exp = parseInt(cleanValue);
        } else if (key === 'szComment') {
          currentNPC.comment = cleanValue.replace(/"/g, '');
        } else {
          // Andere Eigenschaften als generische Daten speichern
          currentNPC.data[key] = cleanValue;
        }
      }
    }
  }
  
  return npcs;
};

/**
 * Parst propMover.txt.txt Datei (enthält Anzeigetexte)
 */
const parsePropMoverText = (content: string): Record<string, { displayName: string, description: string }> => {
  const npcTexts: Record<string, { displayName: string, description: string }> = {};
  const lines = content.split('\n');
  
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();
    
    // Kommentarzeilen überspringen
    if (line.startsWith('//') || line === '') continue;
    
    // Zeile parsen: ID DisplayName Beschreibung
    const parts = line.split('\t');
    if (parts.length >= 2) {
      const id = parts[0].trim();
      const displayName = parts[1].trim();
      const description = parts.length >= 3 ? parts[2].trim() : '';
      
      npcTexts[id] = { displayName, description };
    }
  }
  
  return npcTexts;
};

/**
 * Parst propMoverEx.inc Datei (enthält erweiterte Eigenschaften)
 */
const parsePropMoverEx = (content: string): Record<string, any> => {
  const npcExt: Record<string, any> = {};
  const lines = content.split('\n');
  
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();
    
    // Kommentarzeilen überspringen
    if (line.startsWith('//') || line === '') continue;
    
    // NPC_ID,DialogID,ShopID,BehaviorType,Position_X,Position_Y,Position_Z,Angle
    const parts = line.split(',');
    if (parts.length >= 8) {
      const id = parts[0].trim();
      const dialogId = parts[1].trim();
      const shopId = parts[2].trim();
      const behaviorType = parseInt(parts[3].trim());
      const posX = parseFloat(parts[4].trim());
      const posY = parseFloat(parts[5].trim());
      const posZ = parseFloat(parts[6].trim());
      const angle = parseFloat(parts[7].trim());
      
      npcExt[id] = {
        dialogId: dialogId !== '0' ? dialogId : null,
        shopId: shopId !== '0' ? shopId : null,
        behaviorType,
        position: { x: posX, y: posY, z: posZ, angle }
      };
    }
  }
  
  return npcExt;
};

/**
 * Bestimmt den NPC-Typ basierend auf dem Job-Wert
 */
const getTypeFromJob = (job: number): string => {
  switch (job) {
    case 0: return 'citizen';
    case 1: return 'merchant';
    case 2: return 'guard';
    case 3: return 'quest_giver';
    default: return 'npc';
  }
};

/**
 * Bestimmt den Verhaltenstyp basierend auf dem BehaviorType-Wert
 */
const getBehaviorType = (type: number): string => {
  switch (type) {
    case 0: return 'passive';
    case 1: return 'merchant';
    case 2: return 'guard';
    case 3: return 'aggressive';
    default: return 'passive';
  }
};

/**
 * Speichere Änderungen an einem NPC
 */
export const saveNPCChanges = async (npc: NPCItem, field?: string, oldValue?: any): Promise<boolean> => {
  try {
    // In einer realen Implementierung würden hier die Änderungen in die entsprechenden Dateien geschrieben:
    // - Abhängig vom geänderten Feld die richtige Datei auswählen
    // - z.B. Dialoge in Dialog-Dateien, Namen in propMover.txt.txt, etc.
    
    console.log(`Änderungen an NPC ${npc.id} (${npc.displayName}) gespeichert. Feld: ${field}, Alter Wert: ${oldValue}`);
    
    return true;
  } catch (error) {
    console.error('Fehler beim Speichern der NPC-Änderungen:', error);
    return false;
  }
};

/**
 * Konvertiert NPCItem zurück in das propMover.txt Format
 */
export const serializeToText = (data: NPCFileData): string => {
  // Hier würde der Serialisierer für die propMover.txt Datei implementiert werden
  // Der folgende Code ist nur ein Platzhalter für die Demonstration
  
  return data.originalContent || '';
};

/**
 * Speichert die propMover.txt Datei
 */
export const savePropMoverFile = async (content: string, fileName: string = "propMover.txt"): Promise<boolean> => {
  try {
    // In einer realen Implementierung würde hier die Datei gespeichert werden
    console.log(`Speichere ${fileName} mit ${content.length} Zeichen`);
    
    return true;
  } catch (error) {
    console.error(`Fehler beim Speichern von ${fileName}:`, error);
    return false;
  }
}; 