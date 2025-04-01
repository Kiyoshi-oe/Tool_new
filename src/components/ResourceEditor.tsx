import { useState, useEffect, memo, useMemo, lazy, Suspense, Component, ErrorInfo, useRef } from "react";
import { ResourceItem, EffectData } from "../types/fileTypes";
import { trackModifiedFile, trackItemChanges, formatItemIconValue } from "../utils/file/fileOperations";
import { updateItemIdInDefine } from "../utils/file/defineItemParser";
import { updateModelFileNameInMdlDyna } from "../utils/file/mdlDynaParser";
import { toast } from "sonner";
import { Button } from "@/components/ui/button";

// Error Boundary Komponente für Fehlerbehandlung bei dynamischen Imports
class ErrorBoundary extends Component<
  { fallback: React.ReactNode; children: React.ReactNode },
  { hasError: boolean; error: Error | null }
> {
  constructor(props: { fallback: React.ReactNode; children: React.ReactNode }) {
    super(props);
    this.state = { hasError: false, error: null };
  }

  static getDerivedStateFromError(error: Error) {
    return { hasError: true, error };
  }

  componentDidCatch(error: Error, errorInfo: ErrorInfo) {
    console.error("Component error caught:", error, errorInfo);
  }

  render() {
    if (this.state.hasError) {
      return this.props.fallback;
    }
    return this.props.children;
  }
}

// Robustere Import-Funktion mit mehreren Fallbacks und feingranularer Fehlerbehandlung
const robustImport = async (path: string, componentName: string) => {
  try {
    console.log(`Attempting to load ${componentName} from ${path}`);
    // Erster Versuch mit .tsx
    return await import(/* @vite-ignore */ `${path}.tsx`);
  } catch (error) {
    console.error(`Error loading ${componentName} with .tsx extension:`, error);
    try {
      // Zweiter Versuch ohne Erweiterung
      console.log(`Retry loading ${componentName} without extension`);
      return await import(/* @vite-ignore */ path);
    } catch (retryError) {
      console.error(`Failed on second attempt for ${componentName}:`, retryError);
      
      // Letzte Rettung: Wir liefern ein Fallback-Objekt mit einer leeren Komponente zurück,
      // um die Anwendung am Laufen zu halten
      console.warn(`Using fallback for ${componentName}`);
      return {
        default: (props: any) => (
          <FallbackSection 
            title={componentName} 
            error={retryError instanceof Error ? retryError : new Error(`Failed to load ${componentName}`)} 
          />
        )
      };
    }
  }
};

// Definiere die Komponenten mit der robusteren Import-Methode
const GeneralSection = lazy(() => robustImport("./resource-editor/GeneralSection", "General"));
const StatsSection = lazy(() => robustImport("./resource-editor/StatsSection", "Stats"));
const SetEffectsSection = lazy(() => robustImport("./resource-editor/SetEffectsSection", "Set Effects"));
const PropertiesSection = lazy(() => robustImport("./resource-editor/PropertiesSection", "Properties"));
const WeaponPropertiesSection = lazy(() => robustImport("./resource-editor/WeaponPropertiesSection", "Weapon Properties"));
const ResistancesSection = lazy(() => robustImport("./resource-editor/ResistancesSection", "Resistances"));
const VisualPropertiesSection = lazy(() => robustImport("./resource-editor/VisualPropertiesSection", "Visual Properties"));
const SoundEffectsSection = lazy(() => robustImport("./resource-editor/SoundEffectsSection", "Sound Effects"));

// Fallback für Fehler in Sektionen
const FallbackSection = ({ title, error }: { title: string, error: Error }) => (
  <div className="mb-6 p-4 border border-red-500 rounded-md bg-red-100 dark:bg-red-900/20">
    <h2 className="text-red-600 dark:text-red-400 text-lg font-semibold mb-2">{title} (Fehler beim Laden)</h2>
    <p className="text-sm text-red-500">Die Komponente konnte nicht geladen werden. Fehlermeldung: {error.message}</p>
  </div>
);

// Loading-Fallback für Suspense
const SectionLoader = () => (
  <div className="animate-pulse my-4 p-4 border border-gray-300 rounded-md bg-gray-100 dark:bg-gray-800 dark:border-gray-700">
    <div className="h-6 w-1/4 bg-gray-300 dark:bg-gray-700 rounded mb-4"></div>
    <div className="space-y-2">
      <div className="h-4 bg-gray-300 dark:bg-gray-700 rounded w-3/4"></div>
      <div className="h-4 bg-gray-300 dark:bg-gray-700 rounded"></div>
      <div className="h-4 bg-gray-300 dark:bg-gray-700 rounded w-5/6"></div>
    </div>
  </div>
);

