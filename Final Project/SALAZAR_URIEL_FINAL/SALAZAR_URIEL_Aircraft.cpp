/***************************************************************************//**
* @file		SALAZAR_URIEL_Aircraft.cpp
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// user libraries
#include "SALAZAR_URIEL_Aircraft.h"

// constructor
Aircraft::Aircraft(std::string mn, unsigned short pc, unsigned int fc,
				   unsigned short as, unsigned int aa, float twr,
				   unsigned short pl)
{
	setModelName(mn);
	setPassengerCount(pc);
	setFuelCapacity(fc);
	setAverageSpeed(as);
	setAverageAltitude(aa);
	setThrustWeightRatio(twr);
	setPriorityLevel(pl);
}