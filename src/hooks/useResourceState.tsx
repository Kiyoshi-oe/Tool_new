import { useState } from "react";
import { ResourceItem, LogEntry } from "../types/fileTypes";
import { useUndoRedo } from "./useUndoRedo";
import { useTabs } from "./useTabs";
import { useFileLoader } from "./useFileLoader";
import { useItemEditor } from "./useItemEditor";
import { ensurePropItemConsistency, saveAllModifiedFiles } from "../utils/file/fileOperations";
import { toast } from "sonner";

export const useResourceState = (settings: any, setLogEntries: React.Dispatch<React.SetStateAction<LogEntry[]>>) => {
  const [selectedItem, setSelectedItem] = useState<ResourceItem | null>(null);
  
  const { 
    fileData, 
    handleLoadFile, 
    loadDefaultFiles,
    loadingStatus,
    loadProgress,
    isLoading
  } = useFileLoader(settings, setLogEntries);
  
  const setFileData = (newData: any) => {
    console.log("Warnung: setFileData wird direkt aufgerufen, sollte über handleLoadFile gehen");
    // Tut nichts, da fileData jetzt direkt von useFileLoader verwaltet wird
  };
  
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
    saveAllTabs
  } = useTabs(
    selectedItem,
    setSelectedItem
  );
  
  const { editMode, handleUpdateItem, handleSelectItem, handleToggleEditMode } = useItemEditor({
    fileData,
    setFileData,
    selectedItem,
    setSelectedItem,
    settings,
    setLogEntries,
    updateTabItem,
    saveUndoState
  });
  
  // Extend handleSelectItem to also add the tab
  const handleSelectItemWithTab = (item: ResourceItem, showSettings: boolean, showToDoPanel: boolean) => {
    handleSelectItem(item, showSettings, showToDoPanel);
    if (!showSettings && !showToDoPanel) {
      addTab(item);
    }
  };
  
  // Erweitere die Funktionalität zum Speichern, um sicherzustellen, dass alle Änderungen konsistent sind
  const saveCurrentTabWithSync = () => {
    // Zuerst die Konsistenzprüfung durchführen
    if (fileData) {
      ensurePropItemConsistency(fileData);
    }
    
    // Dann den aktuellen Tab speichern
    return saveCurrentTab(fileData);
  };
  
  // Erweitere die Funktionalität zum Speichern aller Tabs, um sicherzustellen, dass alle Änderungen konsistent sind
  const saveAllTabsWithSync = () => {
    // Zuerst die Konsistenzprüfung durchführen
    if (fileData) {
      ensurePropItemConsistency(fileData);
    }
    
    // Dann alle Tabs speichern
    return saveAllTabs(fileData);
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
    saveCurrentTab: saveCurrentTabWithSync,
    saveAllTabs: saveAllTabsWithSync
  };
};
