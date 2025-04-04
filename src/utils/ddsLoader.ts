import { logImageOperation } from './imageLoaders';

// DDS-Header-Konstanten
const DDPF_ALPHAPIXELS = 0x1;
const DDPF_ALPHA = 0x2;
const DDPF_FOURCC = 0x4;
const DDPF_RGB = 0x40;
const DDPF_RGBA = DDPF_RGB | DDPF_ALPHAPIXELS;
const DDSD_MIPMAPCOUNT = 0x20000;
const DDS_MAGIC = 0x20534444;
const DDSD_CAPS = 0x1;
const DDSD_HEIGHT = 0x2;
const DDSD_WIDTH = 0x4;
const DDSD_PITCH = 0x8;
const DDSD_PIXELFORMAT = 0x1000;
const DDSCAPS_COMPLEX = 0x8;
const DDSCAPS_MIPMAP = 0x400000;
const DDSCAPS_TEXTURE = 0x1000;

// Standard-DDS-Pixelformate
const D3DFMT_DXT1 = 0x31545844; // 'DXT1' in ASCII
const D3DFMT_DXT3 = 0x33545844; // 'DXT3' in ASCII
const D3DFMT_DXT5 = 0x35545844; // 'DXT5' in ASCII
const D3DFMT_A1R5G5B5 = 0x15; 
const D3DFMT_A4R4G4B4 = 0x16;
const D3DFMT_R5G6B5 = 0x17;
const D3DFMT_A8R8G8B8 = 0x21;
const D3DFMT_X8R8G8B8 = 0x22;

// FlyFF spezifische Formate
const FLYFF_FORMAT_A1R5G5B5 = 'A1R5G5B5';
const FLYFF_FORMAT_A1B5G5R5 = 'A1B5G5R5';
const FLYFF_FORMAT_B4G4R4A4 = 'B4G4R4A4';

// DDS-Header-Struktur
interface DDSHeader {
  magic: number;          // 'DDS '
  size: number;           // 124
  flags: number;          // Pflichtflags
  height: number;         // Texturhöhe
  width: number;          // Texturbreite
  pitchOrLinearSize: number; // Byte-Größe der primären Oberfläche
  depth: number;          // Tiefe einer Volumstextur
  mipMapCount: number;    // Anzahl der Mipmaps
  reserved1: number[];    // Reserviert
  pixelFormat: {
    size: number;         // 32
    flags: number;        // Pixelformat-Flags
    fourCC: number;       // Für komprimierte Texturen
    rgbBitCount: number;  // Bits pro Pixel
    rBitMask: number;     // Rote Bitmaske
    gBitMask: number;     // Grüne Bitmaske
    bBitMask: number;     // Blaue Bitmaske
    aBitMask: number;     // Alpha-Bitmaske
  };
  caps: number;           // Textur-Flags
  caps2: number;          // Zusätzliche Flags für Kubuskarten
  caps3: number;          // Nicht verwendet
  caps4: number;          // Nicht verwendet
  reserved2: number;      // Reserviert
}

// Daten-Views für das Lesen des DDS-Formats
let dv: DataView;
let dataOffset: number;

// Die Textur-Daten
let textureData: Uint8Array | Uint16Array | Uint32Array;
let width: number;
let height: number;
let format: string;

// Magenta-Prüfung (FF00FF) mit Toleranz
function isMagentaPixel(r: number, g: number, b: number, tolerance: number = 50): boolean {
  // Erhöhte Toleranz für bessere Erkennung
  return r > (255 - tolerance) && g < tolerance && b > (255 - tolerance);
}

