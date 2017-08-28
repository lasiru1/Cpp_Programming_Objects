/***************************************************************************//**
* @file		SALAZAR_URIEL_Airliner.cpp
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "SALAZAR_URIEL_Airliner.h"

// constructor
Airliner::Airliner(std::string mn, unsigned short pc, unsigned int fc,
				   unsigned short as, unsigned int aa, float twr,
				   unsigned short pl, unsigned short first,
				   unsigned short business, unsigned short economy)
		: Aircraft(mn, pc, fc, as, aa, twr, pl)
{
	setFirstClassPassengerCount(first);
	setBusinessClassPassengerCount(business);
	setEconomyClassPassengerCount(economy);
}

// virtual functions
void Airliner::launch()
{
	std::cout << "Boeing 777-200LR Worldliner launched successfully from "
			  << "the airport!" << std::endl;
}

void Airliner::land()
{
	std::cout << "Boeing 777-200LR Worldliner landed safely at the airport!"
			  << std::endl;
}