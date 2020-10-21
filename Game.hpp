/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- game.hpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - game.hpp - header
**                file.  Game contains the majority of the functions of the game tied in with the
**                space pointer.  The game functionality tracks the time limit, connects Spaces together
**                prints the map for the player, and handles some default exit criteria
**
*********************************************************************************************************/

#include "Player.hpp"
#include "Introduction_Space_Location.hpp"
#include "Goblin.hpp"
#include "fountain.hpp"
#include "stone.hpp"
#include "pray.hpp"
#include "rockey.hpp"
#include "boss.hpp"
#include "inputValidation.hpp"
#include "menu.hpp"
#include <memory>

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
	private:
      Player *player;
      // Space Pointer for space player is currently in
	  Space *current_Space;
      // Space pointer for first space location player starts in
	  // space 1
	  Space *starting_Space;
	  // Space pointer for Goblin spaceLocation
	  // space 2
	  Space *goblin_Space;
	  // space 3
	  Space *fountainz;
	  // space 4
	  Space *stonez;
	  // space 5
	  Space *prayz;
	  // space 6
	  Space *rockeyz;
	  // space 7
	  Space *bossz;

	public:
	  // default constructor
	  Game();
      // runs menu for the game
	  int menu_GOGO();
	  // print_map - enables the printing of the map location based
	  // on where the player is
      void print_map(Space *);
	  // game deconstructor prevents memory leaks
	  ~Game();

};
#endif