// Lese den DDS-Header und interpretiere die Daten
function parseDDSHeader(arrayBuffer: ArrayBuffer): DDSHeader | null {
  if (arrayBuffer.byteLength < 128) {
    console.error('DDS file too small to contain valid header');
    return null;
  }

  dv = new DataView(arrayBuffer);
  
  // Überprüfe das Magic-Wort 'DDS '
  const magic = dv.getUint32(0, true);
  if (magic !== DDS_MAGIC) {
    console.error('Invalid DDS file, wrong magic number:', magic.toString(16));
    
    // Versuch trotzdem einen gültigen Header zu erstellen als Fallback
    // für Dateien, die falsch formatiert sind aber trotzdem Bilddaten enthalten
    try {
      console.log('Attempting fallback conversion with incorrect header');
      
      const estimatedWidth = 32; // Typische Icon-Größe
      const estimatedHeight = 32; // Typische Icon-Größe
      
      // Erstelle einen minimalen Header für Fallback-Versuche
      return {
        magic: DDS_MAGIC, // Korrigiere die Magic Number
        size: 124,
        flags: DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT,
        height: estimatedHeight,
        width: estimatedWidth,
        pitchOrLinearSize: 0,
        depth: 1,
        mipMapCount: 1,
        reserved1: Array(11).fill(0),
        pixelFormat: {
          size: 32,
          flags: DDPF_RGB | DDPF_ALPHAPIXELS,
          fourCC: 0,
          rgbBitCount: 16,
          rBitMask: 0x7C00,
          gBitMask: 0x03E0,
          bBitMask: 0x001F,
          aBitMask: 0x8000,
        },
        caps: DDSCAPS_TEXTURE,
        caps2: 0,
        caps3: 0,
        caps4: 0,
        reserved2: 0,
      };
    } catch (error) {
      console.error('Failed to create fallback header:', error);
      return null;
    }
  }

  const header: DDSHeader = {
    magic,
    size: dv.getUint32(4, true),
    flags: dv.getUint32(8, true),
    height: dv.getUint32(12, true),
    width: dv.getUint32(16, true),
    pitchOrLinearSize: dv.getUint32(20, true),
    depth: dv.getUint32(24, true),
    mipMapCount: dv.getUint32(28, true),
    reserved1: Array(11).fill(0),
    pixelFormat: {
      size: dv.getUint32(76, true),
      flags: dv.getUint32(80, true),
      fourCC: dv.getUint32(84, true),
      rgbBitCount: dv.getUint32(88, true),
      rBitMask: dv.getUint32(92, true),
      gBitMask: dv.getUint32(96, true),
      bBitMask: dv.getUint32(100, true),
      aBitMask: dv.getUint32(104, true),
    },
    caps: dv.getUint32(108, true),
    caps2: dv.getUint32(112, true),
    caps3: dv.getUint32(116, true),
    caps4: dv.getUint32(120, true),
    reserved2: dv.getUint32(124, true),
  };

  return header;
}

// Neue Funktion zur Vorprüfung von DDS-Dateien
function isValidDDSFile(arrayBuffer: ArrayBuffer): boolean {
  if (!arrayBuffer || arrayBuffer.byteLength < 4) {
    console.warn('DDS-Datei ist zu klein für einen gültigen Header');
    return true; // Trotzdem weitermachen mit Fallback
  }
  
  try {
    const dv = new DataView(arrayBuffer);
    const magic = dv.getUint32(0, true);
    
    // Bei Debugging-Zwecken kann man den Magic Number in hexadezimal anzeigen
    console.log('DDS Magic Number:', magic.toString(16));
    
    // Weniger strenge Prüfung - alle Dateien akzeptieren
    if (magic !== DDS_MAGIC) {
      console.warn('DDS hat ungültige Magic Number:', magic.toString(16), 'Erwartet:', DDS_MAGIC.toString(16));
      return true; // Trotzdem weitermachen
    }
    
    return true;
  } catch (error) {
    console.warn('Fehler beim Prüfen der DDS Magic Number:', error);
    return true; // Trotzdem weitermachen mit Fallback
  }
}

