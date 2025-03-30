import { CollectorData, CollectingEnchant, CollectingItem, CollectorValidationResult } from "../types/collectorTypes";

/**
 * Parst die Collector-Daten aus der s.txt-Datei
 */
export const parseCollectorData = (content: string): CollectorData => {
  const data: CollectorData = {
    enchant: [],
    items: [],
    premiumItems: [],
    premiumStatusItems: [],
    enchantTotal: 0,
    itemsTotal: 0,
    premiumItemsTotal: 0,
    premiumStatusItemsTotal: 0
  };
  
  console.log("Parsing content:", content);
  
  try {
    // Format mit geschweiften Klammern unterstützen
    // Enchant-Daten extrahieren
    const enchantMatch = content.match(/[Cc]ollecting_[Ee]nchant[^{]*{([^}]*)}/s);
    if (enchantMatch && enchantMatch[1]) {
      const enchantLines = enchantMatch[1].split('\n')
        .map(line => line.trim())
        .filter(line => {
          // Leere Zeilen und reine Kommentarzeilen überspringen
          // Wir suchen nach Zeilen, die mit einer Ziffer beginnen
          return line && !line.startsWith('//') && /^\s*\d+/.test(line);
        });
      
      data.enchant = enchantLines.map((line, index) => {
        // Entferne Kommentare (alles nach //)
        const parts = line.split('//')[0].trim().split(/\s+/);
        const chance = parseInt(parts[0], 10);
        
        // Versuche, den Level aus Kommentaren zu extrahieren, sonst verwende Index
        let level = index;
        if (line.includes('//')) {
          const commentPart = line.split('//')[1].trim();
          const levelMatch = commentPart.match(/\d+/);
          if (levelMatch) {
            level = parseInt(levelMatch[0], 10);
          }
        }
        
        return {
          level,
          chance
        };
      });
      
      data.enchantTotal = data.enchant.reduce((sum, item) => sum + item.chance, 0);
    }
    
    // Item-Daten extrahieren
    const itemMatch = content.match(/[Cc]ollecting_[Ii]tem(?!\s*_)[^{]*{([^}]*)}/s);
    if (itemMatch && itemMatch[1]) {
      const itemLines = itemMatch[1].split('\n')
        .map(line => line.trim())
        .filter(line => {
          // Nur Zeilen, die ItemIDs enthalten und keine reinen Kommentarzeilen sind
          return line && !line.startsWith('//') && line.includes('II_');
        });
      
      data.items = itemLines.map(line => {
        // Entferne Kommentare (alles nach //)
        const cleanLine = line.split('//')[0].trim();
        // Teile die Zeile am Whitespace
        const parts = cleanLine.split(/\s+/).filter(part => part.trim() !== '');
        
        // Das erste Element ist die ItemID
        const itemId = parts[0];
        // Das letzte Element ist die Wahrscheinlichkeit
        const probability = parseInt(parts[parts.length - 1], 10);
        
        return {
          itemId,
          probability
        };
      });
      
      data.itemsTotal = data.items.reduce((sum, item) => sum + item.probability, 0);
    }
    
    // Premium-Item-Daten extrahieren
    const premiumItemMatch = content.match(/[Cc]ollecting_[Pp]remium[Ii]tem[^{]*{([^}]*)}/s);
    if (premiumItemMatch && premiumItemMatch[1]) {
      const premiumItemLines = premiumItemMatch[1].split('\n')
        .map(line => line.trim())
        .filter(line => {
          // Nur Zeilen, die ItemIDs enthalten und keine reinen Kommentarzeilen sind
          return line && !line.startsWith('//') && line.includes('II_');
        });
      
      data.premiumItems = premiumItemLines.map(line => {
        // Entferne Kommentare (alles nach //)
        const cleanLine = line.split('//')[0].trim();
        // Teile die Zeile am Whitespace
        const parts = cleanLine.split(/\s+/).filter(part => part.trim() !== '');
        
        // Das erste Element ist die ItemID
        const itemId = parts[0];
        // Das letzte Element ist die Wahrscheinlichkeit
        const probability = parseInt(parts[parts.length - 1], 10);
        
        return {
          itemId,
          probability
        };
      });
      
      data.premiumItemsTotal = data.premiumItems.reduce((sum, item) => sum + item.probability, 0);
    }
    
    // Premium-Status-Item-Daten extrahieren
    const premiumStatusItemMatch = content.match(/[Cc]ollecting_[Pp]remium[Ss]tatus[Ii]tem[^{]*{([^}]*)}/s);
    if (premiumStatusItemMatch && premiumStatusItemMatch[1]) {
      const premiumStatusItemLines = premiumStatusItemMatch[1].split('\n')
        .map(line => line.trim())
        .filter(line => {
          // Nur Zeilen, die ItemIDs enthalten und keine reinen Kommentarzeilen sind
          return line && !line.startsWith('//') && line.includes('II_');
        });
      
      data.premiumStatusItems = premiumStatusItemLines.map(line => {
        // Entferne Kommentare (alles nach //)
        const cleanLine = line.split('//')[0].trim();
        // Teile die Zeile am Whitespace
        const parts = cleanLine.split(/\s+/).filter(part => part.trim() !== '');
        
        // Das erste Element ist die ItemID
        const itemId = parts[0];
        // Das letzte Element ist die Wahrscheinlichkeit
        const probability = parseInt(parts[parts.length - 1], 10);
        
        return {
          itemId,
          probability
        };
      });
      
      data.premiumStatusItemsTotal = data.premiumStatusItems.reduce((sum, item) => sum + item.probability, 0);
    }
    
    console.log("Parsed collector data:", data);
  } catch (error) {
    console.error("Error parsing s.txt:", error);
  }
  
  return data;
};

