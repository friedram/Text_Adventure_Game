/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- player.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - player.cpp - source
**                file.  Contains the player based information, hitpoints, win and loss conditions
**
*********************************************************************************************************/
#include "Player.hpp"

// Default constructor
Player::Player()
{

	health = 80;
	wingamez = 0;

}

// getHit_Points - prints players current life
int Player::getHit_Points()
{
  return health;
}

// Player::mod_HitPoints - modifierz the hitpoints
void Player::mod_HitPoints(int modifierz)
{

	health -= modifierz;

}

// getWin_Game - return win game number
int Player::getWin_Game()
{

	return wingamez;

}

// Player::yes_Win_Game - increment wingamez to enable win condition exit 
void Player::yes_Win_Game(int modifierz)
{

	wingamez += modifierz;

}

// getLose_Game - return lose game number
int Player::getLose_Game()
{

	return loserz;

}

// yes_Lose_Game - increment loserz game to enable lose condition
void Player::yes_Lose_Game(int modifierz)
{

	loserz += modifierz;

}


// returns the backpack for player
void Player::get_Item_Backpack()
{
	if (item_Store_Backpk.size() > 2)
	{

		std::cout << "I'm sorry you can only hold two items" << std::endl;

	}

	else
	{
	
		for (size_t i = 0; i < item_Store_Backpk.size(); i++)
		{

			std::cout << " || " << item_Store_Backpk[i]->getItem_Description() << " || ";
			//std::cout << item_Store_Backpk[0]->getItem_Description() << " - item_Store_Backpk full ";
    
		}
	}
}

// adds the item to the player backpack
void Player::add_Item_Backpack(Item * new_item)
{
	
	item_Store_Backpk.push_back(new_item);

}


// Player::look_At_Items - enables looking in a characters equipment
bool Player::look_At_Items(std::string descriptionz)
{
    
	for (size_t i = 0; i < item_Store_Backpk.size(); i++)
    {
		
		if (item_Store_Backpk[i]->getItem_Description() == descriptionz) //i
		{
			
			return true;
		}

	}
  
	//std::cout << "You cannot carry more items" << std::endl;
	return false;
}


// getLose_Game - return lose game number
int Player::getGameTurn()
{

	return gameTurnz;

}

// set getGameTurn to another value
void Player::add_Game_Turn(int addone)
{

	gameTurnz += addone;

}

// Player::nuke_From_Orbit - destroying objects
void Player::nuke_From_Orbit()
{
	for (size_t i = 0; i < item_Store_Backpk.size(); i++)
	{
		delete (item_Store_Backpk[i]);
	}
	item_Store_Backpk.clear();
}

//credit for clearing vectors
// https://stackoverflow.com/questions/12795196/clearing-a-vector-of-pointers
// Default deconstructor - helps avoid memory leaks
Player::~Player()
{
	

}
