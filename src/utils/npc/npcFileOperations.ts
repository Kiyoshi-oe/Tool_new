import { NPCItem, NPCFileData, NPCDialogue } from '../../types/npcTypes';

/**
 * Load a resource file from the public/resource directory
 */
const loadResourceFile = async (fileName: string): Promise<string> => {
  try {
    const response = await fetch(`/public/resource/${fileName}`);
    if (!response.ok) {
      console.warn(`File ${fileName} not found or cannot be loaded. Status: ${response.status}`);
      return ""; // Leere Zeichenkette zurückgeben, wenn die Datei nicht geladen werden kann
    }
    return await response.text();
  } catch (error) {
    console.error(`Error loading ${fileName}:`, error);
    return ""; // Bei Fehlern leere Zeichenkette zurückgeben
  }
};

/**
 * Load NPC dialogue data from JSON file
 */
const loadNPCDialogue = async (npcId: string): Promise<NPCDialogue[] | null> => {
  try {
    const response = await fetch(`/public/resource/NPC/dialog/${npcId}.json`);
    if (!response.ok) {
      console.warn(`No dialogue file found for NPC ${npcId}`);
      return null;
    }
    const data = await response.json();
    return data.dialogues || [];
  } catch (error) {
    console.error(`Error loading dialogue for NPC ${npcId}:`, error);
    return null;
  }
};

/**
 * Load NPC shop data from JSON file
 */
const loadNPCShop = async (npcId: string): Promise<any | null> => {
  try {
    const response = await fetch(`/public/resource/NPC/shop/${npcId}.json`);
    if (!response.ok) {
      console.warn(`No shop file found for NPC ${npcId}`);
      return null;
    }
    return await response.json();
  } catch (error) {
    console.error(`Error loading shop data for NPC ${npcId}:`, error);
    return null;
  }
};

/**
 * Load NPCs from propMover.txt and related files
 */
export const getNPCsFromPropMover = async (): Promise<NPCItem[]> => {
  try {
    // Load propMover.txt first, as it's the primary source
    const propMoverText = await loadResourceFile('NPC/propMover.txt');
    
    // If propMover.txt is not available, return demo NPCs
    if (!propMoverText) {
      console.warn("propMover.txt not found, returning demo NPCs");
      return []; // Return empty array instead of demo NPCs
    }
    
    // Load remaining files with fallbacks for missing files
    const [defineObjText, propMoverTxtText, characterIncText, propMoverExText] = await Promise.all([
      loadResourceFile('NPC/defineObj.h'),
      loadResourceFile('NPC/propMover.txt.txt'),
      loadResourceFile('NPC/character.inc'),
      loadResourceFile('NPC/propMoverEx.inc')
    ]);
    
    // Parse all files, with empty objects as fallbacks
    const defineObjData = defineObjText ? parseDefineObj(defineObjText) : {};
    const propMoverData = parsePropMover(propMoverText);
    const propMoverTxtData = propMoverTxtText ? parseMoverTxtTxt(propMoverTxtText) : {};
    const characterIncData = characterIncText ? parseCharacterInc(characterIncText) : {};
    const propMoverExData = propMoverExText ? parsePropMoverEx(propMoverExText) : {};
    
    if (Object.keys(defineObjData).length === 0) {
      console.warn('define.obj not loaded or empty, returning demo NPCs');
      return []; // Return empty array instead of demo NPCs
    }
    
    // Merge data into a usable NPC list
    const npcs = mergeNpcData(propMoverData, propMoverTxtData, defineObjData, characterIncData, propMoverExData);
    
    if (npcs.length === 0) {
      console.warn("No NPCs found in propMover.txt, returning demo NPCs");
      return []; // Return empty array instead of demo NPCs
    }
    
    // Load dialogues and shop data for each NPC
    const npcsWithExtras = await Promise.all(
      npcs.map(async (npc) => {
        try {
          // Versuche, Dialog zu laden
          const dialogues = await loadNPCDialogue(npc.id);
          if (dialogues) {
            npc.dialogues = dialogues;
          }
          
          // Versuche, Shop-Daten zu laden, falls der NPC ein Shop ist
          if (npc.shop?.isShop) {
            const shopData = await loadNPCShop(npc.id);
            if (shopData) {
              // Aktualisiere die Shop-Daten
              npc.shop.items = shopData.items.map((item: any, index: number) => ({
                id: item.id,
                name: item.name,
                price: item.price,
                count: item.stock || 1,
                position: index
              }));
              
              // Ergänze Shop-Name, falls vorhanden
              if (shopData.shopName) {
                npc.data.shopName = shopData.shopName;
              }
              
              // Ergänze Shop-Typ, falls vorhanden
              if (shopData.shopType) {
                npc.data.shopType = shopData.shopType;
              }
            }
          }
        } catch (error) {
          console.error(`Error loading extras for NPC ${npc.id}:`, error);
          // Fehler bei einzelnen NPCs ignorieren und mit dem nächsten fortfahren
        }
        
        return npc;
      })
    );
    
    return npcsWithExtras;
  } catch (error) {
    console.error('Error loading NPC files:', error);
    console.warn('Resource files not found or incomplete, returning demo NPCs');
    return []; // Return empty array instead of demo NPCs
  }
};

