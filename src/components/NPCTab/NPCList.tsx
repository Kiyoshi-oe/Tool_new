import React, { useState, useEffect } from 'react';
import { Input } from "@/components/ui/input";
import { Button } from "@/components/ui/button";
import { NPCItem } from '../../types/npcTypes';
import { Search } from 'lucide-react';
import { NpcNameMap, getPropMoverNameMap } from '../../utils/npc/npcNameLoader';
import clsx from 'clsx';

interface NPCListProps {
  npcs: NpcNameMap;
  selectedNPCId: string | null;
  onSelectNPC: (id: string) => void;
}

const NPCList = ({ npcs, selectedNPCId, onSelectNPC }: NPCListProps) => {
  const [search, setSearch] = useState('');
  const [nameMap, setNameMap] = useState<Record<string, string>>({});

  // Lade die Namen aus propMover.txt.txt direkt hier
  useEffect(() => {
    const loadNames = async () => {
      try {
        const propMoverNames = await getPropMoverNameMap();
        console.log("Loaded name mappings:", Object.keys(propMoverNames).length);
        // Debug: Zeige die ersten 5 Einträge
        const entries = Object.entries(propMoverNames).slice(0, 5);
        if (entries.length > 0) {
          console.log("Sample mappings:", entries);
        }
        setNameMap(propMoverNames);
      } catch (error) {
        console.error("Failed to load name mappings:", error);
      }
    };
    loadNames();
  }, []);

  // 1. Filter for IDs starting with "MI_"
  const miFilteredNPCIds = React.useMemo(() => 
    Object.keys(npcs).filter(npcId => npcId.startsWith('MI_')),
    [npcs]
  );

  // 2. Filter based on search term (checking name) from the MI_ filtered list
  const filteredNPCIds = React.useMemo(() => 
    miFilteredNPCIds.filter(npcId => {
      const npc = npcs[npcId];
      // Ensure npc and npc.name exist before calling toLowerCase
      return npc && npc.name && npc.name.toLowerCase().includes(search.toLowerCase());
    }).sort((a, b) => npcs[a].name.localeCompare(npcs[b].name)), // Sort alphabetically by name
    [miFilteredNPCIds, npcs, search] // Include dependencies
  );

  return (
    <div className="flex flex-col h-full bg-cyrus-darker border-r border-cyrus-border">
      <div className="p-2">
          <Input 
          type="search"
          placeholder="Suche nach NPC..." 
          value={search} 
          onChange={e => setSearch(e.target.value)} 
          className="w-full bg-cyrus-dark border-cyrus-border placeholder:text-gray-500"
        />
      </div>
      <div className="flex-1 overflow-y-auto">
        {filteredNPCIds.length > 0 ? (
          filteredNPCIds.map(npcId => {
            const npc = npcs[npcId]; // Get npc object for safe access
            if (!npc) return null; // Skip if somehow npc data is missing
            
            return (
              <div 
                key={npcId} 
                onClick={() => onSelectNPC(npcId)}
                className={clsx(
                  "px-3 py-2 cursor-pointer hover:bg-cyrus-accent/20", // Adjusted padding/structure
                  {
                    'bg-cyrus-accent/30': selectedNPCId === npcId,
                  }
                )}
                title={`${npc.name} (${npcId})`} // Tooltip for full name/ID
              >
                {/* Display Name */}
                <div 
                  className={clsx(
                    "text-sm truncate font-medium",
                    selectedNPCId === npcId ? 'text-cyrus-light' : 'text-gray-300 hover:text-cyrus-light'
                  )}
                >
                  {npc.name.replace(/^_MISSING_NAME_\(([^)]+)\)$/, (_, ref) => {
                    // Extrahiere die ID-Nummer
                    const idMatch = ref.match(/IDS_PROPMOVER_TXT_0*(\d+)/);
                    if (!idMatch) return ref;
                    
                    const idNumber = parseInt(idMatch[1], 10);
                    
                    // 1. Versuche eine exakte Übereinstimmung im nameMap zu finden
                    if (nameMap && nameMap[ref]) {
                      return nameMap[ref];
                    }
                    
                    // 2. Bekannte NPCs direkt mit hardcodierten Namen
                    const commonNames: Record<number, string> = {
                      0: "Default",
                      2: "Male", 
                      4: "Female",
                      6: "[Rookie] Aibatt",
                      8: "[Advanced] Aibatt",
                      10: "[Captain] Aibatt",
                      12: "[Giant] Aibatt", 
                      14: "[Rookie] Mushpang",
                      16: "[Advanced] Mushpang",
                      18: "[Captain] Mushpang",
                      20: "[Giant] Mushpang",
                      22: "[Rookie] Burudeng",
                      24: "[Advanced] Burudeng",
                      26: "[Captain] Burudeng",
                      28: "[Giant] Burudeng",
                      30: "[Rookie] Pukepuke",
                      32: "[Advanced] Pukepuke",
                      34: "[Captain] Pukepuke",
                      36: "[Giant] Pukepuke",
                      38: "[Rookie] Cardpuppet",
                      40: "[Advanced] Cardpuppet",
                      42: "[Captain] Cardpuppet",
                      44: "[Giant] Cardpuppet",
                      46: "[Rookie] Totemia",
                      48: "[Advanced] Totemia",
                      50: "[Captain] Totemia",
                      52: "[Giant] Totemia",
                      54: "[Rookie] Doridoma",
                      56: "[Advanced] Doridoma",
                      58: "[Captain] Doridoma",
                      60: "[Giant] Doridoma",
                      62: "[Rookie] Lawolf",
                      64: "[Advanced] Lawolf",
                      66: "[Captain] Lawolf",
                      68: "[Giant] Lawolf",
                      70: "[Rookie] Fefern",
                      72: "[Advanced] Fefern",
                      74: "[Captain] Fefern",
                      76: "[Giant] Fefern",
                      78: "[Rookie] Nyangnyang",
                      80: "[Advanced] Nyangnyang", 
                      82: "[Captain] Nyangnyang",
                      84: "[Giant] Nyangnyang",
                      86: "[Rookie] Bang",
                      88: "[Advanced] Bang",
                      90: "[Captain] Bang",
                      92: "[Giant] Bang",
                      94: "[Rookie] Wagsaac",
                      96: "[Advanced] Wagsaac",
                      98: "[Captain] Wagsaac",
                      100: "[Giant] Wagsaac"
                    };
                    
                    if (commonNames[idNumber]) {
                      return commonNames[idNumber];
                    }
                    
                    // 3. Für unbekannte IDs: Berechne den Typ basierend auf dem Muster
                    // Bei IDs > 100 folgen wir dem Muster: gerade IDs (mod 8) bestimmen den Typ
                    if (idNumber > 100) {
                      const typeIndex = idNumber % 8;
                      if (typeIndex % 2 === 0) { // Nur für gerade Indizes (0, 2, 4, 6)
                        const types: Record<number, string> = {
                          0: "[Giant]",
                          2: "[Rookie]", 
                          4: "[Advanced]",
                          6: "[Captain]"
                        };
                        
                        const monsterType = types[typeIndex] || "";
                        // Berechne die Monsterfamilie (jede Familie hat 8 IDs)
                        const familyIndex = Math.floor(idNumber / 8);
                        
                        return `${monsterType} Monster ${familyIndex}`;
                      }
                    }
                    
                    // 4. Fallback-Format für alle anderen Fälle
                    return `NPC ${idMatch[1]}`;
                  })}
                </div>
                {/* Display ID */}
                <div className="text-xs text-gray-500 truncate">
                  ID: {npcId}
                </div>
              </div>
            )
          })
        ) : (
          <p className="text-center text-gray-500 text-sm p-4">
            {search ? "Keine NPCs gefunden." : (miFilteredNPCIds.length === 0 ? "Keine MI_ NPCs geladen." : "Keine MI_ NPCs mit diesem Namen gefunden.")}
          </p>
        )}
      </div>
    </div>
  );
};

export default NPCList; 