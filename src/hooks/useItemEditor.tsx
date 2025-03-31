import { useState, useCallback, useMemo, useEffect } from "react";
import { FileData, LogEntry, ResourceItem } from "../types/fileTypes";
import { toast } from "sonner";
import { trackModifiedFile, trackPropItemChanges } from "../utils/file/fileOperations";

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
  const handleUpdateItem = useCallback((updatedItem: ResourceItem, field?: string, oldValue?: any) => {
    if (!fileData || !editMode) return;

    console.log(`Aktualisiere Item ${updatedItem.id} (${updatedItem.name})`, `Feld: ${field || 'unbekannt'}`);
    
    // Finde das Item im fileData und aktualisiere es
    const updatedItems = fileData.items.map(item => {
      if (item.id === updatedItem.id) {
        // Für displayName und description spezielles Handling, um Synchronisation zu gewährleisten
        if (field === 'displayName' || field === 'description') {
          console.log(`Ändere ${field} von "${oldValue || 'undefiniert'}" zu "${field === 'displayName' ? updatedItem.displayName : updatedItem.description}"`);
          
          // Stelle sicher, dass die Änderung in beiden Dateien verfolgt wird
          try {
            // Rufe beide Tracking-Funktionen auf, um die Änderungen in beiden Dateien zu verfolgen
            trackPropItemChanges(
              updatedItem.id,
              updatedItem.name,
              updatedItem.displayName || '',
              updatedItem.description || ''
            );
            
            // Importiere und rufe markItemAsModified auf, um das Item im Cache zu aktualisieren
            try {
              const { markItemAsModified } = require('../utils/file/propItemUtils');
              markItemAsModified(
                updatedItem.id,
                updatedItem.displayName || '',
                updatedItem.description || ''
              );
              console.log(`Item ${updatedItem.id} im modifiedItems-Cache markiert`);
            } catch (importError) {
              console.warn(`Konnte markItemAsModified nicht importieren:`, importError);
            }
          } catch (error) {
            console.error(`Fehler beim Tracking von PropItem-Änderungen:`, error);
          }
        }
        
        // Aktualisiere das Item mit den neuen Werten
        return {
          ...item,
          ...updatedItem
        };
      }
      return item;
    });

    // Aktualisiere den fileData-Zustand
    setFileData({
      ...fileData,
      items: updatedItems
    });

    // Aktualisiere auch den selectedItem-Zustand, falls nötig
    if (selectedItem && selectedItem.id === updatedItem.id) {
      setSelectedItem({
        ...selectedItem,
        ...updatedItem
      });
    }

    // Aktualisiere auch die openTabs, falls das Item dort vorhanden ist
    if (openTabs.length > 0) {
      const updatedTabs = openTabs.map(tab => {
        if (tab.item.id === updatedItem.id) {
          return {
            ...tab,
            item: {
              ...tab.item,
              ...updatedItem
            }
          };
        }
        return tab;
      });

      setOpenTabs(updatedTabs);
    }

    // Track that the Spec_Item.txt file has been modified
    // Mark this as a spec item file to ensure it's preserved exactly
    const serializedData = JSON.stringify({
      ...fileData,
      items: updatedItems,
      isSpecItemFile: true,
      originalContent: fileData.originalContent // Pass through the original content if it exists
    });
    
    // Log the presence of originalContent for debugging
    if (fileData.originalContent) {
      console.log("Original content is present, length:", fileData.originalContent.length);
      console.log("First 100 chars:", fileData.originalContent.substring(0, 100));
    } else {
      console.warn("No original content found for Spec_Item.txt");
    }
    
    // Verbessertes Tracking der Änderungen für beide Dateien
    trackModifiedFile("Spec_Item.txt", serializedData, {
      containsDisplayNameChanges: field === 'displayName',
      containsDescriptionChanges: field === 'description',
      modifiedField: field,
      modifiedTimestamp: Date.now()
    });
    
    // Also track propItem changes if this is a displayName or description change
    if (field === 'displayName' || field === 'description') {
      // Jetzt haben wir ein robusteres System für displayName und description Änderungen
      console.log(`Verfolge Änderungen für Item ${updatedItem.id} (${updatedItem.name})`);
      console.log(`  Field: ${field}, Alter Wert: "${oldValue}", Neuer Wert: "${field === 'displayName' ? updatedItem.displayName : updatedItem.description}"`);
      
      // Die Funktion trackPropItemChanges wird aufgerufen, um PropItem.txt.txt zu aktualisieren
      trackPropItemChanges(
        updatedItem.id,
        updatedItem.name,
        updatedItem.displayName || '',
        updatedItem.description || ''
      );
      
      // Rufe auch sicherheitshalber ensurePropItemConsistency auf
      try {
        const { ensurePropItemConsistency } = require('../utils/file/fileOperations');
        ensurePropItemConsistency({
          ...fileData,
          items: updatedItems
        });
      } catch (error) {
        console.warn("Konnte ensurePropItemConsistency nicht aufrufen:", error);
      }
      
      // Explizites Flag für Konsistenz zwischen beiden Dateien setzen
      console.log(`PropItem-Änderungen für ${field} wurden erfasst und für Spec_Item.txt und PropItem.txt.txt synchronisiert`);
    }
  }, [fileData, editMode, selectedItem, openTabs, setFileData, setSelectedItem, setOpenTabs]);
  
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

  return {
    editMode,
    handleUpdateItem,
    handleSelectItem,
    handleToggleEditMode
  };
};
