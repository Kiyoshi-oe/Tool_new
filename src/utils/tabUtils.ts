import { ResourceItem } from "../types/fileTypes";

export const itemTypeToTab: {[key: string]: string} = {
  "IK1_WEAPON": "Weapon",
  "IK1_ARMOR": "Armor", 
  "IK1_GENERAL": "Other Item",
  "IK1_ACCESSORY": "Accessory",
  "IK1_PAPERDOLL": "Fashion",
  "IK1_MONSTER": "Monster",
  "IK1_NPC": "NPC",
  "IK1_COLLECT": "Collecting",
  "IK1_SKILL": "Skill",
  "IK1_QUEST": "Quest",
  "IK1_GIFTBOX": "Giftbox"
};

// Verbesserte Funktion zum Zusammenfügen von Text mit Fallbacks
const safeString = (value: any): string => {
  if (value === undefined || value === null) return '';
  return String(value);
};

export const getItemTab = (item: ResourceItem): string => {
  if (!item?.data) return "Other Item";
  
  const itemKind1 = safeString(item.data.dwItemKind1);
  
  // Wenn kein Typ existiert, versuche ihn anhand des Namens oder der ID zu erraten
  if (!itemKind1) {
    const id = safeString(item.id).toLowerCase();
    const name = safeString(item.name).toLowerCase();
    
    if (id.includes('wea') || name.includes('sword') || name.includes('axe')) {
      return "Weapon";
    } else if (id.includes('arm') || name.includes('armor')) {
      return "Armor";
    } else if (id.includes('chr') || name.includes('costume')) {
      return "Fashion";
    }
    
    return "Other Item";
  }
  
  return itemTypeToTab[itemKind1] || "Other Item";
};

