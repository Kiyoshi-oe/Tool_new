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
  position: number; // Position in the shop list
}

export interface NPCDialogueOption {
  text: string;
  next: string;
  action?: string;
  condition?: string;
}

export interface NPCDialogue {
  id: string;
  text: string;
  options?: NPCDialogueOption[];
}

export interface NPCAppearance {
  modelFile: string;
  skin?: string;
  animations?: string[];
  equipment?: string[];
}

export interface NPCItem {
  id: string;
  name: string;
  displayName: string;
  description?: string;
  type: string; // Type of NPC (merchant, quest giver, etc.)
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
    tabs?: Array<{id: number, name: string}>;
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