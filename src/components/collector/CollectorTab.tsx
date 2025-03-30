import React, { useState, useEffect } from "react";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "../ui/tabs";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from "../ui/card";
import { Button } from "../ui/button";
import { FormField } from "../ui/form-field";
import { Table, TableHeader, TableBody, TableRow, TableHead, TableCell } from "../ui/table";
import { parseCollectorData, serializeCollectorData, validateCollectorData, calculatePercentage } from "../../utils/collectorUtils";
import { CollectorData, CollectingItem, CollectorValidationResult } from "../../types/collectorTypes";
import { Plus, Save, Trash, AlertTriangle } from "lucide-react";
import { toast } from "sonner";

interface CollectorTabProps {
  fileContent: string;
  onSave: (content: string) => void;
}

const CollectorTab: React.FC<CollectorTabProps> = ({ fileContent, onSave }) => {
  const [collectorData, setCollectorData] = useState<CollectorData | null>(null);
  const [validation, setValidation] = useState<CollectorValidationResult | null>(null);
  const [activeTab, setActiveTab] = useState("enchant");
  
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
    
    // Nur speichern, wenn keine kritischen Fehler vorhanden sind
    if (!validation.enchantTotalMismatch &&
        !validation.itemsTotalMismatch &&
        !validation.premiumItemsTotalMismatch && 
        !validation.premiumStatusItemsTotalMismatch) {
      // Serialisiere die Daten und gib sie zurück
      const serialized = serializeCollectorData(collectorData, fileContent);
      onSave(serialized);
    } else {
      // Bei Fehlern wird eine Warnung angezeigt
      toast.error("Cannot save: Please fix validation errors first");
    }
  };
  
  // Enchant editing
  const handleEnchantChange = (index: number, chance: number) => {
    if (!collectorData) return;
    
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
    if (!collectorData) return;
    
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
    if (!collectorData) return;
    
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
    if (!collectorData) return;
    
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
  
  // Funktion zum Hinzufügen von Enchantments
  const handleAddEnchant = () => {
    if (!collectorData) return;
    
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
  
  // Funktion zum Entfernen von Enchantments
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
  
  // Enchant Level Änderung
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
  
  if (!collectorData) {
    return <div className="flex justify-center items-center p-12">Loading collector data...</div>;
  }
  
  return (
    <div className="collector-tab w-full h-full overflow-auto">
      <div className="sticky top-0 z-10 bg-background p-4 pb-0 border-b border-border mb-4">
        <div className="flex justify-between mb-4">
          <h2 className="text-2xl font-bold text-cyrus-gold">Collector System</h2>
          <div className="flex gap-2">
            <Button onClick={handleSave} className="flex items-center bg-cyrus-blue hover:bg-cyrus-blue/90">
              <Save className="mr-2 h-4 w-4" />
              Save
            </Button>
          </div>
        </div>
        
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
        <div className="px-4 mb-4">
          <TabsList className="w-full justify-start bg-cyrus-dark-lighter">
            <TabsTrigger value="enchant" className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white">
              Enchantment {!validation?.enchantValid && <AlertTriangle className="ml-2 h-4 w-4 text-destructive" />}
            </TabsTrigger>
            <TabsTrigger value="items" className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white">
              Items {!validation?.itemsValid && <AlertTriangle className="ml-2 h-4 w-4 text-destructive" />}
            </TabsTrigger>
            <TabsTrigger value="premiumItems" className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white">
              Premium Items {!validation?.premiumItemsValid && <AlertTriangle className="ml-2 h-4 w-4 text-destructive" />}
            </TabsTrigger>
            <TabsTrigger value="premiumStatusItems" className="data-[state=active]:bg-cyrus-blue data-[state=active]:text-white">
              Premium Status Items {!validation?.premiumStatusItemsValid && <AlertTriangle className="ml-2 h-4 w-4 text-destructive" />}
            </TabsTrigger>
          </TabsList>
        </div>
        
        <div className="px-4 pb-4">
          {/* Enchant Tab */}
          <TabsContent value="enchant" className="mt-0">
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest sticky top-[110px] z-10">
                <CardTitle>Enchantment Probabilities</CardTitle>
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
                        <TableHead className="w-[80px] sticky top-[174px] bg-cyrus-dark-lighter z-10">Level</TableHead>
                        <TableHead className="w-[120px] sticky top-[174px] bg-cyrus-dark-lighter z-10">Probability</TableHead>
                        <TableHead className="w-[80px] sticky top-[174px] bg-cyrus-dark-lighter z-10">Actions</TableHead>
                      </TableRow>
                    </TableHeader>
                    <TableBody>
                      {collectorData.enchant.map((enchant, index) => (
                        <TableRow key={index}>
                          <TableCell>
                            <FormField
                              id={`enchant-level-${index}`}
                              label=""
                              type="number"
                              value={enchant.level}
                              onChange={(value) => handleEnchantLevelChange(index, parseInt(value, 10) || 0)}
                              className="w-20"
                              min={0}
                              error={undefined}
                            />
                          </TableCell>
                          <TableCell>
                            <FormField
                              id={`enchant-${index}`}
                              label=""
                              type="number"
                              value={enchant.chance}
                              onChange={(value) => handleEnchantChange(index, parseInt(value, 10) || 0)}
                              className="w-32"
                              min={0}
                              max={1000}
                              error={enchant.chance < 0 ? "Value must be positive" : undefined}
                            />
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
          
          {/* Items Tab */}
          <TabsContent value="items" className="mt-0">
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest sticky top-[110px] z-10">
                <CardTitle>Collector Items</CardTitle>
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
                  <Button onClick={() => handleAddItem('items')} className="flex items-center bg-cyrus-blue hover:bg-cyrus-blue/90">
                    <Plus className="mr-2 h-4 w-4" />
                    Add Item
                  </Button>
                </div>
                <div>
                  <Table>
                    <TableHeader className="bg-cyrus-dark-lighter">
                      <TableRow>
                        <TableHead className="text-gray-300 sticky top-[174px] bg-cyrus-dark-lighter z-10">Item ID</TableHead>
                        <TableHead className="text-gray-300 w-32 sticky top-[174px] bg-cyrus-dark-lighter z-10">Probability</TableHead>
                        <TableHead className="text-gray-300 w-32 sticky top-[174px] bg-cyrus-dark-lighter z-10">Percentage</TableHead>
                        <TableHead className="text-gray-300 w-24 sticky top-[174px] bg-cyrus-dark-lighter z-10">Actions</TableHead>
                      </TableRow>
                    </TableHeader>
                    <TableBody>
                      {collectorData.items.map((item, index) => (
                        <TableRow key={index} className="border-cyrus-dark-lightest">
                          <TableCell>
                            <FormField
                              id={`item-id-${index}`}
                              label=""
                              type="text"
                              value={item.itemId}
                              onChange={(value) => handleItemChange(index, 'itemId', value, 'items')}
                            />
                          </TableCell>
                          <TableCell>
                            <FormField
                              id={`item-prob-${index}`}
                              label=""
                              type="number"
                              value={item.probability}
                              onChange={(value) => handleItemChange(index, 'probability', parseInt(value, 10) || 0, 'items')}
                              min={0}
                              error={item.probability < 0 ? "Value must be positive" : undefined}
                            />
                          </TableCell>
                          <TableCell>{calculatePercentage(item.probability).toFixed(4)}%</TableCell>
                          <TableCell>
                            <Button 
                              variant="destructive" 
                              size="icon"
                              onClick={() => handleRemoveItem(index, 'items')}
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
          
          {/* Premium Items Tab */}
          <TabsContent value="premiumItems" className="mt-0">
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest sticky top-[110px] z-10">
                <CardTitle>Premium Items</CardTitle>
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
                  <Table>
                    <TableHeader className="bg-cyrus-dark-lighter">
                      <TableRow>
                        <TableHead className="text-gray-300 sticky top-[174px] bg-cyrus-dark-lighter z-10">Item ID</TableHead>
                        <TableHead className="text-gray-300 w-32 sticky top-[174px] bg-cyrus-dark-lighter z-10">Probability</TableHead>
                        <TableHead className="text-gray-300 w-32 sticky top-[174px] bg-cyrus-dark-lighter z-10">Percentage</TableHead>
                        <TableHead className="text-gray-300 w-24 sticky top-[174px] bg-cyrus-dark-lighter z-10">Actions</TableHead>
                      </TableRow>
                    </TableHeader>
                    <TableBody>
                      {collectorData.premiumItems.map((item, index) => (
                        <TableRow key={index} className="border-cyrus-dark-lightest">
                          <TableCell>
                            <FormField
                              id={`premium-item-id-${index}`}
                              label=""
                              type="text"
                              value={item.itemId}
                              onChange={(value) => handleItemChange(index, 'itemId', value, 'premiumItems')}
                            />
                          </TableCell>
                          <TableCell>
                            <FormField
                              id={`premium-item-prob-${index}`}
                              label=""
                              type="number"
                              value={item.probability}
                              onChange={(value) => handleItemChange(index, 'probability', parseInt(value, 10) || 0, 'premiumItems')}
                              min={0}
                              error={item.probability < 0 ? "Value must be positive" : undefined}
                            />
                          </TableCell>
                          <TableCell>{calculatePercentage(item.probability).toFixed(4)}%</TableCell>
                          <TableCell>
                            <Button 
                              variant="destructive" 
                              size="icon"
                              onClick={() => handleRemoveItem(index, 'premiumItems')}
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
          
          {/* Premium Status Items Tab */}
          <TabsContent value="premiumStatusItems" className="mt-0">
            <Card className="bg-cyrus-dark-light border-cyrus-dark-lightest">
              <CardHeader className="bg-cyrus-dark-lighter border-b border-cyrus-dark-lightest sticky top-[110px] z-10">
                <CardTitle>Premium Status Items</CardTitle>
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
                  <Table>
                    <TableHeader className="bg-cyrus-dark-lighter">
                      <TableRow>
                        <TableHead className="text-gray-300 sticky top-[174px] bg-cyrus-dark-lighter z-10">Item ID</TableHead>
                        <TableHead className="text-gray-300 w-32 sticky top-[174px] bg-cyrus-dark-lighter z-10">Probability</TableHead>
                        <TableHead className="text-gray-300 w-32 sticky top-[174px] bg-cyrus-dark-lighter z-10">Percentage</TableHead>
                        <TableHead className="text-gray-300 w-24 sticky top-[174px] bg-cyrus-dark-lighter z-10">Actions</TableHead>
                      </TableRow>
                    </TableHeader>
                    <TableBody>
                      {collectorData.premiumStatusItems.map((item, index) => (
                        <TableRow key={index} className="border-cyrus-dark-lightest">
                          <TableCell>
                            <FormField
                              id={`premium-status-item-id-${index}`}
                              label=""
                              type="text"
                              value={item.itemId}
                              onChange={(value) => handleItemChange(index, 'itemId', value, 'premiumStatusItems')}
                            />
                          </TableCell>
                          <TableCell>
                            <FormField
                              id={`premium-status-item-prob-${index}`}
                              label=""
                              type="number"
                              value={item.probability}
                              onChange={(value) => handleItemChange(index, 'probability', parseInt(value, 10) || 0, 'premiumStatusItems')}
                              min={0}
                              error={item.probability < 0 ? "Value must be positive" : undefined}
                            />
                          </TableCell>
                          <TableCell>{calculatePercentage(item.probability).toFixed(4)}%</TableCell>
                          <TableCell>
                            <Button 
                              variant="destructive" 
                              size="icon"
                              onClick={() => handleRemoveItem(index, 'premiumStatusItems')}
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
        </div>
      </Tabs>
    </div>
  );
};

export default CollectorTab; 