/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- main.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - main.cpp - source
**                file.  This initates the program and runs the menu.
**
*********************************************************************************************************/
#include <iostream>

//#include "Game.hpp"
#include "menu.hpp"

int main()
{
	
	std::cout << " Welcome to Final Project. " << std::endl;
	std::cout << " A Text-based Game. " << std::endl;
	std::cout << " Game startup now..... " << std::endl;
	std::cout << "====================================================" << std::endl;
	
	//Game go;
	//go.menu_GOGO();
	
	Menu go;
	go.go_Menu();
	
	std::cout <<" Game exit now." << std::endl;
	
	return 0;
}