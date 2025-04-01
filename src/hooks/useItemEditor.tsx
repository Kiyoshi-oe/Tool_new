import { useState, useCallback, useMemo, useEffect } from "react";
import { FileData, LogEntry, ResourceItem } from "../types/fileTypes";
import { toast } from "sonner";
import { trackModifiedFile, trackItemChanges } from "../utils/file/fileOperations";
import { updatePropItemProperties } from "../utils/file/propItemUtils";

export interface ItemEditorProps {
  fileData: any;
  setFileData: (data: any) => void;
  selectedItem: ResourceItem | null;
  setSelectedItem: (item: ResourceItem | null) => void;
  setLogEntries: (callback: (prev: LogEntry[]) => LogEntry[]) => void;
  updateTabItem: (item: ResourceItem) => void;
  saveUndoState: () => void;
  openTabs: any[];
  setOpenTabs: React.Dispatch<React.SetStateAction<any[]>>;
}

// Lookup-Cache: Map-Objekt für schnellen Zugriff auf Items nach ID
const itemCache = new Map<string, ResourceItem>();
// Flag, ob ein Cache-Update notwendig ist
let cacheNeedsUpdate = true;

// Global Event-Handler für Item-Updates
if (typeof window !== 'undefined') {
  // Handler für PropItem-Updates
  window.addEventListener('propItemsUpdated', (event: any) => {
    const items = event.detail || [];
    
    console.log('Global ItemEditor: PropItems-Update empfangen', items.length);
    
    // ItemCache aktualisieren
    items.forEach((item: ResourceItem) => {
      if (item && item.id) {
        itemCache.set(item.id, item);
      }
    });
    
    // Cache-Update erzwingen
    cacheNeedsUpdate = true;
  });
  
  // Handler für DefineItem-Updates
  window.addEventListener('defineItemsUpdated', (event: any) => {
    const items = event.detail || [];
    
    console.log('Global ItemEditor: DefineItems-Update empfangen', items.length);
    
    // ItemCache aktualisieren
    items.forEach((item: ResourceItem) => {
      if (item && item.id) {
        itemCache.set(item.id, item);
      }
    });
    
    // Cache-Update erzwingen
    cacheNeedsUpdate = true;
  });
  
  // Handler für MdlDyna-Updates
  window.addEventListener('mdlDynaItemsUpdated', (event: any) => {
    const items = event.detail || [];
    
    console.log('Global ItemEditor: MdlDynaItems-Update empfangen', items.length);
    
    // ItemCache aktualisieren
    items.forEach((item: ResourceItem) => {
      if (item && item.id) {
        itemCache.set(item.id, item);
      }
    });
    
    // Cache-Update erzwingen
    cacheNeedsUpdate = true;
  });
}

