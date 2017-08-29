/***************************************************************************//**
* @file		HugeInt.h
* @brief	HW#3 (HugeInt Class)
* @author	Uriel Salazar
* @date		March 2016
* @details	HugeInt declarations, definitions located in HugeInt.cpp
*******************************************************************************/

// prevent multiple inclusions of header
#ifndef HUGEINT_H
#define HUGEINT_H

// system libraries
#include <iostream>

// class "HugeInt" declaration
class HugeInt
{
	friend std::ostream &operator<<(std::ostream &, const HugeInt &);

public:
	static const int digits = 30;	// maximum digits in a HugeInt

	HugeInt(long = 0);	// conversion/default constructor
	HugeInt(const std::string &);	// conversion constructor

	// addition operator; HugeInt + HugeInt
	HugeInt operator+(const HugeInt &) const;

	// addition operator; HugeInt + int
	HugeInt operator+(int) const;

	// addition operator;
	// HugeInt + string that represents large integer value
	HugeInt operator+(const std::string &) const;

	// multiplication operator; HugeInt * HugeInt
	HugeInt operator*(const HugeInt &) const;

	// multiplication operator; HugeInt * int
	HugeInt operator*(int) const;

	// multiplication operator;
	// HugeInt * string that represents large integer value
	HugeInt operator*(const std::string &) const;

	// "less than" operator; HugeInt < HugeInt
	bool operator<(const HugeInt &) const;

	// "less than" operator; HugeInt < int
	bool operator<(int) const;

	// "less than" operator;
	// HugeInt < string that represents large integer value
	bool operator<(const std::string &) const;

	// "less than or equal to" operator; HugeInt <= HugeInt
	bool operator<=(const HugeInt &) const;

	// "less than or equal to" operator; HugeInt <= int
	bool operator<=(int) const;

	// "less than or equal to" operator;
	// HugeInt <= string that represents large integer value
	bool operator<=(const std::string &) const;

	// "greater than" operator; HugeInt > HugeInt
	bool operator>(const HugeInt &) const;

	// "greater than" operator; HugeInt > int
	bool operator>(int) const;

	// "greater than" operator;
	// HugeInt > string that represents large integer value
	bool operator>(const std::string &) const;

	// "greater than or equal to" operator; HugeInt >= HugeInt
	bool operator>=(const HugeInt &) const;

	// "greater than or equal to" operator; HugeInt >= int
	bool operator>=(int) const;

	// "greater than or equal to" operator;
	// HugeInt >= string that represents large integer value
	bool operator>=(const std::string &) const;

	// "equal to" operator; HugeInt == HugeInt
	bool operator==(const HugeInt &) const;

	// "equal to" operator; HugeInt == int
	bool operator==(int) const;

	// "equal to" operator;
	// HugeInt == string that represents large integer value
	bool operator==(const std::string &) const;

	// "not equal to" operator; HugeInt != HugeInt
	bool operator!=(const HugeInt &) const;

	// "not equal to" operator; HugeInt != int
	bool operator!=(int) const;

	// "not equal to" operator;
	// HugeInt != string that represents large integer value
	bool operator!=(const std::string &) const;

private:
	short integer[digits];
};

#endif