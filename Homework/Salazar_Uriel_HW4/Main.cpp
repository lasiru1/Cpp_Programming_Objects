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
#include <iomanip>
#include <limits>
using namespace std;

// user libraries
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

// function prototypes
double validateNum();

// begin execution
int main()
{
	// declare variables
	string			sn, sa, sc, ss, rn, ra, rc, rs;
	unsigned int	sz, rz;
	double			w;
	
	// prompt user for input
	cout << "Enter the sender's full name: "; 
	getline(cin, sn);
	cout << "Enter the sender's street address: ";
	getline(cin, sa);
	cout << "Enter the sender's city: ";
	cin >> sc;
	cout << "Enter the sender's state abbreviation: ";
	cin >> ss;
	cout << "Enter the sender's 5-digit zip code: ";
	sz = validateNum();
	cin.ignore();
	cout << "Enter the recipient's full name: ";
	getline(cin, rn);
	cout << "Enter the recipient's street address: ";
	getline(cin, ra);
	cout << "Enter the recipient's city: ";
	cin >> rc;
	cout << "Enter the recipient's state abbreviation: ";
	cin >> rs;
	cout << "Enter the recipient's 5-digit zip code: ";
	rz = validateNum();
	cout << "Enter the weight of the package in ounces: ";
	w = validateNum();

	// create & initialize objects
	Package				myStandardPackage(sn, sa, sc, ss, sz,
										  rn, ra, rc, rs, rz, w);
	TwoDayPackage		myTwoDayPackage(sn, sa, sc, ss, sz,
										rn, ra, rc, rs, rz, w);
	OvernightPackage	myOvernightPackage(sn, sa, sc, ss, sz,
										   rn, ra, rc, rs, rz, w);
	
	// throw exceptions for invalid zip codes ( base class Package only)
	try
	{
		myStandardPackage.setSenderZip(sz);
	}
	catch (invalid_argument &e)
	{
		cerr << "\a\n\nError: " << e.what();
	}
	try
	{
		myStandardPackage.setRecipientZip(rz);
	}
	catch (invalid_argument &e)
	{
		cerr << "\a\n\nError: " << e.what();
	}

	// display basic package information
	cout << "\n\n";
	cout << "**************************************\n"
		 << "         PACKAGE INFORMATION          \n"
		 << "**************************************";
	cout << "\n\n" << myStandardPackage;
	
	// display prices for each service
	cout << "\n\n";
	cout << "**************************************\n"
		 << "          STANDARD DELIVERY           \n"
	 	 << "**************************************";
	cout << "\n\n\t\t$" << fixed << setprecision(2)
		 << myStandardPackage.calculateCost(w);
	cout << "\n\n";
	cout << "**************************************\n"
		 << "           TWO-DAY DELIVERY           \n"
		 << "**************************************";
	cout << "\n\n\t\t$" << fixed << setprecision(2)
		 << myTwoDayPackage.calculateCost(w);
	cout << "\n\n";
	cout << "**************************************\n"
		 << "          OVERNIGHT DELIVERY          \n"
		 << "**************************************";
	cout << "\n\n\t\t$" << fixed << setprecision(2)
		 << myOvernightPackage.calculateCost(w);
	cout << "\n\n";
	cin.clear();
	cin.ignore();
	cin.get();

	// end execution
	return 0;
}

/***************************************************************************//**
* @fn		double validateNum()
* @brief	Tests the input for any characters, negative values, etc.
* @param	none
* @return	input, a double
*******************************************************************************/
double validateNum()
{
	// declare variables
	bool	valid = false;
	double	input = 0;

	// loop until the extraction operator yields a nonnegative integer
	do
	{
		std::cin >> input;
		if (std::cin.good() && input > 0)
		{
			valid = true;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\a\nError: Invalid input, please reenter: ";
		}
	} while (!valid);

	return input;
}