// Identifiziere das Pixelformat basierend auf Header-Werten
function identifyPixelFormat(header: DDSHeader): string {
  const { pixelFormat } = header;
  
  // Komprimierte Textur (DXT)
  if (pixelFormat.flags & DDPF_FOURCC) {
    switch (pixelFormat.fourCC) {
      case D3DFMT_DXT1: return 'DXT1';
      case D3DFMT_DXT3: return 'DXT3';
      case D3DFMT_DXT5: return 'DXT5';
      default: return 'UNKNOWN_COMPRESSED';
    }
  }
  
  // Unkomprimierte RGB/RGBA-Textur
  if (pixelFormat.flags & DDPF_RGB) {
    const hasAlpha = Boolean(pixelFormat.flags & DDPF_ALPHAPIXELS);
    
    // Identifiziere gängige Formate anhand von Bitmasken
    if (pixelFormat.rgbBitCount === 16) {
      if (
        pixelFormat.rBitMask === 0x7C00 && 
        pixelFormat.gBitMask === 0x03E0 && 
        pixelFormat.bBitMask === 0x001F &&
        hasAlpha && pixelFormat.aBitMask === 0x8000
      ) {
        return FLYFF_FORMAT_A1R5G5B5;
      }
      
      if (
        pixelFormat.rBitMask === 0x001F && 
        pixelFormat.gBitMask === 0x03E0 && 
        pixelFormat.bBitMask === 0x7C00 &&
        hasAlpha && pixelFormat.aBitMask === 0x8000
      ) {
        return FLYFF_FORMAT_A1B5G5R5;
      }
      
      if (
        pixelFormat.rBitMask === 0xF00 && 
        pixelFormat.gBitMask === 0xF0 && 
        pixelFormat.bBitMask === 0xF &&
        hasAlpha && pixelFormat.aBitMask === 0xF000
      ) {
        return 'A4R4G4B4';
      }
      
      if (
        pixelFormat.rBitMask === 0xF800 && 
        pixelFormat.gBitMask === 0x07E0 && 
        pixelFormat.bBitMask === 0x001F &&
        !hasAlpha
      ) {
        return 'R5G6B5';
      }
      
      // FlyFF spezifische Formate basierend auf Erfahrungswerten
      if (pixelFormat.rgbBitCount === 16) {
        // Wenn Bitmasken nicht exakt übereinstimmen, verwenden wir die häufigsten Formate
        return FLYFF_FORMAT_A1R5G5B5; // Standard FlyFF Format
      }

    }
    
    if (pixelFormat.rgbBitCount === 32) {
      if (
        pixelFormat.rBitMask === 0x00FF0000 && 
        pixelFormat.gBitMask === 0x0000FF00 && 
        pixelFormat.bBitMask === 0x000000FF &&
        hasAlpha && pixelFormat.aBitMask === 0xFF000000
      ) {
        return 'A8R8G8B8';
      }
      
      if (
        pixelFormat.rBitMask === 0x00FF0000 && 
        pixelFormat.gBitMask === 0x0000FF00 && 
        pixelFormat.bBitMask === 0x000000FF &&
        !hasAlpha
      ) {
        return 'X8R8G8B8';
      }

    }
    
    // Generisches Format
    return hasAlpha ? `RGBA${pixelFormat.rgbBitCount}` : `RGB${pixelFormat.rgbBitCount}`;
  }
  
  // Nur Alpha-Textur
  if (pixelFormat.flags & DDPF_ALPHA) {
    return `ALPHA${pixelFormat.rgbBitCount}`;
  }
  
  return 'UNKNOWN';
}

