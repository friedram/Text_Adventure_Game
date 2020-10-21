/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- rockey.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - rockey.cpp - source
**                file.  Another temple of sorts- allows the player to workout for 5 rounds and then
**                get a hitpoint buff to enable them to pull the sword from the stone.
**
*********************************************************************************************************/
#include "rockey.hpp"

// default constructor - sets directions to NULL and contains support characteristics
// specific to this space - such as sword / force lance
Rockey::Rockey()
{
	
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;

	space_Identifier = 6;
}


// Rockey::description - space description - text only.
void Rockey::space_Description()
{

	std::cout << "You have reached the odd chapel - there are literally hundreds " << std::endl;
	std::cout << "of creatures of all types, some of which would be naturally " << std::endl;
	std::cout << "enemies locked in strange corgraphy - it looks very odd " << std::endl;
	std::cout << "and upon closer inspection you notice that all of them are " << std::endl;
	std::cout << "incredibly ripped, buff, powerful. " << std::endl;
	std::cout << std::endl;
	
	std::cout << "Greetings!  I am a member here at 'Fitn Ess' and you look  " << std::endl;
	std::cout << "like you could use some help.  I'd like you to join our  " << std::endl;
	std::cout << "group known as 'HASHT AGWE ARELADDER' - and I don't  " << std::endl;
	std::cout << "want your money - I just want you to get ripped and buff!  " << std::endl;
	std::cout << std::endl;
	
	std::cout << "All you need to do is join me in our famous Rocky Balboa workout  " << std::endl;
	std::cout << "for five days and I am sure you will be satisfied!  What do you say?  " << std::endl;
	
	std::cout << std::endl;
	std::cout << "From this location you can travel west back to the large obelisk." << std::endl;
	std::cout << "All other directions are not accesible....  " << std::endl;	

}

// Space * Rockey::space_Options  - enables the user
// to interact with the space, make choices to go top/bottom/left/right
// and interact with items if available.
Space * Rockey::space_Options(Player * player)
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




		std::cout << "==========================" << std::endl;
		std::cout << "You may select one of the following actions:" << std::endl;
		std::cout << "1. Go top" << std::endl;
		std::cout << "2. Go bottom" << std::endl;
		std::cout << "3. Go Left" << std::endl;
		std::cout << "4. Go Right" << std::endl;
		std::cout << "5. Perform whatever this 'HASHT AGWE ARELADDER' and  " << std::endl;
		std::cout << "   join in this Rocky Balboa workout..." << std::endl;

		int user_Input03 = 0;
		int counter = 1;
		int userBuffed = 1;

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
				std::cout << "5. Perform whatever this 'HASHT AGWE ARELADDER' and  " << std::endl;
				std::cout << "   join in this Rocky Balboa workout..." << std::endl;

			}

			user_Input03 = inputValCheck5();

			switch (user_Input03)
			{
			case 1:
				// For space 6, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot go north." << std::endl;
				break;

			case 2:
				// For space 6, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot go south." << std::endl;
				break;

			case 3:
				// allows player to move back to the stone obelisk 
				return left;
				break;

			case 4:
				// For space 6, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot go east." << std::endl;
				break;

			case 5:
				// positive result - perform workout 5 times results in strength buff
				if (userBuffed == 5)
				{

					std::cout << "On this day of training you are visited by an avatar of Fitn Ess" << std::endl;
					std::cout << "'Remember - if it bleeds, you can kill it.' " << std::endl;
					std::cout << "You feel like you could pull the sword out of the stone now! " << std::endl;
					player->mod_HitPoints(-200);
					std::cout << "Hero Hitpoints: " << player->getHit_Points() << std::endl;
					userBuffed++;

				}

				if (userBuffed < 5)
				{
					std::cout << "You work really hard, pushups, situps, squats, deadlifts it hurts and you really " << std::endl;
					std::cout << "want to quit, even though at the end of the day you feel a little bit better... " << std::endl;
					// minor health buff
					player->mod_HitPoints(-1);
					std::cout << "Hero Hitpoints: " << player->getHit_Points() << std::endl;
					userBuffed++;
				}


				else
				{
					std::cout << "You work really hard, pushups, situps, squats, deadlifts it hurts and you really " << std::endl;
					std::cout << "want to quit, even though at the end of the day you feel a little bit better... " << std::endl;
					// minor health buff
					//player->mod_HitPoints(-1);
					std::cout << "Hero Hitpoints: " << player->getHit_Points() << std::endl;
					userBuffed++;
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

// Rockey::setTop - set top pointer to next space location
void Rockey::setTop(Space * spacez)
{
	
	top = spacez;
	
}

// Rockey::setBottom - set bottom pointer to next space location
void Rockey::setBottom(Space * spacez)
{

	bottom = spacez;

}

// Rockey::setLeft - set left pionter to next space location
void Rockey::setLeft(Space * spacez)
{
	
	left = spacez;

}


// Rockey::setRight - set right pointer to next space location
void Rockey::setRight(Space * spacez)
{
	
	right = spacez;

}

// Rockey::getSpace_Identifier - return space number player is at
int Rockey::getSpace_Identifier()
{
	
	return space_Identifier;

}

Rockey::~Rockey()
{



}