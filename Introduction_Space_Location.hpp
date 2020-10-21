/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game-Introduction_Space_Location.hpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - Introduction_Space_Location.hpp
**                header file.  This is where the game starts- the player arrives in the wavy shores
**                seeking out Stilbo.
**
*********************************************************************************************************/
#include "Space.hpp"

#ifndef INTRODUCTION_SPACE_LOCATION_HPP
#define INTRODUCTION_SPACE_LOCATION_HPP

class Introduction_Space_Location : public Space
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
      Introduction_Space_Location();
	  // space text description for each unique spaceLocation
      virtual void space_Description();
	  // Space * Introduction_Space_Location::space_Options  - enables the user
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
	  virtual ~Introduction_Space_Location();
};
#endif