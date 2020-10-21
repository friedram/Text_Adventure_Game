/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- Goblin.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - goblin.cpp - source
**                file.  Runs the goblin room - can try to steal a candle- that won't work and also
**                can attempt to pick up forcelance
**
*********************************************************************************************************/
#include "Goblin.hpp"

// default constructor - sets directions to NULL and contains support characteristics
// specific to this space - such as sword / force lance
Goblin::Goblin()
{
	
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;

	space_Identifier = 2;
	
}


// Goblin::description - space description - text only.
void Goblin::space_Description()
{

	std::cout << "You sneak up on the Goblin camp.  There are six gobilns milling about \n";
	std::cout << "here.  Suddently one of the goblins sees you and utters a high pitched \n";
	std::cout << "screetch and runs north into the forest.  The rest of the goblins freeze \n";
	std::cout << "in fear, except for one who is feebly grasping a sharp shard of glass\n";
	std::cout << "as if it were a dagger. \n";
	std::cout << std::endl << std::endl;
	std::cout << "With a waivering voice in broken common it says: 'You no take candle! \n";
	std::cout << std::endl;
	std::cout << "Of special note in this area you see the following: \n";
	std::cout << "Special 1: A really nice looking goblin candle. \n";
	std::cout << "Special 2: A metallic rod. \n";
	std::cout << std::endl;
	std::cout << "Your options for movement is moving east toward a fountain or south back \n";
	std::cout << "to the coastline.  Your bird advises you to not go back there.... \n";

}

