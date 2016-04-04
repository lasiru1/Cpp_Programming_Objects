/***************************************************************************//**
* @file		TwoDayPackage.h
* @brief	HW#5 (Package Inheritance Hierarchy)
* @author	Uriel Salazar
* @date		April 2016
* @details	TwoDayPackage member-function declarations
*******************************************************************************/

// prevent multiple inclusions
#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

// system libraries
#include <string>

// user libraries
#include "Package.h"

// declare class "Package"
class TwoDayPackage : public Package
{
public:
	// constructor
					TwoDayPackage(const std::string &, const std::string &,
								  const std::string &, const std::string &,
								  unsigned int, const std::string &,
								  const std::string &, const std::string &,
								  const std::string &, unsigned int, double,
								  unsigned short = 6);

	// flatFee; setter/getter
	void			setFlatFee(unsigned short);
	unsigned short	getFlatFee() const;

	// calculateCost
	double			calculateCost(double);

private:
	unsigned short	flatFee;
};

#endif