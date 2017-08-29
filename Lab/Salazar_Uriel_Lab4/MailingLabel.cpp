/***************************************************************************//**
* @file		MailingLabel.cpp
* @brief	Lab#4 (Handed out)
* @author	Uriel Salazar
* @date		March 2016
* @details	MailingLabel class member-function definitions
*******************************************************************************/


// system libraries
#include <iostream>
#include <string>
#include <iomanip>

// user libraries
#include "MailingLabel.h"

// default constructor
MailingLabel::MailingLabel()
{
	firstName = "Joe";
	lastName = "Customer";
	buildingNumber = "123";
	streetName = "MyStreet";
	streetSuffix = "Dr.";
	city = "Somewhereville";
	state = "CA";
	zip = "12345";
	zipExtension = "6789";
}

// constructor
MailingLabel::MailingLabel(std::string fName, std::string lName, std::string bldg,
	std::string sName, std::string suffix, std::string cty,
	std::string st, std::string z, std::string zExt)
{
	firstName = fName;
	lastName = lName;
	buildingNumber = bldg;
	streetName = sName;
	streetSuffix = suffix;
	city = cty;
	state = st;
	zip = z;
	zipExtension = zExt;
}


// outputting all info
std::ostream &operator<<(std::ostream &output, const MailingLabel &label)
{
	output << "\t\t" << label.firstName << " " << label.lastName;
	output << std::endl;
	output << "\t\t" << label.buildingNumber << " " << label.streetName << " "
		<< label.streetSuffix;
	output << std::endl;
	output << "\t\t" << label.city << " " << label.state << " " << label.zip
		<< "-" << label.zipExtension;

	return output;
}

// inputting all info
std::istream &operator>>(std::istream &input, MailingLabel &label)
{
	input >> std::setw(15) >> label.firstName;	// sets firstName
	input.ignore();
	input >> std::setw(25) >> label.lastName;	// sets lastName
	input.ignore();
	input >> std::setw(6) >> label.buildingNumber;	// sets buildingNumber
	input.ignore();
	input >> std::setw(20) >> label.streetName;	// sets streetName
	input.ignore();
	input >> std::setw(8) >> label.streetSuffix;	// sets streetSuffix
	input.ignore();
	input >> std::setw(20) >> label.city;	// sets city
	input.ignore();
	input >> std::setw(2) >> label.state;	// sets state
	input.ignore();
	input >> std::setw(5) >> label.zip;	// sets zip
	input.ignore();
	input >> std::setw(4) >> label.zipExtension;	// sets zipExtension

	return input;
}