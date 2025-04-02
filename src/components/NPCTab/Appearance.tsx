import { useState, useEffect } from 'react';
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Button } from "@/components/ui/button";
import { Card, CardContent } from "@/components/ui/card";
import { NPCItem } from '../../types/npcTypes';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select";
import { FileSearch, RefreshCw } from 'lucide-react';

interface AppearanceProps {
  npc: NPCItem;
  onUpdateNPC: (updatedNPC: NPCItem, field?: string, oldValue?: any) => void;
  editMode: boolean;
}

const Appearance = ({ npc, onUpdateNPC, editMode }: AppearanceProps) => {
  const [localNPC, setLocalNPC] = useState<NPCItem>(npc);
  const [availableModels, setAvailableModels] = useState<string[]>([]);
  const [availableSkins, setAvailableSkins] = useState<string[]>([]);
  const [availableAnimations, setAvailableAnimations] = useState<string[]>([]);
  const [modelPreviewUrl, setModelPreviewUrl] = useState<string>('');
  const [isLoading, setIsLoading] = useState<boolean>(false);

  // Aktualisieren des lokalen Zustands, wenn sich der NPC ändert
  useEffect(() => {
    setLocalNPC(npc);
    if (npc.appearance?.modelFile) {
      generateModelPreviewUrl(npc.appearance.modelFile);
    }
  }, [npc]);

  // Simuliere das Laden von verfügbaren Modellen, Skins und Animationen
  useEffect(() => {
    // Diese würden in einer realen Anwendung aus einer Ressource geladen werden
    setAvailableModels([
      'npc_villager.o3d',
      'npc_merchant.o3d',
      'npc_guard.o3d',
      'npc_wizard.o3d',
      'npc_blacksmith.o3d',
    ]);
    
    setAvailableSkins([
      'default',
      'variant1',
      'variant2',
      'special',
    ]);
    
    setAvailableAnimations([
      'idle',
      'walk',
      'talk',
      'craft',
      'combat',
    ]);
  }, []);

  // Simuliere die Generierung einer Modell-Vorschau-URL
  const generateModelPreviewUrl = (modelFile: string) => {
    setIsLoading(true);
    
    // In einer realen Anwendung würde hier eine Anfrage an einen Server oder eine Ressource erfolgen
    // Simuliere eine asynchrone Anfrage
    setTimeout(() => {
      // Einfacher Platzhalter für die Modellvorschau
      setModelPreviewUrl(`/public/placeholder.svg?model=${encodeURIComponent(modelFile)}&t=${Date.now()}`);
      setIsLoading(false);
    }, 500);
  };

  // Funktion zum Aktualisieren des Modells
  const handleModelChange = (modelFile: string) => {
    if (!editMode) return;
    
    const oldValue = localNPC.appearance?.modelFile;
    const updatedAppearance = { ...localNPC.appearance, modelFile };
    const updatedNPC = { ...localNPC, appearance: updatedAppearance };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'appearance.modelFile', oldValue);
    
    // Generiere Vorschau für das neue Modell
    generateModelPreviewUrl(modelFile);
  };

  // Funktion zum Aktualisieren des Skins
  const handleSkinChange = (skin: string) => {
    if (!editMode) return;
    
    const oldValue = localNPC.appearance?.skin;
    const updatedAppearance = { ...localNPC.appearance, skin };
    const updatedNPC = { ...localNPC, appearance: updatedAppearance };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'appearance.skin', oldValue);
  };

  // Funktion zum Hinzufügen einer Animation
  const handleAddAnimation = (animation: string) => {
    if (!editMode) return;
    
    const currentAnimations = localNPC.appearance?.animations || [];
    if (currentAnimations.includes(animation)) return; // Verhindere Duplikate
    
    const updatedAnimations = [...currentAnimations, animation];
    const updatedAppearance = { ...localNPC.appearance, animations: updatedAnimations };
    const updatedNPC = { ...localNPC, appearance: updatedAppearance };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'appearance.animations', localNPC.appearance?.animations);
  };

  // Funktion zum Entfernen einer Animation
  const handleRemoveAnimation = (animation: string) => {
    if (!editMode || !localNPC.appearance?.animations) return;
    
    const updatedAnimations = localNPC.appearance.animations.filter(a => a !== animation);
    const updatedAppearance = { ...localNPC.appearance, animations: updatedAnimations };
    const updatedNPC = { ...localNPC, appearance: updatedAppearance };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'appearance.animations', localNPC.appearance.animations);
  };

  // Manuelles Eingeben eines Modells
  const handleManualModelInput = (value: string) => {
    if (!editMode) return;
    
    const oldValue = localNPC.appearance?.modelFile;
    const updatedAppearance = { ...localNPC.appearance, modelFile: value };
    const updatedNPC = { ...localNPC, appearance: updatedAppearance };
    
    setLocalNPC(updatedNPC);
    onUpdateNPC(updatedNPC, 'appearance.modelFile', oldValue);
  };

  // Aktualisiere Vorschau
  const handleUpdatePreview = () => {
    if (localNPC.appearance?.modelFile) {
      generateModelPreviewUrl(localNPC.appearance.modelFile);
    }
  };

  return (
    <div className="space-y-6 p-4 bg-cyrus-dark-lighter rounded-md border border-cyrus-dark-lightest">
      <h2 className="text-xl font-semibold text-white mb-4">Erscheinungsbild</h2>
      
      <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
        {/* Linke Spalte: Modell-Auswahl und Eigenschaften */}
        <div className="space-y-4">
          <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
            <CardContent className="pt-6">
              <h3 className="text-md font-semibold text-white mb-3">3D-Modell</h3>
              
              <div className="space-y-4">
                <div className="space-y-2">
                  <Label htmlFor="model-file" className="text-white">Modelldatei (.o3d)</Label>
                  <div className="flex gap-2">
                    <Select 
                      value={localNPC.appearance?.modelFile || ''}
                      onValueChange={handleModelChange}
                      disabled={!editMode}
                    >
                      <SelectTrigger className="bg-cyrus-dark text-white border-cyrus-dark-lightest flex-1">
                        <SelectValue placeholder="Modell wählen" />
                      </SelectTrigger>
                      <SelectContent className="bg-cyrus-dark text-white border-cyrus-dark-lightest">
                        {availableModels.map(model => (
                          <SelectItem key={model} value={model}>{model}</SelectItem>
                        ))}
                      </SelectContent>
                    </Select>
                    
                    <Button 
                      variant="outline" 
                      className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
                      onClick={() => {/* Würde einen Datei-Browser öffnen */}}
                      disabled={!editMode}
                    >
                      <FileSearch className="h-4 w-4" />
                    </Button>
                  </div>
                </div>
                
                <div className="space-y-2">
                  <Label htmlFor="manual-model-input" className="text-white">Manueller Modellpfad</Label>
                  <div className="flex gap-2">
                    <Input
                      id="manual-model-input"
                      value={localNPC.appearance?.modelFile || ''}
                      onChange={(e) => handleManualModelInput(e.target.value)}
                      disabled={!editMode}
                      className="flex-1 bg-cyrus-dark text-white border-cyrus-dark-lightest"
                      placeholder="z.B. models/npc/custom.o3d"
                    />
                    <Button 
                      variant="outline" 
                      className="bg-cyrus-dark text-white border-cyrus-dark-lightest"
                      onClick={handleUpdatePreview}
                      disabled={!editMode || !localNPC.appearance?.modelFile}
                    >
                      <RefreshCw className={`h-4 w-4 ${isLoading ? 'animate-spin' : ''}`} />
                    </Button>
                  </div>
                </div>
                
                <div className="space-y-2">
                  <Label htmlFor="skin-select" className="text-white">Skin/Textur</Label>
                  <Select 
                    value={localNPC.appearance?.skin || 'default'}
                    onValueChange={handleSkinChange}
                    disabled={!editMode}
                  >
                    <SelectTrigger id="skin-select" className="bg-cyrus-dark text-white border-cyrus-dark-lightest w-full">
                      <SelectValue placeholder="Skin wählen" />
                    </SelectTrigger>
                    <SelectContent className="bg-cyrus-dark text-white border-cyrus-dark-lightest">
                      {availableSkins.map(skin => (
                        <SelectItem key={skin} value={skin}>{skin}</SelectItem>
                      ))}
                    </SelectContent>
                  </Select>
                </div>
              </div>
            </CardContent>
          </Card>
          
          <Card className="bg-cyrus-dark border-cyrus-dark-lightest">
            <CardContent className="pt-6">
              <h3 className="text-md font-semibold text-white mb-3">Animationen</h3>
              
              {editMode && (
                <div className="mb-4">
                  <Label htmlFor="animation-select" className="text-white text-sm mb-2 block">Animation hinzufügen</Label>
                  <div className="flex gap-2">
                    <Select 
                      onValueChange={handleAddAnimation}
                    >
                      <SelectTrigger id="animation-select" className="bg-cyrus-dark text-white border-cyrus-dark-lightest flex-1">
                        <SelectValue placeholder="Animation wählen" />
                      </SelectTrigger>
                      <SelectContent className="bg-cyrus-dark text-white border-cyrus-dark-lightest">
                        {availableAnimations.map(animation => (
                          <SelectItem key={animation} value={animation}>{animation}</SelectItem>
                        ))}
                      </SelectContent>
                    </Select>
                  </div>
                </div>
              )}
              
              <div>
                <Label className="text-white text-sm mb-2 block">Aktive Animationen</Label>
                {localNPC.appearance?.animations && localNPC.appearance.animations.length > 0 ? (
                  <ul className="space-y-1">
                    {localNPC.appearance.animations.map(animation => (
                      <li key={animation} className="flex justify-between items-center p-2 bg-cyrus-dark-lighter rounded">
                        <span className="text-white text-sm">{animation}</span>
                        {editMode && (
                          <Button
                            variant="ghost"
                            size="sm"
                            onClick={() => handleRemoveAnimation(animation)}
                            className="h-6 w-6 p-0 hover:bg-red-500/20"
                          >
                            <span className="text-red-400 text-xs">✕</span>
                          </Button>
                        )}
                      </li>
                    ))}
                  </ul>
                ) : (
                  <div className="text-center text-gray-400 p-2 bg-cyrus-dark-lighter rounded">
                    Keine Animationen zugewiesen
                  </div>
                )}
              </div>
            </CardContent>
          </Card>
        </div>
        
        {/* Rechte Spalte: Modell-Vorschau */}
        <div>
          <Card className="bg-cyrus-dark border-cyrus-dark-lightest h-full">
            <CardContent className="pt-6 h-full flex flex-col">
              <h3 className="text-md font-semibold text-white mb-3">Modell-Vorschau</h3>
              
              <div className="flex-1 bg-cyrus-dark-lighter rounded-md flex items-center justify-center overflow-hidden">
                {isLoading ? (
                  <div className="flex flex-col items-center justify-center text-gray-400">
                    <RefreshCw className="h-8 w-8 animate-spin mb-2" />
                    <span>Lade Vorschau...</span>
                  </div>
                ) : modelPreviewUrl ? (
                  <img 
                    src={modelPreviewUrl} 
                    alt="NPC Model Preview" 
                    className="max-w-full max-h-full object-contain"
                  />
                ) : (
                  <div className="text-center text-gray-400 p-4">
                    <p>Keine Modellvorschau verfügbar</p>
                    <p className="text-xs mt-1">Wählen Sie ein Modell, um eine Vorschau zu sehen</p>
                  </div>
                )}
              </div>
              
              <div className="mt-4 text-xs text-gray-400">
                <p>Modell: {localNPC.appearance?.modelFile || 'Nicht festgelegt'}</p>
                <p>Skin: {localNPC.appearance?.skin || 'Default'}</p>
                <p>Animationen: {localNPC.appearance?.animations?.join(', ') || 'Keine'}</p>
              </div>
            </CardContent>
          </Card>
        </div>
      </div>
    </div>
  );
};

export default Appearance; 