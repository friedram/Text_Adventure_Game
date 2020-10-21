/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- item.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - item.cpp - source
**                file.  This file enables the utilization of the games item forcelance and sword
**
*********************************************************************************************************/
#include "Item.hpp"

// default constructor
Item::Item(std::string descriptionz)
{
	
	this->descriptionz = descriptionz;

}

// getter for item description
std::string Item::getItem_Description()
{
	
	return descriptionz;

}

// default deconstructor
Item::~Item()
{

	
}