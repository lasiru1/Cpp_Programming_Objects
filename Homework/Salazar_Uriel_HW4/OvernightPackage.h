/***************************************************************************//**
* @file		OvernightPackage.h
* @brief	HW#5 (Package Inheritance Hierarchy)
* @author	Uriel Salazar
* @date		April 2016
* @details	OvernightPackage member-function declarations
*******************************************************************************/

// prevent multiple inclusions
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

// system libraries
#include <string>

// user libraries
#include "Package.h"

// declare class "Package"
class OvernightPackage : public Package
{
public:
	// constructor
					OvernightPackage(const std::string &, const std::string &,
									 const std::string &, const std::string &,
									 unsigned int, const std::string &,
									 const std::string &, const std::string &,
									 const std::string &, unsigned int, double,
									 double = 0.25);

	// feePerOunce; setter/getter
	void			setFeePerOunce(double);
	double			getFeePerOunce() const;

	// calculateCost
	double			calculateCost(double);

private:
	double			feePerOunce;
};

#endif