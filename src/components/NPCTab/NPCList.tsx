import { useState, useEffect, useMemo } from 'react';
import { Input } from "@/components/ui/input";
import { Button } from "@/components/ui/button";
import { NPCItem } from '../../types/npcTypes';
import { Search } from 'lucide-react';

interface NPCListProps {
  npcs: NPCItem[];
  selectedNPC: NPCItem | null;
  onSelectNPC: (npc: NPCItem) => void;
}

const NPCList = ({ npcs, selectedNPC, onSelectNPC }: NPCListProps) => {
  const [searchTerm, setSearchTerm] = useState('');
  const [filter, setFilter] = useState<string>('all');

  // Filter NPCs based on search term and filter
  const filteredNPCs = useMemo(() => {
    if (!npcs || npcs.length === 0) return [];
    
    return npcs.filter(npc => {
      const matchesSearch = npc.name.toLowerCase().includes(searchTerm.toLowerCase()) || 
                           npc.displayName.toLowerCase().includes(searchTerm.toLowerCase()) ||
                           npc.id.toLowerCase().includes(searchTerm.toLowerCase());
      
      if (filter === 'all') return matchesSearch;
      return matchesSearch && npc.type === filter;
    });
  }, [npcs, searchTerm, filter]);

  // Extract NPC types for the filter
  const npcTypes = useMemo(() => {
    if (!npcs || npcs.length === 0) return [];
    
    const types = new Set<string>();
    npcs.forEach(npc => {
      if (npc.type) types.add(npc.type);
    });
    
    return Array.from(types);
  }, [npcs]);

  return (
    <div className="h-full flex flex-col border-r border-cyrus-dark-lightest bg-cyrus-dark">
      <div className="p-3 border-b border-cyrus-dark-lightest">
        <h2 className="text-lg font-semibold mb-2 text-white">NPCs</h2>
        
        <div className="relative mb-2">
          <Input 
            type="text"
            placeholder="Search NPCs..."
            value={searchTerm}
            onChange={(e) => setSearchTerm(e.target.value)}
            className="pl-8 w-full bg-cyrus-dark-lighter text-white border-cyrus-dark-lightest"
          />
          <Search className="absolute left-2 top-2.5 h-4 w-4 text-gray-400" />
        </div>
        
        <div className="flex flex-wrap gap-1 mt-2">
          <Button 
            variant={filter === 'all' ? "default" : "secondary"}
            className="text-xs px-2 py-1 h-6"
            onClick={() => setFilter('all')}
          >
            All
          </Button>
          
          {npcTypes.map(type => (
            <Button
              key={type}
              variant={filter === type ? "default" : "secondary"}
              className="text-xs px-2 py-1 h-6"
              onClick={() => setFilter(type)}
            >
              {type}
            </Button>
          ))}
        </div>
      </div>
      
      <div className="flex-1 overflow-y-auto">
        {filteredNPCs.length > 0 ? (
          <ul className="divide-y divide-cyrus-dark-lightest">
            {filteredNPCs.map(npc => (
              <li 
                key={npc.id}
                className={`p-2 cursor-pointer hover:bg-cyrus-dark-lighter ${
                  selectedNPC && selectedNPC.id === npc.id ? 'bg-cyrus-dark-lighter border-l-2 border-[#007BFF]' : ''
                }`}
                onClick={() => onSelectNPC(npc)}
              >
                <div className="text-sm font-medium text-white">{npc.displayName}</div>
                <div className="text-xs text-gray-400">ID: {npc.id} - {npc.type}</div>
              </li>
            ))}
          </ul>
        ) : (
          <div className="p-4 text-center text-gray-400">
            {npcs.length === 0 ? "No NPCs loaded" : "No NPCs found"}
          </div>
        )}
      </div>
    </div>
  );
};

export default NPCList; 