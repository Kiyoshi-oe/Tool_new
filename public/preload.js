const { contextBridge, ipcRenderer } = require('electron');

// Ein Debug-Log hinzufügen, um die Ausführung des Preload-Skripts zu bestätigen
console.log('Preload-Skript wird ausgeführt...');

// Expose protected methods that allow the renderer process to use
// the ipcRenderer without exposing the entire object
contextBridge.exposeInMainWorld(
  'electronAPI', {
    // Save a single file - aktualisiere API, um Dateinamen getrennt vom Pfad zu senden
    saveFile: async (fileName, content, savePath) => {
      console.log(`preload: Saving file ${fileName} to ${savePath}`);
      try {
        const result = await ipcRenderer.invoke('save-file', fileName, content, savePath);
        console.log('preload: save-file result', result);
        
        if (result && result.success) {
          return result;
        } else if (result === 'SUCCESS') {
          return 'SUCCESS'; // Legacy format for backward compatibility
        } else {
          console.error('preload: Error saving file', result);
          return result || 'ERROR';
        }
      } catch (error) {
        console.error('preload: Exception in saveFile', error);
        return error.toString();
      }
    },
    
    // Save multiple files at once
    saveAllFiles: (files, targetDirectory) => {
      console.log(`Preload: saveAllFiles aufgerufen für ${files.length} Dateien in Verzeichnis ${targetDirectory || 'standard'}`);
      return ipcRenderer.invoke('save-all-files', files, targetDirectory);
    },
      
    // Load all resource files
    loadAllFiles: () => 
      ipcRenderer.invoke('load-all-files'),
    
    // Listen for save response events
    onSaveFileResponse: (callback) => 
      ipcRenderer.on('save-file-response', (_, data) => callback(data)),
    
    // Neue Funktion: Resolve resource path
    getResourcePath: (subPath) => 
      ipcRenderer.invoke('get-resource-path', subPath),
    
    // Spezielle Funktion zum Speichern mit bestimmter Kodierung (z.B. ANSI/Latin1 für propItem.txt.txt)
    saveFileWithEncoding: async (fileName, content, savePath, encodingOptions) => {
      console.log(`preload: Saving file ${fileName} with encoding ${encodingOptions?.encoding || 'default'}`);
      try {
        const result = await ipcRenderer.invoke('save-file-with-encoding', fileName, content, savePath, encodingOptions);
        console.log('preload: save-file-with-encoding result', result);
        
        if (result && result.success) {
          return result;
        } else {
          console.error('preload: Error saving file with encoding', result);
          return result || 'ERROR';
        }
      } catch (error) {
        console.error('preload: Exception in saveFileWithEncoding', error);
        return error.toString();
      }
    }
  }
);

// Nach dem Einrichten einen Log ausgeben
console.log('Electron API wurde im Renderer-Prozess bereitgestellt');

// Listen for save-file events from the DOM and convert them to IPC calls
window.addEventListener('save-file', (event) => {
  console.log('save-file Event empfangen');
  const { fileName, content, path } = event.detail;
  ipcRenderer.invoke('save-file', fileName, content, path)
    .then(result => {
      // Dispatch a custom event back to the renderer with the result
      window.dispatchEvent(new CustomEvent('save-file-response', { 
        detail: result 
      }));
    })
    .catch(error => {
      window.dispatchEvent(new CustomEvent('save-file-response', { 
        detail: { 
          success: false, 
          fileName,
          error: error.message || 'Unknown error' 
        } 
      }));
    });
});

// Listen for save-all-files events from the DOM
window.addEventListener('save-all-files', (event) => {
  console.log('save-all-files Event empfangen');
  const { files, path } = event.detail;
  ipcRenderer.invoke('save-all-files', files, path)
    .then(result => {
      window.dispatchEvent(new CustomEvent('save-all-files-response', { 
        detail: result 
      }));
    })
    .catch(error => {
      window.dispatchEvent(new CustomEvent('save-all-files-response', { 
        detail: { 
          success: false, 
          error: error.message || 'Unknown error' 
        } 
      }));
    });
});
