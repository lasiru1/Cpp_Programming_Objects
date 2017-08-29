/***************************************************************************//**
* @file		SALAZAR_URIEL_Blimp.cpp
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "SALAZAR_URIEL_Blimp.h"

// constructor
Blimp::Blimp(std::string mn, unsigned short pc, unsigned int fc,
			 unsigned short as, unsigned int aa, float twr, unsigned short pl,
			 std::string ad) : Aircraft(mn, pc, fc, as, aa, twr, pl)
{
	setAdvertiser(ad);
}

// virtual functions
void Blimp::launch()
{
	std::cout << "AI Skyship 600 launched successfully from the airport!"
			  << std::endl;
}

void Blimp::land()
{
	std::cout << "AI Skyship 600 landed safely at the airport!" << std::endl;
}