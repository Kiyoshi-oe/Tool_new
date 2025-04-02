import { useState, useEffect } from 'react';
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Button } from "@/components/ui/button";
import { Switch } from "@/components/ui/switch";
import { Card, CardContent } from "@/components/ui/card";
import { NPCItem, NPCShopItem } from '../../types/npcTypes';
import { ResourceItem } from '../../types/fileTypes';
import { DragDropContext, Droppable, Draggable } from '@hello-pangea/dnd';
import { Search, Plus, GripVertical, Trash2 } from 'lucide-react';

interface NPCShopProps {
  npc: NPCItem;
  onUpdateNPC: (updatedNPC: NPCItem, field?: string, oldValue?: any) => void;
  editMode: boolean;
  availableItems?: ResourceItem[]; // Items aus der Ressourcendatei
}

const NPCShop = ({ npc, onUpdateNPC, editMode, availableItems = [] }: NPCShopProps) => {
  const [localNPC, setLocalNPC] = useState<NPCItem>(npc);
  const [searchTerm, setSearchTerm] = useState('');
  const [filteredItems, setFilteredItems] = useState<ResourceItem[]>(availableItems);

  // Aktualisieren des lokalen Zustands, wenn sich der NPC ändert
  useEffect(() => {
    setLocalNPC(npc);
  }, [npc]);

  // Filtern von Items basierend auf der Suche
  useEffect(() => {
    if (!searchTerm.trim()) {
      setFilteredItems(availableItems);
      return;
    }
    
    const lowercaseSearch = searchTerm.toLowerCase();
    const filtered = availableItems.filter(item => 
      item.name.toLowerCase().includes(lowercaseSearch) ||
      item.displayName.toLowerCase().includes(lowercaseSearch) ||
      item.id.toLowerCase().includes(lowercaseSearch)
    );
    
    setFilteredItems(filtered);
  }, [searchTerm, availableItems]);

  // Toggle Shop-Funktionalität
  const handleToggleShop = (enabled: boolean) => {
    if (!editMode) return;
    
    const updatedShop = enabled ? { isShop: true, items: [] } : { isShop: false, items: [] };
    const updatedNPC = { ...localNPC, shop: updatedShop };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'shop.isShop', localNPC.shop?.isShop);
  };

  // Item zum Shop hinzufügen
  const handleAddItemToShop = (item: ResourceItem) => {
    if (!editMode || !localNPC.shop?.isShop) return;
    
    // Prüfen, ob das Item bereits im Shop ist
    const isItemInShop = localNPC.shop.items.some(shopItem => shopItem.id === item.id);
    if (isItemInShop) return;
    
    const newShopItem: NPCShopItem = {
      id: item.id,
      name: item.displayName || item.name,
      price: 100, // Standardpreis
      count: 1, // Standardmenge
      position: localNPC.shop.items.length // Position ans Ende
    };
    
    const updatedItems = [...localNPC.shop.items, newShopItem];
    const updatedShop = { ...localNPC.shop, items: updatedItems };
    const updatedNPC = { ...localNPC, shop: updatedShop };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'shop.items', localNPC.shop.items);
  };

  // Item aus dem Shop entfernen
  const handleRemoveItemFromShop = (itemId: string) => {
    if (!editMode || !localNPC.shop?.isShop) return;
    
    const updatedItems = localNPC.shop.items.filter(item => item.id !== itemId);
    // Neuberechnung der Positionen
    const reorderedItems = updatedItems.map((item, index) => ({
      ...item,
      position: index
    }));
    
    const updatedShop = { ...localNPC.shop, items: reorderedItems };
    const updatedNPC = { ...localNPC, shop: updatedShop };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'shop.items', localNPC.shop.items);
  };

  // Shop-Item aktualisieren (Preis oder Menge)
  const handleUpdateShopItem = (itemId: string, field: 'price' | 'count', value: number) => {
    if (!editMode || !localNPC.shop?.isShop) return;
    
    const updatedItems = localNPC.shop.items.map(item => {
      if (item.id === itemId) {
        return { ...item, [field]: value };
      }
      return item;
    });
    
    const updatedShop = { ...localNPC.shop, items: updatedItems };
    const updatedNPC = { ...localNPC, shop: updatedShop };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, `shop.items.${itemId}.${field}`, 
      localNPC.shop.items.find(item => item.id === itemId)?.[field]);
  };

  // Drag-and-Drop-Neuordnung
  const handleDragEnd = (result) => {
    if (!editMode || !localNPC.shop?.isShop || !result.destination) return;
    
    const items = Array.from(localNPC.shop.items);
    const [reorderedItem] = items.splice(result.source.index, 1);
    items.splice(result.destination.index, 0, reorderedItem);
    
    // Positionen aktualisieren
    const reorderedItems = items.map((item, index) => ({
      ...item,
      position: index
    }));
    
    const updatedShop = { ...localNPC.shop, items: reorderedItems };
    const updatedNPC = { ...localNPC, shop: updatedShop };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'shop.items', localNPC.shop.items);
  };

  return (
    <div className="space-y-6 p-4 bg-cyrus-dark-lighter rounded-md border border-cyrus-dark-lightest">
      <div className="flex justify-between items-center">
        <h2 className="text-xl font-semibold text-white">NPC-Shop</h2>
        <div className="flex items-center gap-2">
          <span className="text-white text-sm">Shop aktivieren</span>
          <Switch 
            checked={localNPC.shop?.isShop || false}
            onCheckedChange={handleToggleShop}
            disabled={!editMode}
          />
        </div>
      </div>
      
      {localNPC.shop?.isShop ? (
        <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
          {/* Verfügbare Items (linke Spalte) */}
          <div className="space-y-4">
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
                
                <div className="max-h-[400px] overflow-y-auto pr-1">
                  {filteredItems.length > 0 ? (
                    <ul className="space-y-1">
                      {filteredItems.map(item => (
                        <li 
                          key={item.id}
                          className="p-2 bg-cyrus-dark-lighter rounded flex justify-between items-center hover:bg-cyrus-dark-lightest cursor-pointer"
                          onClick={() => handleAddItemToShop(item)}
                        >
                          <div className="truncate">
                            <span className="text-white text-sm">{item.displayName || item.name}</span>
                            <p className="text-gray-400 text-xs truncate">ID: {item.id}</p>
                          </div>
                          {editMode && (
                            <Button
                              variant="ghost"
                              size="sm"
                              onClick={(e) => {
                                e.stopPropagation();
                                handleAddItemToShop(item);
                              }}
                              className="h-6 w-6 p-0"
                            >
                              <Plus className="h-4 w-4 text-green-400" />
                            </Button>
                          )}
                        </li>
                      ))}
                    </ul>
                  ) : (
                    <div className="text-center text-gray-400 py-4">
                      {availableItems.length === 0 ? 'Keine Items geladen' : 'Keine Items gefunden'}
                    </div>
                  )}
                </div>
              </CardContent>
            </Card>
          </div>
          
          {/* Shop-Items (rechte Spalte) */}
          <div className="lg:col-span-2">
            <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
              <CardContent className="pt-6">
                <h3 className="text-md font-semibold text-white mb-3">Shop-Items</h3>
                
                {localNPC.shop.items.length > 0 ? (
                  <DragDropContext onDragEnd={handleDragEnd}>
                    <Droppable droppableId="shop-items">
                      {(provided) => (
                        <ul 
                          className="space-y-2"
                          {...provided.droppableProps}
                          ref={provided.innerRef}
                        >
                          {localNPC.shop.items.map((item, index) => (
                            <Draggable 
                              key={item.id} 
                              draggableId={item.id} 
                              index={index}
                              isDragDisabled={!editMode}
                            >
                              {(provided) => (
                                <li
                                  ref={provided.innerRef}
                                  {...provided.draggableProps}
                                  className="p-3 bg-cyrus-dark-lighter rounded"
                                >
                                  <div className="flex items-center gap-2">
                                    {editMode && (
                                      <div {...provided.dragHandleProps} className="cursor-grab">
                                        <GripVertical className="h-5 w-5 text-gray-400" />
                                      </div>
                                    )}
                                    
                                    <div className="flex-1 grid grid-cols-1 md:grid-cols-3 gap-3">
                                      <div>
                                        <span className="text-white text-sm block mb-1">{item.name}</span>
                                        <span className="text-gray-400 text-xs">ID: {item.id}</span>
                                      </div>
                                      
                                      <div className="space-y-1">
                                        <Label htmlFor={`item-price-${item.id}`} className="text-white text-xs">Preis</Label>
                                        <Input
                                          id={`item-price-${item.id}`}
                                          type="number"
                                          value={item.price}
                                          onChange={(e) => handleUpdateShopItem(item.id, 'price', parseInt(e.target.value))}
                                          disabled={!editMode}
                                          className="h-8 bg-cyrus-dark text-white border-cyrus-dark-lightest"
                                        />
                                      </div>
                                      
                                      <div className="space-y-1">
                                        <Label htmlFor={`item-count-${item.id}`} className="text-white text-xs">Anzahl</Label>
                                        <Input
                                          id={`item-count-${item.id}`}
                                          type="number"
                                          value={item.count}
                                          onChange={(e) => handleUpdateShopItem(item.id, 'count', parseInt(e.target.value))}
                                          disabled={!editMode}
                                          className="h-8 bg-cyrus-dark text-white border-cyrus-dark-lightest"
                                        />
                                      </div>
                                    </div>
                                    
                                    {editMode && (
                                      <Button
                                        variant="ghost"
                                        size="sm"
                                        onClick={() => handleRemoveItemFromShop(item.id)}
                                        className="h-8 w-8 p-0 hover:bg-red-500/20"
                                      >
                                        <Trash2 className="h-4 w-4 text-red-400" />
                                      </Button>
                                    )}
                                  </div>
                                </li>
                              )}
                            </Draggable>
                          ))}
                          {provided.placeholder}
                        </ul>
                      )}
                    </Droppable>
                  </DragDropContext>
                ) : (
                  <div className="text-center text-gray-400 py-6 border border-dashed border-gray-700 rounded-md">
                    <p>Keine Items im Shop</p>
                    <p className="text-xs mt-1">Fügen Sie Items aus der linken Liste hinzu oder ziehen Sie sie per Drag & Drop</p>
                  </div>
                )}
              </CardContent>
            </Card>
          </div>
        </div>
      ) : (
        <div className="bg-cyrus-dark p-8 rounded-md text-center">
          <p className="text-gray-400">
            Der NPC-Shop ist deaktiviert. Aktivieren Sie den Shop, um Items zu verwalten.
          </p>
        </div>
      )}
    </div>
  );
};

export default NPCShop; 