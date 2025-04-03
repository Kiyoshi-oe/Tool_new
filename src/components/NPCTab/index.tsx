import { useState, useEffect } from 'react';
import NPCList from './NPCList';
import NPCEditor from './NPCEditor';
import { NPCItem } from '../../types/npcTypes';
import { ResourceItem } from '../../types/fileTypes';
import { getNPCsFromPropMover } from '../../utils/npc/npcFileOperations';
import { toast } from 'sonner';

interface NPCTabProps {
  editMode: boolean;
  availableItems?: ResourceItem[]; // For the shop
}

const NPCTab = ({ editMode, availableItems = [] }: NPCTabProps) => {
  const [npcs, setNpcs] = useState<NPCItem[]>([]);
  const [selectedNPC, setSelectedNPC] = useState<NPCItem | null>(null);
  const [isLoading, setIsLoading] = useState<boolean>(true);

  // Loading NPCs when the tab is first opened
  useEffect(() => {
    loadNPCs();
  }, []);

  // Function to load NPCs
  const loadNPCs = async () => {
    setIsLoading(true);
    try {
      // Load NPCs from resource files
      const loadedNPCs = await getNPCsFromPropMover();
      
      if (loadedNPCs.length > 0) {
        setNpcs(loadedNPCs);
        // Set the first NPC as selected
        setSelectedNPC(loadedNPCs[0]);
        toast.success(`${loadedNPCs.length} NPCs successfully loaded`);
      } else {
        // Only if no NPCs were found, use the demo NPCs
        console.warn('No NPCs found in resource files, using demo NPCs');
        const demoNPCs = generateDemoNPCs();
        setNpcs(demoNPCs);
        
        if (demoNPCs.length > 0) {
          setSelectedNPC(demoNPCs[0]);
        }
        toast.info('Demo NPCs loaded as no real NPCs were found');
      }
    } catch (error) {
      console.error('Error loading NPCs:', error);
      toast.error('Error loading NPCs, using demo NPCs');
      
      // Fallback for development purposes: Demo NPCs
      const demoNPCs = generateDemoNPCs();
      setNpcs(demoNPCs);
      
      if (demoNPCs.length > 0) {
        setSelectedNPC(demoNPCs[0]);
      }
    } finally {
      setIsLoading(false);
    }
  };

  // Update an NPC
  const handleUpdateNPC = (updatedNPC: NPCItem, field?: string, oldValue?: any) => {
    if (!editMode) return;
    
    // Update the NPC in the list
    const updatedNPCs = npcs.map(npc => 
      npc.id === updatedNPC.id ? updatedNPC : npc
    );
    
    setNpcs(updatedNPCs);
    setSelectedNPC(updatedNPC);
    
    // In a real application, save the changes here
    // saveNPCChanges(updatedNPC, field, oldValue);
  };

  // Generate demo NPCs for development purposes
  const generateDemoNPCs = (): NPCItem[] => {
    return [
      {
        id: 'npc_001',
        name: 'village_elder',
        displayName: 'Village Elder',
        description: 'The wise elder of the village with many stories.',
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
            text: 'Welcome, traveler! What brings you to our humble village?',
            responses: [
              {
                id: 'response_001',
                text: 'I am looking for work. Do you have a task for me?',
                nextDialogueId: 'dialog_002'
              },
              {
                id: 'response_002',
                text: 'Just passing through. Thanks for the welcome!',
              }
            ]
          },
          {
            id: 'dialog_002',
            text: 'Indeed, there are some problems with wolves in the nearby forests. Could you help us?',
            responses: [
              {
                id: 'response_003',
                text: 'Of course, I will take care of it.',
              },
              {
                id: 'response_004',
                text: 'That sounds too dangerous for me.',
              }
            ]
          }
        ],
        shop: { isShop: false, items: [] }
      },
      {
        id: 'npc_002',
        name: 'village_merchant',
        displayName: 'Merchant Götz',
        description: 'A friendly merchant with all kinds of goods.',
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
            { id: 'item_001', name: 'Health Potion', price: 50, count: 10, position: 0 },
            { id: 'item_002', name: 'Mana Potion', price: 80, count: 5, position: 1 },
            { id: 'item_003', name: 'Iron Sword', price: 500, count: 1, position: 2 }
          ] 
        }
      },
      {
        id: 'npc_003',
        name: 'city_guard',
        displayName: 'City Guard',
        description: 'A vigilant city guard who maintains order.',
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
      {/* Left sidebar: NPC list */}
      <div className="w-64 h-full">
        <NPCList 
          npcs={npcs} 
          selectedNPC={selectedNPC} 
          onSelectNPC={setSelectedNPC}
        />
      </div>
      
      {/* Main area: NPC editor */}
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
              <h2 className="text-xl font-semibold mb-2">No NPC selected</h2>
              <p>Select an NPC from the list on the left side to edit it.</p>
              {isLoading && <p className="mt-4">Loading NPCs...</p>}
              {!isLoading && npcs.length === 0 && (
                <p className="mt-4">
                  No NPCs found. Make sure the necessary resource files are loaded.
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