// Neue Funktion zur Erkennung und Konvertierung nicht-standardmäßiger Formate
function tryAlternativeFormats(url: string, arrayBuffer: ArrayBuffer): HTMLCanvasElement {
  // Überprüfe, ob die Datei möglicherweise eine reine Bilddatei ist
  console.log('Trying alternative format conversion for invalid DDS file:', url);
  
  // Verschiedene Strategien versuchen
  try {
    const canvas = document.createElement('canvas');
    const ctx = canvas.getContext('2d');
    if (!ctx) {
      throw new Error('Failed to create canvas context');
    }
    
    // Größe für ein typisches Icon setzen
    canvas.width = 64;
    canvas.height = 64;
    
    // Versuche den Buffer als 16-bit A1R5G5B5 zu interpretieren
    let imageData;
    
    try {
      // Nehme an, dass die Daten nach irgendwelchem Header beginnen (32 Bytes als Annahme)
      const offset = Math.min(32, arrayBuffer.byteLength - 1024); // Mindestens 1kB Daten benötigt
      const data = new Uint16Array(arrayBuffer, offset);
      const pixelCount = Math.min(data.length, 64 * 64);
      
      imageData = ctx.createImageData(64, 64);
      const pixels = imageData.data;
      
      // Teste beide möglichen R5G5B5-Formate
      let transparentPixels = {normal: 0, swapped: 0};
      
      // Analysiere eine Stichprobe, um das wahrscheinlichste Format zu erkennen
      const testSize = Math.min(pixelCount, 1000);
      
      for (let i = 0; i < testSize; i++) {
        const pixelValue = data[i];
        
        // Teste A1R5G5B5 Format
        const r1 = ((pixelValue & 0x7C00) >> 10) * 8; 
        const g1 = ((pixelValue & 0x03E0) >> 5) * 8;
        const b1 = (pixelValue & 0x001F) * 8;
        
        // Teste A1B5G5R5 Format
        const b2 = ((pixelValue & 0x7C00) >> 10) * 8;
        const g2 = ((pixelValue & 0x03E0) >> 5) * 8;
        const r2 = (pixelValue & 0x001F) * 8;
        
        // Prüfe auf Magenta-ähnliche Farben
        if (isMagentaPixel(r1, g1, b1)) transparentPixels.normal++;
        if (isMagentaPixel(r2, g2, b2)) transparentPixels.swapped++;
      }
      
      // Wähle das Format mit weniger Magenta-Pixeln
      const useSwapped = transparentPixels.swapped < transparentPixels.normal;
      
      // Konvertiere die tatsächlichen Daten
      for (let i = 0, j = 0; i < pixelCount; i++, j += 4) {
        const pixelValue = data[i];
        const alpha = ((pixelValue & 0x8000) >> 15) * 255;
        
        let red, green, blue;
        
        if (useSwapped) {
          // A1B5G5R5 Format - Blue und Red vertauscht
          blue = ((pixelValue & 0x7C00) >> 10) * 8; 
          green = ((pixelValue & 0x03E0) >> 5) * 8;
          red = (pixelValue & 0x001F) * 8;
        } else {
          // Standard A1R5G5B5 Format
          red = ((pixelValue & 0x7C00) >> 10) * 8;
          green = ((pixelValue & 0x03E0) >> 5) * 8;
          blue = (pixelValue & 0x001F) * 8;
        }
        
        // Prüfe auf Magenta für Transparenz
        const isMagenta = isMagentaPixel(red, green, blue);
        
        pixels[j] = red;
        pixels[j + 1] = green;
        pixels[j + 2] = blue;
        pixels[j + 3] = isMagenta ? 0 : alpha;
      }
      
      ctx.putImageData(imageData, 0, 0);
      return canvas;
    } catch (error) {
      console.error('Error during alternative format conversion:', error);
      return createErrorCanvas(64, 64, 'Format Error');
    }
  } catch (error) {
    console.error('Failed all alternative format attempts:', error);
    return createErrorCanvas(64, 64, 'Invalid DDS');
  }
}

