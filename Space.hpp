/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- Space.hpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - Space.hpp - header
**                file.  Space is an abstract class that has pure virtual functions.
**
*********************************************************************************************************/
#include <iostream>

#include "inputValidation.hpp"
#include "Player.hpp"

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
	private:
      // program requirement - space pointer top
	  Space *top;
	  // program requirement - space pointer bottom
      Space *bottom;
	  // program requirement - space pointer left
      Space *left;
	  // program requirement - space pointer right
      Space *right;
	  // space_Identifier keeps track of which spaceLocation the player is in
      int space_Identifier;
		  
	public:
	  //default constructor
      Space();
      // declaring pure virtual function by adding = 0; 
	  virtual void space_Description() = 0;
      // space player object for adding items to backpack
	  virtual Space * space_Options(Player *) = 0;
      virtual void setTop(Space *) = 0;
      virtual void setBottom(Space *) = 0;
      virtual void setLeft(Space *) = 0;
      virtual void setRight(Space *) = 0;
	  // return player space/location
	  virtual int getSpace_Identifier() = 0;
	  // deconstructor - avoiding memory leaks
	  virtual ~Space();

};
#endif