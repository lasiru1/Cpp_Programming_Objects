/***************************************************************************//**
* @file		Package.cpp
* @brief	HW#5 (Package Inheritance Hierarchy)
* @author	Uriel Salazar
* @date		April 2016
* @details	Package member-function definitions
*******************************************************************************/

// system libraries
#include <stdexcept>

// user libraries
#include "Package.h"

// default constructor
Package::Package()
{
	senderName			= "Joe Customer";
	senderAddress		= "123 N MyStreet Dr.";
	senderCity			= "Somewhereville";
	senderState			= "CA";
	senderZip			= 12345;
	recipientName		= "Bob Smith";
	recipientAddress	= "456 S Example Ave.";
	recipientCity		= "Populartown";
	recipientState		= "MA";
	recipientZip		= 67890;
	weight				= 160.0;
}

// constructor
Package::Package(const std::string &sn, const std::string &sa,
			const std::string &sc, const std::string &ss, unsigned int sz,
			const std::string &rn, const std::string &ra, const std::string &rc,
			const std::string &rs, unsigned int rz, double w)
{
	senderName			= sn;
	senderAddress		= sa;
	senderCity			= sc;
	senderState			= ss;
	senderZip			= sz;
	recipientName		= rn;
	recipientAddress	= ra;
	recipientCity		= rc;
	recipientState		= rs;
	recipientZip		= rz;
	weight				= w;
}

// set function for senderName
void Package::setSenderName(const std::string &sn)
{
	senderName = sn;
}

// get function for senderName
std::string Package::getSenderName() const
{
	return senderName;
}

// set function for senderAddress
void Package::setSenderAddresss(const std::string &sa)
{
	senderAddress = sa;
}

// get function for senderAddress
std::string Package::getSenderAddress() const
{
	return senderAddress;
}

// set function for senderCity
void Package::setSenderCity(const std::string &sc)
{
	senderCity = sc;
}

// get function for senderCity
std::string Package::getSenderCity() const
{
	return senderCity;
}

// set function for senderState
void Package::setSenderState(const std::string &ss)
{
	senderState = ss;
}

// get function for senderState
std::string Package::getSenderState() const
{
	return senderState;
}

// set function for senderZip
void Package::setSenderZip(unsigned int sz)
{
	if (sz <= 9999 || sz >= 99999)
	{
		senderZip = 12345;
		throw std::invalid_argument(
			"Sender zip code is invalid.\nDefault zip code set.");
	}
	senderZip = sz;
}

// get function for senderZip
unsigned int Package::getSenderZip() const
{
	return senderZip;
}

// set function for recipientName
void Package::setRecipientName(const std::string &rn)
{
	recipientName = rn;
}

// get function for recipientName
std::string Package::getRecipientName() const
{
	return recipientName;
}

// set function for recipientAddress
void Package::setRecipientAddress(const std::string &ra)
{
	recipientAddress = ra;
}

// get function for recipientAddress
std::string Package::getRecipientAddress() const
{
	return recipientAddress;
}

// set function for recipientCity
void Package::setRecipientCity(const std::string &rc)
{
	recipientCity = rc;
}

// get function for recipientCity
std::string Package::getRecipeintCity() const
{
	return recipientCity;
}

// set function for recipientState
void Package::setRecipientState(const std::string &rs)
{
	recipientState = rs;
}

// get function for recipientState
std::string Package::getRecipientState() const
{
	return recipientState;
}

//  set function for recipientZip
void Package::setRecipientZip(unsigned int rz)
{
	if (rz <= 9999 || rz >= 99999)
	{
		senderZip = 12345;
		throw std::invalid_argument(
			"Recipient zip code is invalid.\nDefault zip code set.");
	}
	recipientZip = rz;
}

// get function for recipientZip
unsigned int Package::getRecipientZip() const
{
	return recipientZip;
}

// set function for weight
void Package::setWeight(double w)
{
	weight = w;
}

// get function for weight
double Package::getWeight() const
{
	return weight;
}

// calculateCost
double Package::calculateCost(double w)
{
	double cost = w * costPerOunce;

	return cost;
}

// outputting all info
std::ostream &operator<<(std::ostream &output, const Package &stdPkg)
{
	output << "To:\n";
	output << "\n" << stdPkg.recipientName;
	output << "\n" << stdPkg.recipientAddress;
	output << "\n" << stdPkg.recipientCity << " " << stdPkg.recipientState
		   << " " << stdPkg.recipientZip;
	output << "\n\nFrom:\n";
	output << "\n" << stdPkg.senderName;
	output << "\n" << stdPkg.senderAddress;
	output << "\n" << stdPkg.senderCity << " " << stdPkg.senderState
		   << " " << stdPkg.senderZip;
	output << "\n\nWEIGHT: " << stdPkg.weight << " oz";

	return output;
}