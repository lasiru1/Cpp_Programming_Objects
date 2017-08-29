/***************************************************************************//**
* @file		SALAZAR_URIEL_Cargo.cpp
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "SALAZAR_URIEL_Cargo.h"

// constructor
Cargo::Cargo(std::string mn, unsigned short pc, unsigned int fc,
			 unsigned short as, unsigned int aa, float twr, unsigned short pl,
	unsigned int volume, std::string freight)
  : Aircraft(mn, pc, fc, as, aa, twr, pl)
{
	setCargoVolume(volume);
	setFreightContent(freight);	
}

// virtual functions
void Cargo::launch()
{
	std::cout << "Antonov An-225 Mriya launched successfully from the airport!"
			  << std::endl;
}

void Cargo::land()
{
	std::cout << "Antonov An-225 Mriya landed safely at the airport!"
			  << std::endl;
}