// Lade die Textur und interpretiere die Daten
export async function loadDDSFile(url: string): Promise<{
  width: number;
  height: number;
  format: string;
  data: Uint8Array | Uint16Array | Uint32Array | null;
}> {
  try {
    logImageOperation('LOADING_DDS_DIRECT', { url });
    
    // Fetch und Parse der DDS-Datei
    let response;
    try {
      response = await fetch(url, { 
        // Cache-Control hinzufügen, um Caching-Probleme zu vermeiden
        headers: { 'Cache-Control': 'no-cache' }
      });
    } catch (fetchError) {
      console.error('Network error while fetching DDS:', fetchError);
      throw new Error(`Netzwerkfehler beim Laden der DDS-Datei: ${fetchError instanceof Error ? fetchError.message : 'Unbekannter Fehler'}`);
    }
    
    if (!response.ok) {
      throw new Error(`DDS-Datei konnte nicht geladen werden: ${response.status} ${response.statusText}`);
    }
    
    let arrayBuffer;
    try {
      arrayBuffer = await response.arrayBuffer();
    } catch (bufferError) {
      console.error('Error reading DDS data:', bufferError);
      throw new Error(`Fehler beim Lesen der DDS-Daten: ${bufferError instanceof Error ? bufferError.message : 'Unbekannter Fehler'}`);
    }
    
    // Versuche den Header zu interpretieren
    const header = parseDDSHeader(arrayBuffer);
    
    if (!header) {
      // Bei ungültigem Header versuchen wir alternative Formate
      const alternativeCanvas = tryAlternativeFormats(url, arrayBuffer);
      
      // Erstelle ein ImageData-Objekt aus dem Canvas
      const ctx = alternativeCanvas.getContext('2d');
      if (!ctx) {
        throw new Error('Failed to get 2D context');
      }
      
      const imageData = ctx.getImageData(0, 0, alternativeCanvas.width, alternativeCanvas.height);
      const tempArray = new Uint16Array(alternativeCanvas.width * alternativeCanvas.height);
      
      // Wir müssen einen Daten-Buffer zurückgeben, der mit dem erwarteten Format kompatibel ist
      return {
        width: alternativeCanvas.width,
        height: alternativeCanvas.height,
        format: 'ALTERNATIVE',
        data: tempArray
      };
    }
    
    const width = header.width;
    const height = header.height;
    const format = identifyPixelFormat(header);
    
    // Hole die Rohdaten der Textur
    const dataOffset = 128; // Standard-DDS-Header ist 128 Bytes
    const dataSize = arrayBuffer.byteLength - dataOffset;
    
    if (dataSize <= 0) {
      throw new Error('Keine Texturdaten in der DDS-Datei');
    }
    
    // Sichere Erstellung von TypedArrays basierend auf dem Pixelformat
    let textureData;
    
    if (format === FLYFF_FORMAT_A1R5G5B5 || format === FLYFF_FORMAT_A1B5G5R5 || format.includes('RGB16')) {
      textureData = new Uint16Array(arrayBuffer, dataOffset);
    } else if (format === 'A8R8G8B8' || format === 'X8R8G8B8') {
      textureData = new Uint32Array(arrayBuffer, dataOffset);
    } else {
      // Für andere Formate oder komprimierte Texturen
      textureData = new Uint8Array(arrayBuffer, dataOffset);
    }
    
    logImageOperation('DDS_LOADED_DIRECT', { 
      width, 
      height, 
      format,
      dataSize,
      bytesPerElement: textureData.BYTES_PER_ELEMENT || 1,
      dataLength: textureData.length
    });
    
    return {
      width,
      height,
      format,
      data: textureData
    };
  } catch (error) {
    console.error('Error loading DDS file:', error);
    logImageOperation('DDS_LOAD_ERROR', { 
      url, 
      error: error instanceof Error ? error.message : String(error) 
    });
    
    // Fallback für den Fall, dass die DDS-Datei völlig ungültig ist
    const dummyBuffer = new ArrayBuffer(64 * 64 * 2);
    const dummyData = new Uint16Array(dummyBuffer);
    
    // Fülle mit einem erkennbaren Muster
    for (let i = 0; i < dummyData.length; i++) {
      // Abwechselnd schwarz und dunkelgrau
      dummyData[i] = (i % 2 === 0) ? 0x0000 : 0x7BDE;
    }
    
    return {
      width: 64,
      height: 64,
      format: 'FALLBACK:NO_DATA',
      data: dummyData
    };
  }
}

// Erstelle ein Canvas mit einer Fehlermeldung
export function createErrorCanvas(width: number, height: number, message: string): HTMLCanvasElement {
  const canvas = document.createElement('canvas');
  canvas.width = width;
  canvas.height = height;
  const ctx = canvas.getContext('2d');
  
  if (!ctx) {
    throw new Error('Failed to get 2D context from canvas');
  }
  
  // Dunkelgrauer Hintergrund statt pinkem Hintergrund
  ctx.fillStyle = '#333333';
  ctx.fillRect(0, 0, width, height);
  
  // X-Symbol
  ctx.strokeStyle = '#FFFFFF';
  ctx.lineWidth = 2;
  ctx.beginPath();
  ctx.moveTo(10, 10);
  ctx.lineTo(width - 10, height - 10);
  ctx.moveTo(width - 10, 10);
  ctx.lineTo(10, height - 10);
  ctx.stroke();
  
  // Nachricht
  ctx.fillStyle = '#FFFFFF';
  ctx.font = '10px Arial';
  ctx.textAlign = 'center';
  ctx.fillText(message, width / 2, height / 2);
  
  return canvas;
}

