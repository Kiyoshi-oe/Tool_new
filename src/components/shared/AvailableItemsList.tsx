import { useState, useEffect } from 'react';
import { Input } from "@/components/ui/input";
import { Button } from "@/components/ui/button";
import { Card, CardContent } from "@/components/ui/card";
import { ResourceItem } from '../../types/fileTypes'; // Pfad anpassen, falls nötig
import { Search, Plus } from 'lucide-react';
import { ScrollArea } from "@/components/ui/scroll-area";

interface AvailableItemsListProps {
  availableItems: ResourceItem[];
  onSelectItem: (item: ResourceItem) => void;
  // Optional: editMode könnte benötigt werden, um den Add-Button anzuzeigen/auszublenden
  // editMode?: boolean; 
}

const AvailableItemsList = ({ availableItems = [], onSelectItem }: AvailableItemsListProps) => {
  const [searchTerm, setSearchTerm] = useState('');
  const [filteredItems, setFilteredItems] = useState<ResourceItem[]>([]); // Starte mit leerem Array, wird durch useEffect gesetzt

  console.log("[AvailableItemsList] Rendering. Erhaltene availableItems Länge:", availableItems.length); // LOG hinzugefügt

  // Setze filteredItems, wenn availableItems sich ändert oder initial geladen wird
  useEffect(() => {
    console.log("[AvailableItemsList] useEffect - availableItems geändert. Länge:", availableItems.length); // LOG hinzugefügt
    setFilteredItems(availableItems);
  }, [availableItems]);
  
  // Filtere Items basierend auf searchTerm
  useEffect(() => {
    if (!searchTerm.trim()) {
      setFilteredItems(availableItems); // Zeige alle, wenn Suche leer ist
      return;
    }
    
    const lowercaseSearch = searchTerm.toLowerCase();
    console.log("[AvailableItemsList] Suche nach:", lowercaseSearch); // LOG hinzugefügt
    const filtered = availableItems.filter(item => 
      item.name.toLowerCase().includes(lowercaseSearch) ||
      (item.displayName && item.displayName.toLowerCase().includes(lowercaseSearch)) || // displayName prüfen
      item.id.toLowerCase().includes(lowercaseSearch)
    );
    console.log("[AvailableItemsList] Gefilterte Items Länge:", filtered.length); // LOG hinzugefügt
    
    setFilteredItems(filtered);
  }, [searchTerm, availableItems]);

  return (
    <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
      <CardContent className="pt-6">
        <h3 className="text-md font-semibold text-white mb-3">Verfügbare Items</h3>
        
        <div className="relative mb-3">
          <Input 
            type="text"
            placeholder="Item suchen..."
            value={searchTerm}
            onChange={(e) => setSearchTerm(e.target.value)}
            className="pl-8 bg-cyrus-dark text-white border-cyrus-dark-lightest"
          />
          <Search className="absolute left-2 top-2.5 h-4 w-4 text-gray-400" />
        </div>
        
        <ScrollArea className="h-[400px] pr-1"> {/* Verwende ScrollArea für bessere Konsistenz */}
          {filteredItems.length > 0 ? (
            <ul className="space-y-1">
              {filteredItems.map(item => (
                <li 
                  key={item.id}
                  className="p-2 bg-cyrus-dark-lighter rounded flex justify-between items-center hover:bg-cyrus-dark-lightest cursor-pointer group" // Gruppe für Hover-Effekt auf Button
                  onClick={() => onSelectItem(item)}
                >
                  <div className="truncate">
                    <span className="text-white text-sm">{item.displayName || item.name}</span>
                    <p className="text-gray-400 text-xs truncate">ID: {item.id}</p>
                  </div>
                  {/* Der Button ist optional und könnte über eine Prop gesteuert werden */}
                  <Button
                      variant="ghost"
                      size="sm"
                      onClick={(e) => {
                        e.stopPropagation(); // Verhindert das Auslösen des li onClick
                        onSelectItem(item);
                      }}
                      className="h-6 w-6 p-0 opacity-0 group-hover:opacity-100 transition-opacity" // Nur bei Hover anzeigen
                    >
                      <Plus className="h-4 w-4 text-green-400" />
                    </Button>
                </li>
              ))}
            </ul>
          ) : (
            <div className="text-center text-gray-400 py-4">
              {availableItems.length === 0 ? 'Keine Items geladen' : 'Keine Items gefunden'}
            </div>
          )}
        </ScrollArea>
      </CardContent>
    </Card>
  );
};

export default AvailableItemsList; 