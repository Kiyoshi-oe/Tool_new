import { useState, useEffect } from 'react';
import NPCList from './NPCList';
// import NPCEditor from './NPCEditor'; // Temporarily remove editor
// import { NPCItem } from '../../types/npcTypes';
// import { ResourceItem } from '../../types/fileTypes';
// import { getNPCsFromPropMover } from '../../utils/npc/npcFileOperations'; // Remove old loader
import { loadNpcNamesAndIds, NpcNameMap } from '../../utils/npc/npcNameLoader'; // Import new loader
import { toast } from 'sonner';

interface NPCTabProps {
  editMode: boolean;
  // availableItems?: ResourceItem[]; // Remove editor related props
}

const NPCTab = ({ editMode }: NPCTabProps) => {
  // State now holds the NpcNameMap structure
  const [npcs, setNpcs] = useState<NpcNameMap>({});
  // selectedNPC now holds the ID (string)
  const [selectedNPCId, setSelectedNPCId] = useState<string | null>(null);
  const [isLoading, setIsLoading] = useState<boolean>(true);

  // Loading NPCs when the tab is first opened
  useEffect(() => {
    loadAndSetNpcs();
  }, []);

  // Function to load NPCs using the new loader
  const loadAndSetNpcs = async () => {
    setIsLoading(true);
    setSelectedNPCId(null); // Reset selection
    try {
      // Load NPC names and IDs
      const loadedNpcs = await loadNpcNamesAndIds();
      setNpcs(loadedNpcs);

      if (Object.keys(loadedNpcs).length > 0) {
        // Optionally select the first NPC by default
        // setSelectedNPCId(Object.keys(loadedNpcs)[0]);
        toast.success(`${Object.keys(loadedNpcs).length} NPC names loaded`);
      } else {
        // Message already handled in loadNpcNamesAndIds
        // toast.info('No NPCs found in resource files.');
      }
    } catch (error) {
      // Error handling is done within loadNpcNamesAndIds
      // console.error('Error loading NPCs:', error);
      // toast.error('Error loading NPCs.');
      setNpcs({}); // Ensure state is empty on error
    } finally {
      setIsLoading(false);
    }
  };

  // Update an NPC - Placeholder/Remove for now
  /*
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
  */

  // Removed the local generateDemoNPCs function

  return (
    <div className="h-full flex">
      {/* Left sidebar: NPC list */}
      <div className="w-64 h-full">
        <NPCList 
          npcs={npcs} 
          selectedNPCId={selectedNPCId} 
          onSelectNPC={setSelectedNPCId} // Pass the setter directly
        />
      </div>
      
      {/* Main area: Display selected NPC Info */}
      <div className="flex-1 h-full p-4 bg-cyrus-darker text-cyrus-light">
        {isLoading ? (
            <p>Loading NPC list...</p>
        ) : selectedNPCId && npcs[selectedNPCId] ? (
          <div>
            <h2 className="text-xl font-semibold mb-2">Selected NPC:</h2>
            <p>ID: {selectedNPCId}</p>
            <p>Name: {npcs[selectedNPCId].name}</p>
            {/* Add more details here later if needed */}
          </div>
        ) : (
          <div className="h-full flex items-center justify-center">
            <div className="text-center text-gray-400">
              <h2 className="text-xl font-semibold mb-2">
                {Object.keys(npcs).length > 0 ? "Select an NPC" : "No NPCs Loaded"}
              </h2>
              <p>
                {Object.keys(npcs).length > 0
                  ? "Select an NPC from the list on the left."
                  : "Could not load NPCs. Check resource files or console for errors."
                }
              </p>
            </div>
          </div>
        )}
      </div>
    </div>
  );
};

export default NPCTab; 