/**
 * Parse defineObj.h file to extract NPC type definitions
 */
const parseDefineObj = (text: string): Record<string, number> => {
  const regex = /#define\s+(MI_[^\s]+)\s+(\d+)/g;
  let match;
  const data: Record<string, number> = {};
  
  while ((match = regex.exec(text)) !== null) {
    data[match[1]] = parseInt(match[2]);
  }
  
  return data;
};

/**
 * Parse propMover.txt file
 */
const parsePropMover = (text: string): Record<string, any> => {
  const lines = text.split("\n").filter(line => line && !line.startsWith("//"));
  const headers = [
    "id", "szName", "dwClass", "dwLevel", "dwBelligerence", 
    "dwStr", "dwSta", "dwDex", "dwInt", "dwHR", 
    "dwER", "dwAtkMin", "dwAtkMax", "fSpeed", "szComment"
  ];
  
  const movers: Record<string, any> = {};
  
  lines.forEach(line => {
    const parts = line.split("\t");
    if (parts.length >= headers.length) {
      const npcId = parts[0];
      movers[npcId] = headers.reduce((acc, key, index) => {
        acc[key] = parts[index] || "";
        return acc;
      }, {} as Record<string, any>);
    }
  });
  
  return movers;
};

/**
 * Parse propMover.txt.txt file (comments & names)
 */
const parseMoverTxtTxt = (text: string): Record<string, {name: string, description: string}> => {
  const lines = text.split("\n").filter(line => line.trim() !== "");
  const names: Record<string, {name: string, description: string}> = {};
  
  lines.forEach(line => {
    const parts = line.split("\t");
    if (parts.length >= 2) {
      const id = parts[0].trim();
      const name = parts[1].trim();
      const description = parts.length >= 3 ? parts[2].trim() : "";
      names[id] = { name, description };
    }
  });
  
  return names;
};

/**
 * Parse character.inc file (NPC definitions)
 */
