import React, { useState, useEffect, useMemo } from "react";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "../ui/tabs";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from "../ui/card";
import { Button } from "../ui/button";
import { FormField } from "../ui/form-field";
import { Table, TableHeader, TableBody, TableRow, TableHead, TableCell } from "../ui/table";
import { parseCollectorData, serializeCollectorData, validateCollectorData, calculatePercentage } from "../../utils/collectorUtils";
import { CollectorData, CollectingItem, CollectorValidationResult } from "../../types/collectorTypes";
import { Plus, Save, Trash, AlertTriangle, Search, Filter, X, Copy, ChevronDown, Edit, MoreHorizontal, Download, Upload, GripVertical } from "lucide-react";
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
import AvailableItemsList from '../shared/AvailableItemsList';
import { ResourceItem } from '../../types/fileTypes';

// Füge globale Styles für Formular-Elemente hinzu
import './styles/dark-mode.css';

// Definiere die globale Konfiguration für TypeScript
declare global {
  interface Window {
    APP_CONFIG?: {
      fileData?: {
        items: ResourceItem[]; // Verwende ResourceItem Typ
      };
    };
  }
}

interface CollectorTabProps {
  fileContent: string;
  onSave: (content: string) => void;
  editMode?: boolean;
  availableItems?: ResourceItem[];
}

