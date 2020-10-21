/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game-Introduction_Space_Location.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - Introduction_Space_Location.cpp
**                header file.  This is where the game starts- the player arrives in the wavy shores
**                seeking out Stilbo.
**
*********************************************************************************************************/
#include "Introduction_Space_Location.hpp"

// default constructor - sets directions to NULL and contains support characteristics
// specific to this space - such as sword / force lance
Introduction_Space_Location::Introduction_Space_Location()
{
	
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	
	space_Identifier = 1;
}


// Introduction_Space_Location::description - space description - text only.
void Introduction_Space_Location::space_Description()
{

	std::cout << "You are on a shore of a distant land.  The land feels evil. \n";
	std::cout << "Your magical bird informs you that you cannot go to the east or west \n";
	std::cout << "and the only path forward is toward a gobin camp down the hill. \n";
	std::cout << "fortunately there is a great amount of cover for you to hide your approach. \n";

}

// Space * Introduction_Space_Location::space_Options  - enables the user
// to interact with the space, make choices to go top/bottom/left/right
// and interact with items if available.
Space * Introduction_Space_Location::space_Options(Player * player)
{
	
	player->mod_HitPoints(1);
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
	std::cout << "==========================" << std::endl;
	std::cout << "You may select one of the following actions:" << std::endl;
    std::cout << "1. Go top" << std::endl;
    std::cout << "2. Go bottom" << std::endl;
    std::cout << "3. Go Left" << std::endl;
    std::cout << "4. Go Right" << std::endl;

	int user_Input01 = 0;  
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
		}
		
		user_Input01 = inputValCheck4();
		
		switch (user_Input01)
		{
			case 1:
			  // allows the player to move to space 2 - Goblin space
			  // updates the top pointer
			  return top;
			break;
			
			case 2:
			  // For space 1, an invalid choice - provides user text and doesn't return to a new area.
			  std::cout << "You stare longingly back at the water.  You know you cannot go home until you've stopped Stilbo." << std::endl;
			break;
			  
		    case 3:
			  // For space 1, an invalid choice - provides user text and doesn't return to a new area.
			  std::cout << "Your bird is correct, you cannot go this way." << std::endl;
			break;

			case 4:
			  // For space 1, an invalid choice - provides user text and doesn't return to a new area.
			  std::cout << "Your bird is correct, you cannot go this way." << std::endl;
			break;

			default:
			  std::cout << "Your bird is having troubles......." << std::endl;
			break;
		}
	
	counter ++;
	}
	}
}

// Introduction_Space_Location::setTop - set top pointer to next space location
void Introduction_Space_Location::setTop(Space * spacez)
{
	
	top = spacez;
	
}

// Introduction_Space_Location::setBottom - set bottom pointer to next space location
void Introduction_Space_Location::setBottom(Space * spacez)
{

	bottom = spacez;

}

// Introduction_Space_Location::setLeft - set left pionter to next space location
void Introduction_Space_Location::setLeft(Space * spacez)
{
	
	left = spacez;

}


// Introduction_Space_Location::setRight - set right pointer to next space location
void Introduction_Space_Location::setRight(Space * spacez)
{
	
	right = spacez;

}

// Introduction_Space_Location::getSpace_Identifier - return space number player is at
int Introduction_Space_Location::getSpace_Identifier()
{
	
	return space_Identifier;

}

Introduction_Space_Location::~Introduction_Space_Location()
{

}