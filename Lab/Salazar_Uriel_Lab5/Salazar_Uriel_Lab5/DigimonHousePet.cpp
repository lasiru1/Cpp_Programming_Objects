/***************************************************************************//**
* @file		DigimonHousePet.cpp
* @brief	Lab#5 (Handed out)
* @author	Uriel Salazar
* @date		April 2016
* @details	DigimonHousePet member-function definitions
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "DigimonHousePet.h"

// constructor
DigimonHousePet::DigimonHousePet(
	const std::string &n, const std::string &spec, double h, double w,
	const std::string &atk, const std::string &itm, const std::string &lvl)
	: HousePet(n, spec, h, w)
{
	attack = atk;
	item = itm;
	level = lvl;
}

// set function for attack
void DigimonHousePet::setAttack(const std::string &atk)
{
	attack = atk;
}

// get function for name
std::string DigimonHousePet::getAttack() const
{
	return attack;
}

// set function for name
void DigimonHousePet::setItem(const std::string &itm)
{
	item = itm;
}

// get function for name
std::string DigimonHousePet::getItem() const
{
	return item;
}

// set function for name
void DigimonHousePet::setLevel(const std::string &lvl)
{
	level = lvl;
}

// get function for name
std::string DigimonHousePet::getLevel() const
{
	return level;
}

// print function for "PokemonHousePet"
void DigimonHousePet::printDigimonHousePet() const
{
	// invoke HousePet's print function
	HousePet::printHousePet();

	// print data members for PokemonHousePet
	std::cout <<
		"\nAttack:\t\t" << getAttack() << "\nItem:\t\t" << getItem()
		<< "\nLevel:\t\t" << getLevel();
}