const CollectorTab: React.FC<CollectorTabProps> = ({ 
  fileContent, 
  onSave, 
  editMode = false, 
  availableItems = []
}) => {
  const [collectorData, setCollectorData] = useState<CollectorData | null>(null);
  const [validation, setValidation] = useState<CollectorValidationResult | null>(null);
  const [activeTab, setActiveTab] = useState("enchant");
  const [searchQuery, setSearchQuery] = useState("");
  const [selectedItems, setSelectedItems] = useState<string[]>([]);
  const [showAddItemDialog, setShowAddItemDialog] = useState(false);
  const [selectedCategoryForDialog, setSelectedCategoryForDialog] = useState<'items' | 'premiumItems' | 'premiumStatusItems'>('items');
  const [showImportDialog, setShowImportDialog] = useState(false);
  const [showBatchImportDialog, setShowBatchImportDialog] = useState(false);
  
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
    // Ensure index is valid
    if (index < 0 || index >= updatedItems.length) {
      console.error(`Invalid index ${index} for category ${category}`);
      return;
    }
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
  
  // Function to open the add item dialog
  const openAddItemDialog = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    if (!editMode) return;
    setSelectedCategoryForDialog(category);
    setShowAddItemDialog(true);
  };
  
  // Remove item
  const handleRemoveItem = (
    index: number,
    category: 'items' | 'premiumItems' | 'premiumStatusItems'
  ) => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const updatedItems = [...collectorData[category]];
     // Ensure index is valid
     if (index < 0 || index >= updatedItems.length) {
      console.error(`Invalid index ${index} for category ${category}`);
      return;
    }
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
    
    const itemsInCategory = collectorData[category];
    // Ensure index is valid
    if (index < 0 || index >= itemsInCategory.length) {
      console.error(`Invalid index ${index} for category ${category}`);
      return;
    }
    const itemToDuplicate = itemsInCategory[index];
    const duplicatedItem = { ...itemToDuplicate, probability: 0 }; // Default with 0 probability
    
    const updatedItems = [...itemsInCategory];
    updatedItems.splice(index + 1, 0, duplicatedItem); // Insert after the original
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Add enchant
  const handleAddEnchant = () => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const maxLevel = collectorData.enchant.reduce((max, item) => Math.max(max, item.level), 0);
    const newEnchant = { level: maxLevel + 1, chance: 0 };
    const updatedEnchant = [...collectorData.enchant, newEnchant];
    
    const updatedData = {
      ...collectorData,
      enchant: updatedEnchant,
      enchantTotal: updatedEnchant.reduce((sum, item) => sum + item.chance, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Remove enchant
  const handleRemoveEnchant = (index: number) => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const updatedEnchant = [...collectorData.enchant];
    // Ensure index is valid
    if (index < 0 || index >= updatedEnchant.length) {
      console.error(`Invalid index ${index} for enchant`);
      return;
    }
    updatedEnchant.splice(index, 1);
    
    const updatedData = {
      ...collectorData,
      enchant: updatedEnchant,
      enchantTotal: updatedEnchant.reduce((sum, item) => sum + item.chance, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Change enchant level
  const handleEnchantLevelChange = (index: number, level: number) => {
    if (!collectorData || !editMode) return; // Check if editMode is enabled
    
    const updatedEnchant = [...collectorData.enchant];
    // Ensure index is valid
    if (index < 0 || index >= updatedEnchant.length) {
      console.error(`Invalid index ${index} for enchant`);
      return;
    }
    updatedEnchant[index] = { ...updatedEnchant[index], level };
    
    const updatedData = {
      ...collectorData,
      enchant: updatedEnchant,
      // Total bleibt gleich, da nur Level geändert
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Filter items based on search query
  const filteredItems = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
      if (!collectorData) return [];
      
    const items = collectorData[category];
    
    if (!searchQuery) return items;
    
    return items.filter(item => 
        item.itemId.toLowerCase().includes(searchQuery.toLowerCase())
      );
    };
    
  // Remove selected items
  const handleRemoveSelectedItems = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    if (!collectorData || selectedItems.length === 0 || !editMode) return;
    
    const updatedItems = collectorData[category].filter(item => !selectedItems.includes(item.itemId));
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
    setSelectedItems([]); // Clear selection
    toast.success(`${selectedItems.length} items removed from ${category}`);
  };
  
  // Adjust item probabilities
  const adjustProbabilities = (
    category: 'items' | 'premiumItems' | 'premiumStatusItems', 
    method: 'equal' | 'proportional' | 'reset'
  ) => {
    if (!collectorData || !editMode) return;

    const items = [...collectorData[category]];
    const totalTarget = 1000000; // 1 million

    let updatedItems: CollectingItem[] = [];

    switch (method) {
      case 'equal': {
        if (items.length === 0) return;
        const equalProb = Math.floor(totalTarget / items.length);
        let remainder = totalTarget % items.length;
        updatedItems = items.map((item, index) => {
          const prob = equalProb + (index < remainder ? 1 : 0);
          return { ...item, probability: prob };
        });
        toast.success(`Probabilities in ${category} set equally.`);
        break;
      }
      case 'proportional': {
        const currentTotal = collectorData[`${category}Total`];
        if (currentTotal === 0 || items.length === 0) return;

        let cumulativeProb = 0;
        updatedItems = items.map((item, index) => {
          const proportion = item.probability / currentTotal;
          let newProb = Math.floor(proportion * totalTarget);
          
          // Handle potential rounding issues by assigning remainder to the last item
          if (index === items.length - 1 && cumulativeProb + newProb !== totalTarget) {
             newProb = totalTarget - cumulativeProb; 
          }
          
          cumulativeProb += newProb;
          return { ...item, probability: newProb };
        });
        toast.success(`Probabilities in ${category} adjusted proportionally.`);
        break;
      }
       case 'reset': {
        updatedItems = items.map(item => ({ ...item, probability: 0 }));
        toast.success(`Probabilities in ${category} reset to 0.`);
        break;
      }
      default:
        return;
    }
    
    // Ensure the total is exactly the target by adjusting the last item if necessary
    // This check might be redundant after the adjustment within the proportional case
    const finalTotal = updatedItems.reduce((sum, item) => sum + item.probability, 0);
    if (finalTotal !== totalTarget && updatedItems.length > 0 && method !== 'reset') {
      const diff = totalTarget - finalTotal;
      if(updatedItems.length > 0) updatedItems[updatedItems.length - 1].probability += diff;
    }
    
    const updatedData = {
      ...collectorData,
      [category]: updatedItems,
      [`${category}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Simple alias for clarity
  const distributeEvenly = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    adjustProbabilities(category, 'equal');
  };

  // Adjust enchant probabilities
  const adjustEnchantProbabilities = (method: 'equal' | 'proportional' | 'reset') => {
    if (!collectorData || !editMode) return;

    const enchants = [...collectorData.enchant];
    const totalTarget = 1000000;
    let updatedEnchants: { level: number; chance: number }[] = [];

    switch (method) {
        case 'equal': {
            if (enchants.length === 0) return;
            const equalProb = Math.floor(totalTarget / enchants.length);
            let remainder = totalTarget % enchants.length;
            updatedEnchants = enchants.map((enchant, index) => {
                const prob = equalProb + (index < remainder ? 1 : 0);
                return { ...enchant, chance: prob };
            });
            toast.success(`Enchant probabilities set equally.`);
            break;
        }
        case 'proportional': {
            const currentTotal = collectorData.enchantTotal;
            if (currentTotal === 0 || enchants.length === 0) return;

            let cumulativeProb = 0;
            updatedEnchants = enchants.map((enchant, index) => {
                const proportion = enchant.chance / currentTotal;
                let newProb = Math.floor(proportion * totalTarget);
                if (index === enchants.length - 1 && cumulativeProb + newProb !== totalTarget) {
                    newProb = totalTarget - cumulativeProb;
                }
                cumulativeProb += newProb;
                return { ...enchant, chance: newProb };
            });
            toast.success(`Enchant probabilities adjusted proportionally.`);
            break;
        }
        case 'reset': {
            updatedEnchants = enchants.map(enchant => ({ ...enchant, chance: 0 }));
            toast.success(`Enchant probabilities reset to 0.`);
            break;
        }
        default: return;
    }

    // Ensure the total is exactly the target by adjusting the last item if necessary
    const finalTotal = updatedEnchants.reduce((sum, item) => sum + item.chance, 0);
    if (finalTotal !== totalTarget && updatedEnchants.length > 0 && method !== 'reset') {
        const diff = totalTarget - finalTotal;
         if(updatedEnchants.length > 0) updatedEnchants[updatedEnchants.length - 1].chance += diff;
    }
    
    const updatedData = {
      ...collectorData,
        enchant: updatedEnchants,
        enchantTotal: updatedEnchants.reduce((sum, item) => sum + item.chance, 0)
    };
    
    setCollectorData(updatedData);
    setValidation(validateCollectorData(updatedData));
  };
  
  // Simple alias for clarity
  const distributeEnchantEvenly = () => {
    adjustEnchantProbabilities('equal');
  };

  // --- Definition der Dialog-Komponenten und Hilfsfunktionen --- 

  // Komponente für den "Add Item" Dialog
  const AddItemDialog = () => {
    const [newItemId, setNewItemId] = useState("");
    const [newItemProbability, setNewItemProbability] = useState(0);

    // Logge die Länge der Prop, die vom CollectorTab kommt
    console.log("[AddItemDialog] Rendering. Erhaltene availableItems Prop Länge:", availableItems.length); 

    // Funktion zum Hinzufügen des Items (wird im Dialog-Footer aufgerufen)
    const handleConfirmAddItem = () => {
      if (!collectorData || !editMode || !newItemId.trim()) {
        toast.error("Item ID darf nicht leer sein.");
        return;
      }
      
      const newItem: CollectingItem = { itemId: newItemId, probability: newItemProbability };
      const updatedItems = [...collectorData[selectedCategoryForDialog], newItem];
      
      const updatedData = {
        ...collectorData,
        [selectedCategoryForDialog]: updatedItems,
        [`${selectedCategoryForDialog}Total`]: updatedItems.reduce((sum, item) => sum + item.probability, 0)
      };
      
      setCollectorData(updatedData);
      setValidation(validateCollectorData(updatedData));
      setShowAddItemDialog(false);
      setNewItemId(""); // Reset Dialog state
      setNewItemProbability(0);
      toast.success(`Item ${newItemId} zu ${selectedCategoryForDialog} hinzugefügt`);
    };

    // Funktion, die aufgerufen wird, wenn ein Item aus der Liste ausgewählt wird
    const handleSelectItemFromList = (item: ResourceItem) => {
      setNewItemId(item.id); // Setze die ID des ausgewählten Items
      toast.info(`${item.displayName || item.name} ausgewählt.`);
    };
    
    return (
      <Dialog open={showAddItemDialog} onOpenChange={setShowAddItemDialog}>
        {/* Größerer Dialog für die Liste */}
        <DialogContent className="max-w-4xl bg-cyrus-dark-light border-cyrus-dark-lightest">
          <DialogHeader>
            <DialogTitle className="text-gray-200">Neues Item zu "{selectedCategoryForDialog}" hinzufügen</DialogTitle>
            <DialogDescription className="text-gray-400">
              Suchen und wählen Sie ein Item aus der Liste oder geben Sie die Item-ID manuell ein.
            </DialogDescription>
          </DialogHeader>
          
          {/* Layout mit 2 Spalten */}
          <div className="grid grid-cols-1 md:grid-cols-2 gap-6 py-4"> 
            {/* Linke Spalte: Verfügbare Items Liste */}
            <div>
              {/* Verwende die 'availableItems'-Prop aus CollectorTab */}
              <AvailableItemsList 
                availableItems={availableItems} 
                onSelectItem={handleSelectItemFromList} 
              />
          </div>
          
            {/* Rechte Spalte: Eingabefelder */}
            <div className="space-y-4">
              <div>
                <Label htmlFor="newItemId" className="text-gray-300">Item ID</Label>
                <Input
                  id="newItemId"
                  value={newItemId}
                  onChange={(e) => setNewItemId(e.target.value)}
                  placeholder="II_WEA_..."
                  className="mt-1 bg-cyrus-dark text-white border-cyrus-dark-lightest"
                  disabled={!editMode}
                />
                 <p className="text-xs text-gray-400 mt-1">Sie können ein Item aus der linken Liste auswählen oder die ID manuell eingeben.</p>
          </div>
              <div>
                <Label htmlFor="newItemProbability" className="text-gray-300">Probability</Label>
            <Input
                  id="newItemProbability"
              type="number"
                  value={newItemProbability}
                  onChange={(e) => setNewItemProbability(Number(e.target.value))}
                  min="0"
                  className="mt-1 bg-cyrus-dark text-white border-cyrus-dark-lightest"
                  disabled={!editMode}
                />
              </div>
            </div>
          </div>
          
          <DialogFooter>
            <Button 
              variant="outline" 
              onClick={() => setShowAddItemDialog(false)}
              className="text-gray-300 border-cyrus-dark-lightest"
            >
               Abbrechen
            </Button>
            <Button 
               onClick={handleConfirmAddItem} 
               disabled={!editMode || !newItemId.trim()}
              className="bg-cyrus-blue"
            >
               Item hinzufügen
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
                placeholder={"II_SYS_SYS_SCR_BXCOLL 10000\nII_GEN_GEM_ELE_WIND 5000\nII_ARM_M_CLO_SHIRT01_1 20000"}
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
    const maxProbability = sortedItems.length > 0 ? sortedItems[0].probability : 1; // Avoid division by zero
    
    // Für die Prozentwerte
    const total = collectorData[`${category}Total`];
    
    return (
      <div className="p-4 bg-cyrus-dark-light rounded-md">
        <h3 className="font-semibold mb-2 text-gray-200">Top {maxItems} Items by Probability</h3>
        
        <div className="space-y-3">
          {sortedItems.map((item, index) => {
            const percentage = total > 0 ? (item.probability / total) * 100 : 0;
            const barWidth = maxProbability > 0 ? `${(item.probability / maxProbability) * 100}%` : '0%';
            
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
  
  // --- Definition der Render-Funktionen --- 

  const ItemSearchBar = ({ category }: { category: 'items' | 'premiumItems' | 'premiumStatusItems' }) => {
    
    return (
      <div className="flex flex-wrap items-center justify-between gap-4 mb-4">
        <div className="flex items-center gap-2 flex-1 min-w-[200px]">
            <Input
              placeholder="Search items..."
              value={searchQuery}
              onChange={(e) => setSearchQuery(e.target.value)}
            className="bg-cyrus-dark-lighter border-cyrus-dark-lightest text-gray-300"
            />
            {searchQuery && (
            <Button variant="ghost" size="icon" onClick={() => setSearchQuery('')} className="h-8 w-8">
              <X className="h-4 w-4 text-gray-400" />
            </Button>
          )}
        </div>
        
        <div className="flex items-center gap-2">
          {selectedItems.length > 0 && (
              <Button 
              variant="destructive" 
              onClick={() => handleRemoveSelectedItems(category)}
              disabled={!editMode}
              size="sm"
            >
              <Trash className="mr-2 h-4 w-4" />
              Delete Selected ({selectedItems.length})
              </Button>
            )}
          
          <DropdownMenu>
            <DropdownMenuTrigger asChild>
              <Button variant="outline" size="sm" className="text-gray-300 border-cyrus-dark-lightest">
                Distribute Probability
                <ChevronDown className="ml-2 h-4 w-4" />
              </Button>
            </DropdownMenuTrigger>
            <DropdownMenuContent className="bg-cyrus-dark border-cyrus-dark-lightest text-gray-300">
              <DropdownMenuItem onClick={() => adjustProbabilities(category, 'equal')} disabled={!editMode}>
                Distribute Equally
              </DropdownMenuItem>
              <DropdownMenuItem onClick={() => adjustProbabilities(category, 'proportional')} disabled={!editMode}>
                Adjust Proportionally
              </DropdownMenuItem>
              <DropdownMenuItem onClick={() => adjustProbabilities(category, 'reset')} disabled={!editMode}>
                Reset to 0
              </DropdownMenuItem>
            </DropdownMenuContent>
          </DropdownMenu>
          
          <DropdownMenu>
            <DropdownMenuTrigger asChild>
              <Button variant="outline" size="sm" className="text-gray-300 border-cyrus-dark-lightest">
                File Actions
                <ChevronDown className="ml-2 h-4 w-4" />
              </Button>
            </DropdownMenuTrigger>
            <DropdownMenuContent className="bg-cyrus-dark border-cyrus-dark-lightest text-gray-300">
              <DropdownMenuItem onClick={() => exportItemList(category)}>
                <Download className="mr-2 h-4 w-4" />
                Export Items
              </DropdownMenuItem>
              <DropdownMenuItem 
                onClick={() => {
                  setSelectedCategoryForDialog(category);
                  setShowImportDialog(true);
                }}
                disabled={!editMode}
              >
                <Upload className="mr-2 h-4 w-4" />
                Import Items (JSON)
              </DropdownMenuItem>
              <DropdownMenuItem 
                onClick={() => {
                  setSelectedCategoryForDialog(category);
                  setShowBatchImportDialog(true);
                }}
                disabled={!editMode}
              >
                <Upload className="mr-2 h-4 w-4" />
                Batch Import (Text)
              </DropdownMenuItem>
            </DropdownMenuContent>
          </DropdownMenu>
          
              <Button 
            onClick={() => openAddItemDialog(category)} // Verwende openAddItemDialog hier
            disabled={!editMode}
                size="sm"
            className="bg-cyrus-blue"
              >
            <Plus className="mr-2 h-4 w-4" /> Add Item
              </Button>
        </div>
      </div>
    );
  };
  
  // NEU: Komponente für ein sortierbares Grid-Item
  const SortableGridItem = ({ 
    children, 
    id 
  }: { 
    children: React.ReactNode, 
    id: string 
  }) => {
    const { attributes, listeners, setNodeRef, transform, transition, isDragging } = useSortable({ id });
    
    const style = {
      transform: CSS.Transform.toString(transform),
      transition,
      zIndex: isDragging ? 10 : 'auto',
      opacity: isDragging ? 0.8 : 1,
      boxShadow: isDragging ? '0 10px 15px -3px rgba(0, 0, 0, 0.1), 0 4px 6px -2px rgba(0, 0, 0, 0.05)' : 'none',
    };

    return (
      <div 
        ref={setNodeRef} 
        style={style} 
        {...attributes} 
        // Drag handle wird separat gerendert, daher hier nur {...attributes}
        className={`p-3 bg-cyrus-dark rounded border border-cyrus-dark-lightest flex items-center gap-2 ${isDragging ? 'shadow-lg' : ''}`}
      >
         {/* Drag Handle explizit rendern */} 
         {editMode && (
           <div {...listeners} className="cursor-grab p-1">
             <GripVertical className="h-5 w-5 text-gray-400" /> 
           </div>
         )}
        {children}
      </div>
    );
  };

  // Überarbeitete Funktion zum Rendern der Items als Grid
  const renderTable = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    const itemsToRender = filteredItems(category);
    
    const handleDragEnd = (event: DragEndEvent) => {
      const { active, over } = event;

      if (active.id !== over?.id) {
        if (!collectorData) return;

        const originalItems = collectorData[category];
        const oldIndex = originalItems.findIndex(item => item.itemId === active.id);
        const newIndex = originalItems.findIndex(item => item.itemId === over!.id);

        if (oldIndex !== -1 && newIndex !== -1) {
            const updatedOrder = arrayMove(originalItems, oldIndex, newIndex);
            
            const updatedData = {
                ...collectorData,
                [category]: updatedOrder,
            };

            setCollectorData(updatedData);
            toast.info("Item order updated");
        }
      }
    };

    return (
      <DndContext sensors={sensors} collisionDetection={closestCenter} onDragEnd={handleDragEnd}>
        <SortableContext items={itemsToRender.map(item => item.itemId)} strategy={verticalListSortingStrategy}>
          {/* Grid-Layout anstelle von Tabelle - Maximal 2 Spalten */} 
          <div className="grid grid-cols-1 md:grid-cols-2 gap-3"> {/* xl:grid-cols-3 entfernt */}
              {itemsToRender.length === 0 ? (
                 <p className="col-span-full text-center text-gray-400 py-8">
                   No items found in this category {searchQuery ? 'matching your search' : ''}
                 </p>
              ) : (
                itemsToRender.map((item, displayIndex) => { 
                  const originalIndex = collectorData ? collectorData[category].findIndex(origItem => origItem.itemId === item.itemId) : -1;
                  if (originalIndex === -1) return null; 
                  
                  return (
                    // Verwende SortableGridItem anstelle von SortableTableRow/TableCell
                    <SortableGridItem key={item.itemId} id={item.itemId}>
                      {/* Innere Struktur des Grid-Items - JETZT HORIZONTAL */} 
                      <div className="flex-1 flex items-center gap-2 min-w-0"> {/* Geändert zu flex-row (Standard) und gap-2 */} 
                        {/* Checkbox (optional) */} 
                        {editMode && (
                          <Checkbox
                            className="flex-shrink-0" // Verhindert Schrumpfen
                            checked={selectedItems.includes(item.itemId)}
                            onCheckedChange={(checked) => {
                              setSelectedItems(prev => 
                                checked 
                                  ? [...prev, item.itemId]
                                  : prev.filter(id => id !== item.itemId)
                              );
                            }}
                          />
                        )}
                        {/* Item ID (nimmt verfügbaren Platz ein) */} 
                        <span className="font-mono text-xs text-gray-300 truncate flex-grow" title={item.itemId}>{item.itemId}</span>
                        
                        {/* Probability */} 
                        <Label htmlFor={`prob-${item.itemId}`} className="text-xs text-gray-400 flex-shrink-0 ml-auto">Prob:</Label> {/* ml-auto für Abstand */} 
                        {editMode ? (
                          <Input 
                            id={`prob-${item.itemId}`}
                            type="number"
                            value={item.probability}
                            onChange={(e) => handleItemChange(originalIndex, 'probability', String(e.target.value), category)}
                            className="h-7 text-xs text-right bg-cyrus-dark-lighter border-cyrus-dark-lightest text-gray-300 w-20 flex-shrink-0" /* Breite angepasst */
                          />
                        ) : (
                          <span className="text-xs text-gray-300 w-20 text-right flex-shrink-0">{item.probability.toLocaleString()}</span> /* Breite angepasst */
                        )}

                        {/* Percentage */} 
                        <span className="text-xs text-gray-400 w-12 text-right flex-shrink-0">
                          {calculatePercentage(item.probability)}%
                        </span>

                         {/* Actions Dropdown */} 
                         {editMode && (
                           <div className="flex-shrink-0"> {/* Div für korrekte Platzierung */} 
                            <DropdownMenu>
                              <DropdownMenuTrigger asChild>
                                <Button variant="ghost" size="icon" className="h-6 w-6">
                                  <MoreHorizontal className="h-4 w-4 text-gray-400" />
                                </Button>
                              </DropdownMenuTrigger>
                              <DropdownMenuContent className="bg-cyrus-dark border-cyrus-dark-lightest text-gray-300">
                                <DropdownMenuItem onClick={() => handleDuplicateItem(originalIndex, category)}>
                                  <Copy className="mr-2 h-4 w-4" />
                                  Duplicate
                                </DropdownMenuItem>
                                <DropdownMenuItem onClick={() => handleRemoveItem(originalIndex, category)} className="text-red-400">
                                  <Trash className="mr-2 h-4 w-4" />
                                  Delete
                                </DropdownMenuItem>
                              </DropdownMenuContent>
                            </DropdownMenu>
                           </div>
                          )}
                      </div>
                    </SortableGridItem>
                  );
                })
              )}
          </div>
        </SortableContext>
      </DndContext>
    );
  };


  const renderItemTable = (category: 'items' | 'premiumItems' | 'premiumStatusItems') => {
    if (!collectorData) return <div className="text-center py-8 text-gray-400">Loading data...</div>;
    
    const total = collectorData[`${category}Total`];
    // Umbenannt und geänderte Logik für Validierungsfehler
    const itemValidationError = validation && !validation[`${category}Valid`] ? `Summe für ${category} stimmt nicht (sollte 1,000,000 sein)` : null;
    
        return (
      <div className="bg-cyrus-dark-lighter border border-cyrus-dark-lightest rounded-md p-4">
            <ItemSearchBar category={category} />
        
        <div className="mb-4 flex justify-between items-center">
          <div className="text-sm text-gray-400">
            Total Probability: {total.toLocaleString()} / 1,000,000
          </div>
          {itemValidationError && (
            <Badge variant="destructive" className="flex items-center gap-1">
              <AlertTriangle className="h-4 w-4" />
              {itemValidationError}
            </Badge>
              )}
            </div>
        
        <div className="rounded-md border border-cyrus-dark-lightest overflow-hidden">
          {renderTable(category)}
        </div>
        
        <div className="mt-4">
          <ProbabilityChart category={category} />
        </div>
      </div>
    );
  };

  const renderEnchantTable = () => {
    if (!collectorData) return <div className="text-center py-8 text-gray-400">Loading data...</div>;
    
    const total = collectorData.enchantTotal;
    // Umbenannt und geänderte Logik für Validierungsfehler
    const enchantValidationError = validation && !validation.enchantValid ? "Summe für Enchant stimmt nicht (sollte 1,000,000 sein)" : null;
                          
                          return (
      <Card className="bg-cyrus-dark-lighter border border-cyrus-dark-lightest">
        <CardHeader>
          <CardTitle className="text-gray-200">Enchant Chances</CardTitle>
          <CardDescription className="text-gray-400">
            Configure the probability for each enchant level.
          </CardDescription>
           <div className="flex items-center justify-between mt-2">
             <div className="text-sm text-gray-400">
                Total Probability: {total.toLocaleString()} / 1,000,000
                                </div>
             {enchantValidationError && (
                <Badge variant="destructive" className="flex items-center gap-1">
                  <AlertTriangle className="h-4 w-4" />
                  {enchantValidationError}
                </Badge>
              )}
              <div className="flex gap-2">
                                  <DropdownMenu>
                                    <DropdownMenuTrigger asChild>
                    <Button variant="outline" size="sm" className="text-gray-300 border-cyrus-dark-lightest">
                      Distribute Probability
                      <ChevronDown className="ml-2 h-4 w-4" />
                                      </Button>
                                    </DropdownMenuTrigger>
                  <DropdownMenuContent className="bg-cyrus-dark border-cyrus-dark-lightest text-gray-300">
                    <DropdownMenuItem onClick={() => adjustEnchantProbabilities('equal')} disabled={!editMode}>
                      Distribute Equally
                                      </DropdownMenuItem>
                    <DropdownMenuItem onClick={() => adjustEnchantProbabilities('proportional')} disabled={!editMode}>
                      Adjust Proportionally
                                      </DropdownMenuItem>
                    <DropdownMenuItem onClick={() => adjustEnchantProbabilities('reset')} disabled={!editMode}>
                      Reset to 0
                                      </DropdownMenuItem>
                                    </DropdownMenuContent>
                                  </DropdownMenu>
                <Button onClick={handleAddEnchant} disabled={!editMode} size="sm" className="bg-cyrus-blue">
                  <Plus className="mr-2 h-4 w-4" /> Add Enchant Level
                </Button>
                                </div>
              </div>
        </CardHeader>
        <CardContent>
                  <Table>
            <TableHeader>
                      <TableRow>
                <TableHead className="w-1/3 text-gray-300">Enchant Level</TableHead>
                <TableHead className="w-1/3 text-gray-300">Chance (out of 1,000,000)</TableHead>
                <TableHead className="w-1/3 text-right text-gray-300">Percentage</TableHead>
                {editMode && (
                  <TableHead className="w-20 text-center text-gray-300">Actions</TableHead>
                )}
                      </TableRow>
                    </TableHeader>
                    <TableBody>
              {collectorData.enchant.map((enchant, index) => (
                <TableRow key={`${enchant.level}-${index}`} className="border-b border-cyrus-dark-lightest">
                              <TableCell>
                    {editMode ? (
                      <Input 
                        type="number"
                        value={enchant.level}
                        onChange={(e) => handleEnchantLevelChange(index, parseInt(e.target.value, 10))}
                        className="w-24 bg-cyrus-dark-lighter border-cyrus-dark-lightest text-gray-300"
                      />
                    ) : (
                      <span className="text-gray-300">+{enchant.level}</span>
                    )}
                              </TableCell>
                  <TableCell>
                    {editMode ? (
                      <Input 
                                  type="number"
                        value={enchant.chance}
                        onChange={(e) => handleEnchantChange(index, parseInt(e.target.value, 10))}
                        className="w-32 bg-cyrus-dark-lighter border-cyrus-dark-lightest text-gray-300"
                      />
                    ) : (
                       <span className="text-gray-300">{enchant.chance.toLocaleString()}</span>
                    )}
                              </TableCell>
                  <TableCell className="text-right text-gray-400">
                    {calculatePercentage(enchant.chance)}%
                              </TableCell>
                                  {editMode && (
                    <TableCell className="text-center">
                      <Button variant="ghost" size="icon" onClick={() => handleRemoveEnchant(index)} className="h-8 w-8">
                        <Trash className="h-4 w-4 text-red-400" />
                                    </Button>
                              </TableCell>
                  )}
                </TableRow>
              ))}
                    </TableBody>
                  </Table>
        </CardContent>
      </Card>
    );
  };

  const renderSaveButton = () => {
    if (!editMode) return null;
    return (
        <Button onClick={handleSave} className="mt-4 bg-cyrus-blue">
          <Save className="mr-2 h-4 w-4" /> Save Changes
      </Button>
    );
  };

  // --- Haupt-JSX der Komponente --- 

  console.log("[CollectorTab] Haupt-Render. Verfügbare Items State Länge:", availableItems.length);
  
  if (!collectorData) {
    return <div className="p-4 text-center text-gray-400">Loading Collector data...</div>;
  }
  
  return (
    <div className="p-4 bg-cyrus-dark text-white">
      {/* Dialogs müssen außerhalb der Tabs gerendert werden, um Zustandsprobleme zu vermeiden */}
      <AddItemDialog /> 
      <ImportDialog
        isOpen={showImportDialog}
        onClose={() => setShowImportDialog(false)}
        category={selectedCategoryForDialog}
      />
      <BatchImportDialog
        isOpen={showBatchImportDialog}
        onClose={() => setShowBatchImportDialog(false)}
        category={selectedCategoryForDialog}
      />
      
      <Tabs value={activeTab} onValueChange={setActiveTab} className="mb-4">
        <TabsList className="bg-cyrus-dark-lighter border border-cyrus-dark-lightest">
          <TabsTrigger value="enchant" className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white text-gray-300">Enchant</TabsTrigger>
          <TabsTrigger value="items" className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white text-gray-300">Items</TabsTrigger>
          <TabsTrigger value="premiumItems" className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white text-gray-300">Premium Items</TabsTrigger>
          <TabsTrigger value="premiumStatusItems" className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white text-gray-300">Premium Status Items</TabsTrigger>
          </TabsList>
        
        <TabsContent value="enchant">
          {renderEnchantTable()}
          </TabsContent>
          
        <TabsContent value="items">
                  {renderItemTable('items')}
          </TabsContent>
          
        <TabsContent value="premiumItems">
                  {renderItemTable('premiumItems')}
          </TabsContent>
          
        <TabsContent value="premiumStatusItems">
                  {renderItemTable('premiumStatusItems')}
          </TabsContent>
      </Tabs>
      
      {renderSaveButton()}
    </div>
  );
};

export default CollectorTab; 