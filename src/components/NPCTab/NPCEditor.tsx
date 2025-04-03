import { useState, useEffect } from 'react';
import { NPCItem } from '../../types/npcTypes';
import { ResourceItem } from '../../types/fileTypes';
import { Tabs, TabsContent, TabsList, TabsTrigger } from "@/components/ui/tabs";
import General from './General';
import Attributes from './Attributes';
import Dialogues from './Dialogues';
import Appearance from './Appearance';
import NPCShop from './NPCShop';

interface NPCEditorProps {
  npc: NPCItem;
  onUpdateNPC: (updatedNPC: NPCItem, field?: string, oldValue?: any) => void;
  editMode: boolean;
  availableItems?: ResourceItem[]; // For the shop
}

const NPCEditor = ({ npc, onUpdateNPC, editMode, availableItems = [] }: NPCEditorProps) => {
  const [activeTab, setActiveTab] = useState('general');

  // Update the active tab when a new NPC is selected
  useEffect(() => {
    // Back to the first tab when a new NPC is loaded
    setActiveTab('general');
  }, [npc.id]);

  return (
    <div className="h-full flex flex-col bg-cyrus-dark">
      <Tabs
        value={activeTab}
        onValueChange={setActiveTab}
        className="flex flex-col h-full"
      >
        <div className="border-b border-cyrus-dark-lightest">
          <TabsList className="bg-cyrus-dark border-b border-cyrus-dark-lightest h-auto">
            <TabsTrigger
              value="general"
              className={`px-4 py-2 text-sm font-medium whitespace-nowrap transition-colors duration-200
                ${activeTab === 'general' 
                  ? 'text-white border-b-2 border-[#007BFF] data-[state=active]:bg-transparent data-[state=active]:text-white' 
                  : 'text-gray-400 hover:text-white hover:bg-opacity-20 hover:bg-[#007BFF]'}`}
            >
              General
            </TabsTrigger>
            <TabsTrigger
              value="attributes"
              className={`px-4 py-2 text-sm font-medium whitespace-nowrap transition-colors duration-200
                ${activeTab === 'attributes' 
                  ? 'text-white border-b-2 border-[#007BFF] data-[state=active]:bg-transparent data-[state=active]:text-white' 
                  : 'text-gray-400 hover:text-white hover:bg-opacity-20 hover:bg-[#007BFF]'}`}
            >
              Attributes
            </TabsTrigger>
            <TabsTrigger
              value="dialogues"
              className={`px-4 py-2 text-sm font-medium whitespace-nowrap transition-colors duration-200
                ${activeTab === 'dialogues' 
                  ? 'text-white border-b-2 border-[#007BFF] data-[state=active]:bg-transparent data-[state=active]:text-white' 
                  : 'text-gray-400 hover:text-white hover:bg-opacity-20 hover:bg-[#007BFF]'}`}
            >
              Dialogues
            </TabsTrigger>
            <TabsTrigger
              value="appearance"
              className={`px-4 py-2 text-sm font-medium whitespace-nowrap transition-colors duration-200
                ${activeTab === 'appearance' 
                  ? 'text-white border-b-2 border-[#007BFF] data-[state=active]:bg-transparent data-[state=active]:text-white' 
                  : 'text-gray-400 hover:text-white hover:bg-opacity-20 hover:bg-[#007BFF]'}`}
            >
              Appearance
            </TabsTrigger>
            <TabsTrigger
              value="shop"
              className={`px-4 py-2 text-sm font-medium whitespace-nowrap transition-colors duration-200
                ${activeTab === 'shop' 
                  ? 'text-white border-b-2 border-[#007BFF] data-[state=active]:bg-transparent data-[state=active]:text-white' 
                  : 'text-gray-400 hover:text-white hover:bg-opacity-20 hover:bg-[#007BFF]'}`}
            >
              Shop
            </TabsTrigger>
          </TabsList>
        </div>

        <div className="flex-1 overflow-y-auto p-4">
          <TabsContent value="general" className="mt-0 h-full">
            <General 
              npc={npc} 
              onUpdateNPC={onUpdateNPC} 
              editMode={editMode} 
            />
          </TabsContent>
          
          <TabsContent value="attributes" className="mt-0 h-full">
            <Attributes 
              npc={npc} 
              onUpdateNPC={onUpdateNPC} 
              editMode={editMode} 
            />
          </TabsContent>
          
          <TabsContent value="dialogues" className="mt-0 h-full">
            <Dialogues 
              npc={npc} 
              onUpdateNPC={onUpdateNPC} 
              editMode={editMode} 
            />
          </TabsContent>
          
          <TabsContent value="appearance" className="mt-0 h-full">
            <Appearance 
              npc={npc} 
              onUpdateNPC={onUpdateNPC} 
              editMode={editMode} 
            />
          </TabsContent>
          
          <TabsContent value="shop" className="mt-0 h-full">
            <NPCShop 
              npc={npc} 
              onUpdateNPC={onUpdateNPC} 
              editMode={editMode} 
              availableItems={availableItems}
            />
          </TabsContent>
        </div>
      </Tabs>
    </div>
  );
};

export default NPCEditor; 