/**
 * Serialisiert die Collector-Daten zurück in das s.txt-Format
 */
export const serializeCollectorData = (data: CollectorData, originalContent: string): string => {
  try {
    let newContent = originalContent;
    
    // Enchantment-Bereich aktualisieren
    if (data.enchant.length > 0) {
      const enchantMatch = originalContent.match(/([Cc]ollecting_[Ee]nchant[^{]*{)([^}]*)(})/s);
      if (enchantMatch) {
        // Originalkommentare aus dem Enchant-Bereich extrahieren
        const enchantLines = enchantMatch[2].split('\n');
        const commentLines = enchantLines
          .filter(line => line.trim().startsWith('//'))
          .map(line => line.trim());
          
        // Formatiere die Enchant-Daten
        let enchantContent = '';
        
        // Füge zuerst alle Kommentarzeilen hinzu
        if (commentLines.length > 0) {
          enchantContent += commentLines.join('\n') + '\n';
        }
        
        // Füge dann die Enchant-Daten hinzu
        data.enchant.forEach(enchant => {
          enchantContent += `\t${enchant.chance}\t\t// ${enchant.level}\n`;
        });
        
        // Ersetze den ursprünglichen Enchant-Inhalt
        newContent = newContent.replace(enchantMatch[0], `${enchantMatch[1]}\n${enchantContent}${enchantMatch[3]}`);
      }
    }
    
    // Item-Bereich aktualisieren
    if (data.items.length > 0) {
      const itemMatch = originalContent.match(/([Cc]ollecting_[Ii]tem(?!\s*_)[^{]*{)([^}]*)(})/s);
      if (itemMatch) {
        // Extrahiere Comment "// Sum = XXXX" vom Header
        let sumComment = "";
        const headerCommentMatch = itemMatch[1].match(/\/\/.*?\bSum\s*=\s*\d+/);
        if (headerCommentMatch) {
          sumComment = headerCommentMatch[0];
        } else {
          // Suche nach Kommentaren im Content-Teil
          const contentCommentMatch = itemMatch[2].match(/^\s*\/\/.*?\bSum\s*=\s*\d+/m);
          if (contentCommentMatch) {
            sumComment = contentCommentMatch[0].trim();
          }
        }
        
        // Formatiere die Items mit korrektem Spacing
        let itemContent = '';
        
        // Füge ggf. den Summenkommentar hinzu, wenn er im Content gefunden wurde
        if (sumComment && !itemMatch[1].includes(sumComment)) {
          itemContent += `${sumComment}\n`;
        }
        
        data.items.forEach(item => {
          itemContent += `\t${item.itemId.padEnd(30)}\t${item.probability}\n`;
        });
        
        // Ersetze den ursprünglichen Item-Inhalt und behalte den Kommentar bei
        let newItemSection = itemMatch[1];
        newContent = newContent.replace(itemMatch[0], `${newItemSection}\n${itemContent}${itemMatch[3]}`);
      }
    }
    
    // Premium-Item-Bereich aktualisieren
    if (data.premiumItems.length > 0) {
      const premiumItemMatch = originalContent.match(/([Cc]ollecting_[Pp]remium[Ii]tem[^{]*{)([^}]*)(})/s);
      if (premiumItemMatch) {
        // Extrahiere mögliche Kommentare
        let contentComments = "";
        const commentLines = premiumItemMatch[2].split('\n')
          .filter(line => line.trim().startsWith('//'))
          .map(line => line.trim());
          
        if (commentLines.length > 0) {
          contentComments = commentLines.join('\n') + '\n';
        }
        
        // Formatiere die Premium-Items
        let premiumItemContent = contentComments;
        
        data.premiumItems.forEach(item => {
          premiumItemContent += `\t${item.itemId}\t${item.probability}\n`;
        });
        
        // Ersetze den ursprünglichen Premium-Item-Inhalt
        newContent = newContent.replace(premiumItemMatch[0], `${premiumItemMatch[1]}\n${premiumItemContent}${premiumItemMatch[3]}`);
      }
    }
    
    // Premium-Status-Item-Bereich aktualisieren
    if (data.premiumStatusItems.length > 0) {
      const premiumStatusItemMatch = originalContent.match(/([Cc]ollecting_[Pp]remium[Ss]tatus[Ii]tem[^{]*{)([^}]*)(})/s);
      if (premiumStatusItemMatch) {
        // Extrahiere mögliche Kommentare
        let contentComments = "";
        const commentLines = premiumStatusItemMatch[2].split('\n')
          .filter(line => line.trim().startsWith('//'))
          .map(line => line.trim());
          
        if (commentLines.length > 0) {
          contentComments = commentLines.join('\n') + '\n';
        }
        
        // Formatiere die Premium-Status-Items
        let premiumStatusItemContent = contentComments;
        
        data.premiumStatusItems.forEach(item => {
          premiumStatusItemContent += `\t${item.itemId}\t\t${item.probability}\n`;
        });
        
        // Ersetze den ursprünglichen Premium-Status-Item-Inhalt
        newContent = newContent.replace(premiumStatusItemMatch[0], `${premiumStatusItemMatch[1]}\n${premiumStatusItemContent}${premiumStatusItemMatch[3]}`);
      }
    }
    
    return newContent;
  } catch (error) {
    console.error("Error serializing collector data:", error);
    return originalContent;
  }
};