// Space * Goblin::space_Options  - enables the user
// to interact with the space, make choices to go top/bottom/left/right
// and interact with items if available.
Space * Goblin::space_Options(Player * player)
{
	
	if (player->getHit_Points() < 1)
	{

		std::cout << std::endl;
		std::cout << "You have taken too much damage and have died.  You have failed in your quest." << std::endl;

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

	if (player->getGameTurn() > 29)
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

	else
	{





		std::cout << "=====================================================================" << std::endl;
		std::cout << "You may select one of the following actions:" << std::endl;
		std::cout << "1. Go top" << std::endl;
		std::cout << "2. Go bottom" << std::endl;
		std::cout << "3. Go Left" << std::endl;
		std::cout << "4. Go Right" << std::endl;
		std::cout << "5. Take the goblins candle - this doesn't look like a good idea...." << std::endl;
		std::cout << "6. Approach the metal rod. " << std::endl;

		int user_Input02 = 0;
		int counter = 1;

		while (true)
		{


			// User makes a choice based on the options presented.
			// If it is the second time around, the options are presented again.
			if (counter > 1)
			{
				std::cout << "You may select one of the following actions:" << std::endl;
				std::cout << "1. Go top" << std::endl;
				std::cout << "2. Go bottom" << std::endl;
				std::cout << "3. Go Left" << std::endl;
				std::cout << "4. Go Right" << std::endl;
				std::cout << "5. Take the goblins candle - this doesn't look like a good idea...." << std::endl;
				std::cout << "6. Approach the metal rod. " << std::endl;
			}

			user_Input02 = inputValCheck6();
			int user_Input_02special = 0;

			switch (user_Input02)
			{
			case 1:
				// For space 2, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You can't follow the goblin into the forest, you will be killed for sure... " << std::endl;
				break;

			case 2:
				// For space 2 returns back to space 1
				return bottom;
				break;

			case 3:
				// For space 1, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "Your bird is correct, you cannot go this way." << std::endl;
				break;

			case 4:
				// allows the player to move to space 3 - Fountain
				return right;
				break;

			case 5:

				std::cout << "You approach the goblins candle and arrows come out of the forest, flipping you on \n";
				std::cout << "your back and attacking your weak spot for massive damage.  \n";
				std::cout << " THAT HURT!" << std::endl;
				player->mod_HitPoints(20);
				std::cout << std::endl;
				std::cout << "Hit Points currently: " << player->getHit_Points() << std::endl;
				if (player->getHit_Points() < 1)
				{
					std::cout << "You have taken too much damage and have died.  You have failed in your quest." << std::endl;

					std::cout << "================================================================================================" << std::endl;
					std::cout << std::endl;
					std::cout << "             GAME OVER      " << std::endl;
					std::cout << std::endl;
					std::cout << "================================================================================================" << std::endl;
					player->nuke_From_Orbit();
					// return to main menu
					return(0);

				}
				break;

			case 6:

				std::cout << "You approach the metalic rod and have a the following choices: \n";
				std::cout << "1. Pick up the rod, it's just a metal stick. \n";
				std::cout << "2. Shout 'Let's Bring It' as loud as you can while picking it up \n";
				std::cout << "   because that'll totally do something... hahaha.... \n";
				std::cout << "3. Do the smart thing and wrap it up in your backpack \n";



				user_Input_02special = inputValCheck3();

				switch (user_Input_02special)
				{
				case 1:

					std::cout << "The metalic rod doesn't recognize you- and spikes shoot on impossibly large chains \n";
					std::cout << "that surround you and then pulp you for INSANE damage! \n";
					//player->mod_HitPoints(100);
					std::cout << std::endl;
					//std::cout << "Hit Points currently: " << player->getHit_Points() << std::endl;
					//if (player->getHit_Points() < 1)
					//{
					std::cout << "You have taken too much damage and have died.  You have failed in your quest." << std::endl;

					std::cout << "================================================================================================" << std::endl;
					std::cout << std::endl;
					std::cout << "             GAME OVER      " << std::endl;
					std::cout << std::endl;
					std::cout << "================================================================================================" << std::endl;
					player->yes_Lose_Game(10);
					player->nuke_From_Orbit();
					// return to main menu
					return(0);

					//}

					break;

				case 2:

					if (player->look_At_Items("Forcelance"))
					{

						std::cout << "You already have a Forcelance" << std::endl;
					}

					else
					{
						std::cout << "You shout as loud as you can: \n";
						std::cout << "   LET'S BRING IT!!1!!one!! \n";
						std::cout << "The metalic rod leaps into the air and becomes a quarterstaff, then a wand of \n";
						std::cout << "magic missles, then a grappling hook..... You are in awe as ancient lore of the \n";
						std::cout << "Force Lance embeds into your mind - you are now an unstoppable force! \n";
						std::cout << std::endl;
						player->add_Item_Backpack(new Item("Forcelance"));
						std::cout << "You have acquired Dylan Hunt's Force Lance of Power! " << std::endl;
					}
					break;

				case 3:
					if (player->look_At_Items("Forcelance"))
					{

						std::cout << "You already have a Forcelance" << std::endl;
					}

					else
					{
						std::cout << " You use your backpack to pick up the rod - a metal spike juts out of it but only \n";
						std::cout << " impales your supplies causing you no damage. " << std::endl;
						player->add_Item_Backpack(new Item("Forcelance"));
					}
					break;

				default:

					std::cout << " Your bird stops you from doing anything foolish! " << std::endl;
					break;

				}

			default:
				std::cout << "Your bird is having troubles......." << std::endl;
				break;
			}

			counter++;
		}
	}
}

// Goblin::setTop - set top pointer to next space location
void Goblin::setTop(Space * spacez)
{
	
	top = spacez;
	
}

// Goblin::setBottom - set bottom pointer to next space location
void Goblin::setBottom(Space * spacez)
{

	bottom = spacez;

}

// Goblin::setLeft - set left pionter to next space location
void Goblin::setLeft(Space * spacez)
{
	
	left = spacez;

}


// Goblin::setRight - set right pointer to next space location
void Goblin::setRight(Space * spacez)
{
	
	right = spacez;

}

// Goblin::getSpace_Identifier - return space number player is at
int Goblin::getSpace_Identifier()
{
	
	return space_Identifier;

}

Goblin::~Goblin()
{

}