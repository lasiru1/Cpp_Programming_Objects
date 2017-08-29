/***************************************************************************//**
* @file		HousePet.cpp
* @brief	Lab#5 (Handed out)
* @author	Uriel Salazar
* @date		April 2016
* @details	HousePet member-function definitions
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "HousePet.h"

// default constructor
HousePet::HousePet()
{
	name	= "Rex";
	species	= "Canis Familiaris";
	height	= 0.5;
	weight	= 32.9;
}

// constructor
HousePet::HousePet(const std::string &n, const std::string &spec,
														double h, double w)
{
	name	= n;
	species	= spec;
	height = h;
	weight = w;
}

// set function for name
void HousePet::setName(const std::string &n)
{
	name = n;
}

// get function for name
std::string HousePet::getName() const
{
	return name;
}

// set function for species
void HousePet::setSpecies(const std::string &spec)
{
	species = spec;
}

// get function for species
std::string HousePet::getSpecies() const
{
	return species;
}

// set function for height
void HousePet::setHeight(double h)
{
	height = h;
}

// get function for height
double HousePet::getHeight() const
{
	return height;
}

// set function for weight
void HousePet::setWeight(double w)
{
	weight = w;
}

// get function for weight
double HousePet::getWeight() const
{
	return weight;
}

// print function for class "HousePet"
void HousePet::printHousePet() const
{
	std::cout <<
		"Name:\t\t" << getName() << "\nSpecies:\t"
		<< getSpecies() << "\nHeight:\t\t" << getHeight() << " m"
		<< "\nWeight:\t\t" << getWeight() << " kg";
}