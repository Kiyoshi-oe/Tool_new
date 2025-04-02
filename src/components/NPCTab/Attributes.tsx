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
  { value: 'passive', label: 'Passiv' },
  { value: 'aggressive', label: 'Aggressiv' },
  { value: 'merchant', label: 'Händler' },
  { value: 'quest', label: 'Questgeber' },
  { value: 'guard', label: 'Wache' },
];

const Attributes = ({ npc, onUpdateNPC, editMode }: AttributesProps) => {
  const [localNPC, setLocalNPC] = useState<NPCItem>(npc);

  // Aktualisieren des lokalen Zustands, wenn sich der NPC ändert
  useEffect(() => {
    setLocalNPC(npc);
  }, [npc]);

  // Funktion zum Aktualisieren von Position
  const handlePositionChange = (field: keyof NPCItem['position'], value: number) => {
    if (!editMode) return;

    const oldValue = localNPC.position[field];
    const updatedPosition = { ...localNPC.position, [field]: value };
    const updatedNPC = { ...localNPC, position: updatedPosition };

    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `position.${field}`, oldValue);
  };

  // Funktion zum Aktualisieren von Stats
  const handleStatsChange = (field: string, value: number) => {
    if (!editMode) return;

    const oldValue = localNPC.stats?.[field];
    // Stelle sicher, dass hp immer vorhanden ist, selbst wenn es bisher nicht definiert war
    const updatedStats = { 
      ...(localNPC.stats || { hp: 0 }), // Default hp: 0 wenn stats noch nicht existiert
      [field]: value 
    };
    
    // Stelle sicher, dass hp immer gesetzt ist, falls es noch nicht existiert
    if (field !== 'hp' && !updatedStats.hp) {
      updatedStats.hp = 0;
    }
    
    const updatedNPC = { ...localNPC, stats: updatedStats };

    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `stats.${field}`, oldValue);
  };

  // Funktion zum Aktualisieren von einfachen Eigenschaften
  const handleChange = (field: string, value: string | number) => {
    if (!editMode) return;

    const oldValue = localNPC[field];
    const updatedNPC = { ...localNPC, [field]: value };

    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, field, oldValue);
  };

  return (
    <div className="space-y-6 p-4 bg-cyrus-dark-lighter rounded-md border border-cyrus-dark-lightest">
      <h2 className="text-xl font-semibold text-white mb-4">Attribute & Statistiken</h2>
      
      <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
        <CardContent className="pt-6">
          <h3 className="text-md font-semibold text-white mb-3">Position & Orientierung</h3>
          <div className="grid grid-cols-2 sm:grid-cols-4 gap-4">
            <div className="space-y-2">
              <Label htmlFor="position-x" className="text-white">X-Position</Label>
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
              <Label htmlFor="position-y" className="text-white">Y-Position</Label>
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
              <Label htmlFor="position-z" className="text-white">Z-Position</Label>
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
              <Label htmlFor="position-angle" className="text-white">Blickwinkel</Label>
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
          <h3 className="text-md font-semibold text-white mb-3">NPC-Eigenschaften</h3>
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
              <Label htmlFor="npc-behavior" className="text-white">Verhaltenstyp</Label>
              <Select 
                value={localNPC.behavior || 'passive'} 
                onValueChange={(value) => handleChange('behavior', value)}
                disabled={!editMode}
              >
                <SelectTrigger className="bg-cyrus-dark text-white border-cyrus-dark-lightest">
                  <SelectValue placeholder="Verhaltenstyp wählen" />
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
          <h3 className="text-md font-semibold text-white mb-3">Kampfstatistiken</h3>
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