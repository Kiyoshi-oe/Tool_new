import { useState, useEffect } from 'react';
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Textarea } from "@/components/ui/textarea";
import { NPCItem } from '../../types/npcTypes';

interface GeneralProps {
  npc: NPCItem;
  onUpdateNPC: (updatedNPC: NPCItem, field?: string, oldValue?: any) => void;
  editMode: boolean;
}

const General = ({ npc, onUpdateNPC, editMode }: GeneralProps) => {
  const [localNPC, setLocalNPC] = useState<NPCItem>(npc);

  // Update local state when NPC changes
  useEffect(() => {
    setLocalNPC(npc);
  }, [npc]);

  // Function to update NPC properties
  const handleChange = (field: string, value: string | number) => {
    if (!editMode) return;

    const oldValue = localNPC[field];
    const updatedNPC = { ...localNPC, [field]: value };

    if (field === 'displayName') {
      updatedNPC.fields = {
        ...updatedNPC.fields,
        propMover: {
          ...(updatedNPC.fields?.propMover || {}),
          displayName: value as string
        }
      };
    } else if (field === 'description') {
      updatedNPC.fields = {
        ...updatedNPC.fields,
        propMover: {
          ...(updatedNPC.fields?.propMover || {}),
          description: value as string
        }
      };
    }

    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, field, oldValue);
  };

  return (
    <div className="space-y-4 p-4 bg-cyrus-dark-lighter rounded-md border border-cyrus-dark-lightest">
      <h2 className="text-xl font-semibold text-white mb-4">General Information</h2>
      
      <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
        <div className="space-y-2">
          <Label htmlFor="npc-id" className="text-white">NPC ID</Label>
          <Input
            id="npc-id"
            value={localNPC.id}
            onChange={(e) => handleChange('id', e.target.value)}
            disabled={!editMode}
            className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
          />
        </div>
        
        <div className="space-y-2">
          <Label htmlFor="npc-name" className="text-white">Internal Name</Label>
          <Input
            id="npc-name"
            value={localNPC.name}
            onChange={(e) => handleChange('name', e.target.value)}
            disabled={!editMode}
            className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
          />
        </div>
        
        <div className="space-y-2">
          <Label htmlFor="npc-display-name" className="text-white">Display Name (in game)</Label>
          <Input
            id="npc-display-name"
            value={localNPC.displayName}
            onChange={(e) => handleChange('displayName', e.target.value)}
            disabled={!editMode}
            className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
          />
        </div>
        
        <div className="space-y-2">
          <Label htmlFor="npc-type" className="text-white">NPC Type</Label>
          <Input
            id="npc-type"
            value={localNPC.type}
            onChange={(e) => handleChange('type', e.target.value)}
            disabled={!editMode}
            className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
          />
        </div>
      </div>
      
      <div className="space-y-2">
        <Label htmlFor="npc-description" className="text-white">Description</Label>
        <Textarea
          id="npc-description"
          value={localNPC.description || ''}
          onChange={(e) => handleChange('description', e.target.value)}
          disabled={!editMode}
          className="bg-cyrus-dark text-white border-cyrus-dark-lightest min-h-[100px]"
        />
      </div>
    </div>
  );
};

export default General; 