const parseCharacterInc = (text: string): Record<string, any> => {
  const npcsData: Record<string, any> = {};
  
  // Finden aller NPC-Definitionen
  const npcBlocks = text.match(/\w+\s*\{\s*setting\s*\{[\s\S]+?\}\s*\}/g) || [];
  
  npcBlocks.forEach(block => {
    // Extrahiere NPC-Namen (am Anfang des Blocks)
    const npcNameMatch = block.match(/^(\w+)\s*\{/);
    if (!npcNameMatch) return;
    
    const npcInternalName = npcNameMatch[1];
    const npc: Record<string, any> = {
      internalName: npcInternalName,
      menus: [],
      equipment: [],
      shopItems: [],
      vendorSlots: [],
      figure: null,
      structure: null,
      image: null,
      dialog: null,
      displayNameId: null
    };
    
    // Extrahiere Menüs
    const menuMatches = block.matchAll(/AddMenu\(([^)]+)\)/g);
    for (const match of menuMatches) {
      npc.menus.push(match[1].trim());
    }
    
    // Extrahiere Ausrüstung
    const equipMatch = block.match(/SetEquip\(([^)]+)\)/);
    if (equipMatch) {
      npc.equipment = equipMatch[1].split(',').map(item => item.trim());
    }
    
    // Extrahiere Figurparameter
    const figureMatch = block.match(/SetFigure\(([^)]+)\)/);
    if (figureMatch) {
      const figureParams = figureMatch[1].split(',').map(param => param.trim());
      npc.figure = {
        type: figureParams[0],
        variant: parseInt(figureParams[1]),
        color: figureParams[2],
        hairVariant: parseInt(figureParams[3])
      };
    }
    
    // Extrahiere Shop-Items
    const shopItemMatches = block.matchAll(/AddShopItem\(\s*(\d+)\s*,\s*([^,]+)\s*,\s*(\d+)\s*\)/g);
    for (const match of shopItemMatches) {
      npc.shopItems.push({
        tab: parseInt(match[1]),
        itemId: match[2].trim(),
        price: parseInt(match[3])
      });
    }
    
    // Extrahiere Strukturtyp
    const structureMatch = block.match(/m_nStructure\s*=\s*([^;]+)/);
    if (structureMatch) {
      npc.structure = structureMatch[1].trim();
    }
    
    // Extrahiere Bildreferenz
    const imageMatch = block.match(/SetImage\s*\(\s*([^)]+)\s*\)/);
    if (imageMatch) {
      npc.image = imageMatch[1].trim();
    }
    
    // Extrahiere Dialogdatei
    const dialogMatch = block.match(/m_szDialog\s*=\s*"([^"]+)"/);
    if (dialogMatch) {
      npc.dialog = dialogMatch[1].trim();
    }
    
    // Extrahiere Anzeigename
    const displayNameMatch = block.match(/SetName\s*\(\s*([^)]+)\s*\)/);
    if (displayNameMatch) {
      npc.displayNameId = displayNameMatch[1].trim();
    }
    
    // Extrahiere Vendor-Slots (Shop-Tabs)
    const vendorSlotMatches = block.matchAll(/AddVendorSlot\(\s*(\d+)\s*,\s*([^)]+)\s*\)/g);
    for (const match of vendorSlotMatches) {
      npc.vendorSlots.push({
        tab: parseInt(match[1]),
        tabNameId: match[2].trim()
      });
    }
    
    // Füge NPC zur Ergebnismenge hinzu
    npcsData[npcInternalName] = npc;
  });
  
  return npcsData;
};

/**
 * Parse propMoverEx.inc file (extended NPC properties)
 */
const parsePropMoverEx = (text: string): Record<string, any> => {
  const lines = text.split("\n").filter(line => line.trim() !== "" && !line.startsWith("//"));
  const npcExData: Record<string, any> = {};
  
  lines.forEach(line => {
    const parts = line.split(",");
    if (parts.length >= 8) {
      const npcId = parts[0].trim();
      npcExData[npcId] = {
        dialogType: parts[1].trim(),
        shopType: parts[2].trim(),
        isQuestGiver: parts[3].trim() === "TRUE",
        combatType: parts[4].trim(),
        faction: parts[5].trim(),
        respawnTime: parseInt(parts[6].trim()),
        voiceSet: parts[7].trim()
      };
    }
  });
  
  return npcExData;
};

/**
 * Merge data from different NPC files into a coherent list
 */
