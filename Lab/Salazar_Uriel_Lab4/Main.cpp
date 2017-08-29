/***************************************************************************//**
* @file		Main.cpp
* @brief	Lab#4 (Handed out)
* @author	Uriel Salazar
* @date		March 2016
* @details	Store & retrieve address info using a class w/ overloaded operators
*******************************************************************************/

// system libraries
#include <iostream>
#include <iomanip>

using namespace std;

// user libraries
#include "MailingLabel.h"

// execution begins
int main()
{
	// create object "userLabel"
	MailingLabel userLabel;

	// accept full mailing label from the user
	cout << "Enter the information as followed:" << endl;
	cout << "Separate each item with a space and omit cardinal direction.";
	cout << endl << endl;
	cout << "First Name, Last Name\nBuilding #, Street Name, Street Suffix"
			"\nCity, State (XX), Zip Code (xxxxx-xxxx)" << endl;
	cout << endl << endl;
	cin >> userLabel;	// overloaded operator called

	// output all data member in "MailingLabel" class
	cout << endl << endl;
	cout << setw(40) << "*****************************" << endl;
	cout << setw(34) << "Mailing Label		" << endl;
	cout << setw(40) << "*****************************" << endl;
	cout << endl;
	cout << userLabel;
	cout << endl << endl;

	cin.ignore();
	cin.get();
	return 0;
}