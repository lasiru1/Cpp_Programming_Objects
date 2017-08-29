/***************************************************************************//**
* @file		Rational.h
* @brief	HW#2 (Rational Class)
* @author	Uriel Salazar
* @date		March 2016
* @details	Rational class declarations, definitions are defined in Rational.cpp
*******************************************************************************/

#ifndef RATIONAL_H
#define RATIONAL_H

// class definition for Rational
class Rational
{
public:
			Rational();
	void	setRational(int, int);
	void	setNumerator(int, int);
	int		getNumerator();
	void	setDenominator(int, int);
	int		getDenominator();
	int		findGCD(int, int);
	void	addition(int, int, int, int);
	void	subtraction(int, int, int, int);
	void	multiplication(int, int, int, int);
	void	division(int, int, int, int);
	void	printRational();
	void	printDecimal();
private:
	int		numerator;
	int		denominator;
};

#endif