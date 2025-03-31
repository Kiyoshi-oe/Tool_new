import React, { useState, useEffect, useMemo } from "react";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "../ui/tabs";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from "../ui/card";
import { Button } from "../ui/button";
import { FormField } from "../ui/form-field";
import { Table, TableHeader, TableBody, TableRow, TableHead, TableCell } from "../ui/table";
import { parseCollectorData, serializeCollectorData, validateCollectorData, calculatePercentage } from "../../utils/collectorUtils";
import { CollectorData, CollectingItem, CollectorValidationResult } from "../../types/collectorTypes";
import { Plus, Save, Trash, AlertTriangle, Search, Filter, X, Copy, ChevronDown, Edit, MoreHorizontal, Download, Upload } from "lucide-react";
import { toast } from "sonner";
import { Input } from "../ui/input";
import { DropdownMenu, DropdownMenuContent, DropdownMenuItem, DropdownMenuTrigger } from "../ui/dropdown-menu";
import { Checkbox } from "../ui/checkbox";
import { Dialog, DialogContent, DialogDescription, DialogFooter, DialogHeader, DialogTitle, DialogTrigger } from "../ui/dialog";
import { Label } from "../ui/label";
import { ScrollArea } from "../ui/scroll-area";
import { Badge } from "../ui/badge";
import { DndContext, DragEndEvent, closestCenter, KeyboardSensor, PointerSensor, useSensor, useSensors } from '@dnd-kit/core';
import { arrayMove, SortableContext, sortableKeyboardCoordinates, useSortable, verticalListSortingStrategy } from '@dnd-kit/sortable';
import { CSS } from '@dnd-kit/utilities';
import { saveAs } from 'file-saver';
import { FileWithPath, useDropzone } from 'react-dropzone';

// Füge globale Styles für Formular-Elemente hinzu
import './styles/dark-mode.css';

// Definiere die globale Konfiguration für TypeScript
declare global {
  interface Window {
    APP_CONFIG?: {
      fileData?: {
        items: Array<{
          id: string;
          name: string;
          displayName?: string;
          description?: string;
          data?: {
            dwItemKind1?: string | number;
            [key: string]: any;
          };
        }>;
      };
    };
  }
}

interface CollectorTabProps {
  fileContent: string;
  onSave: (content: string) => void;
  editMode?: boolean; // Add editMode prop
}

