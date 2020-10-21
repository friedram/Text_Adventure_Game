/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- pray.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - pray.cpp - source
**                file.  Location of the heathen temple.  player can pray here for a hitpoint buff
**                that then enables them to pull the sword from the stone.
**
*********************************************************************************************************/
#include "pray.hpp"

// default constructor - sets directions to NULL and contains support characteristics
// specific to this space - such as sword / force lance
Pray::Pray()
{
	
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;

	space_Identifier = 5;
}


// Pray::description - space description - text only.
void Pray::space_Description()
{

	std::cout << "You have arrived at a Pagan Church for a diety that you do not worship." << std::endl; 
	std::cout << "A man with face completely tatooed becons you forward wordlessly " << std::endl;
	std::cout << "and guestures for you to kneel and worship with him.  He plans on performing " << std::endl;
	std::cout << "all kinds of profane acts of unholyness....... " << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "From this location you can travel east to the obelisk." << std::endl;
	std::cout << "The remaining routes north/south/west/east are all blocked off " << std::endl;
	

}

// Space * Pray::space_Options  - enables the user
// to interact with the space, make choices to go top/bottom/left/right
// and interact with items if available.
Space * Pray::space_Options(Player * player)
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

		std::cout << "***********************************************************************************************" << std::endl;
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









		std::cout << "===================================================================================" << std::endl;
		std::cout << "You may select one of the following actions:" << std::endl;
		std::cout << "1. Go top" << std::endl;
		std::cout << "2. Go bottom" << std::endl;
		std::cout << "3. Go Left" << std::endl;
		std::cout << "4. Go Right" << std::endl;
		std::cout << "5. Worship like a heathen... \n";
		std::cout << "   I wonder if your prefered diety will understand...." << std::endl;

		int user_Input05 = 0;
		// counter for number of times worshiped -
		// if worship is 10 or greater then get blessing
		int userPagan = 1;
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
				std::cout << "5. Worship like a heathen... \n";
				std::cout << "   I wonder if your prefered diety will understand...." << std::endl;
			}

			user_Input05 = inputValCheck5();

			switch (user_Input05)
			{
			case 1:
				// For space 5, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot travel in this direction, you may only go east." << std::endl;
				break;

			case 2:
				// For space 5, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot travel in this direction, you may only go east." << std::endl;
				break;

			case 3:
				// For space 5, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot travel in this direction, you may only go east." << std::endl;
				break;

			case 4:
				// returns player back to obelisk area
				return right;
				break;

			case 5:
				// positive result - worshiping at the alter 10 or more times results in strength buff
				if (userPagan == 10)
				{

					std::cout << "You have been infused by the power of Ragnar Lodbrok... " << std::endl;
					std::cout << "You can pull 100 swords out of stones now! " << std::endl;
					player->mod_HitPoints(-200);
					std::cout << "Hero Hitpoints: " << player->getHit_Points() << std::endl;
					userPagan++;

				}

				if (userPagan < 10)
				{

					std::cout << "You feel uneasy but oddly at peace, and feel reassured that you made a good choice... " << std::endl;
					// minor health buff
					player->mod_HitPoints(-1);
					std::cout << "Hero Hitpoints: " << player->getHit_Points() << std::endl;
					userPagan++;

				}

				else
				{
					std::cout << "You feel uneasy but oddly at peace, and feel reassured that you made a good choice... " << std::endl;
					// minor health buff
					//player->mod_HitPoints(-1);
					std::cout << "Hero Hitpoints: " << player->getHit_Points() << std::endl;
					userPagan++;
				}
				break;


			default:
				std::cout << "Your bird is having troubles......." << std::endl;
				break;
			}

			counter++;
		}
	}
}

// Pray::setTop - set top pointer to next space location
void Pray::setTop(Space * spacez)
{
	
	top = spacez;
	
}

// Pray::setBottom - set bottom pointer to next space location
void Pray::setBottom(Space * spacez)
{

	bottom = spacez;

}

// Pray::setLeft - set left pionter to next space location
void Pray::setLeft(Space * spacez)
{
	
	left = spacez;

}


// Pray::setRight - set right pointer to next space location
void Pray::setRight(Space * spacez)
{
	
	right = spacez;

}

// Pray::getSpace_Identifier - return space number player is at
int Pray::getSpace_Identifier()
{
	
	return space_Identifier;

}

Pray::~Pray()
{

}