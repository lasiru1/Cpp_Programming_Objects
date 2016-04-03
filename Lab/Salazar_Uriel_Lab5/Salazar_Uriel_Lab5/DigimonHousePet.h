/***************************************************************************//**
* @file		DigimonHousePet.h
* @brief	Lab#5 (Handed out)
* @author	Uriel Salazar
* @date		April 2016
* @details	DigimonHousePet member-function declarations
*******************************************************************************/

// prevent multiple inclusions
#ifndef DIGIMONHOUSEPET_H
#define DIGIMONHOUSEPET_H

// user libraries
#include "HousePet.h"

// "DigimonHousePet" class declaration
class DigimonHousePet : public HousePet
{
public:
				DigimonHousePet(
				const std::string &, const std::string &, double, double,
				const std::string &, const std::string &, const std::string &);
	void		setAttack(const std::string &);
	std::string getAttack() const;
	void		setItem(const std::string &);
	std::string	getItem() const;
	void		setLevel(const std::string &);
	std::string	getLevel() const;
	void		printDigimonHousePet() const;
private:
	std::string attack;
	std::string item;
	std::string level;
};

#endif