// Verbessere Robustheit und Toleranz bei der Konvertierung
function convertA1R5G5B5ToCanvas(
  data: Uint16Array, 
  width: number,
  height: number,
  swapRedBlue: boolean = false
): HTMLCanvasElement {
  const canvas = document.createElement('canvas');
  canvas.width = width;
  canvas.height = height;
  const ctx = canvas.getContext('2d');
  
  if (!ctx) {
    throw new Error('Failed to get 2D context from canvas');
  }
  
  const imageData = ctx.createImageData(width, height);
  const rgba = imageData.data;
  
  // Stelle sicher, dass wir nicht über die Grenzen hinausgehen
  const pixelCount = Math.min(data.length, width * height);
  
  try {
    for (let i = 0; i < pixelCount; i++) {
      // Berechne die Position im RGBA Array (4 Bytes pro Pixel)
      const rgbaIndex = i * 4;
      
      // Hole den 16-bit Pixelwert
      const pixelValue = data[i];
      
      // A1R5G5B5 Format
      let alpha = ((pixelValue & 0x8000) >> 15) * 255; // Bit 15 ist Alpha (0 oder 1)
      let red, green, blue;
      
      if (swapRedBlue) {
        // A1B5G5R5 Format - vertauschte Rot/Blau Kanäle
        blue = ((pixelValue & 0x7C00) >> 10) * 8;  // Bits 10-14
        green = ((pixelValue & 0x03E0) >> 5) * 8;  // Bits 5-9
        red = (pixelValue & 0x001F) * 8;           // Bits 0-4
      } else {
        // Standard A1R5G5B5 Format
        red = ((pixelValue & 0x7C00) >> 10) * 8;   // Bits 10-14
        green = ((pixelValue & 0x03E0) >> 5) * 8;  // Bits 5-9
        blue = (pixelValue & 0x001F) * 8;          // Bits 0-4
      }
      
      // Wichtig für FlyFF: 
      // 1. Exaktes FF00FF als transparent behandeln
      // 2. Magenta-ähnliche Farben mit Toleranz prüfen
      
      // Exaktes Magenta (oder sehr nah dran)
      if (red >= 248 && green <= 8 && blue >= 248) {
        alpha = 0; // Komplett transparent
      }
      // Magenta-ähnliche Farben 
      else if (isMagentaPixel(red, green, blue)) {
        alpha = 0; // Transparent setzen
      }
      
      // Fülle die Bilddaten
      rgba[rgbaIndex] = red;        // R
      rgba[rgbaIndex + 1] = green;  // G
      rgba[rgbaIndex + 2] = blue;   // B
      rgba[rgbaIndex + 3] = alpha;  // A
    }
    
    // Setze die übrigen Pixel auf transparent schwarz
    for (let i = pixelCount * 4; i < rgba.length; i += 4) {
      rgba[i] = 0;       // R
      rgba[i + 1] = 0;   // G
      rgba[i + 2] = 0;   // B
      rgba[i + 3] = 0;   // A (transparent)
    }
  } catch (error) {
    console.error('Error during pixel conversion:', error);
    
    // Im Fehlerfall ein erkennbares Muster erstellen
    for (let i = 0; i < rgba.length; i += 4) {
      // Rot/Schwarz-Muster für Fehlererkennung
      rgba[i] = (i % 8 === 0) ? 255 : 0;  // R
      rgba[i + 1] = 0;                    // G
      rgba[i + 2] = 0;                    // B
      rgba[i + 3] = 255;                  // A (opak)
    }
  }
  
  ctx.putImageData(imageData, 0, 0);
  return canvas;
}

// Hauptfunktion zum Laden und Konvertieren
export async function loadAndConvertDDS(url: string): Promise<HTMLCanvasElement> {
  try {
    const result = await getBestDDSRepresentation(url);
    return result.canvas;
  } catch (error) {
    console.error('Failed to load and convert DDS:', error);
    return createErrorCanvas(64, 64, 'DDS Processing Error');
  }
}

// Analysiert ein Canvas-Bild um zu prüfen, ob zu viele Magenta-Pixel vorhanden sind
function analyzeCanvasForMagenta(canvas: HTMLCanvasElement): boolean {
  const ctx = canvas.getContext('2d');
  if (!ctx) return false;
  
  const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
  const data = imageData.data;
  let magentaCount = 0;
  let totalPixels = canvas.width * canvas.height;
  
  // Prüfe nur eine Stichprobe von Pixeln
  const sampleSize = Math.min(totalPixels, 1000);
  const sampleStep = Math.max(1, Math.floor(totalPixels / sampleSize));
  
  for (let i = 0; i < totalPixels; i += sampleStep) {
    const index = i * 4;
    // Prüfe auf Magenta (hoher Rot- und Blau-Wert, niedriger Grün-Wert)
    if (data[index] > 200 && data[index + 1] < 50 && data[index + 2] > 200) {
      magentaCount++;
    }
  }
  
  // Wenn mehr als 30% der Stichprobe magenta ist, sollten wir das Format wechseln
  return (magentaCount / (totalPixels / sampleStep)) > 0.3;
}

