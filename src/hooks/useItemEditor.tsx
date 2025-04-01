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
  const [item, setItem] = useState<ResourceItem | null>(selectedItem);
  const [hasUnsavedChanges, setHasUnsavedChanges] = useState(false);
  
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
      // Speichere die Änderungen in der Datei
      await trackPropItemChanges(
        selectedItem.id,
        selectedItem.name,
        selectedItem.displayName || selectedItem.name,
        selectedItem.description || ''
      );

      // Markiere Änderungen als gespeichert
      setHasUnsavedChanges(false);

      // Aktualisiere den Tab-Status
      setOpenTabs(prevTabs => prevTabs.map(tab =>
        tab.item.id === selectedItem.id
          ? { ...tab, modified: false }
          : tab
      ));

      return true;
    } catch (error) {
      console.error("Fehler beim Speichern der Änderungen:", error);
      throw error;
    }
  }, [selectedItem, hasUnsavedChanges, setOpenTabs]);

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
