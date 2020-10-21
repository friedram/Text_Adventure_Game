/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- menu.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - menu.cpp - header
**                file.  This initates the menu and then runs the game.
**
*********************************************************************************************************/

#include "menu.hpp"

// default constructor
Menu::Menu()
{
	
}
// menu options
void Menu::go_Menu()
{
	
	int user_Start_Pick = 0;
    
	std::cout << "Menu choice- do you wish to play the game or exit? " << std::endl;
	std::cout << "1. Play" << std::endl;
	std::cout << "2. Exit" << std::endl;
	
	user_Start_Pick = inputValCheck2a();
	
    
    // If user wants to quit, then quit.
    if (user_Start_Pick == 2)
    {
 
	  std::exit(0);
    
	}
	
	else
	{
		Game go;
		go.menu_GOGO();
	}
	
	
}

// default deconstructor
Menu::~Menu()
{
	
}