export const useItemEditor = ({
  fileData,
  setFileData,
  selectedItem,
  setSelectedItem,
  setLogEntries,
  updateTabItem,
  saveUndoState,
  openTabs,
  setOpenTabs
}: ItemEditorProps) => {
  const [editMode, setEditMode] = useState(false);
  const [item, setItem] = useState<ResourceItem | null>(selectedItem);
  const [hasUnsavedChanges, setHasUnsavedChanges] = useState(false);
  
  // Cache für schnellen Zugriff auf Items nach ID aktualisieren
  useMemo(() => {
    if (fileData && cacheNeedsUpdate) {
      // Vorhandenen Cache beibehalten und nur mit den neuen Items aus fileData aktualisieren
      fileData.items.forEach((item: ResourceItem) => {
        if (item && item.id) {
          itemCache.set(item.id, item);
        }
      });
      cacheNeedsUpdate = false;
    }
  }, [fileData]);
  
  // Event-Listener für Item-Aktualisierungen
  useEffect(() => {
    const handleItemUpdate = (event: CustomEvent) => {
      const type = event.detail?.type;
      const items = event.detail?.items || [];
      
      console.log(`ItemEditor: Ressource-Update vom Typ ${type} empfangen`);
      
      // Prüfe, ob das aktuelle Item aktualisiert wurde
      if (selectedItem) {
        const updatedItem = items.find((item: ResourceItem) => item.id === selectedItem.id);
        if (updatedItem) {
          console.log(`ItemEditor: Update für ausgewähltes Item ${selectedItem.id} gefunden`);
          
          // Aktualisiere ausgewähltes Item
          setSelectedItem({
            ...selectedItem,
            ...updatedItem,
            // Bewahre vorhandene Daten
            data: {
              ...selectedItem.data,
              ...(updatedItem.data || {})
            }
          });
          
          // Aktualisiere item-State
          setItem(prevItem => {
            if (!prevItem) return updatedItem;
            return {
              ...prevItem,
              ...updatedItem,
              data: {
                ...prevItem.data,
                ...(updatedItem.data || {})
              }
            };
          });
          
          // Aktualisiere Tabs
          updateTabItem(updatedItem);
          
          // Aktualisiere fileData
          setFileData((prevData: any) => {
            if (!prevData || !prevData.items) return prevData;
            
            const updatedItems = prevData.items.map((item: ResourceItem) => 
              item.id === updatedItem.id ? updatedItem : item
            );
            
            return {
              ...prevData,
              items: updatedItems
            };
          });
        }
      }
    };
    
    // Event-Handler registrieren
    window.addEventListener('resourceUpdated', handleItemUpdate as EventListener);
    
    // Event-Handler entfernen
    return () => {
      window.removeEventListener('resourceUpdated', handleItemUpdate as EventListener);
    };
  }, [selectedItem, setSelectedItem, updateTabItem, setFileData]);
  
  // Funktion zum Aktualisieren eines Items
  const handleUpdateItem = useCallback((updatedItem: ResourceItem) => {
    if (!fileData || !selectedItem) return;

    // Aktualisiere das Item im fileData
    const updatedItems = fileData.items.map((item: ResourceItem) =>
      item.id === updatedItem.id ? updatedItem : item
    );

    // Aktualisiere fileData
    setFileData({
      ...fileData,
      items: updatedItems
    });

    // Aktualisiere den Tab
    updateTabItem(updatedItem);

    // Markiere Änderungen als nicht gespeichert
    setHasUnsavedChanges(true);

    // Speichere den Zustand für Undo/Redo
    saveUndoState();
  }, [fileData, selectedItem, setFileData, updateTabItem, saveUndoState]);
  
  // Aktualisiere lokalen Item-State wenn sich selectedItem ändert
  useEffect(() => {
    setItem(selectedItem);
  }, [selectedItem]);
  
  // Funktion zum Auswählen eines Items
  const handleSelectItem = useCallback((item: ResourceItem) => {
    setSelectedItem(item);
  }, [setSelectedItem]);
  
  // Funktion zum Umschalten des Edit-Modus
  const handleToggleEditMode = useCallback(() => {
    setEditMode(prev => !prev);
  }, []);

  // Cache invalidieren wenn sich fileData ändert
  useEffect(() => {
    cacheNeedsUpdate = true;
  }, [fileData]);

  // Ändere displayName ohne direkte Speicherung
  const handleDisplayNameChange = useCallback((newDisplayName: string) => {
    setItem(prevItem => ({
      ...prevItem,
      displayName: newDisplayName
    }));
    setHasUnsavedChanges(true);
    console.log(`Anzeigename im State aktualisiert: "${newDisplayName}"`);
  }, []);

  // Ändere description ohne direkte Speicherung
  const handleDescriptionChange = useCallback((newDescription: string) => {
    setItem(prevItem => ({
      ...prevItem,
      description: newDescription
    }));
    setHasUnsavedChanges(true);
    console.log(`Beschreibung im State aktualisiert`);
  }, []);

  // Funktion zum Speichern von Änderungen
  const saveChanges = useCallback(async () => {
    if (!selectedItem || !hasUnsavedChanges) return;

    try {
      // Verwende die neue Funktion zum Speichern aller Dateitypen
      await trackItemChanges(selectedItem, true);

      // Markiere Änderungen als gespeichert
      setHasUnsavedChanges(false);

      // Aktualisiere den Tab-Status
      setOpenTabs(prevTabs => prevTabs.map(tab =>
        tab.item.id === selectedItem.id
          ? { ...tab, modified: false }
          : tab
      ));
      
      // Füge Log-Eintrag hinzu
      setLogEntries(prev => [...prev, {
        timestamp: Date.now(),
        itemId: selectedItem.id,
        itemName: selectedItem.displayName || selectedItem.name,
        field: 'save',
        oldValue: '',
        newValue: 'Gespeichert'
      }]);

      toast.success(`Änderungen am Item "${selectedItem.displayName || selectedItem.name}" gespeichert`);
      return true;
    } catch (error) {
      console.error("Fehler beim Speichern der Änderungen:", error);
      toast.error(`Fehler beim Speichern: ${error.message}`);
      throw error;
    }
  }, [selectedItem, hasUnsavedChanges, setOpenTabs, setLogEntries]);

  return {
    editMode,
    item,
    hasUnsavedChanges,
    handleUpdateItem,
    handleSelectItem,
    handleToggleEditMode,
    handleDisplayNameChange,
    handleDescriptionChange,
    saveChanges
  };
};
