/***************************************************************************//**
* @file		SALAZAR_URIEL_Cargo.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef CARGO_H
#define CARGO_H

// user libraries
#include "SALAZAR_URIEL_Aircraft.h"

// declare class "Cargo"
class Cargo : public Aircraft
{
public:
	// constructor
	Cargo(std::string, unsigned short, unsigned int, unsigned short,
		  unsigned int, float, unsigned short, unsigned int, std::string);

	// cargoVolume; setter/getter
	void setCargoVolume(unsigned int volume)
	{
		cargoVolume = volume;
	}
	unsigned int getCargoVolume()
	{
		return cargoVolume;
	}

	// freightContent; setter/getter
	void setFreightContent(std::string freight)
	{
		freightContent = freight;
	}
	std::string getFreightContent()
	{
		return freightContent;
	}

	// virtual functions
	virtual void launch() override;
	virtual void land() override;

private:
	unsigned int	cargoVolume;
	std::string		freightContent;
};

#endif