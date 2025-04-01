import { useState } from "react";
import { ResourceItem, LogEntry, FileData } from "../types/fileTypes";
import { useUndoRedo } from "./useUndoRedo";
import { useTabs } from "./useTabs";
import { useFileLoader } from "./useFileLoader";
import { useItemEditor } from "./useItemEditor";
import { toast } from "sonner";

export const useResourceState = (settings: any, setLogEntries: React.Dispatch<React.SetStateAction<LogEntry[]>>) => {
  const [selectedItem, setSelectedItem] = useState<ResourceItem | null>(null);
  
  const { 
    fileData, 
    handleLoadFile, 
    loadDefaultFiles,
    loadingStatus,
    loadProgress,
    isLoading,
    setFileData
  } = useFileLoader(settings, setLogEntries);
  
  const { undoStack, redoStack, saveUndoState, handleUndo, handleRedo } = useUndoRedo(
    fileData,
    selectedItem,
    setFileData,
    setSelectedItem
  );
  
  const { 
    openTabs, 
    handleCloseTab, 
    handleSelectTab, 
    addTab, 
    updateTabItem,
    saveCurrentTab,
    saveAllTabs,
    setOpenTabs
  } = useTabs(
    selectedItem,
    setSelectedItem
  );
  
  const { 
    editMode, 
    handleUpdateItem, 
    handleSelectItem, 
    handleToggleEditMode,
    handleEffectsChange,
    saveChanges
  } = useItemEditor({
    fileData,
    setFileData,
    selectedItem,
    setSelectedItem,
    setLogEntries,
    updateTabItem,
    saveUndoState,
    openTabs,
    setOpenTabs
  });
  
  // Extend handleSelectItem to also add the tab
  const handleSelectItemWithTab = (item: ResourceItem, showSettings: boolean, showToDoPanel: boolean) => {
    handleSelectItem(item);
    if (!showSettings && !showToDoPanel) {
      addTab(item);
    }
  };
  
  // Erweitere die Funktionalität zum Speichern des aktuellen Tabs
  const saveCurrentTabWithEditor = async () => {
    if (!selectedItem) {
      toast.warning("Kein Tab ausgewählt zum Speichern");
      return;
    }
    
    try {
      const saved = await saveCurrentTab({ saveChanges });
      if (saved) {
        // Log-Eintrag erstellen
        if (settings.enableLogging) {
          const newLogEntry: LogEntry = {
            timestamp: Date.now(),
            itemId: selectedItem.id,
            itemName: selectedItem.name,
            field: "file-save",
            oldValue: "",
            newValue: `Tab gespeichert um ${new Date().toLocaleTimeString()}`
          };
          setLogEntries(prev => [newLogEntry, ...prev]);
        }
      }
    } catch (error) {
      console.error("Fehler beim Speichern des Tabs:", error);
      toast.error("Fehler beim Speichern des Tabs");
    }
  };
  
  // Erweitere die Funktionalität zum Speichern aller Tabs
  const saveAllTabsWithEditor = async () => {
    if (openTabs.length === 0) {
      toast.warning("Keine Tabs offen zum Speichern");
      return;
    }
    
    try {
      const saved = await saveAllTabs({ saveChanges });
      if (saved) {
        // Log-Eintrag erstellen
        if (settings.enableLogging) {
          const newLogEntry: LogEntry = {
            timestamp: Date.now(),
            itemId: "tabs-save-all",
            itemName: "Alle Tabs",
            field: "file-save-all",
            oldValue: "",
            newValue: `${openTabs.length} Tabs gespeichert um ${new Date().toLocaleTimeString()}`
          };
          setLogEntries(prev => [newLogEntry, ...prev]);
        }
      }
    } catch (error) {
      console.error("Fehler beim Speichern der Tabs:", error);
      toast.error("Fehler beim Speichern der Tabs");
    }
  };
  
  return {
    fileData,
    selectedItem,
    setSelectedItem,
    undoStack,
    redoStack,
    openTabs,
    editMode,
    handleUndo,
    handleRedo,
    handleLoadFile,
    loadDefaultFiles,
    loadingStatus,
    loadProgress,
    isLoading,
    handleSelectItem: handleSelectItemWithTab,
    handleUpdateItem,
    handleCloseTab,
    handleSelectTab,
    handleToggleEditMode,
    handleEffectsChange,
    saveCurrentTab: saveCurrentTabWithEditor,
    saveAllTabs: saveAllTabsWithEditor
  };
};
