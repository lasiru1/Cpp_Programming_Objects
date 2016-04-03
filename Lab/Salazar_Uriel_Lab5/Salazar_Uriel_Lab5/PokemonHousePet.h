/***************************************************************************//**
* @file		PokemonHousePet.h
* @brief	Lab#5 (Handed out)
* @author	Uriel Salazar
* @date		April 2016
* @details	PokemonHousePet member-function declarations
*******************************************************************************/

// prevent multiple inclusions
#ifndef POKEMONHOUSEPET_H
#define POKEMONHOUSEPET_H

// user libraries
#include "HousePet.h"

// "PokemonHousePet" class declaration
class PokemonHousePet : public HousePet
{
public:
				PokemonHousePet(
				const std::string &, const std::string &,double, double,
				const std::string &, const std::string &, const std::string &);
	void		setAttack(const std::string &);
	std::string getAttack() const;
	void		setItem(const std::string &);
	std::string	getItem() const;
	void		setType(const std::string &);
	std::string	getType() const;
	void		printPokemonHousePet() const;
private:
	std::string attack;
	std::string item;
	std::string type;
};

#endif