/***************************************************************************//**
* @file		SALAZAR_URIEL_Blimp.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef BLIMP_H
#define BLIMP_H

// user libraries
#include "SALAZAR_URIEL_Aircraft.h"

// declare class "Blimp"
class Blimp : public Aircraft
{
public:
	// constructor
	Blimp(std::string, unsigned short, unsigned int, unsigned short,
		  unsigned int, float, unsigned short, std::string);

	// advertiser; setter/getter
	void setAdvertiser(std::string ad)
	{
		advertiser = ad;
	}
	std::string getAdvertiser()
	{
		return advertiser;
	}

	// virtual functions
	virtual void launch() override;
	virtual void land() override;

private:
	std::string	advertiser;
};

#endif