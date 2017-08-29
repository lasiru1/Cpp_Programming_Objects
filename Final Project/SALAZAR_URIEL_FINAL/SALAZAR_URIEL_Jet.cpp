/***************************************************************************//**
* @file		SALAZAR_URIEL_Jet.cpp
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "SALAZAR_URIEL_Jet.h"

// constructor
Jet::Jet(std::string mn, unsigned short pc, unsigned int fc, unsigned short as,
		 unsigned int aa, float twr, unsigned short pl, std::string mt,
		 unsigned short mc) : Aircraft(mn, pc, fc, as, aa, twr, pl)
{
	setMissileType(mt);
	setMissileCount(mc);
}

// virtual functions
void Jet::launch()
{
	std::cout << "Lockheed Martin F-16 Fighting Falcon launched successfully "
			  << "from the airport!" << std::endl;
}

void Jet::land()
{
	std::cout << "Lockheed Martin F-16 Fighting Falcon landed safely at the "
			  << "airport!" << std::endl;
}