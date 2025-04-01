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

// Erhalte den zu verwendenden Port aus der Umgebungsvariable oder verwende den Standardwert
const vitePort = process.env.VITE_PORT || 8082;

// Verbesserte Funktion zum Erkennen des Vite-Ports
const detectVitePort = () => {
  return new Promise((resolve) => {
    // Prüfe zuerst den konfigurierten Port
    const checkPort = (port, attempts = 0) => {
      console.log(`Prüfe, ob Vite auf Port ${port} läuft (Versuch ${attempts + 1}/5)...`);
      
      const req = http.get({
        hostname: 'localhost',
        port: port,
        path: '/',
        timeout: 2000
      }, (res) => {
        console.log(`Port ${port} antwortet mit Status: ${res.statusCode}`);
        // Wenn der Server antwortet, verwenden wir diesen Port
        resolve(port);
      });
      
      req.on('error', (error) => {
        console.log(`Port ${port} ist nicht verfügbar: ${error.message}`);
        
        // Wenn der Port nicht verfügbar ist und wir noch nicht zu oft versucht haben
        if (attempts < 4) {
          console.log(`Warte 2 Sekunden und versuche erneut...`);
          setTimeout(() => checkPort(port, attempts + 1), 2000);
        } else {
          // Nach 5 Versuchen - Verwenden wir Fallback-Port
          const fallbackPort = parseInt(port) + 1;
          console.log(`Verwende Fallback-Port ${fallbackPort}`);
          resolve(fallbackPort);
        }
      });
      
      req.on('timeout', () => {
        console.log(`Timeout bei Port ${port} (Versuch ${attempts + 1}/5)`);
        req.destroy();
        
        // Bei Timeout und wir haben noch nicht zu oft versucht
        if (attempts < 4) {
          console.log(`Warte 2 Sekunden und versuche erneut...`);
          setTimeout(() => checkPort(port, attempts + 1), 2000);
        } else {
          // Nach 5 Versuchen - Verwenden wir Fallback-Port
          const fallbackPort = parseInt(port) + 1;
          console.log(`Verwende Fallback-Port ${fallbackPort} nach mehreren Timeouts`);
          resolve(fallbackPort);
        }
      });
    };
    
    // Starte mit dem konfigurierten Port
    checkPort(vitePort);
  });
};

// Starte den Vite-Entwicklungsserver
console.log(`Starte Vite-Entwicklungsserver auf Port ${vitePort}...`);

// Verwende den korrekten Befehl zum Starten des Vite-Servers mit dem konfigurierten Port
const server = spawn(npmCmd, ['run', 'vite', '--', '--port', vitePort, '--strict-port'], {
  stdio: 'inherit',
  shell: true,
  windowsHide: false,
  env: {
    ...process.env,
    VITE_PORT: vitePort
  }
});

// Warte auf die Server-Initialisierung und starte dann Electron
setTimeout(async () => {
  try {
    // Erkenne den tatsächlich verwendeten Port
    const detectedPort = await detectVitePort();
    console.log(`Vite läuft auf Port ${detectedPort}`);
    
    console.log('Starte Electron...');
    
    // Setze die Umgebungsvariable für Electron mit korrektem Port
    process.env.VITE_DEV_SERVER_URL = `http://localhost:${detectedPort}`;
    process.env.ELECTRON_START_URL = `http://localhost:${detectedPort}`;
    
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
        ELECTRON_START_URL: `http://localhost:${detectedPort}`
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