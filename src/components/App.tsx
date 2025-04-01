import { useState, useEffect } from "react";
import { ResourceItem, LogEntry } from "../types/fileTypes";
import Sidebar from "./Sidebar";
import MainContent from "./main/MainContent";
import FileUploadModal from "./FileUploadModal";
import LogModal from "./LogModal";
import ChangelogModal from "./ChangelogModal";
import Tabs from "./Tabs";
import { useResourceState } from "../hooks/useResourceState";
import { Toaster } from "sonner";
import Toolbar from "./Toolbar";
import { ResourceProvider } from "./ResourceEditor";

function App() {
  const { 
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
    handleSelectItem,
    handleUpdateItem,
    handleCloseTab,
    handleSelectTab,
    handleToggleEditMode,
    loadDefaultFiles,
    loadingStatus,
    loadProgress,
    isLoading,
    handleEffectsChange,
    saveCurrentTab,
    saveAllTabs
  } = useResourceState(settings, setLogEntries);

  return (
    <ResourceProvider handleEffectsChange={handleEffectsChange}>
      <div className={`app-container h-screen flex flex-col font-${settings.fontFamily} ${currentTheme.name}`}>
        {/* ... existing content ... */}
      </div>
    </ResourceProvider>
  );
}

export default App; 