/********************************************************************************************************
** Program Name:  Final Project - A Text-based Game- main.cpp
** Author:        Andrew Friedrich
** Date:          06/01/2019
** Description:   This file is the Final Project - A Text-based Game - inputValidation.cpp - source
**                file.  Ensures that user input won't generate errors
**
*********************************************************************************************************/

#include "inputValidation.hpp"

// updated my inputValidation based off inspiration from following:
// https://stackoverflow.com/questions/13212043/integer-input-validation-how
int inputValCheck2()
{

  int input;
  do
  {
    std::cout << "Please enter an integer based on the menu selection above" << std::endl;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
      std::cin.clear();
      std::cin.ignore(10, '\n');
    }
  }
  // change this to set range based on desired input
  while(std::cin.fail() || input < 1 || input > 2);

  return input;
}

int inputValCheck2a()
{

  int input;
  do
  {
    std::cout << "Please enter an integer based on the menu selection above" << std::endl;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
      std::cin.clear();
      std::cin.ignore(10, '\n');
    }
  }
  // change this to set range based on desired input
  while(std::cin.fail() || input < 1 || input > 2);

  return input;
}


int inputValCheck2b()
{

	int input;
	do
	{
		std::cout << "Please enter an integer based on the menu selection above" << std::endl;
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
			std::cin.clear();
			std::cin.ignore(10, '\n');
		}
	}
	// change this to set range based on desired input
	while (std::cin.fail() || input < 1 || input > 2);

	return input;
}

int inputValCheck3()
{

  int input;
  do
  {
    std::cout << "Please enter an integer based on the menu selection above" << std::endl;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
      std::cin.clear();
      std::cin.ignore(10, '\n');
    }
  }
  // change this to set range based on desired input
  while(std::cin.fail() || input < 1 || input > 3);

  return input;
}


int inputValCheck4()
{

  int input;
  do
  {
    std::cout << "Please enter an integer based on the menu selection above" << std::endl;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
      std::cin.clear();
      std::cin.ignore(10, '\n');
    }
  }
  // change this to set range based on desired input
  while(std::cin.fail() || input < 1 || input > 4);

  return input;
}

int inputValCheck5()
{

  int input;
  do
  {
    std::cout << "Please enter an integer based on the menu selection above" << std::endl;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
      std::cin.clear();
      std::cin.ignore(10, '\n');
    }
  }
  // change this to set range based on desired input
  while(std::cin.fail() || input < 1 || input > 5);

  return input;
}

int inputValCheck6()
{

	int input;
	do
	{
		std::cout << "Please enter an integer based on the menu selection above" << std::endl;
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
			std::cin.clear();
			std::cin.ignore(10, '\n');
		}
	}
	// change this to set range based on desired input
	while (std::cin.fail() || input < 1 || input > 6);

	return input;
}


int inputValCheck25x()
{

  int input;
  do
  {
    std::cout << "Please enter an integer based on the menu selection above" << std::endl;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
      std::cin.clear();
      std::cin.ignore(10, '\n');
    }
  }
  // change this to set range based on desired input
  while(std::cin.fail() || input < 2 || input > 25);

  return input;
}


int inputValCheckQuit()
{

  int input;
  do
  {
    std::cout << "Please enter an integer based on the menu selection above" << std::endl;
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cout << "That was not a correct entry, please enter a valid integer." << std::endl;
      std::cin.clear();
      std::cin.ignore(10, '\n');
    }
  }
  // change this to set range based on desired input
  while(std::cin.fail() || input < 1 || input > 4);

  return input;
}