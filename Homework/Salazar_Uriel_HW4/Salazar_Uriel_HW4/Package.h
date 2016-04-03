/***************************************************************************//**
* @file		Package.h
* @brief	HW#5 (Package Inheritance Hierarchy)
* @author	Uriel Salazar
* @date		April 2016
* @details	Package member-function declarations
*******************************************************************************/

// prevent multiple inclusions
#ifndef PACKAGE_H
#define PACKAGE_H

// system libraries
#include <string>

// declare class "Package"
class Package
{
public:
	// default constructor
					Package();

	// constructor
					Package(const std::string &, const std::string &,
							const std::string &, const std::string &,
							unsigned int, const std::string &,
							const std::string &, const std::string &,
							const std::string &, unsigned int, double);

	// senderName; setter/getter
	void			setSenderName(const std::string &);
	std::string		getSenderName() const;

	// senderAddress; setter/getter
	void			setSenderAddresss(const std::string &);
	std::string		getSenderAddress() const;

	// senderCity; setter/getter
	void			setSenderCity(const std::string &);
	std::string		getSenderCity() const;

	// senderState; setter/getter
	void			setSenderState(const std::string &);
	std::string		getSenderState() const;

	// senderZip; setter/getter
	void			setSenderZip(unsigned int);
	unsigned int	getSenderZip() const;

	// recipientName; setter/getter
	void			setRecipientName(const std::string &);
	std::string		getRecipientName() const;

	// recipientAddress; setter/getter
	void			setRecipientAddress(const std::string &);
	std::string		getRecipientAddress() const;

	// recipientCity; setter/getter
	void			setRecipientCity(const std::string &);
	std::string		getRecipeintCity() const;

	// recipientState; setter/getter
	void			setRecipientState(const std::string &);
	std::string		getRecipientState() const;

	// recipientZip; setter/getter
	void			setRecipientZip(unsigned int);
	unsigned int	getRecipientZip() const;

	// weight; setter/getter
	void			setWeight(double);
	double			getWeight() const;

	// calculateCost
	double			calculateCost(double, double);

	// validateInt
	double			validateInt(double);

private:
	std::string		senderName;
	std::string		senderAddress;
	std::string		senderCity;
	std::string		senderState;
	unsigned int	senderZip;
	std::string		recipientName;
	std::string		recipientAddress;
	std::string		recipientCity;
	std::string		recipientState;
	unsigned int	recipientZip;
	double			weight;
	double			costPerOunce = 0.0594375;
};

#endif