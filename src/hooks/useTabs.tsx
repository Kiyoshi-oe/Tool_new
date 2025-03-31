import { useState, useRef, useCallback, useMemo, useEffect } from "react";
import { ResourceItem } from "../types/fileTypes";
import { getModifiedFiles, saveAllModifiedFiles, ensurePropItemConsistency } from "../utils/file/fileOperations";
import { toast } from "sonner";

interface TabItem {
  id: string;
  item: ResourceItem;
  isTemporary: boolean;
  modified: boolean;
}

// Map für schnellen ID-basierten Zugriff auf Tabs
const tabCache = new Map<string, TabItem>();

export const useTabs = (
  selectedItem: ResourceItem | null,
  setSelectedItem: React.Dispatch<React.SetStateAction<ResourceItem | null>>
) => {
  const [openTabs, setOpenTabs] = useState<TabItem[]>([]);
  const lastClickTime = useRef<{ [key: string]: number }>({});
  const doubleClickThreshold = 300; // ms
  
  // Cache für schnellen Zugriff aktualisieren
  useMemo(() => {
    // Cache zurücksetzen wenn sich openTabs ändert
    tabCache.clear();
    openTabs.forEach(tab => {
      tabCache.set(tab.id, tab);
    });
  }, [openTabs]);
  
  // Performance-Optimierung: addTab mit useCallback memoisieren
  const addTab = useCallback((item: ResourceItem) => {
    // Überspringe null oder undefined items
    if (!item || !item.id) return;
    
    const now = Date.now();
    const lastClick = lastClickTime.current[item.id] || 0;
    const isDoubleClick = now - lastClick < doubleClickThreshold;
    
    // Update the last click time
    lastClickTime.current[item.id] = now;
    
    setOpenTabs(prevTabs => {
      // Performance-Optimierung: Schneller Tab-Lookup mittels tabCache
      const existingTab = tabCache.get(item.id);
      const tabIndex = existingTab ? prevTabs.findIndex(tab => tab.id === item.id) : -1;
      
      if (tabIndex >= 0) {
        // Wenn Tab existiert und Doppelklick erfolgt: Fix machen
        if (isDoubleClick && prevTabs[tabIndex].isTemporary) {
          const updatedTabs = [...prevTabs];
          updatedTabs[tabIndex] = {
            ...updatedTabs[tabIndex],
            isTemporary: false
          };
          
          // Cache aktualisieren
          tabCache.set(item.id, updatedTabs[tabIndex]);
          
          return updatedTabs;
        }
        return prevTabs;
      }
      
      // Temporäre Tabs schließen bevor neuer Tab geöffnet wird
      const filteredTabs = prevTabs.filter(tab => !tab.isTemporary);
      
      // Neuen Tab hinzufügen, standardmäßig temporär außer bei Doppelklick
      const newTab = { 
        id: item.id, 
        item,
        isTemporary: !isDoubleClick,
        modified: false
      };
      
      // Cache aktualisieren
      tabCache.set(item.id, newTab);
      
      return [...filteredTabs, newTab];
    });
  }, []);
  
  // Performance-Optimierung: updateTabItem mit useCallback memoisieren
  const updateTabItem = useCallback((item: ResourceItem) => {
    if (!item || !item.id) return;
    
    // Performance-Optimierung: Prüfen ob der Tab existiert
    const existingTab = tabCache.get(item.id);
    if (!existingTab) return;
    
    setOpenTabs(prevTabs => {
      // Performance-Optimierung: Direkte Array-Manipulation
      const updatedTabs = [...prevTabs];
      const tabIndex = updatedTabs.findIndex(tab => tab.id === item.id);
      
      if (tabIndex >= 0) {
        const updatedTab = {
          ...updatedTabs[tabIndex],
          item,
          modified: true
        };
        updatedTabs[tabIndex] = updatedTab;
        
        // Cache aktualisieren
        tabCache.set(item.id, updatedTab);
        
        return updatedTabs;
      }
      
      return prevTabs;
    });
  }, []);
  
  // Performance-Optimierung: handleCloseTab mit useCallback memoisieren
  const handleCloseTab = useCallback((id: string) => {
    if (!id) return;
    
    setOpenTabs(prevTabs => {
      // Performance-Optimierung: Cache bereinigen
      tabCache.delete(id);
      
      const newTabs = prevTabs.filter(tab => tab.id !== id);
      
      // Wenn aktiver Tab geschlossen wird, anderen selektieren
      if (selectedItem && selectedItem.id === id) {
        const lastTab = newTabs[newTabs.length - 1];
        if (lastTab) {
          // Asynchrone State-Aktualisierung für bessere Reaktionsfähigkeit
          queueMicrotask(() => {
            setSelectedItem(lastTab.item);
          });
        } else {
          queueMicrotask(() => {
            setSelectedItem(null);
          });
        }
      }
      
      return newTabs;
    });
  }, [selectedItem, setSelectedItem]);
  
  // Performance-Optimierung: handleSelectTab mit useCallback memoisieren
  const handleSelectTab = useCallback((id: string) => {
    if (!id) return;
    
    // Performance-Optimierung: Direkt aus Cache lesen
    const selectedTab = tabCache.get(id);
    
    if (selectedTab) {
      // Vermeiden unnötiger Re-Selektierungen
      if (selectedItem && selectedItem.id === id) return;
      
      // Asynchrone State-Aktualisierung für bessere Reaktionsfähigkeit
      queueMicrotask(() => {
        setSelectedItem(selectedTab.item);
      });
      
      // Wenn der ausgewählte Tab nicht temporär ist, temporäre Tabs schließen
      if (!selectedTab.isTemporary) {
        setOpenTabs(prevTabs => {
          // Alle temporären Tabs außer den aktiven filtern
          return prevTabs.filter(tab => !tab.isTemporary || tab.id === id);
        });
      }
    }
  }, [selectedItem, setSelectedItem]);
  
  // Tab speichern
  const saveCurrentTab = useCallback((fileData: any) => {
    // Sicherstellen, dass sowohl Spec_Item.txt als auch propItem.txt.txt aktualisiert werden
    if (selectedItem && fileData) {
      ensurePropItemConsistency(fileData);
      
      // Anzeige für den Benutzer
      const modifiedFiles = getModifiedFiles();
      const specItemModified = modifiedFiles.some(f => f.name.toLowerCase().includes('spec_item'));
      const propItemModified = modifiedFiles.some(f => f.name.toLowerCase().includes('propitem'));
      
      if (specItemModified && propItemModified) {
        console.log("Beide Dateien (Spec_Item.txt und propItem.txt.txt) werden gespeichert");
      } else if (specItemModified) {
        console.log("Nur Spec_Item.txt wird gespeichert");
      } else if (propItemModified) {
        console.log("Nur propItem.txt.txt wird gespeichert");
      }
      
      // Speichern
      toast.promise(saveAllModifiedFiles(), {
        loading: "Speichere aktuellen Tab...",
        success: `Tab ${selectedItem.name || selectedItem.id} gespeichert`,
        error: "Fehler beim Speichern des Tabs"
      });
      
      // Tab als nicht mehr modifiziert markieren nach dem Speichern
      setOpenTabs(prevTabs => {
        const tabIndex = prevTabs.findIndex(tab => selectedItem && tab.item.id === selectedItem.id);
        if (tabIndex === -1) return prevTabs;
        
        const updatedTab = {
          ...prevTabs[tabIndex],
          modified: false
        };
        
        return [
          ...prevTabs.slice(0, tabIndex),
          updatedTab,
          ...prevTabs.slice(tabIndex + 1)
        ];
      });
      
      return saveAllModifiedFiles();
    }
    
    return Promise.resolve(false);
  }, [selectedItem]);
  
  // Alle Tabs speichern
  const saveAllTabs = useCallback((fileData: any) => {
    // Sicherstellen, dass sowohl Spec_Item.txt als auch propItem.txt.txt aktualisiert werden
    if (fileData) {
      ensurePropItemConsistency(fileData);
    }
    
    const modifiedTabsCount = openTabs.filter(tab => tab.modified).length;
    
    if (modifiedTabsCount === 0) {
      toast.info("Keine modifizierten Tabs zum Speichern");
      return Promise.resolve(false);
    }
    
    // Speichern
    toast.promise(saveAllModifiedFiles(), {
      loading: `Speichere ${modifiedTabsCount} modifizierte Tabs...`,
      success: `${modifiedTabsCount} Tabs gespeichert`,
      error: "Fehler beim Speichern der Tabs"
    });
    
    // Alle Tabs als nicht mehr modifiziert markieren
    setOpenTabs(prevTabs => prevTabs.map(tab => ({
      ...tab,
      modified: false
    })));
    
    return saveAllModifiedFiles();
  }, [openTabs]);
  
  return {
    openTabs,
    addTab,
    updateTabItem,
    handleCloseTab,
    handleSelectTab,
    saveCurrentTab,
    saveAllTabs
  };
};

// Funktion zum Speichern aller geöffneten Tabs
export const saveModifiedTabs = (tabs: any[], fileData: any): Promise<boolean> => {
  // Prüfe, ob es geänderte Tabs gibt
  const modifiedTabs = tabs.filter(tab => tab.modified);
  
  if (modifiedTabs.length === 0) {
    console.log("Keine modifizierten Tabs zum Speichern");
    toast.info("Keine Änderungen zum Speichern vorhanden");
    return Promise.resolve(false);
  }
  
  // Stelle sicher, dass propItem.txt.txt auch aktualisiert wird, wenn Änderungen an Namen vorliegen
  if (fileData) {
    ensurePropItemConsistency(fileData);
  }
  
  // Hinweis anzeigen
  toast.promise(saveAllModifiedFiles(), {
    loading: `Speichere ${modifiedTabs.length} modifizierte Tabs...`,
    success: `${modifiedTabs.length} Tabs erfolgreich gespeichert`,
    error: "Fehler beim Speichern der Tabs"
  });
  
  return saveAllModifiedFiles();
};
