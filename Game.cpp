/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- game.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - game.cpp - source
**                file.  Game contains the majority of the functions of the game tied in with the
**                space pointer.  The game functionality tracks the time limit, connects Spaces together
**                prints the map for the player, and handles one exit criteria - but other exits are now
**                loaded into the spaces
**
*********************************************************************************************************/
#include "Game.hpp"


// default constructor - sets the game up
Game::Game()
{
	// initializing player for new Player()
	player = new Player();
	// setting starting_Space = to new Introduction Space location  
	starting_Space = new Introduction_Space_Location();
	// setting current_Space to the Introduction_Space_Location (starting space)
	current_Space = starting_Space;
	// setup other locations for spaces
	goblin_Space = new Goblin();
	// drink from the fountain, get sick
	fountainz = new Fountain();
	// pull the sword from the stone, because reasons
	stonez = new Stone();
	// buff to powerup for pulling sword out
	prayz = new Pray();
	// buff to powerup for pulling sword out
	rockeyz = new Rockey();
	// face the evil Stilbo 
	bossz = new Boss();
		
	// setting pointer locations for north south west east
	// Space 01 - Water space - starting location
	starting_Space->setTop(goblin_Space);
	starting_Space->setBottom(NULL);
	starting_Space->setLeft(NULL);
	starting_Space->setRight(NULL);
	// Space 02 - Goblin
	goblin_Space->setTop(NULL);
	goblin_Space->setBottom(starting_Space);
	goblin_Space->setLeft(NULL);
	goblin_Space->setRight(fountainz);
	// Space 03 - Fountain
	fountainz->setTop(stonez);
	fountainz->setBottom(NULL);
	fountainz->setLeft(goblin_Space);
	fountainz->setRight(NULL);
	//Space 04 - Stone
	stonez->setTop(bossz);
	stonez->setBottom(fountainz);
	stonez->setLeft(prayz);
	stonez->setRight(rockeyz);
	// Space 05 - Pray
	prayz->setTop(NULL);
	prayz->setBottom(NULL);
	prayz->setLeft(NULL);
	prayz->setRight(stonez);
	// Space 06 - Rockey training
	rockeyz->setTop(NULL);
	rockeyz->setBottom(NULL);
	rockeyz->setLeft(stonez);
	rockeyz->setRight(NULL);
	//space 07 - Final Combat Boss
	bossz->setTop(NULL);
	bossz->setBottom(stonez);
	bossz->setLeft(NULL);
	bossz->setRight(NULL);
	
}



