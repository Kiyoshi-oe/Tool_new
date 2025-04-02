// propMoverEx.inc - Extended properties for NPCs
// Contains dialog references, shop definitions, etc.

// Format:
// NPC_ID,DialogID,ShopID,BehaviorType,Position_X,Position_Y,Position_Z,Angle

// NPC_ID: Unique identifier for the NPC
// DialogID: Reference to the dialog file
// ShopID: Shop identifier (0 if no shop)
// BehaviorType: 0=passive, 1=merchant, 2=guard, 3=quest_giver
// Position: X,Y,Z coordinates in the world
// Angle: Facing direction in degrees

1,dialog001,0,0,100.5,25.0,200.8,90
2,dialog002,0,0,105.2,25.0,210.4,180
3,dialog003,shop001,1,120.7,25.0,195.6,270
4,dialog004,0,2,90.3,25.0,220.1,45 