const mergeNpcData = (
  propMoverData: Record<string, any>,
  propMoverTxtData: Record<string, any>,
  defineObjData: Record<string, number>,
  characterIncData: Record<string, any>,
  propMoverExData: Record<string, any>
): NPCItem[] => {
  const npcs: NPCItem[] = [];
  
  // Create NPC items from propMover.txt data
  for (const [npcId, npcData] of Object.entries(propMoverData)) {
    const textData = propMoverTxtData[npcId] || { name: npcData.szName, description: "" };
    
    // Finde characterInc-Daten, falls verfügbar
    const charIncData = Object.values(characterIncData).find(data => 
      data.internalName === npcData.szName
    );
    
    // Finde propMoverEx-Daten, falls verfügbar
    const exData = propMoverExData[npcId];
    
    // Shop-Items aus character.inc, falls vorhanden
    const shopItems = charIncData?.shopItems?.map((item: any, index: number) => ({
      id: item.itemId,
      name: item.itemId,
      price: item.price,
      count: 1,
      position: index
    })) || [];
    
    // Bestimme, ob NPC ein Shop ist, basierend auf verschiedenen Quellen
    const isShop = (charIncData?.menus?.includes('MMI_TRADE') || false) || 
                   (exData?.shopType !== 'NONE') ||
                   shopItems.length > 0;
    
    // Zusammenführen der Daten
    const npc: NPCItem = {
      id: npcId,
      name: npcData.szName || `npc_${npcId}`,
      displayName: textData.name || npcData.szName || `NPC ${npcId}`,
      description: textData.description || "",
      type: exData?.shopType || getNpcType(npcData.dwClass),
      level: parseInt(npcData.dwLevel) || 1,
      data: {
        ...npcData,
        dwClass: npcData.dwClass,
        dwBelligerence: npcData.dwBelligerence,
        dwStr: npcData.dwStr,
        dwSta: npcData.dwSta,
        dwDex: npcData.dwDex,
        dwInt: npcData.dwInt
      },
      position: {
        x: 0, y: 0, z: 0, angle: 0
      },
      behavior: exData?.combatType || getBehaviorType(parseInt(npcData.dwBelligerence) || 0),
      stats: {
        hp: parseInt(npcData.dwHR) || 0,
        mp: parseInt(npcData.dwER) || 0,
        def: 0,
        atk: parseInt(npcData.dwAtkMin) || 0,
        exp: 0
      },
      appearance: {
        modelFile: charIncData?.image ? `${charIncData.image}.o3d` : `npc_${npcId}.o3d`,
        equipment: charIncData?.equipment || []
      },
      dialogues: [],
      shop: {
        isShop: isShop,
        items: shopItems,
        tabs: charIncData?.vendorSlots?.map((slot: any) => ({
          id: slot.tab,
          name: slot.tabNameId
        })) || []
      }
    };
    
    // Füge zusätzliche Daten aus propMoverEx hinzu
    if (exData) {
      npc.shop.isShop = exData.shopType !== 'NONE'; // Update isShop basierend auf shopType
      
      // Wenn NPC ein Dialoggeber ist
      if (exData.dialogType !== 'NONE') {
        // In einer realen Implementierung würde hier das Laden von Dialogen erfolgen
        // basierend auf dem dialogType und möglichen Dialog-Dateien
      }
      
      // Setze faction als zusätzliche Information
      if (exData.faction) {
        npc.data.faction = exData.faction;
      }
      
      // Setze respawnTime als zusätzliche Information
      if (exData.respawnTime) {
        npc.data.respawnTime = exData.respawnTime;
      }
    }
    
    npcs.push(npc);
  }
  
  return npcs;
};

/**
 * Determine NPC type based on class value
 */
const getNpcType = (classValue: string): string => {
  const classNum = parseInt(classValue) || 0;
  
  switch (classNum) {
    case 0: return 'citizen';
    case 1: return 'merchant';
    case 2: return 'guard';
    case 3: return 'quest_giver';
    default: return 'npc';
  }
};

/**
 * Determine behavior type based on belligerence value
 */
const getBehaviorType = (belligerence: number): string => {
  switch (belligerence) {
    case 0: return 'passive';
    case 1: return 'merchant';
    case 2: return 'guard';
    case 3: return 'aggressive';
    default: return 'passive';
  }
};

/**
 * Save changes to an NPC
 */
export const saveNPCChanges = async (npc: NPCItem, field?: string, oldValue?: any): Promise<boolean> => {
  try {
    // In a real implementation, changes would be written to the appropriate files:
    // - Choose the right file depending on the changed field
    // - E.g. dialogues in dialogue files, names in propMover.txt.txt, etc.
    
    console.log(`Changes saved to NPC ${npc.id} (${npc.displayName}). Field: ${field}, Old value: ${oldValue}`);
    
    return true;
  } catch (error) {
    console.error('Error saving NPC changes:', error);
    return false;
  }
};

/**
 * Convert NPCItem back to propMover.txt format
 */
export const serializeToText = (data: NPCFileData): string => {
  // Here would be the serializer for the propMover.txt file
  // The following code is just a placeholder for demonstration
  
  return data.originalContent || '';
};

