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
console.log('Starting Vite development server...');

// Verwende den korrekten Befehl zum Starten des Vite-Servers
const server = spawn(npmCmd, ['run', 'vite'], {
  stdio: 'inherit',
  shell: true,
  windowsHide: false
});

// Warte auf die Server-Initialisierung
setTimeout(() => {
  console.log('Starting Electron...');
  
  // Setze die Umgebungsvariable für Electron
  process.env.VITE_DEV_SERVER_URL = 'http://localhost:5173';
  
  // Starte Electron
  const electron = spawn(npmCmd, ['run', 'electron:start'], {
    stdio: 'inherit',
    shell: true,
    windowsHide: false
  });
  
  // Behandle das Beenden des Electron-Prozesses
  electron.on('close', (code) => {
    console.log(`Electron process exited with code ${code}`);
    server.kill();
    process.exit(code);
  });
}, 5000); // Warte 5 Sekunden, bis der Server gestartet ist

console.log('Starting development server and Electron...'); 