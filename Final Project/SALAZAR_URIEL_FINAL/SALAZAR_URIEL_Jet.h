/***************************************************************************//**
* @file		SALAZAR_URIEL_Jet.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef JET_H
#define JET_H

// user libraries
#include "SALAZAR_URIEL_Aircraft.h"

// declare class "Jet"
class Jet : public Aircraft
{
public:
	// constructor
	Jet(std::string, unsigned short, unsigned int, unsigned short,
		unsigned int, float, unsigned short, std::string, unsigned short);

	// setMissileType; setter/getter
	void setMissileType(std::string mt)
	{
		missileType = mt;
	}
	std::string getMissileType()
	{
		return missileType;
	}

	// missileCount; setter/getter
	void setMissileCount(unsigned short mc)
	{
		missileCount = mc;
	}
	unsigned short getMissileCount()
	{
		return missileCount;
	}

	// virtual functions
	virtual void launch() override;
	virtual void land() override;

private:
	std::string		missileType;
	unsigned short	missileCount;
};

#endif