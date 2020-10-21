/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- boss.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - boss.cpp - source
**                file.  This program contains the spaceLocation of the boss, and the boss encounter with
**                Stilbo.  Provides for two win conditions, a loss condition and the ability to leave
**                the spaceLocation
**
*********************************************************************************************************/
#include "boss.hpp"

// default constructor - sets directions to NULL and contains support characteristics
// specific to this space - such as sword / force lance
Boss::Boss()
{
	
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;

	space_Identifier = 7;
}


// Boss::description - space description - text only.
void Boss::space_Description()
{

	std::cout << "You travel another full day and your bird reports to you what your " << std::endl;
	std::cout << "eyes saw for miles - a huge tree, and what looks like your quarry. " << std::endl;
	std::cout << std::endl;
	
	std::cout << "You have finally reached the thirty foot blackened" << std::endl;
	std::cout << "tree.  The tree is a deeper black than any coal" << std::endl;
	std::cout << "that you have ever seen in your entire life.  The limbs" << std::endl;
	std::cout << "of the tree sweep upward as if protesting the existence" << std::endl;
	std::cout << "of the heavens themselves.  They claw at the sky as if" << std::endl;
	std::cout << "to try to catch and drag angels to the depts of hell itself." << std::endl;
	std::cout << "No leaves adorn this tree and a putrid brackish green slime" << std::endl;
	std::cout << "seeps from cracks in the bark.  A cold chill sweeps over you" << std::endl;
	std::cout << "and you begin to shiver even though you are in a temperate" << std::endl;
	std::cout << "climate.  Even as you look at the tree and try to fathom its" << std::endl;
	std::cout << "existence, you feel as if it is staring through you into your soul." << std::endl;
	std::cout << "You leap back as a few branches begin to move, but they are not" << std::endl;
	std::cout << "moving toward you.  Instead they have cleared a path into a large" << std::endl;
	std::cout << "opening in the tree.  The opening leads downward with strange" << std::endl;
	std::cout << "looking stairs lighted by eerie torches.  You think you hear a" << std::endl;
	std::cout << "cackle of glee as you near the entrance." << std::endl;
	std::cout << std::endl;

	std::cout << "The great blackened tree stands here and claws at the sky as if to" << std::endl;
	std::cout << "try to tear the heavens down itself.  An opening looms near the base" << std::endl;
	std::cout << "of the tree and it would be a true test of your courage to enter" << std::endl;
	std::cout << "the depths below." << std::endl;	
	
	std::cout << "You have reached the end of your journey - you have found Stilbo " << std::endl;
	std::cout << "and his minions looking for the artifacts within the tree. " << std::endl;
	std::cout << std::endl;
		
	std::cout << std::endl;
	std::cout << "From this location you can attempt to retreat south back to the large obelisk." << std::endl;
	std::cout << "All other directions are not accesible without alerting Stilbo's entourage ....  " << std::endl;	

}