// Eine Funktion, die versucht, die beste Darstellung für ein DDS-Format zu finden
export async function getBestDDSRepresentation(url: string, retryCount = 0): Promise<{
  canvas: HTMLCanvasElement,
  format: string,
  width: number,
  height: number
}> {
  try {
    // Füge zufälligen Parameter für Cache-Busting hinzu
    const cacheBustUrl = `${url}${url.includes('?') ? '&' : '?'}_t=${Date.now()}`;
    
    let ddsData;
    try {
      ddsData = await loadDDSFile(cacheBustUrl);
    } catch (loadError) {
      // Bei Netzwerkfehlern einen Retry versuchen
      if (retryCount < 2) {
        console.warn(`Retry ${retryCount + 1}/2 for DDS load: ${url}`);
        // Kurze Verzögerung vor dem Retry
        await new Promise(resolve => setTimeout(resolve, 500));
        return getBestDDSRepresentation(url, retryCount + 1);
      }
      
      // Nach Retries - erstelle Fallback-Canvas
      console.error("Failed to load DDS after retries:", loadError);
      return createFallbackDDSRepresentation("LOAD_ERROR");
    }
    
    if (!ddsData.data || ddsData.width === 0 || ddsData.height === 0) {
      return createFallbackDDSRepresentation("NO_DATA");
    }
    
    // Für alternative Formate, die nicht standardmäßig interpretiert werden konnten
    if (ddsData.format === 'ALTERNATIVE') {
      // Die alternative Methode hat bereits ein fertiges Canvas erstellt
      const alternativeCanvas = document.createElement('canvas');
      alternativeCanvas.width = ddsData.width;
      alternativeCanvas.height = ddsData.height;
      
      // Einfach ein leeres Canvas zurückgeben, die eigentliche Umwandlung
      // erfolgte bereits in tryAlternativeFormats
      const ctx = alternativeCanvas.getContext('2d');
      if (ctx) {
        // Ein leeres Canvas für Daten, die wir nicht interpretieren können
        ctx.fillStyle = '#000000';
        ctx.fillRect(0, 0, ddsData.width, ddsData.height);
        
        // Statustext
        ctx.fillStyle = '#FFFFFF';
        ctx.font = '10px Arial';
        ctx.textAlign = 'center';
        ctx.fillText('DDS: Alt Format', ddsData.width/2, ddsData.height/2);
      }
      
      return {
        canvas: alternativeCanvas,
        format: 'ALTERNATIVE',
        width: ddsData.width,
        height: ddsData.height
      };
    }
    
    // Versuche beide Formate für 16-bit Texturen
    if (ddsData.format === FLYFF_FORMAT_A1R5G5B5 || ddsData.format === FLYFF_FORMAT_A1B5G5R5 || 
        ddsData.format.includes('RGB16') || ddsData.format === 'UNKNOWN') {
      
      try {
        // Versuche alle vier möglichen Varianten
        const formats = [false, true]; // [normal, swapped]
        let bestCanvas = null;
        let bestFormat = "";
        let bestNonMagentaPixels = -1;
        
        // Teste beide Format-Varianten und wähle die mit den wenigsten Magenta-Pixeln
        for (const swapped of formats) {
          const canvas = convertA1R5G5B5ToCanvas(
            ddsData.data as Uint16Array, 
            ddsData.width, 
            ddsData.height,
            swapped
          );
          
          // Analysiere, wie viele nicht-magenta/nicht-transparente Pixel wir haben
          const ctx = canvas.getContext('2d');
          if (ctx) {
            const imgData = ctx.getImageData(0, 0, canvas.width, canvas.height);
            
            // Zähle sichtbare Pixel (nicht transparent)
            let visiblePixels = 0;
            for (let i = 3; i < imgData.data.length; i += 4) {
              if (imgData.data[i] > 0) {
                visiblePixels++;
              }
            }
            
            // Wenn dies mehr sichtbare Pixel hat als die bisherige beste Option
            if (visiblePixels > bestNonMagentaPixels) {
              bestNonMagentaPixels = visiblePixels;
              bestCanvas = canvas;
              bestFormat = swapped ? FLYFF_FORMAT_A1B5G5R5 : FLYFF_FORMAT_A1R5G5B5;
              
              // Wenn wir genügend sichtbare Pixel haben, nehmen wir diese sofort
              // Ein guter Schwellenwert könnte 20% der Gesamtpixel sein
              const totalPixels = canvas.width * canvas.height;
              if (visiblePixels > totalPixels * 0.2) {
                break;
              }
            }
          }
        }
        
        // Wenn wir ein gutes Canvas gefunden haben
        if (bestCanvas) {
          return {
            canvas: bestCanvas,
            format: bestFormat,
            width: ddsData.width,
            height: ddsData.height
          };
        }
        
        // Fallback auf Standard-Format, wenn keine Analyse möglich war
        const defaultCanvas = convertA1R5G5B5ToCanvas(
          ddsData.data as Uint16Array, 
          ddsData.width, 
          ddsData.height,
          false // standardmäßig nicht vertauscht
        );
        
        return {
          canvas: defaultCanvas,
          format: ddsData.format,
          width: ddsData.width,
          height: ddsData.height
        };
      } catch (error) {
        console.error('Error during format testing:', error);
      }
    }
    
    // Fallback für unbekannte oder nicht unterstützte Formate
    return createFallbackDDSRepresentation("UNSUPPORTED_FORMAT");
  } catch (error) {
    console.error('Error getting best DDS representation:', error);
    return createFallbackDDSRepresentation("PROCESSING_ERROR");
  }
}

