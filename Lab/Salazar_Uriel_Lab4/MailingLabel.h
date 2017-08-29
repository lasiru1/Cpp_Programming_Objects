/***************************************************************************//**
* @file		MailingLabel.h
* @brief	Lab#4 (Handed out)
* @author	Uriel Salazar
* @date		March 2016
* @details	MailingLabel declarations, definitions located in MailingLabel.cpp
*******************************************************************************/

#ifndef MAILINGLABEL_H
#define MAILINGLABEL_H

// class definition for "MailingLabel"
class MailingLabel
{
public:
	MailingLabel();	// default constructor
	MailingLabel(std::string, std::string, std::string, std::string,
					std::string, std::string, std::string, std::string,
					std::string);	// constructor

	// friend declarations
	friend std::ostream &operator<<(
		std::ostream &, const MailingLabel &);	// outputting all info
	friend std::istream &operator>>(
		std::istream &, MailingLabel &);	// inputting all info

private:
	std::string	firstName;
	std::string	lastName;
	std::string	buildingNumber;
	std::string	streetName;
	std::string	streetSuffix;
	std::string	city;
	std::string	state;
	std::string	zip;
	std::string	zipExtension;
};

#endif