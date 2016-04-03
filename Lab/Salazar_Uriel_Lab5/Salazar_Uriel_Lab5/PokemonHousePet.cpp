/***************************************************************************//**
* @file		PokemonHousePet.cpp
* @brief	Lab#5 (Handed out)
* @author	Uriel Salazar
* @date		April 2016
* @details	PokemonHousePet member-function definitions
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "PokemonHousePet.h"

// constructor
PokemonHousePet::PokemonHousePet(
	const std::string &n, const std::string &spec, double h, double w,
	const std::string &atk, const std::string &itm, const std::string &t)
	: HousePet(n, spec, h, w)
{
	attack = atk;
	item = itm;
	type = t;
}

// set function for attack
void PokemonHousePet::setAttack(const std::string &atk)
{
	attack = atk;
}

// get function for name
std::string PokemonHousePet::getAttack() const
{
	return attack;
}

// set function for name
void PokemonHousePet::setItem(const std::string &itm)
{
	item = itm;
}

// get function for name
std::string PokemonHousePet::getItem() const
{
	return item;
}

// set function for name
void PokemonHousePet::setType(const std::string &t)
{
	type = t;
}

// get function for name
std::string PokemonHousePet::getType() const
{
	return type;
}

// print function for "PokemonHousePet"
void PokemonHousePet::printPokemonHousePet() const
{
	// invoke HousePet's print function
	HousePet::printHousePet();

	// print data members for PokemonHousePet
	std::cout <<
		"\nAttack:\t\t" << getAttack() << "\nItem:\t\t" << getItem()
		<< "\nType:\t\t" << getType();
}