interface ResourceEditorProps {
  item: ResourceItem;
  onUpdateItem: (updatedItem: ResourceItem, field?: string, oldValue?: any) => void;
  editMode?: boolean;
}

// Performance-Optimierung: Memoized Editor-Komponente
const ResourceEditor = memo(({ item, onUpdateItem, editMode = false }: ResourceEditorProps) => {
  const [localItem, setLocalItem] = useState<ResourceItem>(item);
  const [hasUnsavedChanges, setHasUnsavedChanges] = useState(false);
  const editorRef = useRef<HTMLDivElement>(null);
  
  // Aktualisiere localItem wenn sich das übergebene Item ändert
  useEffect(() => {
    setLocalItem(item);
  }, [item]);

  // Registriere Event-Listener für Ressourcen-Updates
  useEffect(() => {
    const handleResourceUpdate = (event: CustomEvent) => {
      const { type, items } = event.detail;
      
      // Prüfe, ob die Aktualisierung für dieses Item relevant ist
      const updatedItem = items.find((item: any) => item.id === localItem.id);
      if (updatedItem) {
        console.log(`ResourceEditor: Update für Item ${localItem.id} empfangen`, updatedItem);
        
        // Aktualisiere den lokalen State ohne Änderungsstatus zu setzen
        setLocalItem(prevItem => ({
          ...prevItem,
          ...updatedItem,
          // Bewahre vorhandene Daten, wenn diese nicht im Update enthalten sind
          data: {
            ...prevItem.data,
            ...(updatedItem.data || {})
          }
        }));
        
        // Benachrichtigung anzeigen
        toast.success(`Item "${localItem.displayName || localItem.name}" wurde aktualisiert`);
      }
    };
    
    // Event-Listener hinzufügen
    const editorElement = editorRef.current;
    if (editorElement) {
      editorElement.addEventListener('resourceUpdated', handleResourceUpdate as EventListener);
    }
    
    // Event-Listener entfernen beim Aufräumen
    return () => {
      if (editorElement) {
        editorElement.removeEventListener('resourceUpdated', handleResourceUpdate as EventListener);
      }
    };
  }, [localItem.id, localItem.displayName, localItem.name]);

  // Funktion zum Speichern der Änderungen
  const handleSave = async () => {
    try {
      if (hasUnsavedChanges) {
        // Verwende die neue einheitliche Funktion zum Speichern aller Änderungen
        await trackItemChanges(localItem, true);
        
        // Aktualisiere den Parent-State
        onUpdateItem(localItem);
        
        // Setze den Änderungsstatus zurück
        setHasUnsavedChanges(false);
        
        console.log("Änderungen erfolgreich gespeichert");
        
        // Erfolgsbenachrichtigung
        toast.success(`Änderungen am Item "${localItem.displayName || localItem.name}" gespeichert`);
      }
    } catch (error) {
      console.error("Fehler beim Speichern der Änderungen:", error);
      toast.error(`Fehler beim Speichern: ${error.message}`);
    }
  };

  // Funktion zum Verarbeiten von Änderungen ohne direkte Speicherung
  const handleDataChange = useMemo(() => {
    return (field: string, value: string | number | boolean) => {
      // If not in edit mode, don't allow changes
      if (!editMode) {
        console.log('Änderungen im View-Modus nicht erlaubt');
        return;
      }

      let updatedItem: ResourceItem = { ...localItem };

      // Aktualisiere das entsprechende Feld
      if (field === 'displayName') {
        updatedItem = {
          ...localItem,
          displayName: value as string,
          // Aktualisiere auch das entsprechende Feld im fields-Objekt
          fields: {
            ...localItem.fields,
            specItem: {
              ...localItem.fields?.specItem,
              displayName: value as string
            }
          }
        };
        console.log(`Anzeigename aktualisiert: "${value}"`);
      } else if (field === 'description') {
        updatedItem = {
          ...localItem,
          description: value as string,
          // Aktualisiere auch das entsprechende Feld im fields-Objekt
          fields: {
            ...localItem.fields,
            specItem: {
              ...localItem.fields?.specItem,
              description: value as string
            }
          }
        };
        console.log(`Beschreibung aktualisiert`);
      } else if (field === 'define') {
        // Spezialfall für Define im Spec_Item und DefineItem
        updatedItem = {
          ...localItem,
          fields: {
            ...localItem.fields,
            specItem: {
              ...localItem.fields?.specItem,
              define: value as string
            }
          }
        };
        console.log(`Define aktualisiert: "${value}"`);
      } else if (field === 'itemIcon') {
        // Spezialfall für Item Icon, erfordert dreifache Anführungszeichen in der Spec_Item.txt
        // Wir verwenden hier immer die formatItemIconValue-Funktion, um konsistenz zu gewährleisten
        const formattedValue = formatItemIconValue(value as string);
        updatedItem = {
          ...localItem,
          fields: {
            ...localItem.fields,
            specItem: {
              ...localItem.fields?.specItem,
              itemIcon: formattedValue
            }
          }
        };
        console.log(`Item Icon aktualisiert: "${formattedValue}"`);
      } else if (field === 'fileName' || field === 'modelFile') {
        // Spezialfall für Dateinamen in MdlDyna
        const fileName = value as string;
        updatedItem = {
          ...localItem,
          modelFile: fileName,
          fields: {
            ...localItem.fields,
            mdlDyna: {
              ...localItem.fields?.mdlDyna,
              fileName: fileName
            }
          }
        };
        console.log(`Modell-Datei aktualisiert: "${fileName}"`);
      } else {
        // Für andere Felder, aktualisiere data
        updatedItem = {
          ...localItem,
          data: {
            ...localItem.data,
            [field]: value
          }
        };
      }

      // Aktualisiere den lokalen State
      setLocalItem(updatedItem);
      setHasUnsavedChanges(true);

      // Benachrichtige den Parent über die Änderungen
      onUpdateItem(updatedItem);
    };
  }, [localItem, editMode, onUpdateItem]);
  
  /**
   * Verwende die importierte formatItemIconValue-Funktion aus fileOperations.ts
   * Diese Funktion wurde hier entfernt und durch den Import ersetzt
   */
  
  // Performance-Optimierung: Memoized handleEffectChange
  const handleEffectChange = useMemo(() => {
    return (index: number, field: 'type' | 'value', value: string | number) => {
      // If not in edit mode, don't allow changes
      if (!editMode) return;
      
      const updatedEffects = [...localItem.effects];
      
      // Store old effect for logging
      const oldEffect = updatedEffects[index] ? { ...updatedEffects[index] } : null;
      
      if (index >= updatedEffects.length) {
        // Add a new effect if we're editing beyond current array length
        updatedEffects.push({ type: field === 'type' ? value as string : '', value: field === 'value' ? value : '' });
      } else {
        // Update existing effect
        updatedEffects[index] = {
          ...updatedEffects[index],
          [field]: value
        };
      }
      
      const updatedItem = {
        ...localItem,
        effects: updatedEffects
      };
      
      // Track effects modification in defineItem.h
      trackModifiedFile("defineItem.h", `Effect ${index} ${field} updated for item ${localItem.id}`);
      
      setLocalItem(updatedItem);
      onUpdateItem(updatedItem, `effect_${index}_${field}`, oldEffect ? oldEffect[field] : null);
    };
  }, [localItem, editMode, onUpdateItem]);
  
  // Performance-Optimierung: Memoized visageWeight
  // Analysiere das Item, um zu entscheiden, welche Sektionen gezeigt werden sollen
  const { showWeaponProps, showResistances, showVisualProps, showSoundEffects } = useMemo(() => {
    // Analyse des Items für bedingte Rendering-Entscheidungen
    const itemType = localItem.data?.dwItemKind;
    const isWeapon = itemType === "IK_WEAPON";
    const hasResistances = localItem.data?.dwAddAbility || localItem.data?.dwAbnormalKind;
    const hasVisuals = localItem.data?.dwItemKind1 || localItem.data?.dwItemLV;
    const hasSounds = localItem.data?.dwSndAttack1 || localItem.data?.dwSndAttack2;
    
    return {
      showWeaponProps: isWeapon,
      showResistances: hasResistances,
      showVisualProps: hasVisuals,
      showSoundEffects: hasSounds
    };
  }, [localItem.data]);
  
  return (
    <div 
      ref={editorRef} 
      className="flex-1 overflow-y-auto p-4"
      data-resource-editor
      data-resource-type={getResourceType(localItem)}
      data-item-id={localItem.id}
    >
      <ErrorBoundary fallback={<FallbackSection title="General" error={new Error("Komponente konnte nicht gerendert werden")} />}>
        <Suspense fallback={<SectionLoader />}>
          <GeneralSection 
            localItem={localItem}
            editMode={editMode}
            handleDataChange={handleDataChange}
          />
        </Suspense>
      </ErrorBoundary>
      
      <ErrorBoundary fallback={<FallbackSection title="Stats" error={new Error("Komponente konnte nicht gerendert werden")} />}>
        <Suspense fallback={<SectionLoader />}>
          <StatsSection 
            localItem={localItem}
            editMode={editMode}
            handleEffectChange={handleEffectChange}
          />
        </Suspense>
      </ErrorBoundary>
      
      <ErrorBoundary fallback={<FallbackSection title="Properties" error={new Error("Komponente konnte nicht gerendert werden")} />}>
        <Suspense fallback={<SectionLoader />}>
          <PropertiesSection 
            localItem={localItem}
            editMode={editMode}
            handleDataChange={handleDataChange}
          />
        </Suspense>
      </ErrorBoundary>
      
      {showWeaponProps && (
        <ErrorBoundary fallback={<FallbackSection title="Weapon Properties" error={new Error("Komponente konnte nicht gerendert werden")} />}>
          <Suspense fallback={<SectionLoader />}>
            <WeaponPropertiesSection 
              localItem={localItem}
              editMode={editMode}
              handleDataChange={handleDataChange}
            />
          </Suspense>
        </ErrorBoundary>
      )}
      
      {showResistances && (
        <ErrorBoundary fallback={<FallbackSection title="Resistances" error={new Error("Komponente konnte nicht gerendert werden")} />}>
          <Suspense fallback={<SectionLoader />}>
            <ResistancesSection 
              localItem={localItem}
              editMode={editMode}
              handleDataChange={handleDataChange}
            />
          </Suspense>
        </ErrorBoundary>
      )}
      
      {showSoundEffects && (
        <ErrorBoundary fallback={<FallbackSection title="Sound Effects" error={new Error("Komponente konnte nicht gerendert werden")} />}>
          <Suspense fallback={<SectionLoader />}>
            <SoundEffectsSection 
              localItem={localItem}
              editMode={editMode}
              handleDataChange={handleDataChange}
            />
          </Suspense>
        </ErrorBoundary>
      )}
      
      {showVisualProps && (
        <ErrorBoundary fallback={<FallbackSection title="Visual Properties" error={new Error("Komponente konnte nicht gerendert werden")} />}>
          <Suspense fallback={<SectionLoader />}>
            <VisualPropertiesSection 
              localItem={localItem}
              editMode={editMode}
              handleDataChange={handleDataChange}
            />
          </Suspense>
        </ErrorBoundary>
      )}
      
      <ErrorBoundary fallback={<FallbackSection title="Set Effects" error={new Error("Komponente konnte nicht gerendert werden")} />}>
        <Suspense fallback={<SectionLoader />}>
          <SetEffectsSection item={localItem} />
        </Suspense>
      </ErrorBoundary>
      
      <div className="flex justify-between items-center">
        <h1 className="text-2xl font-bold text-cyrus-blue">
          {localItem.displayName || localItem.name || 'Unnamed Item'}
        </h1>
        {hasUnsavedChanges && (
          <Button onClick={handleSave} className="bg-cyrus-blue hover:bg-cyrus-blue-dark">
            Save Changes
          </Button>
        )}
      </div>
    </div>
  );
});

/**
 * Bestimmt den Ressourcentyp eines Items basierend auf seinen Eigenschaften
 */
const getResourceType = (item: ResourceItem): string => {
  if (item.id.includes('IDS_PROPITEM_TXT_')) {
    return 'propItem';
  } else if (item.id && item.effects && Array.isArray(item.effects)) {
    return 'defineItem';
  } else if (item.modelFile || (item.fields?.mdlDyna?.fileName)) {
    return 'mdlDyna';
  } else {
    return 'unknown';
  }
};

// Display name für bessere Debug-Erfahrung
ResourceEditor.displayName = 'ResourceEditor';

export default ResourceEditor;