/**
 * Validiert die Collector-Daten
 */
export const validateCollectorData = (data: CollectorData): CollectorValidationResult => {
  const errors: string[] = [];
  
  // Erwartete Summe für Enchantments: 1000
  const expectedEnchantTotal = 1000;
  const enchantTotalMismatch = data.enchantTotal !== expectedEnchantTotal;
  
  if (enchantTotalMismatch) {
    errors.push(`Enchant total (${data.enchantTotal}) does not match expected value (${expectedEnchantTotal})`);
  }
  
  // Erwartete Summe für Items: 1000000
  const expectedItemsTotal = 1000000;
  const itemsTotalMismatch = data.itemsTotal !== expectedItemsTotal;
  
  if (itemsTotalMismatch) {
    errors.push(`Items total (${data.itemsTotal}) does not match expected value (${expectedItemsTotal})`);
  }
  
  // Erwartete Summe für Premium-Items: 1000000
  const expectedPremiumItemsTotal = 1000000;
  const premiumItemsTotalMismatch = data.premiumItemsTotal !== expectedPremiumItemsTotal;
  
  if (premiumItemsTotalMismatch) {
    errors.push(`Premium items total (${data.premiumItemsTotal}) does not match expected value (${expectedPremiumItemsTotal})`);
  }
  
  // Erwartete Summe für Premium-Status-Items: 1000000
  const expectedPremiumStatusItemsTotal = 1000000;
  const premiumStatusItemsTotalMismatch = data.premiumStatusItemsTotal !== expectedPremiumStatusItemsTotal;
  
  if (premiumStatusItemsTotalMismatch) {
    errors.push(`Premium status items total (${data.premiumStatusItemsTotal}) does not match expected value (${expectedPremiumStatusItemsTotal})`);
  }
  
  return {
    enchantValid: !enchantTotalMismatch,
    itemsValid: !itemsTotalMismatch,
    premiumItemsValid: !premiumItemsTotalMismatch,
    premiumStatusItemsValid: !premiumStatusItemsTotalMismatch,
    enchantTotalMismatch,
    itemsTotalMismatch,
    premiumItemsTotalMismatch,
    premiumStatusItemsTotalMismatch,
    isValid: errors.length === 0,
    errors
  };
};

/**
 * Berechnet den Prozentwert für eine Wahrscheinlichkeit
 * basierend auf einem Gesamtwert von 1000000
 */
export const calculatePercentage = (probability: number): number => {
  return (probability / 1000000) * 100;
}; 