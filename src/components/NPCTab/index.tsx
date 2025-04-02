import { useState, useEffect } from 'react';
import NPCList from './NPCList';
import NPCEditor from './NPCEditor';
import { NPCItem } from '../../types/npcTypes';
import { ResourceItem } from '../../types/fileTypes';
import { getNPCsFromPropMover } from '../../utils/npc/npcFileOperations';
import { toast } from 'sonner';

interface NPCTabProps {
  editMode: boolean;
  availableItems?: ResourceItem[]; // Für den Shop
}

const NPCTab = ({ editMode, availableItems = [] }: NPCTabProps) => {
  const [npcs, setNpcs] = useState<NPCItem[]>([]);
  const [selectedNPC, setSelectedNPC] = useState<NPCItem | null>(null);
  const [isLoading, setIsLoading] = useState<boolean>(true);

  // Laden der NPCs beim ersten Öffnen der Tab
  useEffect(() => {
    loadNPCs();
  }, []);

  // Funktion zum Laden der NPCs
  const loadNPCs = async () => {
    setIsLoading(true);
    try {
      // NPCs aus den Ressourcendateien laden
      // In der realen Implementierung würde dies die Dateien aus den angegebenen Ressourcen laden
      const loadedNPCs = await getNPCsFromPropMover();
      setNpcs(loadedNPCs);
      
      // Setze den ersten NPC als ausgewählt, wenn welche geladen wurden
      if (loadedNPCs.length > 0) {
        setSelectedNPC(loadedNPCs[0]);
      }
      
      toast.success(`${loadedNPCs.length} NPCs erfolgreich geladen`);
    } catch (error) {
      console.error('Fehler beim Laden der NPCs:', error);
      toast.error('Fehler beim Laden der NPCs');
      
      // Fallback für Entwicklungszwecke: Demo-NPCs
      const demoNPCs = generateDemoNPCs();
      setNpcs(demoNPCs);
      
      if (demoNPCs.length > 0) {
        setSelectedNPC(demoNPCs[0]);
      }
    } finally {
      setIsLoading(false);
    }
  };

  // Aktualisieren eines NPCs
  const handleUpdateNPC = (updatedNPC: NPCItem, field?: string, oldValue?: any) => {
    if (!editMode) return;
    
    // Aktualisiere den NPC in der Liste
    const updatedNPCs = npcs.map(npc => 
      npc.id === updatedNPC.id ? updatedNPC : npc
    );
    
    setNpcs(updatedNPCs);
    setSelectedNPC(updatedNPC);
    
    // In einer realen Anwendung hier die Änderungen speichern
    // saveNPCChanges(updatedNPC, field, oldValue);
  };

  // Demo-NPCs für Entwicklungszwecke generieren
  const generateDemoNPCs = (): NPCItem[] => {
    return [
      {
        id: 'npc_001',
        name: 'village_elder',
        displayName: 'Dorfältester',
        description: 'Der weise Älteste des Dorfes mit vielen Geschichten.',
        type: 'quest_giver',
        level: 50,
        data: {},
        position: { x: 100, y: 50, z: 200, angle: 90 },
        behavior: 'passive',
        stats: { hp: 500, mp: 100, def: 50, atk: 30 },
        appearance: {
          modelFile: 'npc_villager.o3d',
          skin: 'elder',
          animations: ['idle', 'talk']
        },
        dialogues: [
          {
            id: 'dialog_001',
            text: 'Willkommen, Reisender! Was führt dich in unser bescheidenes Dorf?',
            responses: [
              {
                id: 'response_001',
                text: 'Ich suche nach Arbeit. Habt Ihr eine Aufgabe für mich?',
                nextDialogueId: 'dialog_002'
              },
              {
                id: 'response_002',
                text: 'Nur auf der Durchreise. Danke für die Begrüßung!',
              }
            ]
          },
          {
            id: 'dialog_002',
            text: 'In der Tat, es gibt einige Probleme mit Wölfen in den nahen Wäldern. Könntest du uns helfen?',
            responses: [
              {
                id: 'response_003',
                text: 'Natürlich, ich werde mich darum kümmern.',
              },
              {
                id: 'response_004',
                text: 'Das klingt zu gefährlich für mich.',
              }
            ]
          }
        ],
        shop: { isShop: false, items: [] }
      },
      {
        id: 'npc_002',
        name: 'village_merchant',
        displayName: 'Händler Götz',
        description: 'Ein freundlicher Händler mit allerlei Waren.',
        type: 'merchant',
        level: 30,
        data: {},
        position: { x: 120, y: 50, z: 220, angle: 45 },
        behavior: 'merchant',
        stats: { hp: 300 },
        appearance: {
          modelFile: 'npc_merchant.o3d',
          skin: 'default'
        },
        shop: { 
          isShop: true, 
          items: [
            { id: 'item_001', name: 'Heiltrank', price: 50, count: 10, position: 0 },
            { id: 'item_002', name: 'Manatrank', price: 80, count: 5, position: 1 },
            { id: 'item_003', name: 'Eisenschwert', price: 500, count: 1, position: 2 }
          ] 
        }
      },
      {
        id: 'npc_003',
        name: 'city_guard',
        displayName: 'Stadtwache',
        description: 'Eine wachsame Stadtwache, die für Ordnung sorgt.',
        type: 'guard',
        level: 40,
        data: {},
        position: { x: 150, y: 50, z: 180, angle: 180 },
        behavior: 'passive',
        stats: { hp: 800, mp: 0, def: 80, atk: 120 },
        appearance: {
          modelFile: 'npc_guard.o3d',
          animations: ['idle', 'patrol']
        }
      }
    ];
  };

  return (
    <div className="h-full flex">
      {/* Linke Seitenleiste: NPC-Liste */}
      <div className="w-64 h-full">
        <NPCList 
          npcs={npcs} 
          selectedNPC={selectedNPC} 
          onSelectNPC={setSelectedNPC}
        />
      </div>
      
      {/* Hauptbereich: NPC-Editor */}
      <div className="flex-1 h-full">
        {selectedNPC ? (
          <NPCEditor 
            npc={selectedNPC} 
            onUpdateNPC={handleUpdateNPC} 
            editMode={editMode}
            availableItems={availableItems}
          />
        ) : (
          <div className="h-full flex items-center justify-center bg-cyrus-dark">
            <div className="text-center text-gray-400 p-8 max-w-md">
              <h2 className="text-xl font-semibold mb-2">Kein NPC ausgewählt</h2>
              <p>Wählen Sie einen NPC aus der Liste auf der linken Seite, um ihn zu bearbeiten.</p>
              {isLoading && <p className="mt-4">Lade NPCs...</p>}
              {!isLoading && npcs.length === 0 && (
                <p className="mt-4">
                  Keine NPCs gefunden. Stellen Sie sicher, dass die notwendigen Ressourcendateien geladen sind.
                </p>
              )}
            </div>
          </div>
        )}
      </div>
    </div>
  );
};

export default NPCTab; 