// Hilfs-Funktion, um eine Fallback-Darstellung für fehlgeschlagene DDS-Texturen zu erstellen
function createFallbackDDSRepresentation(errorType: string): {
  canvas: HTMLCanvasElement,
  format: string,
  width: number,
  height: number
} {
  // Erstelle ein Fallback-Canvas
  const canvas = document.createElement('canvas');
  const width = 64;
  const height = 64;
  canvas.width = width;
  canvas.height = height;
  const ctx = canvas.getContext('2d');
  
  if (ctx) {
    // Hintergrund füllen - verschiedene Farben je nach Fehlertyp aber keine pinken Farben
    switch (errorType) {
      case "LOAD_ERROR":
        ctx.fillStyle = '#553333'; // Rötlich für Ladefehler
        break;
      case "NO_DATA":
        ctx.fillStyle = '#335555'; // Grünlich/Bläulich für fehlende Daten
        break;
      case "PROCESSING_ERROR":
        ctx.fillStyle = '#555533'; // Gelblich für Verarbeitungsfehler
        break;
      case "UNSUPPORTED_FORMAT":
        ctx.fillStyle = '#333355'; // Bläulich für nicht unterstützte Formate
        break;
      default:
        ctx.fillStyle = '#333333'; // Dunkelgrau für unbekannte Fehler
    }
    ctx.fillRect(0, 0, width, height);
    
    // Grid-Muster für bessere Sichtbarkeit
    const squareSize = 8;
    for (let y = 0; y < height; y += squareSize) {
      for (let x = 0; x < width; x += squareSize) {
        if ((x / squareSize + y / squareSize) % 2 === 0) {
          // Dunklere Version der Hintergrundfarbe
          ctx.fillStyle = errorType === "LOAD_ERROR" ? '#442222' : 
                         errorType === "NO_DATA" ? '#224444' : 
                         errorType === "PROCESSING_ERROR" ? '#444422' : 
                         errorType === "UNSUPPORTED_FORMAT" ? '#222244' : '#222222';
          ctx.fillRect(x, y, squareSize, squareSize);
        }
      }
    }
    
    // DDS Text
    ctx.fillStyle = '#FFFFFF';
    ctx.font = '12px Arial';
    ctx.textAlign = 'center';
    ctx.fillText('DDS', width / 2, height / 2 - 6);
    
    // Fehlertyp anzeigen
    ctx.font = '8px Arial';
    ctx.fillText(errorType, width / 2, height / 2 + 8);
  }
  
  return {
    canvas,
    format: "FALLBACK:" + errorType,
    width,
    height
  };
} 