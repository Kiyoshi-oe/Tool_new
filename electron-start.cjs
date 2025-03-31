// @ts-nocheck
const { spawn } = require('child_process');
const os = require('os');
const fs = require('fs');
const path = require('path');
const http = require('http');

// Bestimme den korrekten npm-Befehl basierend auf dem Betriebssystem
const npmCmd = os.platform() === 'win32' ? 'npm.cmd' : 'npm';

// Prüfe, ob Electron lokal installiert ist
const isElectronInstalled = () => {
  try {
    require.resolve('electron');
    return true;
  } catch (e) {
    return false;
  }
};

// Funktion zum Erkennen des tatsächlich laufenden Ports
const detectVitePort = () => {
  return new Promise((resolve) => {
    // Prüfe zuerst den konfigurierten Port (8081)
    const checkPort = (port, nextPort) => {
      console.log(`Prüfe, ob Vite auf Port ${port} läuft...`);
      
      const req = http.get({
        hostname: 'localhost',
        port: port,
        path: '/',
        timeout: 1000
      }, (res) => {
        console.log(`Port ${port} antwortet mit Status: ${res.statusCode}`);
        // Wenn der Server antwortet, verwenden wir diesen Port
        resolve(port);
      });
      
      req.on('error', () => {
        console.log(`Port ${port} ist nicht verfügbar`);
        if (nextPort) {
          // Versuche den nächsten Port
          checkPort(nextPort);
        } else {
          // Fallback auf Standardport
          console.log('Kein aktiver Port gefunden, verwende Standardport 8081');
          resolve(8081);
        }
      });
      
      req.on('timeout', () => {
        console.log(`Timeout bei Port ${port}`);
        req.destroy();
        if (nextPort) {
          checkPort(nextPort);
        } else {
          console.log('Timeout bei allen Ports, verwende Standardport 8081');
          resolve(8081);
        }
      });
    };
    
    // Prüfe die möglichen Ports in dieser Reihenfolge
    checkPort(8081, 8080);
  });
};

// Starte den Vite-Entwicklungsserver
console.log('Starte Vite-Entwicklungsserver...');

// Verwende den korrekten Befehl zum Starten des Vite-Servers
const server = spawn(npmCmd, ['run', 'vite'], {
  stdio: 'inherit',
  shell: true,
  windowsHide: false
});

// Warte auf die Server-Initialisierung und starte dann Electron
setTimeout(async () => {
  try {
    // Erkenne den tatsächlich verwendeten Port
    const vitePort = await detectVitePort();
    console.log(`Vite läuft vermutlich auf Port ${vitePort}`);
    
    console.log('Starte Electron...');
    
    // Setze die Umgebungsvariable für Electron mit korrektem Port
    process.env.VITE_DEV_SERVER_URL = `http://localhost:${vitePort}`;
    
    // Starte Electron direkt mit Pfad zur Hauptdatei
    const electronBin = path.join(process.cwd(), 'node_modules', '.bin', os.platform() === 'win32' ? 'electron.cmd' : 'electron');
    console.log(`Verwende Electron-Binary: ${electronBin}`);
    console.log(`Aktuelles Arbeitsverzeichnis: ${process.cwd()}`);
    
    // Prüfe, ob die electron.cjs existiert
    const electronMainPath = path.join(process.cwd(), 'public', 'electron.cjs');
    if (fs.existsSync(electronMainPath)) {
      console.log(`electron.cjs gefunden unter: ${electronMainPath}`);
    } else {
      console.error(`Fehler: electron.cjs nicht gefunden unter ${electronMainPath}`);
    }
    
    // Starte Electron mit direktem Pfad zum Einstiegspunkt
    const electron = spawn(electronBin, ['.'], {
      stdio: 'inherit',
      shell: true,
      windowsHide: false,
      env: {
        ...process.env,
        ELECTRON_START_URL: `http://localhost:${vitePort}`
      }
    });
    
    // Behandle das Beenden des Electron-Prozesses
    electron.on('close', (code) => {
      console.log(`Electron-Prozess beendet mit Code ${code}`);
      server.kill();
      process.exit(code);
    });
  } catch (error) {
    console.error('Fehler beim Starten von Electron:', error);
    server.kill();
    process.exit(1);
  }
}, 5000); // Warte 5 Sekunden, bis der Server gestartet ist

console.log('Starte Entwicklungsserver und Electron...'); 