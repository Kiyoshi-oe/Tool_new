import { useState, useEffect } from 'react';
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select";
import { NPCItem } from '../../types/npcTypes';
import { Card, CardContent } from "@/components/ui/card";

interface AttributesProps {
  npc: NPCItem;
  onUpdateNPC: (updatedNPC: NPCItem, field?: string, oldValue?: any) => void;
  editMode: boolean;
}

const behaviorTypes = [
  { value: 'passive', label: 'Passive' },
  { value: 'aggressive', label: 'Aggressive' },
  { value: 'merchant', label: 'Merchant' },
  { value: 'quest', label: 'Quest Giver' },
  { value: 'guard', label: 'Guard' },
];

const Attributes = ({ npc, onUpdateNPC, editMode }: AttributesProps) => {
  const [localNPC, setLocalNPC] = useState<NPCItem>(npc);

  // Update local state when NPC changes
  useEffect(() => {
    setLocalNPC(npc);
  }, [npc]);

  // Function to update position
  const handlePositionChange = (field: keyof NPCItem['position'], value: number) => {
    if (!editMode) return;

    const oldValue = localNPC.position[field];
    const updatedPosition = { ...localNPC.position, [field]: value };
    const updatedNPC = { ...localNPC, position: updatedPosition };

    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `position.${field}`, oldValue);
  };

  // Function to update stats
  const handleStatsChange = (field: string, value: number) => {
    if (!editMode) return;

    const oldValue = localNPC.stats?.[field];
    // Make sure hp is always present, even if it wasn't defined before
    const updatedStats = { 
      ...(localNPC.stats || { hp: 0 }), // Default hp: 0 if stats doesn't exist yet
      [field]: value 
    };
    
    // Make sure hp is always set if it doesn't exist yet
    if (field !== 'hp' && !updatedStats.hp) {
      updatedStats.hp = 0;
    }
    
    const updatedNPC = { ...localNPC, stats: updatedStats };

    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `stats.${field}`, oldValue);
  };

  // Function to update simple properties
  const handleChange = (field: string, value: string | number) => {
    if (!editMode) return;

    const oldValue = localNPC[field];
    const updatedNPC = { ...localNPC, [field]: value };

    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, field, oldValue);
  };

  return (
    <div className="space-y-6 p-4 bg-cyrus-dark-lighter rounded-md border border-cyrus-dark-lightest">
      <h2 className="text-xl font-semibold text-white mb-4">Attributes & Statistics</h2>
      
      <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
        <CardContent className="pt-6">
          <h3 className="text-md font-semibold text-white mb-3">Position & Orientation</h3>
          <div className="grid grid-cols-2 sm:grid-cols-4 gap-4">
            <div className="space-y-2">
              <Label htmlFor="position-x" className="text-white">X Position</Label>
              <Input
                id="position-x"
                type="number"
                value={localNPC.position.x}
                onChange={(e) => handlePositionChange('x', parseFloat(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
            
            <div className="space-y-2">
              <Label htmlFor="position-y" className="text-white">Y Position</Label>
              <Input
                id="position-y"
                type="number"
                value={localNPC.position.y}
                onChange={(e) => handlePositionChange('y', parseFloat(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
            
            <div className="space-y-2">
              <Label htmlFor="position-z" className="text-white">Z Position</Label>
              <Input
                id="position-z"
                type="number"
                value={localNPC.position.z}
                onChange={(e) => handlePositionChange('z', parseFloat(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
            
            <div className="space-y-2">
              <Label htmlFor="position-angle" className="text-white">Viewing Angle</Label>
              <Input
                id="position-angle"
                type="number"
                value={localNPC.position.angle}
                onChange={(e) => handlePositionChange('angle', parseFloat(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
          </div>
        </CardContent>
      </Card>
      
      <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
        <CardContent className="pt-6">
          <h3 className="text-md font-semibold text-white mb-3">NPC Properties</h3>
          <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 gap-4">
            <div className="space-y-2">
              <Label htmlFor="npc-level" className="text-white">Level</Label>
              <Input
                id="npc-level"
                type="number"
                value={localNPC.level}
                onChange={(e) => handleChange('level', parseInt(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
            
            <div className="space-y-2">
              <Label htmlFor="npc-behavior" className="text-white">Behavior Type</Label>
              <Select 
                value={localNPC.behavior || 'passive'} 
                onValueChange={(value) => handleChange('behavior', value)}
                disabled={!editMode}
              >
                <SelectTrigger className="bg-cyrus-dark text-white border-cyrus-dark-lightest">
                  <SelectValue placeholder="Select behavior type" />
                </SelectTrigger>
                <SelectContent className="bg-cyrus-dark text-white border-cyrus-dark-lightest">
                  {behaviorTypes.map((type) => (
                    <SelectItem key={type.value} value={type.value}>
                      {type.label}
                    </SelectItem>
                  ))}
                </SelectContent>
              </Select>
            </div>
          </div>
        </CardContent>
      </Card>
      
      <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
        <CardContent className="pt-6">
          <h3 className="text-md font-semibold text-white mb-3">Combat Statistics</h3>
          <div className="grid grid-cols-2 sm:grid-cols-3 md:grid-cols-5 gap-4">
            <div className="space-y-2">
              <Label htmlFor="npc-hp" className="text-white">HP</Label>
              <Input
                id="npc-hp"
                type="number"
                value={localNPC.stats?.hp || 0}
                onChange={(e) => handleStatsChange('hp', parseInt(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
            
            <div className="space-y-2">
              <Label htmlFor="npc-mp" className="text-white">MP</Label>
              <Input
                id="npc-mp"
                type="number"
                value={localNPC.stats?.mp || 0}
                onChange={(e) => handleStatsChange('mp', parseInt(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
            
            <div className="space-y-2">
              <Label htmlFor="npc-def" className="text-white">DEF</Label>
              <Input
                id="npc-def"
                type="number"
                value={localNPC.stats?.def || 0}
                onChange={(e) => handleStatsChange('def', parseInt(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
            
            <div className="space-y-2">
              <Label htmlFor="npc-atk" className="text-white">ATK</Label>
              <Input
                id="npc-atk"
                type="number"
                value={localNPC.stats?.atk || 0}
                onChange={(e) => handleStatsChange('atk', parseInt(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
            
            <div className="space-y-2">
              <Label htmlFor="npc-exp" className="text-white">EXP</Label>
              <Input
                id="npc-exp"
                type="number"
                value={localNPC.stats?.exp || 0}
                onChange={(e) => handleStatsChange('exp', parseInt(e.target.value))}
                disabled={!editMode}
                className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
              />
            </div>
          </div>
        </CardContent>
      </Card>
    </div>
  );
};

export default Attributes; 