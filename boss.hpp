/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- boss.hpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - boss.hpp - header
**                file.  This program contains the spaceLocation of the boss, and the boss encounter with 
**                Stilbo.  Provides for two win conditions, a loss condition and the ability to leave
**                the spaceLocation
**
*********************************************************************************************************/
#include "Space.hpp"

#ifndef BOSS_HPP
#define BOSS_HPP

class Boss : public Space
{
	private:
      // program requirement - space pointer top
	  Space *top;
	  // program requirement - space pointer left
      Space *left;
	  // program requirement - space pointer right
      Space *right;
	  // program requirement - space pointer bottom
      Space *bottom;
	  // space_Identifier keeps track of which spaceLocation the player is in
      int space_Identifier;

    
	public:
	  // default constructor
      Boss();
	  // space text description for each unique spaceLocation
      virtual void space_Description();
	  // Space * Boss::space_Options  - enables the user
	  // to interact with the spaceLocation, make choices to go top/bottom/left/right
	  // and interact with items if available.
      virtual Space* space_Options(Player *);
      // setting Space pointers for top/bottom/left/right
	  virtual void setTop(Space *);
      virtual void setBottom(Space *);
      virtual void setLeft(Space *);
      virtual void setRight(Space *);
      // return player space/location
      virtual int getSpace_Identifier();
	  // default deconstructor - prevents memory leaks
	  virtual ~Boss();
};
#endif