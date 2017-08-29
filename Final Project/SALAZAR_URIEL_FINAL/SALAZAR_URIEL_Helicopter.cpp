/***************************************************************************//**
* @file		SALAZAR_URIEL_Helicopter.cpp
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "SALAZAR_URIEL_Helicopter.h"

// constructor
Helicopter::Helicopter(std::string mn, unsigned short pc, unsigned int fc,
					   unsigned short as, unsigned int aa, float twr,
					   unsigned short pl, unsigned short mrd, unsigned short trd)
			: Aircraft(mn, pc, fc, as, aa, twr, pl)
{
	setMainRotorDiameter(mrd);
	setTailRotorDiameter(trd);
}

// virtual functions
void Helicopter::launch()
{
	std::cout << "Mil Mi-8 launched successfully from the airport!"
			  << std::endl;
}

void Helicopter::land()
{
	std::cout << "Mil Mi-8 landed safely at the airport!" << std::endl;
}