// Space * Boss::space_Options  - enables the user
// to interact with the space, make choices to go top/bottom/left/right
// and interact with items if available.
Space * Boss::space_Options(Player * player)
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
	
	std::cout << "==========================" << std::endl;
	std::cout << "You may select one of the following actions:" << std::endl;
    std::cout << "1. Go top" << std::endl;
    std::cout << "2. Go bottom" << std::endl;
    std::cout << "3. Go Left" << std::endl;
    std::cout << "4. Go Right" << std::endl;
	std::cout << "5. Attack Stilbo and his men" << std::endl;


	int user_Input07 = 0;  
	int counter = 1;
	
	//int userBuffed = 0;
	//bool forceLance = false;
	//bool twoHandedSword = false;

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
				std::cout << "5. Attack Stilbo and his men" << std::endl;

			}

			user_Input07 = inputValCheck5();

			//switch (user_Input07)
			//{
			//	case 1:

			if (user_Input07 == 1)
			{
				// For space 7, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot go north." << std::endl;
				//	break;
			}

			if (user_Input07 == 2)
			{
				//	case 2:
					  // player retreats back to the stone obelisk
				return bottom;
				//	break;
			}

			if (user_Input07 == 3)
			{

				//case 3:
				  // For space 7, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot go north." << std::endl;

				//	break;
			}

			if (user_Input07 == 4)
			{
				//	case 4:
					  // For space 7, an invalid choice - provides user text and doesn't return to a new area.
				std::cout << "You cannot go east." << std::endl;
				//break;
			}

			// did the player win? 0 or less then no
			int winnerwinnerchickendinner = 0;

			if (user_Input07 == 5)
			{
				//	case 5:
					  // need to work on this - something like the following
				if (player->look_At_Items("Forcelance"))
				{
					// prevent loss condition
					winnerwinnerchickendinner++;
					std::cout << "You shout: 'Stilbo!  The long night has not come for our world yet!'" << std::endl;
					std::cout << "Stilbo and his entourage turn suprised, initiative is yours!" << std::endl;
					std::cout << std::endl;
					std::cout << "With impossible knowledge from the Force Lance - you proclaim: " << std::endl;
					std::cout << "' I have vowed to drive back the night and rekindle the light! " << std::endl;
					std::cout << "'Hope lives again! " << std::endl;
					std::cout << std::endl;

					std::cout << "Stilbo quickly tries to rally but it is too late, you begin the sacred encantation " << std::endl;
					std::cout << "Radiant Silvergun: Be Attitudes for Gains- FLAP ARMS! " << std::endl;
					std::cout << std::endl;
					std::cout << "The force lance fires multiple magic missles, completely destroying Silbo and his crew! " << std::endl;

					std::cout << std::endl;

					std::cout << std::endl;

					std::cout << "==============================================" << std::endl;
					std::cout << "               YOU WIN" << std::endl;
					std::cout << "==============================================" << std::endl;

					// execute win command
					player->yes_Win_Game(10);
					player->nuke_From_Orbit();
					return(0);

				}

				if (player->look_At_Items("sword"))
				{

					// prevent loss condition
					winnerwinnerchickendinner++;
					std::cout << "You shout: 'Stilbo!  The long night has not come for our world yet!'" << std::endl;
					std::cout << "Stilbo and his entourage turn suprised, initiative is yours!" << std::endl;
					std::cout << std::endl;
					std::cout << "You draw the two handed sword and slay Stilbo quickly.  His minions flee... " << std::endl;

					std::cout << std::endl;

					std::cout << std::endl;

					std::cout << "==============================================" << std::endl;
					std::cout << "               YOU WIN" << std::endl;
					std::cout << "==============================================" << std::endl;
					// execute win command
					player->yes_Win_Game(10);
					player->nuke_From_Orbit();
					return(0);

				}

				// loss condition
				if (winnerwinnerchickendinner == 0)
				{

					std::cout << "You charge toward Stilbo and his men, but you aren't prepared." << std::endl;
					std::cout << "it ends quickly, you dispatch two of his minions, but they hold you down " << std::endl;
					std::cout << "and Stilbo draws his curved Vashna dagger and carves out your heart and " << std::endl;
					std::cout << "you see him eat half of it before your death........ " << std::endl;
					// apply damage (for affect - run script showing death
					player->mod_HitPoints(500);
					std::cout << "Hero Hitpoints " << player->getHit_Points() << std::endl;
					player->yes_Lose_Game(10);

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

				else
				{

					std::cout << std::endl << std::endl;
					std::cout << "==============================================" << std::endl;
					std::cout << "               GAME OVER" << std::endl;
					std::cout << "==============================================" << std::endl;
					player->nuke_From_Orbit();
					return(0);

				}

			}
		}
	
	counter ++;
	}
}

// Boss::setTop - set top pointer to next space location
void Boss::setTop(Space * spacez)
{
	
	top = spacez;
	
}

// Boss::setBottom - set bottom pointer to next space location
void Boss::setBottom(Space * spacez)
{

	bottom = spacez;

}

// Boss::setLeft - set left pionter to next space location
void Boss::setLeft(Space * spacez)
{
	
	left = spacez;

}


// Boss::setRight - set right pointer to next space location
void Boss::setRight(Space * spacez)
{
	
	right = spacez;

}

// Boss::getSpace_Identifier - return space number player is at
int Boss::getSpace_Identifier()
{
	
	return space_Identifier;

}

Boss::~Boss()
{

}