// Game::print_map - provides the user a map and helped in following the code due to
// space assignments
void Game::print_map(Space * spaceLocation)
{
		
	std::cout << "=========================================================== \n";
	std::cout << "Using your magical bird you see in your minds eye a map. \n";
	std::cout << "@ marks your current location." << std::endl;
	std::cout << " I and = are paths you can take." << std::endl;
	std::cout << std::endl << std::endl;
	  
	switch (spaceLocation->getSpace_Identifier())
    {
		case 1:
		// water - first space
		  std::cout <<  "              	\n"
						"      -			\n"
						"     | |		\n"
						"      - 		\n"
						"      I			\n"
						"  -   -   - 	\n"
						" | |=| |=| |	\n"
						"  -   -   -     \n"
						"      I         \n"
						"  -   -         \n"
						" | |=| |        \n"
						"  -   -         \n"
						"  I             \n"
						" |@|            \n"
						"  -             \n" << std::endl;
		  break;
		  
		case 2:
		  // goblin space
		  std::cout <<  "              	\n"
						"      -			\n"
						"     | |		\n"
						"      - 		\n"
						"      I			\n"
						"  -   -   - 	\n"
						" | |=| |=| |	\n"
						"  -   -   -     \n"
						"      I         \n"
						"  -   -         \n"
						" |@|=| |        \n"
						"  -   -         \n"
						"  I             \n"
						" | |            \n"
						"  -             \n" << std::endl;
		  break;
		
		case 3:
		// fountain space
		  std::cout <<  "              	\n"
						"      -			\n"
						"     | |		\n"
						"      - 		\n"
						"      I			\n"
						"  -   -   - 	\n"
						" | |=| |=| |	\n"
						"  -   -   -     \n"
						"      I         \n"
						"  -   -         \n"
						" | |=|@|        \n"
						"  -   -         \n"
						"  I             \n"
						" | |            \n"
						"  -             \n" << std::endl;
		  break;
		
		case 4:
		// fountain space
		  std::cout <<  "              	\n"
						"      -			\n"
						"     | |		\n"
						"      - 		\n"
						"      I			\n"
						"  -   -   - 	\n"
						" | |=|@|=| |	\n"
						"  -   -   -     \n"
						"      I         \n"
						"  -   -         \n"
						" | |=| |        \n"
						"  -   -         \n"
						"  I             \n"
						" | |            \n"
						"  -             \n" << std::endl;
		  break;
		
		case 5:
		// pray space
		  std::cout <<  "              	\n"
						"      -			\n"
						"     | |		\n"
						"      - 		\n"
						"      I			\n"
						"  -   -   - 	\n"
						" |@|=| |=| |	\n"
						"  -   -   -     \n"
						"      I         \n"
						"  -   -         \n"
						" | |=| |        \n"
						"  -   -         \n"
						"  I             \n"
						" | |            \n"
						"  -             \n" << std::endl;
		  break;
		
		case 6:
		// workout with rockey space  
		  std::cout <<  "              	\n"
						"      -			\n"
						"     | |		\n"
						"      - 		\n"
						"      I			\n"
						"  -   -   - 	\n"
						" | |=| |=|@|	\n"
						"  -   -   -     \n"
						"      I         \n"
						"  -   -         \n"
						" | |=| |        \n"
						"  -   -         \n"
						"  I             \n"
						" | |            \n"
						"  -             \n" << std::endl;
		  break;
		  
		case 7:
		 // final boss space 
		  std::cout <<  "              	\n"
						"      -			\n"
						"     |@|		\n"
						"      - 		\n"
						"      I			\n"
						"  -   -   - 	\n"
						" | |=| |=| |	\n"
						"  -   -   -     \n"
						"      I         \n"
						"  -   -         \n"
						" | |=| |        \n"
						"  -   -         \n"
						"  I             \n"
						" | |            \n"
						"  -             \n" << std::endl;
		  break;
		
		default:
		  std::cout << " You have discovered an area where your bird /n";
		  std::cout << " cannot see." << std::endl;
		  break;
	  
	}
	
	std::cout << "=========================================================== \n";
	std::cout << std::endl << std::endl;
}


