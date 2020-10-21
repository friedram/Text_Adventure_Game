/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- player.hpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - player.hpp - header
**                file.  Contains the player based information, hitpoints, win and loss conditions,
**                player backpack with limit of two items
**
*********************************************************************************************************/
#include "Item.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>


#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{

	private:

      // hitpoints
	  int health;
	  // win condition 
	  int wingamez;
	  // lose condition
	  int loserz;
	  // game turns
	  int gameTurnz = 1;


  public:
	// default constructor
	Player();
	// get hit points
    int getHit_Points();
	// modify hitpoints
	void mod_HitPoints(int);
	// add items to player backpack
    void add_Item_Backpack(Item*);
	// getter for backpack
    void get_Item_Backpack();
    bool look_At_Items(std::string);
	// getter for wingamez
	int getWin_Game();
	// set wingamez to a value - enables win condition
	void yes_Win_Game(int);
	// getter for loserz
	int getLose_Game();
	// set loserz to a value - enables loss condition
	void yes_Lose_Game(int);
	// default deconstructor - avoid memory leaks
	int getGameTurn();
	// set getGameTurn to another value
	void add_Game_Turn(int);
	// required structure for item
	std::vector<Item*> item_Store_Backpk;
	// destroy backpack items
	void nuke_From_Orbit();
	// default deconstructor - prevents memory leaks
	~Player();


};
#endif