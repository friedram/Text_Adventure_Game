/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- fountain.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - fountain.cpp - source
**                file.  This has a spaceLocation with a fountain in it.  The water will make you sick and
**                cause you to lose the game.
**
*********************************************************************************************************/
#include "fountain.hpp"

// default constructor - sets directions to NULL and contains support characteristics
// specific to this space - such as sword / force lance
Fountain::Fountain()
{
	
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;

	space_Identifier = 3;
}


// Fountain::description - space description - text only.
void Fountain::space_Description()
{

	std::cout << "You have arrived at a large fountain.  While at one point " << std::endl;
	std::cout << "this fountain may have been a symbol of beauty now it is broken" << std::endl;
	std::cout << "and twisted like the surrounding area.  Putrid brown water" << std::endl;
	std::cout << "flows from the top and poisoned dead animals surround the fountain" << std::endl;
	std::cout << "in a semi circle.  A crumbling brick wall surrounds the fountain" << std::endl;
	std::cout << "and the wall to the east looks as if it has all but collapsed." << std::endl;
	std::cout << "A black aura is emmited from the fountain and your bile fills your" << std::endl;
	std::cout << "throat at the smell of the water." << std::endl;
	std::cout << std::endl;
	
	std::cout << "From this location you can travel west back to the Goblin encampment " << std::endl;
	std::cout << "Or you can travel north to a large stone obelisk............" << std::endl;
	
	

}

// Space * Fountain::space_Options  - enables the user
// to interact with the space, make choices to go top/bottom/left/right
// and interact with items if available.
Space * Fountain::space_Options(Player * player)
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
		// death - and yes- it's a three handed sword- because it's a three armed beast- because reasons
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

		std::cout << "==========================" << std::endl;
		std::cout << "You may select one of the following actions:" << std::endl;
		std::cout << "1. Go top" << std::endl;
		std::cout << "2. Go bottom" << std::endl;
		std::cout << "3. Go Left" << std::endl;
		std::cout << "4. Go Right" << std::endl;
		std::cout << "5. Drink the water, yup that's smart..." << std::endl;

		int user_Input03 = 0;
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
				std::cout << "5. Drink the water, yup that's smart..." << std::endl;
			}

			user_Input03 = inputValCheck5();

			switch (user_Input03)
			{
			case 1:
				// allows the player to move to space 4 - Stone Sword space
				// updates the top pointer
				return top;
				break;

			case 2:
				// For space 3, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "The forest looks dangerous to the south- you don't want to go there..." << std::endl;
				break;

			case 3:
				// allows player to move back to the goblin encampment 
				return left;
				break;

			case 4:
				// For space 3, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "Your bird is correct, you cannot go this way." << std::endl;
				break;

			case 5:
				// that water is nasty
				std::cout << "You drink the water and throw up, you are sick and your quest is over. " << std::endl;
				player->mod_HitPoints(620);
				std::cout << std::endl;
				std::cout << "Hit Points currently: " << player->getHit_Points() << std::endl;

				std::cout << "You have taken too much damage and have died.  You have failed in your quest." << std::endl;

				std::cout << "================================================================================================" << std::endl;
				std::cout << std::endl;
				std::cout << "             GAME OVER      " << std::endl;
				std::cout << std::endl;
				std::cout << "================================================================================================" << std::endl;

				player->yes_Lose_Game(10);
				player->nuke_From_Orbit();
				return(0);
				break;


			default:
				std::cout << "Your bird is having troubles......." << std::endl;
				break;
			}

			counter++;
		}
	}
}

// Fountain::setTop - set top pointer to next space location
void Fountain::setTop(Space * spacez)
{
	
	top = spacez;
	
}

// Fountain::setBottom - set bottom pointer to next space location
void Fountain::setBottom(Space * spacez)
{

	bottom = spacez;

}

// Fountain::setLeft - set left pionter to next space location
void Fountain::setLeft(Space * spacez)
{
	
	left = spacez;

}


// Fountain::setRight - set right pointer to next space location
void Fountain::setRight(Space * spacez)
{
	
	right = spacez;

}

// Fountain::getSpace_Identifier - return space number player is at
int Fountain::getSpace_Identifier()
{
	
	return space_Identifier;

}

Fountain::~Fountain()
{

}