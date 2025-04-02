export interface NPCData {
  [key: string]: string | number | boolean;
}

export interface NPCPosition {
  x: number;
  y: number;
  z: number;
  angle: number;
}

export interface NPCShopItem {
  id: string;
  name: string;
  price: number;
  count: number;
  position: number; // Position in der Shop-Liste
}

export interface NPCDialogue {
  id: string;
  text: string;
  responses?: {
    id: string;
    text: string;
    nextDialogueId?: string;
  }[];
}

export interface NPCAppearance {
  modelFile: string;
  skin?: string;
  animations?: string[];
}

export interface NPCItem {
  id: string;
  name: string;
  displayName: string;
  description?: string;
  type: string; // Typ des NPC (Händler, Questgeber, etc.)
  level: number;
  data: NPCData;
  position: NPCPosition;
  behavior?: string;
  stats?: {
    hp: number;
    mp?: number;
    def?: number;
    atk?: number;
    exp?: number;
  };
  dialogues?: NPCDialogue[];
  appearance: NPCAppearance;
  shop?: {
    isShop: boolean;
    items: NPCShopItem[];
  };
  fields?: {
    propMover?: {
      define?: string;
      displayName?: string;
      description?: string;
    }
  };
}

export interface NPCFileData {
  header: string[];
  items: NPCItem[];
  originalContent?: string;
  isPropMoverFile?: boolean;
} 