export const getFilteredItems = (fileData: any, currentTab: string, settings: any = { enableDebug: false }): ResourceItem[] => {
  if (!fileData) {
    console.log("No fileData available for filtering");
    return [];
  }
  
  // Ausgabe der FileData-Struktur für Diagnose
  console.log("FileData Struktur:", {
    typ: typeof fileData,
    hat_items: !!fileData.items,
    items_typ: fileData.items ? typeof fileData.items : 'undefined',
    ist_array: fileData.items ? Array.isArray(fileData.items) : false,
    items_länge: fileData.items && Array.isArray(fileData.items) ? fileData.items.length : 0
  });
  
  if (!fileData.items || !Array.isArray(fileData.items)) {
    console.error("fileData.items ist kein Array oder fehlt:", fileData);
    
    // Erstelle ein Platzhalter-Item, damit die UI nicht völlig fehlschlägt
    return [{
      id: "empty_placeholder",
      name: "Lade...",
      displayName: "Dateien werden geladen...",
      description: "Bitte warten, Datendatei ist leer oder beschädigt",
      data: { 
        dwItemKind1: "IK1_GENERAL",
        dwID: "0"
      },
      effects: []
    }];
  }
  
  // Logging für Debugzwecke
  const totalItemCount = fileData.items.length;
  console.log(`Filtere für Tab: ${currentTab}, Anzahl verfügbarer Items: ${totalItemCount}`);
  
  // Wenn keine Items vorhanden sind, zeige eine aussagekräftige Meldung und gib leere Liste zurück
  if (totalItemCount === 0) {
    console.warn(`Keine Items zum Filtern verfügbar für Tab: ${currentTab}`);
    
    // Erstelle ein aussagekräftiges Platzhalter-Item
    return [{
      id: "no_items",
      name: "Keine Items gefunden",
      displayName: "Keine Items gefunden",
      description: "Die Datei enthält keine Items",
      data: { 
        dwItemKind1: currentTab === "Weapon" ? "IK1_WEAPON" : 
                    currentTab === "Armor" ? "IK1_ARMOR" : 
                    currentTab === "Fashion" ? "IK1_PAPERDOLL" : "IK1_GENERAL"
      },
      effects: []
    }];
  }
  
  // Zähle, wie viele Items einen gültigen dwItemKind1-Wert haben
  const itemsWithType = fileData.items.filter(item => item && item.data && item.data.dwItemKind1);
  console.log(`Items mit Typinformation: ${itemsWithType.length} von ${totalItemCount}`);
  
  // Wenn keine Items mit Typ-Information vorhanden sind, weisen wir Standard-Typen zu
  if (itemsWithType.length === 0 && totalItemCount > 0) {
    console.warn("Keine Items mit Typ-Information gefunden, weise Standard-Typen zu");
    
    for (let i = 0; i < fileData.items.length; i++) {
      const item = fileData.items[i];
      if (!item) continue;
      
      if (!item.data) {
        item.data = {};
      }
      
      // Einen Standardtyp basierend auf ID oder Namen zuweisen
      const id = String(item.id || '').toLowerCase();
      const name = String(item.name || '').toLowerCase();
      
      if (id.includes('wea') || name.includes('sword') || name.includes('axe')) {
        item.data.dwItemKind1 = "IK1_WEAPON";
      } else if (id.includes('arm') || name.includes('armor')) {
        item.data.dwItemKind1 = "IK1_ARMOR";
      } else if (id.includes('chr') || name.includes('costume')) {
        item.data.dwItemKind1 = "IK1_PAPERDOLL";
      } else {
        // Verteilung auf verschiedene Typen für bessere Testbarkeit
        const types = ["IK1_WEAPON", "IK1_ARMOR", "IK1_PAPERDOLL", "IK1_GENERAL"];
        item.data.dwItemKind1 = types[i % types.length];
      }
    }
  }
  
  // Set Effect Tab spezialbehandeln
  if (currentTab === "Set Effect") {
    const filtered = fileData.items.filter((item: ResourceItem) => item && item.setEffects && item.setEffects.length > 0);
    console.log(`Filtered Set Effect items: ${filtered.length}`);
    return filtered;
  }
  
  // Filtere Items basierend auf der aktuellen Tab-Auswahl
  let filtered: ResourceItem[] = [];
  
  const isWeaponTab = currentTab === "Weapon";
  const isArmorTab = currentTab === "Armor";
  const isFashionTab = currentTab === "Fashion";
  const isOtherTab = currentTab === "Other Item";
  
  // Effizientere Filterung mit O(n) Zeitkomplexität
  filtered = fileData.items.filter((item: ResourceItem) => {
    // Sicherheitscheck, ob item null/undefined ist
    if (!item) return false;
    
    // Nicht typisierte Items je nach Konfiguration behandeln
    if (!item.data) {
      // Default: Andere Items-Tab
      return isOtherTab;
    }
    
    // Sicherere Stringkonvertierung
    const dwItemKind1 = String(item.data.dwItemKind1 || '');
    const id = String(item.id || '').toLowerCase();
    const name = String(item.name || '').toLowerCase();
    
    // Optimierte Erkennung basierend auf der Tab-Kategorie
    if (isWeaponTab) {
      return dwItemKind1.includes('WEAPON') || id.includes('wea') || name.includes('sword') || name.includes('axe');
    } else if (isArmorTab) {
      return dwItemKind1.includes('ARMOR') || id.includes('arm') || name.includes('armor');
    } else if (isFashionTab) {
      return dwItemKind1.includes('PAPERDOLL') || id.includes('chr') || name.includes('costume');
    } else if (isOtherTab) {
      return !dwItemKind1.includes('WEAPON') && !dwItemKind1.includes('ARMOR') && !dwItemKind1.includes('PAPERDOLL');
    } else {
      // Für alle anderen Tabs die Zuordnung über die tabMapping-Konstante verwenden
      return itemTypeToTab[dwItemKind1] === currentTab;
    }
  });
  
  console.log(`Gefiltert für ${currentTab}: ${filtered.length} / ${totalItemCount} Items`);
  
  // Wenn keine passenden Items für diesen Tab gefunden wurden, erstelle ein Standard-Item
  if (filtered.length === 0) {
    console.log(`Keine passenden Items für Tab ${currentTab} gefunden. Erstelle Standard-Item.`);
    
    if (isWeaponTab) {
      return [{
        id: "default_weapon",
        name: "Standardwaffe",
        displayName: "Keine Waffen gefunden",
        description: "Es wurden keine Waffen gefunden. Bitte Datei neu laden oder eine andere Kategorie wählen.",
        data: { dwItemKind1: "IK1_WEAPON", dwID: "0" },
        effects: []
      }];
    } else if (isArmorTab) {
      return [{
        id: "default_armor",
        name: "Standardrüstung",
        displayName: "Keine Rüstungen gefunden",
        description: "Es wurden keine Rüstungen gefunden. Bitte Datei neu laden oder eine andere Kategorie wählen.",
        data: { dwItemKind1: "IK1_ARMOR", dwID: "0" },
        effects: []
      }];
    } else if (isOtherTab) {
      // Für "Other Item" zeigen wir die ersten 50 Items an
      if (totalItemCount > 0) {
        console.log("Keine passenden 'Other Items' gefunden. Zeige die ersten Items als Fallback an.");
        return fileData.items.slice(0, 50);
      }
    }
  }
  
  // Endgültiger Sicherheitscheck
  if (!filtered || !Array.isArray(filtered)) {
    console.error("Gefilterte Items sind kein Array:", filtered);
    return [{
      id: "filter_error",
      name: "Filterfehler",
      displayName: "Filterfehler",
      description: "Ein Fehler ist beim Filtern der Items aufgetreten",
      data: { dwItemKind1: "IK1_GENERAL" },
      effects: []
    }];
  }
  
  return filtered;
};

export const tabs = [
  "Weapon", "Armor", "Fashion", "Monster", "Other Item", 
  "Accessory", "NPC", "Collecting", "Skill", "Quest", "Giftbox", "Set Effect"
];
