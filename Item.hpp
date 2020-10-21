/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- item.hpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - item.hpp - header
**                file.  This file enables the utilization of the games item forcelance and sword
**
*********************************************************************************************************/

#include "inputValidation.hpp"
#include <string>
#include <cstring>


#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
	private:
      // description of the item
  	  std::string descriptionz;
    
	public:
	  // default constructor
      Item(std::string);
      // item description
      std::string getItem_Description();
	  // default deconstructor
	  ~Item();

};
#endif