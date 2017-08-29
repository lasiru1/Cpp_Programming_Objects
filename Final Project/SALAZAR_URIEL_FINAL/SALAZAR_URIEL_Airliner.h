/***************************************************************************//**
* @file		SALAZAR_URIEL_Airliner.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef AIRLINER_H
#define AIRLINER_H

// user libraries
#include "SALAZAR_URIEL_Aircraft.h"

// declare class "Airliner"
class Airliner : public Aircraft
{
public:
	// constructor
	Airliner(std::string, unsigned short, unsigned int, unsigned short,
			 unsigned int, float, unsigned short, unsigned short, unsigned short,
			 unsigned short);

	// firstClassPassengerCount; setter/getter
	void setFirstClassPassengerCount(unsigned short first)
	{
		firstClassPassengerCount = first;
	}
	unsigned short getFirstClassPassengerCount()
	{
		return firstClassPassengerCount;
	}

	// businessClassPassengerCount; setter/getter
	void setBusinessClassPassengerCount(unsigned short business)
	{
		businessClassPassengerCount = business;
	}
	unsigned short getBusinessClassPassengerCount()
	{
		return businessClassPassengerCount;
	}

	// economyClassPassengerCount; setter/getter
	void setEconomyClassPassengerCount(unsigned short economy)
	{
		economyClassPassengerCount = economy;
	}
	unsigned short getEcomomyClassPassengerCount()
	{
		return economyClassPassengerCount;
	}

	// virtual functions
	virtual void launch() override;
	virtual void land() override;

private:
	unsigned short firstClassPassengerCount;
	unsigned short businessClassPassengerCount;
	unsigned short economyClassPassengerCount;
};

#endif