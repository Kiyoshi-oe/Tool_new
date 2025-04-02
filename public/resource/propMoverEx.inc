// Mystralia - Monster Drop Script

MI_AIBATT1
{
	Maxitem = 2;
	DropGold(6, 9);

	DropItem(II_GEN_GEM_GEM_TWINKLESTONE, 100000000, 0, 1);

	m_dwAttackMoveDelay = 2000;
	m_dwRunawayDelay = 3000;
	m_nAttackFirstRange = 8;
   
        AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
//			evade 5
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}
MI_AIBATT2
{
	Maxitem = 2;
	DropGold(6, 9);
	
	DropItem(II_GEN_GEM_GEM_TWINKLESTONE, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}
MI_AIBATT3
{
	Maxitem = 2;
	DropGold(8, 11);
	
	DropItem(II_GEN_GEM_GEM_TWINKLESTONE, 200000000, 0, 1);
	
	m_nAttackFirstRange = 8;

      	AI
	{
		#Scan
                    {
			scan range 8
                    }
		#battle
		    {
			Attack cunning low
                             
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_AIBATT4 // Giant Aibatt
{
	Maxitem = 3;
	DropGold(150, 151);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 15);


	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, MI_AIBATT2, 5 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
			Recovery 10 50 100 m
			evade 20
                                                            
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_MUSHPANG1
{
	Maxitem = 3;
	DropGold(9, 13);

	DropItem(II_GEN_GEM_GEM_FORFORM, 100000000, 0, 1);
    

	m_dwAttackMoveDelay = 2000;
	m_dwRunawayDelay = 3000;
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan range 6
                    }
		#battle
		    {
			Attack			                   
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}
MI_MUSHPANG2
{
	Maxitem = 2;
	DropGold(9, 13);

	DropItem(II_GEN_GEM_GEM_FORFORM, 200000000, 0, 1);
    
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
//                        evade 10
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_MUSHPANG3
{
	Maxitem = 2;
	DropGold(10, 15);

	DropItem(II_GEN_GEM_GEM_FORFORM, 200000000, 0, 1);
    

	m_nAttackFirstRange = 8;
	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_MUSHPANG4 // Giant Mushpang
{
	Maxitem = 3;
	DropGold(174, 175);
	
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 15);
	
	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, MI_MUSHPANG2, 5 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        evade 20
			Recovery 20 50 100 m
                                    
                    }
		#move
		    {
			Loot d 4
		    }	
   	}               
}

MI_BURUDENG1
{
	Maxitem = 2;
	DropGold(11, 16);
	DropKind(IK3_SWD, 1, 3);
	DropKind(IK3_SUIT, 1, 3);
	DropKind(IK3_GAUNTLET, 1, 3);
	DropKind(IK3_BOOTS, 1, 3);

	DropItem(II_GEN_GEM_GEM_PALIN, 100000000, 0, 1);
    

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                                
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_BURUDENG2
{
	Maxitem = 2;
	DropGold(11, 16);
	DropKind(IK3_SWD, 1, 3);
	DropKind(IK3_SUIT, 1, 3);
	DropKind(IK3_GAUNTLET, 1, 3);
	DropKind(IK3_BOOTS, 1, 3);
	
	DropItem(II_GEN_GEM_GEM_PALIN, 200000000, 0, 1);
    
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			                                                         
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_BURUDENG3
{
	Maxitem = 2;
	DropGold(12, 18);
	DropKind(IK3_SWD, 2, 5);
	DropKind(IK3_SUIT, 2, 5);
	DropKind(IK3_GAUNTLET, 2, 5);
	DropKind(IK3_BOOTS, 2, 5);
	
	DropItem(II_GEN_GEM_GEM_PALIN, 200000000, 0, 1);
    
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_BURUDENG4 // Giant Burudeng
{
	Maxitem = 3;
	DropGold(200, 201);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 15);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        evade 30
                        
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_PUKEPUKE1
{
	Maxitem = 2;
	DropGold(14, 20);
	DropKind(IK3_SWD, 3, 6);
	DropKind(IK3_AXE, 3, 6);
	DropKind(IK3_SUIT, 3, 6);
	DropKind(IK3_GAUNTLET, 3, 6);
	DropKind(IK3_BOOTS, 3, 6);
	
	DropItem(II_GEN_GEM_GEM_CHUPIM, 100000000, 0, 1);
	

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 750;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                                                            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_PUKEPUKE2
{
	Maxitem = 2;
	DropGold(14, 20);
	DropKind(IK3_SWD, 3, 6);
	DropKind(IK3_AXE, 3, 6);
	DropKind(IK3_SUIT, 3, 6);
	DropKind(IK3_GAUNTLET, 3, 6);
	DropKind(IK3_BOOTS, 3, 6);
	
	DropItem(II_GEN_GEM_GEM_CHUPIM, 200000000, 0, 1);
	

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 750;
	SetRunAway( 10, MI_BURUDENG3, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low               
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_PUKEPUKE3
{
	Maxitem = 2;
	DropGold(16, 23);
	DropKind(IK3_SWD, 4, 7);
	DropKind(IK3_AXE, 4, 7);
	DropKind(IK3_SUIT, 4, 7);
	DropKind(IK3_GAUNTLET, 4, 7);
	DropKind(IK3_BOOTS, 4, 7);
	DropKind(IK3_SHIELD, 4, 7);
	
	DropItem(II_GEN_GEM_GEM_CHUPIM, 200000000, 0, 1);
	

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 750;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack                       
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_PUKEPUKE4 // Giant Pukepuke
{
	Maxitem = 3;
	DropGold(250, 251);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 15);
	
	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, MI_PUKEPUKE1, 5 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_PEAKYTURTLE1
{
	Maxitem = 2;
	DropGold(16, 23);
	DropKind(IK3_SWD, 4, 7);
	DropKind(IK3_AXE, 4, 7);
	DropKind(IK3_SUIT, 4, 7);
	DropKind(IK3_GAUNTLET, 4, 7);
	DropKind(IK3_BOOTS, 4, 7);
	DropKind(IK3_SHIELD, 4, 7);


	DropItem(II_GEN_GEM_GEM_PEAKYRIND, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning hi
                                                            
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_PEAKYTURTLE2
{
	Maxitem = 2;
	DropGold(16, 23);
	DropKind(IK3_SWD, 6, 9);
	DropKind(IK3_AXE, 6, 9);
	DropKind(IK3_SUIT, 6, 9);
	DropKind(IK3_GAUNTLET, 6, 9);
	DropKind(IK3_BOOTS, 6, 9);
	DropKind(IK3_SHIELD, 3, 7);

	DropItem(II_GEN_GEM_GEM_PEAKYRIND, 200000000, 0, 1);
	


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning low			
                                                            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_PEAKYTURTLE3
{
	Maxitem = 2;
	DropGold(17, 25);

	DropKind(IK3_SWD, 6, 10);
	DropKind(IK3_AXE, 6, 10);
	DropKind(IK3_SUIT, 6, 10);
	DropKind(IK3_GAUNTLET, 6, 10);
	DropKind(IK3_BOOTS, 6, 10);
	DropKind(IK3_SHIELD, 3, 7);

	DropItem(II_GEN_GEM_GEM_PEAKYRIND, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                             
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_PEAKYTURTLE4 // Giant Peakyturtle
{
	Maxitem = 3;
	DropGold(300, 301);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 15);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        berserk 30 1.2  
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_DEMIAN1
{
	Maxitem = 2;
	DropGold(17, 25);
	DropKind(IK3_SWD, 7, 11);
	DropKind(IK3_AXE, 7, 11);
	DropKind(IK3_SUIT, 7, 11);
	DropKind(IK3_GAUNTLET, 7, 11);
	DropKind(IK3_BOOTS, 7, 11);
	DropKind(IK3_SHIELD, 5, 9);

	DropItem(II_GEN_GEM_GEM_MOP, 50000000, 0, 1);
	
	DropItem(II_GEN_FOO_INS_CHOCOLATE, 8300000, 0, 1);
	DropItem(II_GEN_FOO_INS_MILK, 8300000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 8300000, 0, 1);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 750;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning hi
                        Evade 15                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_DEMIAN2
{
	Maxitem = 2;
	DropGold(17, 25);
	DropKind(IK3_SWD, 7, 11);
	DropKind(IK3_AXE, 7, 11);
	DropKind(IK3_HELMET, 1, 5);
	DropKind(IK3_SUIT, 7, 11);
	DropKind(IK3_GAUNTLET, 7, 11);
	DropKind(IK3_BOOTS, 7, 11);
	DropKind(IK3_SHIELD, 6, 10);


	DropItem(II_GEN_GEM_GEM_MOP, 50000000, 0, 1);
	
	DropItem(II_GEN_FOO_INS_CHOCOLATE, 3300000, 0, 1);
	DropItem(II_GEN_FOO_INS_MILK, 3300000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 3300000, 0, 1);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 750;
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning hi
                        Evade 15                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_DEMIAN3
{
	Maxitem = 2;
	DropGold(19, 27);
	DropKind(IK3_SWD, 7, 11);
	DropKind(IK3_AXE, 7, 11);
	DropKind(IK3_HELMET, 1, 5);
	DropKind(IK3_SUIT, 7, 11);
	DropKind(IK3_GAUNTLET, 7, 11);
	DropKind(IK3_BOOTS, 7, 11);
	DropKind(IK3_SHIELD, 6, 10);

	DropItem(II_GEN_GEM_GEM_MOP, 50000000, 0, 1);
	
	DropItem(II_GEN_FOO_INS_CHOCOLATE, 3300000, 0, 1);
	DropItem(II_GEN_FOO_INS_MILK, 3300000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 3300000, 0, 1);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 750;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning hi
                        Evade 15                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_DEMIAN4 // Giant Demian
{
	Maxitem = 3;
	DropGold(400, 401);

	DropItem(II_GEN_FOO_INS_CHOCOLATE, 15000000, 0, 15);
	DropItem(II_GEN_FOO_INS_MILK, 15000000, 0, 15);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 15000000, 0, 5);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 15);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                                            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_DORIDOMA1
{
	Maxitem = 2;
	DropGold(20, 30);
	DropKind(IK3_SWD, 8, 12);
	DropKind(IK3_AXE, 8, 12);
	DropKind(IK3_HELMET, 5, 9);
	DropKind(IK3_SUIT, 8, 12);
	DropKind(IK3_GAUNTLET, 8, 12);
	DropKind(IK3_BOOTS, 8, 12);
	DropKind(IK3_SHIELD, 7, 11);

	DropItem(II_GEN_GEM_GEM_POPORAM, 100000000, 0, 1);
	

	
	m_nAttackFirstRange = 8;

        AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
//                        evade 20            
                    }
		#move
		    {
			
		    }	
   	}                 
}
MI_DORIDOMA2
{
	Maxitem = 2;
	DropGold(20, 30);
	DropKind(IK3_SWD, 8, 12);
	DropKind(IK3_AXE, 8, 12);
	DropKind(IK3_HELMET, 5, 9);
	DropKind(IK3_SUIT, 8, 12);
	DropKind(IK3_GAUNTLET, 8, 12);
	DropKind(IK3_BOOTS, 8, 12);
	DropKind(IK3_SHIELD, 7, 11);

	
	DropItem(II_GEN_GEM_GEM_POPORAM, 200000000, 0, 1);
	


	m_nAttackFirstRange = 8;

        AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}                  
}
MI_DORIDOMA3
{
	Maxitem = 2;
	DropGold(22, 32);
	DropKind(IK3_SWD, 8, 12);
	DropKind(IK3_AXE, 8, 12);
	DropKind(IK3_HELMET, 5, 9);
	DropKind(IK3_SUIT, 8, 12);
	DropKind(IK3_GAUNTLET, 8, 12);
	DropKind(IK3_BOOTS, 8, 12);
	DropKind(IK3_SHIELD, 7, 11);


	DropItem(II_GEN_GEM_GEM_POPORAM, 200000000, 0, 1);
    
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack                                   
                    }
		#move
		    {
			
		    }	
   	}
}
MI_DORIDOMA4 // Giant Doridoma
{
	Maxitem = 3;
	DropGold(500, 501);
	
	DropItem(II_SYS_SYS_EVE_BXFACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST15	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST15	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 15);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, MI_DORIDOMA1, 2 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 20 1.2            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_LAWOLF1
{
	Maxitem = 2;
	DropGold(24, 34);
	DropKind(IK3_SWD, 11, 15);
	DropKind(IK3_AXE, 11, 15);
	DropKind(IK3_HELMET, 11, 15);
	DropKind(IK3_SUIT, 11, 15);
	DropKind(IK3_GAUNTLET, 11, 15);
	DropKind(IK3_SHIELD, 11, 15);


	DropItem(II_GEN_GEM_GEM_SLAIN, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
//                        Evade 30            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_LAWOLF2
{
	Maxitem = 2;
	DropGold(24, 34);
	DropKind(IK3_SWD, 11, 15);
	DropKind(IK3_AXE, 11, 15);
	DropKind(IK3_CHEERSTICK, 11, 15);
	DropKind(IK3_KNUCKLEHAMMER, 11, 15);
	DropKind(IK3_WAND, 11, 15);
	DropKind(IK3_STAFF, 11, 15);
	DropKind(IK3_HELMET, 11, 15);
	DropKind(IK3_SUIT, 11, 15);
	DropKind(IK3_GAUNTLET, 11, 15);
	DropKind(IK3_SHIELD, 11, 15);
	DropKind(IK3_BOW, 11, 15);
	DropKind(IK3_YOYO, 11, 15);

	DropItem(II_GEN_GEM_GEM_SLAIN, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack                            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_LAWOLF3
{
	Maxitem = 2;
	DropGold(26, 38);
	DropKind(IK3_SWD, 11, 15);
	DropKind(IK3_AXE, 11, 15);
	DropKind(IK3_CHEERSTICK, 11, 15);
	DropKind(IK3_KNUCKLEHAMMER, 11, 15);
	DropKind(IK3_WAND, 11, 15);
	DropKind(IK3_STAFF, 11, 15);
	DropKind(IK3_HELMET, 11, 15);
	DropKind(IK3_SUIT, 11, 15);
	DropKind(IK3_GAUNTLET, 11, 15);
	DropKind(IK3_BOOTS, 11, 15);
	DropKind(IK3_SHIELD, 11, 15);
	DropKind(IK3_BOW, 11, 15);
	DropKind(IK3_YOYO, 11, 15);

	DropItem(II_GEN_GEM_GEM_SLAIN, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack sam                                                           
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_LAWOLF4 // Giant Lawolf
{
	Maxitem = 3;
	DropGold(550, 551);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST15	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST15	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 15);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 20, MI_LAWOLF1, 3 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 10 1.2            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_FEFERN1
{
	Maxitem = 2;
	DropGold(28, 40);
	DropKind(IK3_SWD, 13, 17);
	DropKind(IK3_AXE, 13, 17);
	DropKind(IK3_CHEERSTICK, 13, 17);
	DropKind(IK3_KNUCKLEHAMMER, 13, 17);
	DropKind(IK3_WAND, 13, 17);
	DropKind(IK3_STAFF, 13, 17);
	DropKind(IK3_HELMET, 13, 17);
	DropKind(IK3_SUIT, 13, 17);
	DropKind(IK3_GAUNTLET, 13, 17);
	DropKind(IK3_BOOTS, 13, 17);
	DropKind(IK3_SHIELD, 13, 17);
	DropKind(IK3_BOW, 13, 17);
	DropKind(IK3_YOYO, 13, 17);

	DropItem(II_GEN_GEM_GEM_TARINROOT, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
//                        evade 10            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_FEFERN2
{
	Maxitem = 2;
	DropGold(28, 40);
	DropKind(IK3_SWD, 13, 17);
	DropKind(IK3_AXE, 13, 17);
	DropKind(IK3_CHEERSTICK, 13, 17);
	DropKind(IK3_KNUCKLEHAMMER, 13, 17);
	DropKind(IK3_WAND, 13, 17);
	DropKind(IK3_STAFF, 13, 17);
	DropKind(IK3_HELMET, 13, 17);
	DropKind(IK3_SUIT, 13, 17);
	DropKind(IK3_GAUNTLET, 13, 17);
	DropKind(IK3_BOOTS, 13, 17);
	DropKind(IK3_SHIELD, 13, 17);
	DropKind(IK3_BOW, 13, 17);
	DropKind(IK3_YOYO, 13, 17);

	DropItem(II_GEN_GEM_GEM_TARINROOT, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_FEFERN3
{
	Maxitem = 2;
	DropGold(28, 40);
	DropKind(IK3_SWD, 13, 17);
	DropKind(IK3_AXE, 13, 17);
	DropKind(IK3_CHEERSTICK, 13, 17);
	DropKind(IK3_KNUCKLEHAMMER, 13, 17);
	DropKind(IK3_WAND, 13, 17);
	DropKind(IK3_STAFF, 13, 17);
	DropKind(IK3_HELMET, 13, 17);
	DropKind(IK3_SUIT, 13, 17);
	DropKind(IK3_GAUNTLET, 13, 17);
	DropKind(IK3_BOOTS, 13, 17);
	DropKind(IK3_SHIELD, 13, 17);
	DropKind(IK3_BOW, 13, 17);
	DropKind(IK3_YOYO, 13, 17);

	DropItem(II_GEN_GEM_GEM_TARINROOT, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
//                        berserk 20 1.25           
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_FEFERN4 // Giant Fefren
{
	Maxitem = 3;
	DropGold(207, 300);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST15	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST15	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 20);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_NYANGNYANG1
{
	Maxitem = 2;
	DropGold(28, 41);
	DropKind(IK3_SWD, 15, 19);
	DropKind(IK3_AXE, 15, 19);
	DropKind(IK3_CHEERSTICK, 15, 19);
	DropKind(IK3_KNUCKLEHAMMER, 15, 19);
	DropKind(IK3_WAND, 15, 19);
	DropKind(IK3_STAFF, 15, 19);
	DropKind(IK3_HELMET, 15, 19);
	DropKind(IK3_SUIT, 15, 19);
	DropKind(IK3_GAUNTLET, 15, 19);
	DropKind(IK3_BOOTS, 15, 19);
	DropKind(IK3_SHIELD, 15, 19);
	DropKind(IK3_BOW, 15, 19);
	DropKind(IK3_YOYO, 15, 19);


	DropItem(II_GEN_GEM_GEM_STARSTONE, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning hi  
                        evade 10            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_NYANGNYANG2
{
	Maxitem = 2;
	DropGold(28, 41);
	DropKind(IK3_SWD, 15, 19);
	DropKind(IK3_AXE, 15, 19);
	DropKind(IK3_CHEERSTICK, 15, 19);
	DropKind(IK3_KNUCKLEHAMMER, 15, 19);
	DropKind(IK3_WAND, 15, 19);
	DropKind(IK3_STAFF, 15, 19);
	DropKind(IK3_HELMET, 15, 19);
	DropKind(IK3_SUIT, 15, 19);
	DropKind(IK3_GAUNTLET, 15, 19);
	DropKind(IK3_BOOTS, 15, 19);
	DropKind(IK3_SHIELD, 15, 19);
	DropKind(IK3_BOW, 15, 19);
	DropKind(IK3_YOYO, 15, 19);


	DropItem(II_GEN_GEM_GEM_STARSTONE, 200000000, 0, 1);
	

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 30 cunning sam
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_NYANGNYANG3
{
	Maxitem = 2;
	DropGold(28, 41);
	DropKind(IK3_SWD, 15, 19);
	DropKind(IK3_AXE, 15, 19);
	DropKind(IK3_CHEERSTICK, 15, 19);
	DropKind(IK3_KNUCKLEHAMMER, 15, 19);
	DropKind(IK3_WAND, 15, 19);
	DropKind(IK3_STAFF, 15, 19);
	DropKind(IK3_HELMET, 15, 19);
	DropKind(IK3_SUIT, 15, 19);
	DropKind(IK3_GAUNTLET, 15, 19);
	DropKind(IK3_BOOTS, 15, 19);
	DropKind(IK3_SHIELD, 15, 19);
	DropKind(IK3_BOW, 15, 19);	
	DropKind(IK3_YOYO, 15, 19);


	DropItem(II_GEN_GEM_GEM_STARSTONE, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_NYANGNYANG4 // Giant Nyangyang
{
	Maxitem = 3;
	DropGold(600, 601);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST15	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST15	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 20);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                        Berserk 20 1.4            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_BANG1
{
	Maxitem = 2;
	DropGold(29, 42);
	DropKind(IK3_SWD, 17, 21);
	DropKind(IK3_AXE, 17, 21);
	DropKind(IK3_CHEERSTICK, 17, 21);
	DropKind(IK3_KNUCKLEHAMMER, 17, 21);
	DropKind(IK3_WAND, 17, 21);
	DropKind(IK3_STAFF, 17, 21);
	DropKind(IK3_HELMET, 17, 21);
	DropKind(IK3_SUIT, 17, 21);
	DropKind(IK3_GAUNTLET, 17, 21);
	DropKind(IK3_BOOTS, 17, 21);
	DropKind(IK3_SHIELD, 17, 21);
	DropKind(IK3_BOW, 17, 21);	
	DropKind(IK3_YOYO, 17, 21);


	DropItem(II_GEN_GEM_GEM_GOLDENWING, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 30 cunning sam 
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}
MI_BANG2
{
	Maxitem = 2;
	DropGold(29, 42);
	DropKind(IK3_SWD, 17, 21);
	DropKind(IK3_AXE, 17, 21);
	DropKind(IK3_CHEERSTICK, 17, 21);
	DropKind(IK3_KNUCKLEHAMMER, 17, 21);
	DropKind(IK3_WAND, 17, 21);
	DropKind(IK3_STAFF, 17, 21);
	DropKind(IK3_HELMET, 17, 21);
	DropKind(IK3_SUIT, 17, 21);
	DropKind(IK3_GAUNTLET, 17, 21);
	DropKind(IK3_BOOTS, 17, 21);
	DropKind(IK3_SHIELD, 17, 21);
	DropKind(IK3_BOW, 17, 21);	
	DropKind(IK3_YOYO, 17, 21);


	DropItem(II_GEN_GEM_GEM_GOLDENWING, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10  
//                        berserk 20 1.2            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_BANG3
{
	Maxitem = 2;
	DropGold(29, 42);
	DropKind(IK3_SWD, 17, 21);
	DropKind(IK3_AXE, 17, 21);
	DropKind(IK3_CHEERSTICK, 17, 21);
	DropKind(IK3_KNUCKLEHAMMER, 17, 21);
	DropKind(IK3_WAND, 17, 21);
	DropKind(IK3_STAFF, 17, 21);
	DropKind(IK3_HELMET, 17, 21);
	DropKind(IK3_SUIT, 17, 21);
	DropKind(IK3_GAUNTLET, 17, 21);
	DropKind(IK3_BOOTS, 17, 21);
	DropKind(IK3_SHIELD, 17, 21);
	DropKind(IK3_BOW, 17, 21);	
	DropKind(IK3_YOYO, 17, 21);


	DropItem(II_GEN_GEM_GEM_GOLDENWING, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
                        
                        Evade 10            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_BANG4
{
	Maxitem = 3;
	DropGold(601, 602);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST15	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST15	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 20);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, MI_BANG1, 2 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_WAGSAAC1
{
	Maxitem = 2;
	DropGold(30, 44);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BLUEHONEY, 20000000, 0, 1);
	
	DropItem(II_GEN_GEM_CRAFTMATERIAL074, 250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL014, 250000, 0, 1);
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        keeprangeattack 6
            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_WAGSAAC2
{
	Maxitem = 2;
	DropGold(30, 44);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	
	DropItem(II_GEN_GEM_GEM_BLUEHONEY, 20000000, 0, 1);
	
	DropItem(II_GEN_GEM_CRAFTMATERIAL074, 250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL014, 250000, 0, 1);

	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_WAGSAAC3
{
	Maxitem = 2;
	DropGold(30, 44);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BLUEHONEY, 20000000, 0, 1);
	
	DropItem(II_GEN_GEM_CRAFTMATERIAL074, 250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL014, 250000, 0, 1);


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                        keeprangeattack 6
            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}
MI_WAGSAAC4
{
	Maxitem = 3;
	DropGold(649, 650);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST15	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST15	   , 3500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL014   , 7500000, 0, 3);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 20);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL074, 5000000, 0, 1);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        rangeattack 10            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_MIA1
{
	Maxitem = 2;
	DropGold(31, 45);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_MIADOLL, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        Berserk 50 1.2            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_MIA2
{
	Maxitem = 2;
	DropGold(31, 45);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	
	DropItem(II_GEN_GEM_GEM_MIADOLL, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 30 cunning sam 
                                  
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_MIA3
{
	Maxitem = 2;
	DropGold(32, 46);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_MIADOLL, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
                        
                        Berserk 5 1.2            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_MIA4
{
	Maxitem = 3;
	DropGold(674, 675);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST15	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST15	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 20);
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    { 
			loot d 5
		    }	
   	}               
}

MI_MIA5
{
	Maxitem = 50;
	DropGold(229, 332);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    { 
			loot d 5
		    }	
   	}               
}


MI_MZOMBIE
{
	Maxitem = 5;
	DropGold(229, 332);

	DropItem(II_SYS_SYS_SCR_BXEVMONSTER01, 3000000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    { 
			loot d 5
		    }	
   	}               
}

MI_FZOMBIE
{
	Maxitem = 5;
	DropGold(229, 332);

	DropItem(II_SYS_SYS_SCR_BXEVMONSTER02, 3000000000, 0, 1);


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    { 
			loot d 5
		    }	
   	}               
}
MI_NMZOMBIE
{
	Maxitem = 5;
	DropGold(229, 332);
	
	DropItem(II_SYS_SYS_EVE_BXZOMBIES, 3000000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    { 
			loot d 5
		    }	
   	}               
}

MI_NFZOMBIE
{
	Maxitem = 5;
	DropGold(229, 332);
	
	DropItem(II_SYS_SYS_EVE_BXZOMBIES, 3000000000, 0, 1);


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    { 
			loot d 5
		    }	
   	}               
}
MI_MRPUMPKIN1
{
	Maxitem = 2;
	DropGold(32, 46);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_FURIOUSMATCH, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_MRPUMPKIN2
{
	Maxitem = 2;
	DropGold(32, 46);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_FURIOUSMATCH, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			
			Keeprangeattack 8 
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_MRPUMPKIN3
{
	Maxitem = 2;
	DropGold(32, 47);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_FURIOUSMATCH, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_MRPUMPKIN4
{
	Maxitem = 3;
	DropGold(684, 685);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT15   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN15  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY15 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST15	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST15	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 25);
	
	m_nAttackFirstRange = 8;
	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 2
		    }	
   	}               
}
MI_REDMANTIS1
{
	Maxitem = 2;
	DropGold(32, 47);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	
	DropItem(II_GEN_GEM_GEM_CARDRIN, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 
                        Berserk 30 1.4            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_REDMANTIS2
{
	Maxitem = 2;
	DropGold(32, 47);
//	DropItem(II_ARM_ARM_SHI_HEAVY, 83320, 0, 1);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_CARDRIN, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_REDMANTIS3
{
	Maxitem = 2;
	DropGold(33, 48);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_CARDRIN, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50 cunning sam
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}
MI_REDMANTIS4
{
	Maxitem = 3;
	DropGold(699, 700);

	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MER	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MER	, 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 25);
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                                                 
                        Berserk 10 1.2            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_JACKTHEHAMMER1
{
	Maxitem = 2;
	DropGold(34, 49);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_HAMMARBLE, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 30  
                        evade 10            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_JACKTHEHAMMER2
{
	Maxitem = 2;
	DropGold(34, 49);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_HAMMARBLE, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;
	


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Keeprangeattack 8 
                        evade 20            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}
MI_JACKTHEHAMMER3
{
	Maxitem = 2;
	DropGold(34, 49);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_HAMMARBLE, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_JACKTHEHAMMER4
{
	Maxitem = 3;
	DropGold(724, 725);

	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MER	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MER	, 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 25);
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_GIGGLEBOX1
{
	Maxitem = 2;
	DropGold(35, 51);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GIGGLANDE, 100000000, 0, 1);
    

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 30 cunning sam 
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_GIGGLEBOX2
{
	Maxitem = 2;
	DropGold(35, 51);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GIGGLANDE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50 
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_GIGGLEBOX3
{
	Maxitem = 2;
	DropGold(36, 52);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GIGGLANDE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                                    
                    }
		#move
		    {

		    }
	}
			
	               

}
MI_GIGGLEBOX4
{
	Maxitem = 3;
	DropGold(4´749, 750);

	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MER	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MER	, 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 25);	
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_ROCKMUSCLE1
{
	Maxitem = 2;
	DropGold(36, 52);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_MOONSTONE, 100000000, 0, 1);
	


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50 
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_ROCKMUSCLE2
{
	Maxitem = 2;
	DropGold(36, 52);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_MOONSTONE, 200000000, 0, 1);
	


	
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 30 cunning hi 
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_ROCKMUSCLE3
{
	Maxitem = 2;
	DropGold(36, 53);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_MOONSTONE, 200000000, 0, 1);
	


	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                        berserk 20 1.4            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}
MI_ROCKMUSCLE4
{
	Maxitem = 3;
	DropGold(750, 751);

	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MER	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MER	, 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 25);

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                                    
                    }
		#move
		    {
			loot d 3
             	    }
	}	               

}

MI_BIGMUSCLE
{
	Maxitem = 25;
	DropGold(36, 52);

	DropItem(II_GEN_MAT_ORICHALCUM01, 7500000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 30 2
                        recovery 5 20 100 m                                               
                    }
		#move
		    {

		    }	
   	}               
}




MI_HOBO1
{
	Maxitem = 2;
	DropGold(37, 54);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BOBAND, 100000000, 0, 1);


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam 
                        rangeattack 10
			Evade 20            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_HOBO2
{
	Maxitem = 2;
	DropGold(37, 54);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_BOBAND, 200000000, 0, 1);


	
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Keeprangeattack 8
                        evade 10
			           
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_HOBO3
{
	Maxitem = 2;
	DropGold(37, 54);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BOBAND, 200000000, 0, 1);


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        
                        Berserk 30 1.4            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_HOBO4
{
	Maxitem = 3;
	DropGold(774, 775);

	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MER	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MER	, 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 25);
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}

MI_DUMBBULL1
{
	Maxitem = 2;
	DropGold(38, 55);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_DUMBLING, 100000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL120, 50000, 0, 1);


	
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning sam 
                        berserk 20 1.2            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}
MI_DUMBBULL2
{
	Maxitem = 2;
	DropGold(38, 55);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	
	DropItem(II_GEN_GEM_GEM_DUMBLING, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL120, 50000, 0, 1);

m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_DUMBBULL3
{
	Maxitem = 2;
	DropGold(39, 56);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_DUMBLING, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL120, 50000, 0, 1);


	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_DUMBBULL4
{
	Maxitem = 3;
	DropGold(779, 780);

	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MER	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MER	, 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 25);
	DropItem(II_GEN_GEM_CRAFTMATERIAL120, 40000000, 0, 1);

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}     
}
MI_TOTEMIA1
{
	Maxitem = 2;
	DropGold(40, 58);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_KALIN, 100000000, 0, 1);
	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam 
                                    
                    }
		#move
		    {
			loot d 2
		    }	
   	}               
}
MI_TOTEMIA2
{
	Maxitem = 2;
	DropGold(40, 58);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_KALIN, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning hi
                        Berserk 20 1.4            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_TOTEMIA3
{
	Maxitem = 2;
	DropGold(40, 58);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_KALIN, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_TOTEMIA4
{
	Maxitem = 3;
	DropGold(789, 790);

	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MAG	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ASI	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_ACR	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_F_MER	, 3500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_REWARD_BX_30ARMOR_M_MER	, 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 30);
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_CARDPUPPET1
{
	Maxitem = 2;
	DropGold(40, 59);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_CLOCKHEART, 100000000, 0, 1);
	


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_CARDPUPPET2
{
	Maxitem = 2;
	DropGold(40, 59);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_CLOCKHEART, 200000000, 0, 1);
	

	m_nAttackFirstRange = 8;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Keeprangeattack 8 
                        Evade 20            
                    }
		#move
		    {
			loot d 2
		    }	
   	}               
}
MI_CARDPUPPET3
{
	Maxitem = 2;
	DropGold(41, 60);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_CLOCKHEART, 200000000, 0, 1);
	


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                        Evade 10            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_CARDPUPPET4
{
	Maxitem = 3;
	DropGold(799, 800);
	
	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);		
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 30);
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CARDPUPPET5
{
	Maxitem = 71;
DropGold(229, 332);

	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FLY01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FOR01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FUN01, 3000000000, 0, 1);
	




	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_TOMBSTONEBEARER1
{
	Maxitem = 2;
	DropGold(42, 61);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_TOMBMARBLE, 100000000, 0, 1);
    


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}
MI_TOMBSTONEBEARER2
{
	Maxitem = 2;
	DropGold(42, 61);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_TOMBMARBLE, 200000000, 0, 1);
    


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        berserk 20 1.5            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_TOMBSTONEBEARER3
{
	Maxitem = 2;
	DropGold(42, 61);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_TOMBMARBLE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_TOMBSTONEBEARER4
{
	Maxitem = 3;
	DropGold(824, 825);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 30);
	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                        berserk 20 1.2            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_BASQUE1
{
	Maxitem = 2;
	DropGold(43, 62);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_GOLDENFIST, 100000000, 0, 1);
    


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50 
                        keeprangeattack 6            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}
MI_BASQUE2
{
	Maxitem = 2;
	DropGold(43, 62);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

		

	DropItem(II_GEN_GEM_GEM_GOLDENFIST, 200000000, 0, 1);
    


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Berserk 20 1.3 
                        keeprangeattack 7            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_BASQUE3
{
	Maxitem = 2;
	DropGold(44, 63);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GOLDENFIST, 200000000, 0, 1);
    

	m_nAttackFirstRange = 8;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50
                        
                        Rangeattack 6
			evade 30
            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_BASQUE4
{
	Maxitem = 3;
	DropGold(829, 830);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 30);


	m_nAttackFirstRange = 8;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        rangeattack 10            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_PRANKSTER1
{
	Maxitem = 2;
	DropGold(44, 64);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_ORBRIN, 100000000, 0, 1);
    

	

	m_nAttackFirstRange = 8;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_PRANKSTER2
{
	Maxitem = 2;
	DropGold(44, 64);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_ORBRIN, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 8;
	


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low 
                        Berserk 20 1.3            
                    }
		#move
		    {
			loot d 2
		    }	
   	}               
}
MI_PRANKSTER3
{
	Maxitem = 2;
	DropGold(45, 66);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_GEM_GEM_ORBRIN, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_PRANKSTER4
{
	Maxitem = 3;
	DropGold(839, 840);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 30);
	
	m_nAttackFirstRange = 8;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_WHEELEM1
{
	Maxitem = 2;
	DropGold(46, 67);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_GOLDENCUP, 100000000, 0, 1);
    

	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        evade 10            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_WHEELEM2
{
	Maxitem = 2;
	DropGold(46, 67);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_GOLDENCUP, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50 
                        berserk 30 1.2            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}
MI_WHEELEM3
{
	Maxitem = 2;
	DropGold(46, 67);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GOLDENCUP, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 8;
	


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_WHEELEM4
{
	Maxitem = 3;
	DropGold(840, 850);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 30);
	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                        Berserk 20 1.3            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}


MI_LEYENA1
{
	Maxitem = 2;
	DropGold(47, 68);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_TOMA, 100000000, 0, 1);
    


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_LEYENA2
{
	Maxitem = 2;
	DropGold(47, 68);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_TOMA, 200000000, 0, 1);
    


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Keeprangeattack 8 
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_LEYENA3
{
	Maxitem = 2;
	DropGold(48, 69);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_TOMA, 200000000, 0, 1);
    


	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_LEYENA4
{
	Maxitem = 3;
	DropGold(850, 851);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 35);	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_LEYENA3
			recovery 10 40 100 m  
                          
                                    
                    }
		#move
		    { 
			loot d 3
		    }	
   	}               

}

MI_STEAMWALKER1
{
	Maxitem = 2;
	DropGold(48, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_STEAMTEAR, 100000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                        evade 30            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}
MI_STEAMWALKER2
{
	Maxitem = 2;
	DropGold(48, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_GEM_GEM_STEAMTEAR, 200000000, 0, 1);
    

	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50 
                        Berserk 30 1.2            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_STEAMWALKER3
{
	Maxitem = 2;
	DropGold(49, 71);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_STEAMTEAR, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}
MI_STEAMWALKER4
{
	Maxitem = 3;
	DropGold(859, 860);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 35);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_STEAMWALKER3
			recovery 10 40 100 m 
                          
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}


MI_STEELKNIGHT1
{
	Maxitem = 2;
	DropGold(50, 73);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_KNIGHTLER, 100000000, 0, 1);
    
    DropItem(II_GEN_GEM_CRAFTMATERIAL041, 1000000, 0, 1);


	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}
MI_STEELKNIGHT2
{
	Maxitem = 2;
	DropGold(50, 73);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_KNIGHTLER, 200000000, 0, 1);
    
   	DropItem(II_GEN_GEM_CRAFTMATERIAL041, 1000000, 0, 1);


	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                        Keeprangeattack 10            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_STEELKNIGHT3
{
	Maxitem = 2;
	DropGold(51, 74);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_KNIGHTLER, 200000000, 0, 1);
    
   	DropItem(II_GEN_GEM_CRAFTMATERIAL041, 1000000, 0, 1);


	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_STEELKNIGHT4
{
	Maxitem = 3;
	DropGold(869, 870);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 35);		
    DropItem(II_GEN_GEM_CRAFTMATERIAL041, 5000000, 0, 1);


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_STEELKNIGHT3
			recovery 10 40 100 m 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_NUTTYWHEEL1
{
	Maxitem = 2;
	DropGold(52, 75);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_WHEESHOE, 100000000, 0, 1);
    


	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 80 
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}
MI_NUTTYWHEEL2
{
	Maxitem = 2;
	DropGold(52, 75);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_WHEESHOE, 200000000, 0, 1);
    


	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Keeprangeattack 6 
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_NUTTYWHEEL3
{
	Maxitem = 2;
	DropGold(52, 76);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_WHEESHOE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_NUTTYWHEEL4 // Giant Nuttywheel
{
	Maxitem = 3;
	DropGold(879, 880);

	DropItem(II_SYS_SYS_EVE_BXFACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMACROBAT45   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMAGICIAN45  , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMMERCENARY45 , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXFASSIST45	   , 3500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXMASSIST45	   , 3500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 35);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_NUTTYWHEEL3
			recovery 10 40 100 m            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_DRILLER1    // ���⼭���� 59������.
{
	Maxitem = 2;
	DropGold(53, 77);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_DROIL, 100000000, 0, 1);
    


	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_DRILLER2
{
	Maxitem = 2;
	DropGold(53, 77);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_DROIL, 200000000, 0, 1);
    


	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			keeprangeattack 7  
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}
MI_DRILLER3
{
	Maxitem = 2;
	DropGold(54, 78);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_DROIL, 200000000, 0, 1);
    


	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}
MI_DRILLER4 // Giant Driller

{
	Maxitem = 2;
	DropGold(14999, 15000);

	DropItem(II_WEA_SWO_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_SWT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_KNU_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_CHE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_WAN_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_STA_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_BOW_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_YOY_SUHO, 2500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING04_1, 2250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);		
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 40);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1);
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_DRILLER3
			recovery 10 50 100 m 
                        
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}

MI_VOLT1
{
	Maxitem = 2;
	DropGold(55, 80);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_AMPERE, 100000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        
			evade 20            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_VOLT2
{
	Maxitem = 2;
	DropGold(55, 80);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_AMPERE, 200000000, 0, 1);
    
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 70 cunning low
			berserk 20 1.2 
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}
MI_VOLT3
{
	Maxitem = 2;
	DropGold(56, 81);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_AMPERE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}
MI_VOLT4
{
	Maxitem = 2;
	DropGold(14999, 15000);
	
	DropItem(II_WEA_SWO_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_SWT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_KNU_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_CHE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_WAN_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_STA_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_BOW_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_YOY_SUHO, 2500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING04_1, 2250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);		
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 40);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 5);
    DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1)
	;m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_VOLT3
			recovery 10 50 100 m  
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}


MI_ELDERGUARD1
{
	Maxitem = 2;
	DropGold(56, 82);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GUARDIEYE, 100000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}
MI_ELDERGUARD2
{
	Maxitem = 2;
	DropGold(56, 82);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GUARDIEYE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			attack
			 
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_ELDERGUARD3
{
	Maxitem = 2;
	DropGold(57, 83);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GUARDIEYE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 20 1.25            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_ELDERGUARD4
{
	Maxitem = 2;
	DropGold(14999, 15000);

	DropItem(II_WEA_SWO_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_SWT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_KNU_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_CHE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_WAN_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_STA_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_BOW_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_YOY_SUHO, 2500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING04_1, 2250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);		
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 40);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1);
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_ELDERGUARD3
			recovery 10 50 100 m 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_GARBAGEPIDER1
{
	Maxitem = 2;
	DropGold(58, 84);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GARBAGETON, 100000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50 cunning sam
			berserk 20 1.15 
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}
MI_GARBAGEPIDER2
{
	Maxitem = 2;
	DropGold(58, 84);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GARBAGETON, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			attack 
                        evade 20            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}
MI_GARBAGEPIDER3
{
	Maxitem = 2;
	DropGold(59, 85);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_GARBAGETON, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_GARBAGEPIDER4
{
	Maxitem = 2;
	DropGold(14999, 15000);


	DropItem(II_WEA_SWO_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_SWT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_KNU_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_CHE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_WAN_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_STA_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_BOW_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_YOY_SUHO, 2500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);	
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 5);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 40);
	DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1);
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GARBAGEPIDER3
			recovery 10 50 100 m          
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_CRANEMACHINERY1
{
	Maxitem = 2;
	DropGold(60, 87);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ERONIOR, 100000000, 0, 1);
    

m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                                    
                    }
		#move
		    {
			loot d 10
		    }	
   	}               

}
MI_CRANEMACHINERY2
{
	Maxitem = 2;
	DropGold(60, 87);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ERONIOR, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			attack cunning low  
                        evade 20            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_CRANEMACHINERY3
{
	Maxitem = 2;
	DropGold(61, 89);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ERONIOR, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        berserk 30 1.25            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_CRANEMACHINERY4
{
	Maxitem = 2;
	DropGold(14999, 15000);

	DropItem(II_WEA_SWO_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_SWT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_KNU_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_CHE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_WAN_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_STA_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_BOW_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_YOY_SUHO, 2500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING04_1, 2250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);		
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 40);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_CRANEMACHINERY3
			recovery 10 50 100 m 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_MOTHBEE1
{
	Maxitem = 2;
	DropGold(29, 42);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 10000000, 0, 1);


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}
MI_MOTHBEE2
{
	Maxitem = 2;
	DropGold(29, 42);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 10000000, 0, 1);	


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                        berserk 30 1.25            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_MOTHBEE3
{
	Maxitem = 2;
	DropGold(30, 44);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 10000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 10000000, 0, 1);	


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_MOTHBEE4
{
	Maxitem = 2;
	DropGold(224, 324);

	DropItem(II_GEN_JEW_EAR_ATTEARRING, 30000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 30000000, 0, 1);	


	DropItem(II_GEN_MAT_ORICHALCUM01, 3006250, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1560000, 0, 1);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                        berserk 30 1.2            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_FLBYRIGEN1
{
	Maxitem = 2;
	DropGold(41, 60);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 10000000, 7, 1);


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 70 
                                    
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_FLBYRIGEN2
{
	Maxitem = 2;
	DropGold(41, 60);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 10000000, 7, 1);


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        berserk 20 1.2            
                    }
		#move
		    {
			loot d 3
		    }	
   	}              

}
MI_FLBYRIGEN3
{
	Maxitem = 2;
	DropGold(42, 61);

	DropItem(II_GEN_JEW_EAR_ATTEARRING, 10000000, 2, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 10000000, 7, 1);


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                        evade 5            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_FLBYRIGEN4
{
	Maxitem = 2;
	DropGold(308, 446);

	DropItem(II_GEN_JEW_EAR_ATTEARRING, 30000000, 2, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 30000000, 7, 1);


	DropItem(II_GEN_MAT_ORICHALCUM01, 3006250, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1560000, 0, 1);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}

MI_ROCKEPELLER1
{
	Maxitem = 2;
	DropGold(46, 67);

	DropItem(II_GEN_GEM_CRAFTMATERIAL068, 10000000, 1, 1);


	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                        evade 20            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}
MI_ROCKEPELLER2
{
	Maxitem = 2;
	DropGold(46, 67);

	DropItem(II_GEN_GEM_CRAFTMATERIAL068, 10000000, 1, 1);



	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low 
                        berserk 30 1.35            
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_ROCKEPELLER3
{
	Maxitem = 2;
	DropGold(46, 67);

	DropItem(II_GEN_GEM_CRAFTMATERIAL068, 10000000, 1, 1);



	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
                                                          
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_ROCKEPELLER4
{
	Maxitem = 2;
	DropGold(341, 495);

	DropItem(II_GEN_GEM_CRAFTMATERIAL068, 20000000, 1, 1);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_ROCKEPELLER3
			recovery 10 40 100 m             
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_MINECATCHER
{
	Maxitem = 0;
}

MI_ERONSCATCHER
{
	Maxitem = 0;
}

MI_KRASECCATCHER
{
	Maxitem = 0;
}

MI_GURUCATCHER
{
	Maxitem = 0;
}

//���϶�ī
MI_SYLIACA1
{
	Maxitem = 2;
	DropGold(91, 93);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SYCALE, 100000000, 0, 1);
    

	m_nAttackFirstRange = 10;
	

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 70 
                        Berserk 20 1.3            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_SYLIACA2
{
	Maxitem = 2;
	DropGold(91, 93);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SYCALE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Keeprangeattack 8
			
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}

MI_SYLIACA3
{
	Maxitem = 2;
	DropGold(91, 93);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SYCALE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                        evade 20            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_SYLIACA4
{
	Maxitem = 2;
	DropGold(15999, 16000);

	DropItem(II_WEA_SWO_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_SWT_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_AXE_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_AXT_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_KNU_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_CHE_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_WAN_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_STA_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_BOW_SUHO, 3150000, 0, 1);
	DropItem(II_WEA_YOY_SUHO, 3150000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING04_1, 2250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);		
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 40);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 7);
	DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_SYLIACA3
			recovery 10 40 100 m            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

//�׸���
MI_GREEMONG1
{
	Maxitem = 2;
	DropGold(94, 95);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_MONGTEAR, 100000000, 0, 1);
    

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 30 
                        Rangeattack 6            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_GREEMONG2
{
	Maxitem = 2;
	DropGold(94, 95);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_MONGTEAR, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning hi 
                                   
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_GREEMONG3
{
	Maxitem = 2;
	DropGold(94, 95);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_MONGTEAR, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
                       
                        Berserk 20 1.3           
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}

MI_GREEMONG4
{
	Maxitem = 2;
	DropGold(15999, 16000);

	DropItem(II_WEA_SWO_USU, 3150000, 0, 1);
	DropItem(II_WEA_SWT_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXE_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXT_USU, 3150000, 0, 1);
	DropItem(II_WEA_KNU_USU, 3150000, 0, 1);
	DropItem(II_WEA_CHE_USU, 3150000, 0, 1);
	DropItem(II_WEA_BOW_USU, 3150000, 0, 1);
	DropItem(II_WEA_YOY_USU, 3150000, 0, 1);
	DropItem(II_WEA_WAN_USU, 3150000, 0, 1);
	DropItem(II_WEA_STA_USU, 3150000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING04_1, 2250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);		
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 40);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 7);
	DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1);
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GREEMONG3
			recovery 10 40 100 m             
                    }
		#move
		    {
			
		    }	
   	}               
}

//ĳ���ƺ�
MI_CARRIERBOMB1
{
	Maxitem = 2;
	DropGold(68, 98);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BOMBTIMER, 100000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                        berserk 20 1.2            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CARRIERBOMB2
{
	Maxitem = 2;
	DropGold(68, 99);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BOMBTIMER, 200000000, 0, 1);
    
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        keeprangeattack 5            
					
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CARRIERBOMB3
{
	Maxitem = 2;
	DropGold(68, 99);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BOMBTIMER, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
			recovery 10 20 100 u
                        Rangeattack 6            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CARRIERBOMB4
{
	Maxitem = 2;
	DropGold(16499, 16500);


	DropItem(II_WEA_SWO_USU, 3150000, 0, 1);
	DropItem(II_WEA_SWT_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXE_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXT_USU, 3150000, 0, 1);
	DropItem(II_WEA_KNU_USU, 3150000, 0, 1);
	DropItem(II_WEA_CHE_USU, 3150000, 0, 1);
	DropItem(II_WEA_BOW_USU, 3150000, 0, 1);
	DropItem(II_WEA_YOY_USU, 3150000, 0, 1);
	DropItem(II_WEA_WAN_USU, 3150000, 0, 1);
	DropItem(II_WEA_STA_USU, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 45);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL018, 25000000, 0, 1);
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_CARRIERBOMB3
			recovery 10 40 100 m            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

//������
MI_RISEM1
{

	Maxitem = 2;
	DropGold(68, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ZEMMARK, 100000000, 0, 1);
 	DropItem(II_SYS_SYS_MUSICFESTIVALDROPITEM_GREEN, 350000, 0, 1);
   

	SetCallHelper( 100, MI_RISEM3, 1, TRUE);
	SetCallHelper( 100, MI_RISEM2, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60
			berserk 20 1.3 
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_RISEM2
{
	Maxitem = 2;
	DropGold(68, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ZEMMARK, 200000000, 0, 1);
 	DropItem(II_SYS_SYS_MUSICFESTIVALDROPITEM_GREEN, 350000, 0, 1);
    

	SetCallHelper( 100, MI_RISEM3, 1, TRUE);
	SetCallHelper( 100, MI_RISEM1, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Keeprangeattack 8 
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_RISEM3
{
	Maxitem = 2;
	DropGold(68, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ZEMMARK, 200000000, 0, 1);
 	DropItem(II_SYS_SYS_MUSICFESTIVALDROPITEM_GREEN, 350000, 0, 1);
   

	SetCallHelper( 100, MI_RISEM1, 2, TRUE);
	SetCallHelper( 100, MI_RISEM2, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
			
                        Rangeattack 6            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_RISEM4
{

	Maxitem = 2;
	DropGold(2499, 2500);

	DropKind(IK3_SWD, 57, 64);
	DropKind(IK3_AXE, 57, 64);
	DropKind(IK3_CHEERSTICK, 57, 64);
	DropKind(IK3_KNUCKLEHAMMER, 57, 64);
	DropKind(IK3_WAND, 57, 64);
	DropKind(IK3_STAFF, 57, 64);
	DropKind(IK3_HELMET, 57, 64);
	DropKind(IK3_SUIT, 57, 64);
	DropKind(IK3_GAUNTLET, 57, 64);
	DropKind(IK3_BOOTS, 57, 64);
	DropKind(IK3_SHIELD, 57, 64);
	DropKind(IK3_BOW, 57, 64);
	DropKind(IK3_YOYO, 57, 64);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 35);
	DropItem(II_SYS_SYS_MUSICFESTIVALDROPITEM_GREEN, 3500000, 0, 1);

	SetCallHelper( 100, MI_RISEM3, 5, TRUE);
	SetCallHelper( 100, MI_RISEM2, 5, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_RISEM3
			recovery 10 40 100 m            
                    }
		#move
		    {
			
		    }	
   	}               
}

//���ͺ�Ŭ
MI_NUCTUVEHICLE1
{
	Maxitem = 2;
	DropGold(68, 70);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_NUCTUWHEEL, 100000000, 0, 1);
    

	SetCallHelper( 100, MI_NUCTUVEHICLE3, 1, TRUE);
	SetCallHelper( 100, MI_NUCTUVEHICLE2, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam 
                        Rangeattack 6            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_NUCTUVEHICLE2
{
	Maxitem = 2;
	DropGold(68, 70);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_NUCTUWHEEL, 200000000, 0, 1);
    

	SetCallHelper( 100, MI_NUCTUVEHICLE1, 2, TRUE);
	SetCallHelper( 100, MI_NUCTUVEHICLE3, 1, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        berserk 30 1.3            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_NUCTUVEHICLE3
{
	Maxitem = 2;
	DropGold(68, 70);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_NUCTUWHEEL, 200000000, 0, 1);
    

	SetCallHelper( 100, MI_NUCTUVEHICLE1, 2, TRUE);
	SetCallHelper( 100, MI_NUCTUVEHICLE2, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
			
                        Rangeattack 10            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_NUCTUVEHICLE4
{
	Maxitem = 2;
	DropGold(2399, 2400);


	DropKind(IK3_SWD, 55, 62);
	DropKind(IK3_AXE, 55, 62);
	DropKind(IK3_CHEERSTICK, 55, 62);
	DropKind(IK3_KNUCKLEHAMMER, 55, 62);
	DropKind(IK3_WAND, 55, 62);
	DropKind(IK3_STAFF, 55, 62);
	DropKind(IK3_HELMET, 55, 62);
	DropKind(IK3_SUIT, 55, 62);
	DropKind(IK3_GAUNTLET, 55, 62);
	DropKind(IK3_BOOTS, 55, 62);
	DropKind(IK3_SHIELD, 55, 62);
	DropKind(IK3_BOW, 55, 62);
	DropKind(IK3_YOYO, 55, 62);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 35);

	SetCallHelper( 100, MI_NUCTUVEHICLE3, 5, TRUE);
	SetCallHelper( 100, MI_NUCTUVEHICLE2, 5, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_NUCTUVEHICLE3
			recovery 10 50 100 m 
                         
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

//����
MI_ZOMBIGER1
{
	Maxitem = 2;
	DropGold(68, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ZOMBYHOE, 100000000, 0, 1);
    

	SetCallHelper( 100, MI_ZOMBIGER3, 1, TRUE);
	SetCallHelper( 100, MI_ZOMBIGER2, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 50 
                        Berserk 20 1.2            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ZOMBIGER2
{

	Maxitem = 2;
	DropGold(68, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ZOMBYHOE, 200000000, 0, 1);
    

	SetCallHelper( 100, MI_ZOMBIGER1, 2, TRUE);
	SetCallHelper( 100, MI_ZOMBIGER3, 1, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			KeepRangeattack 10
			evade 30            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_ZOMBIGER3
{
	Maxitem = 2;
	DropGold(68, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ZOMBYHOE, 200000000, 0, 1);
    

	SetCallHelper( 100, MI_ZOMBIGER1, 2, TRUE);
	SetCallHelper( 100, MI_ZOMBIGER2, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
                        Rangeattack 6            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ZOMBIGER4
{
	Maxitem = 2;
	DropGold(2199, 2200);


	DropKind(IK3_SWD, 56, 63);
	DropKind(IK3_AXE, 56, 63);
	DropKind(IK3_CHEERSTICK, 56, 63);
	DropKind(IK3_KNUCKLEHAMMER, 56, 63);
	DropKind(IK3_WAND, 56, 63);
	DropKind(IK3_STAFF, 56, 63);
	DropKind(IK3_HELMET, 56, 63);
	DropKind(IK3_SUIT, 56, 63);
	DropKind(IK3_GAUNTLET, 56, 63);
	DropKind(IK3_BOOTS, 56, 63);
	DropKind(IK3_SHIELD, 56, 63);
	DropKind(IK3_BOW, 56, 63);
	DropKind(IK3_YOYO, 56, 63);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 35);

	SetCallHelper( 100, MI_ZOMBIGER3, 5, TRUE);
	SetCallHelper( 100, MI_ZOMBIGER2, 5, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_ZOMBIGER3
			recovery 10 50 100 m         
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

//�ش� ��ɿ� ����

MI_FLYBAT1
{
	Maxitem = 4;
	DropGold(45, 66);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BATHOOK, 100000000, 0, 1);


	SetCallHelper( 100, MI_FLYBAT3, 1, TRUE);
	SetCallHelper( 100, MI_FLYBAT2, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 3
		    }	 
   	}               
}
MI_FLYBAT2
{
	Maxitem = 4;
	DropGold(45, 66);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BATHOOK, 200000000, 0, 1);


	SetCallHelper( 100, MI_FLYBAT1, 2, TRUE);
	SetCallHelper( 100, MI_FLYBAT3, 1, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
	
}
MI_FLYBAT3
{
	Maxitem = 4;
	DropGold(45, 66);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BATHOOK, 200000000, 0, 1);


	SetCallHelper( 100, MI_FLYBAT1, 2, TRUE);
	SetCallHelper( 100, MI_FLYBAT2, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               

}
MI_FLYBAT4
{
	Maxitem = 8;
	DropGold(224, 324);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 20);

	DropKind(IK3_SWD, 19, 26);
	DropKind(IK3_AXE, 19, 26);
	DropKind(IK3_CHEERSTICK, 19, 26);
	DropKind(IK3_KNUCKLEHAMMER, 19, 26);
	DropKind(IK3_WAND, 19, 26);
	DropKind(IK3_STAFF, 19, 26);
	DropKind(IK3_HELMET, 19, 26);
	DropKind(IK3_SUIT, 19, 26);
	DropKind(IK3_GAUNTLET, 19, 26);
	DropKind(IK3_BOOTS, 19, 26);
	DropKind(IK3_SHIELD, 19, 26);
	DropKind(IK3_BOW, 19, 26);
	DropKind(IK3_YOYO, 19, 26);

	SetCallHelper( 100, MI_FLYBAT3, 5, TRUE);
	SetCallHelper( 100, MI_FLYBAT2, 5, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}


MI_BUCROW1
{
	Maxitem = 4;
	DropGold(55, 60);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BUCORONG, 100000000, 0, 1);
	

	SetCallHelper( 100, MI_BUCROW2, 2, TRUE);
	SetCallHelper( 100, MI_BUCROW3, 1, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               


}
MI_BUCROW2
{
	Maxitem = 4;
	DropGold(55, 60);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BUCORONG, 200000000, 0, 1);
	

	SetCallHelper( 100, MI_BUCROW1, 2, TRUE);
	SetCallHelper( 100, MI_BUCROW3, 1, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 5
		    }	 
   	}               
}
MI_BUCROW3
{
	Maxitem = 4;
	DropGold(55, 60);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BUCORONG, 200000000, 0, 1);
	

	SetCallHelper( 100, MI_BUCROW2, 2, TRUE);
	SetCallHelper( 100, MI_BUCROW1, 2, TRUE);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_BUCROW4
{
	Maxitem = 8;
	DropGold(268, 389);


	DropKind(IK3_SWD, 31, 38);
	DropKind(IK3_AXE, 31, 38);
	DropKind(IK3_CHEERSTICK, 31, 38);
	DropKind(IK3_KNUCKLEHAMMER, 31, 38);
	DropKind(IK3_WAND, 31, 38);
	DropKind(IK3_STAFF, 31, 38);
	DropKind(IK3_HELMET, 31, 38);
	DropKind(IK3_SUIT, 31, 38);
	DropKind(IK3_GAUNTLET, 31, 38);
	DropKind(IK3_BOOTS, 31, 38);
	DropKind(IK3_SHIELD, 31, 38);
	DropKind(IK3_BOW, 31, 38);
	DropKind(IK3_YOYO, 31, 38);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 25);
	
	SetCallHelper( 100, MI_BUCROW2, 5, TRUE);
	SetCallHelper( 100, MI_BUCROW3, 5, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_BUCROW3
			recovery 10 50 100 m
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}


MI_SCOPICON1
{
	Maxitem = 4;
	DropGold(63, 72);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SCOTOOTH, 100000000, 0, 1);
    

	SetCallHelper( 100, MI_SCOPICON2, 2, TRUE);
	SetCallHelper( 100, MI_SCOPICON3, 1, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_SCOPICON2
{
	Maxitem = 4;
	DropGold(63, 72);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SCOTOOTH, 200000000, 0, 1);
    
	
	SetCallHelper( 100, MI_SCOPICON1, 2, TRUE);
	SetCallHelper( 100, MI_SCOPICON3, 1, TRUE);
	
	m_nAttackFirstRange = 10;
	


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_SCOPICON3
{
	Maxitem = 4;
	DropGold(63, 72);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SCOTOOTH, 200000000, 0, 1);
    

	SetCallHelper( 100, MI_SCOPICON2, 2, TRUE);
	SetCallHelper( 100, MI_SCOPICON1, 2, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_SCOPICON4
{
	Maxitem = 8;
	DropGold(313, 454);


	DropKind(IK3_SWD, 41, 48);
	DropKind(IK3_AXE, 41, 48);
	DropKind(IK3_CHEERSTICK, 41, 48);
	DropKind(IK3_KNUCKLEHAMMER, 41, 48);
	DropKind(IK3_WAND, 41, 48);
	DropKind(IK3_STAFF, 41, 48);
	DropKind(IK3_HELMET, 41, 48);
	DropKind(IK3_SUIT, 41, 48);
	DropKind(IK3_GAUNTLET, 41, 48);
	DropKind(IK3_BOOTS, 41, 48);
	DropKind(IK3_SHIELD, 41, 48);
	DropKind(IK3_BOW, 41, 48);
	DropKind(IK3_YOYO, 41, 48);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 30);

	SetCallHelper( 100, MI_SCOPICON2, 5, TRUE);
	SetCallHelper( 100, MI_SCOPICON3, 5, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_SCOPICON3
			recovery 10 30 100 m
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}


MI_TRANGFOMA1
{
	Maxitem = 4;
	DropGold(70, 75);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_RANGLASS, 100000000, 0, 1);
    
	DropItem(II_GEN_GEM_CRAFTMATERIAL068, 500000, 0, 1);

	SetCallHelper( 100, MI_TRANGFOMA2, 2, TRUE);
	SetCallHelper( 100, MI_TRANGFOMA3, 1, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}
MI_TRANGFOMA2
{
	Maxitem = 4;
	DropGold(70, 75);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_RANGLASS, 200000000, 0, 1);
    
	DropItem(II_GEN_GEM_CRAFTMATERIAL068, 500000, 0, 1);

	SetCallHelper( 100, MI_TRANGFOMA1, 2, TRUE);
	SetCallHelper( 100, MI_TRANGFOMA3, 1, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}
MI_TRANGFOMA3
{
	Maxitem = 4;
	DropGold(70, 75);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_RANGLASS, 200000000, 0, 1);
    
	DropItem(II_GEN_GEM_CRAFTMATERIAL068, 500000, 0, 1);

	SetCallHelper( 100, MI_TRANGFOMA2, 2, TRUE);
	SetCallHelper( 100, MI_TRANGFOMA1, 2, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}
MI_TRANGFOMA4
{
	Maxitem = 8;
	DropGold(352, 511);



	DropKind(IK3_SWD, 49, 56);
	DropKind(IK3_AXE, 49, 56);
	DropKind(IK3_CHEERSTICK, 49, 56);
	DropKind(IK3_KNUCKLEHAMMER, 49, 56);
	DropKind(IK3_WAND, 49, 56);
	DropKind(IK3_STAFF, 49, 56);
	DropKind(IK3_HELMET, 49, 56);
	DropKind(IK3_SUIT, 49, 56);
	DropKind(IK3_GAUNTLET, 49, 56);
	DropKind(IK3_BOOTS, 49, 56);
	DropKind(IK3_SHIELD, 49, 56);
	DropKind(IK3_BOW, 49, 56);
	DropKind(IK3_YOYO, 49, 56);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 35);
	DropItem(II_GEN_GEM_CRAFTMATERIAL068, 5000000, 0, 1);

	SetCallHelper( 100, MI_TRANGFOMA2, 5, TRUE);
	SetCallHelper( 100, MI_TRANGFOMA3, 5, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_TRANGFOMA3
			recovery 10 30 100 m
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}
MI_CLOCKWORK1 // Clockworks
{
	Maxitem = 8;
	DropGold(30000, 30001);

	DropItem(II_GEN_FOO_INS_SUPERSTARCANDY,  10000000, 0, 10);
	DropItem(II_GEN_FOO_INS_PANCAKE, 		  10000000, 0, 8);
	DropItem(II_GEN_FOO_INS_DONUT,			  10000000, 0, 6);
	DropItem(II_GEN_FOO_INS_CAKE, 			  10000000, 0, 5);
	DropItem(II_GEN_FOO_INS_CUPCAKE, 		  10000000, 0, 4);
	DropItem(II_GEN_FOO_INS_FRUITCAKE,  	  10000000, 0, 2);
	DropItem(II_WEA_SWO_SET01, 175000000, 0, 1);   
	DropItem(II_WEA_AXE_SET01, 175000000, 0, 1);   
	DropItem(II_WEA_CHE_SET01, 175000000, 0, 1);   
	DropItem(II_WEA_WAN_SET01, 175000000, 0, 1);   
	DropItem(II_WEA_STA_SET01, 175000000, 0, 1);   
	DropItem(II_WEA_KNU_SET01, 175000000, 0, 1);                  
    DropItem(II_ARM_ARM_SHI_RUKENSHIA, 15000000, 0, 1);         
    DropItem(II_ARM_ARM_SHI_TOEFFIN, 15000000, 0, 1);            
    DropItem(II_ARM_ARM_SHI_CATEPO, 15000000, 0, 1); 
	DropItem(II_ARM_M_MER_SET01HELMET,10000000		,0,1);
	DropItem(II_ARM_M_MER_SET01SUIT	  ,10000000,0,1);
	DropItem(II_ARM_M_MER_SET01GAUNTLET,10000000,0,1);
	DropItem(II_ARM_M_MER_SET01BOOTS	,  10000000,0,1);
	DropItem(II_ARM_M_ASS_SET01HELMET,10000000,0,1);
	DropItem(II_ARM_M_ASS_SET01SUIT	  ,10000000,0,1);
	DropItem(II_ARM_M_ASS_SET01GAUNTLET,10000000,0,1);
	DropItem(II_ARM_M_ASS_SET01BOOTS	,  10000000,0,1);
	DropItem(II_ARM_M_MAG_SET01HELMET,10000000,0,1);
	DropItem(II_ARM_M_MAG_SET01SUIT	  ,10000000,0,1);
	DropItem(II_ARM_M_MAG_SET01GAUNTLET,10000000,0,1);
	DropItem(II_ARM_M_MAG_SET01BOOTS	,  10000000,0,1);
	DropItem(II_ARM_F_MER_SET01HELMET,10000000,0,1);
	DropItem(II_ARM_F_MER_SET01SUIT	  ,10000000,0,1);
	DropItem(II_ARM_F_MER_SET01GAUNTLET,10000000,0,1);
	DropItem(II_ARM_F_MER_SET01BOOTS	,  10000000,0,1);
	DropItem(II_ARM_F_ASS_SET01HELMET,10000000,0,1);
	DropItem(II_ARM_F_ASS_SET01SUIT	  ,10000000,0,1);
	DropItem(II_ARM_F_ASS_SET01GAUNTLET,10000000,0,1);
	DropItem(II_ARM_F_ASS_SET01BOOTS	,  10000000,0,1);
	DropItem(II_ARM_F_MAG_SET01HELMET,10000000,0,1);
	DropItem(II_ARM_F_MAG_SET01SUIT	  ,10000000,0,1);
	DropItem(II_ARM_F_MAG_SET01GAUNTLET,10000000,0,1);
	DropItem(II_ARM_F_MAG_SET01BOOTS	,  10000000,0,1);
	DropItem(II_ARM_M_ACR_SET01HELMET,10000000,0,1);
	DropItem(II_ARM_M_ACR_SET01SUIT	  ,10000000,0,1);
	DropItem(II_ARM_M_ACR_SET01GAUNTLET,10000000,0,1);
	DropItem(II_ARM_M_ACR_SET01BOOTS	,  10000000,0,1);
	DropItem(II_ARM_F_ACR_SET01HELMET,10000000,0,1);
	DropItem(II_ARM_F_ACR_SET01SUIT	  ,10000000,0,1);
	DropItem(II_ARM_F_ACR_SET01GAUNTLET,10000000,0,1);
	DropItem(II_ARM_F_ACR_SET01BOOTS	,  10000000,0,1);
	DropItem(II_CHP_FARMCHIP, 175000000, 0, 150);
	DropItem(II_GEN_JEW_EAR_U_EARRING02, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING05, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING08, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE02, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE05, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE08, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING02, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING05, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING08, 175000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_METEOFY, 175000000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL249, 1000000, 0, 1);		
	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 30 2
			Rangeattack 60
            KeepRangeAttack 60
                        recovery 5 20 100 m            
                    }
		#move
		    {
			
		    }	
   	}               

}


// ���ܼ���3�� ���� ������ ������

MI_GRRR1	// �׸���
{
	Maxitem = 2;
	DropGold(81, 118);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	


	DropItem(II_GEN_GEM_GEM_GRBANDAGE, 100000000, 0, 1);
    
m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GRRR2
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_GRBANDAGE, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GRRR3
{
	Maxitem = 2;
	DropGold(84, 121);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	


	DropItem(II_GEN_GEM_GEM_GRBANDAGE, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        Rangeattack 6            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GRRR4
{
	Maxitem = 1;
	DropGold(16999, 17000);

	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);

	

	

	m_nAttackFirstRange = 10;
	

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GRRR3
			recovery 10 30 100 m            
                    }
		#move
		    {
			loot d 5			
		    }	
   	}               
}
MI_KRRR
{
	Maxitem = 25;
	DropGold(120, 155);


	m_nAttackFirstRange = 10;
	

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GRRR3
			recovery 10 30 100 m            
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_MUSHMOOT
{
	Maxitem = 25;
	DropGold(190, 270);

	DropItem(II_GEN_MAT_ORICHALCUM01, 7500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 28880000, 0, 1);

	m_nAttackFirstRange = 10;
	

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GRRR3
			recovery 10 30 100 m            
                    }
		#move
		    {
			
		    }	
   	}               
}      

MI_SMALL_MUSHPOIE
{
	Maxitem = 0;

	m_nAttackFirstRange = 10;
	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_DUMP1	//����
{
	Maxitem = 2;
	DropGold(84, 122);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_DUMPTIRE, 100000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DUMP2
{
	Maxitem = 2;
	DropGold(86, 125);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_DUMPTIRE, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        keeprangeattack 5            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DUMP3
{
	Maxitem = 2;
	DropGold(88, 127);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_DUMPTIRE, 200000000, 0, 1);
    

	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        Rangeattack 6            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DUMP4
{
	Maxitem = 1;
	DropGold(16999, 17000);


	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);

	
	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        recovery 20 30 100 a
			Berserk 30 1.8
			summon 10 1 MI_DUMP3            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_NAUTREPY1
{
	Maxitem = 2;
	DropGold(61, 89);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_GEM_GEM_REPYGLE, 100000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_NAUTREPY2
{
	Maxitem = 2;
	DropGold(62, 90);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	
	DropItem(II_GEN_GEM_GEM_REPYGLE, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_NAUTREPY3
{
	Maxitem = 2;
	DropGold(63, 91);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_REPYGLE, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_NAUTREPY4
{
	Maxitem = 2;
	DropGold(15999, 16000);
	DropItem(II_WEA_SWO_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_SWT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_KNU_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_CHE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_WAN_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_STA_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_BOW_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_YOY_SUHO, 2500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING04_1, 2250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);		
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 45);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 7);
	DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1);
		

	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        recovery 10 20 100 a
			Berserk 30 1.5
			summon 10 1 MI_NAUTREPY3            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}

MI_BOO1
{
	Maxitem = 2;
	DropGold(64, 93);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_BOOPOSN, 100000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_BOO2
{
	Maxitem = 2;
	DropGold(66, 96);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	
	DropItem(II_GEN_GEM_GEM_BOOPOSN, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_BOO3
{
	Maxitem = 2;
	DropGold(67, 97);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_BOOPOSN, 200000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_BOO4
{
	Maxitem = 2;
	DropGold(15999, 16000);

	DropItem(II_WEA_SWO_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_SWT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_AXT_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_KNU_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_CHE_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_WAN_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_STA_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_BOW_SUHO, 2500000, 0, 1);
	DropItem(II_WEA_YOY_SUHO, 2500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING01_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING07_1, 2250000, 0, 1);		
	DropItem(II_GEN_JEW_EAR_U_EARRING04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING10, 2250000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04_2, 2250000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07_1, 2250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING04_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_13, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_4, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_10, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_16, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_1, 2250000, 0, 1);	
	DropItem(II_ARM_ARM_SHI_ANCIENT_7, 2250000, 0, 1);	
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 45);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 7);
	DropItem(II_GEN_GEM_CRAFTMATERIAL101, 17500000, 0, 1);
	

	m_nAttackFirstRange = 10;


	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        recovery 10 30 100 a
			Berserk 30 1.5
			summon 10 1 MI_BOO3            
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}

MI_HOPPRE1
{
	Maxitem = 2;
	DropGold(99, 100);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_PREWING, 100000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 10000, 0, 1);
    

	m_nAttackFirstRange = 10;
	


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HOPPRE2
{
	Maxitem = 2;
	DropGold(99, 100);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_PREWING, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 10000, 0, 1);
    

	
	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        keeprangeattack 8            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HOPPRE3
{
	Maxitem = 2;
	DropGold(99, 100);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_PREWING, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 10000, 0, 1);
    

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HOPPRE4
{
	Maxitem = 2;
	DropGold(3499, 3500);

	DropItem(II_WEA_SWO_USU, 3150000, 0, 1);
	DropItem(II_WEA_SWT_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXE_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXT_USU, 3150000, 0, 1);
	DropItem(II_WEA_KNU_USU, 3150000, 0, 1);
	DropItem(II_WEA_CHE_USU, 3150000, 0, 1);
	DropItem(II_WEA_WAN_USU, 3150000, 0, 1);
	DropItem(II_WEA_STA_USU, 3150000, 0, 1);
	DropItem(II_WEA_BOW_USU, 3150000, 0, 1);
	DropItem(II_WEA_YOY_USU, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL018, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 10000000, 0, 5);
	
	m_nAttackFirstRange = 10;


	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_HOPPRE3
			recovery 10 20 100 m            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_MUSHPOIE1
{
	Maxitem = 2;
	DropGold(71, 103);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_POIESPORE, 100000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 10000, 0, 1);
    

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MUSHPOIE2
{
	Maxitem = 2;
	DropGold(72, 104);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_POIESPORE, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 10000, 0, 1);
    

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MUSHPOIE3
{
	Maxitem = 2;
	DropGold(73, 106);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_GEM_GEM_POIESPORE, 200000000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MUSHPOIE4
{
	Maxitem = 2;
	DropGold(16499, 16500);

	DropItem(II_WEA_SWO_USU, 3150000, 0, 1);
	DropItem(II_WEA_SWT_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXE_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXT_USU, 3150000, 0, 1);
	DropItem(II_WEA_KNU_USU, 3150000, 0, 1);
	DropItem(II_WEA_CHE_USU, 3150000, 0, 1);
	DropItem(II_WEA_WAN_USU, 3150000, 0, 1);
	DropItem(II_WEA_STA_USU, 3150000, 0, 1);
	DropItem(II_WEA_BOW_USU, 3150000, 0, 1);
	DropItem(II_WEA_YOY_USU, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL018, 25000000, 0, 1);
	
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 10000000, 0, 5);   

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        recovery 10 30 100 a
			Berserk 30 1.8
			summon 10 1 MI_MUSHPOIE3            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

MI_IREN1
{
	Maxitem = 2;
	DropGold(74, 107);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_RENYKEN, 100000000, 0, 1);
    

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_IREN2
{
	Maxitem = 2;
	DropGold(75, 109);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_RENYKEN, 200000000, 0, 1);
    

	

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_IREN3
{
	Maxitem = 2;
	DropGold(76, 111);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_RENYKEN, 200000000, 0, 1);
    

	

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_IREN4
{
	Maxitem = 2;
	DropGold(16499, 16500);

	DropItem(II_WEA_SWO_USU, 3150000, 0, 1);
	DropItem(II_WEA_SWT_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXE_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXT_USU, 3150000, 0, 1);
	DropItem(II_WEA_KNU_USU, 3150000, 0, 1);
	DropItem(II_WEA_CHE_USU, 3150000, 0, 1);
	DropItem(II_WEA_WAN_USU, 3150000, 0, 1);
	DropItem(II_WEA_STA_USU, 3150000, 0, 1);
	DropItem(II_WEA_BOW_USU, 3150000, 0, 1);
	DropItem(II_WEA_YOY_USU, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL018, 25000000, 0, 1);
		

	m_nAttackFirstRange = 10;

		
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_IREN3
			recovery 10 30 100 a            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

MI_WATANGKA1
{
	Maxitem = 2;
	DropGold(77, 112);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropItem(II_GEN_GEM_GEM_TANGKASK, 100000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_WATANGKA2
{
	Maxitem = 2;
	DropGold(79, 114);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_TANGKASK, 200000000, 0, 1);
    

	

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        keeprangeattack 5            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_WATANGKA3
{
	Maxitem = 2;
	DropGold(80, 116);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_GEM_GEM_TANGKASK, 200000000, 0, 1);
    

	

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        recovery 10 10 100 a            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_WATANGKA4
{
	Maxitem = 2;
	DropGold(16499, 16500);

	DropItem(II_WEA_SWO_USU, 3150000, 0, 1);
	DropItem(II_WEA_SWT_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXE_USU, 3150000, 0, 1);
	DropItem(II_WEA_AXT_USU, 3150000, 0, 1);
	DropItem(II_WEA_KNU_USU, 3150000, 0, 1);
	DropItem(II_WEA_CHE_USU, 3150000, 0, 1);
	DropItem(II_WEA_WAN_USU, 3150000, 0, 1);
	DropItem(II_WEA_STA_USU, 3150000, 0, 1);
	DropItem(II_WEA_BOW_USU, 3150000, 0, 1);
	DropItem(II_WEA_YOY_USU, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL018, 25000000, 0, 1);
		
	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                       	Berserk 30 1.5
			summon 10 1 MI_WATANGKA3            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_ANTIQUERY1
{
	Maxitem = 2;
	DropGold(81, 118);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_ROOTIOE, 100000000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL125, 100000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL133, 250000, 0, 1);

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ANTIQUERY2
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ROOTIOE, 200000000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL125, 100000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL133, 250000, 0, 1);

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ANTIQUERY3
{
	Maxitem = 2;
	DropGold(84, 121);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_ROOTIOE, 200000000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL125, 100000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL133, 250000, 0, 1);	

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        
			            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ANTIQUERY4
{
	Maxitem = 2;
	DropGold(16999, 17000);

	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 55);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL135, 5000000, 0, 1);

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
			Recovery 10 50 100 a 
			Berserk 30 1.5
			summon 10 1 MI_ANTIQUERY3            
                    }
		#move
		    {
			loot d 4 
		    }	
   	}               

}

MI_LUIA1
{
	Maxitem = 2;
	DropGold(84, 122);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_LUCHEST, 10000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL076, 250000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_LUIA2
{
	Maxitem = 2;
	DropGold(86, 125);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_LUCHEST, 20000000, 0, 1);
    
	DropItem(II_GEN_GEM_CRAFTMATERIAL076, 250000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);  

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_LUIA3
{
	Maxitem = 2;
	DropGold(88, 127);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_LUCHEST, 20000000, 0, 1);
    
	DropItem(II_GEN_GEM_CRAFTMATERIAL076, 250000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;
	

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_LUIA4
{
	Maxitem = 2;
	DropGold(16999, 17000);

	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 55);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL076, 5000000, 0, 1);

		

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		{
		Attack 
		Berserk 30 1.5
		Recovery 10 50 100 m
		summon 10 1 MI_LUIA3            
		}
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_GONGURY1
{
	Maxitem = 2;
	DropGold(88, 128);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_ERONSIMINT, 100000000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GONGURY2
{
	Maxitem = 2;
	DropGold(90, 131);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_ERONSIMINT, 200000000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                   
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GONGURY3
{
	Maxitem = 2;
	DropGold(92, 133);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_GEM_GEM_ERONSIMINT, 200000000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        recovery 10 20 100 a            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GONGURY4
{
	Maxitem = 2;
	DropGold(16999, 17000);


	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 55);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.6
			summon 10 1 MI_GONGURY3
			recovery 20 30 100 a           
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_SHUHAMMA1
{
	Maxitem = 2;
	DropGold(92, 134);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_HAMMAMER, 100000000, 0, 1);
    

	

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_SHUHAMMA2
{
	Maxitem = 2;
	DropGold(94, 136);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	

	DropItem(II_GEN_GEM_GEM_HAMMAMER, 200000000, 0, 1);
    

	
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                        keeprangeattack 5            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_SHUHAMMA3
{
	Maxitem = 2;
	DropGold(96, 139);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_HAMMAMER, 200000000, 0, 1);
    

	

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        Rangeattack 6            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_SHUHAMMA4
{
	Maxitem = 2;
	DropGold(16999, 17000);


	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 55);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.6
			summon 10 1 MI_SHUHAMMA3             
                    }
		#move
		    {
			loot d 4
		    }	
   	}               

}

MI_KERN1
{
	Maxitem = 2;
	DropGold(97, 141);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_RNAMOND, 20000000, 0, 1);
    
    DropItem(II_GEN_GEM_CRAFTMATERIAL100, 250000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KERN2
{
	Maxitem = 2;
	DropGold(99, 143);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_RNAMOND, 20000000, 0, 1);
    
    DropItem(II_GEN_GEM_CRAFTMATERIAL100, 250000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);  

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KERN3
{
	Maxitem = 2;
	DropGold(99, 143);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_GEM_GEM_RNAMOND, 20000000, 0, 1);
    
    DropItem(II_GEN_GEM_CRAFTMATERIAL100, 250000, 0, 1);
 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1); 

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                        recovery 20 10 100 a            
                    }
		#move
		    {
			loot d 9
		    }	
   	}               
}

MI_KERN4
{
	Maxitem = 2;
	DropGold(16999, 17000);


	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 60);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL100, 5500000, 0, 2);

		

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Recovery 10 50 100 m
			Berserk 30 1.5
			summon 10 1 MI_KERN3            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

MI_GLAPHAN1
{
	Maxitem = 2;
	DropGold(74, 75);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_PHANBUBLE, 100000000, 0, 1);

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 40000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GLAPHAN2
{
	Maxitem = 2;
	DropGold(74, 75);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_PHANBUBLE, 200000000, 0, 1);

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 40000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GLAPHAN3
{
	Maxitem = 2;
	DropGold(74, 75);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_PHANBUBLE, 200000000, 0, 1);

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 40000, 0, 1);   

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                                    
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GLAPHAN4
{
	Maxitem = 2;
	DropGold(17499, 17500);

	DropItem(II_WEA_SWO_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 3150000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 15);

	//Knight
	DropItem(II_ARM_M_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_M_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_M_KIN_BOOTS_SET_10, 770123, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_F_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_F_KIN_BOOTS_SET_10, 770123, 0, 1);
	
	//Blade
	DropItem(II_ARM_M_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_M_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 770123, 0, 1);          
	DropItem(II_ARM_M_BLA_BOOTS_SET_13, 770123, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_F_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 770123, 0, 1);         
	DropItem(II_ARM_F_BLA_BOOTS_SET_13, 770123, 0, 1);
	
	//Jester
	DropItem(II_ARM_M_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_M_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_M_JST_BOOTS_SET_16, 770123, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_F_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_F_JST_BOOTS_SET_16, 770123, 0, 1);
	
	//Ranger
	DropItem(II_ARM_M_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_M_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_M_RAG_BOOTS_SET_19, 770123, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_F_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_F_RAG_BOOTS_SET_19, 770123, 0, 1);
	
	//Ringmaster
	DropItem(II_ARM_M_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_M_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_M_RIN_BOOTS_SET_22, 770123, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_F_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_F_RIN_BOOTS_SET_22, 770123, 0, 1);	

	//Ringmaster 1on1
	DropItem(II_ARM_M_RIN_HELMET_SET_22_1, 770123, 0, 1);     
	DropItem(II_ARM_M_RIN_SUIT_SET_22_1, 770123, 0, 1);			   
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22_1, 770123, 0, 1);          
	DropItem(II_ARM_M_RIN_BOOTS_SET_22_1, 770123, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22_1, 770123, 0, 1);     
	DropItem(II_ARM_F_RIN_SUIT_SET_22_1, 770123, 0, 1);			   
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22_1, 770123, 0, 1);          
	DropItem(II_ARM_F_RIN_BOOTS_SET_22_1, 770123, 0, 1);
	
	//Billposter
	DropItem(II_ARM_M_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_M_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_M_BIL_BOOTS_SET_25, 770123, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_F_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_F_BIL_BOOTS_SET_25, 770123, 0, 1);
	
	//Psykeper
	DropItem(II_ARM_M_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_M_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_M_PSY_BOOTS_SET_28, 770123, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_F_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_F_PSY_BOOTS_SET_28, 770123, 0, 1);
	
	//Elementor
	DropItem(II_ARM_M_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_M_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_M_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_F_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_F_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 65);
	DropItem(II_GEN_GEM_CRAFTMATERIAL036, 25000000, 0, 1);
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        summon 10 1 MI_GLAPHAN3
			Berserk 30 1.8
			recovery 10 40 100 m            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

//�ű� �������� ����
MI_KIMERADON1	//Ű�޶�
{
	Maxitem = 2;
	DropGold(88, 128);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_HOOKKIMERA, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
			berserk 15 2                                 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KIMERADON2
{
	Maxitem = 2;
	DropGold(88, 128);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_HOOKKIMERA, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
			berserk 15 2                                 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KIMERADON3
{
	Maxitem = 2;
	DropGold(90, 131);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_HOOKKIMERA, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			berserk 15 2.5                                 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KIMERADON4
{
	Maxitem = 2;
	DropGold(92, 133);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_HOOKKIMERA, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			berserk 15 3                                  
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KIMERADON5
{
	Maxitem = 2;
	DropGold(16999, 17000);

	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 60);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
			berserk 15 3.5                               
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_BEARNUCKY1	// �����Ű
{
	Maxitem = 2;
	DropGold(92, 134);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BEARMANE, 100000000, 0, 1);
	DropItem(II_SYS_BearPart_Head, 14000, 0, 1);
	DropItem(II_SYS_BearPart_Body, 14000, 0, 1);
	DropItem(II_SYS_BearPart_Arm, 14000, 0, 1);	 
	DropItem(II_SYS_BearPart_Leg, 14000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
			berserk 15 2                                
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_BEARNUCKY2
{
	Maxitem = 2;
	DropGold(92, 134);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BEARMANE, 200000000, 0, 1);
 	DropItem(II_SYS_BearPart_Head, 14000, 0, 1);
	DropItem(II_SYS_BearPart_Body, 14000, 0, 1);
	DropItem(II_SYS_BearPart_Arm, 14000, 0, 1);	 
	DropItem(II_SYS_BearPart_Leg, 14000, 0, 1);   

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack    
			berserk 15 2                             
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_BEARNUCKY3
{
	Maxitem = 2;
	DropGold(94, 136);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BEARMANE, 200000000, 0, 1);
  	DropItem(II_SYS_BearPart_Head, 14000, 0, 1);
	DropItem(II_SYS_BearPart_Body, 14000, 0, 1);
	DropItem(II_SYS_BearPart_Arm, 14000, 0, 1);	 
	DropItem(II_SYS_BearPart_Leg, 14000, 0, 1);  

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack   
			berserk 15 2.5                              
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_BEARNUCKY4
{
	Maxitem = 2;
	DropGold(96, 139);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_BEARMANE, 200000000, 0, 1);
 	DropItem(II_SYS_BearPart_Head, 14000, 0, 1);
	DropItem(II_SYS_BearPart_Body, 14000, 0, 1);
	DropItem(II_SYS_BearPart_Arm, 14000, 0, 1);	 
	DropItem(II_SYS_BearPart_Leg, 14000, 0, 1);   

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			berserk 15 3                                 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_BEARNUCKY5
{
	Maxitem = 2;
	DropGold(16999, 17000);

	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 60);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);
	DropItem(II_SYS_BearPart_Head, 55000, 0, 1);
	DropItem(II_SYS_BearPart_Body, 55000, 0, 1);
	DropItem(II_SYS_BearPart_Arm, 55000, 0, 1);	 
	DropItem(II_SYS_BearPart_Leg, 55000, 0, 1);	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
			berserk 15 3.5                                
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MUFFRIN1	//��Ǫ��
{
	Maxitem = 2;
	DropGold(97, 141);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_CRUETMUF, 100000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack   
			berserk 15 2                               
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MUFFRIN2
{
	Maxitem = 2;
	DropGold(97, 141);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_CRUETMUF, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack   
			berserk 15 2                            
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MUFFRIN3
{
	Maxitem = 2;
	DropGold(99, 143);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_CRUETMUF, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			berserk 15 2.5                                 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MUFFRIN4
{
	Maxitem = 2;
	DropGold(99, 143);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_CRUETMUF, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
			berserk 15 3                                
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MUFFRIN6
{
	Maxitem = 2;
	DropGold(16999, 17000);

	DropItem(II_WEA_SWO_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_SWT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_AXT_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_KNU_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_CHE_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_WAN_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_STA_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_BOW_ANGEL, 3150000, 0, 1);
	DropItem(II_WEA_YOY_ANGEL, 3150000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 60);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);
	DropItem(II_GEN_GEM_CRAFTMATERIAL022, 17500000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
			berserk 15 3.5                                 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POPCRANK1
{
	Maxitem = 2;
	DropGold(99, 142);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SHIFTPOP, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
			berserk 15 2                                
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POPCRANK2
{
	Maxitem = 2;
	DropGold(99, 142);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SHIFTPOP, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack   
			berserk 15 2                               
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POPCRANK3
{
	Maxitem = 2;
	DropGold(99, 143);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SHIFTPOP, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			 Attack 
			berserk 15 2.5                                
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POPCRANK4
{
	Maxitem = 2;
	DropGold(99, 143);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_SHIFTPOP, 200000000, 0, 1);
    

 	DropItem(II_GEN_GEM_CRAFTMATERIAL096, 350000, 0, 1);   

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			berserk 15 3                                  
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POPCRANK5
{
	Maxitem = 3;
	DropGold(17499, 17500);

	DropItem(II_WEA_SWO_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 3150000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 3150000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 12);

	//Knight
	DropItem(II_ARM_M_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_M_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_M_KIN_BOOTS_SET_10, 770123, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_F_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_F_KIN_BOOTS_SET_10, 770123, 0, 1);
	
	//Blade
	DropItem(II_ARM_M_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_M_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 770123, 0, 1);          
	DropItem(II_ARM_M_BLA_BOOTS_SET_13, 770123, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_F_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 770123, 0, 1);         
	DropItem(II_ARM_F_BLA_BOOTS_SET_13, 770123, 0, 1);
	
	//Jester
	DropItem(II_ARM_M_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_M_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_M_JST_BOOTS_SET_16, 770123, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_F_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_F_JST_BOOTS_SET_16, 770123, 0, 1);
	
	//Ranger
	DropItem(II_ARM_M_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_M_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_M_RAG_BOOTS_SET_19, 770123, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_F_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_F_RAG_BOOTS_SET_19, 770123, 0, 1);
	
	//Ringmaster
	DropItem(II_ARM_M_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_M_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_M_RIN_BOOTS_SET_22, 770123, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_F_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_F_RIN_BOOTS_SET_22, 770123, 0, 1);
		
	//Billposter
	DropItem(II_ARM_M_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_M_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_M_BIL_BOOTS_SET_25, 770123, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_F_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_F_BIL_BOOTS_SET_25, 770123, 0, 1);
	
	//Psykeper
	DropItem(II_ARM_M_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_M_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_M_PSY_BOOTS_SET_28, 770123, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_F_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_F_PSY_BOOTS_SET_28, 770123, 0, 1);
	
	//Elementor
	DropItem(II_ARM_M_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_M_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_M_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_F_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_F_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 65);
	DropItem(II_GEN_GEM_CRAFTMATERIAL036, 25000000, 0, 1);
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
			berserk 15 3.5                               
                    }
		#move
		    {
			
		    }	
   	}               
}


//������ ����
MI_DUFEFERN1
{
	Maxitem = 2;
	DropGold(30, 44);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_MAT_ORICHALCUM01, 7500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3050000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DUTARINROOT, 100000000, 0, 1);
	

	DropItem(II_SYS_SYS_KEY_COPPER, 200000000, 0, 1);
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam 
                                   
                    }
		#move
		    {
			
		    }	
   	}               

}
MI_DUFEFERN2
{
	Maxitem = 2;
	DropGold(30, 44);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_MAT_ORICHALCUM01, 7500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3050000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DUTARINROOT, 100000000, 0, 1);
	DropItem(II_SYS_SYS_KEY_COPPER, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
                        
                        berserk 20 1.25           
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}
MI_DUFEFERN3
{
	Maxitem = 5;
	DropGold(224, 324);


	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	
	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DUTARINROOT, 1000000000, 0, 1);
	DropItem(II_GEN_GEM_GEM_DUTARINROOT, 1000000000, 0, 1);


	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                          
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}            
}
MI_DUNYANGNYANG1
{
	Maxitem = 2;
	DropGold(31, 45);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3050000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DUSTARSTONE, 100000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL074, 250000, 0, 1);

	m_nAttackFirstRange = 10;
	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 30 cunning sam
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_DUNYANGNYANG2
{
	Maxitem = 2;
	DropGold(32, 46);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3050000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DUSTARSTONE, 100000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL074, 250000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
                        
                                    
                    }
		#move
		    {
			
		    }	
   	}              
}
MI_DUNYANGNYANG3
{
	Maxitem = 5;
	DropGold(229, 332);
	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DUSTARSTONE, 1000000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL074, 250000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                        Berserk 20 1.4            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}
MI_DUBANG1
{
	Maxitem = 2;
	DropGold(32, 46);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3050000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DUGOLDENWING, 100000000, 0, 1);

	DropItem(II_SYS_SYS_KEY_COPPER, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10  
                        berserk 20 1.2            
                    }
		#move
		    {
			
		    }	
   	}            

}
MI_DUBANG2
{
	Maxitem = 2;
	DropGold(32, 47);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3050000, 0, 1);
	
	DropItem(II_GEN_GEM_GEM_DUGOLDENWING, 100000000, 0, 1);

	DropItem(II_SYS_SYS_KEY_COPPER, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning sam
                        
                        Evade 10            
                    }
		#move
		    {
			
		    }	
   	}   
}
MI_DUBANG3
{
	Maxitem = 5;
	DropGold(240, 349);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DUGOLDENWING, 1000000000, 0, 1);
	DropItem(II_GEN_GEM_GEM_DUGOLDENWING, 1000000000, 0, 1);




	DropItem(II_SYS_SYS_KEY_COPPER, 200000000, 0, 1);
	DropItem(II_SYS_SYS_KEY_SILVER, 20000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}                            

}
MI_WORMVEDUQUE
{
	Maxitem = 5;
	DropGold(60, 70);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);




	m_nAttackFirstRange = 10;
	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
    		    }
		#move
		    {
			loot d 2
		    }	
   	}               

}
MI_SERUSURIEL
{
	Maxitem = 5;
	DropGold(70, 80);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
			recovery 20 70 100 m
			berserk 10 2                
                    }
		#move
		    {
			loot d 2
		    }	
   	}               

}
MI_VICEVEDUQUE
{
	Maxitem = 2;
	DropGold(39, 56);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack cunning low
                    }
		#move
		    {
			loot d 2
		    }	
   	}               

}

MI_GUARDMON1 // Venel Guardian
{

	Maxitem = 2;
	DropGold(10000, 15000);

	DropItem(II_GEN_GEM_RECYCLEMATERIAL8,  30000000, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                        
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_SHURAITURE
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 10 1.5              
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_REN
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         summon 30 1 MI_AIBATT3
			 berserk 10 1.5              
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_SISIF
{

	m_nAttackFirstRange = 10;	

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 15 1.5            
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_RUBO
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         summon 30 1 MI_AIBATT3
			 berserk 10 1.5             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_CHANER
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 10 1.5              
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_BABARI
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 10 1.5              
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_SEIDO
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 10 1.5              
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_KIDLER
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         summon 30 2 MI_LAWOLF1
			 berserk 15 2             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_SHAKALPION
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 20 2             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_HOIREN
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         summon 30 3 MI_WAGSAAC2
			 berserk 10 1.5             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_HUNTERX
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         summon 30 3 MI_BANG2
			 berserk 10 1.5             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_KYNSY
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         summon 30 3 MI_FEFERN3
			 berserk 15 1.5             
                    }

		#move
		    {
			
		    }	
   	}   
}

//�Ϲ� ����Ʈ ����	
MI_RBANG1
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 20 2             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_RBANG2
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 25 2             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_LORDBANG
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan quest 112
                    }

		#battle
		    {
		         berserk 10 2             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_LBHANOYAN
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 10 3            
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_MOMYORN
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                     
                    }

		#move
		    {
			
		    }	
   	}
}

MI_CLOCKS
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 10 2.5             
                    }

		#move
		    {
			
		    }	
   	}   
}

//�ó����� ����Ʈ(2��) ����	
MI_VIOLMAGICION
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan quest 1019
                    }

		#battle
		    {
		         berserk 15 2             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_VIOLMAGICION2
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan quest 1021
                    }

		#battle
		    {
		         berserk 20 2             
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_VIOLMAGICION3
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan quest 1024
                    }

		#battle
		    {
		         berserk 15 3            
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_EMERALDMANTIS
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan quest 118
                    }

		#battle
		    {
		         berserk 15 3            
                    }

		#move
		    {
			
		    }	
   	}   
}

//�Ϲ� ����Ʈ(����Mob) ����	
MI_ORGANIGOR
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 25 2             
                    }

		#move
		    {
			
		    }	
   	}   
}	

MI_GANGARD
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 20 2             
                    }

		#move
		    {
			
		    }	
   	}   
}	

MI_HADESEOR
{

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		         berserk 15 2             
                    }

		#move
		    {
			
		    }	
   	}   
}

//P.K ���� ��� �� ���� ����

MI_MaEw_GUARDIAN01
{
	
	m_nAttackFirstRange = 10;

	SetCallHelper( 0, 0, 0, FALSE );

	AI
	{
		#Scan
                    {
			scan range 10 chao 100
                    }

		#battle
		    {
			attack
			Helper sam 5000 1
			Rangeattack 10              
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_MaEw_GUARDIAN02
{
	
	m_nAttackFirstRange = 10;

	SetCallHelper( 0, 0, 0, FALSE );

	AI
	{
		#Scan
                    {
			scan range 10 chao 100
                    }

		#battle
		    {
			attack
			Helper sam 5000 1
			Rangeattack 10              
                    }

		#move
		    {
			
		    }	
   	}   
}

MI_GUARDIAN
{
	
	m_nAttackFirstRange = 10;

	SetCallHelper( 0, 0, 0, FALSE );

	AI
	{
		#Scan
                    {
			scan range 10 chao 100
                    }

		#battle
		    {
			attack
			Helper sam 5000 1
			Rangeattack 10              
                    }

		#move
		    {
			
		    }	
   	}   
}
MI_CHAOGUARDIAN
{

	m_nAttackFirstRange = 10;

	SetCallHelper( 0, 0, 0, FALSE );

	AI
	{
		#Scan
                    {
			scan range 10 chao 101
                    }

		#battle
		    {
		       attack	
		       Helper sam 5000 1 
		       Rangeattack 10                  
                    }

		#move
		    {
			
		    }	
   	}   
}
MI_PK_FEFERN
{
	DropGold(1, 5);


	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_WAGSAAC
{

	DropGold(1, 5);


	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_MRPUMPKIN
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_GIGGLEBOX
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;	
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_HOBO
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_CARDPUPPET
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_BASQUE
{

	DropGold(1, 5);
	
	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_LEYENA
{

	DropGold(1, 5);
	
	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_STEELKNIGHT
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_VOLT
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);	
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_GARBAGEPIDER
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;	
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_GREEMONG
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_HOPPRE
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_IREN
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_WATANGKA
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_LUIA
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_SHUHAMMA
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_PK_GLAPHAN
{

	DropGold(1, 5);

	DropItem(II_SYS_SYS_KEY_PKENTRANCE,  30000000, 0, 1);
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}

MI_HAMMERKICK
{
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               
}

MI_ANTTURTLE
{
	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               
}

MI_DU_DKKEAKOON1 // Keakoon Worker
{

	Maxitem = 2;
	DropGold(160, 206);

	DropItem(II_GEN_GEM_RECYCLEMATERIAL4, 1000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5, 1000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6, 1000000, 0, 1);
    DropItem(II_GEN_GEM_RECYCLEMATERIAL7, 1000000, 0, 1);


	m_nAttackFirstRange = 10;

	AI
	{ 
		#Scan
                    {
		
                    }

		#battle
		    {
			attack               
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON2
{

	Maxitem = 2;
	DropGold(160, 206);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);




	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan range 5 quest 68
                    }

		#battle
		    {
			                 
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON3 // Keakoon Worker Leader
{
	Maxitem = 2;
	DropGold(160, 206);


	DropItem(II_GEN_GEM_RECYCLEMATERIAL4, 1000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5, 1000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6, 1000000, 0, 1);
    DropItem(II_GEN_GEM_RECYCLEMATERIAL7, 1000000, 0, 1);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
	
                    }

		#battle
		    {
			attack                
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON4
{
	Maxitem = 5;
	DropGold(150, 182);



	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan range 5 quest 68
                    }

		#battle
		    {    
			berserk 10 1.5           
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON5
{

	Maxitem = 2;
	DropGold(160, 206);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);






	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {

                    }

		#battle
		    {
			evade 1                  
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON6 // Elite Keakoon Guard
{

	Maxitem = 2;
	DropGold(160, 206);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL4, 1000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5, 1000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6, 1000000, 0, 1);
    DropItem(II_GEN_GEM_RECYCLEMATERIAL7, 1000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			attack
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON7
{
	Maxitem = 5;
	DropGold(150, 185);



	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan range 5 quest 70
                    }

		#battle
		    {
			evade 1             
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON8
{
	Maxitem = 5;
	DropGold(150, 185);



	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan range 5 quest 70
                    }

		#battle
		    {    
			berserk 10 1.5
			recovery 20 50 100 m               
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON9
{

	Maxitem = 2;
	DropGold(80, 116);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3050000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    { 
			berserk 10 1.5
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON10
{

	Maxitem = 2;
	DropGold(80, 116);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3050000, 0, 1);

	m_nAttackFirstRange = 10;


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
			berserk 10 1.5
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON11
{

	Maxitem = 5;
	DropGold(150, 185);



	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);



	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {  
			berserk 10 1.5           
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKKEAKOON12
{

	Maxitem = 7;
	DropGold(150, 185);

	DropItem(II_GEN_JEW_RIN_STRRING, 10000000, 4, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 10000000, 4, 1);

	DropItem(II_GEN_MAT_ORICHALCUM01, 45150000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 12480000, 0, 1);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {  
			 berserk 10 1.8
		         recovery 20 70 100 a             
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKROACHFL1 // Blue Roach
{

	Maxitem = 2;
	DropGold(160, 206);

	DropItem(II_GEN_GEM_RECYCLEMATERIAL4, 1200000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5, 1200000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6, 1200000, 0, 1);
    DropItem(II_GEN_GEM_RECYCLEMATERIAL7, 1200000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKROACHFL2 // Pink Roach
{

	Maxitem = 2;
	DropGold(160, 206);

	DropItem(II_GEN_GEM_RECYCLEMATERIAL4, 1200000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5, 1200000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6, 1200000, 0, 1);
    DropItem(II_GEN_GEM_RECYCLEMATERIAL7, 1200000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKROACHFL3
{
	Maxitem = 5;
	DropGold(15499, 15500);



	DropItem(II_GEN_GEM_RECYCLEMATERIAL4 , 30000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5 , 30000000, 0, 3);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6 , 30000000, 0, 5);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL7 , 30000000, 0, 8);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 10 1.5              
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKROACHFL4
{
	Maxitem = 5;
	DropGold(150, 185);



	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 10 1.5           
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKROACHFL5
{

	Maxitem = 2;
	DropGold(160, 206);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	
	DropItem(II_GEN_MAT_ORICHALCUM01, 2250000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1200000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		       
		       evade 5   		              
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKROACHFL6
{

	Maxitem = 2;
	DropGold(160, 206);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_MAT_ORICHALCUM01, 2250000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1200000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		       evade 5               
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKTRILLIPY1 // Green Trillipy
{

	Maxitem = 2;
	DropGold(160, 206);

	DropItem(II_GEN_GEM_RECYCLEMATERIAL4, 1400000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5, 1400000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6, 1400000, 0, 1);
    DropItem(II_GEN_GEM_RECYCLEMATERIAL7, 1400000, 0, 1);
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 15 1.2     
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKTRILLIPY2
{

	Maxitem = 5;
	DropGold(150, 185);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {     
			berserk 20 1.5
			recovery 20 50 100 m                
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKTRILLIPY3 // Violet Trillipy
{

	Maxitem = 2;
	DropGold(160, 206);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL4, 1400000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5, 1400000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6, 1400000, 0, 1);
    DropItem(II_GEN_GEM_RECYCLEMATERIAL7, 1400000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		     	berserk 15 1.2             
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKTRILLIPY4
{

	Maxitem = 5;
	DropGold(150, 185);



	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);


	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {  
			berserk 20 1.5
			recovery 20 50 100 m                 
                    }

		#move
		    {
			
		    }	
   	}               

}
MI_DU_DKTRILLIPY5 // Blood Trillipy
{

	Maxitem = 2;
	DropGold(160, 206);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL4, 1400000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5, 1400000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6, 1400000, 0, 1);
    DropItem(II_GEN_GEM_RECYCLEMATERIAL7, 1400000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 15 1.2             
                    }
		#move
		    {
			
		    }	
   	}               
}
MI_DU_DKTRILLIPY6
{

	Maxitem = 5;
	DropGold(15499, 15500);



	DropItem(II_GEN_GEM_RECYCLEMATERIAL4 , 30000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5 , 30000000, 0, 3);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6 , 30000000, 0, 5);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL7 , 30000000, 0, 8);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {  
			berserk 20 1.5
			recovery 20 50 100 m               
                    }

		#move
		    {
			
		    }	
   	}               
}
MI_DU_DKKIMERADON1
{

	Maxitem = 2;
	DropGold(80, 116);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_MAT_ORICHALCUM01, 11262500, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 920000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		                       
                    }

		#move
		    {
			
		    }	
   	}               
}
MI_DU_DKKIMERADON2
{

	Maxitem = 5;
	DropGold(588, 852);

	DropItem(II_GEN_JEW_RIN_STRRING, 4166000, 4, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 4166000, 4, 1);

	DropItem(II_GEN_MAT_ORICHALCUM01, 22575000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 6240000, 0, 1);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 30 1.8
			recovery 20 50 100 m               
                    }

		#move
		    {
			
		    }	
   	}               
}

MI_DU_METEONYKER
{
	Maxitem = 3;
    DropGold(150, 151);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_DRAGONHEART, 100000000, 0, 1);
	DropItem(II_GEN_GEM_GEM_DRAGONCANINE, 200000000, 0, 1);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 20 2.0
        
                    }

		#move
		    {
			
		    }	
   	}               

}

MI_DU_METEONYKER_1 //old wise Meteonyker
{
	Maxitem = 10;
    DropGold(50000, 50001);

	DropItem(II_ARM_M_KIN_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_M_KIN_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_F_KIN_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_M_BLA_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_M_JST_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_M_JST_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_M_RAG_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_M_RIN_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_M_BIL_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_M_PSY_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_M_ELE_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_F_BLA_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_F_JST_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_F_JST_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_F_RAG_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_F_RIN_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_F_BIL_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_F_PSY_BOOTS_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_33_30	, 1500000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_33_30	, 1500000, 0, 1);	
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_33_30, 1500000, 0, 1);	
	DropItem(II_ARM_F_ELE_BOOTS_SET_33_30	, 1500000, 0, 1);

	//Dragon Gold Nuggets


	//Random Stat increase Scrolls
	DropItem(II_SYS_SYS_SCR_RANDOMSTR, 50000000, 0, 2);
	DropItem(II_SYS_SYS_SCR_RANDOMDEX, 50000000, 0, 2);
	DropItem(II_SYS_SYS_SCR_RANDOMSTA, 50000000, 0, 2);
	DropItem(II_SYS_SYS_SCR_RANDOMINT, 50000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL027, 55000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL036, 65000000, 0, 1);

	//Gold Bars to make money
	DropItem(II_GEN_GEM_CRAFTBAR02, 50000000, 0, 1);	
	DropItem(II_GEN_GEM_RECYCLEMATERIAL1, 35000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL2, 25000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL3, 20000000, 0, 1);
	DropItem(II_SYS_SYS_QUE_DRAGONGOLD, 50000000, 0, 1);

	// Golden Dragon Egg
	DropItem(II_GEN_GEM_CRAFTMATERIAL221, 2750000, 0, 1);



	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 20 2.0
        
                    }

		#move
		    {
			
		    }	
   	}               

}

MI_DU_METEONYKER2 // Red Meteonyker
{
	Maxitem = 2;
	DropGold(29999, 30000);

	DropItem(II_GEN_MAT_ORICHALCUM02, 15000000, 0, 15);
	DropItem(II_SYS_SYS_BACARDBOX, 20000000, 0, 35);		
	DropItem(II_RID_RID_BOR_RIDINGCLOUD04, 250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL215, 750000, 0, 1);

	DropItem(II_WEA_SWO_BLOODY, 3000000, 0, 1);
	DropItem(II_WEA_SWT_BLOODY, 3000000, 0, 1);
	DropItem(II_WEA_AXE_BLOODY, 3000000, 0, 1);
	DropItem(II_WEA_AXT_BLOODY, 3000000, 0, 1);
	DropItem(II_WEA_KNU_BLOODY, 3000000, 0, 1);
	DropItem(II_WEA_CHE_BLOODY, 3000000, 0, 1);
	DropItem(II_WEA_WAN_BLOODY2, 3000000, 0, 1);
	DropItem(II_WEA_STA_BLOODY, 3000000, 0, 1);
	DropItem(II_WEA_BOW_BLOODY, 3000000, 0, 1);
	DropItem(II_WEA_YOY_BLOODY, 3000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL027, 3500000, 0, 1);



	m_nAttackFirstRange = 10;

	AI
	{
		#battle
		{
			berserk 2 1.5
		}
	}
}

MI_DU_METEONYKER3 // Blue Meteonyker
{
	Maxitem = 2;
	DropGold(29999, 30000);

	DropItem(II_GEN_MAT_ORICHALCUM02, 35000000, 0, 10);
	DropItem(II_SYS_SYS_BACARDBOX, 35000000, 0, 25);
	DropItem(II_GEN_GEM_CRAFTMATERIAL217, 1000000, 0, 1);
	DropItem(II_RID_RID_BOR_RIDINGCLOUD, 250000, 0, 1);
	DropItem(II_GEN_JEW_RIN_STRRING, 5000000, 18, 1);
	DropItem(II_GEN_JEW_RIN_DEXRING, 5000000, 18, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 5000000, 18, 1);
	DropItem(II_GEN_JEW_RIN_STARING, 5000000, 18, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 5000000, 18, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 5000000, 18, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACE, 5000000, 18, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACE, 5000000, 18, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACE, 5000000, 18, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#battle
		{
			berserk 2 1.5
		}
	}
}

MI_DU_METEONYKER4 // Green Meteonyker
{
	Maxitem = 3;
	DropGold(29999, 30000);

		DropItem(II_GEN_MAT_ORICHALCUM02, 20000000, 0, 10);
		DropItem(II_SYS_SYS_BACARDBOX, 20000000, 0, 25);
		DropItem(II_SYS_SYS_SCR_CLOUDBOX, 20000000, 0, 7);
		DropItem(II_GEN_GEM_CRAFTMATERIAL213, 1000000, 0, 1);
		DropItem(II_GEN_GEM_CRAFTMATERIAL012, 500000, 0, 1);
		DropItem(II_ARM_M_KIN_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_KIN_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_BLA_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_BLA_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_JST_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_JST_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_RAG_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_RAG_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_RIN_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_RIN_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_BIL_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_BIL_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_PSY_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_PSY_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_ELE_HELMET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_ELE_HELMET_SET_33, 650000, 0, 1);	
		DropItem(II_ARM_M_KIN_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_KIN_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_BLA_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_BLA_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_JST_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_JST_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_RAG_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_RAG_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_RIN_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_RIN_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_BIL_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_BIL_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_PSY_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_PSY_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_ELE_SUIT_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_ELE_SUIT_SET_33, 650000, 0, 1);	
		DropItem(II_ARM_M_KIN_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_BLA_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_BLA_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_JST_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_JST_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_RAG_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_RAG_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_RIN_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_RIN_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_BIL_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_BIL_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_PSY_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_PSY_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_ELE_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_ELE_GAUNTLET_SET_33, 650000, 0, 1);	
		DropItem(II_ARM_F_KIN_GAUNTLET_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_BLA_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_BLA_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_JST_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_JST_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_RAG_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_RAG_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_RIN_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_RIN_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_BIL_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_BIL_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_PSY_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_PSY_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_M_ELE_BOOTS_SET_33, 650000, 0, 1);
		DropItem(II_ARM_F_ELE_BOOTS_SET_33, 650000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#battle
		{
			berserk 2 1.5
		}
	}
}

MI_DU_METEONYKER6 // Dragon prince Meteonyker
{
	Maxitem = 3;
	DropGold(80000, 99999);

	DropItem(II_GEN_JEW_EAR_U_EARRING11_1, 500000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING11_1, 500000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE11_1, 500000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_METEOFY_1, 500000, 0, 1);		
	DropItem(II_GEN_JEW_RIN_METEOFY_1, 500000, 0, 1);		
	DropItem(II_ARM_M_KIN_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_KIN_SUIT_SET_33_1	   , 500000, 0, 1); 
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_KIN_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_KIN_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_KIN_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_KIN_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_BLA_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_BLA_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_BLA_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_BLA_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_BLA_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_BLA_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_JST_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_JST_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_JST_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_JST_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_JST_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_JST_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_JST_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_JST_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_RAG_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_RAG_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_RAG_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_RAG_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_RAG_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_RAG_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_RIN_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_RIN_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_RIN_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_RIN_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_RIN_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_RIN_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_BIL_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_BIL_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_BIL_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_BIL_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_BIL_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_BIL_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_PSY_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_PSY_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_PSY_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_PSY_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_PSY_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_PSY_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_ELE_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_ELE_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_M_ELE_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_ELE_HELMET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_ELE_SUIT_SET_33_1, 500000, 0, 1);	    
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_33_1, 500000, 0, 1);	
	DropItem(II_ARM_F_ELE_BOOTS_SET_33_1, 500000, 0, 1);	    
	DropItem(II_WEA_SWO_BLOODY_1, 500000, 0, 1);  			
	DropItem(II_WEA_SWO_BLOODY_1, 500000, 0, 1);  			
	DropItem(II_WEA_SWT_BLOODY_1, 500000, 0, 1); 			
	DropItem(II_WEA_AXE_BLOODY_1, 500000, 0, 1); 			
	DropItem(II_WEA_AXE_BLOODY_1, 500000, 0, 1); 			
	DropItem(II_WEA_AXT_BLOODY_1, 500000, 0, 1); 			
	DropItem(II_WEA_KNU_BLOODY_1, 500000, 0, 1); 			
	DropItem(II_WEA_KNU_BLOODY_1_RM, 500000, 0, 1); 			
	DropItem(II_WEA_CHE_BLOODY_1, 500000, 0, 1); 			
	DropItem(II_WEA_WAN_BLOODY2_1, 500000, 0, 1);			
	DropItem(II_WEA_STA_BLOODY_1, 500000, 0, 1); 			
	DropItem(II_WEA_YOY_BLOODY_1, 500000, 0, 1); 			
	DropItem(II_WEA_BOW_BLOODY_1, 500000, 0, 1); 					
	DropItem(II_ARM_ARM_SHI_ANCIENT_22, 500000, 0, 1);		
	DropItem(II_ARM_ARM_SHI_ANCIENT_23, 500000, 0, 1);		

	m_nAttackFirstRange = 10;

	AI
	{
		#battle
		{
			berserk 2 1.5
		}
	}
}

// �̺�Ʈ�� ���� ����
MI_DEMIAN5
{
	Maxitem = 16;

	DropItem(II_GEN_MAG_TRI_NEWYEARBOMB, 1000000000, 0, 10);
	DropItem(II_GEN_MAG_TRI_FIRESHOWER, 3000000000, 0, 10);
	DropItem(II_GEN_MAG_TRI_SULNALBOMB, 3000000000, 0, 10);
	DropItem(II_GEN_MAG_TRI_GOODBYEBOMB, 3000000000, 0, 10);
	DropItem(II_GEN_MAG_TRI_HWFIREWORKS, 3000000000, 0, 10);
	DropItem(II_RID_RID_BOR_EVEINSHOVER, 2496000000, 0, 1);
	DropItem(II_RID_RID_BOR_LADOLF, 2496000000, 0, 1);
	DropItem(II_CHR_MAG_TRI_ANGELWING, 1248000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_FBOX, 624000000, 0, 1);

	m_nAttackFirstRange = 8;
}

MI_KEAKOON5
{
	Maxitem = 3;

	DropGold(30000, 30001);

	DropItem(II_GEN_GEM_RECYCLEMATERIAL4 , 30000000, 0, 1);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL5 , 30000000, 0, 3);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL6 , 30000000, 0, 5);
	DropItem(II_GEN_GEM_RECYCLEMATERIAL7 , 30000000, 0, 8);
	DropItem(II_SYS_SYS_SCR_DEKANE , 30000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_DEKANE , 30000000, 0, 1);


	m_nAttackFirstRange = 10;

	AI
	{ 
		#Scan
                    {
		
                    }

		#battle
		    {
			attack               
                    }

		#move
		    {
			
		    }	
   	}               

}


MI_MUFFRIN5
{
	Maxitem = 16;

	DropItem(II_GEN_FOO_PIL_YELLOW, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_BLUE, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_RED, 2496000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_GOLD, 2496000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_GRAY, 390000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 1248000000, 0, 5);
	DropItem(II_GEN_FOO_COO_DDUKGUKFRESH, 1248000000, 0, 5);
	DropItem(II_GEN_FOO_COO_DDUKGUKSWEET, 1248000000, 0, 5);
	DropItem(II_SYS_SYS_EVE_WHITEGIFTBOX, 624000000, 0, 1);

	m_nAttackFirstRange = 8;
}

// �̱� �̺�Ʈ ����

MI_LOADCLOCKWORK
{
	Maxitem = 4;
	DropItem(II_GEN_FOO_INS_SUPERSTARCANDY,  10000000, 0, 15);
	DropItem(II_GEN_FOO_INS_PANCAKE, 		  9000000, 0, 10);
	DropItem(II_GEN_FOO_INS_DONUT,			  8000000, 0, 8);
	DropItem(II_GEN_FOO_INS_CAKE, 			  7000000, 0, 7);
	DropItem(II_GEN_FOO_INS_CUPCAKE, 		  6000000, 0, 6);
	DropItem(II_GEN_FOO_INS_FRUITCAKE,  	  5000000, 0, 3);
    DropItem(II_GEN_GEM_CRAFTMATERIAL366, 220000000, 0, 3);  
	DropItem(II_CHP_FARMCHIP, 95000000, 0, 300);
	DropItem(II_GEN_GEM_CRAFTMATERIAL128, 220000000, 0, 2); 
	DropItem(II_GEN_JEW_EAR_U_EARRING03, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING06, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING09, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE03, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE06, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE09, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING03, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING06, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING09, 75000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_METEOFY, 75000000, 0, 1);	


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 30 2
                        recovery 5 20 100 m            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_BRIGADIER
{
	Maxitem = 8;

	DropItem(II_GEN_JEW_RIN_STRRING, 36000000, 4, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 36000000, 4, 1);
	DropItem(II_GEN_JEW_RIN_DEXRING, 36000000, 4, 1);
	DropItem(II_GEN_JEW_RIN_STARING, 36000000, 4, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACE, 36000000, 4, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACE, 36000000, 11, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACE, 36000000, 11, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 36000000, 3, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 36000000, 9, 1);

	DropKind(IK3_SWD, 95, 109);
	DropKind(IK3_AXE, 95, 109);
	DropKind(IK3_CHEERSTICK, 95, 109);
	DropKind(IK3_KNUCKLEHAMMER, 95, 109);
	DropKind(IK3_SHIELD, 95, 109);
	DropKind(IK3_BOW, 95, 109);
	DropKind(IK3_YOYO, 95, 109);
	DropKind(IK3_WAND, 95, 109);
	DropKind(IK3_STAFF, 95, 109);
	DropKind(IK3_HELMET, 95, 109);
	DropKind(IK3_SUIT, 95, 109);
	DropKind(IK3_GAUNTLET, 95, 109);
	DropKind(IK3_BOOTS, 95, 109);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 30 1.5
                        recovery 5 20 100 m            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_LIEUTENANT 
{
	Maxitem = 8;

	DropItem(II_GEN_JEW_RIN_STRRING, 360000000, 5, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 360000000, 5, 1);
	DropItem(II_GEN_JEW_RIN_DEXRING, 360000000, 5, 1);
	DropItem(II_GEN_JEW_RIN_STARING, 360000000, 5, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACE, 360000000, 5, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACE, 360000000, 9, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACE, 360000000, 9, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 360000000, 4, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 360000000, 9, 1);

	DropKind(IK3_SWD, 95, 109);
	DropKind(IK3_AXE, 95, 109);
	DropKind(IK3_CHEERSTICK, 95, 109);
	DropKind(IK3_KNUCKLEHAMMER, 95, 109);
	DropKind(IK3_WAND, 95, 109);
	DropKind(IK3_SHIELD, 95, 109);
	DropKind(IK3_BOW, 95, 109);
	DropKind(IK3_YOYO, 95, 109);
	DropKind(IK3_STAFF, 95, 109);
	DropKind(IK3_HELMET, 95, 109);
	DropKind(IK3_SUIT, 95, 109);
	DropKind(IK3_GAUNTLET, 95, 109);
	DropKind(IK3_BOOTS, 95, 109);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 30 1.5
                        recovery 5 20 100 m            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_SPIKETAIL 
{
	Maxitem = 8;

	DropItem(II_GEN_JEW_RIN_STRRING, 360000000, 5, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 360000000, 5, 1);
	DropItem(II_GEN_JEW_RIN_DEXRING, 360000000, 5, 1);
	DropItem(II_GEN_JEW_RIN_STARING, 360000000, 5, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACE, 360000000, 5, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACE, 360000000, 9, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACE, 360000000, 9, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 360000000, 4, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 360000000, 9, 1);

	DropKind(IK3_SWD, 95, 109);
	DropKind(IK3_AXE, 95, 109);
	DropKind(IK3_CHEERSTICK, 95, 109);
	DropKind(IK3_KNUCKLEHAMMER, 95, 109);
	DropKind(IK3_WAND, 95, 109);
	DropKind(IK3_STAFF, 95, 109);
	DropKind(IK3_SHIELD, 95, 109);
	DropKind(IK3_BOW, 95, 109);
	DropKind(IK3_YOYO, 95, 109);
	DropKind(IK3_HELMET, 95, 109);
	DropKind(IK3_SUIT, 95, 109);
	DropKind(IK3_GAUNTLET, 95, 109);
	DropKind(IK3_BOOTS, 95, 109);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 30 1.5
                        recovery 5 20 100 m            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_GLYPHAXZ 
{
	Maxitem = 8;

	DropItem(II_GEN_JEW_RIN_STRRING, 360000000, 6, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 360000000, 6, 1);
	DropItem(II_GEN_JEW_RIN_DEXRING, 360000000, 6, 1);
	DropItem(II_GEN_JEW_RIN_STARING, 360000000, 6, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACE, 360000000, 6, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACE, 360000000, 9, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACE, 360000000, 9, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 360000000, 4, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 360000000, 9, 1);

	DropKind(IK3_SWD, 95, 109);
	DropKind(IK3_AXE, 95, 109);
	DropKind(IK3_CHEERSTICK, 95, 109);
	DropKind(IK3_KNUCKLEHAMMER, 95, 109);
	DropKind(IK3_WAND, 95, 109);
	DropKind(IK3_SHIELD, 95, 109);
	DropKind(IK3_BOW, 95, 109);
	DropKind(IK3_YOYO, 95, 109);
        DropKind(IK3_STAFF, 95, 109);
	DropKind(IK3_HELMET, 95, 109);
	DropKind(IK3_SUIT, 95, 109);
	DropKind(IK3_GAUNTLET, 95, 109);
	DropKind(IK3_BOOTS, 95, 109);
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.7
                        summon 50 2 MI_DU_DKKIMERADON1       
                    }
		#move
		    {
			
		    }	
   	}               

}


//  Ivillis Temple

MI_IBLCRASHER
{
	Maxitem = 2;

    DropGold(43, 62);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLPOISONER
{
	Maxitem = 2;

    DropGold(55, 75);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLWRECKER
{
	Maxitem = 2;

    DropGold(62, 80);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLDOZER
{
	Maxitem = 2;

    DropGold(100, 110);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLPUPPET
{
	Maxitem = 2;

    DropGold(100, 150);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_MAT_ORICHALCUM01, 14500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 2800000, 0, 1);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLTAKER
{
	Maxitem = 2;

    DropGold(150, 200);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLREDOTEM
{
	Maxitem = 2;

    DropGold(1, 1000);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLBLACKOTEM
{
	Maxitem = 2;

    DropGold(1, 1000);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLBOXTER
{
	Maxitem = 2;

    DropGold(100, 200);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 30 2.0
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLDANDISHER
{
	Maxitem = 2;

    DropGold(150, 200);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.5
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLGUARDER
{
	Maxitem = 2;

    DropGold(100, 700);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.0
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_IBLQUAKER
{
	Maxitem = 2;

    DropGold(100, 750);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.0
                    }
		#move
		    {
			
		    }	
   	}               

}


MI_IBLMUCILAGER
{
	Maxitem = 2;

    DropGold(100, 800);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 1.0
                    }
		#move
		    {
			
		    }	
   	}               

}


MI_IBLLINESS // Leans
{
	Maxitem = 2;

        DropGold(1999, 2000);

	DropItem(II_WEA_SWO_IBLLINESS,  1050000, 0, 1);
	DropItem(II_WEA_SWT_IBLLINESS,  1100000, 0, 1);
	DropItem(II_WEA_AXE_IBLLINESS,  1050000, 0, 1);
	DropItem(II_WEA_AXT_IBLLINESS,  1100000, 0, 1);
	DropItem(II_WEA_KNU_IBLLINESS,  1100000, 0, 1);
	DropItem(II_WEA_CHE_IBLLINESS,  1100000, 0, 1);
	DropItem(II_WEA_WAN_IBLLINESS,  1100000, 0, 1);
	DropItem(II_WEA_STA_IBLLINESS,  1100000, 0, 1);
	DropItem(II_WEA_BOW_IBLLINESS,  1100000, 0, 1);
	DropItem(II_WEA_YOY_IBLLINESS,  1100000, 0, 1);
	DropItem(II_ARM_ARM_SHI_CONTRA, 1100000, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 30 3 MI_IBLDANDISHER       
                    }
		#move
		    {
			
		    }	
   	}               
}                 

MI_CYCLOPSX
{
	Maxitem = 3;
    DropGold(155, 156);

	DropItem(II_WEA_SWO_BLOODY, 450, 0, 1);
	DropItem(II_WEA_SWT_BLOODY, 450, 0, 1);
	DropItem(II_WEA_AXE_BLOODY, 450, 0, 1);
	DropItem(II_WEA_AXT_BLOODY, 450, 0, 1);
	DropItem(II_WEA_KNU_BLOODY, 450, 0, 1);
	DropItem(II_WEA_CHE_BLOODY, 450, 0, 1);
	DropItem(II_WEA_WAN_BLOODY2, 450, 0, 1);
	DropItem(II_WEA_STA_BLOODY, 450, 0, 1);
	DropItem(II_WEA_BOW_BLOODY, 450, 0, 1);
	DropItem(II_WEA_YOY_BLOODY, 450, 0, 1);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_STRANGEEYES, 100000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_NPC_YETI01
{
	Maxitem = 2;
    DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_REDCRYSTAL, 100000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL150, 500000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 15000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_AZRIAGIANT01
{
	Maxitem = 2;
        DropGold(900, 901);

	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL391, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_NPC_YETI02
{
	Maxitem = 2;
    DropGold(100, 101);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_REDCRYSTAL, 100000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL150, 500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  15000000, 0, 1);

	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_AZRIAGIANT02
{
	Maxitem = 2;
    DropGold(950, 951);

	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL391, 15000000, 0, 1);	


	m_nAttackFirstRange = 10;
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_NPC_AUGOO01
{
	Maxitem = 2;
    DropGold(101, 102);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_YELLOWCRYSTAL, 100000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 15000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_AZRIAGIANT03
{
	Maxitem = 2;
    DropGold(1000, 1002);

	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL391, 15000000, 0, 1);	


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_NPC_AUGOO02
{
	Maxitem = 2;
        DropGold(103, 104);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_YELLOWCRYSTAL, 100000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 15000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_AZRIAGIANT04
{
	Maxitem = 2;
    DropGold(1100, 1150);

	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL391, 15000000, 0, 1);	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_NPC_SADKING01
{
	Maxitem = 2;
        DropGold(105, 110);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GREENCRYSTAL, 100000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 15000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_AZRIAGIANT05
{
	Maxitem = 2;
    DropGold(1150, 1200);

	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL391, 15000000, 0, 1);	


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_NPC_SADKING02
{
	Maxitem = 2;
        DropGold(110, 115);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GREENCRYSTAL, 100000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 15000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_AZRIAGIANT06
{
	Maxitem = 2;
    DropGold(1300, 1350);

	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL391, 15000000, 0, 1);	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_NPC_MAMMOTH01
{
	Maxitem = 2;
        DropGold(120, 125);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BLUECRYSTAL, 100000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 15000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_AZRIAGIANT07
{
	Maxitem = 2;
    DropGold(1300, 1350);

	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL391, 15000000, 0, 1);	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_NPC_MAMMOTH02
{
	Maxitem = 2;
        DropGold(125, 130);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BLUECRYSTAL, 100000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 15000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_AZRIAGIANT08
{
	Maxitem = 2;
    DropGold(1400, 1450);

	
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 30000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 30000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL391, 15000000, 0, 1);	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
                    }
		#move
		    {
	            }	
   	}               

}

MI_EVENT01
{
	Maxitem = 30;

	DropItem(II_SYS_SYS_EVE_BALLOON_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON01_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON02_01, 3000000000, 0, 1);

	DropItem(II_SYS_SYS_SCR_COTTONCANDYVIOLET_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYBLUE_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYGREEN_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYRED_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYBLUESKY_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYPINK_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYYELLOW_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYWHITE_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYGRAY_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_COTTONCANDYORANGE_01, 3000000000, 0, 1);

	DropItem(II_GEN_FOO_COO_MEDICINE02, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_COO_MEDICINE02, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_COO_MEDICINE02, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_COO_MEDICINE02, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_COO_MEDICINE02, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_COO_MEDICINE02, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_COO_MEDICINE02, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_COO_MEDICINE02, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);
	DropItem(II_GEN_FOO_PIL_SINBI, 3000000000, 0, 10);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_EVENT02
{
	Maxitem = 30;

	DropItem(II_SYS_SYS_EVE_BALLOON_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON01_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON02_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON01_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON02_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON01_01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON02_01, 3000000000, 0, 1);

	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);



	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_EVENT03
{
	Maxitem = 50;



	DropItem(II_SYS_SYS_SCR_BXSUHO01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXSUHO01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXUSU01, 3000000000, 0, 1);

	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_EVENT04
{
	Maxitem = 50;

	DropItem(II_SYS_SYS_SCR_BXUSU01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXUSU01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXWOODSET01, 3000000000, 0, 1);

	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}               
}

//12�� ���� �߰� ����(�ӽù���)
MI_CAITSITH01
{
	Maxitem = 1;
	DropGold(79, 80);

	DropItem(II_GEN_GEM_GEM_CATBELL, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);

	//Mercenary
	DropItem(II_ARM_M_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_M_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_M_MER_GAUNTLET_SET_04, 100000, 0, 1);	
	DropItem(II_ARM_M_MER_BOOTS_SET_04, 100000, 0, 1);
	DropItem(II_ARM_F_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_F_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_GAUNTLET_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_BOOTS_SET_04, 100000, 0, 1);
	
//Acrobat
	DropItem(II_ARM_M_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_M_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_M_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_M_ACR_BOOTS_SET_05, 100000, 0, 1);
	DropItem(II_ARM_F_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_F_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_F_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_F_ACR_BOOTS_SET_05, 100000, 0, 1);
	
//Asist
	DropItem(II_ARM_M_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_M_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_M_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_M_ASS_BOOTS_SET_06, 100000, 0, 1);
	DropItem(II_ARM_F_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_F_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_F_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_F_ASS_BOOTS_SET_06, 100000, 0, 1);
	
//Magician
	DropItem(II_ARM_M_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_M_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_M_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_M_MAG_BOOTS_SET_07, 100000, 0, 1);
	DropItem(II_ARM_F_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_F_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_F_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_F_MAG_BOOTS_SET_07, 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CAITSITH02
{
	Maxitem = 1;
	DropGold(79, 80);
	
	DropItem(II_GEN_GEM_GEM_CATBELL, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);


	//Mercenary
	DropItem(II_ARM_M_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_M_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_M_MER_GAUNTLET_SET_04, 100000, 0, 1);	
	DropItem(II_ARM_M_MER_BOOTS_SET_04, 100000, 0, 1);
	DropItem(II_ARM_F_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_F_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_GAUNTLET_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_BOOTS_SET_04, 100000, 0, 1);
	
//Acrobat
	DropItem(II_ARM_M_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_M_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_M_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_M_ACR_BOOTS_SET_05, 100000, 0, 1);
	DropItem(II_ARM_F_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_F_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_F_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_F_ACR_BOOTS_SET_05, 100000, 0, 1);
	
//Asist
	DropItem(II_ARM_M_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_M_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_M_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_M_ASS_BOOTS_SET_06, 100000, 0, 1);
	DropItem(II_ARM_F_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_F_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_F_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_F_ASS_BOOTS_SET_06, 100000, 0, 1);
	
//Magician
	DropItem(II_ARM_M_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_M_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_M_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_M_MAG_BOOTS_SET_07, 100000, 0, 1);
	DropItem(II_ARM_F_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_F_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_F_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_F_MAG_BOOTS_SET_07, 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CAITSITH03
{
	Maxitem = 1;
	DropGold(79, 80);
	
	DropItem(II_GEN_GEM_GEM_CATBELL, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);


	//Mercenary
	DropItem(II_ARM_M_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_M_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_M_MER_GAUNTLET_SET_04, 100000, 0, 1);	
	DropItem(II_ARM_M_MER_BOOTS_SET_04, 100000, 0, 1);
	DropItem(II_ARM_F_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_F_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_GAUNTLET_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_BOOTS_SET_04, 100000, 0, 1);
	
//Acrobat
	DropItem(II_ARM_M_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_M_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_M_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_M_ACR_BOOTS_SET_05, 100000, 0, 1);
	DropItem(II_ARM_F_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_F_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_F_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_F_ACR_BOOTS_SET_05, 100000, 0, 1);
	
//Asist
	DropItem(II_ARM_M_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_M_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_M_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_M_ASS_BOOTS_SET_06, 100000, 0, 1);
	DropItem(II_ARM_F_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_F_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_F_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_F_ASS_BOOTS_SET_06, 100000, 0, 1);
	
//Magician
	DropItem(II_ARM_M_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_M_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_M_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_M_MAG_BOOTS_SET_07, 100000, 0, 1);
	DropItem(II_ARM_F_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_F_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_F_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_F_MAG_BOOTS_SET_07, 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CAITSITH04 // Giant Catsy
{
	Maxitem = 3;
	DropGold(7999, 8000);

    //Mercenary
	DropItem(II_ARM_M_MER_HELMET_SET_04, 750000, 0, 1);		
	DropItem(II_ARM_M_MER_SUIT_SET_04, 750000, 0, 1);			
	DropItem(II_ARM_M_MER_GAUNTLET_SET_04, 750000, 0, 1);	
	DropItem(II_ARM_M_MER_BOOTS_SET_04, 750000, 0, 1);
	DropItem(II_ARM_F_MER_HELMET_SET_04, 750000, 0, 1);		
	DropItem(II_ARM_F_MER_SUIT_SET_04, 750000, 0, 1);			
	DropItem(II_ARM_F_MER_GAUNTLET_SET_04, 750000, 0, 1);			
	DropItem(II_ARM_F_MER_BOOTS_SET_04, 750000, 0, 1);
	
	//Acrobat
	DropItem(II_ARM_M_ACR_HELMET_SET_05, 750000, 0, 1);     
	DropItem(II_ARM_M_ACR_SUIT_SET_05, 750000, 0, 1);			   
	DropItem(II_ARM_M_ACR_GAUNTLET_SET_05, 750000, 0, 1);          
	DropItem(II_ARM_M_ACR_BOOTS_SET_05, 750000, 0, 1);
	DropItem(II_ARM_F_ACR_HELMET_SET_05, 750000, 0, 1);     
	DropItem(II_ARM_F_ACR_SUIT_SET_05, 750000, 0, 1);			   
	DropItem(II_ARM_F_ACR_GAUNTLET_SET_05, 750000, 0, 1);          
	DropItem(II_ARM_F_ACR_BOOTS_SET_05, 750000, 0, 1);
	
	//Asist
	DropItem(II_ARM_M_ASS_HELMET_SET_06, 750000, 0, 1);     
	DropItem(II_ARM_M_ASS_SUIT_SET_06, 750000, 0, 1);			   
	DropItem(II_ARM_M_ASS_GAUNTLET_SET_06, 750000, 0, 1);          
	DropItem(II_ARM_M_ASS_BOOTS_SET_06, 750000, 0, 1);
	DropItem(II_ARM_F_ASS_HELMET_SET_06, 750000, 0, 1);     
	DropItem(II_ARM_F_ASS_SUIT_SET_06, 750000, 0, 1);			   
	DropItem(II_ARM_F_ASS_GAUNTLET_SET_06, 750000, 0, 1);          
	DropItem(II_ARM_F_ASS_BOOTS_SET_06, 750000, 0, 1);
	
	//Magician
	DropItem(II_ARM_M_MAG_HELMET_SET_07, 750000, 0, 1);     
	DropItem(II_ARM_M_MAG_SUIT_SET_07, 750000, 0, 1);			   
	DropItem(II_ARM_M_MAG_GAUNTLET_SET_07, 750000, 0, 1);          
	DropItem(II_ARM_M_MAG_BOOTS_SET_07, 750000, 0, 1);
	DropItem(II_ARM_F_MAG_HELMET_SET_07, 750000, 0, 1);     
	DropItem(II_ARM_F_MAG_SUIT_SET_07, 750000, 0, 1);			   
	DropItem(II_ARM_F_MAG_GAUNTLET_SET_07, 750000, 0, 1);          
	DropItem(II_ARM_F_MAG_BOOTS_SET_07, 750000, 0, 1);
		DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 7);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CAITSITH04_1
{
	Maxitem = 3;
	DropGold(420, 609);

	DropItem(II_GEN_GEM_GEM_CATBELL, 30000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HARPY01
{
	Maxitem = 1;
	DropGold(87, 88);
	
	DropItem(II_GEN_GEM_GEM_HARPYFEATHER, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);

	//Mercenary
	DropItem(II_ARM_M_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_M_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_M_MER_GAUNTLET_SET_04, 100000, 0, 1);	
	DropItem(II_ARM_M_MER_BOOTS_SET_04, 100000, 0, 1);
	DropItem(II_ARM_F_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_F_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_GAUNTLET_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_BOOTS_SET_04, 100000, 0, 1);
	
//Acrobat
	DropItem(II_ARM_M_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_M_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_M_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_M_ACR_BOOTS_SET_05, 100000, 0, 1);
	DropItem(II_ARM_F_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_F_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_F_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_F_ACR_BOOTS_SET_05, 100000, 0, 1);
	
//Asist
	DropItem(II_ARM_M_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_M_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_M_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_M_ASS_BOOTS_SET_06, 100000, 0, 1);
	DropItem(II_ARM_F_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_F_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_F_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_F_ASS_BOOTS_SET_06, 100000, 0, 1);
	
//Magician
	DropItem(II_ARM_M_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_M_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_M_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_M_MAG_BOOTS_SET_07, 100000, 0, 1);
	DropItem(II_ARM_F_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_F_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_F_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_F_MAG_BOOTS_SET_07, 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HARPY02
{
	Maxitem = 1;
	DropGold(87, 88);
	
	DropItem(II_GEN_GEM_GEM_HARPYFEATHER, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);



	//Mercenary
	DropItem(II_ARM_M_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_M_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_M_MER_GAUNTLET_SET_04, 100000, 0, 1);	
	DropItem(II_ARM_M_MER_BOOTS_SET_04, 100000, 0, 1);
	DropItem(II_ARM_F_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_F_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_GAUNTLET_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_BOOTS_SET_04, 100000, 0, 1);
	
//Acrobat
	DropItem(II_ARM_M_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_M_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_M_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_M_ACR_BOOTS_SET_05, 100000, 0, 1);
	DropItem(II_ARM_F_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_F_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_F_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_F_ACR_BOOTS_SET_05, 100000, 0, 1);
	
//Asist
	DropItem(II_ARM_M_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_M_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_M_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_M_ASS_BOOTS_SET_06, 100000, 0, 1);
	DropItem(II_ARM_F_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_F_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_F_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_F_ASS_BOOTS_SET_06, 100000, 0, 1);
	
//Magician
	DropItem(II_ARM_M_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_M_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_M_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_M_MAG_BOOTS_SET_07, 100000, 0, 1);
	DropItem(II_ARM_F_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_F_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_F_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_F_MAG_BOOTS_SET_07, 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HARPY03
{
	Maxitem = 1;
	DropGold(87, 88);
	
	DropItem(II_GEN_GEM_GEM_HARPYFEATHER, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);



	//Mercenary
	DropItem(II_ARM_M_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_M_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_M_MER_GAUNTLET_SET_04, 100000, 0, 1);	
	DropItem(II_ARM_M_MER_BOOTS_SET_04, 100000, 0, 1);
	DropItem(II_ARM_F_MER_HELMET_SET_04, 100000, 0, 1);		
	DropItem(II_ARM_F_MER_SUIT_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_GAUNTLET_SET_04, 100000, 0, 1);			
	DropItem(II_ARM_F_MER_BOOTS_SET_04, 100000, 0, 1);
	
//Acrobat
	DropItem(II_ARM_M_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_M_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_M_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_M_ACR_BOOTS_SET_05, 100000, 0, 1);
	DropItem(II_ARM_F_ACR_HELMET_SET_05, 100000, 0, 1);     
	DropItem(II_ARM_F_ACR_SUIT_SET_05, 100000, 0, 1);			   
	DropItem(II_ARM_F_ACR_GAUNTLET_SET_05, 100000, 0, 1);          
	DropItem(II_ARM_F_ACR_BOOTS_SET_05, 100000, 0, 1);
	
//Asist
	DropItem(II_ARM_M_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_M_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_M_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_M_ASS_BOOTS_SET_06, 100000, 0, 1);
	DropItem(II_ARM_F_ASS_HELMET_SET_06, 100000, 0, 1);     
	DropItem(II_ARM_F_ASS_SUIT_SET_06, 100000, 0, 1);			   
	DropItem(II_ARM_F_ASS_GAUNTLET_SET_06, 100000, 0, 1);          
	DropItem(II_ARM_F_ASS_BOOTS_SET_06, 100000, 0, 1);
	
//Magician
	DropItem(II_ARM_M_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_M_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_M_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_M_MAG_BOOTS_SET_07, 100000, 0, 1);
	DropItem(II_ARM_F_MAG_HELMET_SET_07, 100000, 0, 1);     
	DropItem(II_ARM_F_MAG_SUIT_SET_07, 100000, 0, 1);			   
	DropItem(II_ARM_F_MAG_GAUNTLET_SET_07, 100000, 0, 1);          
	DropItem(II_ARM_F_MAG_BOOTS_SET_07, 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_HARPY04 // Giant Harpy
{
	Maxitem = 3;
	DropGold(8499, 8500);

	//Mercenary
	DropItem(II_ARM_M_MER_HELMET_SET_04, 750000, 0, 1);		
	DropItem(II_ARM_M_MER_SUIT_SET_04, 750000, 0, 1);			
	DropItem(II_ARM_M_MER_GAUNTLET_SET_04, 750000, 0, 1);	
	DropItem(II_ARM_M_MER_BOOTS_SET_04, 750000, 0, 1);
	DropItem(II_ARM_F_MER_HELMET_SET_04, 750000, 0, 1);		
	DropItem(II_ARM_F_MER_SUIT_SET_04, 750000, 0, 1);			
	DropItem(II_ARM_F_MER_GAUNTLET_SET_04, 750000, 0, 1);			
	DropItem(II_ARM_F_MER_BOOTS_SET_04, 750000, 0, 1);
	
	//Acrobat
	DropItem(II_ARM_M_ACR_HELMET_SET_05, 750000, 0, 1);     
	DropItem(II_ARM_M_ACR_SUIT_SET_05, 750000, 0, 1);			   
	DropItem(II_ARM_M_ACR_GAUNTLET_SET_05, 750000, 0, 1);          
	DropItem(II_ARM_M_ACR_BOOTS_SET_05, 750000, 0, 1);
	DropItem(II_ARM_F_ACR_HELMET_SET_05, 750000, 0, 1);     
	DropItem(II_ARM_F_ACR_SUIT_SET_05, 750000, 0, 1);			   
	DropItem(II_ARM_F_ACR_GAUNTLET_SET_05, 750000, 0, 1);          
	DropItem(II_ARM_F_ACR_BOOTS_SET_05, 750000, 0, 1);
	
	//Asist
	DropItem(II_ARM_M_ASS_HELMET_SET_06, 750000, 0, 1);     
	DropItem(II_ARM_M_ASS_SUIT_SET_06, 750000, 0, 1);			   
	DropItem(II_ARM_M_ASS_GAUNTLET_SET_06, 750000, 0, 1);          
	DropItem(II_ARM_M_ASS_BOOTS_SET_06, 750000, 0, 1);
	DropItem(II_ARM_F_ASS_HELMET_SET_06, 750000, 0, 1);     
	DropItem(II_ARM_F_ASS_SUIT_SET_06, 750000, 0, 1);			   
	DropItem(II_ARM_F_ASS_GAUNTLET_SET_06, 750000, 0, 1);          
	DropItem(II_ARM_F_ASS_BOOTS_SET_06, 750000, 0, 1);
	
	//Magician
	DropItem(II_ARM_M_MAG_HELMET_SET_07, 750000, 0, 1);     
	DropItem(II_ARM_M_MAG_SUIT_SET_07, 750000, 0, 1);			   
	DropItem(II_ARM_M_MAG_GAUNTLET_SET_07, 750000, 0, 1);          
	DropItem(II_ARM_M_MAG_BOOTS_SET_07, 750000, 0, 1);
	DropItem(II_ARM_F_MAG_HELMET_SET_07, 750000, 0, 1);     
	DropItem(II_ARM_F_MAG_SUIT_SET_07, 750000, 0, 1);			   
	DropItem(II_ARM_F_MAG_GAUNTLET_SET_07, 750000, 0, 1);          
	DropItem(II_ARM_F_MAG_BOOTS_SET_07, 750000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 7);	
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		     {
             Attack
			       }
		#move
		    {
			
		    }	
   	}               
}

MI_HARPY04_1
{
	Maxitem = 2;
	DropGold(464, 673);
	DropKind(IK3_SWD, 70, 76);
	DropKind(IK3_AXE, 70, 76);
	DropKind(IK3_CHEERSTICK, 70, 76);
	DropKind(IK3_KNUCKLEHAMMER, 70, 76);
	DropKind(IK3_WAND, 70, 76);
	DropKind(IK3_STAFF, 70, 76);
	DropKind(IK3_HELMET, 70, 76);
	DropKind(IK3_SUIT, 70, 76);
	DropKind(IK3_GAUNTLET, 70, 76);
	DropKind(IK3_BOOTS, 70, 76);
	DropKind(IK3_SHIELD, 70, 76);
	DropKind(IK3_BOW, 70, 76);
	DropKind(IK3_YOYO, 70, 76);
	DropKind(IK3_THSWD, 70, 76);
	DropKind(IK3_THAXE, 70, 76);	
	DropItem(II_GEN_GEM_GEM_HARPYFEATHER, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POLEVIK01
{
	Maxitem = 1;
	DropGold(94, 95);
	
	DropItem(II_GEN_GEM_GEM_POLEVIKMUD, 25000000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_08	 , 100000, 0, 1);    
	DropItem(II_ARM_F_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_HELMET_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11,100000, 0, 1);  
	DropItem(II_ARM_M_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_F_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_M_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17,100000, 0, 1);  
	DropItem(II_ARM_F_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_F_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_M_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_F_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_M_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26,100000, 0, 1);  
	DropItem(II_ARM_F_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_BOOTS_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_BOOTS_SET_29, 100000, 0, 1);  
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POLEVIK02
{
	Maxitem = 1;
	DropGold(94, 95);

	DropItem(II_GEN_GEM_GEM_POLEVIKMUD, 25000000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_08	 , 100000, 0, 1);    
	DropItem(II_ARM_F_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_HELMET_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11,100000, 0, 1);  
	DropItem(II_ARM_M_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_F_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_M_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17,100000, 0, 1);  
	DropItem(II_ARM_F_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_F_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_M_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_F_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_M_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26,100000, 0, 1);  
	DropItem(II_ARM_F_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_BOOTS_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_BOOTS_SET_29, 100000, 0, 1);  
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POLEVIK03
{
	Maxitem = 1;
	DropGold(94, 95);

	DropItem(II_GEN_GEM_GEM_POLEVIKMUD, 25000000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_08	 , 100000, 0, 1);    
	DropItem(II_ARM_F_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_HELMET_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11,100000, 0, 1);  
	DropItem(II_ARM_M_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_F_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_M_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17,100000, 0, 1);  
	DropItem(II_ARM_F_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_F_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_M_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_F_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_M_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26,100000, 0, 1);  
	DropItem(II_ARM_F_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_BOOTS_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_BOOTS_SET_29, 100000, 0, 1);  
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_POLEVIK04 // Giant Gullah
{
	Maxitem = 3;
	DropGold(8999, 9000);

	DropItem(II_ARM_F_KIN_HELMET_SET_08	 , 750000, 0, 1);    
	DropItem(II_ARM_F_KIN_SUIT_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08, 750000, 0, 1);  
	DropItem(II_ARM_F_KIN_BOOTS_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_M_KIN_HELMET_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_M_KIN_SUIT_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08, 750000, 0, 1);  
	DropItem(II_ARM_M_KIN_BOOTS_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_F_BLA_HELMET_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_F_BLA_SUIT_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11, 750000, 0, 1);  
	DropItem(II_ARM_F_BLA_BOOTS_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_M_BLA_HELMET_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_M_BLA_SUIT_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11,750000, 0, 1);  
	DropItem(II_ARM_M_BLA_BOOTS_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_F_JST_HELMET_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_F_JST_SUIT_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14,750000, 0, 1);  
	DropItem(II_ARM_F_JST_BOOTS_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_M_JST_HELMET_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_M_JST_SUIT_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14,750000, 0, 1);  
	DropItem(II_ARM_M_JST_BOOTS_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_F_RAG_HELMET_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_F_RAG_SUIT_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17,750000, 0, 1);  
	DropItem(II_ARM_F_RAG_BOOTS_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_M_RAG_HELMET_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_M_RAG_SUIT_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17, 750000, 0, 1);  
	DropItem(II_ARM_M_RAG_BOOTS_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_F_RIN_HELMET_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_F_RIN_SUIT_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20, 750000, 0, 1);  
	DropItem(II_ARM_F_RIN_BOOTS_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_M_RIN_HELMET_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_M_RIN_SUIT_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20, 750000, 0, 1);  
	DropItem(II_ARM_M_RIN_BOOTS_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_F_BIL_HELMET_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_F_BIL_SUIT_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23, 750000, 0, 1);  
	DropItem(II_ARM_F_BIL_BOOTS_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_M_BIL_HELMET_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_M_BIL_SUIT_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23, 750000, 0, 1);  
	DropItem(II_ARM_M_BIL_BOOTS_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_F_PSY_HELMET_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_F_PSY_SUIT_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26, 750000, 0, 1);  
	DropItem(II_ARM_F_PSY_BOOTS_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_M_PSY_HELMET_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_M_PSY_SUIT_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26, 750000, 0, 1);  
	DropItem(II_ARM_M_PSY_BOOTS_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_F_ELE_HELMET_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_F_ELE_SUIT_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29, 750000, 0, 1);  
	DropItem(II_ARM_F_ELE_BOOTS_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_M_ELE_HELMET_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_M_ELE_SUIT_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29, 750000, 0, 1);  
	DropItem(II_ARM_M_ELE_BOOTS_SET_29, 750000, 0, 1);  
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 10);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);		
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_POLEVIK04_1
{
	Maxitem = 2;
	DropGold(515, 747);
	DropKind(IK3_SWD, 71, 81);
	DropKind(IK3_AXE, 71, 81);
	DropKind(IK3_CHEERSTICK, 71, 81);
	DropKind(IK3_KNUCKLEHAMMER, 71, 81);
	DropKind(IK3_WAND, 71, 81);
	DropKind(IK3_STAFF, 71, 81);
	DropKind(IK3_HELMET, 71, 81);
	DropKind(IK3_SUIT, 71, 81);
	DropKind(IK3_GAUNTLET, 71, 81);
	DropKind(IK3_BOOTS, 71, 81);
	DropKind(IK3_SHIELD, 71, 81);
	DropKind(IK3_BOW, 71, 81);
	DropKind(IK3_YOYO, 71, 81);
	DropKind(IK3_THSWD, 71, 81);
	DropKind(IK3_THAXE, 71, 81);	
	DropItem(II_GEN_GEM_GEM_POLEVIKMUD, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ABRAXAS01
{
	Maxitem = 1;
	DropGold(100, 101);
	
	DropItem(II_GEN_GEM_GEM_BADTONGUE, 25000000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_08	 , 100000, 0, 1);    
	DropItem(II_ARM_F_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_HELMET_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11,100000, 0, 1);  
	DropItem(II_ARM_M_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_F_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_M_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17,100000, 0, 1);  
	DropItem(II_ARM_F_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_F_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_M_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_F_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_M_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26,100000, 0, 1);  
	DropItem(II_ARM_F_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_BOOTS_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_BOOTS_SET_29, 100000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);	  
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ABRAXAS02
{
	Maxitem = 1;
	DropGold(100, 101);
	
	DropItem(II_GEN_GEM_GEM_BADTONGUE, 25000000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_08	 , 100000, 0, 1);    
	DropItem(II_ARM_F_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_HELMET_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11,100000, 0, 1);  
	DropItem(II_ARM_M_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_F_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_M_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17,100000, 0, 1);  
	DropItem(II_ARM_F_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_F_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_M_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_F_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_M_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26,100000, 0, 1);  
	DropItem(II_ARM_F_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_BOOTS_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_BOOTS_SET_29, 100000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);	  
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ABRAXAS03
{
	Maxitem = 1;
	DropGold(100, 101);
	
	DropItem(II_GEN_GEM_GEM_BADTONGUE, 25000000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_08	 , 100000, 0, 1);    
	DropItem(II_ARM_F_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_F_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_HELMET_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_SUIT_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08, 100000, 0, 1);  
	DropItem(II_ARM_M_KIN_BOOTS_SET_08	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11, 100000, 0, 1);  
	DropItem(II_ARM_F_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_HELMET_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_SUIT_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11,100000, 0, 1);  
	DropItem(II_ARM_M_BLA_BOOTS_SET_11	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_F_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_HELMET_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_SUIT_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14,100000, 0, 1);  
	DropItem(II_ARM_M_JST_BOOTS_SET_14	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17,100000, 0, 1);  
	DropItem(II_ARM_F_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_HELMET_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_SUIT_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17, 100000, 0, 1);  
	DropItem(II_ARM_M_RAG_BOOTS_SET_17	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_F_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_HELMET_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_SUIT_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20,100000, 0, 1);  
	DropItem(II_ARM_M_RIN_BOOTS_SET_20	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_F_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_HELMET_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_SUIT_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23,100000, 0, 1);  
	DropItem(II_ARM_M_BIL_BOOTS_SET_23	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26,100000, 0, 1);  
	DropItem(II_ARM_F_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_HELMET_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_SUIT_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26, 100000, 0, 1);  
	DropItem(II_ARM_M_PSY_BOOTS_SET_26	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_F_ELE_BOOTS_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_HELMET_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_SUIT_SET_29	, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29, 100000, 0, 1);  
	DropItem(II_ARM_M_ELE_BOOTS_SET_29, 100000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);	  
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_ABRAXAS04 // Giant Abraxas
{
	Maxitem = 3;
	DropGold(9999, 10000);

	DropItem(II_ARM_F_KIN_HELMET_SET_08	 , 750000, 0, 1);    
	DropItem(II_ARM_F_KIN_SUIT_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08, 750000, 0, 1);  
	DropItem(II_ARM_F_KIN_BOOTS_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_M_KIN_HELMET_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_M_KIN_SUIT_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08, 750000, 0, 1);  
	DropItem(II_ARM_M_KIN_BOOTS_SET_08	, 750000, 0, 1);  
	DropItem(II_ARM_F_BLA_HELMET_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_F_BLA_SUIT_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11, 750000, 0, 1);  
	DropItem(II_ARM_F_BLA_BOOTS_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_M_BLA_HELMET_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_M_BLA_SUIT_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11,750000, 0, 1);  
	DropItem(II_ARM_M_BLA_BOOTS_SET_11	, 750000, 0, 1);  
	DropItem(II_ARM_F_JST_HELMET_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_F_JST_SUIT_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14,750000, 0, 1);  
	DropItem(II_ARM_F_JST_BOOTS_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_M_JST_HELMET_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_M_JST_SUIT_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14,750000, 0, 1);  
	DropItem(II_ARM_M_JST_BOOTS_SET_14	, 750000, 0, 1);  
	DropItem(II_ARM_F_RAG_HELMET_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_F_RAG_SUIT_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17,750000, 0, 1);  
	DropItem(II_ARM_F_RAG_BOOTS_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_M_RAG_HELMET_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_M_RAG_SUIT_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17, 750000, 0, 1);  
	DropItem(II_ARM_M_RAG_BOOTS_SET_17	, 750000, 0, 1);  
	DropItem(II_ARM_F_RIN_HELMET_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_F_RIN_SUIT_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20, 750000, 0, 1);  
	DropItem(II_ARM_F_RIN_BOOTS_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_M_RIN_HELMET_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_M_RIN_SUIT_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20, 750000, 0, 1);  
	DropItem(II_ARM_M_RIN_BOOTS_SET_20	, 750000, 0, 1);  
	DropItem(II_ARM_F_BIL_HELMET_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_F_BIL_SUIT_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23, 750000, 0, 1);  
	DropItem(II_ARM_F_BIL_BOOTS_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_M_BIL_HELMET_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_M_BIL_SUIT_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23, 750000, 0, 1);  
	DropItem(II_ARM_M_BIL_BOOTS_SET_23	, 750000, 0, 1);  
	DropItem(II_ARM_F_PSY_HELMET_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_F_PSY_SUIT_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26, 750000, 0, 1);  
	DropItem(II_ARM_F_PSY_BOOTS_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_M_PSY_HELMET_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_M_PSY_SUIT_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26, 750000, 0, 1);  
	DropItem(II_ARM_M_PSY_BOOTS_SET_26	, 750000, 0, 1);  
	DropItem(II_ARM_F_ELE_HELMET_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_F_ELE_SUIT_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29, 750000, 0, 1);  
	DropItem(II_ARM_F_ELE_BOOTS_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_M_ELE_HELMET_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_M_ELE_SUIT_SET_29	, 750000, 0, 1);  
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29, 750000, 0, 1);  
	DropItem(II_ARM_M_ELE_BOOTS_SET_29, 750000, 0, 1);  
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ABRAXAS04_1
{
	Maxitem = 2;
	DropGold(560, 812);
	DropKind(IK3_SWD, 73, 89);
	DropKind(IK3_AXE, 73, 89);
	DropKind(IK3_CHEERSTICK, 73, 89);
	DropKind(IK3_KNUCKLEHAMMER, 73, 89);
	DropKind(IK3_WAND, 73, 89);
	DropKind(IK3_STAFF, 73, 89);
	DropKind(IK3_HELMET, 73, 89);
	DropKind(IK3_SUIT, 73, 89);
	DropKind(IK3_GAUNTLET, 73, 89);
	DropKind(IK3_BOOTS, 73, 89);
	DropKind(IK3_SHIELD, 73, 89);
	DropKind(IK3_BOW, 73, 89);
	DropKind(IK3_YOYO, 73, 89);
	DropKind(IK3_THSWD, 73, 89);
	DropKind(IK3_THAXE, 73, 89);	
	DropItem(II_GEN_GEM_GEM_BADTONGUE, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HAG01
{
	Maxitem = 1;
	
	DropGold(114, 115);

	DropItem(II_GEN_GEM_GEM_HAGNAIL, 25000000, 0, 1);
	DropItem(II_ARM_M_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 100000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_30      , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_30      , 100000, 0, 1);


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HAG02
{
	Maxitem = 1;
	DropGold(114, 115);

	DropItem(II_GEN_GEM_GEM_HAGNAIL			,25000000, 0, 1);
	DropItem(II_ARM_M_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024     , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_30      , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_30      , 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HAG03
{
	Maxitem = 1;
	DropGold(114, 115);


	DropItem(II_GEN_GEM_GEM_HAGNAIL			,25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_30      , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_30      , 100000, 0, 1);


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_HAG04 // Giant Hague
{
	Maxitem = 3;
	DropGold(11110, 11111);

	DropItem(II_ARM_M_KIN_HELMET_SET_09     , 750000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_09     , 750000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09       , 750000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09       , 750000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09   , 750000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09   , 750000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_09      , 750000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_09      , 750000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_12     , 750000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_12     , 750000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12       , 750000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12       , 750000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12   , 750000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12   , 750000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12      , 750000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12      , 750000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_15     , 750000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_15     , 750000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15       , 750000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15       , 750000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15   , 750000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15   , 750000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_15      , 750000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_15      , 750000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_18     , 750000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_18     , 750000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18       , 750000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18       , 750000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18   , 750000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18   , 750000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_18      , 750000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_18      , 750000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_21     , 750000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_21     , 750000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21       , 750000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21       , 750000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21   , 750000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21   , 750000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_21      , 750000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_21      , 750000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_24     , 750000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_24     , 750000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24       , 750000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24       , 750000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24   , 750000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24   , 750000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_24      , 750000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_24      , 750000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_27     , 750000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_27     , 750000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27       , 750000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27       , 750000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27   , 750000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27   , 750000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_27      , 750000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_27      , 750000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_30     , 750000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_30     , 750000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_30       , 750000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_30       , 750000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30   , 750000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30   , 750000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_30      , 750000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_30      , 750000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);	
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 10);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_HAG04_1
{
	Maxitem = 2;
	DropGold(616, 893);
	DropKind(IK3_SWD, 80, 95);
	DropKind(IK3_AXE, 80, 95);
	DropKind(IK3_CHEERSTICK, 80, 95);
	DropKind(IK3_KNUCKLEHAMMER, 80, 95);
	DropKind(IK3_WAND, 80, 95);
	DropKind(IK3_STAFF, 80, 95);
	DropKind(IK3_HELMET, 80, 95);
	DropKind(IK3_SUIT, 80, 95);
	DropKind(IK3_GAUNTLET, 80, 95);
	DropKind(IK3_BOOTS, 80, 95);
	DropKind(IK3_SHIELD, 80, 95);
	DropKind(IK3_BOW, 80, 95);
	DropKind(IK3_YOYO, 80, 95);
	DropKind(IK3_THSWD, 80, 95);
	DropKind(IK3_THAXE, 80, 95);	
	DropItem(II_GEN_GEM_GEM_HAGNAIL, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_THOTH01
{
	Maxitem = 1;
	DropGold(121, 122);
	
	DropItem(II_GEN_GEM_GEM_HAGNAIL, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_30      , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_30      , 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_THOTH02
{
	Maxitem = 1;
	DropGold(121, 122);

	DropItem(II_GEN_GEM_GEM_HAGNAIL, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_30      , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_30      , 100000, 0, 1);


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_THOTH03
{
	Maxitem = 1;
	DropGold(121, 122);

	DropItem(II_GEN_GEM_GEM_HAGNAIL, 25000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_09     , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09       , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09   , 100000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_09      , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_12     , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12       , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12   , 100000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12      , 100000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_15     , 100000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15       , 100000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15   , 100000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_15      , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_18     , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18       , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18   , 100000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_18      , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_21     , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21       , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21   , 100000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_21      , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_24     , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24       , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24   , 100000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_24      , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_27     , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27       , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27   , 100000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_27      , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_30     , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_30       , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30   , 100000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_30      , 100000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_30      , 100000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_THOTH04 // Giant Tengu
{
	Maxitem = 3;
	DropGold(11999, 12000);


	DropItem(II_ARM_M_KIN_HELMET_SET_09     , 750000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_09     , 750000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09       , 750000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09       , 750000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09   , 750000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09   , 750000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_09      , 750000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_09      , 750000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_12     , 750000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_12     , 750000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12       , 750000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12       , 750000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12   , 750000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12   , 750000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12      , 750000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12      , 750000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_15     , 750000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_15     , 750000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15       , 750000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15       , 750000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15   , 750000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15   , 750000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_15      , 750000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_15      , 750000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_18     , 750000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_18     , 750000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18       , 750000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18       , 750000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18   , 750000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18   , 750000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_18      , 750000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_18      , 750000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_21     , 750000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_21     , 750000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21       , 750000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21       , 750000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21   , 750000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21   , 750000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_21      , 750000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_21      , 750000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_24     , 750000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_24     , 750000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24       , 750000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24       , 750000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24   , 750000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24   , 750000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_24      , 750000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_24      , 750000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_27     , 750000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_27     , 750000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27       , 750000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27       , 750000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27   , 750000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27   , 750000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_27      , 750000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_27      , 750000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_30     , 750000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_30     , 750000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_30       , 750000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_30       , 750000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30   , 750000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30   , 750000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_30      , 750000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_30      , 750000, 0, 1);
		DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 10);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_THOTH04_1
{
	Maxitem = 2;
	DropGold(672, 974);

	DropKind(IK3_SWD, 90, 101);
	DropKind(IK3_AXE, 90, 101);
	DropKind(IK3_CHEERSTICK, 90, 101);
	DropKind(IK3_KNUCKLEHAMMER, 90, 101);
	DropKind(IK3_WAND, 90, 101);
	DropKind(IK3_STAFF, 90, 101);
	DropKind(IK3_HELMET, 90, 101);
	DropKind(IK3_SUIT, 90, 101);
	DropKind(IK3_GAUNTLET, 90, 101);
	DropKind(IK3_BOOTS, 90, 101);
	DropKind(IK3_SHIELD, 90, 101);
	DropKind(IK3_BOW, 90, 101);
	DropKind(IK3_YOYO, 90, 101);
	DropKind(IK3_THSWD, 90, 101);
	DropKind(IK3_THAXE, 90, 101);
	
	DropItem(II_GEN_GEM_GEM_THOTHBEAK, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KHNEMU01
{
	Maxitem = 1;
	DropGold(129, 130);
	
	DropItem(II_GEN_GEM_GEM_KHNEMUCORNU, 25000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KHNEMU02
{
	Maxitem = 1;
	DropGold(129, 130);
	
	DropItem(II_GEN_GEM_GEM_KHNEMUCORNU, 25000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KHNEMU03
{
	Maxitem = 1;
	DropGold(129, 130);

	DropItem(II_GEN_GEM_GEM_KHNEMUCORNU, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_KHNEMU04 // Giant Asterius
{
	Maxitem = 3;
	DropGold(12999, 13000);



	DropItem(II_ARM_M_KIN_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_KIN_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_KIN_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_KIN_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_BLA_HELMET_SET_13	,  500000,0,1);
	DropItem(II_ARM_M_BLA_SUIT_SET_13	,  500000,0,1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 500000,0,1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_13	,  500000,0,1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13	,  500000,0,1);
	DropItem(II_ARM_F_BLA_SUIT_SET_13	,  500000,0,1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 500000,0,1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_13	,  500000,0,1);
	DropItem(II_ARM_M_BLA_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_BLA_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_BLA_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_BLA_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_JST_HELMET_SET_16	,  500000,0,1);
	DropItem(II_ARM_M_JST_SUIT_SET_16	,  500000,0,1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 500000,0,1);
	DropItem(II_ARM_M_JST_BOOTS_SET_16	,  500000,0,1);
	DropItem(II_ARM_F_JST_HELMET_SET_16	,  500000,0,1);
	DropItem(II_ARM_F_JST_SUIT_SET_16	,  500000,0,1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 500000,0,1);
	DropItem(II_ARM_F_JST_BOOTS_SET_16	,  500000,0,1);
	DropItem(II_ARM_M_JST_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_JST_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_JST_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_JST_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_JST_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_JST_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_RAG_HELMET_SET_19	,  500000,0,1);
	DropItem(II_ARM_M_RAG_SUIT_SET_19	,  500000,0,1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 500000,0,1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_19	,  500000,0,1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19	,  500000,0,1);
	DropItem(II_ARM_F_RAG_SUIT_SET_19	,  500000,0,1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 500000,0,1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_19	,  500000,0,1);
	DropItem(II_ARM_M_RAG_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_RAG_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_RAG_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_RAG_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_RIN_HELMET_SET_22	,  500000,0,1);
	DropItem(II_ARM_M_RIN_SUIT_SET_22	,  500000,0,1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 500000,0,1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_22	,  500000,0,1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22	,  500000,0,1);
	DropItem(II_ARM_F_RIN_SUIT_SET_22	,  500000,0,1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 500000,0,1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_22	,  500000,0,1);
	DropItem(II_ARM_M_RIN_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_RIN_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_RIN_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_RIN_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_BIL_HELMET_SET_25	,  500000,0,1);
	DropItem(II_ARM_M_BIL_SUIT_SET_25	,  500000,0,1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 500000,0,1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_25	,  500000,0,1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25	,  500000,0,1);
	DropItem(II_ARM_F_BIL_SUIT_SET_25	,  500000,0,1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 500000,0,1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_25	,  500000,0,1);
	DropItem(II_ARM_M_BIL_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_BIL_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_BIL_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_BIL_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_PSY_HELMET_SET_28	,  500000,0,1);
	DropItem(II_ARM_M_PSY_SUIT_SET_28	,  500000,0,1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 500000,0,1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_28	,  500000,0,1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28	,  500000,0,1);
	DropItem(II_ARM_F_PSY_SUIT_SET_28	,  500000,0,1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 500000,0,1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_28	,  500000,0,1);
	DropItem(II_ARM_M_PSY_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_PSY_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_PSY_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_PSY_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_ELE_HELMET_SET_31	,  500000,0,1);
	DropItem(II_ARM_M_ELE_SUIT_SET_31	,  500000,0,1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 500000,0,1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_31	,  500000,0,1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31	,  500000,0,1);
	DropItem(II_ARM_F_ELE_SUIT_SET_31	,  500000,0,1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 500000,0,1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_31	,  500000,0,1);
	DropItem(II_ARM_M_ELE_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_ELE_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_ELE_HELMET_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_ELE_SUIT_SET_32	,  500000,0,1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_32,    500000,0,1);
	DropItem(II_CHP_FARMCHIP, 150000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 10);
	
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KHNEMU04_1
{
	Maxitem = 2;
	DropGold(694, 1006);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);		
	DropItem(II_GEN_GEM_GEM_KHNEMUCORNU, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DANTALIAN01
{
	Maxitem = 1;
	DropGold(138, 139);
	
	DropItem(II_GEN_GEM_GEM_DATALBALL, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DANTALIAN02
{
	Maxitem = 1;
	DropGold(138, 139);
	
	DropItem(II_GEN_GEM_GEM_DATALBALL, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DANTALIAN03
{
	Maxitem = 1;
	DropGold(138, 139);
	
	DropItem(II_GEN_GEM_GEM_DATALBALL, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_DANTALIAN04 // Giant Dantalian
{
	Maxitem = 3;
	DropGold(13999, 14000);

	DropItem(II_ARM_M_KIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_KIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_HELMET_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_SUIT_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 500000,0,1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_SUIT_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 500000,0,1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_HELMET_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_SUIT_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 500000,0,1);
	DropItem(II_ARM_M_JST_BOOTS_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_HELMET_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_SUIT_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 500000,0,1);
	DropItem(II_ARM_F_JST_BOOTS_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_JST_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_JST_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_HELMET_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_SUIT_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 500000,0,1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_SUIT_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 500000,0,1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_HELMET_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_SUIT_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 500000,0,1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_SUIT_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 500000,0,1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_BIL_HELMET_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_SUIT_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 500000,0,1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_SUIT_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 500000,0,1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BIL_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_32, 	  500000,0,1);
	DropItem(II_ARM_M_PSY_HELMET_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_SUIT_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 500000,0,1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_SUIT_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 500000,0,1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_PSY_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_ELE_HELMET_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_SUIT_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 500000,0,1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_SUIT_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 500000,0,1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_ELE_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_32,    500000,0,1);
	DropItem(II_CHP_FARMCHIP, 150000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);


	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DANTALIAN04_1
{
	Maxitem = 2;
	DropGold(700, 1100);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);	
	DropItem(II_GEN_GEM_GEM_DATALBALL, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GANESA01
{
	Maxitem = 1;
	DropGold(144, 145);

	DropItem(II_GEN_GEM_GEM_GANESALVORY, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GANESA02
{
	Maxitem = 1;
	DropGold(144, 145);

	DropItem(II_GEN_GEM_GEM_GANESALVORY, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GANESA03
{
	Maxitem = 1;
	DropGold(144, 145);
	
	DropItem(II_GEN_GEM_GEM_GANESALVORY, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_GANESA04 // Giant Gannessa
{
	Maxitem = 3;
	DropGold(14999, 15000);

	DropItem(II_ARM_M_KIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_KIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_HELMET_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_SUIT_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 500000,0,1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_SUIT_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 500000,0,1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_HELMET_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_SUIT_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 500000,0,1);
	DropItem(II_ARM_M_JST_BOOTS_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_HELMET_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_SUIT_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 500000,0,1);
	DropItem(II_ARM_F_JST_BOOTS_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_JST_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_JST_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_HELMET_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_SUIT_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 500000,0,1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_SUIT_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 500000,0,1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_HELMET_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_SUIT_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 500000,0,1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_SUIT_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 500000,0,1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_BIL_HELMET_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_SUIT_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 500000,0,1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_SUIT_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 500000,0,1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BIL_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_PSY_HELMET_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_SUIT_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 500000,0,1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_SUIT_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 500000,0,1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_PSY_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_ELE_HELMET_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_SUIT_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 500000,0,1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_SUIT_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 500000,0,1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_ELE_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_32,    500000,0,1);
	DropItem(II_CHP_FARMCHIP, 150000000, 0, 50);
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);	
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_GANESA04_1
{
	Maxitem = 3;
	DropGold(700, 1100);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
	DropItem(II_GEN_GEM_GEM_GANESALVORY, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ASURA01
{
	Maxitem = 1;
	DropGold(150, 151);
	

	DropItem(II_GEN_GEM_GEM_ASURAHEART, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ASURA02
{
	Maxitem = 1;
	DropGold(150, 151);
	
	DropItem(II_GEN_GEM_GEM_ASURAHEART, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ASURA03
{
	Maxitem = 1;
	DropGold(150, 151);
	
	DropItem(II_GEN_GEM_GEM_ASURAHEART, 15000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 250000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_ASURA04 // Giant Asuras
{
	Maxitem = 3;
	DropGold(39999, 40000);
	
	DropItem(II_GEN_GEM_CRAFTMATERIAL015, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL062, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL042, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL024, 15000000, 0, 2);

	DropItem(II_ARM_M_KIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_KIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_HELMET_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_SUIT_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 500000,0,1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_SUIT_SET_13	, 500000,0,1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 500000,0,1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_13	, 500000,0,1);
	DropItem(II_ARM_M_BLA_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_HELMET_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_SUIT_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 500000,0,1);
	DropItem(II_ARM_M_JST_BOOTS_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_HELMET_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_SUIT_SET_16	, 500000,0,1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 500000,0,1);
	DropItem(II_ARM_F_JST_BOOTS_SET_16	, 500000,0,1);
	DropItem(II_ARM_M_JST_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_JST_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_JST_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_HELMET_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_SUIT_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 500000,0,1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_SUIT_SET_19	, 500000,0,1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 500000,0,1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_19	, 500000,0,1);
	DropItem(II_ARM_M_RAG_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_HELMET_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_SUIT_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 500000,0,1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_SUIT_SET_22	, 500000,0,1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 500000,0,1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_22	, 500000,0,1);
	DropItem(II_ARM_M_RIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_BIL_HELMET_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_SUIT_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 500000,0,1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_SUIT_SET_25	, 500000,0,1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 500000,0,1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_25	, 500000,0,1);
	DropItem(II_ARM_M_BIL_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BIL_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_PSY_HELMET_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_SUIT_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 500000,0,1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_SUIT_SET_28	, 500000,0,1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 500000,0,1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_28	, 500000,0,1);
	DropItem(II_ARM_M_PSY_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_PSY_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_32,    500000,0,1);
	DropItem(II_ARM_M_ELE_HELMET_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_SUIT_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 500000,0,1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_SUIT_SET_31	, 500000,0,1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 500000,0,1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_31	, 500000,0,1);
	DropItem(II_ARM_M_ELE_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_ELE_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_HELMET_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_SUIT_SET_32	, 500000,0,1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_32, 500000,0,1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_32, 500000,0,1);	
	DropItem(II_CHP_FARMCHIP, 150000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ASURA04_1 
{
	Maxitem = 3;
	DropGold(700, 1100);

	DropItem(II_GEN_GEM_GEM_ASURAHEART, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_IMP01
{
	Maxitem = 2;
        DropGold(1, 2);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 6  
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_IMP02
{
	Maxitem = 2;
        DropGold(1, 2);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 6  
			Summon	40	2	MI_IMP01
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_IMP03
{
	Maxitem = 2;
        DropGold(1, 2);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 6  
			Summon	30	2	MI_IMP02
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_LUCIFER01
{
	Maxitem = 10;
        DropGold(20000, 30000);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
                        Berserk 10 1.5 
			Summon	20	2	MI_IMP03
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_RANGDA01 // Rangda
{
	Maxitem = 10;
	DropGold(19999, 20000);
	

	DropItem(II_GEN_MAT_TOPAZ, 30000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 30000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 30000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 30000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 30000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL364, 35000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);		
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			recovery 10 50 100 m  
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_RANGDA02 // Horrible Rangda
{
	Maxitem = 10;
	DropGold(19999, 22000);
	
	DropItem(II_GEN_MAT_TOPAZ, 30000000, 0, 2);
	DropItem(II_GEN_MAT_RUBY, 30000000, 0, 2);
	DropItem(II_GEN_MAT_SAPPHIRE, 30000000, 0, 2);
	DropItem(II_GEN_MAT_EMERALD, 30000000, 0, 2);
	DropItem(II_GEN_MAT_DIAMOND, 30000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL364, 40000000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			recovery 10 50 100 m  
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_RANGDA05 // Event Rangda
{
	Maxitem = 44;
	DropGold(100, 200);
	
	DropItem(II_SYS_SYS_SCR_BXSUHO01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXUSU01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXSUHO01, 3000000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXUSU01, 3000000000, 0, 1);

	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);	
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 3000000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 3000000000, 0, 1);

	II_SYS_SYS_SCR_BXSUHO01
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			recovery 10 50 100 m  
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_RANGDA03 // Uncanny Rangda
{
	Maxitem = 10;
	DropGold(19999, 25000);
	
	DropItem(II_GEN_MAT_TOPAZ, 30000000, 0, 3);
	DropItem(II_GEN_MAT_RUBY, 30000000, 0, 3);
	DropItem(II_GEN_MAT_SAPPHIRE, 30000000, 0, 3);
	DropItem(II_GEN_MAT_EMERALD, 30000000, 0, 3);
	DropItem(II_GEN_MAT_DIAMOND, 30000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL364, 45000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			recovery 10 50 100 m  
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_RANGDA04 // Dreadful Rangda
{
	Maxitem = 10;
	DropGold(19999, 28000);
	

	DropItem(II_GEN_MAT_TOPAZ, 30000000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL364, 50000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 30000000, 0, 5);
	DropItem(II_GEN_MAT_SAPPHIRE, 30000000, 0, 5);
	DropItem(II_GEN_MAT_EMERALD, 30000000, 0, 5);
	DropItem(II_GEN_MAT_DIAMOND, 30000000, 0, 3);
	DropItem(II_CHP_FARMCHIP, 15000000, 0, 50);	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			recovery 10 50 100 m  
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KINGSTER01
{
	Maxitem = 3;
	DropGold(55, 60);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GIANTFORCEPS, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KINGSTER02
{
	Maxitem = 3;
	DropGold(55, 60);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GIANTFORCEPS, 100000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KINGSTER03
{
	Maxitem = 3;
	DropGold(55, 60);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GIANTFORCEPS, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KRAKEN01
{
	Maxitem = 3;
	DropGold(56, 61);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_INKSAC, 100000000, 0, 1);


	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KRAKEN02
{
	Maxitem = 3;
	DropGold(56, 61);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_INKSAC, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_KRAKEN03
{
	Maxitem = 3;
	DropGold(56, 61);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_INKSAC, 100000000, 0, 1);


	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CREPER01
{
	Maxitem = 3;
	DropGold(57, 62);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CARAPACE, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CREPER02
{
	Maxitem = 3;
	DropGold(57, 62);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CARAPACE, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_CREPER03
{
	Maxitem = 3;
	DropGold(57, 62);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CARAPACE, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_NAGA01
{
	Maxitem = 3;
	DropGold(58, 63);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CRISPHAIR, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_NAGA02
{
	Maxitem = 3;
	DropGold(58, 63);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CRISPHAIR, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_NAGA03
{
	Maxitem = 3;
	DropGold(58, 63);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CRISPHAIR, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ATROX01
{
	Maxitem = 3;
	DropGold(59, 64);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BROKENWINGS, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ATROX02
{
	Maxitem = 3;
	DropGold(59, 64);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BROKENWINGS, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_ATROX03
{
	Maxitem = 3;
	DropGold(59, 64);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BROKENWINGS, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_OKEAN01
{
	Maxitem = 3;
	DropGold(60, 65);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CROWN, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_OKEAN02
{
	Maxitem = 3;
	DropGold(60, 65);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CROWN, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_OKEAN03
{
	Maxitem = 3;
	DropGold(60, 65);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CROWN, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_TAIGA01
{
	Maxitem = 3;
	DropGold(61, 66);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CANINETOOTH, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_TAIGA02
{
	Maxitem = 3;
	DropGold(61, 66);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CANINETOOTH, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_TAIGA03
{
	Maxitem = 3;
	DropGold(61, 66);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CANINETOOTH, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DORIAN01
{
	Maxitem = 3;
	DropGold(62, 67);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_SHARPTOOTH, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DORIAN02
{
	Maxitem = 3;
	DropGold(62, 67);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_SHARPTOOTH, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_DORIAN03
{
	Maxitem = 3;
	DropGold(62, 67);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_SHARPTOOTH, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MEREL01
{
	Maxitem = 3;
	DropGold(79, 80);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GOGGLOO, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MEREL02
{
	Maxitem = 3;
	DropGold(70, 71);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GOGGLOO, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_MEREL03
{
	Maxitem = 3;
	DropGold(70, 71);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GOGGLOO, 100000000, 0, 1);



	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_Crohell01
{
	Maxitem = 2;
        DropGold(159, 160);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_DOGTOOTH, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL127, 150000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Crohell02
{
	Maxitem = 2;
        DropGold(159, 160);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_DOGTOOTH, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL127, 150000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Crohell03
{
	Maxitem = 2;
        DropGold(159, 160);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_DOGTOOTH, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL127, 150000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Crohell04
{
	Maxitem = 2;
	DropGold(27499, 27500);
	DropItem(II_WEA_SWO_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 900000, 0, 1);


	//Knight
	DropItem(II_ARM_M_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_M_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_M_KIN_BOOTS_SET_10, 770123, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_F_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_F_KIN_BOOTS_SET_10, 770123, 0, 1);
	
	//Blade
	DropItem(II_ARM_M_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_M_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 770123, 0, 1);          
	DropItem(II_ARM_M_BLA_BOOTS_SET_13, 770123, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_F_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 770123, 0, 1);         
	DropItem(II_ARM_F_BLA_BOOTS_SET_13, 770123, 0, 1);
	
	//Jester
	DropItem(II_ARM_M_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_M_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_M_JST_BOOTS_SET_16, 770123, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_F_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_F_JST_BOOTS_SET_16, 770123, 0, 1);
	
	//Ranger
	DropItem(II_ARM_M_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_M_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_M_RAG_BOOTS_SET_19, 770123, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_F_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_F_RAG_BOOTS_SET_19, 770123, 0, 1);
	
	//Ringmaster
	DropItem(II_ARM_M_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_M_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_M_RIN_BOOTS_SET_22, 770123, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_F_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_F_RIN_BOOTS_SET_22, 770123, 0, 1);
		
	//Billposter
	DropItem(II_ARM_M_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_M_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_M_BIL_BOOTS_SET_25, 770123, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_F_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_F_BIL_BOOTS_SET_25, 770123, 0, 1);
	
	//Psykeper
	DropItem(II_ARM_M_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_M_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_M_PSY_BOOTS_SET_28, 770123, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_F_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_F_PSY_BOOTS_SET_28, 770123, 0, 1);
	
	//Elementor
	DropItem(II_ARM_M_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_M_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_M_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_F_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_F_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 75);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL127, 15000000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL027, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL036, 25000000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Frinker01
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_FLOWER, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Frinker02
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_FLOWER, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Frinker03
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_FLOWER, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Frinker04
{
	Maxitem = 2;
	DropGold(27499, 27500);

	DropItem(II_WEA_SWO_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 900000, 0, 1);
	

	//Knight
	DropItem(II_ARM_M_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_M_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_M_KIN_BOOTS_SET_10, 770123, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_F_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_F_KIN_BOOTS_SET_10, 770123, 0, 1);
	
	//Blade
	DropItem(II_ARM_M_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_M_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 770123, 0, 1);          
	DropItem(II_ARM_M_BLA_BOOTS_SET_13, 770123, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_F_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 770123, 0, 1);         
	DropItem(II_ARM_F_BLA_BOOTS_SET_13, 770123, 0, 1);
	
	//Jester
	DropItem(II_ARM_M_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_M_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_M_JST_BOOTS_SET_16, 770123, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_F_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_F_JST_BOOTS_SET_16, 770123, 0, 1);
	
	//Ranger
	DropItem(II_ARM_M_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_M_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_M_RAG_BOOTS_SET_19, 770123, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_F_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_F_RAG_BOOTS_SET_19, 770123, 0, 1);
	
	//Ringmaster
	DropItem(II_ARM_M_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_M_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_M_RIN_BOOTS_SET_22, 770123, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_F_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_F_RIN_BOOTS_SET_22, 770123, 0, 1);
		
	//Billposter
	DropItem(II_ARM_M_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_M_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_M_BIL_BOOTS_SET_25, 770123, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_F_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_F_BIL_BOOTS_SET_25, 770123, 0, 1);
	
	//Psykeper
	DropItem(II_ARM_M_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_M_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_M_PSY_BOOTS_SET_28, 770123, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_F_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_F_PSY_BOOTS_SET_28, 770123, 0, 1);
	
	//Elementor
	DropItem(II_ARM_M_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_M_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_M_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_F_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_F_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 75);
    DropItem(II_GEN_GEM_CRAFTMATERIAL036, 25000000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Toadrin01
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_POISONBAG, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Toadrin02
{
	Maxitem = 2;
	DropGold(100, 145);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_POISONBAG, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Toadrin03
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_POISONBAG, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Toadrin04
{
	Maxitem = 2;
	DropGold(26999, 27000);


	DropItem(II_WEA_SWO_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 900000, 0, 1);


	//Knight
	DropItem(II_ARM_M_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_M_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_M_KIN_BOOTS_SET_10, 770123, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_F_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_F_KIN_BOOTS_SET_10, 770123, 0, 1);
	
	//Blade
	DropItem(II_ARM_M_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_M_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 770123, 0, 1);          
	DropItem(II_ARM_M_BLA_BOOTS_SET_13, 770123, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_F_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 770123, 0, 1);         
	DropItem(II_ARM_F_BLA_BOOTS_SET_13, 770123, 0, 1);
	
	//Jester
	DropItem(II_ARM_M_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_M_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_M_JST_BOOTS_SET_16, 770123, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_F_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_F_JST_BOOTS_SET_16, 770123, 0, 1);
	
	//Ranger
	DropItem(II_ARM_M_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_M_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_M_RAG_BOOTS_SET_19, 770123, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_F_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_F_RAG_BOOTS_SET_19, 770123, 0, 1);
	
	//Ringmaster
	DropItem(II_ARM_M_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_M_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_M_RIN_BOOTS_SET_22, 770123, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_F_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_F_RIN_BOOTS_SET_22, 770123, 0, 1);
		
	//Billposter
	DropItem(II_ARM_M_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_M_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_M_BIL_BOOTS_SET_25, 770123, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_F_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_F_BIL_BOOTS_SET_25, 770123, 0, 1);
	
	//Psykeper
	DropItem(II_ARM_M_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_M_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_M_PSY_BOOTS_SET_28, 770123, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_F_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_F_PSY_BOOTS_SET_28, 770123, 0, 1);
	
	//Elementor
	DropItem(II_ARM_M_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_M_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_M_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_F_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_F_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 75);	
    DropItem(II_GEN_GEM_CRAFTMATERIAL036, 25000000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Hatsalra01
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_NECKLACE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Hatsalra02
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_NECKLACE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Hatsalra03
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_NECKLACE, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_Hatsalra04
{
	Maxitem = 2;
	DropGold(26999, 27000);


	DropItem(II_WEA_SWO_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 900000, 0, 1);


	//Knight
	DropItem(II_ARM_M_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_M_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_M_KIN_BOOTS_SET_10, 770123, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_F_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_F_KIN_BOOTS_SET_10, 770123, 0, 1);
	
	//Blade
	DropItem(II_ARM_M_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_M_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 770123, 0, 1);          
	DropItem(II_ARM_M_BLA_BOOTS_SET_13, 770123, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_F_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 770123, 0, 1);         
	DropItem(II_ARM_F_BLA_BOOTS_SET_13, 770123, 0, 1);
	
	//Jester
	DropItem(II_ARM_M_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_M_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_M_JST_BOOTS_SET_16, 770123, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_F_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_F_JST_BOOTS_SET_16, 770123, 0, 1);
	
	//Ranger
	DropItem(II_ARM_M_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_M_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_M_RAG_BOOTS_SET_19, 770123, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_F_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_F_RAG_BOOTS_SET_19, 770123, 0, 1);
	
	//Ringmaster
	DropItem(II_ARM_M_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_M_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_M_RIN_BOOTS_SET_22, 770123, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_F_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_F_RIN_BOOTS_SET_22, 770123, 0, 1);
		
	//Billposter
	DropItem(II_ARM_M_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_M_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_M_BIL_BOOTS_SET_25, 770123, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_F_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_F_BIL_BOOTS_SET_25, 770123, 0, 1);
	
	//Psykeper
	DropItem(II_ARM_M_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_M_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_M_PSY_BOOTS_SET_28, 770123, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_F_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_F_PSY_BOOTS_SET_28, 770123, 0, 1);
	
	//Elementor
	DropItem(II_ARM_M_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_M_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_M_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_F_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_F_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 75);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL036, 25000000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_Berken01
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BLAD, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Berken02
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BLAD, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Berken03
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BLAD, 200000000, 0, 1);
    

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_Berken04
{
	Maxitem = 2;
	DropGold(26999, 27000);

	
	DropItem(II_WEA_SWO_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 900000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 900000, 0, 1);


	//Knight
	DropItem(II_ARM_M_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_M_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_M_KIN_BOOTS_SET_10, 770123, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_10, 770123, 0, 1);     
	DropItem(II_ARM_F_KIN_SUIT_SET_10, 770123, 0, 1);			   
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_10, 770123, 0, 1);          
	DropItem(II_ARM_F_KIN_BOOTS_SET_10, 770123, 0, 1);
	
	//Blade
	DropItem(II_ARM_M_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_M_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_13, 770123, 0, 1);          
	DropItem(II_ARM_M_BLA_BOOTS_SET_13, 770123, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_13, 770123, 0, 1);     
	DropItem(II_ARM_F_BLA_SUIT_SET_13, 770123, 0, 1);			   
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_13, 770123, 0, 1);         
	DropItem(II_ARM_F_BLA_BOOTS_SET_13, 770123, 0, 1);
	
	//Jester
	DropItem(II_ARM_M_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_M_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_M_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_M_JST_BOOTS_SET_16, 770123, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_16, 770123, 0, 1);     
	DropItem(II_ARM_F_JST_SUIT_SET_16, 770123, 0, 1);			   
	DropItem(II_ARM_F_JST_GAUNTLET_SET_16, 770123, 0, 1);          
	DropItem(II_ARM_F_JST_BOOTS_SET_16, 770123, 0, 1);
	
	//Ranger
	DropItem(II_ARM_M_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_M_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_M_RAG_BOOTS_SET_19, 770123, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_19, 770123, 0, 1);     
	DropItem(II_ARM_F_RAG_SUIT_SET_19, 770123, 0, 1);			   
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_19, 770123, 0, 1);          
	DropItem(II_ARM_F_RAG_BOOTS_SET_19, 770123, 0, 1);
	
	//Ringmaster
	DropItem(II_ARM_M_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_M_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_M_RIN_BOOTS_SET_22, 770123, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_22, 770123, 0, 1);     
	DropItem(II_ARM_F_RIN_SUIT_SET_22, 770123, 0, 1);			   
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_22, 770123, 0, 1);          
	DropItem(II_ARM_F_RIN_BOOTS_SET_22, 770123, 0, 1);	

	//Billposter
	DropItem(II_ARM_M_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_M_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_M_BIL_BOOTS_SET_25, 770123, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_25, 770123, 0, 1);     
	DropItem(II_ARM_F_BIL_SUIT_SET_25, 770123, 0, 1);			   
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_25, 770123, 0, 1);          
	DropItem(II_ARM_F_BIL_BOOTS_SET_25, 770123, 0, 1);
	
	//Psykeper
	DropItem(II_ARM_M_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_M_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_M_PSY_BOOTS_SET_28, 770123, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_28, 770123, 0, 1);     
	DropItem(II_ARM_F_PSY_SUIT_SET_28, 770123, 0, 1);			   
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_28, 770123, 0, 1);          
	DropItem(II_ARM_F_PSY_BOOTS_SET_28, 770123, 0, 1);
	
	//Elementor
	DropItem(II_ARM_M_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_M_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_M_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_31, 770123, 0, 1);     
	DropItem(II_ARM_F_ELE_SUIT_SET_31, 770123, 0, 1);			   
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_31, 770123, 0, 1);          
	DropItem(II_ARM_F_ELE_BOOTS_SET_31, 770123, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 75);	
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_PRICKANT01
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	
	DropItem(II_GEN_GEM_GEM_ANTEGG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_PRICKANT02
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_ANTEGG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_PRICKANT03
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_ANTEGG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_PRICKANT04
{
	Maxitem = 4;
	DropGold(14999, 15000);

	DropItem(II_WEA_SWO_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 4500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 50);	
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

    DropItem(II_GEN_GEM_CRAFTMATERIAL027, 15000000, 0, 1);
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_CRIPESCENTIPEDE01
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_OILLEG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CRIPESCENTIPEDE02
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_OILLEG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CRIPESCENTIPEDE03
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_OILLEG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CRIPESCENTIPEDE04
{
	Maxitem = 4;
	DropGold(14999, 15000);

	DropItem(II_WEA_SWO_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 4500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 50);	
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

    DropItem(II_GEN_GEM_CRAFTMATERIAL027, 15000000, 0, 1);

	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_MAULMOUSE01
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_NICECHEESE, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_MAULMOUSE02
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_NICECHEESE, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_MAULMOUSE03
{
	Maxitem = 2;
        DropGold(99, 100);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_NICECHEESE, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_MAULMOUSE04
{
	Maxitem = 4;
	DropGold(14999, 15000);

	DropItem(II_WEA_SWO_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 4500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 50);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL027, 15000000, 0, 1);	
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_LYCANOS01
{
	Maxitem = 4;
	DropGold(19999, 20000);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BIGTOENAIL, 210000000, 0, 1);
	DropItem(II_GEN_GEM_GEM_BIGTOENAIL, 210000000, 0, 1);
	DropItem(II_GEN_GEM_GEM_BIGTOENAIL, 210000000, 0, 1);

	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX01, 300000000, 0, 5);
	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX02, 300000000, 0, 5);
	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX03, 300000000, 0, 5);

	DropItem(II_GEN_MAT_ELE_LIGHTING, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_VOLCANO, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_EARTHQUAKE, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_OCEAN, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_VACCUM, 15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_VEMPAIN01 // Darkul the Diabolic
{
	Maxitem = 3;
    DropGold(29999, 30000);

	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX01, 400000000, 0, 7);
	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX02, 400000000, 0, 7);
	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX03, 400000000, 0, 7);
	DropItem(II_GEN_MAT_ORICHALCUM02, 55000000, 0, 10);

	DropItem(II_GEN_JEW_RIN_STRRING, 5000000, 19, 1);
	DropItem(II_GEN_JEW_RIN_DEXRING, 5000000, 19, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 5000000, 19, 1);
	DropItem(II_GEN_JEW_RIN_STARING, 5000000, 19, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 5000000, 19, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 5000000, 19, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACE, 5000000, 19, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACE, 5000000, 19, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACE, 5000000, 19, 1);

	DropItem(II_WEA_SWO_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_SWT_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_AXE_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_AXT_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_KNU_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_CHE_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_WAN_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_STA_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_BOW_VEMPIRE, 4500000, 0, 1);
	DropItem(II_WEA_YOY_VEMPIRE, 4500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTRECYCLE12, 35000000, 0, 1)
	
    DropItem(II_GEN_MAT_ELE_CANDLEA, 4000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_RAINATKA, 4000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_SPARKATKA, 4000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_BREEZEATKA, 4000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_SANDATKA, 4000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_PRICKANT01_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSEANTEGG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_PRICKANT02_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSEANTEGG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_PRICKANT03_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSEANTEGG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_PRICKANT04_1
{
	Maxitem = 1;
	DropGold(15999, 16000);

	DropItem(II_WEA_SWO_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 4500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 75);	

	DropItem(II_GEN_GEM_CRAFTMATERIAL027, 15000000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_CRIPESCENTIPEDE01_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSEOILLEG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CRIPESCENTIPEDE02_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
	DropItem(II_GEN_GEM_GEM_CURSEOILLEG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CRIPESCENTIPEDE03_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSEOILLEG, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CRIPESCENTIPEDE04_1
{
	Maxitem = 1;
	DropGold(15999, 16000);

	DropItem(II_WEA_SWO_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 4500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 75);	
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);


	DropItem(II_GEN_GEM_CRAFTMATERIAL027, 15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_MAULMOUSE01_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSENICECHEESE, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_MAULMOUSE02_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSENICECHEESE, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_MAULMOUSE03_1
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSENICECHEESE, 200000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_MAULMOUSE04_1
{
	Maxitem = 1;
	DropGold(15999, 16000);

	DropItem(II_WEA_SWO_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_KNU_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG, 4500000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG, 4500000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 75);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL027, 15000000, 0, 2);	
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);



	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}


MI_LYCANOS01_1
{
	Maxitem = 6;
	DropGold(19999, 20000);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_CURSEBIGTOENAIL, 210000000, 0, 1);
	DropItem(II_GEN_GEM_GEM_CURSEBIGTOENAIL, 210000000, 0, 1);
	DropItem(II_GEN_GEM_GEM_CURSEBIGTOENAIL, 210000000, 0, 1);

	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX01, 450000000, 0, 5);
	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX02, 450000000, 0, 5);
	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX03, 450000000, 0, 5);

	DropItem(II_GEN_MAT_ELE_LIGHTING, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_VOLCANO, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_EARTHQUAKE, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_OCEAN, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_VACCUM, 15000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_VEMPAIN01_1 // Dread Darkul the Diabolic
{
	Maxitem = 3;	
    DropGold(34999, 35000);

	DropItem(II_GEN_MAT_ORICHALCUM02, 55000000, 0, 8);

	DropItem(II_GEN_JEW_RIN_STRRING, 5000000, 20, 1);
	DropItem(II_GEN_JEW_RIN_DEXRING, 5000000, 20, 1);
	DropItem(II_GEN_JEW_RIN_INTRING, 5000000, 20, 1);
	DropItem(II_GEN_JEW_RIN_STARING, 5000000, 20, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 5000000, 20, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 5000000, 20, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACE, 5000000, 20, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACE, 5000000, 20, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACE, 5000000, 20, 1);

	DropItem(II_WEA_SWO_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_SWT_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_AXE_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_AXT_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_KNU_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_CHE_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_WAN_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_STA_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_BOW_ANCIENT, 4500000, 0, 1);
	DropItem(II_WEA_YOY_ANCIENT, 4500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTRECYCLE12, 50000000, 0, 1);

	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX01, 500000000, 0, 7);
	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX02, 500000000, 0, 7);
	DropItem(II_SYS_SYS_EVE_OMINOUSGIFTBOX03, 500000000, 0, 7);
	
    DropItem(II_GEN_MAT_ELE_CANDLEA, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_RAINATKA, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_SPARKATKA, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_BREEZEATKA, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_SANDATKA, 6000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_MOCOMOCHI1
{
	Maxitem = 8;	
	
	DropItem(II_SYS_SYS_SCR_BXSPECIALHOOD01, 157500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXSPECIALFUN01, 157500000, 0, 1);
	DropItem(II_CHR_MAG_TRI_ROCKETBOMB, 900000000, 0, 1);
	DropItem(II_GEN_MAG_TRI_HWFIREWORKS, 900000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

//15�� ����
MI_SKELWOLF
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_WOLFTOOTH, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL305, 20000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL119, 20000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELSWORD
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_SKELSKIN, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL305, 20000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL119, 20000, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELSPEAR
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_SKELPIECE, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL305, 20000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL119, 20000, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELMAGE
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_SKELSTAFFPIECE, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL305, 20000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL119, 20000, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			keeprangeattack 6
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELASSASSIN
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_SKELWEAPIECE, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL305, 20000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL119, 20000, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELFIGHTER
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_SKELTOOLBOX, 200000000, 0, 1);
		DropItem(II_GEN_GEM_CRAFTMATERIAL305, 20000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL119, 20000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELGENERAL // Razgul
{
	Maxitem = 3;
	DropGold(49999, 50000);	
	
	DropItem(II_ARM_ARM_SHI_BOKSOUL, 5000000, 0, 1);
	DropItem(II_ARM_ARM_SHI_SHESOUL, 5000000, 0, 1);	
	
	DropItem(II_GEN_GEM_CRAFTMATERIAL211, 30000000, 0, 1);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL295, 30000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL296, 30000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTRECYCLE12,   50000000, 0, 1);	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELGRIFFIN
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_GRIFFINFEATHER, 200000000, 0, 1);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL170, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL173, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL174, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL175, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL051, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL079, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL212, 50000, 0, 1);		

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELLEADER
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BACKBONELEADER, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL170, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL173, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL174, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL175, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL051, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL079, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL212, 50000, 0, 1);	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELSPAIN
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_BACKBONESPAIN, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL170, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL173, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL174, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL175, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL051, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL079, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL212, 50000, 0, 1);	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELSHAMEN
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_MAGICBOOK, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL170, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL173, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL174, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL175, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL051, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL079, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL212, 50000, 0, 1);	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 6
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELRIDER
{
	Maxitem = 2;
	DropGold(99, 143);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_GEN_GEM_GEM_DARKBEAD, 200000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL170, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL173, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL174, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL175, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL051, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL079, 50000, 0, 1);		
	DropItem(II_GEN_GEM_CRAFTMATERIAL212, 50000, 0, 1);		

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			rangeattack 6
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SKELDEVIL // Kheldor
{
	Maxitem = 3;
	DropGold(540000, 550000);

	DropItem(II_ARM_M_KIN_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_KIN_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_KIN_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_KIN_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_BLA_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_BLA_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_JST_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_JST_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_JST_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_JST_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_RAG_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_RAG_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_RAG_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_RIN_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_RIN_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_RIN_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_RIN_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_BIL_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_BIL_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_BIL_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_BIL_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_PSY_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_PSY_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_PSY_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_PSY_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_ELE_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_M_ELE_BOOTS_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_ELE_HELMET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_34 , 1250000, 0, 1);
	DropItem(II_ARM_F_ELE_BOOTS_SET_34 , 1250000, 0, 1);

	DropItem(II_GEN_GEM_GEM_DEVILPIECE , 7500000, 0, 1);
	DropItem(II_WEA_SWO_SWDSOUL , 2500000, 0, 1);
	DropItem(II_ARM_ARM_SHI_ZEMSOUL , 2500000, 0, 1);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_DREADSTONE01
{
	Maxitem = 1;
	DropGold(99, 143);

	DropItem(II_GEN_GEM_CRAFTMATERIAL246 , 20000000, 0, 1);
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
			Summon	20	2	MI_SKELGRIFFIN
                    }
		#move
		    {
		    }	
   	}               
}

MI_DREADSTONE02
{
	Maxitem = 1;
	DropGold(99, 143);

	DropItem(II_GEN_GEM_CRAFTMATERIAL246 , 20000000, 0, 1);

	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
			Summon	20	2	MI_SKELLEADER
                    }
		#move
		    {
		    }	
   	}               
}

MI_DREADSTONE03
{

	Maxitem = 1;
	DropGold(99, 143);

	DropItem(II_GEN_GEM_CRAFTMATERIAL246 , 20000000, 0, 1);	
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
			Summon	20	2	MI_SKELSPAIN
                    }
		#move
		    {
		    }	
   	}               
}

MI_DREADSTONE04
{

	Maxitem = 1;
	DropGold(99, 143);

	DropItem(II_GEN_GEM_CRAFTMATERIAL246 , 20000000, 0, 1);	
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
			Summon	20	2	MI_SKELSHAMEN
                    }
		#move
		    {
		    }	
   	}               
}

MI_DREADSTONE05
{
	Maxitem = 1;
	DropGold(99, 143);

	DropItem(II_GEN_GEM_CRAFTMATERIAL246 , 20000000, 0, 1);

	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
			Summon	20	2	MI_SKELRIDER
                    }
		#move
		    {
		    }	
   	}               
}

MI_DREADSTONE06
{
	Maxitem = 1;
	DropGold(99, 143);

	DropItem(II_GEN_GEM_CRAFTMATERIAL246 , 20000000, 0, 1);

	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
			Summon	20	2	MI_SKELRIDER
                    }
		#move
		    {
		    }	
   	}               
}

MI_RUSTIACRASHGATE01
{
	AI
	{
		#Scan
                    {
		    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			rangeattack 6
                    }
		#move
		    {
		    }	
   	}                
}

MI_RUSTIACRASHGATE02
{
	AI
	{
		#Scan
                    {
		    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			rangeattack 6
                    }
		#move
		    {
		    }	
   	}                
}

MI_RUSTIACRASHGATE03
{
	AI
	{
		#Scan
                    {
		    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			rangeattack 6
                    }
		#move
		    {
		    }	
   	}                
}

MI_RUSTIACRASHGATE04
{
	AI
	{
		#Scan
                    {
		    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			rangeattack 6
                    }
		#move
		    {
		    }	
   	}                
}





MI_BIGCOBRA01
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);

	DropItem(II_GEN_GEM_GEM_POISONTOOTH, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BIGVARIETYCOBRA01
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_COBRASCALE, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BIGRACCOON01
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_SOFTFUR, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BIGSOLDIERRACCOON01
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_TWOHANDBLADE, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_SOLDIERTANGZ01
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_BRACELET, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_SHAMANWUTANGKA01
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_LUSIKAMASK, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BESIBIGFOOT01 // Beast King Khan
{
	Maxitem = 3;

	//inteli Set
	DropItem(II_ARM_M_RIN_HELMET_SET_20_3	, 500000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_20_3	  	, 500000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20_3 , 500000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_20_3	, 500000, 0, 1);  	
	DropItem(II_ARM_F_RIN_HELMET_SET_20_3	, 500000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_20_3	    , 500000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20_3 , 500000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_20_3	, 500000, 0, 1);    
	DropItem(II_ARM_M_PSY_HELMET_SET_26_2	, 500000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_26_2	  	, 500000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26_2 , 500000, 0, 1); 
	DropItem(II_ARM_M_PSY_BOOTS_SET_26_2	, 500000, 0, 1);  	
	DropItem(II_ARM_F_PSY_HELMET_SET_26_2	, 500000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_26_2	  	, 500000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26_2 , 500000, 0, 1); 
	DropItem(II_ARM_F_PSY_BOOTS_SET_26_2	, 500000, 0, 1);  	
	DropItem(II_ARM_M_ELE_HELMET_SET_29_2	, 500000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_29_2	  	, 500000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29_2 , 500000, 0, 1); 
	DropItem(II_ARM_M_ELE_BOOTS_SET_29_2	, 500000, 0, 1); 	
	DropItem(II_ARM_F_ELE_HELMET_SET_29_2	, 500000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_29_2	  	, 500000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29_2 , 500000, 0, 1); 
	DropItem(II_ARM_F_ELE_BOOTS_SET_29_2	, 500000, 0, 1);  	

	//Vitra Set
	DropItem(II_ARM_M_BLA_HELMET_SET_11_2	, 500000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_11_2		, 500000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11_2	, 500000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_11_2	, 500000, 0, 1);	
	DropItem(II_ARM_F_BLA_HELMET_SET_11_2	, 500000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_11_2		, 500000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11_2	, 500000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_11_2	, 500000, 0, 1);	
	DropItem(II_ARM_M_KIN_HELMET_SET_08_2	, 500000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_08_2	 	, 500000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08_2 , 500000, 0, 1); 
	DropItem(II_ARM_M_KIN_BOOTS_SET_08_2	, 500000, 0, 1); 	
	DropItem(II_ARM_F_KIN_HELMET_SET_08_2	, 500000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_08_2	 	, 500000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08_2 , 500000, 0, 1); 
	DropItem(II_ARM_F_KIN_BOOTS_SET_08_2	, 500000, 0, 1); 	
	DropItem(II_ARM_M_RAG_HELMET_SET_17_2	, 500000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_17_2	  	, 500000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17_2 , 500000, 0, 1); 
	DropItem(II_ARM_M_RAG_BOOTS_SET_17_2  	, 500000, 0, 1);
	DropItem(II_ARM_F_RAG_HELMET_SET_17_2	, 500000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_17_2	  	, 500000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17_2 , 500000, 0, 1); 
	DropItem(II_ARM_F_RAG_BOOTS_SET_17_2	, 500000, 0, 1);  	
	DropItem(II_ARM_M_JST_HELMET_SET_14_2	, 500000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_14_2	  	, 500000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14_2 , 500000, 0, 1); 
	DropItem(II_ARM_M_JST_BOOTS_SET_14_2	, 500000, 0, 1);  	
	DropItem(II_ARM_F_JST_HELMET_SET_14_2	, 500000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_14_2	  	, 500000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14_2 , 500000, 0, 1); 
	DropItem(II_ARM_F_JST_BOOTS_SET_14_2	, 500000, 0, 1);  	
	DropItem(II_ARM_M_RIN_HELMET_SET_20_2	, 500000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_20_2	  	, 500000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20_2 , 500000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_20_2	, 500000, 0, 1);  	
	DropItem(II_ARM_F_RIN_HELMET_SET_20_2	, 500000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_20_2	    , 500000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20_2 , 500000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_20_2	, 500000, 0, 1);    
	DropItem(II_ARM_M_BIL_HELMET_SET_23_2   , 500000, 0, 1); 
	DropItem(II_ARM_M_BIL_SUIT_SET_23_2	  	, 500000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23_2 , 500000, 0, 1); 
	DropItem(II_ARM_M_BIL_BOOTS_SET_23_2	, 500000, 0, 1);  	
	DropItem(II_ARM_F_BIL_HELMET_SET_23_2   , 500000, 0, 1); 
	DropItem(II_ARM_F_BIL_SUIT_SET_23_2	  	, 500000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23_2 , 500000, 0, 1); 
	DropItem(II_ARM_F_BIL_BOOTS_SET_23_2	, 500000, 0, 1);  	
	DropItem(II_ARM_M_ELE_HELMET_SET_29_1	, 500000, 0, 1);
	DropItem(II_ARM_M_ELE_SUIT_SET_29_1	  	, 500000, 0, 1);
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_29_1 , 500000, 0, 1); 
	DropItem(II_ARM_M_ELE_BOOTS_SET_29_1	, 500000, 0, 1); 	
	DropItem(II_ARM_F_ELE_HELMET_SET_29_1	, 500000, 0, 1);
	DropItem(II_ARM_F_ELE_SUIT_SET_29_1	  	, 500000, 0, 1);
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_29_1 , 500000, 0, 1); 
	DropItem(II_ARM_F_ELE_BOOTS_SET_29_1	, 500000, 0, 1);  	
	DropItem(II_ARM_M_PSY_HELMET_SET_26_1	, 500000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_26_1	  	, 500000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_26_1 , 500000, 0, 1); 
	DropItem(II_ARM_M_PSY_BOOTS_SET_26_1	, 500000, 0, 1); 	
	DropItem(II_ARM_F_PSY_HELMET_SET_26_1	, 500000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_26_1	  	, 500000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_26_1 , 500000, 0, 1); 
	DropItem(II_ARM_F_PSY_BOOTS_SET_26_1	, 500000, 0, 1);


	DropItem(II_WEA_SWO_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_SWT_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_AXE_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_AXT_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_KNU_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_CHE_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_WAN_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_STA_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_BOW_LUZA, 1500000, 0, 1);
	DropItem(II_WEA_YOY_LUZA, 1500000, 0, 1);

	//Might Set
	DropItem(II_ARM_M_BLA_HELMET_SET_11_1	, 500000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_11_1		, 500000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_11_1	, 500000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_11_1	, 500000, 0, 1);	
	DropItem(II_ARM_F_BLA_HELMET_SET_11_1	, 500000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_11_1		, 500000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_11_1	, 500000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_11_1	, 500000, 0, 1);	
	DropItem(II_ARM_M_KIN_HELMET_SET_08_1	, 500000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_08_1	 	, 500000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_08_1 , 500000, 0, 1); 
	DropItem(II_ARM_M_KIN_BOOTS_SET_08_1	, 500000, 0, 1); 	
	DropItem(II_ARM_F_KIN_HELMET_SET_08_1	, 500000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_08_1	 	, 500000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_08_1 , 500000, 0, 1); 
	DropItem(II_ARM_F_KIN_BOOTS_SET_08_1	, 500000, 0, 1); 	
	DropItem(II_ARM_M_JST_HELMET_SET_14_1	, 500000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_14_1	  	, 500000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_14_1 , 500000, 0, 1); 
	DropItem(II_ARM_M_JST_BOOTS_SET_14_1	, 500000, 0, 1);  	
	DropItem(II_ARM_F_JST_HELMET_SET_14_1	, 500000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_14_1	  	, 500000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_14_1 , 500000, 0, 1); 
	DropItem(II_ARM_F_JST_BOOTS_SET_14_1	, 500000, 0, 1);  	
	DropItem(II_ARM_M_RIN_HELMET_SET_20_1	, 500000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_20_1	  	, 500000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_20_1 , 500000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_20_1	, 500000, 0, 1);  	
	DropItem(II_ARM_F_RIN_HELMET_SET_20_1	, 500000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_20_1	    , 500000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_20_1 , 500000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_20_1	, 500000, 0, 1);    
	DropItem(II_ARM_M_BIL_HELMET_SET_23_1   , 500000, 0, 1); 
	DropItem(II_ARM_M_BIL_SUIT_SET_23_1	  	, 500000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_23_1 , 500000, 0, 1); 
	DropItem(II_ARM_M_BIL_BOOTS_SET_23_1	, 500000, 0, 1);  	
	DropItem(II_ARM_F_BIL_HELMET_SET_23_1   , 500000, 0, 1); 
	DropItem(II_ARM_F_BIL_SUIT_SET_23_1	  	, 500000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_23_1 , 500000, 0, 1); 
	DropItem(II_ARM_F_BIL_BOOTS_SET_23_1	, 500000, 0, 1);  	
	DropItem(II_ARM_M_RAG_HELMET_SET_17_1	, 500000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_17_1	  	, 500000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_17_1 , 500000, 0, 1); 
	DropItem(II_ARM_M_RAG_BOOTS_SET_17_1	, 500000, 0, 1);  	
	DropItem(II_ARM_F_RAG_HELMET_SET_17_1	, 500000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_17_1	  	, 500000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_17_1 , 500000, 0, 1); 
	DropItem(II_ARM_F_RAG_BOOTS_SET_17_1	, 500000, 0, 1); 

	DropItem(II_GEN_GEM_GEM_BIGFOOTHEART, 4000000, 0, 2);	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
			
			KeepRangeattack 8	
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BIGCOBRA02
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_LIGHTPOISONTOOTH, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BIGVARIETYCOBRA02
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_LIGHTCOBRASCALE, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BIGRACCOON02
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_LIGHTSOFTFUR, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BIGSOLDIERRACCOON02
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_LIGHTTWOHANDBLADE, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_SOLDIERTANGZ02
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_LIGHTBRACELET, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_SHAMANWUTANGKA02
{
	Maxitem = 2;
	DropGold(82, 119);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	

	DropItem(II_GEN_GEM_GEM_LIGHTLUSIKAMASK, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_BESIBIGFOOT02 // Beast Overlord Khan
{
	Maxitem = 2;
	
	DropItem(II_WEA_SWO_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_SWT_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_AXE_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_AXT_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_KNU_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_CHE_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_WAN_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_STA_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_BOW_LUZAM, 1500000, 0, 1);
	DropItem(II_WEA_YOY_LUZAM, 1500000, 0, 1);
	DropItem(II_GEN_GEM_GEM_LIGHTBIGFOOTHEART, 3000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_FIRERING, 1500000, 0, 1);
	DropItem(II_GEN_JEW_RIN_LANDRING, 1500000, 0, 1);
	DropItem(II_GEN_JEW_RIN_WATERRING, 1500000, 0, 1);
	DropItem(II_GEN_JEW_RIN_ELECTRICRING, 1500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRINGEST, 1500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRINGEST, 1500000, 0, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACEMR, 1500000, 0, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACEMR, 1500000, 0, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACEMR, 1500000, 0, 1);
	DropItem(II_GEN_JEW_NEC_HPMPNECKLACE, 1500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_MAGICRINGEST, 1500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_RANGERINGEST, 1500000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
			
			KeepRangeattack 8	
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_RABBITGUARDER01
{
	Maxitem = 2;
    DropGold(130, 135);
	DropItem(II_GEN_GEM_GEM_TRASQI1, 200000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 10000000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_TUTTLESWORDER01
{
	Maxitem = 2;
    DropGold(135, 140);
	DropItem(II_GEN_GEM_GEM_TRASQI4, 200000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 10000000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_TUTTLEFIGHTER01
{
	Maxitem = 2;
    DropGold(140, 145);
	DropItem(II_GEN_GEM_GEM_TRASQI6, 200000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 10000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_TUTTLEASSASSIN01
{
	Maxitem = 2;
    DropGold(145, 150);
	DropItem(II_GEN_GEM_GEM_TRASQI5, 200000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 10000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_TUTTLESPEAR01
{
	Maxitem = 2;
    DropGold(150, 155);
	DropItem(II_GEN_GEM_GEM_TRASQI2, 200000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 10000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_TUTTLEAXE01
{
	Maxitem = 2;
    DropGold(135, 140);
	DropItem(II_GEN_GEM_GEM_TRASQI3, 200000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 10000000, 0, 1);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_TUTTLEKING01 // Guan Yu Heavyblade
{
	Maxitem = 3;
	DropGold(49999, 50000);

	DropItem(II_WEA_LC_TURTLEKING_SHIELD, 900000, 0, 1)
	
	DropItem(II_GEN_GEM_CRAFTMATERIAL086, 15000000, 0, 1)
	DropItem(II_GEN_GEM_CRAFTMATERIAL295, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL296, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL008, 10000000, 0, 1);
	DropItem(II_CHP_FARMCHIP, 10000000, 0, 60);	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}




//16�� ī�Ϸ� �ʿ�


MI_PUPPETWOLF
{
	Maxitem = 2;
	DropGold(145, 150);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_SKULLMASK01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_RYSENTRY
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_LEATHERCAPE01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_RYGUARD
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_LYCANCLAW01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_RYARCHER
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_BLOODANTIDOTE01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8    
			           
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_RYMAGI
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_MAGICSKULL01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8                                 			         
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_RYWARRIOR
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_DEVILHORN01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_RYBARGA // Chief Keokuk
{
	Maxitem = 3;
	DropGold(49999, 50000);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL069, 7500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL098, 7500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL295, 2500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL296, 2500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTRECYCLE12,   5000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL070, 7500000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}




MI_CLOCKWORKBUTLER01
{
	Maxitem = 3;	
	DropItem(II_GEN_FOO_INS_SUPERSTARCANDY,  10000000, 0, 7);
	DropItem(II_GEN_FOO_INS_PANCAKE, 		  9000000, 0, 6);
	DropItem(II_GEN_FOO_INS_DONUT,			  8000000, 0, 5);
	DropItem(II_GEN_FOO_INS_CAKE, 			  7000000, 0, 4);
	DropItem(II_GEN_FOO_INS_CUPCAKE, 		  6000000, 0, 3);
	DropItem(II_GEN_FOO_INS_FRUITCAKE,  	  5000000, 0, 2);
	DropItem(II_GEN_JEW_RIN_METEOR,  	 	  5500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING01, 	  5500000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING04, 	  5500000, 0, 1);	
	DropItem(II_GEN_JEW_EAR_U_EARRING07, 	  5500000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE01, 	  5500000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE04, 	  5500000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_U_NECKLACE07, 	  5500000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING01, 		  5500000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING04, 		  5500000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_U_RING07, 		  5500000, 0, 1);	     
	DropItem(II_GEN_JEW_RIN_METEOR, 		  5500000, 0, 1);	     

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_SPAINDRAGON01
{
	Maxitem = 1;	
	DropItem(II_GEN_JEW_EAR_ATTEARRING, 7500000, 9, 1);
	DropItem(II_GEN_JEW_RIN_STRRING, 7500000, 9, 1);
	DropItem(II_ARM_S_CLO_CLOCK01, 1500000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXBLUEWEA01, 150000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_BXCLOCKRABBIT01, 66000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_COMMERGIFTBOX37, 67500000, 0, 1);
	DropItem(II_GEN_GEM_GEM_CLOCKHEART, 450000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_WHEEL, 900000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_MINIWHEEL, 900000000, 0, 1);
	DropItem(II_GEN_GEM_GEM_NUCTUWHEEL, 450000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_DUMBBULL5
{
	Maxitem = 0;	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
                    }
		#move
		    {
			
		    }	
   	}                
}


//16�� ������

MI_STATUE
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_STETUEPIECE01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_SPIRITTULA
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_TULAZAM01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_SPIRITUMTULA
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_UMTULAZAM01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8 
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_SPIRITOBNIS
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_OBNISCRYSTAL01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_SPIRITBAGNIS
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	

	DropItem(II_SYS_SYS_QUE_BAGNISHAIR01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8 
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_BEGUARDIAN
{
	Maxitem = 2;
	DropGold(149, 215);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	

	DropItem(II_SYS_SYS_QUE_ARMORSHARD01, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}



MI_BEHEMOTH // Ankou
{
	Maxitem = 10;
	
	DropItem(II_WEA_SWO_BEHESWORD, 3250000, 0, 1);
	DropItem(II_WEA_SWT_BEHETWOSWORD, 3250000, 0, 1);
	DropItem(II_WEA_AXT_BEHETWOAXE, 3250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_BEHESHILD, 3250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_BEHESHILD_1, 3250000, 0, 1);
	DropItem(II_WEA_SWO_BEHEONEHANDSWORD, 3250000, 0, 1);
	DropItem(II_WEA_AXE_BEHEONEHANDAXE, 3250000, 0, 1);
	DropItem(II_WEA_BOW_BEHECROSSBOW, 3250000, 0, 1);
	DropItem(II_WEA_YOY_BEHEYOYO, 3250000, 0, 1);
	DropItem(II_WEA_KNU_BEHENUCLE, 3250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_BEHEFORCEZEM, 3250000, 0, 1);
	DropItem(II_WEA_CHE_BEHESTICK, 3250000, 0, 1);
	DropItem(II_WEA_WAN_BEHEWAND, 3250000, 0, 1);
	DropItem(II_ARM_ARM_SHI_BEHEMAGICBOOK, 3250000, 0, 1);
	DropItem(II_WEA_STA_BEHESTAFF, 3250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL013, 25000000, 0, 3);
	DropItem(II_GEN_GEM_CRAFTBAR04, 25000000, 0, 3);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 15
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_PINATA
{
	Maxitem = 1;


	DropItem(II_SYS_SYS_SCR_BXHAPPYBDAY, 3000000000, 0, 1);


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}



MI_BEHESTATUE01
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_BEHESTATUE02
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_BEHESTATUE03
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_BEHESTATUE04
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_BEHESTATUE05
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_TGLUIA01
{
	Maxitem = 5;
	DropGold(229, 332);
	
	DropItem(II_SYS_SYS_SCR_BXThGiving, 450000000, 0, 1);
	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    { 
			loot d 5
		    }	
   	}               
}


//17�� ����

MI_RUGALHEAT01
{
	Maxitem = 2;
	DropGold(409, 515);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_SYS_SYS_QUE_LUGALHORN, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}



MI_RUGALWIN
{
	Maxitem = 2;
	DropGold(409, 515);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_SYS_SYS_QUE_LUGALFEATHER, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_RUGALKUM
{
	Maxitem = 2;
	DropGold(409, 515);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_SYS_SYS_QUE_KUMCLOTH, 200000000, 0, 1);
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_RUGALRIM
{
	Maxitem = 2;
	DropGold(409, 515);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_SYS_SYS_QUE_RIMSTAFF, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8 
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_RUGALKUMA
{
	Maxitem = 2;
	DropGold(409, 515);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
    DropItem(II_SYS_SYS_QUE_KUMCLOTH, 200000000, 0, 1);

	AddSummonMonster( MI_RUGALWIND02 );

	m_nAttackFirstRange = 8;
	

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_RUGALWIND02
{
	Maxitem = 2;
	DropGold(409, 515);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	DropItem(II_SYS_SYS_QUE_LUGALFETTERS, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}



MI_RUGALRIMA
{
	Maxitem = 2;
	DropGold(409, 515);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
	AddSummonMonster( MI_RUGALHEAT02 );
	DropItem(II_SYS_SYS_QUE_RIMACROWN, 200000000, 0, 1);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8 
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_RUGALHEAT02
{
	Maxitem = 2;
	DropGold(409, 515);

	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}



MI_BASILISK // Basilisk of the Great Maw
{
	Maxitem = 3;
	DropGold(49999, 50000);	

	DropItem(II_GEN_GEM_CRAFTMATERIAL011, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL060, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL052, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL017, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL200, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL066, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL040, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL069, 15000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL048, 15000000, 0, 1);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL211, 30000000, 0, 1);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL295, 30000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL296, 30000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTRECYCLE12,   50000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}


//17�� �δ�


MI_KALGASKUMA01  //������ ���� ����
{
	Maxitem = 2;
	DropGold(224, 305);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_KALGASRIMA01		//������ ���� ����
{
	Maxitem = 2;
	DropGold(224, 305);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8 
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_KALGASBABY01		//���̺� ī����
{
	Maxitem = 2;
	DropGold(224, 305);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_KALGASFLY01		//�ö��� ī����
{
	Maxitem = 2;
	DropGold(224, 305);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8 
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_KALGASLESSER01		//���� Į����
{
	Maxitem = 2;
	DropGold(224, 305);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			Keeprangeattack 8 
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_KALGASAKIN01		//��Ų
{
	Maxitem = 2;
	DropGold(224, 305);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
	DropItem(II_SYS_VIS_LV3_WARRIOR, 11000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_KNIGHT, 11000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_BUBBLE 11000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_IBLIS, 11000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_SHADE, 11000000, 0, 1);
		
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 10 cunning sam
			Berserk 20 2.0
			summon 30 1 MI_KALGASKUMA01
			Keeprangeattack 8 
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}


MI_KALGASBALT01		//��Ʈ
{
	Maxitem = 2;
	DropGold(224, 305);


	
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	
	DropItem(II_SYS_VIS_LV3_WARRIOR, 11000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_KNIGHT, 11000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_BUBBLE 11000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_IBLIS, 11000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_SHADE, 11000000, 0, 1);
	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			summon 10 1 MI_KALGASRIMA01
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_KALGASBOSS		//Kalgas
{
	Maxitem = 2;
	DropGold(90009, 140003);

	DropItem(II_ARM_M_LORDK_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_LORDK_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_LORDK_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_LORDK_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_LORDK_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_LORDK_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_LORDK_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_LORDK_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_STORMB_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_STORMB_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_STORMB_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_STORMB_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_STORMB_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_STORMB_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_STORMB_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_STORMB_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_WINDL_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_WINDL_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_WINDL_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_WINDL_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_WINDL_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_WINDL_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_WINDL_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_WINDL_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_CRACKS_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_CRACKS_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_CRACKS_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_CRACKS_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_CRACKS_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_CRACKS_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_CRACKS_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_CRACKS_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_FLOR_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_FLOR_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_FLOR_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_FLOR_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_FLOR_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_FLOR_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_FLOR_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_FLOR_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_FORCEM_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_FORCEM_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_FORCEM_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_FORCEM_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_FORCEM_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_FORCEM_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_FORCEM_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_FORCEM_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_MENT_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_MENT_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_MENT_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_MENT_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_MENT_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_MENT_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_MENT_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_MENT_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_ELEL_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_ELEL_HELMET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_ELEL_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_ELEL_SUIT_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_ELEL_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_ELEL_GAUNTLET_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_M_ELEL_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_ARM_F_ELEL_BOOTS_SET_KAL , 2062500, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL087 , 28062500, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL081,  25000000, 0, 3);

	DropItem(II_GEN_MAT_ELE_CANDLEA, 10000000, 0, 2);
	DropItem(II_GEN_MAT_ELE_RAINATKA, 10000000, 0, 2);
	DropItem(II_GEN_MAT_ELE_SPARKATKA, 10000000, 0, 2);
	DropItem(II_GEN_MAT_ELE_BREEZEATKA, 10000000, 0, 2);
	DropItem(II_GEN_MAT_ELE_SANDATKA, 10000000, 0, 2);

	DropItem(II_GEN_MAT_ELE_LIGHTING, 30000000, 0, 2);
	DropItem(II_GEN_MAT_ELE_VOLCANO, 30000000, 0, 2);
	DropItem(II_GEN_MAT_ELE_EARTHQUAKE, 30000000, 0, 2);
	DropItem(II_GEN_MAT_ELE_OCEAN, 30000000, 0, 2);
	DropItem(II_GEN_MAT_ELE_VACCUM, 30000000, 0, 2);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 60
                        KeepRangeAttack 60
			Berserk 20 2.0
			summon 10 3 MI_KALGASLESSER01
                    }
		#move
		    {
			
		    }	
   	}                
}



MI_KALGASSTELE01			//��Ų ����
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}




MI_KALGASSTELE02			//��Ʈ ����
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}



MI_KALGASEGG01			// Į���� ��
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_COLOBANG // �Ŵ��
{
	Maxitem = 5;
	DropGold(999 , 1000);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 30006250, 0, 1);
	DropItem(II_CHP_COLOSSEUM, 30006250, 0, 1);


	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, MI_BANG1, 2 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_COLOWAGJAK // �Ŵ� �ͱ���
{
	Maxitem = 5;
	DropGold(1700 , 1750);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 30006250, 0, 2);
	DropItem(II_CHP_COLOSSEUM, 30006250, 0, 2);
	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        rangeattack 10            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_COLOREDMANTIS // �Ŵ� �����Ƽ��
{
	Maxitem = 5;
	DropGold(1800 , 1850);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 30006250, 0, 2);
	DropItem(II_CHP_COLOSSEUM, 30006250, 0, 2);
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                                                 
                        Berserk 10 1.2            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_COLOJACKTHEHAMMER // �Ŵ� ����ظ�
{
	Maxitem = 5;
	DropGold(1900 , 1950);
	DropItem(II_GEN_FOO_INS_HPPOTION4, 30006250, 0, 3);
	DropItem(II_CHP_COLOSSEUM, 30006250, 0, 3);

	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_COLOBERKRO // �Ŵ� ��ũ��
{
	Maxitem = 8;
	DropGold(2000 , 2050);


	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 3);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 3);

	SetCallHelper( 100, MI_BUCROW2, 5, TRUE);
	SetCallHelper( 100, MI_BUCROW3, 5, TRUE);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_BUCROW3
			recovery 10 50 100 m
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}

MI_COLOHOWBOW // �Ŵ� ȣ�캸��
{
	Maxitem = 5;
	DropGold(2100 , 2150);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 4);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 4);

	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}

MI_COLOROKEPELER // �Ŵ� �����緯
{
	Maxitem = 2;
	DropGold(2200 , 2250);

	DropItem(II_GEN_JEW_EAR_ATTEARRING, 30000000, 3, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING, 30000000, 9, 1);


	DropItem(II_GEN_MAT_ORICHALCUM01, 3006250, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1560000, 0, 1);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_ROCKEPELLER3
			recovery 10 40 100 m             
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_COLOSTIMEWORK // �Ŵ� ������Ŀ
{
	Maxitem = 5;
	DropGold(2300 , 2350);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 4);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 4);

	

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_STEAMWALKER3
			recovery 10 40 100 m 
                          
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

MI_COLOGRREUNG // �Ŵ� �׸���
{
	Maxitem = 5;
	DropGold(5000 , 5100);


	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 5);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 5);
	DropItem(II_WEA_SWO_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_2, 106250, 0, 1);
	

	m_nAttackFirstRange = 10;
	

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GRRR3
			recovery 10 30 100 m            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_COLOGRIMONG // �Ŵ� �׸���
{
	Maxitem = 5;
	DropGold(4000 , 4100);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 5);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 5);
	DropItem(II_WEA_SWO_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_1	, 106250, 0, 1);

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GREEMONG3
			recovery 10 40 100 m             
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_COLOLUIA // �Ŵ� ���̾�
{
	Maxitem = 5;
	DropGold(5500 , 5550);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 6);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 6);
	DropItem(II_WEA_SWO_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_2, 90000, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_2, 90000, 0, 1);

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			recovery 10 50 100 m
			summon 10 1 MI_LUIA3            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_COLOGONGRI // �Ŵ� ���׸�
{
	Maxitem = 5;
	DropGold(5600 , 5650);


	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 6);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 6);
	DropItem(II_WEA_SWO_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_2, 106250, 0, 1);

	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.6
			summon 10 1 MI_GONGURY3
			recovery 20 30 100 a           
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_COLOKEREUN // �Ŵ� �ɸ�
{
	Maxitem = 5;
	DropGold(5700 , 5750);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 6);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 6);
	DropItem(II_WEA_SWO_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_2, 106250, 0, 1);

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Recovery 10 50 100 m
			Berserk 30 1.5
			summon 10 1 MI_KERN3            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

MI_COLOMATEONIKER // ���׿���Ŀ
{
	Maxitem = 3;
	DropGold(2500 , 3000);
	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 10);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 10);
	DropItem(II_WEA_SWO_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_3, 106250, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 20 2.0
        
                    }

		#move
		    {
			
		    }	
   	}               

}

MI_COLOCYCLOPSX // ����Ŭ�ӽ� X
{
	Maxitem = 3;
	DropGold(2000 , 2010);

	DropItem(II_GEN_FOO_INS_HPPOTION4, 3006250, 0, 7);
	DropItem(II_CHP_COLOSSEUM, 3006250, 0, 7);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_COLODIEOPNIS // ������ ���� �ɴϽ�
{
	Maxitem = 1;
	DropGold(1600 , 1690);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 10);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLORACCOUN // �Ŵ� ����
{
	Maxitem = 2;
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 10);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLOMATEONIKER01 // ���� ���׿���Ŀ
{
	Maxitem = 10;
	DropGold(1000 , 2000);

	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 15);
	DropItem(II_WEA_SWO_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_3_UM, 300000, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_3_UM, 300000, 0, 1);


	m_nAttackFirstRange = 10;

	AI
	{
		#battle
		{
			berserk 2 1.5
		}
	}
}

MI_COLOCLOCKWORK // Ŭ����ũ
{
	Maxitem = 8;
	DropGold(20000 , 30000);

	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 10);	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 30 2
                        recovery 5 20 100 m            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_COLOBIGFOOT // �Ƿ��� ��ǲ
{
	Maxitem = 4;
	DropGold(20000 , 30000);

	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 3);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 3);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 3);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 3);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 3);
	DropItem(II_WEA_SWO_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_SWT_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_AXE_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_AXT_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_KNU_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_CHE_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_WAN_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_STA_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_BOW_COLOGRADE_1_UM, 256250, 0, 1);	
	DropItem(II_WEA_YOY_COLOGRADE_1_UM, 256250, 0, 1);
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 10);	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLOLUCIFER // �����
{
	Maxitem = 10;
	DropGold(200000 , 300000);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 18);	
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
                        Berserk 10 1.5 
			Summon	20	2	MI_IMP03
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_COLOLYCANOS // ������ ����ī�뽺
{
	Maxitem = 5;
	DropGold(20000 , 30000);

	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 15);	
	DropItem(II_WEA_SWO_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_SWT_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_AXE_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_AXT_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_KNU_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_CHE_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_WAN_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_STA_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_BOW_COLOGRADE_2_UM, 100000, 0, 1);	
	DropItem(II_WEA_YOY_COLOGRADE_2_UM, 100000, 0, 1);	


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOSOULVAMPAIN // ��ȥ�� ������
{
	Maxitem = 6;
	DropGold(200000, 300000);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 15);	




	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOSKELGENERAL // ����ư ���ʷ�
{
	Maxitem = 8;
    DropGold(15500 , 16000);

	DropItem(II_SYS_VIS_LV3_WARRIOR, 21000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_KNIGHT, 21000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_BUBBLE 21000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_IBLIS, 21000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_SHADE, 21000000, 0, 1);

	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOSKELDEVIL // ����ư ����
{
	Maxitem = 8;
    DropGold(24500 , 25000);

	DropItem(II_SYS_VIS_LV3_WARRIOR, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_KNIGHT, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_BUBBLE 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_IBLIS, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_SHADE, 31000000, 0, 1);

	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);


	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOTUTTLEKING // ��Ʋŷ
{
	Maxitem = 4;
	DropGold(20000 , 30000);

	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 21000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 27000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 36000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 48000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 63000000, 0, 1);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLORYCANBARGA // ����ĭ �ٸ���
{
	Maxitem = 7;
    DropGold(16000 , 16500);
	DropItem(II_GEN_MAT_DIAMOND, 31000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 31000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 31000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 31000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 31000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 37000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 37000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 37000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 37000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 37000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 46000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 46000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 46000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 46000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 46000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 58000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 58000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 58000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 58000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 58000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 73000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 73000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 73000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 73000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 73000000, 0, 1);


	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLOANGRYBEHEMOTH // �г��� ������
{
	Maxitem = 7;
	DropGold(20000 , 30000);
	
	DropItem(II_GEN_MAT_DIAMOND, 45000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 45000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 45000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 45000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 45000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 49000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 49000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 49000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 49000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 49000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 58000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 58000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 58000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 58000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 58000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 70000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 70000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 70000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 70000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 70000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 83000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 83000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 83000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 83000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 83000000, 0, 1);

	DropItem(II_SYS_SYS_QUE_BEHEMOTHSCALES01, 400000000, 0, 1);
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 15
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLOBASILISK // �ٽǸ���ũ
{
	Maxitem = 8;
    DropGold(22500 , 23000);
	
	DropItem(II_SYS_VIS_LV3_WARRIOR, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_KNIGHT, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_BUBBLE 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_IBLIS, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_SHADE, 31000000, 0, 1);

	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 33);

	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOKALGAS		//Į����
{
	Maxitem = 8;
	DropGold(20000 , 30000);

	DropItem(II_SYS_VIS_LV3_WARRIOR, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_KNIGHT, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_BUBBLE 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_IBLIS, 31000000, 0, 1);
	DropItem(II_SYS_VIS_LV3_SHADE, 31000000, 0, 1);

	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_DIAMOND, 51000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_EMERALD, 57000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_SAPPHIRE, 660000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_RUBY, 680000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);
	DropItem(II_GEN_MAT_TOPAZ, 830000000, 0, 1);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 33);

	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 60
                        KeepRangeAttack 60
			Berserk 20 2.0
			summon 10 3 MI_KALGASLESSER01
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOBANG_1 // �Ŵ��
{
	Maxitem = 5;
	DropGold(1000 , 2000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 1);

	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, MI_BANG1, 2 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_COLOWAGJAK_1 // �Ŵ� �ͱ���
{
	Maxitem = 5;
	DropGold(1000 , 2000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);

	m_dwAttackMoveDelay = 0;
	m_dwRunawayDelay = 1000;
	SetRunAway( 10, 0, 1 );
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        rangeattack 10            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_COLOREDMANTIS_1 // �Ŵ� �����Ƽ��
{
	Maxitem = 5;
	DropGold(1000 , 2000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                                                 
                        Berserk 10 1.2            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_COLOJACKTHEHAMMER_1 // �Ŵ� ����ظ�
{
	Maxitem = 5;
	DropGold(1000 , 2000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);

	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 3
		    }	
   	}               
}

MI_COLOBERKRO_1 // �Ŵ� ��ũ��
{
	Maxitem = 5;
	DropGold(1000 , 2000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_BUCROW3
			recovery 10 50 100 m
                                    
                    }
		#move
		    {
			Loot d 3
		    }	
   	}               
}

MI_COLOHOWBOW_1 // �Ŵ� ȣ�캸��
{
	Maxitem = 5;
	DropGold(1000 , 2000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 1);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);

	

	m_nAttackFirstRange = 8;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                          
                                    
                    }
		#move
		    {
			loot d 4
		    }	
   	}               
}

MI_COLOROKEPELER_1 // �Ŵ� �����緯
{
	Maxitem = 5;
	DropGold(1000 , 2000);


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_ROCKEPELLER3
			recovery 10 40 100 m             
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_COLOSTIMEWORK_1 // �Ŵ� ������Ŀ
{
	Maxitem = 5;
	DropGold(1000 , 2000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 2);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
		{
			scan
		}
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_STEAMWALKER3
			recovery 10 40 100 m 


			}
		#move
		    {
			loot d 5
		    }	
   	}               

}

MI_COLOGRREUNG_1 // �Ŵ� �׸���
{
	Maxitem = 5;
	DropGold(4500 , 5000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 2);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);
	DropItem(II_WEA_SWO_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_2, 106250, 0, 1);	
	m_nAttackFirstRange = 10;AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GRRR3
			recovery 10 30 100 m            
                    }
		#move
		    {
			loot d 5
		    }			
   	}               
}

MI_COLOGRIMONG_1 // �Ŵ� �׸���
{
	Maxitem = 5;
	DropGold(5000 , 6000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 2);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);
	DropItem(II_WEA_SWO_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_1	, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_1	, 106250, 0, 1);


	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			summon 10 1 MI_GREEMONG3
			recovery 10 40 100 m             
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_COLOLUIA_1 // �Ŵ� ���̾�
{
	Maxitem = 5;
	DropGold(6000 , 7000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 2);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);
	DropItem(II_WEA_SWO_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_2, 106250, 0, 1);

	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
			recovery 10 50 100 m
			summon 10 1 MI_LUIA3            
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_COLOGONGRI_1 // �Ŵ� ���׸�
{
	Maxitem = 5;
	DropGold(6500 , 7000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 3);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);	
	DropItem(II_WEA_SWO_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_2, 106250, 0, 1);
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.6
			summon 10 1 MI_GONGURY3
			recovery 20 30 100 a           
                    }
		#move
		    {
			loot d 3
		    }	
   	}               

}

MI_COLOKEREUN_1 // �Ŵ� �ɸ�
{
	Maxitem = 5;
	DropGold(7500 , 8000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 3);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);
	DropItem(II_WEA_SWO_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_2, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_2, 106250, 0, 1);
	

	m_nAttackFirstRange = 10;

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Recovery 10 50 100 m
			Berserk 30 1.5
			summon 10 1 MI_KERN3            
                    }
		#move
		    {
			loot d 5
		    }	
   	}               

}

MI_COLOMATEONIKER_1 // ���׿���Ŀ
{
	Maxitem = 5;
    DropGold(1000 , 3000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 3);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);
	DropItem(II_WEA_SWO_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_3, 106250, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_3, 106250, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }

		#battle
		    {
		        berserk 20 2.0
        
                    }

		#move
		    {
			
		    }	
   	}               

}

MI_COLOCYCLOPSX_1 // ����Ŭ�ӽ� X
{
	Maxitem = 5;
    DropGold(1000 , 2000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 3);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 5);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 5);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_COLODIEOPNIS_1 // ������ ���� �ɴϽ�
{
	Maxitem = 5;
	DropGold(6500 , 7000);
	
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 5);
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLORACCOUN_1 // �Ŵ� ����
{
	Maxitem = 5;
	DropGold(6500 , 7000);
	
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 5);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 5);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 10);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 5);	
	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLOMATEONIKER01_1 // ���� ���׿���Ŀ
{
	Maxitem = 5;
   	DropGold(6500 , 7000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 5);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 5);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 10);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 5);	
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 15);
	DropItem(II_WEA_SWO_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_SWT_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_AXE_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_AXT_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_KNU_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_CHE_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_WAN_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_STA_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_BOW_COLOGRADE_3_UM, 500000, 0, 1);
	DropItem(II_WEA_YOY_COLOGRADE_3_UM, 500000, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#battle
		{
			berserk 2 1.5
		}
	}
}

MI_COLOCLOCKWORK_1 // Ŭ����ũ
{
	Maxitem = 5;
	DropGold(13500, 14000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 5);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 5);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 10);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 5);	

	m_nAttackFirstRange = 10;



	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 30 2
                        recovery 5 20 100 m            
                    }
		#move
		    {
			
		    }	
   	}               

}

MI_COLOBIGFOOT_1 // �Ƿ��� ��ǲ
{
	Maxitem = 5;

	DropGold(9500, 10000);

	DropItem(II_CHP_COLOSSEUM, 30000000, 0, 25);
	DropItem(II_GEN_FOO_PIL_GOLD, 30000000, 0, 5);
	DropItem(II_CHR_FOO_COO_REMANTIS, 30000000, 0, 5);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 30000000, 0, 10);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 5);	
	DropItem(II_WEA_SWO_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_SWT_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_AXE_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_AXT_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_KNU_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_CHE_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_WAN_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_STA_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_BOW_COLOGRADE_1_UM, 306250, 0, 1);	
	DropItem(II_WEA_YOY_COLOGRADE_1_UM, 306250, 0, 1);	
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLOLUCIFER_1 // �����
{
	Maxitem = 5;
    DropGold(14500 , 15000);
	
	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 5);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 5);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 10);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 5);	
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
                        Berserk 10 1.5 
			Summon	20	2	MI_IMP03
                    }
		#move
		    {
			
		    }	
   	}               
}

MI_COLOLYCANOS_1 // ������ ����ī�뽺
{
	Maxitem = 5;
	DropGold(9500 , 10000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 25);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 5);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 5);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 10);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 5);		
	DropItem(II_WEA_SWO_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_SWT_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_AXE_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_AXT_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_KNU_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_CHE_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_WAN_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_STA_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_BOW_COLOGRADE_2_UM, 75000, 0, 1);	
	DropItem(II_WEA_YOY_COLOGRADE_2_UM, 75000, 0, 1);
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
			Berserk 20 2.5
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOSOULVAMPAIN_1 // ��ȥ�� ������
{
	Maxitem = 5;
    DropGold(14500 , 15000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 50);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 10);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 25);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 10);		

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOSKELGENERAL_1 // ����ư ���ʷ�
{
	Maxitem = 5;
	DropGold(19000 , 20000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 50);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 10);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 25);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 10);	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOSKELDEVIL_1 // ����ư ����
{
	Maxitem = 5;
    DropGold(24500 , 25000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 50);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 10);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 25);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 10);	
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOTUTTLEKING_1 // ��Ʋŷ
{
	Maxitem = 5;

    DropGold(15500 , 16000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 50);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 10);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 25);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 10);		


	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack cunning low
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLORYCANBARGA_1 // ����ĭ �ٸ���
{
	Maxitem = 5;
	DropGold(10000 , 20000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 50);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 10);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 25);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 15);	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLOANGRYBEHEMOTH_1 // �г��� ������
{
	Maxitem = 5;
    DropGold(24500 , 25000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 50);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 10);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 25);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 15);		

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan 
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 15
			Berserk 20 2.0
                               
                    }
		#move
		    {
			Loot d 5
		    }	
   	}               
}

MI_COLOBASILISK_1 // �ٽǸ���ũ
{
	Maxitem = 5;
    DropGold(22500 , 23000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 100);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 10);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 25);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 15);	
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_COLOKALGAS_1 // �ణ ������ �ݷμ��� ���� ��ī�ο� �۰����� Į����

{
	Maxitem = 5;
    DropGold(27500 , 28000);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 50);
	DropItem(II_GEN_FOO_PIL_GOLD, 300000000, 0, 10);
	DropItem(II_CHR_FOO_COO_REMANTIS, 300000000, 0, 10);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 300000000, 0, 25);
	DropItem(II_GEN_MAT_ORICHALCUM02, 3006250, 0, 15);	
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 60
						KeepRangeAttack 60
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_EVEROCKEPELLER
{
	Maxitem = 2;
	
	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 60 
                               
                    }
		#move
		    {
			loot d 3			
			
		    }	
   	}               

}

MI_EVEMOTHBEE
{
	Maxitem = 2;

	m_nAttackFirstRange = 10;


	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack  
                                    
                    }
		#move
		    {
			loot d 5
		    }	
   	}               
}

MI_BURR
{
	Maxitem = 2;	
	
	DropItem(II_SYS_SYS_SCR_BXGOLDPACK,15000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXTAMER, 24000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01_1, 310500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE_1, 310500000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON_GP, 360000000, 0, 1);
	DropItem(II_CHR_SYS_SCR_CM_03, 30000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_02, 30000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_01, 30000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_LV60, 270000000, 0, 3);
	DropItem(II_CHR_SYS_SCR_CM_LV65, 270000000, 0, 3);
	DropItem(II_CHR_SYS_SCR_CM_LV70, 270000000, 0, 3);
	DropItem(II_SYS_SYS_EVE_WHITEGG1, 150000000, 0, 3);
	DropItem(II_SYS_SYS_EVE_YELLOWEGG1, 150000000, 0, 3);


	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}
MI_SAPHYRYAN
{
	Maxitem = 2;	
	
	DropItem(II_SYS_SYS_SCR_BXGOLDPACK,15000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BXLEVEL,24000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01_1, 310500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE_1, 310500000, 0, 1);
	DropItem(II_CHR_SYS_SCR_CM_03, 30000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_02, 30000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_LV35, 285000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_LV45, 285000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_LV55, 285000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_LV65, 285000000, 0, 2);
	DropItem(II_SYS_SYS_EVE_PURPLEEGG1, 150000000, 0, 2);
	DropItem(II_SYS_SYS_EVE_GRAYEGG1, 150000000, 0, 2);
m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}
MI_GRAYEARL
{
	Maxitem = 2;	
	
	DropItem(II_SYS_SYS_SCR_BXGOLDPACK,15000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_COMMERGIFTBOX20,24000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON_01,300000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON01_01,300000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_BALLOON02_01,300000000, 0, 1);
	DropItem(II_CHR_SYS_SCR_CM_04,30000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_01,30000000, 0, 2);
	DropItem(II_CHR_SYS_SCR_CM_LV30,34500000, 0, 3);
	DropItem(II_CHR_SYS_SCR_CM_LV40,34500000, 0, 3);
	DropItem(II_CHR_SYS_SCR_CM_LV50,34500000, 0, 3);
	DropItem(II_CHR_SYS_SCR_CM_LV60,34500000, 0, 3);
	DropItem(II_SYS_SYS_EVE_CHRISTMASTEA01,153000000, 0, 1);
	DropItem(II_SYS_SYS_EVE_CHOCOLATE02,240000000, 0, 3);

	

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_GPOTATO01
{
	Maxitem = 6;
   	DropGold(20000, 30000);

	DropItem(II_GEN_MAT_ORICHALCUM01, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1500000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 1500000000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 15);
	DropItem(II_GEN_FOO_PIL_GOLD, 1500000000, 0, 30);
	DropItem(II_CHR_FOO_COO_REMANTIS, 1500000000, 0, 30);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 1500000000, 0, 30);
	DropItem(II_GEN_MAT_ORICHALCUM02, 1500000000, 0, 1);
    
    
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_GPOTATO02
{
	Maxitem = 6;
   	DropGold(20000, 30000);

	DropItem(II_GEN_FOO_PIL_GOLD, 1500000000, 0, 30);
	DropItem(II_CHR_FOO_COO_REMANTIS, 1500000000, 0, 30);
	DropItem(II_GEN_FOO_COO_DDUKGUKHOT, 1500000000, 0, 30);
	DropItem(II_GEN_MAT_ORICHALCUM02, 1500000000, 0, 1);
    
    
	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}
MI_EVEKALGASBABY
{
	Maxitem = 2;	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}
MI_LOVETHIEF
{
	Maxitem = 5;
	DropGold(229, 332);

	DropItem(II_SYS_SYS_EVE_HEARTPIECE, 3000000000, 0, 1);
	

	m_nAttackFirstRange = 8;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        
                        berserk 30 1.2
			Evade 10            
                    }
		#move
		    { 
			loot d 5
		    }	
   	}               
}

MI_SHIPHARPINEES		// Silverwing Dutchess		
{			

	Maxitem = 2;
    DropGold(16999, 17000);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 20);
	DropItem(II_GEN_GEM_CRAFTBAR03, 1000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL077, 3000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL002, 3000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL078, 3000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL108, 3000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL109, 3000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL140, 550000, 0, 1);

	
	m_nAttackFirstRange = 10;					
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack 20 cunning sam
            Rangeattack 60
            KeepRangeAttack 60
			Berserk 20 2.0					
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPMOUGUS						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPWINGMOUGUS						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPMESPI						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPWINDMESPI						
{						
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPREDHARPY						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPBLUEHARPY						
{						
	Maxitem = 2;
    DropGold(99, 100);
	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPHIPPOGRIPH						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 35						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMFLAME01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMRAPRA01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMOLDRUT01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMMINIMUSHU01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMLADYBLUM01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMNIGHTMIST01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMQEEN01		// [Queen of Thorns] Entaness				
{	

	Maxitem = 3;
    DropGold(14999, 15000);
	DropItem(II_SYS_SYS_BACARDBOX, 7500000, 0, 20);	
    DropItem(II_GEN_GEM_CRAFTBAR03, 1000000, 0, 1);
    DropItem(II_GEN_GEM_CRAFTMATERIAL077, 1000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL002, 1000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL078, 1000000, 0, 1);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL108, 1000000, 0, 1);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL109, 1000000, 0, 1);	

	//Almighty Set	
	DropItem(II_ARM_F_BLA_HELMET_SET_12_1	, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12_1		, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12_1	, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12_1	, 250000, 0, 1);	
	DropItem(II_ARM_F_KIN_HELMET_SET_09_1	, 250000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_KIN_BOOTS_SET_09_1    , 250000, 0, 1); 	
	DropItem(II_ARM_F_JST_HELMET_SET_15_1	, 250000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_JST_BOOTS_SET_15_1	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_RIN_HELMET_SET_21_1	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_21_1	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_BIL_HELMET_SET_24_1	, 250000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_BIL_BOOTS_SET_24_1	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_RAG_HELMET_SET_18_1	, 250000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_RAG_BOOTS_SET_18_1	, 250000, 0, 1);  	
	
	//Vigra Set	
	DropItem(II_ARM_F_BLA_HELMET_SET_12_2	, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12_2		, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12_2	, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12_2	, 250000, 0, 1);	
	DropItem(II_ARM_F_KIN_HELMET_SET_09_2	, 250000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_KIN_BOOTS_SET_09_2    , 250000, 0, 1); 	
	DropItem(II_ARM_F_JST_HELMET_SET_15_2	, 250000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_JST_BOOTS_SET_15_2	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_RAG_HELMET_SET_18_2	, 250000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_RAG_BOOTS_SET_18_2	, 250000, 0, 1);  	  	
	DropItem(II_ARM_F_RIN_HELMET_SET_21_2	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_21_2	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_BIL_HELMET_SET_24_2	, 250000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_BIL_BOOTS_SET_24_2	, 250000, 0, 1);  	  	
	DropItem(II_ARM_F_PSY_HELMET_SET_27_1	, 250000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_PSY_BOOTS_SET_27_1	, 250000, 0, 1); 	  	
	DropItem(II_ARM_F_ELE_HELMET_SET_30_1   , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_SUIT_SET_30_1     , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_BOOTS_SET_30_1	, 250000, 0, 1); 	
	
	//Intelus Set 	
	DropItem(II_ARM_F_RIN_HELMET_SET_21_3	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21_3	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21_3 , 250000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_21_3	, 250000, 0, 1);  	  	
	DropItem(II_ARM_F_PSY_HELMET_SET_27_2	, 250000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_PSY_BOOTS_SET_27_2	, 250000, 0, 1); 	  	
	DropItem(II_ARM_F_ELE_HELMET_SET_30_2   , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_SUIT_SET_30_2     , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_BOOTS_SET_30_2	, 250000, 0, 1); 		
	//Almighty Set
	DropItem(II_ARM_M_BLA_HELMET_SET_12_1	, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12_1		, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12_1	, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12_1	, 250000, 0, 1);	
	DropItem(II_ARM_M_KIN_HELMET_SET_09_1	, 250000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_KIN_BOOTS_SET_09_1    , 250000, 0, 1); 
	DropItem(II_ARM_M_JST_HELMET_SET_15_1	, 250000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_JST_BOOTS_SET_15_1	, 250000, 0, 1);  		
	DropItem(II_ARM_M_RIN_HELMET_SET_21_1	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_21_1	, 250000, 0, 1);  	 	
	DropItem(II_ARM_M_BIL_HELMET_SET_24_1	, 250000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_BIL_BOOTS_SET_24_1	, 250000, 0, 1);  	
	DropItem(II_ARM_M_RAG_HELMET_SET_18_1	, 250000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_RAG_BOOTS_SET_18_1	, 250000, 0, 1);  		
	
	//Vigra Set
	DropItem(II_ARM_M_BLA_HELMET_SET_12_2	, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12_2		, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12_2	, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12_2	, 250000, 0, 1);		
	DropItem(II_ARM_M_KIN_HELMET_SET_09_2	, 250000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_KIN_BOOTS_SET_09_2    , 250000, 0, 1); 
	DropItem(II_ARM_M_JST_HELMET_SET_15_2	, 250000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_JST_BOOTS_SET_15_2	, 250000, 0, 1);  	 	
	DropItem(II_ARM_M_RAG_HELMET_SET_18_2	, 250000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_RAG_BOOTS_SET_18_2	, 250000, 0, 1);  		
	DropItem(II_ARM_M_RIN_HELMET_SET_21_2	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_21_2	, 250000, 0, 1);  	
	DropItem(II_ARM_M_BIL_HELMET_SET_24_2	, 250000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_BIL_BOOTS_SET_24_2	, 250000, 0, 1);  	 	
	DropItem(II_ARM_M_PSY_HELMET_SET_27_1	, 250000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_PSY_BOOTS_SET_27_1	, 250000, 0, 1);  		
	DropItem(II_ARM_M_ELE_HELMET_SET_30_1   , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_SUIT_SET_30_1     , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_BOOTS_SET_30_1	, 250000, 0, 1);  		
	
	//Intelus Set
	DropItem(II_ARM_M_RIN_HELMET_SET_21_3	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21_3	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21_3 , 250000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_21_3	, 250000, 0, 1);  		
	DropItem(II_ARM_M_PSY_HELMET_SET_27_2	, 250000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_PSY_BOOTS_SET_27_2	, 250000, 0, 1);  		
	DropItem(II_ARM_M_ELE_HELMET_SET_30_2   , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_SUIT_SET_30_2     , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_BOOTS_SET_30_2	, 250000, 0, 1);  
	m_nAttackFirstRange = 10;					
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack 20 cunning sam			
                        KeepRangeattack 50						
			Berserk 20 2.0					
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNSHARK01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNMERMAN01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNMERMAID01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNTURTLE01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNMERMAN02						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;		
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNMERMAID02						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNSIREN01						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;		
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNKRAKEN01		// King Chiton				
{						

    Maxitem = 3;
    DropGold(15999, 16000);
	DropItem(II_SYS_SYS_BACARDBOX, 7500000, 0, 20);
	DropItem(II_GEN_GEM_CRAFTBAR03, 2500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL077, 2500000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL002, 2500000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL078, 2500000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL108, 2500000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL109, 2500000, 0, 2);

	//Almighty Set
	DropItem(II_ARM_M_BLA_HELMET_SET_12_1	, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12_1		, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12_1	, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12_1	, 250000, 0, 1);	
	DropItem(II_ARM_M_KIN_HELMET_SET_09_1	, 250000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_KIN_BOOTS_SET_09_1    , 250000, 0, 1); 
	DropItem(II_ARM_M_JST_HELMET_SET_15_1	, 250000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_JST_BOOTS_SET_15_1	, 250000, 0, 1);  		
	DropItem(II_ARM_M_RIN_HELMET_SET_21_1	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_21_1	, 250000, 0, 1);  	 	
	DropItem(II_ARM_M_BIL_HELMET_SET_24_1	, 250000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_BIL_BOOTS_SET_24_1	, 250000, 0, 1);  	
	DropItem(II_ARM_M_RAG_HELMET_SET_18_1	, 250000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_RAG_BOOTS_SET_18_1	, 250000, 0, 1);  		
	
	//Vigra Set
	DropItem(II_ARM_M_BLA_HELMET_SET_12_2	, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_SUIT_SET_12_2		, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_GAUNTLET_SET_12_2	, 250000, 0, 1);
	DropItem(II_ARM_M_BLA_BOOTS_SET_12_2	, 250000, 0, 1);		
	DropItem(II_ARM_M_KIN_HELMET_SET_09_2	, 250000, 0, 1);
	DropItem(II_ARM_M_KIN_SUIT_SET_09_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_KIN_GAUNTLET_SET_09_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_KIN_BOOTS_SET_09_2    , 250000, 0, 1); 
	DropItem(II_ARM_M_JST_HELMET_SET_15_2	, 250000, 0, 1);
	DropItem(II_ARM_M_JST_SUIT_SET_15_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_JST_GAUNTLET_SET_15_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_JST_BOOTS_SET_15_2	, 250000, 0, 1);  	 	
	DropItem(II_ARM_M_RAG_HELMET_SET_18_2	, 250000, 0, 1);
	DropItem(II_ARM_M_RAG_SUIT_SET_18_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RAG_GAUNTLET_SET_18_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_RAG_BOOTS_SET_18_2	, 250000, 0, 1);  		
	DropItem(II_ARM_M_RIN_HELMET_SET_21_2	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_21_2	, 250000, 0, 1);  	
	DropItem(II_ARM_M_BIL_HELMET_SET_24_2	, 250000, 0, 1);
	DropItem(II_ARM_M_BIL_SUIT_SET_24_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_BIL_GAUNTLET_SET_24_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_BIL_BOOTS_SET_24_2	, 250000, 0, 1);  	 	
	DropItem(II_ARM_M_PSY_HELMET_SET_27_1	, 250000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27_1	  	, 250000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_PSY_BOOTS_SET_27_1	, 250000, 0, 1);  		
	DropItem(II_ARM_M_ELE_HELMET_SET_30_1   , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_SUIT_SET_30_1     , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30_1 , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_BOOTS_SET_30_1	, 250000, 0, 1);  		
	
	//Intelus Set
	DropItem(II_ARM_M_RIN_HELMET_SET_21_3	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_SUIT_SET_21_3	  	, 250000, 0, 1);
	DropItem(II_ARM_M_RIN_GAUNTLET_SET_21_3 , 250000, 0, 1); 
	DropItem(II_ARM_M_RIN_BOOTS_SET_21_3	, 250000, 0, 1);  		
	DropItem(II_ARM_M_PSY_HELMET_SET_27_2	, 250000, 0, 1);
	DropItem(II_ARM_M_PSY_SUIT_SET_27_2	  	, 250000, 0, 1);
	DropItem(II_ARM_M_PSY_GAUNTLET_SET_27_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_PSY_BOOTS_SET_27_2	, 250000, 0, 1);  		
	DropItem(II_ARM_M_ELE_HELMET_SET_30_2   , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_SUIT_SET_30_2     , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_GAUNTLET_SET_30_2 , 250000, 0, 1); 
	DropItem(II_ARM_M_ELE_BOOTS_SET_30_2	, 250000, 0, 1);  		

	//Almighty Set	
	DropItem(II_ARM_F_BLA_HELMET_SET_12_1	, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12_1		, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12_1	, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12_1	, 250000, 0, 1);	
	DropItem(II_ARM_F_KIN_HELMET_SET_09_1	, 250000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_KIN_BOOTS_SET_09_1    , 250000, 0, 1); 	
	DropItem(II_ARM_F_JST_HELMET_SET_15_1	, 250000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_JST_BOOTS_SET_15_1	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_RIN_HELMET_SET_21_1	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_21_1	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_BIL_HELMET_SET_24_1	, 250000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_BIL_BOOTS_SET_24_1	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_RAG_HELMET_SET_18_1	, 250000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_RAG_BOOTS_SET_18_1	, 250000, 0, 1);  	
	
	//Vigra Set	
	DropItem(II_ARM_F_BLA_HELMET_SET_12_2	, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_SUIT_SET_12_2		, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_GAUNTLET_SET_12_2	, 250000, 0, 1);
	DropItem(II_ARM_F_BLA_BOOTS_SET_12_2	, 250000, 0, 1);	
	DropItem(II_ARM_F_KIN_HELMET_SET_09_2	, 250000, 0, 1);
	DropItem(II_ARM_F_KIN_SUIT_SET_09_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_KIN_GAUNTLET_SET_09_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_KIN_BOOTS_SET_09_2    , 250000, 0, 1); 	
	DropItem(II_ARM_F_JST_HELMET_SET_15_2	, 250000, 0, 1);
	DropItem(II_ARM_F_JST_SUIT_SET_15_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_JST_GAUNTLET_SET_15_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_JST_BOOTS_SET_15_2	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_RAG_HELMET_SET_18_2	, 250000, 0, 1);
	DropItem(II_ARM_F_RAG_SUIT_SET_18_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RAG_GAUNTLET_SET_18_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_RAG_BOOTS_SET_18_2	, 250000, 0, 1);  	  	
	DropItem(II_ARM_F_RIN_HELMET_SET_21_2	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_21_2	, 250000, 0, 1);  	 	
	DropItem(II_ARM_F_BIL_HELMET_SET_24_2	, 250000, 0, 1);
	DropItem(II_ARM_F_BIL_SUIT_SET_24_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_BIL_GAUNTLET_SET_24_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_BIL_BOOTS_SET_24_2	, 250000, 0, 1);  	  	
	DropItem(II_ARM_F_PSY_HELMET_SET_27_1	, 250000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27_1	  	, 250000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_PSY_BOOTS_SET_27_1	, 250000, 0, 1); 	  	
	DropItem(II_ARM_F_ELE_HELMET_SET_30_1   , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_SUIT_SET_30_1     , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30_1 , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_BOOTS_SET_30_1	, 250000, 0, 1); 	
	
	//Intelus Set 	
	DropItem(II_ARM_F_RIN_HELMET_SET_21_3	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_SUIT_SET_21_3	  	, 250000, 0, 1);
	DropItem(II_ARM_F_RIN_GAUNTLET_SET_21_3 , 250000, 0, 1); 
	DropItem(II_ARM_F_RIN_BOOTS_SET_21_3	, 250000, 0, 1);  	  	
	DropItem(II_ARM_F_PSY_HELMET_SET_27_2	, 250000, 0, 1);
	DropItem(II_ARM_F_PSY_SUIT_SET_27_2	  	, 250000, 0, 1);
	DropItem(II_ARM_F_PSY_GAUNTLET_SET_27_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_PSY_BOOTS_SET_27_2	, 250000, 0, 1); 	  	
	DropItem(II_ARM_F_ELE_HELMET_SET_30_2   , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_SUIT_SET_30_2     , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_GAUNTLET_SET_30_2 , 250000, 0, 1); 
	DropItem(II_ARM_F_ELE_BOOTS_SET_30_2	, 250000, 0, 1); 

	m_nAttackFirstRange = 10;					
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack 20 cunning sam			
                        						
                        KeepRangeattack 50						
			Berserk 20 2.0					
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPHARPINEES_1		// Ace Silverwing Dutchess			
{						
	Maxitem = 2;
    DropGold(19999, 20000);

    DropItem(II_GEN_GEM_CRAFTBAR03, 5000000, 0, 2);
    DropItem(II_GEN_GEM_CRAFTMATERIAL077, 5000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL002, 3000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL078, 3000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL108, 3000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL109, 3000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL140, 900000, 0, 1);	
	DropItem(II_GEN_GEM_CRAFTRECYCLE12,   6000000, 0, 1);
	DropItem(II_SYS_SYS_BACARDBOX, 15000000, 0, 20);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack 20 cunning sam
            Rangeattack 60
            KeepRangeAttack 60
			Berserk 20 2.0	
			summon 10 3 MI_SHIPREDHARPY_1				
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPMOUGUS_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPWINGMOUGUS_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPMESPI_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;		
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPWINDMESPI_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;		
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPREDHARPY_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPBLUEHARPY_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_SHIPHIPPOGRIPH_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;		
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 35
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMFLAME01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMRAPRA01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMOLDRUT01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMMINIMUSHU01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMLADYBLUM01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMNIGHTMIST01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_DREAMQEEN01_1		// [Vile Queen of Thorns] Entaness		
{						
	Maxitem = 2;
    DropGold(17999, 18000);

    DropItem(II_GEN_GEM_CRAFTBAR03, 1000000, 0, 2);
    DropItem(II_GEN_GEM_CRAFTMATERIAL077, 1000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL002, 1000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL078, 1000000, 0, 2);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL108, 1000000, 0, 2);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL109, 1000000, 0, 2);	
	DropItem(II_GEN_GEM_CRAFTRECYCLE12,   2000000, 0, 1);


	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack 20 cunning sam			
                      						
                        KeepRangeattack 50						
			Berserk 20 2.0			
			summon 10 3 MI_DREAMNIGHTMIST01_1			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNSHARK01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNMERMAN01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNMERMAID01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNTURTLE01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNMERMAN02_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNMERMAID02_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNSIREN01_1						
{						
	Maxitem = 2;
    DropGold(99, 100);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
                        Rangeattack 10						
			Berserk 20 3.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_HERNKRAKEN01_1		//  Abyssal King Chiton				
{						
	Maxitem = 2;
    DropGold(18999, 19000);
	
	DropItem(II_GEN_GEM_CRAFTBAR03, 1000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL077, 1000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL002, 1000000, 0, 2);
	DropItem(II_GEN_GEM_CRAFTMATERIAL078, 1000000, 0, 2);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL108, 1000000, 0, 2);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL109, 1000000, 0, 2);	
	DropItem(II_GEN_GEM_CRAFTRECYCLE12,   2000000, 0, 1);	


	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack 20 cunning sam			
                       						
                        KeepRangeattack 50						
			Berserk 20 2.0			
			summon 10 3 MI_HERNMERMAID02_1			
                    }						
		#move				
		    {				
		    }				
   	}                					
}						
MI_EVENT_FWCMONSTER		//�Ʒ��� ��� ����				
{						
	Maxitem = 2;
    DropGold(500, 2000);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	DropItem(II_GEN_GEM_GEM_BLUECRYSTAL, 300000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
			Berserk 20 2.0			
                    }						
		#move				
		    {				
		    }				
   	}                					
}			

MI_CHAMELEON_GREEN
{
	Maxitem = 2;	
	
	DropItem(II_SYS_SYS_SCR_TWOMGGREEN,3000000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CHAMELEON_BLUE
{
	Maxitem = 2;	
	
	DropItem(II_SYS_SYS_SCR_TWOMGBLUE,3000000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CHAMELEON_YELLOW
{
	Maxitem = 2;	
	
	DropItem(II_SYS_SYS_SCR_TWOMGYELLOW,3000000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CHAMELEON_RED
{
	Maxitem = 2;	
	
	DropItem(II_SYS_SYS_SCR_TWOMGRED,3000000000, 0, 1);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_CRISTMASGIGLEBOX						
{		
	SetLevelDropPanalty_Off									
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack			
}						
		#move				
		{				
		}				
	}					
}			



MI_TURTLEGUARDER						
{						
	Maxitem = 2;
    DropGold(170, 175);
	DropItem(II_GEN_GEM_GEM_RORE, 300000000, 0, 1);


	m_nAttackFirstRange = 8;		
	AI					
	{					
		#Scan				
                    {						
			scan 			
                    }						
		#battle				
		    {				
			Attack cunning low			
                               						
                    }						
		#move				
		    {				
			Loot d 5			
		    }				
   	}               					
}					
	
	
MI_RABBITFIGHTER						
{						
	Maxitem = 2;
    DropGold(175, 180);
	DropItem(II_GEN_GEM_GEM_PORE, 200000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 10000000, 0, 1);


	m_nAttackFirstRange = 8;			
	AI					
	{					
		#Scan				
                    {						
			scan 			
                    }						
		#battle				
		    {				
			Attack cunning low			
                               						
                    }						
		#move				
		    {				
			Loot d 5			
		    }				
   	}               					
}					
	
MI_RABBITSWORDER						
{						
	Maxitem = 2;
    DropGold(180, 185);
	DropItem(II_GEN_GEM_GEM_GORE, 200000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 10000000, 0, 1);

	m_nAttackFirstRange = 8;				
	AI					
	{					
		#Scan				
                    {						
			scan 			
                    }						
		#battle				
		    {				
			Attack cunning low			
                               						
                    }						
		#move				
		    {				
			Loot d 5			
		    }				
   	}               					
}						

MI_RABBITSPEAR			
{						
	Maxitem = 2;
    DropGold(185, 190);
	DropItem(II_GEN_GEM_GEM_SORE, 200000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 10000000, 0, 1);	

	m_nAttackFirstRange = 8;			
	AI					
	{					
		#Scan				
                    {						
			scan 			
                    }						
		#battle				
		    {				
			Attack cunning low			
                               						
                    }						
		#move				
		    {				
			Loot d 5			
		    }				
   	}               					
}				
		
MI_RABBITASSASSIN						
{						
	Maxitem = 2;
    DropGold(190, 195);
	DropItem(II_GEN_GEM_GEM_CORE, 200000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 10000000, 0, 1);
	m_nAttackFirstRange = 8;				
	AI					
	{					
		#Scan				
                    {						
			scan 			
                    }						
		#battle				
		    {				
			Attack cunning low			
                               						
                    }						
		#move				
		    {				
			Loot d 5			
		    }				
   	}               					
}		
				
MI_RABBITAXE						
{						
	Maxitem = 2;
    DropGold(195, 200);
	DropItem(II_GEN_GEM_GEM_MORE, 200000000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE, 10000000, 0, 1);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
                    {						
			scan 			
                    }						
		#battle				
		    {				
			Attack cunning low			
                               						
                    }						
		#move				
		    {				
			Loot d 5			
		    }				
   	}               					
}			
			
MI_IBLESSPUPPET	// Iblis's Perpetrator
{						
	Maxitem = 3;
    DropGold(300000, 350000);

	DropItem(II_GEN_GEM_CRAFTMATERIAL081, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL295, 30000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL296, 30000000, 0, 1);	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
                    {						
			scan 			
                    }						
		#battle				
		    {				
			Attack cunning low	
			 Rangeattack 20		
                               						
                    }						
		#move				
		    {				
			Loot d 5			
		    }				
   	}               					
}

MI_GRAYEARL01						
{		
	SetLevelDropPanalty_Off									
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack			
}						
		#move				
		{				
		}				
	}					
}

//�� ���ϴ� ������� ����. �߰� �۾��� �ٷ� ������ ����..
MI_PUKEPUKE5
{
	Maxitem = 2;

	m_nAttackFirstRange = 8;
}

MI_BANG5
{
	Maxitem = 2;

	m_nAttackFirstRange = 8;
}

MI_ROCKMUSCLE5
{
	Maxitem = 2;

	m_nAttackFirstRange = 8;
}

MI_MRPUMPKIN5
{
	Maxitem = 2;

	m_nAttackFirstRange = 8;
}

MI_MAFL_PATROL
{
	
	m_nAttackFirstRange = 10;

	SetCallHelper( 0, 0, 0, FALSE );

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
			Berserk 20 3.0
                    }
		#move
		    {
			
		    }	
   	}   
}

MI_DU_METEONYKER5	// Flame King Meteonyker				
{						
	Maxitem = 2;
    DropGold(74999, 75000);

	DropItem(II_GEN_JEW_RIN_FIRERING_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_WATERRING_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_ELECTRICRING_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_ATTEARRINGEST_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_MAGICRINGEST_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_RANGERINGEST_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_HPNECKLACEMR_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_MPNECKLACEMR_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_FPNECKLACEMR_EVENT, 4000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_LANDRING_EVENT,  3500000, 0, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRINGEST_EVENT,  3500000, 0, 1);
	DropItem(II_GEN_JEW_NEC_HPMPNECKLACE_EVENT,  3500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL250,  7500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL301, 14000000, 0, 1);
	m_nAttackFirstRange = 8;	
	
	AI					
	{					
		#battle				
		{
			Attack
			summon 99 5 MI_CYCLOPSX2					
			berserk 2 1.5			
		}				
	}					
}

MI_CYCLOPSX2						
{						
	Maxitem = 2;
    DropGold(99, 100);

	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack			
			Berserk 20 2.0			
                    }						
		#move				
		    {				
		    }				
   	}               					
}

MI_GLAPHAN5					
{						
	Maxitem = 2;
    DropGold(99, 100);

	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack
			rangeattack 10 			
                        summon 50 1 MI_GLAPHAN6					
			Berserk 30 1.8			
                    }						
		#move				
		    {				
			loot d 5			
		    }				
   	}               					
}

MI_GLAPHAN6						
{						
	Maxitem = 2;
    DropGold(99, 100);

	m_nAttackFirstRange = 8;	
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack  			
                                    						
                    }						
		#move				
		    {				
		    }				
   	}               					
}

MI_MUSHMOOT2	// Contaminated Giant Mushmoot				
{						
	Maxitem = 3;
    DropGold(39999, 40000);

	DropItem(II_GEN_GEM_CRAFTMATERIAL044, 12500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL049, 12500000, 0, 1);
	
	m_nAttackFirstRange = 8;		
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack 			
                        Berserk 30 1.5						
			summon 15 1 MI_SMALL_MUSHPOIE2			
                    }						
		#move				
		    {				
		    }				
   	}               					
}

MI_SMALL_MUSHPOIE2
{						
	Maxitem = 2;
    DropGold(99, 100);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
                    }						
		#move				
		    {				
		    }				
   	}               					
}

MI_KRRR2	// Contaminated Giant Kururung				
{						
	Maxitem = 3;
    DropGold(39999, 40000);

	DropItem(II_GEN_GEM_CRAFTMATERIAL044, 12500000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL049, 12500000, 0, 1);

	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
                    {						
			scan			
                    }						
		#battle				
		    {				
			Attack 			
                        Berserk 30 1.5						
			summon 15 1 MI_WAGSAAC5			
			recovery 10 30 0 m            			
                    }						
		#move				
		    {				
		    }				
   	}               					
}

MI_WAGSAAC5						
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;						
	AI					
	{					
		#Scan				
		{						
			scan			
		}						
		#battle				
		{				
			Attack			
			rangeattack 10						
		}						
		#move				
		{				
			loot d 5			
		}				
	}					
}

	
MI_AIBATT6						
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}

MI_ANT1 // Yggdrasil Queen Ant
{						
	Maxitem = 2;
    DropGold(19999, 20000);
	DropItem(II_GEN_MAT_ELE_VACCUM, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_VOLCANO, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_OCEAN, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_LIGHTING, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_EARTHQUAKE, 15000000, 0, 1);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_ANT2
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_ANT3
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_BEETLE1
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_BEETLE2
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_DSPIDER1
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_DSPIDER2
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}

MI_DSPIDER3

{						
	Maxitem = 2;
    DropGold(200, 205);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_GIANTTREEK1 // Contaminated Yggdrasil Tree Branch
{						
	Maxitem = 2;
    DropGold(89999, 90000);
	
    DropItem(II_ARM_F_CRACKS_BOOTS_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_CRACKS_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_CRACKS_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_CRACKS_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_ELEL_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_ELEL_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_ELEL_HELMET_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_ELEL_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_FLOR_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_FLOR_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_FLOR_HELMET_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_FLOR_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_FORCEM_BOOTS_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_FORCEM_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_FORCEM_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_FORCEM_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_LORDK_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_LORDK_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_LORDK_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_LORDK_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_MENT_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_MENT_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_MENT_HELMET_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_MENT_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_STORMB_BOOTS_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_STORMB_GAUNTLET_SET_YGG,  1000000, 0, 1);
	DropItem(II_ARM_F_STORMB_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_STORMB_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_WINDL_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_F_WINDL_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_WINDL_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_F_WINDL_SUIT_SET_YGG, 		1000000, 0, 1);
    DropItem(II_ARM_M_CRACKS_BOOTS_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_CRACKS_GAUNTLET_SET_YGG,  1000000, 0, 1);
	DropItem(II_ARM_M_CRACKS_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_CRACKS_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_ELEL_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_ELEL_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_ELEL_HELMET_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_ELEL_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_FLOR_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_FLOR_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_FLOR_HELMET_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_FLOR_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_FORCEM_BOOTS_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_FORCEM_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_FORCEM_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_FORCEM_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_LORDK_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_LORDK_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_LORDK_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_LORDK_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_MENT_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_MENT_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_MENT_HELMET_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_MENT_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_STORMB_BOOTS_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_STORMB_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_STORMB_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_STORMB_SUIT_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_WINDL_BOOTS_SET_YGG, 		1000000, 0, 1);
	DropItem(II_ARM_M_WINDL_GAUNTLET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_WINDL_HELMET_SET_YGG, 	1000000, 0, 1);
	DropItem(II_ARM_M_WINDL_SUIT_SET_YGG, 		1000000, 0, 1);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 40
            KeepRangeAttack 40
			Berserk 20 2.0		
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_GIANTTREEQ1 // Contaminated Dryad
{						
	Maxitem = 2;
    DropGold(89999, 90000);
	
	DropItem(II_WEA_SWO_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_SWT_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_SWOT_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_AXE_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_AXT_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_ARM_ARM_SHI_YGGDRASILL, 1000000, 0, 1);
	DropItem(II_ARM_ARM_SHI_YGGDRASILL_1, 1000000, 0, 1);
	DropItem(II_WEA_KNU_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_CHE_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_WAN_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_STA_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_BOW_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_YOY_YGGDRASILL, 	1000000, 0, 1);
	DropItem(II_WEA_BOOK_YGG, 			1000000, 0, 1);
	DropItem(II_ARM_ARM_ZEM_YGGDRASIL, 	1000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_YGGRING_STR, 		1000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_YGGNECKLACE_STR, 	1000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_YGGEARRING_STR, 	1000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_YGGRING_DEX, 		1000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_YGGNECKLACE_DEX, 	1000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_YGGEARRING_DEX, 	1000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_YGGRING_INT, 		1000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_YGGNECKLACE_INT, 	1000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_YGGEARRING_INT, 	1000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_YGGRING_STA, 		1000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_YGGNECKLACE_STA, 	1000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_YGGEARRING_STA, 	1000000, 0, 1);
	DropItem(II_ARM_ARM_ZEM_YGGDRASIL_RM, 		1000000, 0, 1);
	DropItem(II_WEA_KNU_YGGDRASILL_RM, 			1000000, 0, 1);


	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 40
            KeepRangeAttack 40
			Berserk 20 2.0
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_GRLARVA1
{						
	Maxitem = 2;
    DropGold(200, 205);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_GRLARVA2
{						
	Maxitem = 2;
    DropGold(200, 205);
	DropKind(IK3_SWD, 6, 6);
	DropKind(IK3_AXE, 6, 6);
	DropKind(IK3_CHEERSTICK, 6, 6);
	DropKind(IK3_KNUCKLEHAMMER, 6, 6);
	DropKind(IK3_WAND, 6, 6);
	DropKind(IK3_STAFF, 6, 6);
	DropKind(IK3_HELMET, 6, 6);
	DropKind(IK3_SUIT, 6, 6);
	DropKind(IK3_GAUNTLET, 6, 6);
	DropKind(IK3_BOOTS, 6, 6);
	DropKind(IK3_SHIELD, 6, 6);
	DropKind(IK3_BOW, 6, 6);
	DropKind(IK3_YOYO, 6, 6);
	DropKind(IK3_THSWD, 6, 6);
	DropKind(IK3_THAXE, 6, 6);
	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_GRLARVA3
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_WOODSPIRIT1
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_WOODSPIRIT2
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low				
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_WOODSPIRIT3
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_WOODSPIRIT4
{						
	Maxitem = 2;
    DropGold(200, 205);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low				
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}
MI_WOODSPIRITBOSS1 // Hugh Naphin
{						
	Maxitem = 2;
    DropGold(19999, 20000);
	DropItem(II_GEN_MAT_ELE_CANDLEA, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_RAINATKA, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_BREEZEATKA, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_SPARKATKA, 15000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_SANDATKA, 15000000, 0, 1);

	DropItem(II_GEN_MAT_ORICHALCUM01, 4500000, 0, 1);
	DropItem(II_GEN_MAT_MOONSTONE,  4500000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}

MI_DURIDTREE // Farming Area - Durid Tree
{						
	Maxitem = 2;
    DropGold(450, 455);	 
	DropItem(II_GEN_FOO_INS_FRUITCAKE,  350000, 0, 1); 		
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				

		}	
   }
   
}


MI_ABESA // Pandora Monster
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_BONWARE
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_BROCKLAN
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_CHESTDEMON
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_CNAKKER // Fortress Monster - Cnakkerling
{						
	Maxitem = 2;
    DropGold(200, 201);	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_CRAZYRAKKIT
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_CROKMASK
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_DAYGORRA
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_DEVILUS
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_EASTERTHIEF
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_EASTERTRICKSTER
{						
	Maxitem = 2;
    DropGold(200, 201);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_EILSES // Farming Area - Elises
{						
	Maxitem = 2;
    DropGold(332, 333);		 
		DropItem(II_GEN_FOO_INS_DONUT,  350000, 0, 1);		 
	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low
}						
		#move				
		{				

		}	
   }
   
}


MI_FORESTSPRITE // Farming Area - Forest Sprite
{						
	Maxitem = 2;
    DropGold(363, 370);	 
		DropItem(II_GEN_FOO_INS_CAKE,  350000, 0, 1);	 
	

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				

		}	
   }
   
}


MI_GOSUKE
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_GYALONG
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_ILLIEN
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_MREGGY
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_MURMUR // Fortress Monster - Murmur
{						
	Maxitem = 2;
    DropGold(200, 205);	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
	
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_NOMBEAR
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_PODLING
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_POSIONMASTER
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_PROTOWORM
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_RAZORLING
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_SHIMMER
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_SLEEPGHOST
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_TINUEN
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_VENADRIO
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_WENJAH
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_YUSHNUN
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_FLUFFEL
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_HELLBREATHER
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_HOODSHOG
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_IRONCHASER
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_MAKIDD
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_MENTIGNIS // Fortress Monster - Mentignis
{						
	Maxitem = 2;
    DropGold(200, 205);		
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_PANPOM // Farming Area - Panpom
{						
	Maxitem = 2;
    DropGold(390, 400);
 
		DropItem(II_GEN_FOO_INS_CUPCAKE,  350000, 0, 1);		 

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low				
}						
		#move				
		{				

		}	
   }
   
}

MI_TOMPAK // Farming Area - Tompak
{						
	Maxitem = 2;
    DropGold(210, 230);	

		DropItem(II_GEN_FOO_INS_SUPERSTARCANDY,  350000, 0, 1); 


	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{			
		
		}	
   }
   
}

MI_TORASK
{						
	Maxitem = 2;
    DropGold(500, 501);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}


MI_TROLUM // Farming Area - Trolum
{						
	Maxitem = 2;
    DropGold(299, 300);
		DropItem(II_GEN_FOO_INS_PANCAKE,  350000, 0, 1);		 
		
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low				
}						
		#move				
		{				

		}	
   }
   
}

MI_FROZENDRAGON
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_GEMBOT
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_GOLDENBUDDHA
{						
	Maxitem = 2;
    DropGold(200, 205);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_HARDO
{						
	Maxitem = 2;
    DropGold(200, 205);		
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
			Recovery 10 50 0 m			
			evade 20			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_HEADDRAGON
{						
	Maxitem = 2;
    DropGold(499999, 500000);	

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam			
                      						
            Attack 20 cunning sam
            Rangeattack 60
            KeepRangeAttack 60
			Berserk 20 2.0			
			
		Berserk 15 1.5				
}						
		#move				
		{				
		}	
   }
   
}

MI_DREADLORD
{						
	Maxitem = 2;
    DropGold(499999, 500000);
	
	m_nAttackFirstRange = 10;					
	
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack
                        Rangeattack 10
			Berserk 15 1.5		
}						
		#move				
		{
		
		}	
   }
   
}

MI_KENTAUROS
{						
	Maxitem = 2;
    DropGold(499999, 500000);	
	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack
                        Rangeattack 10
			Berserk 15 1.5	
}						
		#move				
		{	
		
		}	
   }
   
}

MI_QUKOISOFTHECLEV
{						
	Maxitem = 2;
    DropGold(499999, 500000);
	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack
                        Rangeattack 10
			Berserk 15 1.5			
}						
		#move				
		{
		
		}	
   }
   
}

MI_RIZONTIE
{						
	Maxitem = 2;
    DropGold(499999, 500000);
	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack
			Attack 20 cunning sam
			Berserk 15 1.5				
}						
		#move				
		{
		
		}	
   }
   
}

MI_AEVNASS
{						
	Maxitem = 2;
    DropGold(499999, 500000);
	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
			Berserk 15 1.5		
}						
		#move				
		{
		
		}	
   }
   
}

MI_MINERVA
{						
	Maxitem = 2;
    DropGold(1199999, 1200000);
	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack
                        Rangeattack 10
			Berserk 5 3.0		
}						
		#move				
		{
		
		}	
   }
   
}

MI_NIMAH
{						
	Maxitem = 2;
    DropGold(999999, 1000000);	
	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack
                        Rangeattack 10
			Berserk 10 2.0		
}						
		#move				
		{
		
		}	
   }
   
}

// Ophidian Monsters

MI_CHAOSSOUL
{						
	Maxitem = 4;
    DropGold(3499, 3500);	
		
		//Mighty Set	
		DropItem(II_ARM_M_MER_HELMET_SET_04_1	, 1500000, 0, 1);
		DropItem(II_ARM_M_MER_SUIT_SET_04_1		, 1500000, 0, 1);
		DropItem(II_ARM_M_MER_GAUNTLET_SET_04_1	, 1500000, 0, 1);
		DropItem(II_ARM_M_MER_BOOTS_SET_04_1	, 1500000, 0, 1);	
		DropItem(II_ARM_F_MER_HELMET_SET_04_1	, 1500000, 0, 1);
		DropItem(II_ARM_F_MER_SUIT_SET_04_1		, 1500000, 0, 1);
		DropItem(II_ARM_F_MER_GAUNTLET_SET_04_1	, 1500000, 0, 1);
		DropItem(II_ARM_F_MER_BOOTS_SET_04_1	, 1500000, 0, 1);	
		DropItem(II_ARM_M_ACR_HELMET_SET_05_1	, 1500000, 0, 1);
		DropItem(II_ARM_M_ACR_SUIT_SET_05_1		, 1500000, 0, 1);
		DropItem(II_ARM_M_ACR_GAUNTLET_SET_05_1	, 1500000, 0, 1);
		DropItem(II_ARM_M_ACR_BOOTS_SET_05_1	, 1500000, 0, 1);	
		DropItem(II_ARM_F_ACR_HELMET_SET_05_1	, 1500000, 0, 1);
		DropItem(II_ARM_F_ACR_SUIT_SET_05_1		, 1500000, 0, 1);
		DropItem(II_ARM_F_ACR_GAUNTLET_SET_05_1	, 1500000, 0, 1);
		DropItem(II_ARM_F_ACR_BOOTS_SET_05_1	, 1500000, 0, 1);	
		DropItem(II_ARM_M_ASS_HELMET_SET_06_1	, 1500000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_1	  	, 1500000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_1 , 1500000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_1	, 1500000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_1	, 1500000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_1	  	, 1500000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_1 , 1500000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_1	, 1500000, 0, 1); 

		//Vita Set
		DropItem(II_ARM_M_MER_HELMET_SET_04_2	, 1500000, 0, 1);
		DropItem(II_ARM_M_MER_SUIT_SET_04_2		, 1500000, 0, 1);
		DropItem(II_ARM_M_MER_GAUNTLET_SET_04_2	, 1500000, 0, 1);
		DropItem(II_ARM_M_MER_BOOTS_SET_04_2	, 1500000, 0, 1);	
		DropItem(II_ARM_F_MER_HELMET_SET_04_2	, 1500000, 0, 1);
		DropItem(II_ARM_F_MER_SUIT_SET_04_2		, 1500000, 0, 1);
		DropItem(II_ARM_F_MER_GAUNTLET_SET_04_2	, 1500000, 0, 1);
		DropItem(II_ARM_F_MER_BOOTS_SET_04_2	, 1500000, 0, 1);	
		DropItem(II_ARM_M_ACR_HELMET_SET_05_2	, 1500000, 0, 1);
		DropItem(II_ARM_M_ACR_SUIT_SET_05_2		, 1500000, 0, 1);
		DropItem(II_ARM_M_ACR_GAUNTLET_SET_05_2	, 1500000, 0, 1);
		DropItem(II_ARM_M_ACR_BOOTS_SET_05_2	, 1500000, 0, 1);	
		DropItem(II_ARM_F_ACR_HELMET_SET_05_2	, 1500000, 0, 1);
		DropItem(II_ARM_F_ACR_SUIT_SET_05_2		, 1500000, 0, 1);
		DropItem(II_ARM_F_ACR_GAUNTLET_SET_05_2	, 1500000, 0, 1);
		DropItem(II_ARM_F_ACR_BOOTS_SET_05_2	, 1500000, 0, 1);	
		DropItem(II_ARM_M_ASS_HELMET_SET_06_2	, 1500000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_2	  	, 1500000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_2 , 1500000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_2	, 1500000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_2	, 1500000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_2	  	, 1500000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_2 , 1500000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_2	, 1500000, 0, 1);  	
		DropItem(II_ARM_M_MAG_HELMET_SET_07_1	, 1500000, 0, 1);
		DropItem(II_ARM_M_MAG_SUIT_SET_07_1	 	, 1500000, 0, 1);
		DropItem(II_ARM_M_MAG_GAUNTLET_SET_07_1 , 1500000, 0, 1); 
		DropItem(II_ARM_M_MAG_BOOTS_SET_07_1	, 1500000, 0, 1); 	
		DropItem(II_ARM_F_MAG_HELMET_SET_07_1	, 1500000, 0, 1);
		DropItem(II_ARM_F_MAG_SUIT_SET_07_1	 	, 1500000, 0, 1);
		DropItem(II_ARM_F_MAG_GAUNTLET_SET_07_1 , 1500000, 0, 1); 
		DropItem(II_ARM_F_MAG_BOOTS_SET_07_1	, 1500000, 0, 1);

		//Intel Set
		DropItem(II_ARM_M_ASS_HELMET_SET_06_3	, 1500000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_3  	, 1500000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_3 , 1500000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_3	, 1500000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_3	, 1500000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_3	  	, 1500000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_3 , 1500000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_3	, 1500000, 0, 1);  	
		DropItem(II_ARM_M_MAG_HELMET_SET_07_2	, 1500000, 0, 1);
		DropItem(II_ARM_M_MAG_SUIT_SET_07_2	 	, 1500000, 0, 1);
		DropItem(II_ARM_M_MAG_GAUNTLET_SET_07_2 , 1500000, 0, 1); 
		DropItem(II_ARM_M_MAG_BOOTS_SET_07_2	, 1500000, 0, 1); 	
		DropItem(II_ARM_F_MAG_HELMET_SET_07_2	, 1500000, 0, 1);
		DropItem(II_ARM_F_MAG_SUIT_SET_07_2	 	, 1500000, 0, 1);
		DropItem(II_ARM_F_MAG_GAUNTLET_SET_07_2 , 1500000, 0, 1); 
		DropItem(II_ARM_F_MAG_BOOTS_SET_07_2	, 1500000, 0, 1); 

		DropItem(II_SYS_SYS_SCR_OPHIDIANAMP, 15000000, 0, 3);
		DropItem(II_PET_CHAOSSOUL, 1000000, 0, 1);


	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack		
			Berserk 20 2.0			
}						
		#move				
		{				
		}	
   }
   
}

MI_PHASEBEAST
{						
	Maxitem = 3;
    DropGold(1249, 1250);	

		//Mighty Set	
		DropItem(II_ARM_M_MER_HELMET_SET_04_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_SUIT_SET_04_1		, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_GAUNTLET_SET_04_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_BOOTS_SET_04_1	, 1000000, 0, 1);	
		DropItem(II_ARM_F_MER_HELMET_SET_04_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_SUIT_SET_04_1		, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_GAUNTLET_SET_04_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_BOOTS_SET_04_1	, 1000000, 0, 1);	
		DropItem(II_ARM_M_ACR_HELMET_SET_05_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_SUIT_SET_05_1		, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_GAUNTLET_SET_05_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_BOOTS_SET_05_1	, 1000000, 0, 1);	
		DropItem(II_ARM_F_ACR_HELMET_SET_05_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_SUIT_SET_05_1		, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_GAUNTLET_SET_05_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_BOOTS_SET_05_1	, 1000000, 0, 1);	
		DropItem(II_ARM_M_ASS_HELMET_SET_06_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_1	  	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_1 , 1000000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_1	, 1000000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_1	  	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_1 , 1000000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_1	, 1000000, 0, 1); 

		//Vita Set
		DropItem(II_ARM_M_MER_HELMET_SET_04_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_SUIT_SET_04_2		, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_GAUNTLET_SET_04_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_BOOTS_SET_04_2	, 1000000, 0, 1);	
		DropItem(II_ARM_F_MER_HELMET_SET_04_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_SUIT_SET_04_2		, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_GAUNTLET_SET_04_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_BOOTS_SET_04_2	, 1000000, 0, 1);	
		DropItem(II_ARM_M_ACR_HELMET_SET_05_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_SUIT_SET_05_2		, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_GAUNTLET_SET_05_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_BOOTS_SET_05_2	, 1000000, 0, 1);	
		DropItem(II_ARM_F_ACR_HELMET_SET_05_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_SUIT_SET_05_2		, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_GAUNTLET_SET_05_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_BOOTS_SET_05_2	, 1000000, 0, 1);	
		DropItem(II_ARM_M_ASS_HELMET_SET_06_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_2	  	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_2 , 1000000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_2	, 1000000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_2	  	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_2 , 1000000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_2	, 1000000, 0, 1);  	
		DropItem(II_ARM_M_MAG_HELMET_SET_07_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_MAG_SUIT_SET_07_1	 	, 1000000, 0, 1);
		DropItem(II_ARM_M_MAG_GAUNTLET_SET_07_1 , 1000000, 0, 1); 
		DropItem(II_ARM_M_MAG_BOOTS_SET_07_1	, 1000000, 0, 1); 	
		DropItem(II_ARM_F_MAG_HELMET_SET_07_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_MAG_SUIT_SET_07_1	 	, 1000000, 0, 1);
		DropItem(II_ARM_F_MAG_GAUNTLET_SET_07_1 , 1000000, 0, 1); 
		DropItem(II_ARM_F_MAG_BOOTS_SET_07_1	, 1000000, 0, 1);

		//Intel Set
		DropItem(II_ARM_M_ASS_HELMET_SET_06_3	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_3  	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_3 , 1000000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_3	, 1000000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_3	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_3	  	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_3 , 1000000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_3	, 1000000, 0, 1);  	
		DropItem(II_ARM_M_MAG_HELMET_SET_07_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_MAG_SUIT_SET_07_2	 	, 1000000, 0, 1);
		DropItem(II_ARM_M_MAG_GAUNTLET_SET_07_2 , 1000000, 0, 1); 
		DropItem(II_ARM_M_MAG_BOOTS_SET_07_2	, 1000000, 0, 1); 	
		DropItem(II_ARM_F_MAG_HELMET_SET_07_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_MAG_SUIT_SET_07_2	 	, 1000000, 0, 1);
		DropItem(II_ARM_F_MAG_GAUNTLET_SET_07_2 , 1000000, 0, 1); 
		DropItem(II_ARM_F_MAG_BOOTS_SET_07_2	, 1000000, 0, 1); 

		DropItem(II_PET_PHASEBEAST,  2000000, 0, 1);
		DropItem(II_SYS_SYS_SCR_OPHIDIANAMP, 15000000, 0, 2);




	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam			
	
}						
		#move				
		{				

		}	
   }
   
}

MI_BLAZELICH
{						
	Maxitem = 3;
    DropGold(1249, 1250);	

		//Mighty Set	
		DropItem(II_ARM_M_MER_HELMET_SET_04_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_SUIT_SET_04_1		, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_GAUNTLET_SET_04_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_BOOTS_SET_04_1	, 1000000, 0, 1);	
		DropItem(II_ARM_F_MER_HELMET_SET_04_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_SUIT_SET_04_1		, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_GAUNTLET_SET_04_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_BOOTS_SET_04_1	, 1000000, 0, 1);	
		DropItem(II_ARM_M_ACR_HELMET_SET_05_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_SUIT_SET_05_1		, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_GAUNTLET_SET_05_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_BOOTS_SET_05_1	, 1000000, 0, 1);	
		DropItem(II_ARM_F_ACR_HELMET_SET_05_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_SUIT_SET_05_1		, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_GAUNTLET_SET_05_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_BOOTS_SET_05_1	, 1000000, 0, 1);	
		DropItem(II_ARM_M_ASS_HELMET_SET_06_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_1	  	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_1 , 1000000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_1	, 1000000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_1	  	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_1 , 1000000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_1	, 1000000, 0, 1); 

		//Vita Set
		DropItem(II_ARM_M_MER_HELMET_SET_04_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_SUIT_SET_04_2		, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_GAUNTLET_SET_04_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_MER_BOOTS_SET_04_2	, 1000000, 0, 1);	
		DropItem(II_ARM_F_MER_HELMET_SET_04_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_SUIT_SET_04_2		, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_GAUNTLET_SET_04_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_MER_BOOTS_SET_04_2	, 1000000, 0, 1);	
		DropItem(II_ARM_M_ACR_HELMET_SET_05_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_SUIT_SET_05_2		, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_GAUNTLET_SET_05_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_ACR_BOOTS_SET_05_2	, 1000000, 0, 1);	
		DropItem(II_ARM_F_ACR_HELMET_SET_05_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_SUIT_SET_05_2		, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_GAUNTLET_SET_05_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_ACR_BOOTS_SET_05_2	, 1000000, 0, 1);	
		DropItem(II_ARM_M_ASS_HELMET_SET_06_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_2	  	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_2 , 1000000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_2	, 1000000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_2	  	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_2 , 1000000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_2	, 1000000, 0, 1);  	
		DropItem(II_ARM_M_MAG_HELMET_SET_07_1	, 1000000, 0, 1);
		DropItem(II_ARM_M_MAG_SUIT_SET_07_1	 	, 1000000, 0, 1);
		DropItem(II_ARM_M_MAG_GAUNTLET_SET_07_1 , 1000000, 0, 1); 
		DropItem(II_ARM_M_MAG_BOOTS_SET_07_1	, 1000000, 0, 1); 	
		DropItem(II_ARM_F_MAG_HELMET_SET_07_1	, 1000000, 0, 1);
		DropItem(II_ARM_F_MAG_SUIT_SET_07_1	 	, 1000000, 0, 1);
		DropItem(II_ARM_F_MAG_GAUNTLET_SET_07_1 , 1000000, 0, 1); 
		DropItem(II_ARM_F_MAG_BOOTS_SET_07_1	, 1000000, 0, 1);

		//Intel Set
		DropItem(II_ARM_M_ASS_HELMET_SET_06_3	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_SUIT_SET_06_3  	, 1000000, 0, 1);
		DropItem(II_ARM_M_ASS_GAUNTLET_SET_06_3 , 1000000, 0, 1); 
		DropItem(II_ARM_M_ASS_BOOTS_SET_06_3	, 1000000, 0, 1);  	
		DropItem(II_ARM_F_ASS_HELMET_SET_06_3	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_SUIT_SET_06_3	  	, 1000000, 0, 1);
		DropItem(II_ARM_F_ASS_GAUNTLET_SET_06_3 , 1000000, 0, 1); 
		DropItem(II_ARM_F_ASS_BOOTS_SET_06_3	, 1000000, 0, 1);  	
		DropItem(II_ARM_M_MAG_HELMET_SET_07_2	, 1000000, 0, 1);
		DropItem(II_ARM_M_MAG_SUIT_SET_07_2	 	, 1000000, 0, 1);
		DropItem(II_ARM_M_MAG_GAUNTLET_SET_07_2 , 1000000, 0, 1); 
		DropItem(II_ARM_M_MAG_BOOTS_SET_07_2	, 1000000, 0, 1); 	
		DropItem(II_ARM_F_MAG_HELMET_SET_07_2	, 1000000, 0, 1);
		DropItem(II_ARM_F_MAG_SUIT_SET_07_2	 	, 1000000, 0, 1);
		DropItem(II_ARM_F_MAG_GAUNTLET_SET_07_2 , 1000000, 0, 1); 
		DropItem(II_ARM_F_MAG_BOOTS_SET_07_2	, 1000000, 0, 1); 

		DropItem(II_PET_BLAZELICH,  2000000, 0, 1);
		DropItem(II_SYS_SYS_SCR_OPHIDIANAMP, 10000000, 0, 2);
		


	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam			
}						
		#move				
		{				

		}	
   }
   
}

MI_CAVERNTHINK
{						
	Maxitem = 2;
    DropGold(49, 50);	

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam			
}						
		#move				
		{				

		}	
   }
   
}

MI_TRANCEVINE
{						
	Maxitem = 2;
    DropGold(49, 50);	

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam			
}						
		#move				
		{				

		}	
   }
   
}

MI_MCLASHSKELDEVIL_1
{
	Maxitem = 1;
    DropGold(20000, 30000);

	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 20 cunning sam
                        Rangeattack 10
			Berserk 20 2.0
                    }
		#move
		    {
			
		    }	
   	}                
}

MI_MCLASHLUCIFER
{
	Maxitem = 1;
    DropGold(20000, 30000);

	
	m_nAttackFirstRange = 10;

	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack
                        Rangeattack 10
                        Berserk 10 1.5 
                    }
		#move
		    {
			
		    }	
   	}               
}


MI_MCLASHFLAMEMETEO						
{						
	Maxitem = 1;
    DropGold(20000, 30000);

	m_nAttackFirstRange = 8;	
	AI					
	{					
		#battle				
		{
			Attack
			berserk 2 1.5			
		}				
	}					
}


MI_MCLASHKRRR
{
	Maxitem = 1;
    DropGold(99, 100);

	m_nAttackFirstRange = 10;
	

	
	AI
	{
		#Scan
                    {
			scan
                    }
		#battle
		    {
			Attack 
                        Berserk 30 1.5
     
                    }
		#move
		    {
			
		    }	
   	}        
}

// Forteress Monsters

MI_KETTENTYP // Dark Kettentyp
{						
	Maxitem = 2;
    DropGold(74000, 75000);
	
	DropItem(II_GEN_MAT_ELE_CANDLEA, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_RAINATKA, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_SPARKATKA, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_BREEZEATKA, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_SANDATKA, 6000000, 0, 1);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}

MI_WGOLEM // Willful Golem
{						
	Maxitem = 2;
    DropGold(74000, 75000);

	DropItem(II_GEN_MAT_ELE_LIGHTING, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_VOLCANO, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_EARTHQUAKE, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_OCEAN, 6000000, 0, 1);
	DropItem(II_GEN_MAT_ELE_VACCUM, 6000000, 0, 1);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}				
	}					
}

MI_WABESA // Warrior Abesa - Pandora Monster
{						
	Maxitem = 2;
    DropGold(99, 100);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_EABESA // Entraced Abesa - Pandora Monster
{						
	Maxitem = 2;
    DropGold(99, 100);	
	DropItem(II_GEN_MAT_MOONSTONE,  100000000, 0, 1);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack cunning low			
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_DREADKNIGHT // Dread Knight - Fortress Final Boss
{						
	Maxitem = 2;
    DropGold(99999, 100000);	
	DropItem(II_ARM_M_STORMB_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_STORMB_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_STORMB_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_STORMB_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_STORMB_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_STORMB_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_STORMB_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_STORMB_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_FORCEM_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_FORCEM_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_FORCEM_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_FORCEM_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_FORCEM_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_FORCEM_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_FORCEM_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_FORCEM_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_LORDK_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_LORDK_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_LORDK_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_LORDK_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_LORDK_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_LORDK_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_LORDK_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_LORDK_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_WINDL_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_WINDL_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_WINDL_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_WINDL_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_WINDL_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_WINDL_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_WINDL_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_WINDL_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_MENT_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_MENT_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_MENT_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_MENT_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_MENT_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_MENT_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_MENT_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_MENT_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_ELEL_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_ELEL_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_ELEL_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_ELEL_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_ELEL_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_ELEL_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_ELEL_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_ELEL_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_CRACKS_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_CRACKS_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_CRACKS_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_CRACKS_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_CRACKS_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_CRACKS_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_CRACKS_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_CRACKS_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_FLOR_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_FLOR_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_FLOR_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_M_FLOR_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_FLOR_HELMET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_FLOR_SUIT_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_FLOR_GAUNTLET_SET_35,  1132500, 0, 1);
	DropItem(II_ARM_F_FLOR_BOOTS_SET_35,  1132500, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_FORTRING_STR,  2062500, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_FORTEARRING_STR,  2062500, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_FORTNECKLACE_STR,  2062500, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_FORTRING_DEX,  2062500, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_FORTEARRING_DEX,  2062500, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_FORTNECKLACE_DEX,  2062500, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_FORTRING_INT,  2062500, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_FORTEARRING_INT,  2062500, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_FORTNECKLACE_INT,  2062500, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_FORTRING_STA,  2062500, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_FORTEARRING_STA,  2062500, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_FORTNECKLACE_STA,  2062500, 0, 1);
	DropItem(II_WEA_SWO_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_SWT_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_SWO_FORTRESSSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_SWO_FORTRESSSCHAMP_1,  2062500, 0, 1);
	DropItem(II_WEA_AXE_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_AXT_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_KNU_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_CHE_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_CHE_FORTRESSCHAMP_1,  2062500, 0, 1);
	DropItem(II_WEA_WAN_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_STA_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_BOW_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_YOY_FORTRESSCHAMP,  2062500, 0, 1);
	DropItem(II_WEA_BOOK_FORTRESSCHAMPBOOK,  2062500, 0, 1);
	DropItem(II_WEA_SHI_FORTRESSCHAMPSHIELD,  2062500, 0, 1);
	DropItem(II_WEA_SHI_FORTRESSCHAMPSHIELD_1,  2062500, 0, 1);
	DropItem(II_WEA_ZEM_FORTRESSCHAMPGEM,  2062500, 0, 1);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 30
            KeepRangeAttack 30
			Berserk 20 2.0					
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_DUMMY // Dummy of Flaris
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_DUMMY2 // Dummy of Flaris
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_CRYSTAL1 // Kalgas Crystal
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_CRYSTAL2 // Kalgas Crystal
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_CRYSTAL3 // Kalgas Crystal
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}

MI_CRYSTAL4 // Kalgas Crystal
{
	AI
	{
		#Scan
                    {
                    }
		#battle
		    {
                    }
		#move
		    {
		    }	
   	}               
}


MI_PET_SHROOM01 // Cursed Forest Spirit
{						
	Maxitem = 3;
    DropGold(150, 151);	

	DropItem(II_GEN_GEM_CRAFTMATERIAL195,  	1250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL159,  	1250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL302,  	1250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL306,  	1250000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL064,  	1250000, 0, 1);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 30
            KeepRangeAttack 30
			Berserk 20 2.0					
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_PET_SHROOM02 // Twin Shroompa
{						
	Maxitem = 1;
    DropGold(34999, 35000);	

	DropItem(II_GEN_JEW_EAR_U_EARRING12_1,  20000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE12_1,  20000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING13,  		20000000, 0, 1);
	DropItem(II_GEN_GEM_CRAFTMATERIAL195,  	7500000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL159,  	7500000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL302,  	7500000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL306,  	7500000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL064,  	7500000, 0, 5);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 30
            KeepRangeAttack 30
			Berserk 20 2.0
			summon 100 8 MI_PET_SHROOM01								
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_PET_SHROOM03 // Twin Shroompu
{						
	Maxitem = 1;
    DropGold(34999, 35000);

	DropItem(II_GEN_JEW_EAR_U_EARRING10_1,  20000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE10_1, 10000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_METEOR_1,  20000000, 0, 1);
	
	DropItem(II_GEN_GEM_CRAFTMATERIAL195,  	7500000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL159,  	7500000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL302,  	7500000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL306,  	7500000, 0, 5);
	DropItem(II_GEN_GEM_CRAFTMATERIAL064,  	7500000, 0, 5);

	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 30
            KeepRangeAttack 30
			Berserk 20 2.0
			summon 100 8 MI_PET_SHROOM01  									
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_PET_SHROOM04 // Mother Shroomira
{						
	Maxitem = 2;
    DropGold(50000, 50001);	

	DropItem(II_GEN_JEW_EAR_DEFEARRING06,  7500000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_HPNECKLACE06,  7500000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_STARING06,  7500000, 0, 1);	
	DropItem(II_WEA_KNU_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_SWO_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG_1,  5000000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG_1,  5000000, 0, 1);

	DropItem(II_GEN_GEM_CRAFTMATERIAL195,  	7500000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL159,  	7500000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL302,  	7500000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL306,  	7500000, 0, 10);
	DropItem(II_GEN_GEM_CRAFTMATERIAL064,  	7500000, 0, 10);


	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 30
            KeepRangeAttack 30
			Berserk 20 2.0					
			summon 1 1 MI_PET_SHROOM05  					
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_PET_SHROOM05 // Father Shroom
{						
	Maxitem = 3;
    DropGold(75000, 99000);	
	DropItem(II_WEA_KNU_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_YOY_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_SWO_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_SWT_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_AXE_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_AXT_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_BOW_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_CHE_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_WAN_LEAGENDG_1,  10000000, 0, 1);
	DropItem(II_WEA_STA_LEAGENDG_1,  10000000, 0, 1);

	DropItem(II_GEN_JEW_EAR_U_EARRING10_1,  10000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE10_1,  10000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_METEOR_1,  10000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_U_EARRING12_1,  10000000, 0, 1);
	DropItem(II_GEN_JEW_NEC_U_NECKLACE12_1,  10000000, 0, 1);
	DropItem(II_GEN_JEW_RIN_U_RING13,  		10000000, 0, 1);
	DropItem(II_GEN_JEW_EAR_DEFEARRING06,  10000000, 0, 1);	
	DropItem(II_GEN_JEW_NEC_HPNECKLACE06,  10000000, 0, 1);	
	DropItem(II_GEN_JEW_RIN_STARING06,  10000000, 0, 1);	
	DropItem(II_GEN_GEM_CRAFTMATERIAL195,  	9500000, 0, 15);
	DropItem(II_GEN_GEM_CRAFTMATERIAL159,  	9500000, 0, 15);
	DropItem(II_GEN_GEM_CRAFTMATERIAL302,  	9500000, 0, 15);
	DropItem(II_GEN_GEM_CRAFTMATERIAL306,  	9500000, 0, 15);
	DropItem(II_GEN_GEM_CRAFTMATERIAL064,  	9500000, 0, 15);	
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 30
            KeepRangeAttack 30
			Berserk 20 2.0
			summon 100 1 MI_PET_SHROOM01  					 					
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}

MI_PET_COLOSHROOM06 // Colo Father Shroom
{						
	Maxitem = 3;
    DropGold(7500, 9900);

	DropItem(II_CHP_COLOSSEUM, 300000000, 0, 15);
	DropItem(II_SYS_SYS_SCR_SCRAPTOPAZ	    , 3006250, 0, 15);	
	DropItem(II_SYS_SYS_SCR_SCRAPRUBY	    , 3006250, 0, 15);	
	DropItem(II_SYS_SYS_SCR_SCRAPSAPPHIRE   , 3006250, 0, 15);	
	DropItem(II_SYS_SYS_SCR_SCRAPEMERALD	, 3006250, 0, 15);	
	DropItem(II_SYS_SYS_SCR_SCRAPDIAMOND	, 3006250, 0, 15);
	m_nAttackFirstRange = 8;					
	AI					
	{					
		#Scan				
{						
			scan			
}						
		#battle				
		{				
			Attack 20 cunning sam
            Rangeattack 30
            KeepRangeAttack 30
			Berserk 20 2.0
			summon 100 1 MI_PET_SHROOM01  					 					
}						
		#move				
		{				
			Loot d 5			
		}	
   }
   
}