// Game::menu_GOGO - runs the game, provides the initial story, provides loss
// conditions, keeps track of game rounds, and decrement of 1 health per movement
int Game::menu_GOGO()
{
	// track number of turns in the game - round only counts when player moves
	// from location to location - game_round is a day of time
	int game_Rounds = 1;
	
	/*******
	int user_Start_Pick = 0;
    
	std::cout << "Menu choice- do you wish to play the game or exit? " << std::endl;
	std::cout << "1. Play" << std::endl;
	std::cout << "2. Exit" << std::endl;
	
	user_Start_Pick = inputValCheck2a();
	
    
    // If user wants to quit, then quit.
    if (user_Start_Pick == 2)
    {
 
	  std::exit(0);
    
	}
	********/ 
    
    // if user does not select to quit, then play the game
	// start the epic journey - yes this is based on a AD&D custom campaign & some M.U.D. dungeons that I wrote in the 1990's
	//==============================================================================================================================================
    std::cout << " A aged man, about 5ft 8in a long grey beard flows down his chin and he has a kindly look to his demenor." << std::endl;
	std::cout << " He wears a simple grey cloak over his rather shabby but clean robes.  I have need of men and women to complete" << std::endl;
	std::cout << " a quest, in which the fate of many more than just that of the Celphians and Forestrians are at stake.  The" << std::endl;
	std::cout <<" balance of much is at stake.  The homelands of the Elves has also been assulted by their longtime hated rivals" << std::endl;
	std::cout <<" the Drow." << std::endl;
	
	std::cout <<" He takes you to a medium sized cabin where there is fresh food and drink waiting around the table.  " << std::endl;
	std::cout <<" Please sit down and eat.  He sits facing you in an modest easy chair by the warmth of the roaring fire in the fireplace. " << std::endl;
	
	std::cout <<" The events which have been set into motion has been not been done by the mage formaly known as Stilbo.  In fact " << std::endl;
	std::cout <<" they were bound to happend in any case, so it was fortold.  He sighs.  There has been a great upheaval in the heavens," << std::endl;
	std::cout <<" the immortals themselves have begun a struggle of power and it has become manifest here on Enroth.  Great evil and good " << std::endl;
	std::cout <<" have come to the land to do battle, and there are those who have yet to truly choose a side.  All sides search for an" << std::endl;
	std::cout <<" artifact so great that it could spell destruction for one side or all.  This artifact location is yet a mystery but legend," << std::endl;
	std::cout <<" as much of it as I know now that is of it, that it is only useable by the one who dons the Gauntlet of Firun." << std::endl;

	std::cout <<" Firun was a Paladin of such purity and humbleness the gods of both good and evil became furious.  The gods of good wanted " << std::endl;
	std::cout <<" to test him for sincerity, the gods of evil wanted him destroyed as he had hampered their desires over the entire world" << std::endl;
	std::cout <<" of Enroth. " << std::endl;
	
	std::cout <<" Firun was put to the task of challenging the mightiest of the Great Ancient Red Wyrms known to mortals as Hellbringer. " << std::endl;
	std::cout <<" Hellbringer was told in advance that Firun was going to challenge him and after Firun set upon his unicorn to challenge " << std::endl; 
	std::cout <<" Hellbringer, Hellbring destroyed his summer palace where his wife and 4 children were staying.  Firun was found out about  " << std::endl; 
	std::cout <<" this trikery just an hour to late, and when he charged back to his summer palace he found Hellbringer waiting for him.  " << std::endl; 
	std::cout << std::endl << std::endl;
	
	std::cout << " The battle was epic, the forces of both good and evil backed by the gods, the country side was blasted apart and as the  " << std::endl; 
	std::cout << " two fought.  Firuns steed was badly wounded in the hellish fire that Hellbringer spout at them both and Firun ordered his " << std::endl; 
	std::cout << " steed to retreat as he would face Hellbringer alone.  Hellbringer charged head on to Firun spouting flames at him, preparing  " << std::endl; 
	std::cout << " to eat Firun whole.  Firun set for the charge and with his last prayer to Torm he drew back his holy sword in two hands and  " << std::endl; 
	std::cout << " as the creature striked him he cut the beasts eyes out, severing the jaw in a buitiful 360 arc swing of his great sword.  " << std::endl; 
	std::cout << " Hellbringer landed on Firun and breathing its last final curse insinerated itself and all of Firun.  All that was left of  " << std::endl; 
	std::cout << " Firun was his breastplate, holysword and guantlet.  " << std::endl; 
	std::cout << std::endl << std::endl;
	
	std::cout << " Your first part of the quest is to defeat the evil Wizard Stilbo who is seaching for Firun's artifacts.  Stilbo has not "  << std::endl; 
	std::cout << " yet found any of these yet, and you must stop him.  Stilbo has powerful magical wards that protect him so you must retreive  " << std::endl; 
	std::cout << " either a magical sword out of a huge stone of adamantine or find another magical weapon to defeat Stilbo.  You will take a  " << std::endl; 
	std::cout << " boat to a distant shore and travel to the ruins location our Bothan scouts have said they have seen Stilbo.  Many Boathans  " << std::endl; 
	std::cout << " died to bring us that information. " << std::endl;
	//==============================================================================================================================================
	
    // game begins on the shore- first space - this contains the conditions for
	// play - player must have more than 0 hitpoints and has fewer than 30 turns
	// to finish the game.
    while (player->getHit_Points() > 0 && game_Rounds <= 30 && player->getWin_Game() == 0 && player->getLose_Game() == 0 )
    {
		
		if (player->getWin_Game() > 0)
		{
			player->nuke_From_Orbit();
			// return to main menu
			return(0);

		}

		if (player->getLose_Game() > 0)
		{
			player->nuke_From_Orbit();
			// return to main menu
			return(0);

		}

		if (game_Rounds > 30)
		{


			std::cout << "Three huge hulking three armed beasts appear before you weilding unique " << std::endl;
			std::cout << "three handed swords glowing in power.  The largest steps forward toward you" << std::endl;
			std::cout << "and bellows - 'My master Stilbo has found the map to the fabled artifacts, we" << std::endl;
			std::cout << "are here to send you to corpse hall where you will not know the glory of Sto'Vo'Kor" << std::endl;
			std::cout << std::endl << std::endl;
			std::cout << "You fight back mightily but the fight is completely unfair, you slay one outright, and" << std::endl;
			std::cout << "you sever two of the three arms of another, but ultimately you are slain.  Your last thoughts" << std::endl;
			std::cout << "are that of wondering if you could have just prayed longer or spent more time training with" << std::endl;
			std::cout << "Rocky, perhaps you might have stood a chance........" << std::endl;
			std::cout << "================================================================================================" << std::endl;
			std::cout << std::endl;
			std::cout << "             GAME OVER      " << std::endl;
			std::cout << std::endl;
			std::cout << "================================================================================================" << std::endl;
			player->yes_Lose_Game(10);
			player->nuke_From_Orbit();
			// return to main menu
			return(0);
		}
		
		// Heroes stats- game round - equipment
		std::cout << "*************************************" << std::endl;
		std::cout << "Game Round number:  " << game_Rounds << std::endl;
		std::cout << "Hero Hitpoints: " << player->getHit_Points() << std::endl;
		std::cout << "Equipment: ";
		player->get_Item_Backpack();
		std::cout << std::endl;
		std::cout << "*************************************" << std::endl;
		std::cout << "This is a cursed land, you need to hurry, you will take a point of damage for every day that goes by..." << std::endl;
      
		// Provide warning when hitpoints get low.
		if (player->getHit_Points() < 20)
		{
		  
		  // yes, a reference from Gauntlet, because Gauntlet is awesome
		  std::cout << "Warrior needs food badly!  You may die soon." << std::endl;
		  
		}
	  
		// provide warning when turns are running out
		if (game_Rounds > 19)
		{
		  
		  std::cout << "You have a feeling that you are taking too much time and " << std::endl;
		  std::cout << "the evil Stilbo is close to completing his quest..... " << std::endl;
	  
		}
          
		// Print the current map and the player's location in it.
		print_map(current_Space);
      
		// Present the current spaceLocation's description and options within it.
		current_Space->space_Description();
            
		// Set the current_Space to the pointer returned above. But not just the pointer, 
		// the actual object it points to. That way we get the next spaceLocation object.
		current_Space = current_Space->space_Options(player);
      
        // increase the number of turns
		game_Rounds++;

		player->add_Game_Turn(1);

		// was having problems running death in Game.cpp so I tried out a pointer to a new variable add_Game_Turn- fixed many problems
		//std::cout << "custom game turn: " << player->getGameTurn() << std::endl;
		

		player->mod_HitPoints(1);
	  
    }
 

	std::cout << "Your journey has come to an end" << std::endl;
		
	player->nuke_From_Orbit();
	// return to main menu
	return(0);
	 
}

// default deconstructor - prevents memory leaks
Game::~Game()
{
	
	
	delete player;
	delete current_Space;

	delete starting_Space;
	
	delete goblin_Space;
	delete fountainz;
	delete stonez;
	delete prayz;
	delete rockeyz;
	delete bossz;
	
}