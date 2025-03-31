const { app, BrowserWindow, dialog, ipcMain } = require('electron');
const path = require('path');
const fs = require('fs');
const isDev = process.env.NODE_ENV !== 'production' || process.env.ELECTRON_START_URL;

function createWindow() {
  // Create the browser window
  const mainWindow = new BrowserWindow({
    width: 1200,
    height: 800,
    webPreferences: {
      nodeIntegration: false,
      contextIsolation: true,
      preload: path.join(__dirname, 'preload.js')
    },
    icon: path.join(__dirname, 'lovable-uploads/icon_small.png'),
    title: 'Cyrus Resource Tool'
  });

  // Set application menu
  mainWindow.setMenuBarVisibility(false);

  // Debug-Info ausgeben
  console.log('App path:', app.getAppPath());
  console.log('__dirname:', __dirname);
  console.log('process.cwd():', process.cwd());
  console.log('isDev:', isDev);
  console.log('ELECTRON_START_URL:', process.env.ELECTRON_START_URL);
  console.log('VITE_DEV_SERVER_URL:', process.env.VITE_DEV_SERVER_URL);

  // Load the app
  if (isDev) {
    const devServerUrl = process.env.ELECTRON_START_URL || process.env.VITE_DEV_SERVER_URL || 'http://localhost:8081';
    console.log('Versuche Dev-Server zu laden:', devServerUrl);
    
    // Prüfe, ob der Vite-Server bereits läuft
    const checkServerRunning = (url, retries = 3) => {
      return new Promise((resolve) => {
        const https = url.startsWith('https') ? require('https') : require('http');
        const urlObj = new URL(url);
        
        console.log(`Prüfe, ob Server auf ${url} läuft...`);
        
        const req = https.get({
          hostname: urlObj.hostname,
          port: urlObj.port,
          path: '/',
          timeout: 1000
        }, (res) => {
          console.log(`Server antwortet mit Status: ${res.statusCode}`);
          resolve(res.statusCode >= 200 && res.statusCode < 400);
        });
        
        req.on('error', (error) => {
          console.log(`Server nicht erreichbar: ${error.message}`);
          if (retries > 0) {
            console.log(`Versuche es erneut... (${retries} verbleibend)`);
            setTimeout(() => {
              resolve(checkServerRunning(url, retries - 1));
            }, 1000);
          } else {
            resolve(false);
          }
        });
        
        req.on('timeout', () => {
          console.log('Server-Verbindung Timeout');
          req.destroy();
          if (retries > 0) {
            console.log(`Versuche es erneut... (${retries} verbleibend)`);
            setTimeout(() => {
              resolve(checkServerRunning(url, retries - 1));
            }, 1000);
          } else {
            resolve(false);
          }
        });
      });
    };
    
    // Versuche zuerst zu prüfen, ob der Server läuft
    checkServerRunning(devServerUrl).then(isRunning => {
      if (isRunning) {
        // Server läuft, lade die App
        mainWindow.loadURL(devServerUrl).catch(err => {
          handleLoadError(err);
        });
      } else {
        // Server läuft nicht, versuche alternative Ports
        const alternativePorts = [8080, 3000, 5173];
        console.log('Server nicht erreichbar, versuche alternative Ports...');
        
        const tryAlternativePort = (index) => {
          if (index >= alternativePorts.length) {
            console.log('Keine alternativen Ports verfügbar, verwende Fallback...');
            return handleLoadError(new Error('Kein Server erreichbar'));
          }
          
          const port = alternativePorts[index];
          const altUrl = `http://localhost:${port}`;
          console.log(`Versuche alternativen Port: ${port}`);
          
          checkServerRunning(altUrl).then(isAltRunning => {
            if (isAltRunning) {
              console.log(`Server auf ${altUrl} gefunden!`);
              mainWindow.loadURL(altUrl).catch(err => {
                handleLoadError(err);
              });
            } else {
              tryAlternativePort(index + 1);
            }
          });
        };
        
        tryAlternativePort(0);
      }
    });
    
    // Funktion zur Behandlung von Ladefehlern
    const handleLoadError = (err) => {
      console.error('Fehler beim Laden der URL:', err);
      
      // Versuche zuerst die lokale index.html zu laden
      const indexPath = path.join(__dirname, '..', 'dist', 'index.html');
      if (fs.existsSync(indexPath)) {
        console.log('Verwende Fallback-HTML-Datei:', indexPath);
        mainWindow.loadFile(indexPath);
      } else {
        // Versuche einen alternativen Fallback-Pfad
        const altIndexPath = path.join(process.cwd(), 'dist', 'index.html');
        if (fs.existsSync(altIndexPath)) {
          console.log('Verwende alternativen Fallback-Pfad:', altIndexPath);
          mainWindow.loadFile(altIndexPath);
        } else {
          // Zeige eine Fehlermeldung an, wenn kein Fallback verfügbar ist
          dialog.showErrorBox(
            'Laden fehlgeschlagen',
            `Konnte weder Dev-Server noch lokale HTML-Datei laden. 
             URL: ${devServerUrl}, 
             Fehler: ${err.message}
             
             Bitte starten Sie den Dev-Server mit 'npm run dev' oder 
             erstellen Sie eine Build-Version mit 'npm run build'.`
          );
        }
      }
    };
    
    // Open DevTools in development mode
    mainWindow.webContents.openDevTools();
  } else {
    // Try to load the index.html from the dist folder
    const indexPath = path.join(__dirname, '..', 'dist', 'index.html');
    console.log('Versuche Produktions-HTML zu laden:', indexPath);
    
    if (fs.existsSync(indexPath)) {
      mainWindow.loadFile(indexPath);
    } else {
      console.error('index.html nicht gefunden:', indexPath);
      dialog.showErrorBox(
        'Laden fehlgeschlagen',
        `Die Anwendungsdateien wurden nicht gefunden. Pfad: ${indexPath}`
      );
    }
  }

  // Handle errors when loading the app
  mainWindow.webContents.on('did-fail-load', () => {
    dialog.showErrorBox(
      'Loading Failed',
      'The application failed to load. Please check your internet connection or restart the application.'
    );
  });

  // Handle IPC events for saving individual files
  ipcMain.handle('save-file', async (_, fileName, content, savePath) => {
    try {
      console.log(`Electron: Speichere Datei ${fileName} nach ${savePath || 'Standard-Ressourcenordner'}`);
      console.log(`Inhaltslänge: ${content ? content.length : 0} Zeichen`);
      
      // Zusätzliche Überprüfung für leeren Inhalt
      if (!content || content.length === 0) {
        console.error(`WARNUNG: Leerer Inhalt für ${fileName}`);
        return { 
          success: false, 
          error: 'Leerer Dateiinhalt' 
        };
      }
      
      // Inhaltsdiagnose für .txt Dateien
      if (fileName.endsWith('.txt') && content) {
        const firstFewChars = content.substring(0, 100).replace(/\n/g, '\\n');
        console.log(`Inhalt beginnt mit: ${firstFewChars}...`);
        console.log(`Zeilen: ${content.split('\n').length}`);
      }
      
      // Determine the actual path to save to
      let finalPath;
      
      if (savePath) {
        // Prüfe, ob es sich um einen der Standard-Ordnernamen handelt
        if (savePath === 'resource' || savePath === 'resources') {
          finalPath = path.join(app.getAppPath(), 'public', 'resource');
        } else if (savePath === 'userData') {
          finalPath = app.getPath('userData');
        } else if (savePath === 'documents') {
          finalPath = app.getPath('documents');
        } else if (!path.isAbsolute(savePath)) {
          // Wenn es ein relativer Pfad ist, mache ihn absolut
          finalPath = path.join(app.getAppPath(), savePath);
        } else {
          // Ansonsten verwende den Pfad direkt
          finalPath = savePath;
        }
      } else {
        // Default path is the resource folder in the app
        finalPath = path.join(app.getAppPath(), 'public', 'resource');
      }
      
      console.log(`Auflösung des Speicherpfads: ${finalPath}`);
      console.log(`App-Pfad: ${app.getAppPath()}`);
      console.log(`Aktuelles Arbeitsverzeichnis: ${process.cwd()}`);
      
      // List available resources in the folder
      try {
        if (fs.existsSync(finalPath)) {
          console.log("Vorhandene Dateien im Ressourcenordner:");
          const files = fs.readdirSync(finalPath);
          files.forEach(file => {
            console.log(`- ${file}`);
          });
        }
      } catch (listError) {
        console.warn("Konnte Ordnerinhalt nicht auflisten:", listError);
      }
      
      // Make sure the directory exists
      if (!fs.existsSync(finalPath)) {
        try {
          fs.mkdirSync(finalPath, { recursive: true });
          console.log(`Verzeichnis erstellt: ${finalPath}`);
        } catch (mkdirError) {
          console.error(`Fehler beim Erstellen des Verzeichnisses ${finalPath}:`, mkdirError);
          
          // Try fallback to current working directory if app path fails
          finalPath = path.join(process.cwd(), 'public', 'resource');
          console.log(`Verwende Fallback-Pfad: ${finalPath}`);
          
          if (!fs.existsSync(finalPath)) {
            try {
              fs.mkdirSync(finalPath, { recursive: true });
              console.log(`Fallback-Verzeichnis erstellt: ${finalPath}`);
            } catch (fallbackError) {
              console.error(`Fehler beim Erstellen des Fallback-Verzeichnisses ${finalPath}:`, fallbackError);
              throw new Error(`Konnte Verzeichnis nicht erstellen: ${fallbackError.message}`);
            }
          }
        }
      }
      
      // Spezielle Behandlung für propItem.txt.txt
      if (fileName === 'propItem.txt.txt') {
        console.log(`Spezielle Behandlung für propItem.txt.txt aktiviert`);
        
        // Prüfen, ob die Datei bereits existiert, und wenn ja, Inhalte zusammenführen
        const fullPath = path.join(finalPath, fileName);
        if (fs.existsSync(fullPath)) {
          try {
            console.log(`Bestehende propItem.txt.txt gefunden, führe Inhalte zusammen`);
            const existingContent = fs.readFileSync(fullPath, 'utf8');
            
            // Wir haben neue Einträge im Format "ID\tWert"
            // Wir müssen sicherstellen, dass IDs nicht dupliziert werden
            const existingLines = existingContent.split(/\r?\n/);
            const newLines = content.split(/\r?\n/);
            
            // Erstelle eine Map von ID zu Wert aus dem bestehenden Inhalt
            const entries = {};
            existingLines.forEach(line => {
              const parts = line.split('\t');
              if (parts.length >= 2 && parts[0].trim().match(/IDS_PROPITEM_TXT_\d+/)) {
                entries[parts[0].trim()] = parts[1].trim();
              }
            });
            
            // Aktualisiere oder füge neue Einträge hinzu
            newLines.forEach(line => {
              const parts = line.split('\t');
              if (parts.length >= 2 && parts[0].trim().match(/IDS_PROPITEM_TXT_\d+/)) {
                entries[parts[0].trim()] = parts[1].trim();
              }
            });
            
            // Erstelle den endgültigen Inhalt, sortiert nach ID
            const finalLines = Object.entries(entries)
              .sort((a, b) => {
                const numA = parseInt(a[0].replace(/\D/g, ''), 10);
                const numB = parseInt(b[0].replace(/\D/g, ''), 10);
                return numA - numB;
              })
              .map(([id, value]) => `${id}\t${value}`);
            
            // Nutze Windows-Zeilenumbrüche für bessere Kompatibilität
            content = finalLines.join('\r\n');
            
            console.log(`Zusammengeführte propItem.txt.txt hat ${finalLines.length} Einträge`);
          } catch (mergeError) {
            console.error(`Fehler beim Zusammenführen von propItem.txt.txt:`, mergeError);
            // Verwende neuen Inhalt, wenn Zusammenführung fehlschlägt
          }
        }
      }
      
      // The full path including filename
      const fullPath = path.join(finalPath, fileName);
      console.log(`Speichere nach: ${fullPath}`);
      
      // Try using fs.access to check if we have write permissions
      try {
        if (fs.existsSync(finalPath)) {
          fs.accessSync(finalPath, fs.constants.W_OK);
          console.log(`Schreibrechte für Verzeichnis bestätigt: ${finalPath}`);
        }
      } catch (accessError) {
        console.error(`Keine Schreibrechte für Verzeichnis ${finalPath}:`, accessError);
        throw new Error(`Keine Schreibberechtigung: ${accessError.message}`);
      }
      
      // Write the file with explicit error handling
      try {
        // Entferne den Backup-Code - Dateien direkt überschreiben
        fs.writeFileSync(fullPath, content, { encoding: 'utf8', flag: 'w' });
        console.log(`Datei erfolgreich nach ${fullPath} geschrieben`);
        
        // Verify the file was actually written
        if (fs.existsSync(fullPath)) {
          const stats = fs.statSync(fullPath);
          console.log(`Dateigröße: ${stats.size} Bytes`);
          
          // Read back the first few bytes to verify content was written correctly
          if (stats.size > 0) {
            const buffer = Buffer.alloc(Math.min(stats.size, 100));
            const fd = fs.openSync(fullPath, 'r');
            fs.readSync(fd, buffer, 0, buffer.length, 0);
            fs.closeSync(fd);
            console.log(`Erste Bytes: ${buffer.toString().replace(/\n/g, '\\n')}`);
          }
          
          // Super-sicher, dass Änderungen geschrieben wurden, indem wir explizit Pufferinhalt leeren
          try {
            fs.fsyncSync(fs.openSync(fullPath, 'r+'));
            console.log("Dateisystem-Puffer geleert");
          } catch (fsyncError) {
            console.warn("Konnte Dateisystem-Puffer nicht leeren:", fsyncError);
          }
          
          // Rückgabe des Erfolgs mit Pfad
          return { 
            success: true, 
            path: fullPath,
            size: stats.size,
            timestamp: new Date().toISOString()
          };
        } else {
          throw new Error(`Datei existiert nach dem Schreiben nicht: ${fullPath}`);
        }
      } catch (writeError) {
        console.error(`FEHLER beim Schreiben der Datei: ${writeError.message}`);
        
        // Versuche es mit einem alternativen Speichermethode
        try {
          console.log("Versuche alternative Speichermethode...");
          
          // Verwende writeFile mit voller Fehlerrückmeldung
          await fs.promises.writeFile(fullPath, content, { encoding: 'utf8' });
          
          if (fs.existsSync(fullPath)) {
            const stats = fs.statSync(fullPath);
            console.log(`Datei erfolgreich mit alternativer Methode gespeichert. Größe: ${stats.size} Bytes`);
            
            return { 
              success: true, 
              path: fullPath,
              size: stats.size,
              method: 'alternative'
            };
          }
        } catch (altWriteError) {
          console.error(`Auch alternative Speichermethode fehlgeschlagen: ${altWriteError.message}`);
        }
        
        return { 
          success: false, 
          error: writeError.message || 'Unbekannter Fehler beim Schreiben der Datei',
          fileName,
          path: fullPath
        };
      }
    } catch (error) {
      console.error(`Allgemeiner Fehler beim Speichern von ${fileName}:`, error);
      return { 
        success: false, 
        error: error.message || 'Unbekannter Fehler',
        fileName
      };
    }
  });

  // Handle IPC events for saving multiple files
  ipcMain.handle('save-all-files', async (_, files, savePath) => {
    try {
      console.log(`Speichere ${files.length} Dateien nach ${savePath || 'Standard-Ressourcenordner'}`);
      
      // Determine the actual path to save to
      let finalPath;
      
      if (savePath) {
        // Prüfe, ob es sich um einen der Standard-Ordnernamen handelt
        if (savePath === 'resource' || savePath === 'resources') {
          finalPath = path.join(app.getAppPath(), 'public', 'resource');
        } else if (savePath === 'userData') {
          finalPath = app.getPath('userData');
        } else if (savePath === 'documents') {
          finalPath = app.getPath('documents');
        } else if (!path.isAbsolute(savePath)) {
          // Wenn es ein relativer Pfad ist, mache ihn absolut
          finalPath = path.join(app.getAppPath(), savePath);
        } else {
          // Ansonsten verwende den Pfad direkt
          finalPath = savePath;
        }
      } else {
        // Default path is the resource folder in the app
        finalPath = path.join(app.getAppPath(), 'public', 'resource');
      }
      
      console.log(`Speicherpfad: ${finalPath}`);
      
      // Make sure the directory exists
      if (!fs.existsSync(finalPath)) {
        fs.mkdirSync(finalPath, { recursive: true });
        console.log(`Verzeichnis erstellt: ${finalPath}`);
      }
      
      const results = [];
      
      // Speichere jede Datei einzeln
      for (const file of files) {
        try {
          console.log(`Speichere Datei ${file.name} (${file.content ? file.content.length : 0} Zeichen)`);
          
          // Spezielle Behandlung für propItem.txt.txt
          let finalContent = file.content;
          
          if (file.name === 'propItem.txt.txt' && fs.existsSync(path.join(finalPath, file.name))) {
            try {
              console.log(`Bestehende propItem.txt.txt gefunden, führe Inhalte zusammen`);
              const existingContent = fs.readFileSync(path.join(finalPath, file.name), 'utf8');
              
              // Wir haben neue Einträge im Format "ID\tWert"
              // Wir müssen sicherstellen, dass IDs nicht dupliziert werden
              const existingLines = existingContent.split(/\r?\n/);
              const newLines = file.content.split(/\r?\n/);
              
              // Erstelle eine Map von ID zu Wert aus dem bestehenden Inhalt
              const entries = {};
              existingLines.forEach(line => {
                const parts = line.split('\t');
                if (parts.length >= 2 && parts[0].trim().match(/IDS_PROPITEM_TXT_\d+/)) {
                  entries[parts[0].trim()] = parts[1].trim();
                }
              });
              
              // Aktualisiere oder füge neue Einträge hinzu
              newLines.forEach(line => {
                const parts = line.split('\t');
                if (parts.length >= 2 && parts[0].trim().match(/IDS_PROPITEM_TXT_\d+/)) {
                  entries[parts[0].trim()] = parts[1].trim();
                }
              });
              
              // Erstelle den endgültigen Inhalt, sortiert nach ID
              const finalLines = Object.entries(entries)
                .sort((a, b) => {
                  const numA = parseInt(a[0].replace(/\D/g, ''), 10);
                  const numB = parseInt(b[0].replace(/\D/g, ''), 10);
                  return numA - numB;
                })
                .map(([id, value]) => `${id}\t${value}`);
              
              // Nutze Windows-Zeilenumbrüche für bessere Kompatibilität
              finalContent = finalLines.join('\r\n');
              
              console.log(`Zusammengeführte propItem.txt.txt hat ${finalLines.length} Einträge`);
            } catch (mergeError) {
              console.error(`Fehler beim Zusammenführen von propItem.txt.txt:`, mergeError);
              // Verwende neuen Inhalt, wenn Zusammenführung fehlschlägt
            }
          }
          
          // The full path including filename
          const fullPath = path.join(finalPath, file.name);
          
          // Entferne den Backup-Code - Dateien direkt überschreiben
          fs.writeFileSync(fullPath, finalContent, { encoding: 'utf8', flag: 'w' });
          
          // Verify the file was actually written
          if (fs.existsSync(fullPath)) {
            const stats = fs.statSync(fullPath);
            console.log(`Datei ${file.name} erfolgreich gespeichert. Größe: ${stats.size} Bytes`);
            
            results.push({
              name: file.name,
              success: true,
              path: fullPath,
              size: stats.size
            });
          } else {
            throw new Error(`Datei existiert nach dem Schreiben nicht: ${fullPath}`);
          }
        } catch (fileError) {
          console.error(`Fehler beim Speichern von ${file.name}:`, fileError);
          
          results.push({
            name: file.name,
            success: false,
            error: fileError.message || 'Unbekannter Fehler'
          });
        }
      }
      
      // Prüfe, ob alle Dateien erfolgreich gespeichert wurden
      const allSuccessful = results.every(result => result.success);
      
      return {
        success: allSuccessful,
        results,
        timestamp: new Date().toISOString()
      };
    } catch (error) {
      console.error(`Allgemeiner Fehler beim Speichern aller Dateien:`, error);
      
      return {
        success: false,
        error: error.message || 'Unbekannter Fehler',
        timestamp: new Date().toISOString()
      };
    }
  });

  // Handle loading all files from the resource folder
  ipcMain.handle('load-all-files', async () => {
    try {
      console.log('Loading all resource files from resource folder');
      
      // Determine the resource folder path
      const resourceFolder = path.join(app.getAppPath(), 'public', 'resource');
      
      console.log(`Ressourcenordner: ${resourceFolder}`);
      console.log(`App-Pfad: ${app.getAppPath()}`);
      console.log(`Aktuelles Arbeitsverzeichnis: ${process.cwd()}`);
      
      // Alternativer Pfad, falls der Hauptpfad nicht funktioniert
      const alternativeFolder = path.join(process.cwd(), 'public', 'resource');
      console.log(`Alternativer Ressourcenordner: ${alternativeFolder}`);
      
      // Check if the resource folder exists
      let finalResourceFolder = resourceFolder;
      if (!fs.existsSync(resourceFolder)) {
        console.warn(`Resource folder does not exist: ${resourceFolder}`);
        
        // Versuche den alternativen Pfad
        if (fs.existsSync(alternativeFolder)) {
          console.log(`Verwende alternativen Ressourcenordner: ${alternativeFolder}`);
          finalResourceFolder = alternativeFolder;
        } else {
          console.error(`Auch alternativer Ressourcenordner existiert nicht: ${alternativeFolder}`);
          return {
            success: false,
            error: 'Resource folder not found'
          };
        }
      }
      
      // Liste alle Dateien im Ressourcenordner auf
      console.log(`Lese Dateien aus ${finalResourceFolder}:`);
      const files = fs.readdirSync(finalResourceFolder);
      console.log(`Gefundene Dateien (${files.length}):`);
      files.forEach(file => console.log(`- ${file}`));
      
      const fileContents = {};
      
      // Read each file
      for (const file of files) {
        const filePath = path.join(finalResourceFolder, file);
        const stats = fs.statSync(filePath);
        
        // Skip directories
        if (stats.isDirectory()) {
          console.log(`Überspringe Verzeichnis: ${file}`);
          continue;
        }
        
        try {
          console.log(`Lese Datei: ${file} (${stats.size} Bytes)`);
          const content = fs.readFileSync(filePath, 'utf8');
          fileContents[file] = content;
          console.log(`Datei ${file} erfolgreich gelesen, Inhaltslänge: ${content.length}`);
        } catch (readError) {
          console.error(`Error reading file ${file}:`, readError);
        }
      }
      
      console.log(`Insgesamt ${Object.keys(fileContents).length} Dateien gelesen`);
      
      return {
        success: true,
        files: fileContents
      };
    } catch (error) {
      console.error('Error loading all resource files:', error);
      return {
        success: false,
        error: error.message || 'Unknown error loading resource files'
      };
    }
  });

  // Neuer Handler für die Pfadauflösung
  ipcMain.handle('get-resource-path', async (_, subPath) => {
    try {
      console.log(`Electron: Resolving path for ${subPath || 'resource directory'}`);
      
      let finalPath;
      
      if (subPath) {
        // Prüfe, ob es sich um einen der Standard-Ordnernamen handelt
        if (subPath === 'resource' || subPath === 'resources') {
          finalPath = path.join(app.getAppPath(), 'public', 'resource');
        } else if (subPath === 'userData') {
          finalPath = app.getPath('userData');
        } else if (subPath === 'documents') {
          finalPath = app.getPath('documents');
        } else if (!path.isAbsolute(subPath)) {
          // Wenn es ein relativer Pfad ist, mache ihn absolut
          finalPath = path.join(app.getAppPath(), subPath);
        } else {
          // Ansonsten verwende den Pfad direkt
          finalPath = subPath;
        }
      } else {
        // Default path is the resource folder in the app
        finalPath = path.join(app.getAppPath(), 'public', 'resource');
      }
      
      // Prüfe, ob der Pfad existiert, und erstelle ihn, falls nicht
      if (!fs.existsSync(finalPath)) {
        fs.mkdirSync(finalPath, { recursive: true });
        console.log(`Verzeichnis erstellt: ${finalPath}`);
      }
      
      // Prüfe, ob wir Schreibzugriff haben
      try {
        fs.accessSync(finalPath, fs.constants.W_OK);
        console.log(`Schreibrechte für ${finalPath} bestätigt`);
      } catch (accessError) {
        console.warn(`Keine Schreibrechte für ${finalPath}`);
        
        // Versuche einen alternativen Pfad im Benutzerverzeichnis
        const altPath = path.join(app.getPath('userData'), subPath || 'resource');
        
        if (!fs.existsSync(altPath)) {
          fs.mkdirSync(altPath, { recursive: true });
          console.log(`Alternatives Verzeichnis erstellt: ${altPath}`);
        }
        
        finalPath = altPath;
      }
      
      return {
        success: true,
        path: finalPath,
        exists: fs.existsSync(finalPath),
        writable: true,
        appPath: app.getAppPath(),
        platform: process.platform
      };
    } catch (error) {
      console.error('Error resolving resource path:', error);
      return {
        success: false,
        error: error.message || 'Unknown error',
        appPath: app.getAppPath(),
        platform: process.platform
      };
    }
  });
}

// This method will be called when Electron has finished initialization
app.whenReady().then(createWindow);

// Quit when all windows are closed, except on macOS
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', () => {
  // On macOS it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow();
  }
});