/**
 * Save the propMover.txt file
 */
export const savePropMoverFile = async (content: string, fileName: string = "propMover.txt"): Promise<boolean> => {
  try {
    // In a real implementation, the file would be saved here
    console.log(`Saving ${fileName} with ${content.length} characters`);
    
    return true;
  } catch (error) {
    console.error(`Error saving ${fileName}:`, error);
    return false;
  }
};

/**
 * Generate demo NPCs for development and testing - REMOVING THIS
 */
/*
const generateDemoNPCs = (): NPCItem[] => {
  const demoNPCs: NPCItem[] = [
    {
      id: "1001",
      name: "village_elder",
      displayName: "Dorfältester",
      description: "Der weise Dorfälteste, der viele Geschichten kennt und Rat gibt.",
      type: "quest_giver",
      level: 1,
      data: {
        dwClass: "0",
        dwBelligerence: "0"
      },
      position: { x: 100, y: 0, z: 100, angle: 180 },
      behavior: "passive",
      stats: { hp: 100, mp: 50, def: 10, atk: 0, exp: 0 },
      appearance: { modelFile: "npc_elder.o3d" },
      dialogues: [
        {
          id: "default",
          text: "Willkommen in unserem Dorf, Reisender. Wie kann ich dir helfen?",
          options: [
            { text: "Erzählt mir etwas über das Dorf.", next: "about_village" },
            { text: "Auf Wiedersehen.", next: "exit" }
          ]
        },
        {
          id: "about_village",
          text: "Unser Dorf besteht seit Generationen. Wir leben vom Handel und der Landwirtschaft.",
          options: [
            { text: "Zurück", next: "default" }
          ]
        }
      ],
      shop: { isShop: false, items: [] }
    },
    {
      id: "1002",
      name: "merchant",
      displayName: "Händler Götz",
      description: "Ein freundlicher Händler mit allerlei Waren.",
      type: "merchant",
      level: 1,
      data: {
        dwClass: "1",
        dwBelligerence: "1"
      },
      position: { x: 110, y: 0, z: 90, angle: 90 },
      behavior: "merchant",
      stats: { hp: 120, mp: 0, def: 15, atk: 0, exp: 0 },
      appearance: { modelFile: "npc_merchant.o3d" },
      dialogues: [
        {
          id: "default",
          text: "Willkommen in meinem Laden! Was kann ich für dich tun?",
          options: [
            { text: "Zeigt mir Eure Waren.", next: "show_goods", action: "open_shop" },
            { text: "Auf Wiedersehen.", next: "exit" }
          ]
        }
      ],
      shop: { 
        isShop: true, 
        items: [
          { id: "10001", name: "Heiltrank", price: 50, count: 10, position: 0 },
          { id: "10002", name: "Brot", price: 10, count: 25, position: 1 },
          { id: "10003", name: "Fackel", price: 15, count: 8, position: 2 }
        ] 
      }
    },
    {
      id: "1003",
      name: "blacksmith",
      displayName: "Schmied Hagen",
      description: "Der Dorfschmied, der Waffen und Rüstungen herstellt.",
      type: "merchant",
      level: 5,
      data: {
        dwClass: "1",
        dwBelligerence: "0"
      },
      position: { x: 85, y: 0, z: 120, angle: 270 },
      behavior: "passive",
      stats: { hp: 200, mp: 0, def: 25, atk: 30, exp: 0 },
      appearance: { modelFile: "npc_blacksmith.o3d" },
      dialogues: [
        {
          id: "default",
          text: "Brauchst du Waffen oder Rüstungen? Ich kann dir helfen.",
          options: [
            { text: "Zeigt mir Eure Waren.", next: "show_goods", action: "open_shop" },
            { text: "Auf Wiedersehen.", next: "exit" }
          ]
        }
      ],
      shop: { 
        isShop: true, 
        items: [
          { id: "20001", name: "Eisenschwert", price: 150, count: 3, position: 0 },
          { id: "20002", name: "Lederwams", price: 100, count: 5, position: 1 },
          { id: "20003", name: "Eisenhelm", price: 120, count: 2, position: 2 }
        ] 
      }
    }
  ];
  
  return demoNPCs;
}; 
*/ 