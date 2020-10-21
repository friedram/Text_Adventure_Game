/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- stone.hpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - stone.cpp - source
**                file.  This is the stone room- is the location where the player if they have enough
**                hitpoints can pull the sword from the stone to kill Stilbo.
**
*********************************************************************************************************/
#include "stone.hpp"

// default constructor - sets directions to NULL and contains support characteristics
// specific to this space - such as sword / force lance
Stone::Stone()
{
	
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	
	// insert sword pulling stuff

	space_Identifier = 4;
}


// Stone::description - space description - text only.
void Stone::space_Description()
{
	
	std::cout << "You have arrived at the obelisk, and a huge two handed sword " << std::endl;
	std::cout << "juts out of it.  You are unsure if you are strong enough to pull it out. " << std::endl;
	std::cout << std::endl << std::endl;
	
	std::cout << "You see long columns of peasants and merchants filing by you on the" << std::endl;
	std::cout << "left side of the road.  The sky is dark and lightning crackles overhead." << std::endl;
	std::cout << "The trees ahead of you look twisted and forboding.  The ground rumbles" << std::endl;
	std::cout << "and you begin to wonder what is wrong with this strange land." << std::endl;
	std::cout << "An old woman comes near you and begs for your attention." << std::endl;
	std::cout << std::endl;


	std::cout << "'Traveler, turn away from this nightmarish land.  The Stilbo" << std::endl;
	std::cout << "has turned away from the light and darkness has engulfed this" << std::endl;
	std::cout << "land.  Turn back- please for your own sake!'  She rests her" << std::endl;
	std::cout << "hand on her cane and continues on down the road.  She looks over" << std::endl;
	std::cout << "her shoulder as if to expect you to follow her, but then when" << std::endl;
	std::cout << "she realizes that you will not follow she shakes her head sadly" << std::endl;
	std::cout << "and continues down the road." << std::endl;

	std::cout << std::endl;
	
	std::cout << "From this location you can travel in four directions. " << std::endl;
	std::cout << "North your bird companion tells you is Stilbo and his companions " << std::endl;
	std::cout << "searching for clues for the artifacts. " << std::endl;
	std::cout << std::endl;
	std::cout << "To the west there is a Pagan Chapel. " << std::endl;
	std::cout << "To the east is a strange chapel dedicated to the god 'Fitn Ess' " << std::endl;
	std::cout << "To the south is the fountain. " << std::endl;	

}

// Space * Stone::space_Options  - enables the user
// to interact with the space, make choices to go top/bottom/left/right
// and interact with items if available.
Space * Stone::space_Options(Player * player)
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

		std::cout << "You may select one of the following actions:" << std::endl;
		std::cout << "1. Go top" << std::endl;
		std::cout << "2. Go bottom" << std::endl;
		std::cout << "3. Go Left" << std::endl;
		std::cout << "4. Go Right" << std::endl;
		std::cout << "5. Attempt to pull the sword from the obelisk" << std::endl;

		int user_Input04 = 0;
		int counter = 1;

		bool hasSword = false;

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
				std::cout << "5. Attempt to pull the sword from the obelisk" << std::endl;
			}

			user_Input04 = inputValCheck5();


			switch (user_Input04)
			{
			case 1:
				// allows the player to move to space 7 - Final Boss
				// updates the top pointer
				return top;
				break;

			case 2:
				// allows the player to move back to the fountain
				// updates bottom pointer
				return bottom;
				break;

			case 3:
				// allows player to move to space 5 - Pagen Pray location 
				// updates left pointer
				return left;
				break;

			case 4:
				// allows player to move to space 6 - rockey's gym 
				// updates the right pointer
				return right;
				break;

			case 5:
				// attempt to pull the sword from the stone
				// need to update with following code
				// if user pagan and buff > may not work and container may better

				  //std::cout << "Hero Hitpoints: " << player->getHit_Points() << std::endl;
				//If player health is greater than 299 then can do this
				if (player->getHit_Points() > 199)
				{

					std::cout << "**************************************************************" << std::endl;
					std::cout << " You are empowered and easily pull the sword from the obelisk! " << std::endl;
					std::cout << "**************************************************************" << std::endl;

					if (player->look_At_Items("sword"))
					{

						std::cout << "You already have the Sword" << std::endl;
					}

					else
					{
						std::cout << std::endl;
						player->add_Item_Backpack(new Item("sword"));
					}

					hasSword = true;

				}

				else
				{

					std::cout << " You are unable to pull the sword out- perhaps you should visit a church..." << std::endl;

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

// Stone::setTop - set top pointer to next space location
void Stone::setTop(Space * spacez)
{
	
	top = spacez;
	
}

// Stone::setBottom - set bottom pointer to next space location
void Stone::setBottom(Space * spacez)
{

	bottom = spacez;

}

// Stone::setLeft - set left pionter to next space location
void Stone::setLeft(Space * spacez)
{
	
	left = spacez;

}


// Stone::setRight - set right pointer to next space location
void Stone::setRight(Space * spacez)
{
	
	right = spacez;

}

// Stone::getSpace_Identifier - return space number player is at
int Stone::getSpace_Identifier()
{
	
	return space_Identifier;

}

Stone::~Stone()
{

}