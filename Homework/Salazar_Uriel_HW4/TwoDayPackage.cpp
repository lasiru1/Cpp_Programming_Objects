/***************************************************************************//**
* @file		TwoDayPackage.cpp
* @brief	HW#5 (Package Inheritance Hierarchy)
* @author	Uriel Salazar
* @date		April 2016
* @details	TwoDayPackage member-function definitions
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "TwoDayPackage.h"

// constructor
TwoDayPackage::TwoDayPackage(const std::string &sn, const std::string &sa,
	const std::string &sc, const std::string &ss, unsigned int sz,
	const std::string &rn, const std::string &ra, const std::string &rc,
	const std::string &rs, unsigned int rz, double w, unsigned short fFee)
	: Package(sn, sa, sc, ss, sz, rn, ra, rc, rs, rz, w)
{
	setFlatFee(fFee);
}

// set function for flatFee
void TwoDayPackage::setFlatFee(unsigned short fFee)
{
	flatFee = fFee;
}

unsigned short TwoDayPackage::getFlatFee() const
{
	return flatFee;
}

double TwoDayPackage::calculateCost(double w)
{
	return flatFee + (w * costPerOunce);
}