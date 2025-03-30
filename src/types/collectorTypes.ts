/**
 * Typ-Definitionen für das Collector-System
 */

export interface CollectingEnchant {
  level: number;
  chance: number;
}

export interface CollectingItem {
  itemId: string;
  probability: number;
}

export interface CollectorData {
  enchant: CollectingEnchant[];
  items: CollectingItem[];
  premiumItems: CollectingItem[];
  premiumStatusItems: CollectingItem[];
  
  // Summen für Validierung
  enchantTotal: number;
  itemsTotal: number;
  premiumItemsTotal: number;
  premiumStatusItemsTotal: number;
}

/**
 * Ergebnis der Validierung der Collector-Daten
 */
export interface CollectorValidationResult {
  isValid: boolean;
  enchantValid: boolean;
  itemsValid: boolean;
  premiumItemsValid: boolean;
  premiumStatusItemsValid: boolean;
  enchantTotalMismatch: boolean;
  itemsTotalMismatch: boolean;
  premiumItemsTotalMismatch: boolean;
  premiumStatusItemsTotalMismatch: boolean;
  errors: string[];
} 