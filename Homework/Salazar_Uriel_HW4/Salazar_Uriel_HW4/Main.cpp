/***************************************************************************//**
* @file		Main.cpp
* @brief	HW#5 (Package Inheritance Hierarchy)
* @author	Uriel Salazar
* @date		April 2016
* @details	Use derived classes to create a three-option package calculator.
* @include	Main.cpp, Package.h, Package.cpp, TwoDayPackage.h,
			TwoDayPackage.cpp, OvernightPackage.h, OvernightPackage.cpp
*******************************************************************************/

// system libraries
#include <iostream>
using namespace std;

// user libraries
#include "Package.h"

// function prototypes
double validateInt(double);


// begin execution
int main()
{
	// declare variables
	string			sn, sa, sc, ss, rn, ra, rc, rs;
	unsigned int	sz, rz;

	// declare objects
	Package myStandardPackage;
	/*TwoDayPackage myTwoDayPackage;
	OvernightPackage myOvernightPackage;*/
	


	// end execution
	return 0;
}

/***************************************************************************//**
* @fn		double validateInt(double num)
* @brief	Tests the input for characters, negative integers, etc.
* @param	num, a double
* @return	num, a double
*******************************************************************************/
double validateInt(double num)
{
	// loop until the extraction operator yields a nonnegative integer
	while (!(cin >> num) || num < 1)
	{
		cerr << "\aERROR: Enter a positive value: ";
		cin.clear();
		cin.ignore(1e9, '\n');
	}

	return num;
}