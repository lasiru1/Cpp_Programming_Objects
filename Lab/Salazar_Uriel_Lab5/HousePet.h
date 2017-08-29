/***************************************************************************//**
* @file		HousePet.h
* @brief	Lab#5 (Handed out)
* @author	Uriel Salazar
* @date		April 2016
* @details	HousePet member-function declarations
*******************************************************************************/

// prevent multiple inclusions
#ifndef HOUSEPET_H
#define HOUSEPET_H

// system libraries
#include <string>

// "HousePet" class declaration
class HousePet
{
public:
				HousePet();
				HousePet(
				const std::string &, const std::string &, double, double);
	void		setName(const std::string &);
	std::string getName() const;
	void		setSpecies(const std::string &);
	std::string	getSpecies() const;
	void		setHeight(double);
	double		getHeight() const;
	void		setWeight(double);
	double		getWeight() const;
	void		printHousePet() const;
private:
	std::string name;
	std::string species;
	double height;
	double weight;
};

#endif