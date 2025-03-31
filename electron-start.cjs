// @ts-nocheck
const { spawn } = require('child_process');
const os = require('os');
const fs = require('fs');
const path = require('path');

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

// Starte den Vite-Entwicklungsserver
console.log('Starte Vite-Entwicklungsserver...');

// Verwende den korrekten Befehl zum Starten des Vite-Servers
const server = spawn(npmCmd, ['run', 'vite'], {
  stdio: 'inherit',
  shell: true,
  windowsHide: false
});

// Standardport für Vite
let vitePort = 8081; // Wir nehmen an, dass Vite auf Port 8081 läuft, basierend auf der vorherigen Ausgabe

// Warte auf die Server-Initialisierung
setTimeout(() => {
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
}, 5000); // Warte 5 Sekunden, bis der Server gestartet ist

console.log('Starte Entwicklungsserver und Electron...'); 