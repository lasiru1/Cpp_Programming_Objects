/***************************************************************************//**
* @file		OvernightPackage.cpp
* @brief	HW#5 (Package Inheritance Hierarchy)
* @author	Uriel Salazar
* @date		April 2016
* @details	OvernightPackage member-function definitions
*******************************************************************************/

// system libraries
#include <iostream>

// user libraries
#include "OvernightPackage.h"

// constructor
OvernightPackage::OvernightPackage(const std::string &sn, const std::string &sa,
	const std::string &sc, const std::string &ss, unsigned int sz,
	const std::string &rn, const std::string &ra, const std::string &rc,
	const std::string &rs, unsigned int rz, double w, double fpo)
	: Package(sn, sa, sc, ss, sz, rn, ra, rc, rs, rz, w)
{
	setFeePerOunce(fpo);
}

// set function for feePerOunce
void OvernightPackage::setFeePerOunce(double fpo)
{
	feePerOunce = fpo;
}

double OvernightPackage::getFeePerOunce() const
{
	return feePerOunce;
}

double OvernightPackage::calculateCost(double w)
{
	return (w * feePerOunce) + (w * costPerOunce);
}