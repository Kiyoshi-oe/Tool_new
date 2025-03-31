import { toast } from "sonner";
import { trackModifiedFile } from "./fileOperations";

// Interface for storing item define mappings
interface ItemDefineMapping {
  [key: string]: string; // Map from define name (e.g. II_WEA_SWO_WOODEN) to ID (e.g. 21)
}

// Global cache for item define mappings
let itemDefineMappings: ItemDefineMapping = {};
// Store the original file content so we can modify it correctly
let originalDefineItemContent = "";

// Parse defineItem.h file content
export const parseDefineItemFile = (content: string): void => {
  // Store the original content
  originalDefineItemContent = content;
  try {
    console.log("Parsing defineItem.h file...");
    
    const defineRegex = /\#define\s+(II_[A-Z0-9_]+)\s+(\d+)/g;
    const mappings: ItemDefineMapping = {};
    
    let match;
    let count = 0;
    
    while ((match = defineRegex.exec(content)) !== null) {
      const defineName = match[1];
      const defineValue = match[2];
      
      mappings[defineName] = defineValue;
      count++;
      
      if (count <= 5) {
        console.log(`Parsed define: ${defineName} = ${defineValue}`);
      }
    }
    
    console.log(`Successfully parsed ${count} item definitions from defineItem.h`);
    
    // Store in global cache
    itemDefineMappings = mappings;
    
    toast.success(`Loaded ${count} item definitions from defineItem.h`);
  } catch (error) {
    console.error("Error parsing defineItem.h:", error);
    toast.error("Failed to parse defineItem.h file");
  }
};

// Get item ID from define name
export const getItemIdFromDefine = (defineName: string): string => {
  if (!defineName) return '';
  
  // Clean the input from any quotes
  const cleanDefineName = defineName.replace(/^"+|"+$/g, '');
  
  // Look up the ID in our mappings
  const itemId = itemDefineMappings[cleanDefineName] || '';
  
  if (itemId) {
    console.log(`Resolved item ID for ${cleanDefineName}: ${itemId}`);
  } else {
    console.log(`No item ID found for ${cleanDefineName}`);
  }
  
  return itemId;
};

// Get all available item define mappings
export const getItemDefineMappings = (): ItemDefineMapping => {
  return itemDefineMappings;
};

// Update an item ID in the defineItem.h file
export const updateItemIdInDefine = (defineName: string, newId: string): boolean => {
  if (!defineName || !newId || !originalDefineItemContent) {
    console.error("Missing data for updating defineItem.h");
    return false;
  }

  try {
    // Clean the input from any quotes
    const cleanDefineName = defineName.replace(/^"+|"+$/g, '');
    
    // Check if this define exists in our mappings
    if (!(cleanDefineName in itemDefineMappings)) {
      console.error(`Define name ${cleanDefineName} not found in defineItem.h`);
      return false;
    }

    // Update the mapping in memory
    const oldId = itemDefineMappings[cleanDefineName];
    itemDefineMappings[cleanDefineName] = newId;
    
    console.log(`Updating item ID for ${cleanDefineName}: ${oldId} → ${newId}`);
    
    // Update the file content - we need to replace the exact define line
    const defineRegex = new RegExp(`(#define\\s+${cleanDefineName}\\s+)\\d+`, 'g');
    const updatedContent = originalDefineItemContent.replace(defineRegex, `$1${newId}`);
    
    // Check if the content was actually changed
    if (updatedContent === originalDefineItemContent) {
      console.warn(`No changes were made to defineItem.h for ${cleanDefineName}`);
      return false;
    }
    
    // Track the modified file to be saved
    trackModifiedFile("defineItem.h", updatedContent);
    console.log(`defineItem.h modified: ${cleanDefineName} ID updated to ${newId}`);
    
    // Update our original content to reflect the changes
    originalDefineItemContent = updatedContent;
    
    return true;
  } catch (error) {
    console.error("Error updating defineItem.h:", error);
    return false;
  }
};

// Function to load defineItem.h from public folder
export const loadDefineItemFile = async (): Promise<void> => {
  try {
    console.log("Loading defineItem.h file from public folder...");
    
    // Bessere Fehlermeldung und mehrere Pfade probieren
    let response;
    let paths = [
      '/resource/defineItem.h',  // Korrigierter Pfad ohne 'public'
      './resource/defineItem.h'
    ];
    
    console.log("Versuche defineItem.h zu laden mit folgenden Pfaden:", paths);
    
    let content = null;
    let loadedPath = null;
    
    // Versuche alle Pfade nacheinander
    for (const path of paths) {
      try {
        console.log(`Versuche Pfad: ${path}`);
        response = await fetch(path);
        
        if (response.ok) {
          console.log(`Erfolgreich geladen von: ${path}`);
          content = await response.text();
          loadedPath = path;
          break;
        } else {
          console.warn(`Konnte defineItem.h nicht von ${path} laden, Status: ${response.status}`);
        }
      } catch (fetchError) {
        console.warn(`Fehler beim Laden von ${path}:`, fetchError);
      }
    }
    
    if (!content) {
      // Wenn keine der Pfade funktioniert hat, probieren wir Electron API
      if ((window as any).electronAPI) {
        try {
          console.log("Versuche Laden über Electron API");
          const result = await (window as any).electronAPI.loadAllFiles();
          
          if (result.success && result.files && result.files["defineItem.h"]) {
            console.log("defineItem.h über Electron API geladen");
            content = result.files["defineItem.h"];
            loadedPath = "electron-api";
          }
        } catch (electronError) {
          console.error("Fehler beim Laden über Electron API:", electronError);
        }
      }
    }
    
    if (!content) {
      throw new Error(`Konnte defineItem.h über keinen Pfad laden`);
    }
    
    console.log(`defineItem.h erfolgreich von ${loadedPath} geladen, Inhaltslänge:`, content.length);
    
    parseDefineItemFile(content);
  } catch (error) {
    console.error("Error loading defineItem.h file:", error);
    toast.error("Fehler beim Laden der defineItem.h Datei");
  }
};
