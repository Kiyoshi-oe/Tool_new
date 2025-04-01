import { useState, useCallback, useMemo, useEffect } from "react";
import { FileData, LogEntry, ResourceItem } from "../types/fileTypes";
import { toast } from "sonner";
import { trackModifiedFile, trackPropItemChanges } from "../utils/file/fileOperations";
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
  
  // Cache für schnellen Zugriff auf Items nach ID aktualisieren
  useMemo(() => {
    if (fileData && cacheNeedsUpdate) {
      itemCache.clear();
      fileData.items.forEach(item => {
        itemCache.set(item.id, item);
      });
      cacheNeedsUpdate = false;
    }
  }, [fileData]);
  
  // Performance-Optimierung: handleUpdateItem memoisieren
  const handleUpdateItem = async (updatedItem: any) => {
    console.log('Aktualisiere Item:', updatedItem);
    
    // Kombiniere das ausgewählte Item mit den aktualisierten Werten
    const mergedItem = {
      ...selectedItem,
      ...updatedItem
    };
    
    // Aktualisiere den Namen und die Beschreibung in PropItem.txt.txt, falls geändert
    if (
      (updatedItem.displayName !== undefined && updatedItem.displayName !== selectedItem?.displayName) ||
      (updatedItem.description !== undefined && updatedItem.description !== selectedItem?.description)
    ) {
      console.log('PropItem Informationen ändern sich, aktualisiere PropItem.txt.txt');
      
      try {
        // Verwende updatePropItemProperties, um die Änderungen zu verfolgen
        const propItemUpdated = await updatePropItemProperties(
          mergedItem,
          updatedItem.displayName || selectedItem?.displayName || mergedItem.name,
          updatedItem.description || selectedItem?.description || ''
        );
        
        console.log('PropItem Eigenschaften aktualisiert:', propItemUpdated);
      } catch (error) {
        console.error('Fehler beim Aktualisieren der PropItem Eigenschaften:', error);
      }
    }
    
    // Aktualisiere das Item im fileData
    if (fileData && fileData.items) {
      // Finde den Index des zu aktualisierenden Items
      const itemIndex = fileData.items.findIndex((item: any) => item.id === mergedItem.id);
      
      if (itemIndex !== -1) {
        // Erstelle eine Kopie des fileData
        const updatedFileData = { ...fileData };
        
        // Erstelle eine Kopie des Items-Arrays
        updatedFileData.items = [...fileData.items];
        
        // Aktualisiere das Item
        updatedFileData.items[itemIndex] = mergedItem;
        
        // Setze das aktualisierte fileData
        setFileData(updatedFileData);
        
        // Aktualisiere auch das ausgewählte Item
        setSelectedItem(mergedItem);
        
        console.log('Item im fileData aktualisiert:', mergedItem);
        
        // Markiere die Datei als geändert
        trackModifiedFile('Spec_Item.txt', JSON.stringify({
          ...updatedFileData,
          originalContent: fileData.originalContent
        }));
        
        console.log('Datei als modifiziert markiert');
      } else {
        console.warn('Item nicht im fileData gefunden:', mergedItem.id);
      }
    } else {
      console.warn('Kein fileData oder items vorhanden');
    }
  };
  
  // Performance-Optimierung: handleSelectItem memoisieren
  const handleSelectItem = useCallback((item: ResourceItem, showSettings: boolean, showToDoPanel: boolean) => {
    if (showSettings || showToDoPanel) return;
    
    // Vor der Auswahl den UndoState speichern
    saveUndoState();
    
    // Performance-Optimierung: Wenn das Item bereits ausgewählt ist, nichts tun
    if (selectedItem && selectedItem.id === item.id) return;
    
    // Priorität mit queueMicrotask erhöhen
    queueMicrotask(() => {
      setSelectedItem(item);
    });
  }, [selectedItem, setSelectedItem, saveUndoState]);
  
  // Performance-Optimierung: handleToggleEditMode memoisieren
  const handleToggleEditMode = useCallback(() => {
    setEditMode(prevMode => {
      const newMode = !prevMode;
      toast.info(newMode ? "Switched to Edit mode" : "Switched to View mode");
      return newMode;
    });
  }, []);

  // Cache invalidieren wenn sich fileData ändert
  useEffect(() => {
    cacheNeedsUpdate = true;
  }, [fileData]);

  // Ändere displayName und speichere die Änderung
  const handleDisplayNameChange = async (newDisplayName: string) => {
    if (!selectedItem) return;
    setSelectedItem({ ...selectedItem, displayName: newDisplayName });
    console.log("Speichere den neuen Display-Namen:", newDisplayName);
    try {
      await trackPropItemChanges(
        selectedItem.id,
        selectedItem.name,
        newDisplayName,
        selectedItem.description || ''
      );
      console.log("PropItem-Änderungen erfolgreich gespeichert");
    } catch (error) {
      console.error("Fehler beim Speichern der PropItem-Änderungen:", error);
    }
  };

  // Ändere description und speichere die Änderung
  const handleDescriptionChange = async (newDescription: string) => {
    if (!selectedItem) return;
    setSelectedItem({ ...selectedItem, description: newDescription });
    console.log("Speichere die neue Beschreibung:", newDescription);
    
    try {
      // Die Funktion trackPropItemChanges wird aufgerufen, um PropItem.txt.txt zu aktualisieren
      await trackPropItemChanges(
        selectedItem.id,
        selectedItem.name,
        selectedItem.displayName || selectedItem.name,
        newDescription
      );
      console.log("PropItem-Änderungen erfolgreich gespeichert");
    } catch (error) {
      console.error("Fehler beim Speichern der PropItem-Änderungen:", error);
    }
  };

  return {
    editMode,
    handleUpdateItem,
    handleSelectItem,
    handleToggleEditMode,
    handleDisplayNameChange,
    handleDescriptionChange
  };
};
