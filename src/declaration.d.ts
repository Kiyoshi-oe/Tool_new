// Type definitions for Electron API in the renderer process

interface ElectronAPI {
  saveFile: (savePath: string, content: string) => Promise<any>;
  saveAllFiles: (files: any[], savePath: string) => Promise<any>;
  loadAllFiles: () => Promise<any>;
  getResourcePath: (subPath: string) => Promise<any>;
  onSaveFileResponse: (callback: (data: any) => void) => void;
}

declare global {
  interface Window {
    electronAPI?: ElectronAPI;
  }
}

export {}; 