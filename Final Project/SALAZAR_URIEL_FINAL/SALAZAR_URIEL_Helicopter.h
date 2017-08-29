/***************************************************************************//**
* @file		SALAZAR_URIEL_Helicopter.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef HELICOPTER_H
#define HELICOPTER_H

// user libraries
#include "SALAZAR_URIEL_Aircraft.h"

// declare class "Helicopter"
class Helicopter : public Aircraft
{
public:
	// constructor
	Helicopter(std::string, unsigned short, unsigned int, unsigned short,
		unsigned int, float, unsigned short, unsigned short, unsigned short);

	// mainRotorDiameter; setter/getter
	void setMainRotorDiameter(unsigned short mrd)
	{
		mainRotorDiameter = mrd;
	}
	unsigned short getMainRotorDiameter()
	{
		return mainRotorDiameter;
	}

	// tailRotorDiameter; setter/getter
	void setTailRotorDiameter(unsigned short trd)
	{
		tailRotorDiameter = trd;
	}
	unsigned short getTailRotorDiameter()
	{
		return tailRotorDiameter;
	}

	// virtual functions
	virtual void launch() override;
	virtual void land() override;

private:
	unsigned short mainRotorDiameter;
	unsigned short tailRotorDiameter;
};

#endif