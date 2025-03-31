// Wir importieren alle benötigten Funktionen und exportieren sie wieder
import path from 'path';
import { serializeToText, serializePropItemData } from './fileOperations';
import { trackModifiedFile, trackPropItemChanges, savePropItemChanges, getModifiedFiles, clearModifiedFiles } from './fileOperations';
import { saveTextFile, saveAllModifiedFiles } from './fileOperations';
import { readTextFile } from './fileOperations';

// Expliziter Re-Export aller wichtigen Funktionen
export {
  serializeToText,
  serializePropItemData,
  trackModifiedFile,
  trackPropItemChanges,
  savePropItemChanges,
  getModifiedFiles,
  clearModifiedFiles,
  saveTextFile,
  saveAllModifiedFiles,
  readTextFile
};

// Weitere Importe und Exporte aus anderen Dateien
export * from './defineItemParser';
export * from './mdlDynaParser';
export * from './parseUtils';
export * from './resourceLoader';
export * from './propItemUtils';