const CollectorTab: React.FC<CollectorTabProps> = ({ fileContent, onSave, editMode = false }) => {
  const [collectorData, setCollectorData] = useState<CollectorData | null>(null);
  const [validation, setValidation] = useState<CollectorValidationResult | null>(null);
  const [activeTab, setActiveTab] = useState("enchant");
  const [searchQuery, setSearchQuery] = useState("");
  const [selectedItems, setSelectedItems] = useState<string[]>([]);
  const [showAddItemDialog, setShowAddItemDialog] = useState(false);
  const [selectedCategory, setSelectedCategory] = useState<'items' | 'premiumItems' | 'premiumStatusItems'>('items');
  const [showImportDialog, setShowImportDialog] = useState(false);
  const [showBatchImportDialog, setShowBatchImportDialog] = useState(false);
  const [fileDataLoaded, setFileDataLoaded] = useState(false);
  
  // Laden der globalen spec_item.txt-Daten bei Komponentenmontage
  useEffect(() => {
    // Prüfe, ob die fileData im globalen Scope existiert
    const checkForFileData = () => {
      if (window.APP_CONFIG && window.APP_CONFIG.fileData) {
        console.log("Spec_item Daten gefunden, Items:", window.APP_CONFIG.fileData.items?.length || 0);
        setFileDataLoaded(true);
        return true;
      }
      return false;
    };
    
    // Wenn die Daten noch nicht geladen sind, warten und erneut prüfen
    if (!checkForFileData()) {
      console.log("Warte auf das Laden der spec_item.txt-Daten...");
      
      // Event-Listener für Datenaktualisierungen
      const handleDataLoaded = () => {
        checkForFileData();
      };
      
      // Custom Event Listener für Datenladung
      window.addEventListener('fileDataLoaded', handleDataLoaded);
      
      // Alle 2 Sekunden prüfen, ob die Daten geladen wurden
      const interval = setInterval(() => {
        if (checkForFileData()) {
          clearInterval(interval);
        }
      }, 2000);
      
      // Cleanup
      return () => {
        window.removeEventListener('fileDataLoaded', handleDataLoaded);
        clearInterval(interval);
      };
    }
  }, []);

  // Define sensors for DnD correctly, without calling useSensors inside useMemo
  const pointerSensor = useSensor(PointerSensor, {
    activationConstraint: {
      distance: 8,
    },
  });

  const keyboardSensor = useSensor(KeyboardSensor, {
    coordinateGetter: sortableKeyboardCoordinates,
  });

  // Combine all sensors
  const sensors = useSensors(pointerSensor, keyboardSensor);

  // Create a check for DnD
  const hasDragAndDrop = useMemo(() => {
    return collectorData !== null;
  }, [collectorData]);
  
  useEffect(() => {
    if (fileContent) {
      try {
        const data = parseCollectorData(fileContent);
        setCollectorData(data);
        setValidation(validateCollectorData(data));
      } catch (error) {
        console.error("Error parsing collector data:", error);
        toast.error("Error loading collector data");
      }
    }
  }, [fileContent]);
  
  const handleSave = () => {
    if (!collectorData) return;
      
    // Validiere die Daten vor dem Speichern
    const validation = validateCollectorData(collectorData);
    setValidation(validation);
    
    // Serialisiere die Daten und gib sie zurück
    const serialized = serializeCollectorData(collectorData, fileContent);
    onSave(serialized);
    
    // Zeige eine entsprechende Erfolgsmeldung oder Warnung an
    if (!validation.isValid) {
      toast.warning("Änderungen wurden gespeichert, aber es gibt noch Validierungsfehler. Bitte überprüfe die Summen.");
    } else {
      toast.success("Collector-Daten erfolgreich gespeichert");
    }
  };
  
  // Enchant editing
  const handleEnchantChange = (index: number, chance: number) => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const updatedEnchant = [...collectorData.enchant];
    updatedEnchant[index] = { ...updatedEnchant[index], chance };
    
    const updatedData = {
      ...collectorData,
      enchant: updatedEnchant,
      enchantTotal: updatedEnchant.reduce((sum, item) => sum + item.chance, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Item editing
  const handleItemChange = (
    index: number, 
    field: keyof CollectingItem, 
    value: string | number,
    category: 'items' | 'premiumItems' | 'premiumStatusItems'
  ) => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const updatedItems = [...collectorData[category]];
    updatedItems[index] = { 
      ...updatedItems[index], 
      [field]: field === 'probability' ? Number(value) : value 
    };
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Add item
  const handleAddItem = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const updatedItems = [...collectorData[category], { itemId: "II_NEW_ITEM", probability: 0 }];
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Remove item
  const handleRemoveItem = (
    index: number,
    category: 'items' | 'premiumItems' | 'premiumStatusItems'
  ) => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const updatedItems = [...collectorData[category]];
    updatedItems.splice(index, 1);
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Function to duplicate an item
  const handleDuplicateItem = (
    index: number,
    category: 'items' | 'premiumItems' | 'premiumStatusItems'
  ) => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const itemToDuplicate = collectorData[category][index];
    const duplicatedItem = { ...itemToDuplicate, probability: 0 }; // Default with 0 probability
    
    const updatedItems = [...collectorData[category]];
    updatedItems.splice(index + 1, 0, duplicatedItem); // Insert after the original
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
    toast.success("Item duplicated");
  };
  
  // Function to add enchantments
  const handleAddEnchant = () => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const nextLevel = collectorData.enchant.length > 0 
      ? Math.max(...collectorData.enchant.map(e => e.level)) + 1 
      : 0;
    
    const updatedEnchant = [...collectorData.enchant, { level: nextLevel, chance: 0 }];
    
    const updatedData = {
      ...collectorData,
      enchant: updatedEnchant,
      enchantTotal: updatedEnchant.reduce((sum, item) => sum + item.chance, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Function to remove enchantments
  const handleRemoveEnchant = (index: number) => {
    if (!collectorData) return;
    
    const updatedEnchant = [...collectorData.enchant];
    updatedEnchant.splice(index, 1);
    
    const updatedData = {
      ...collectorData,
      enchant: updatedEnchant,
      enchantTotal: updatedEnchant.reduce((sum, item) => sum + item.chance, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Enchant Level change
  const handleEnchantLevelChange = (index: number, level: number) => {
    if (!collectorData) return;
    
    const updatedEnchant = [...collectorData.enchant];
    updatedEnchant[index] = { ...updatedEnchant[index], level };
    
    const updatedData = {
      ...collectorData,
      enchant: updatedEnchant
    };
    
    setCollectorData(updatedData);
  };
  
  // Function to filter items based on the search
  const filteredItemsMemo = useMemo(() => {
    const filterItems = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
      if (!collectorData) return [];
      
      return collectorData[category].filter(item => 
        item.itemId.toLowerCase().includes(searchQuery.toLowerCase())
      );
    };
    
    return {
      items: filterItems('items'),
      premiumItems: filterItems('premiumItems'),
      premiumStatusItems: filterItems('premiumStatusItems')
    };
  }, [collectorData, searchQuery]);
  
  // Function to delete multiple selected items
  const handleRemoveSelectedItems = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    if (!collectorData || selectedItems.length === 0) return;
    
    const updatedItems = collectorData[category].filter(item => !selectedItems.includes(item.itemId));
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
    setSelectedItems([]);
    toast.success(`${selectedItems.length} items deleted`);
  };
  
  // Function to adjust probabilities of selected items
  const adjustProbabilities = (
    category: 'items' | 'premiumItems' | 'premiumStatusItems', 
    method: 'equal' | 'proportional' | 'reset'
  ) => {
    if (!collectorData || selectedItems.length === 0) return;
    
    const updatedItems = [...collectorData[category]];
    
    // Calculate the total probability of all non-selected items
    const nonSelectedTotal = updatedItems
      .filter(item => !selectedItems.includes(item.itemId))
      .reduce((sum, item) => sum + item.probability, 0);
    
    // Available probability for selected items
    const availableProbability = 1000000 - nonSelectedTotal;
    
    if (method === 'equal') {
      // Equal distribution across all selected items
      const equalProbability = Math.floor(availableProbability / selectedItems.length);
      
      updatedItems.forEach(item => {
        if (selectedItems.includes(item.itemId)) {
          item.probability = equalProbability;
        }
      });
    } else if (method === 'proportional') {
      // Calculate the current total probability of selected items
      const selectedTotal = updatedItems
        .filter(item => selectedItems.includes(item.itemId))
        .reduce((sum, item) => sum + item.probability, 0);
      
      if (selectedTotal > 0) {
        // Proportional adjustment
        const ratio = availableProbability / selectedTotal;
        
        updatedItems.forEach(item => {
          if (selectedItems.includes(item.itemId)) {
            item.probability = Math.floor(item.probability * ratio);
          }
        });
      }
    } else if (method === 'reset') {
      // Reset all selected items to 0
      updatedItems.forEach(item => {
        if (selectedItems.includes(item.itemId)) {
          item.probability = 0;
        }
      });
    }
    
    // Round differences to get exactly 1,000,000
    const newTotal = updatedItems.reduce((sum, item) => sum + item.probability, 0);
    const diff = 1000000 - newTotal;
    
    if (diff !== 0 && selectedItems.length > 0) {
      // Add the difference to the first selected item
      const firstSelectedItem = updatedItems.find(item => selectedItems.includes(item.itemId));
      if (firstSelectedItem) {
        firstSelectedItem.probability += diff;
      }
    }
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
    toast.success(`Probabilities adjusted using ${method} distribution`);
  };
  
  // Function to distribute all probabilities evenly
  const distributeEvenly = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    if (!collectorData || collectorData[category].length === 0) return;
    
    const totalItems = collectorData[category].length;
    
    // If there's only one item, it gets the entire probability
    if (totalItems === 1) {
      const updatedItems = [...collectorData[category]];
      updatedItems[0] = { ...updatedItems[0], probability: 1000000 };
      
      const updatedData = {
        ...collectorData,
        [category]: updatedItems,
        [`${category}Total`]: 1000000
      };
      
      setCollectorData(updatedData);
      setValidation(validateCollectorData(updatedData));
      toast.success("All probability assigned to the single item");
      return;
    }
    
    // Even distribution
    const baseProbability = Math.floor(1000000 / totalItems);
    let remainder = 1000000 % totalItems;
    
    const updatedItems = [...collectorData[category]].map(item => {
      const extraAmount = remainder > 0 ? 1 : 0;
      remainder -= extraAmount;
      return { ...item, probability: baseProbability + extraAmount };
    });
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
    toast.success(`Probabilities evenly distributed across all ${totalItems} items`);
  };
  
  // Function to distribute enchantment probabilities evenly
  const distributeEnchantEvenly = () => {
    if (!collectorData || collectorData.enchant.length === 0) return;
    
    const totalEnchants = collectorData.enchant.length;
    
    // If there's only one enchantment, it gets the entire probability
    if (totalEnchants === 1) {
      const updatedEnchant = [...collectorData.enchant];
      updatedEnchant[0] = { ...updatedEnchant[0], chance: 1000 };
      
      const updatedData = {
        ...collectorData,
        enchant: updatedEnchant,
        enchantTotal: 1000
      };
      
      setCollectorData(updatedData);
      setValidation(validateCollectorData(updatedData));
      toast.success("All probability assigned to the single enchantment");
      return;
    }
    
    // Even distribution
    const baseChance = Math.floor(1000 / totalEnchants);
    let remainder = 1000 % totalEnchants;
    
    const updatedEnchant = [...collectorData.enchant].map(enchant => {
      const extraAmount = remainder > 0 ? 1 : 0;
      remainder -= extraAmount;
      return { ...enchant, chance: baseChance + extraAmount };
    });
    
    const updatedData = {
      ...collectorData,
      enchant: updatedEnchant,
      enchantTotal: updatedEnchant.reduce((sum, enchant) => sum + enchant.chance, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
    toast.success(`Enchantment chances evenly distributed across all ${totalEnchants} levels`);
  };
  
  // Dialog for adding new items - with dark mode styling
  const ItemSearchDialog = () => {
    const [itemSearchQuery, setItemSearchQuery] = useState("");
    const [searchResults, setSearchResults] = useState<{id: string, name: string, description?: string}[]>([]);
    const [selectedItemId, setSelectedItemId] = useState("");
    const [probability, setProbability] = useState(1000);
    const [searchType, setSearchType] = useState<'id' | 'name' | 'category'>('id');
    const [isSearching, setIsSearching] = useState(false);
    
    // Zugriff auf die globale fileData-Variable für die spec_item.txt-Daten
    useEffect(() => {
      // Prüfe, ob Daten in der globalen Variable verfügbar sind
      if (window.APP_CONFIG && window.APP_CONFIG.fileData && window.APP_CONFIG.fileData.items) {
        // Initial suchen, wenn Dialog geöffnet wird
        handleSearch();
      }
    }, [showAddItemDialog]);
    
    // Verbesserte Suchfunktion mit Zugriff auf die tatsächlichen spec_item.txt-Daten
    const handleSearch = () => {
      try {
        setIsSearching(true);
        let results: {id: string, name: string, description?: string}[] = [];
        
        // Prüfe, ob Daten in der globalen Variable verfügbar sind
        if (window.APP_CONFIG && window.APP_CONFIG.fileData && window.APP_CONFIG.fileData.items) {
          const items = window.APP_CONFIG.fileData.items;
          
          // Suchlogik basierend auf dem Suchtyp
          if (searchType === 'id') {
            results = items
              .filter(item => item.id.toLowerCase().includes(itemSearchQuery.toLowerCase()))
              .map(item => ({
                id: item.id,
                name: item.displayName || item.name,
                description: item.description
              }))
              .slice(0, 100); // Begrenze die Ergebnisse auf 100 Items
          } else if (searchType === 'name') {
            results = items
              .filter(item => 
                (item.displayName && item.displayName.toLowerCase().includes(itemSearchQuery.toLowerCase())) ||
                (item.name && item.name.toLowerCase().includes(itemSearchQuery.toLowerCase()))
              )
              .map(item => ({
                id: item.id,
                name: item.displayName || item.name,
                description: item.description
              }))
              .slice(0, 100);
          } else if (searchType === 'category') {
            // Suche nach der Kategorie im data-Objekt
            results = items
              .filter(item => {
                const category = item.data?.dwItemKind1 || '';
                return category.toString().toLowerCase().includes(itemSearchQuery.toLowerCase());
              })
              .map(item => ({
                id: item.id,
                name: item.displayName || item.name,
                description: item.description
              }))
              .slice(0, 100);
          }
        } else {
          // Fallback, wenn keine fileData gefunden wurde
          console.warn("Keine spec_item.txt-Daten gefunden, verwende Beispieldaten");
          
          // Beispieldaten für den Demo-Modus
          const demoResults = [
            { id: "II_SYS_SYS_SCR_BXCOLLPREM", name: "Premium Collector Box" },
            { id: "II_SYS_SYS_SCR_MINIWHEEL", name: "Mini Fortune Wheel" },
            { id: "II_SYS_SYS_SCR_WHEEL", name: "Fortune Wheel" },
            { id: "II_CHP_COLLECTOR", name: "Collector Chip" }
          ].filter(item => 
            item.id.toLowerCase().includes(itemSearchQuery.toLowerCase()) || 
            item.name.toLowerCase().includes(itemSearchQuery.toLowerCase())
          );
          
          results = demoResults;
        }
        
        setSearchResults(results);
        if (results.length > 0 && !selectedItemId) {
          setSelectedItemId(results[0].id);
        }
        
      } catch (error) {
        console.error("Fehler bei der Suche:", error);
        toast.error("Fehler bei der Suche nach Items");
      } finally {
        setIsSearching(false);
      }
    };
    
    const handleAddItem = () => {
      if (!selectedItemId || !collectorData) return;
      
      const newItem = {
        itemId: selectedItemId,
        probability: probability
      };
      
      const updatedItems = [...collectorData[selectedCategory], newItem];
      
      const updatedData = {
        ...collectorData,
        [selectedCategory]: updatedItems,
        [`${selectedCategory}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
      };
      
      setCollectorData(updatedData);
      setValidation(validateCollectorData(updatedData));
      setShowAddItemDialog(false);
      toast.success(`Item ${selectedItemId} added to ${selectedCategory}`);
    };
    
    return (
      <Dialog open={showAddItemDialog} onOpenChange={setShowAddItemDialog}>
        <DialogContent className="sm:max-w-[500px] bg-cyrus-dark-light border-cyrus-dark-lightest">
          <DialogHeader>
            <DialogTitle className="text-gray-200">Add new item</DialogTitle>
            <DialogDescription className="text-gray-400">
              Search for an item and specify its probability
            </DialogDescription>
          </DialogHeader>
          
          <div className="flex gap-2 mb-4">
            <div className="flex-1">
              <Input
                placeholder="Search for an item..."
                value={itemSearchQuery}
                onChange={(e) => setItemSearchQuery(e.target.value)}
                className="bg-cyrus-dark-lighter text-gray-300"
              />
            </div>
            <Button onClick={handleSearch} className="bg-cyrus-blue">
              <Search className="h-4 w-4" />
            </Button>
          </div>
          
          <div className="flex gap-2 mb-4">
            <Button 
              variant={searchType === 'id' ? 'default' : 'outline'} 
              onClick={() => setSearchType('id')}
              className={searchType === 'id' ? 'bg-cyrus-blue' : 'text-gray-300 border-cyrus-dark-lightest'}
              size="sm"
            >
              ID
            </Button>
            <Button 
              variant={searchType === 'name' ? 'default' : 'outline'} 
              onClick={() => setSearchType('name')}
              className={searchType === 'name' ? 'bg-cyrus-blue' : 'text-gray-300 border-cyrus-dark-lightest'}
              size="sm"
            >
              Name
            </Button>
            <Button 
              variant={searchType === 'category' ? 'default' : 'outline'} 
              onClick={() => setSearchType('category')}
              className={searchType === 'category' ? 'bg-cyrus-blue' : 'text-gray-300 border-cyrus-dark-lightest'}
              size="sm"
            >
              Kategorie
            </Button>
          </div>
          
          <div className="flex flex-wrap gap-2 mb-4">
            <Button 
              variant="ghost"
              size="xs"
              onClick={() => {
                setItemSearchQuery("II_WEA");
                handleSearch();
              }}
              className="text-gray-300"
            >
              Waffen
            </Button>
            <Button 
              variant="ghost"
              size="xs"
              onClick={() => {
                setItemSearchQuery("II_ARM");
                handleSearch();
              }}
              className="text-gray-300"
            >
              Rüstung
            </Button>
            <Button 
              variant="ghost"
              size="xs"
              onClick={() => {
                setItemSearchQuery("II_GEN");
                handleSearch();
              }}
              className="text-gray-300"
            >
              Gegenstände
            </Button>
            <Button 
              variant="ghost"
              size="xs"
              onClick={() => {
                setItemSearchQuery("II_SYS");
                handleSearch();
              }}
              className="text-gray-300"
            >
              System
            </Button>
            <Button 
              variant="ghost"
              size="xs"
              onClick={() => {
                setItemSearchQuery("II_GOLD");
                handleSearch();
              }}
              className="text-gray-300"
            >
              Gold
            </Button>
          </div>
          
          <ScrollArea className="max-h-[200px] mb-4 bg-cyrus-dark-lightest p-2 rounded">
            {isSearching ? (
              <div className="flex justify-center items-center h-20">
                <div className="animate-spin h-8 w-8 border-4 border-cyrus-blue border-t-transparent rounded-full"></div>
              </div>
            ) : searchResults.length > 0 ? (
              searchResults.map((result) => (
                <div 
                  key={result.id}
                  className={`p-2 cursor-pointer rounded ${selectedItemId === result.id ? 'bg-cyrus-blue' : 'hover:bg-cyrus-dark-lighter'}`}
                  onClick={() => setSelectedItemId(result.id)}
                >
                  <div className="font-bold text-gray-200">{result.id}</div>
                  <div className="text-sm text-gray-300">{result.name}</div>
                  {result.description && (
                    <div className="text-xs text-gray-400 mt-1 line-clamp-2">{result.description}</div>
                  )}
                </div>
              ))
            ) : !fileDataLoaded && window.APP_CONFIG?.fileData === undefined ? (
              <div className="text-center text-gray-400 py-4">
                Spec_item.txt-Daten werden geladen... Dies kann einige Momente dauern.
              </div>
            ) : (
              <div className="text-center text-gray-400 py-4">
                {itemSearchQuery 
                  ? "Keine Ergebnisse gefunden. Bitte andere Suchbegriffe verwenden."
                  : "Bitte gib einen Suchbegriff ein, um Items zu finden."}
              </div>
            )}
          </ScrollArea>
          
          <div className="flex items-center gap-4 mb-4">
            <Label htmlFor="probability" className="w-32 text-gray-300">Probability:</Label>
            <Input
              id="probability"
              type="number"
              value={probability}
              onChange={(e) => setProbability(parseInt(e.target.value, 10))}
              className="bg-cyrus-dark-lighter text-gray-300"
            />
          </div>
          
          <DialogFooter>
            <Button 
              variant="outline" 
              onClick={() => setShowAddItemDialog(false)}
              className="text-gray-300 border-cyrus-dark-lightest"
            >
              Cancel
            </Button>
            <Button 
              onClick={handleAddItem} 
              disabled={!selectedItemId}
              className="bg-cyrus-blue"
            >
              Add Item
            </Button>
          </DialogFooter>
        </DialogContent>
      </Dialog>
    );
  };
  
  // Export-Funktion für Item-Listen
  const exportItemList = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    if (!collectorData) return;
    
    const items = collectorData[category];
    const fileName = `collector_${category}_${new Date().toISOString().split('T')[0]}.json`;
    
    // Erstelle einen JSON-String mit Einrückung für bessere Lesbarkeit
    const jsonContent = JSON.stringify(items, null, 2);
    
    // Erstelle einen Blob und biete ihn zum Download an
    const blob = new Blob([jsonContent], { type: 'application/json' });
    saveAs(blob, fileName);
    
    toast.success(`Item list exported to ${fileName}`);
  };

  // Import-Funktion für Item-Listen
  const importItemList = async (
    file: FileWithPath, 
    category: 'items' | 'premiumItems' | 'premiumStatusItems'
  ) => {
    if (!collectorData) return;
    
    try {
      // Lese den Dateiinhalt
      const fileContent = await file.text();
      const importedItems = JSON.parse(fileContent) as CollectingItem[];
      
      // Validiere den Import
      if (!Array.isArray(importedItems)) {
        throw new Error('Invalid format: Expected an array of items');
      }
      
      // Prüfe, ob jedes Item das richtige Format hat
      const validItems = importedItems.filter(item => 
        typeof item === 'object' && 
        item !== null && 
        'itemId' in item && 
        'probability' in item
      );
      
      if (validItems.length !== importedItems.length) {
        throw new Error('Some items in the import file have invalid format');
      }
      
      // Aktualisiere die Daten
      const updatedData = {
        ...collectorData,
        [category]: validItems,
        [`${category}Total`]: validItems.reduce((sum, item) => sum + item.probability, 0)
      };
      
      setCollectorData(updatedData);
      setValidation(validateCollectorData(updatedData));
      
      toast.success(`Successfully imported ${validItems.length} items`);
    } catch (error) {
      console.error('Error importing item list:', error);
      toast.error('Error importing item list: ' + (error instanceof Error ? error.message : 'Unknown error'));
    }
  };

  // Import dialog component - with dark mode styling
  const ImportDialog = ({ 
    isOpen, 
    onClose, 
    category 
  }: { 
    isOpen: boolean, 
    onClose: () => void, 
    category: 'items' | 'premiumItems' | 'premiumStatusItems' 
  }) => {
    const { getRootProps, getInputProps, isDragActive, acceptedFiles } = useDropzone({
      accept: {
        'application/json': ['.json']
      },
      maxFiles: 1
    });
    
    const handleImport = async () => {
      if (acceptedFiles.length === 0) {
        toast.error('Please select a file to import');
        return;
      }
      
      await importItemList(acceptedFiles[0], category);
      onClose();
    };
    
    return (
      <Dialog open={isOpen} onOpenChange={onClose}>
        <DialogContent className="sm:max-w-[500px] bg-cyrus-dark-light border-cyrus-dark-lightest">
          <DialogHeader>
            <DialogTitle className="text-gray-200">Import Item List</DialogTitle>
            <DialogDescription className="text-gray-400">
              Import items from a JSON file for {category}
            </DialogDescription>
          </DialogHeader>
          
          <div 
            {...getRootProps()} 
            className={`p-8 border-2 border-dashed rounded-md cursor-pointer transition-colors ${
              isDragActive ? 'border-cyrus-blue bg-cyrus-blue/10' : 'border-gray-500'
            }`}
          >
            <input {...getInputProps()} />
            {acceptedFiles.length > 0 ? (
              <div className="text-center">
                <p className="font-medium text-gray-200">Selected file:</p>
                <p className="text-gray-400">{acceptedFiles[0].name}</p>
                <p className="text-gray-400 text-sm">
                  {(acceptedFiles[0].size / 1024).toFixed(2)} KB
                </p>
              </div>
            ) : (
              <div className="text-center">
                <Upload className="mx-auto h-10 w-10 text-gray-400 mb-2" />
                <p className="font-medium text-gray-200">Drop JSON file here, or click to select</p>
                <p className="text-gray-400 text-sm">
                  Only .json files are accepted
                </p>
              </div>
            )}
          </div>
          
          <DialogFooter className="mt-4">
            <Button 
              variant="outline" 
              onClick={onClose}
              className="text-gray-300 border-cyrus-dark-lightest"
            >
              Cancel
            </Button>
            <Button 
              onClick={handleImport} 
              disabled={acceptedFiles.length === 0}
              className="bg-cyrus-blue"
            >
              Import
            </Button>
          </DialogFooter>
        </DialogContent>
      </Dialog>
    );
  };
  
  // Batch import dialog component - with dark mode styling
  const BatchImportDialog = ({ 
    isOpen, 
    onClose, 
    category 
  }: { 
    isOpen: boolean, 
    onClose: () => void, 
    category: 'items' | 'premiumItems' | 'premiumStatusItems' 
  }) => {
    const [batchText, setBatchText] = useState("");
    const [errorMessage, setErrorMessage] = useState("");
    const [previewItems, setPreviewItems] = useState<CollectingItem[]>([]);
    
    // Format: II_ITEM_ID  1000
    const parseBatchInput = () => {
      setErrorMessage("");
      
      if (!batchText.trim()) {
        setErrorMessage("Please enter some data");
        return;
      }
      
      try {
        const lines = batchText.trim().split('\n');
        const items: CollectingItem[] = [];
        
        for (let i = 0; i < lines.length; i++) {
          const line = lines[i].trim();
          if (!line) continue;
          
          // Match an item ID pattern (II_) and a number with optional spaces in between
          const matches = line.match(/^(II_[A-Za-z0-9_]+)\s+(\d+)$/);
          
          if (!matches) {
            setErrorMessage(`Error in line ${i+1}: Invalid format. Expected format: "II_ITEM_ID 1000"`);
            return;
          }
          
          const itemId = matches[1];
          const probability = parseInt(matches[2], 10);
          
          items.push({ itemId, probability });
        }
        
        setPreviewItems(items);
        
      } catch (error) {
        console.error("Error parsing batch input:", error);
        setErrorMessage("Failed to parse input: " + (error instanceof Error ? error.message : "Unknown error"));
      }
    };
    
    const handleImport = () => {
      if (!collectorData || previewItems.length === 0) return;
      
      // Update data
      const updatedData = {
        ...collectorData,
        [category]: [...collectorData[category], ...previewItems],
        [`${category}Total`]: collectorData[category].reduce((sum, item) => sum + item.probability, 0) + 
                             previewItems.reduce((sum, item) => sum + item.probability, 0)
      };
      
      setCollectorData(updatedData);
      setValidation(validateCollectorData(updatedData));
      
      toast.success(`Successfully imported ${previewItems.length} items`);
      onClose();
      setBatchText("");
      setPreviewItems([]);
    };
    
    return (
      <Dialog open={isOpen} onOpenChange={onClose}>
        <DialogContent className="sm:max-w-[600px] bg-cyrus-dark-light border-cyrus-dark-lightest">
          <DialogHeader>
            <DialogTitle className="text-gray-200">Batch Import Items</DialogTitle>
            <DialogDescription className="text-gray-400">
              Import multiple items at once. Use format: "II_ITEM_ID 1000" (one per line)
            </DialogDescription>
          </DialogHeader>
          
          <div className="flex flex-col gap-4">
            <div>
              <Label htmlFor="batchInput" className="text-gray-300">Enter items (one per line)</Label>
              <textarea
                id="batchInput"
                value={batchText}
                onChange={(e) => setBatchText(e.target.value)}
                className="w-full h-40 mt-2 p-3 bg-cyrus-dark-lighter text-gray-300 text-sm font-mono rounded-md border border-cyrus-dark-lightest"
                placeholder="II_SYS_SYS_SCR_BXCOLL 10000&#10;II_GEN_GEM_ELE_WIND 5000&#10;II_ARM_M_CLO_SHIRT01_1 20000"
              />
              
              {errorMessage && (
                <p className="text-red-400 text-sm mt-1">{errorMessage}</p>
              )}
            </div>
            
            <Button 
              onClick={parseBatchInput}
              className="self-end bg-cyrus-blue"
            >
              Validate & Preview
            </Button>
            
            {previewItems.length > 0 && (
              <div>
                <h4 className="font-semibold mb-2 text-gray-200">Preview ({previewItems.length} items)</h4>
                <div className="border border-cyrus-dark-lightest rounded-md overflow-hidden">
                  <ScrollArea className="h-40">
                    <Table>
                      <TableHeader className="bg-cyrus-dark-lighter">
                        <TableRow>
                          <TableHead className="text-gray-300">Item ID</TableHead>
                          <TableHead className="text-gray-300">Probability</TableHead>
                        </TableRow>
                      </TableHeader>
                      <TableBody>
                        {previewItems.map((item, index) => (
                          <TableRow key={index} className="border-cyrus-dark-lightest">
                            <TableCell className="text-gray-300">{item.itemId}</TableCell>
                            <TableCell className="text-gray-300">{item.probability.toLocaleString()}</TableCell>
                          </TableRow>
                        ))}
                      </TableBody>
                    </Table>
                  </ScrollArea>
                </div>
                
                <div className="mt-2 text-sm text-gray-400">
                  Total: {previewItems.reduce((sum, item) => sum + item.probability, 0).toLocaleString()}
                </div>
              </div>
            )}
          </div>
          
          <DialogFooter className="mt-4">
            <Button 
              variant="outline" 
              onClick={onClose}
              className="text-gray-300 border-cyrus-dark-lightest"
            >
              Cancel
            </Button>
            <Button 
              onClick={handleImport} 
              disabled={previewItems.length === 0}
              className="bg-cyrus-blue"
            >
              Import {previewItems.length} Items
            </Button>
          </DialogFooter>
        </DialogContent>
      </Dialog>
    );
  };
  
  // ProbabilityChart mit angepassten Farben
  const ProbabilityChart = ({ 
    category,
    maxItems = 10
  }: { 
    category: 'items' | 'premiumItems' | 'premiumStatusItems',
    maxItems?: number 
  }) => {
    if (!collectorData || collectorData[category].length === 0) {
      return <div className="text-gray-400 p-4 text-center">No items available to display</div>;
    }
    
    // Sortiere die Items nach Wahrscheinlichkeit (absteigend)
    const sortedItems = [...collectorData[category]]
      .sort((a, b) => b.probability - a.probability)
      .slice(0, maxItems);
    
    // Der höchste Wert für die Skalierung
    const maxProbability = sortedItems[0].probability;
    
    // Für die Prozentwerte
    const total = collectorData[`${category}Total`];
    
    return (
      <div className="p-4 bg-cyrus-dark-light rounded-md">
        <h3 className="font-semibold mb-2 text-gray-200">Top {maxItems} Items by Probability</h3>
        
        <div className="space-y-3">
          {sortedItems.map((item, index) => {
            const percentage = (item.probability / total) * 100;
            const barWidth = `${(item.probability / maxProbability) * 100}%`;
            
            return (
              <div key={index} className="relative">
                <div className="flex items-center mb-1">
                  <span className="text-sm font-mono truncate max-w-xs text-gray-300" title={item.itemId}>
                    {item.itemId}
                  </span>
                  <span className="ml-auto text-sm font-medium text-gray-300">
                    {percentage.toFixed(2)}%
                  </span>
                </div>
                <div className="h-2 w-full bg-cyrus-dark-lighter rounded-full overflow-hidden">
                  <div 
                    className="h-full bg-cyrus-blue rounded-full" 
                    style={{ width: barWidth }}
                  />
                </div>
              </div>
            );
          })}
        </div>
      </div>
    );
  };
  
  // Item search bar component with dark mode styling
  const ItemSearchBar = ({ category }: { category: 'items' | 'premiumItems' | 'premiumStatusItems' }) => {
    return (
      <div className="flex flex-wrap gap-2 items-center mb-4">
        <div className="flex-1 flex gap-2 items-center">
          <div className="relative flex-1">
            <Search className="absolute left-2 top-2.5 h-4 w-4 text-gray-400" />
            <Input
              placeholder="Search items..."
              value={searchQuery}
              onChange={(e) => setSearchQuery(e.target.value)}
              className="pl-8 bg-cyrus-dark-lighter text-gray-300 border-cyrus-dark-lightest"
            />
            {searchQuery && (
              <Button 
                variant="ghost" 
                size="icon" 
                className="absolute right-1 top-1 text-gray-400 hover:text-gray-300"
                onClick={() => setSearchQuery("")}
              >
                <X className="h-4 w-4" />
              </Button>
            )}
          </div>
          <DropdownMenu>
            <DropdownMenuTrigger asChild>
              <Button variant="filter" className="gap-1 text-white">
                <Filter className="h-4 w-4" />
                Filter
                <ChevronDown className="h-3 w-3" />
              </Button>
            </DropdownMenuTrigger>
            <DropdownMenuContent align="end" className="bg-cyrus-dark-lighter border-cyrus-dark-lightest">
              <DropdownMenuItem onClick={() => setSearchQuery("II_SYS")} className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200">
                System Items
              </DropdownMenuItem>
              <DropdownMenuItem onClick={() => setSearchQuery("II_GEN_GEM")} className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200">
                Gem Items
              </DropdownMenuItem>
              <DropdownMenuItem onClick={() => setSearchQuery("II_ARM")} className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200">
                Armor Items
              </DropdownMenuItem>
              <DropdownMenuItem onClick={() => setSearchQuery("II_WEA")} className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200">
                Weapon Items
              </DropdownMenuItem>
            </DropdownMenuContent>
          </DropdownMenu>
        </div>
        
        <div className="flex gap-2">
          <Button 
            variant="add" 
            size="sm"
            onClick={() => {
              setSelectedCategory(category);
              setShowAddItemDialog(true);
            }}
            className="flex items-center text-white"
          >
            <Plus className="mr-1 h-4 w-4" />
            Add
          </Button>
          
          <DropdownMenu>
            <DropdownMenuTrigger asChild>
              <Button variant="import" size="sm" className="flex items-center text-white">
                <Download className="mr-1 h-4 w-4" />
                Import/Export
                <ChevronDown className="ml-1 h-3 w-3" />
              </Button>
            </DropdownMenuTrigger>
            <DropdownMenuContent align="end" className="bg-cyrus-dark-lighter border-cyrus-dark-lightest">
              <DropdownMenuItem 
                onClick={() => exportItemList(category)}
                className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
              >
                <Download className="mr-2 h-4 w-4" />
                Export Items
              </DropdownMenuItem>
              <DropdownMenuItem 
                onClick={() => {
                  setSelectedCategory(category);
                  setShowImportDialog(true);
                }}
                className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
              >
                <Upload className="mr-2 h-4 w-4" />
                Import Items
              </DropdownMenuItem>
              <DropdownMenuItem 
                onClick={() => {
                  setSelectedCategory(category);
                  setShowBatchImportDialog(true);
                }}
                className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
              >
                <Upload className="mr-2 h-4 w-4" />
                Batch Import
              </DropdownMenuItem>
            </DropdownMenuContent>
          </DropdownMenu>
          
          {selectedItems.length > 0 && (
            <>
              <Button 
                variant="destructive" 
                size="sm"
                onClick={() => handleRemoveSelectedItems(category)}
                className="flex items-center"
              >
                <Trash className="mr-1 h-4 w-4" />
                Delete ({selectedItems.length})
              </Button>
              
              <DropdownMenu>
                <DropdownMenuTrigger asChild>
                  <Button variant="outline" size="sm" className="flex items-center text-gray-300 border-cyrus-dark-lightest">
                    <Edit className="mr-1 h-4 w-4" />
                    Adjust
                    <ChevronDown className="ml-1 h-3 w-3" />
                  </Button>
                </DropdownMenuTrigger>
                <DropdownMenuContent align="end" className="bg-cyrus-dark-lighter border-cyrus-dark-lightest">
                  <DropdownMenuItem onClick={() => adjustProbabilities(category, 'equal')} className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200">
                    Equal Distribution
                  </DropdownMenuItem>
                  <DropdownMenuItem onClick={() => adjustProbabilities(category, 'proportional')} className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200">
                    Proportional Distribution
                  </DropdownMenuItem>
                  <DropdownMenuItem onClick={() => adjustProbabilities(category, 'reset')} className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200">
                    Reset to Zero
                  </DropdownMenuItem>
                </DropdownMenuContent>
              </DropdownMenu>
            </>
          )}
        </div>
        
        {selectedItems.length > 0 && (
          <div className="w-full mt-2">
            <Badge className="bg-cyrus-blue">
              {selectedItems.length} items selected
              <Button 
                variant="ghost" 
                size="icon" 
                className="h-4 w-4 ml-1" 
                onClick={() => setSelectedItems([])}
              >
                <X className="h-3 w-3" />
              </Button>
            </Badge>
          </div>
        )}
      </div>
    );
  };
  
  // Add SortableTableRow component back
  const SortableTableRow = ({ 
    children, 
    id 
  }: { 
    children: React.ReactNode, 
    id: string 
  }) => {
    const {
      attributes,
      listeners,
      setNodeRef,
      transform,
      transition,
      isDragging
    } = useSortable({ id });

    const style = {
      transform: CSS.Transform.toString(transform),
      transition,
      opacity: isDragging ? 0.5 : 1,
      zIndex: isDragging ? 999 : 1,
    };

    return (
      <TableRow 
        ref={setNodeRef} 
        style={style} 
        className={`border-cyrus-dark-lightest ${isDragging ? 'bg-cyrus-blue/20' : ''}`}
        {...attributes}
        {...listeners}
      >
        {children}
      </TableRow>
    );
  };
  
  // Erstelle eine memoized Version von renderItemTable
  const renderItemTableMemo = useMemo(() => {
    const renderTable = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
      const items = filteredItemsMemo[category];
      
      // Handler for the end of a drag operation
      const handleDragEnd = (event: DragEndEvent) => {
        const { active, over } = event;
        
        if (!over || active.id === over.id) return;
        
        if (collectorData) {
          const oldIndex = collectorData[category].findIndex(item => item.itemId === active.id);
          const newIndex = collectorData[category].findIndex(item => item.itemId === over.id);
          
          const updatedItems = arrayMove([...collectorData[category]], oldIndex, newIndex);
          
          const updatedData = {
            ...collectorData,
            [category]: updatedItems
          };
          
          setCollectorData(updatedData);
        }
      };
      
      // Split items into two columns
      const halfLength = Math.ceil(items.length / 2);
      const leftItems = items.slice(0, halfLength);
      const rightItems = items.slice(halfLength);
      
      const renderItemColumn = (itemsToRender: typeof items) => {
        return (
          <div className="overflow-x-auto">
            <Table>
              <TableHeader className="bg-cyrus-dark-lighter">
                <TableRow>
                  <TableHead className="w-10 sticky top-0 bg-cyrus-dark-lighter z-10">
                    <Checkbox 
                      checked={
                        itemsToRender.length > 0 && 
                        itemsToRender.every(item => selectedItems.includes(item.itemId))
                      }
                      onCheckedChange={(checked) => {
                        if (checked) {
                          setSelectedItems([
                            ...selectedItems,
                            ...itemsToRender
                              .filter(item => !selectedItems.includes(item.itemId))
                              .map(item => item.itemId)
                          ]);
                        } else {
                          setSelectedItems(
                            selectedItems.filter(id => 
                              !itemsToRender.find(item => item.itemId === id)
                            )
                          );
                        }
                      }}
                    />
                  </TableHead>
                  <TableHead className="w-8 sticky top-0 bg-cyrus-dark-lighter z-10"></TableHead>
                  <TableHead className="text-gray-300 sticky top-0 bg-cyrus-dark-lighter z-10">Item ID</TableHead>
                  <TableHead className="text-gray-300 w-28 sticky top-0 bg-cyrus-dark-lighter z-10">Probability</TableHead>
                  <TableHead className="text-gray-300 w-24 sticky top-0 bg-cyrus-dark-lighter z-10">%</TableHead>
                  <TableHead className="text-gray-300 w-24 sticky top-0 bg-cyrus-dark-lighter z-10">Actions</TableHead>
                </TableRow>
              </TableHeader>
              <TableBody>
                {itemsToRender.map((item, index) => {
                  const originalIndex = collectorData ? collectorData[category].findIndex(i => i.itemId === item.itemId) : -1;
                  
                  return (
                    <TableRow key={item.itemId} className="border-cyrus-dark-lightest">
                      <TableCell>
                        <Checkbox 
                          checked={selectedItems.includes(item.itemId)}
                          onCheckedChange={(checked) => {
                            if (checked) {
                              setSelectedItems([...selectedItems, item.itemId]);
                            } else {
                              setSelectedItems(selectedItems.filter(id => id !== item.itemId));
                            }
                          }}
                        />
                      </TableCell>
                      <TableCell className="px-2">
                        <div className="flex flex-col h-4 justify-between">
                          <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                          <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                          <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                        </div>
                      </TableCell>
                      <TableCell className="text-gray-300">
                        <FormField
                          id={`${category}-id-${originalIndex}`}
                          label=""
                          type="text"
                          value={item.itemId}
                          onChange={(value) => handleItemChange(originalIndex, 'itemId', value, category)}
                          className="bg-cyrus-dark-lighter text-gray-300"
                          readOnly={!editMode}
                        />
                      </TableCell>
                      <TableCell className="text-gray-300">
                        <FormField
                          id={`${category}-prob-${originalIndex}`}
                          label=""
                          type="number"
                          value={item.probability}
                          onChange={(value) => handleItemChange(originalIndex, 'probability', parseInt(value, 10) || 0, category)}
                          min={0}
                          className="bg-cyrus-dark-lighter text-gray-300 [&>input]:dark-mode-number-input"
                          error={item.probability < 0 ? "Value must be positive" : undefined}
                          readOnly={!editMode}
                        />
                      </TableCell>
                      <TableCell 
                        className={
                          collectorData && 
                          collectorData[`${category}Total`] === 1000000 ? 
                          'text-green-400' : 'text-red-400'
                        }
                      >
                        {calculatePercentage(item.probability).toFixed(2)}%
                      </TableCell>
                      <TableCell>
                        <div className="flex gap-1">
                          {editMode && (
                            <Button 
                              variant="destructive" 
                              size="icon"
                              onClick={() => handleRemoveItem(originalIndex, category)}
                            >
                              <Trash className="h-4 w-4" />
                            </Button>
                          )}
                          <DropdownMenu>
                            <DropdownMenuTrigger asChild>
                              <Button 
                                variant="outline" 
                                size="icon" 
                                className="border-cyrus-dark-lightest"
                                disabled={!editMode}
                              >
                                <MoreHorizontal className="h-4 w-4" />
                              </Button>
                            </DropdownMenuTrigger>
                            <DropdownMenuContent align="end" className="bg-cyrus-dark-lighter border-cyrus-dark-lightest">
                              <DropdownMenuItem 
                                onClick={() => {
                                  if (!editMode) return;
                                  
                                  const updatedItems = [...collectorData![category]];
                                  updatedItems[originalIndex] = { ...updatedItems[originalIndex], probability: 1000000 };
                                  
                                  // Set all other items to 0
                                  updatedItems.forEach((item, i) => {
                                    if (i !== originalIndex) {
                                      updatedItems[i] = { ...updatedItems[i], probability: 0 };
                                    }
                                  });
                                  
                                  const updatedData = {
                                    ...collectorData!,
                                    [category]: updatedItems,
                                    [`${category}Total`]: 1000000
                                  };
                                  
                                  setCollectorData(updatedData);
                                  setValidation(validateCollectorData(updatedData));
                                }}
                                className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                                disabled={!editMode}
                              >
                                Set to 100%
                              </DropdownMenuItem>
                              <DropdownMenuItem 
                                onClick={() => handleDuplicateItem(originalIndex, category)}
                                className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                                disabled={!editMode}
                              >
                                <Copy className="mr-2 h-4 w-4" />
                                Duplicate Item
                              </DropdownMenuItem>
                              <DropdownMenuItem 
                                onClick={() => {
                                  navigator.clipboard.writeText(item.itemId);
                                  toast.success("Item ID copied to clipboard");
                                }}
                                className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                              >
                                <Copy className="mr-2 h-4 w-4" />
                                Copy ID
                              </DropdownMenuItem>
                            </DropdownMenuContent>
                          </DropdownMenu>
                        </div>
                      </TableCell>
                    </TableRow>
                  );
                })}
              </TableBody>
            </Table>
          </div>
        );
      };
      
      // If collectorData or hasDragAndDrop is false, show the table without DnD
      if (!collectorData || !hasDragAndDrop) {
        return (
          <>
            <ItemSearchBar category={category} />
            <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
              {leftItems.length > 0 && (
                <div>{renderItemColumn(leftItems)}</div>
              )}
              {rightItems.length > 0 && (
                <div>{renderItemColumn(rightItems)}</div>
              )}
            </div>
          </>
        );
      }
      
      // With DnD, if collectorData and sensors are available
      return (
        <>
          <ItemSearchBar category={category} />
          <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
            {leftItems.length > 0 && (
              <div>
                <DndContext 
                  sensors={sensors}
                  collisionDetection={closestCenter}
                  onDragEnd={handleDragEnd}
                >
                  <Table>
                    <TableHeader className="bg-cyrus-dark-lighter">
                      <TableRow>
                        <TableHead className="w-10 sticky top-0 bg-cyrus-dark-lighter z-10">
                          <Checkbox 
                            checked={
                              leftItems.length > 0 && 
                              leftItems.every(item => selectedItems.includes(item.itemId))
                            }
                            onCheckedChange={(checked) => {
                              if (checked) {
                                setSelectedItems([
                                  ...selectedItems,
                                  ...leftItems
                                    .filter(item => !selectedItems.includes(item.itemId))
                                    .map(item => item.itemId)
                                ]);
                              } else {
                                setSelectedItems(
                                  selectedItems.filter(id => 
                                    !leftItems.find(item => item.itemId === id)
                                  )
                                );
                              }
                            }}
                          />
                        </TableHead>
                        <TableHead className="w-8 sticky top-0 bg-cyrus-dark-lighter z-10"></TableHead>
                        <TableHead className="text-gray-300 sticky top-0 bg-cyrus-dark-lighter z-10">Item ID</TableHead>
                        <TableHead className="text-gray-300 w-28 sticky top-0 bg-cyrus-dark-lighter z-10">Probability</TableHead>
                        <TableHead className="text-gray-300 w-24 sticky top-0 bg-cyrus-dark-lighter z-10">%</TableHead>
                        <TableHead className="text-gray-300 w-24 sticky top-0 bg-cyrus-dark-lighter z-10">Actions</TableHead>
                      </TableRow>
                    </TableHeader>
                    <TableBody>
                      <SortableContext 
                        items={leftItems.map(item => item.itemId)} 
                        strategy={verticalListSortingStrategy}
                      >
                        {leftItems.map((item) => {
                          const originalIndex = collectorData ? collectorData[category].findIndex(i => i.itemId === item.itemId) : -1;
                          
                          return (
                            <SortableTableRow key={item.itemId} id={item.itemId}>
                              <TableCell>
                                <Checkbox 
                                  checked={selectedItems.includes(item.itemId)}
                                  onCheckedChange={(checked) => {
                                    if (checked) {
                                      setSelectedItems([...selectedItems, item.itemId]);
                                    } else {
                                      setSelectedItems(selectedItems.filter(id => id !== item.itemId));
                                    }
                                  }}
                                />
                              </TableCell>
                              <TableCell className="cursor-grab px-2">
                                <div className="flex flex-col h-4 justify-between">
                                  <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                                  <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                                  <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                                </div>
                              </TableCell>
                              <TableCell className="text-gray-300">
                                <FormField
                                  id={`${category}-id-${originalIndex}`}
                                  label=""
                                  type="text"
                                  value={item.itemId}
                                  onChange={(value) => handleItemChange(originalIndex, 'itemId', value, category)}
                                  className="bg-cyrus-dark-lighter text-gray-300"
                                  readOnly={!editMode}
                                />
                              </TableCell>
                              <TableCell className="text-gray-300">
                                <FormField
                                  id={`${category}-prob-${originalIndex}`}
                                  label=""
                                  type="number"
                                  value={item.probability}
                                  onChange={(value) => handleItemChange(originalIndex, 'probability', parseInt(value, 10) || 0, category)}
                                  min={0}
                                  className="bg-cyrus-dark-lighter text-gray-300 [&>input]:dark-mode-number-input"
                                  error={item.probability < 0 ? "Value must be positive" : undefined}
                                  readOnly={!editMode}
                                />
                              </TableCell>
                              <TableCell 
                                className={
                                  collectorData && 
                                  collectorData[`${category}Total`] === 1000000 ? 
                                  'text-green-400' : 'text-red-400'
                                }
                              >
                                {calculatePercentage(item.probability).toFixed(2)}%
                              </TableCell>
                              <TableCell>
                                <div className="flex gap-1">
                                  {editMode && (
                                    <Button 
                                      variant="destructive" 
                                      size="icon"
                                      onClick={() => handleRemoveItem(originalIndex, category)}
                                    >
                                      <Trash className="h-4 w-4" />
                                    </Button>
                                  )}
                                  <DropdownMenu>
                                    <DropdownMenuTrigger asChild>
                                      <Button 
                                        variant="outline" 
                                        size="icon" 
                                        className="border-cyrus-dark-lightest"
                                        disabled={!editMode}
                                      >
                                        <MoreHorizontal className="h-4 w-4" />
                                      </Button>
                                    </DropdownMenuTrigger>
                                    <DropdownMenuContent align="end" className="bg-cyrus-dark-lighter border-cyrus-dark-lightest">
                                      <DropdownMenuItem 
                                        onClick={() => {
                                          if (!editMode) return;
                                          
                                          const updatedItems = [...collectorData![category]];
                                          updatedItems[originalIndex] = { ...updatedItems[originalIndex], probability: 1000000 };
                                          
                                          // Set all other items to 0
                                          updatedItems.forEach((item, i) => {
                                            if (i !== originalIndex) {
                                              updatedItems[i] = { ...updatedItems[i], probability: 0 };
                                            }
                                          });
                                          
                                          const updatedData = {
                                            ...collectorData!,
                                            [category]: updatedItems,
                                            [`${category}Total`]: 1000000
                                          };
                                          
                                          setCollectorData(updatedData);
                                          setValidation(validateCollectorData(updatedData));
                                        }}
                                        className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                                        disabled={!editMode}
                                      >
                                        Set to 100%
                                      </DropdownMenuItem>
                                      <DropdownMenuItem 
                                        onClick={() => handleDuplicateItem(originalIndex, category)}
                                        className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                                        disabled={!editMode}
                                      >
                                        <Copy className="mr-2 h-4 w-4" />
                                        Duplicate Item
                                      </DropdownMenuItem>
                                      <DropdownMenuItem 
                                        onClick={() => {
                                          navigator.clipboard.writeText(item.itemId);
                                          toast.success("Item ID copied to clipboard");
                                        }}
                                        className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                                      >
                                        <Copy className="mr-2 h-4 w-4" />
                                        Copy ID
                                      </DropdownMenuItem>
                                    </DropdownMenuContent>
                                  </DropdownMenu>
                                </div>
                              </TableCell>
                            </SortableTableRow>
                          );
                        })}
                      </SortableContext>
                    </TableBody>
                  </Table>
                </DndContext>
              </div>
            )}
            
            {rightItems.length > 0 && (
              <div>
                <DndContext 
                  sensors={sensors}
                  collisionDetection={closestCenter}
                  onDragEnd={handleDragEnd}
                >
                  <Table>
                    <TableHeader className="bg-cyrus-dark-lighter">
                      <TableRow>
                        <TableHead className="w-10 sticky top-0 bg-cyrus-dark-lighter z-10">
                          <Checkbox 
                            checked={
                              rightItems.length > 0 && 
                              rightItems.every(item => selectedItems.includes(item.itemId))
                            }
                            onCheckedChange={(checked) => {
                              if (checked) {
                                setSelectedItems([
                                  ...selectedItems,
                                  ...rightItems
                                    .filter(item => !selectedItems.includes(item.itemId))
                                    .map(item => item.itemId)
                                ]);
                              } else {
                                setSelectedItems(
                                  selectedItems.filter(id => 
                                    !rightItems.find(item => item.itemId === id)
                                  )
                                );
                              }
                            }}
                          />
                        </TableHead>
                        <TableHead className="w-8 sticky top-0 bg-cyrus-dark-lighter z-10"></TableHead>
                        <TableHead className="text-gray-300 sticky top-0 bg-cyrus-dark-lighter z-10">Item ID</TableHead>
                        <TableHead className="text-gray-300 w-28 sticky top-0 bg-cyrus-dark-lighter z-10">Probability</TableHead>
                        <TableHead className="text-gray-300 w-24 sticky top-0 bg-cyrus-dark-lighter z-10">%</TableHead>
                        <TableHead className="text-gray-300 w-24 sticky top-0 bg-cyrus-dark-lighter z-10">Actions</TableHead>
                      </TableRow>
                    </TableHeader>
                    <TableBody>
                      <SortableContext 
                        items={rightItems.map(item => item.itemId)} 
                        strategy={verticalListSortingStrategy}
                      >
                        {rightItems.map((item) => {
                          const originalIndex = collectorData ? collectorData[category].findIndex(i => i.itemId === item.itemId) : -1;
                          
                          return (
                            <SortableTableRow key={item.itemId} id={item.itemId}>
                              <TableCell>
                                <Checkbox 
                                  checked={selectedItems.includes(item.itemId)}
                                  onCheckedChange={(checked) => {
                                    if (checked) {
                                      setSelectedItems([...selectedItems, item.itemId]);
                                    } else {
                                      setSelectedItems(selectedItems.filter(id => id !== item.itemId));
                                    }
                                  }}
                                />
                              </TableCell>
                              <TableCell className="cursor-grab px-2">
                                <div className="flex flex-col h-4 justify-between">
                                  <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                                  <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                                  <div className="h-0.5 w-4 bg-gray-400 rounded"></div>
                                </div>
                              </TableCell>
                              <TableCell className="text-gray-300">
                                <FormField
                                  id={`${category}-id-${originalIndex}`}
                                  label=""
                                  type="text"
                                  value={item.itemId}
                                  onChange={(value) => handleItemChange(originalIndex, 'itemId', value, category)}
                                  className="bg-cyrus-dark-lighter text-gray-300"
                                  readOnly={!editMode}
                                />
                              </TableCell>
                              <TableCell className="text-gray-300">
                                <FormField
                                  id={`${category}-prob-${originalIndex}`}
                                  label=""
                                  type="number"
                                  value={item.probability}
                                  onChange={(value) => handleItemChange(originalIndex, 'probability', parseInt(value, 10) || 0, category)}
                                  min={0}
                                  className="bg-cyrus-dark-lighter text-gray-300 [&>input]:dark-mode-number-input"
                                  error={item.probability < 0 ? "Value must be positive" : undefined}
                                  readOnly={!editMode}
                                />
                              </TableCell>
                              <TableCell 
                                className={
                                  collectorData && 
                                  collectorData[`${category}Total`] === 1000000 ? 
                                  'text-green-400' : 'text-red-400'
                                }
                              >
                                {calculatePercentage(item.probability).toFixed(2)}%
                              </TableCell>
                              <TableCell>
                                <div className="flex gap-1">
                                  {editMode && (
                                    <Button 
                                      variant="destructive" 
                                      size="icon"
                                      onClick={() => handleRemoveItem(originalIndex, category)}
                                    >
                                      <Trash className="h-4 w-4" />
                                    </Button>
                                  )}
                                  <DropdownMenu>
                                    <DropdownMenuTrigger asChild>
                                      <Button 
                                        variant="outline" 
                                        size="icon" 
                                        className="border-cyrus-dark-lightest"
                                        disabled={!editMode}
                                      >
                                        <MoreHorizontal className="h-4 w-4" />
                                      </Button>
                                    </DropdownMenuTrigger>
                                    <DropdownMenuContent align="end" className="bg-cyrus-dark-lighter border-cyrus-dark-lightest">
                                      <DropdownMenuItem 
                                        onClick={() => {
                                          if (!editMode) return;
                                          
                                          const updatedItems = [...collectorData![category]];
                                          updatedItems[originalIndex] = { ...updatedItems[originalIndex], probability: 1000000 };
                                          
                                          // Set all other items to 0
                                          updatedItems.forEach((item, i) => {
                                            if (i !== originalIndex) {
                                              updatedItems[i] = { ...updatedItems[i], probability: 0 };
                                            }
                                          });
                                          
                                          const updatedData = {
                                            ...collectorData!,
                                            [category]: updatedItems,
                                            [`${category}Total`]: 1000000
                                          };
                                          
                                          setCollectorData(updatedData);
                                          setValidation(validateCollectorData(updatedData));
                                        }}
                                        className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                                        disabled={!editMode}
                                      >
                                        Set to 100%
                                      </DropdownMenuItem>
                                      <DropdownMenuItem 
                                        onClick={() => handleDuplicateItem(originalIndex, category)}
                                        className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                                        disabled={!editMode}
                                      >
                                        <Copy className="mr-2 h-4 w-4" />
                                        Duplicate Item
                                      </DropdownMenuItem>
                                      <DropdownMenuItem 
                                        onClick={() => {
                                          navigator.clipboard.writeText(item.itemId);
                                          toast.success("Item ID copied to clipboard");
                                        }}
                                        className="text-gray-300 focus:bg-cyrus-dark focus:text-gray-200"
                                      >
                                        <Copy className="mr-2 h-4 w-4" />
                                        Copy ID
                                      </DropdownMenuItem>
                                    </DropdownMenuContent>
                                  </DropdownMenu>
                                </div>
                              </TableCell>
                            </SortableTableRow>
                          );
                        })}
                      </SortableContext>
                    </TableBody>
                  </Table>
                </DndContext>
              </div>
            )}
          </div>
        </>
      );
    };
    
    return {
      items: () => renderTable('items'),
      premiumItems: () => renderTable('premiumItems'),
      premiumStatusItems: () => renderTable('premiumStatusItems')
    };
  }, [collectorData, selectedItems, filteredItemsMemo, hasDragAndDrop, sensors]);

  // Function to filter items based on the search
  const filteredItems = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    return filteredItemsMemo[category];
  };
  
  // Updated renderItemTable function that uses the memoized version
  const renderItemTable = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    return renderItemTableMemo[category]();
  };
  
  // Render the save button with conditional rendering based on editMode
  const renderSaveButton = () => {
    if (!editMode) return null; // Don't show save button in view mode
    
    return (
      <Button 
        onClick={handleSave} 
        className="bg-cyrus-blue hover:bg-cyrus-blue/90 text-white flex gap-1"
        disabled={!collectorData}
      >
        <Save className="h-4 w-4" />
        Save Changes
      </Button>
    );
  };
  
  if (!collectorData) {
    return <div className="flex justify-center items-center p-12 text-gray-300">Loading collector data...</div>;
  }
  
  return (
    <div className="collector-tab w-full h-full overflow-auto bg-cyrus-dark">
      <div className="sticky top-0 z-20 bg-cyrus-dark p-4 pb-0 border-b border-cyrus-dark-lightest mb-4">
        <div className="flex justify-between mb-4">
          <h2 className="text-2xl font-bold text-cyrus-gold">Collector Configuration</h2>
          <div className="flex gap-2">
            {renderSaveButton()}
          </div>
        </div>
        
        {/* Display validation warnings */}
        {validation && !validation.isValid && (
          <Card className="mb-4 border-destructive bg-destructive/10">
            <CardHeader className="pb-2">
              <CardTitle className="flex items-center text-destructive">
                <AlertTriangle className="mr-2 h-5 w-5" />
                Errors in Collector Data
              </CardTitle>
            </CardHeader>
            <CardContent className="pt-4">
              <ul className="list-disc pl-5">
                {validation.errors.map((error, index) => (
                  <li key={index} className="text-destructive">{error}</li>
                ))}
              </ul>
            </CardContent>
          </Card>
        )}
      </div>
      
      <Tabs value={activeTab} onValueChange={setActiveTab} className="w-full">
        <div className="px-4 mb-4 sticky top-[72px] z-10 bg-cyrus-dark">
          <TabsList className="w-full justify-start bg-cyrus-dark-lighter">
            <TabsTrigger 
              value="enchant" 
              className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white text-gray-300"
            >
              Enchantment {!validation?.enchantValid && <AlertTriangle className="ml-2 h-4 w-4 text-destructive" />}
            </TabsTrigger>
            <TabsTrigger 
              value="items" 
              className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white text-gray-300"
            >
              Items {!validation?.itemsValid && <AlertTriangle className="ml-2 h-4 w-4 text-destructive" />}
            </TabsTrigger>
            <TabsTrigger 
              value="premiumItems" 
              className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white text-gray-300"
            >
              Premium Items {!validation?.premiumItemsValid && <AlertTriangle className="ml-2 h-4 w-4 text-destructive" />}
            </TabsTrigger>
            <TabsTrigger 
              value="premiumStatusItems" 
              className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white text-gray-300"
            >
              Premium Status Items {!validation?.premiumStatusItemsValid && <AlertTriangle className="ml-2 h-4 w-4 text-destructive" />}
            </TabsTrigger>
          </TabsList>
        </div>
        
        <div className="px-4 pb-4">
          {/* Enchant Tab */}
          <TabsContent value="enchant" className="mt-0">
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest sticky top-[121px] z-10">
                <div className="flex justify-between items-center">
                  <CardTitle className="text-gray-200">Enchantment Probabilities</CardTitle>
                  <Button 
                    variant="outline" 
                    size="sm" 
                    onClick={() => distributeEnchantEvenly()}
                    className="text-xs text-gray-300 border-cyrus-dark-lightest bg-cyrus-dark hover:bg-cyrus-dark-light"
                  >
                    Distribute Evenly
                  </Button>
                </div>
                <CardDescription className="text-gray-400">
                  Configure the probabilities for each enchantment level. Total should be 1000.
                  Current: {collectorData.enchantTotal.toLocaleString()}/1000
                  {collectorData.enchantTotal !== 1000 && (
                    <span className="text-destructive"> (Invalid)</span>
                  )}
                </CardDescription>
              </CardHeader>

              <CardContent className="p-0">
                <div className="p-4">
                  <Button onClick={handleAddEnchant} className="flex items-center bg-cyrus-blue hover:bg-cyrus-blue/90">
                    <Plus className="mr-2 h-4 w-4" />
                    Add Enchantment
                  </Button>
                </div>
                <div>
                  <Table>
                    <TableHeader>
                      <TableRow className="bg-cyrus-dark-lighter">
                        <TableHead className="w-[80px] sticky top-0 bg-cyrus-dark-lighter z-10 text-gray-300">Level</TableHead>
                        <TableHead className="w-[120px] sticky top-0 bg-cyrus-dark-lighter z-10 text-gray-300">Probability</TableHead>
                        <TableHead className="w-[80px] sticky top-0 bg-cyrus-dark-lighter z-10 text-gray-300">Actions</TableHead>
                      </TableRow>
                    </TableHeader>
                    <TableBody>
                      {collectorData.enchant.map((enchant, index) => (
                        <TableRow key={index} className="border-cyrus-dark-lightest">
                          <TableCell className="text-gray-300">
                            <FormField
                              id={`enchant-level-${index}`}
                              label=""
                              type="number"
                              value={enchant.level}
                              onChange={(value) => handleEnchantLevelChange(index, parseInt(value, 10) || 0)}
                              className="w-20 bg-cyrus-dark-lighter text-gray-300 [&>input]:dark-mode-number-input"
                              min={0}
                              error={undefined}
                            />
                          </TableCell>
                          <TableCell className="text-gray-300">
                            <div className="flex items-center space-x-2 w-full">
                              <FormField
                                id={`enchant-${index}`}
                                label=""
                                type="number"
                                value={enchant.chance}
                                onChange={(value) => handleEnchantChange(index, parseInt(value, 10) || 0)}
                                className="w-24 bg-cyrus-dark-lighter text-gray-300"
                                min={0}
                                max={1000}
                                error={enchant.chance < 0 ? "Value must be positive" : undefined}
                                readOnly={!editMode}
                              />
                              <div className="flex-1 flex items-center gap-2 py-2 px-3 bg-cyrus-dark-light rounded-md">
                                <input
                                  type="range"
                                  min="0"
                                  max="1000"
                                  value={enchant.chance}
                                  onChange={(e) => handleEnchantChange(index, parseInt(e.target.value, 10) || 0)}
                                  disabled={!editMode}
                                  className="w-full h-2 bg-cyrus-dark-lighter rounded-lg appearance-none cursor-pointer"
                                  style={{
                                    backgroundImage: `linear-gradient(to right, #007BFF ${enchant.chance/10}%, #2D2D30 ${enchant.chance/10}%)`
                                  }}
                                />
                                <div className="bg-cyrus-dark-lighter rounded-md px-2 py-1 min-w-[60px] text-center text-gray-300">
                                  {enchant.chance}/1000
                                </div>
                              </div>
                            </div>
                          </TableCell>
                          <TableCell>
                            <Button 
                              variant="destructive" 
                              size="icon"
                              onClick={() => handleRemoveEnchant(index)}
                            >
                              <Trash className="h-4 w-4" />
                            </Button>
                          </TableCell>
                        </TableRow>
                      ))}
                    </TableBody>
                  </Table>
                </div>
              </CardContent>
            </Card>
          </TabsContent>
          
          {/* Items Tab - Two Column Layout */}
          <TabsContent value="items" className="mt-0">
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest mb-4">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest sticky top-[121px] z-10">
                <div className="flex justify-between items-center">
                  <CardTitle className="text-gray-200">Collector Items</CardTitle>
                  <Button 
                    variant="outline" 
                    size="sm" 
                    onClick={() => distributeEvenly('items')}
                    className="text-xs text-gray-300 border-cyrus-dark-lightest bg-cyrus-dark hover:bg-cyrus-dark-light"
                  >
                    Distribute Evenly
                  </Button>
                </div>
                <CardDescription className="text-gray-400">
                  Configure the probabilities for collector items. Total should be 1,000,000 (100%).
                  Current: {collectorData.itemsTotal.toLocaleString()}/1,000,000 
                  ({(collectorData.itemsTotal / 1000000 * 100).toFixed(2)}%)
                  {collectorData.itemsTotal !== 1000000 && (
                    <span className="text-destructive"> (Invalid)</span>
                  )}
                </CardDescription>
              </CardHeader>
              <CardContent className="pt-6">
                <div className="mb-4">
                  <Button variant="add" onClick={() => handleAddItem('items')} className="flex items-center text-white">
                    <Plus className="mr-2 h-4 w-4" />
                    Add Item
                  </Button>
                </div>
                <div>
                  {renderItemTable('items')}
                </div>
              </CardContent>
            </Card>
            
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest mb-4">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest">
                <CardTitle className="text-gray-200">Probability Distribution</CardTitle>
              </CardHeader>
              <CardContent className="pt-6">
                <ProbabilityChart category="items" />
              </CardContent>
            </Card>
          </TabsContent>
          
          {/* Premium Items Tab - Two Column Layout */}
          <TabsContent value="premiumItems" className="mt-0">
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest mb-4">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest sticky top-[121px] z-10">
                <div className="flex justify-between items-center">
                  <CardTitle className="text-gray-200">Premium Items</CardTitle>
                  <Button 
                    variant="outline" 
                    size="sm" 
                    onClick={() => distributeEvenly('premiumItems')}
                    className="text-xs text-gray-300 border-cyrus-dark-lightest bg-cyrus-dark hover:bg-cyrus-dark-light"
                  >
                    Distribute Evenly
                  </Button>
                </div>
                <CardDescription className="text-gray-400">
                  Configure the probabilities for premium items. Total should be 1,000,000 (100%).
                  Current: {collectorData.premiumItemsTotal.toLocaleString()}/1,000,000
                  ({(collectorData.premiumItemsTotal / 1000000 * 100).toFixed(2)}%)
                  {collectorData.premiumItemsTotal !== 1000000 && (
                    <span className="text-destructive"> (Invalid)</span>
                  )}
                </CardDescription>
              </CardHeader>
              <CardContent className="pt-6">
                <div className="mb-4">
                  <Button onClick={() => handleAddItem('premiumItems')} className="flex items-center bg-cyrus-blue hover:bg-cyrus-blue/90">
                    <Plus className="mr-2 h-4 w-4" />
                    Add Premium Item
                  </Button>
                </div>
                <div>
                  {renderItemTable('premiumItems')}
                </div>
              </CardContent>
            </Card>
            
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest mb-4">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest">
                <CardTitle className="text-gray-200">Probability Distribution</CardTitle>
              </CardHeader>
              <CardContent className="pt-6">
                <ProbabilityChart category="premiumItems" />
              </CardContent>
            </Card>
          </TabsContent>
          
          {/* Premium Status Items Tab - Two Column Layout */}
          <TabsContent value="premiumStatusItems" className="mt-0">
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest mb-4">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest sticky top-[121px] z-10">
                <div className="flex justify-between items-center">
                  <CardTitle className="text-gray-200">Premium Status Items</CardTitle>
                  <Button 
                    variant="outline" 
                    size="sm" 
                    onClick={() => distributeEvenly('premiumStatusItems')}
                    className="text-xs text-gray-300 border-cyrus-dark-lightest bg-cyrus-dark hover:bg-cyrus-dark-light"
                  >
                    Distribute Evenly
                  </Button>
                </div>
                <CardDescription className="text-gray-400">
                  Configure the probabilities for premium status items. Total should be 1,000,000 (100%).
                  Current: {collectorData.premiumStatusItemsTotal.toLocaleString()}/1,000,000
                  ({(collectorData.premiumStatusItemsTotal / 1000000 * 100).toFixed(2)}%)
                  {collectorData.premiumStatusItemsTotal !== 1000000 && (
                    <span className="text-destructive"> (Invalid)</span>
                  )}
                </CardDescription>
              </CardHeader>
              <CardContent className="pt-6">
                <div className="mb-4">
                  <Button onClick={() => handleAddItem('premiumStatusItems')} className="flex items-center bg-cyrus-blue hover:bg-cyrus-blue/90">
                    <Plus className="mr-2 h-4 w-4" />
                    Add Premium Status Item
                  </Button>
                </div>
                <div>
                  {renderItemTable('premiumStatusItems')}
                </div>
              </CardContent>
            </Card>
            
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest mb-4">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest">
                <CardTitle className="text-gray-200">Probability Distribution</CardTitle>
              </CardHeader>
              <CardContent className="pt-6">
                <ProbabilityChart category="premiumStatusItems" />
              </CardContent>
            </Card>
          </TabsContent>
        </div>
      </Tabs>
      
      <ItemSearchDialog />
      <ImportDialog
        isOpen={showImportDialog}
        onClose={() => setShowImportDialog(false)}
        category={selectedCategory}
      />
      <BatchImportDialog
        isOpen={showBatchImportDialog}
        onClose={() => setShowBatchImportDialog(false)}
        category={selectedCategory}
      />
    </div>
  );
};

export default CollectorTab; 