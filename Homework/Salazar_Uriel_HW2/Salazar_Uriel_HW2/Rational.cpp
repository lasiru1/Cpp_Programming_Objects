/***************************************************************************//**
* @file		Rational.cpp
* @brief	HW#2 (Rational Class)
* @author	Uriel Salazar
* @date		March 2016
* @details	Rational class member-function definitions
*******************************************************************************/

// system libraries
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Rational.h"

// default constructor
Rational::Rational()
{
	numerator = 1;
	denominator = 2;
}

// initialize setRational
void Rational::setRational(int n, int d)
{
	setNumerator(n, d);
	setDenominator(n, d);
}

// set function for numerator
void Rational::setNumerator(int n, int d)
{
	// check for zero in the denominator
	if (d == 0)
	{
		throw std::invalid_argument(
			"dividing by 0 is undefined.\nDefault rational has been set.");
	}

	// call recursive function to find the greatest common divisor
	int gcd = findGCD(n, d);

	// divide numerator by GCD
	n /= gcd;
	numerator = n;
}

// get function for numerator
int Rational::getNumerator()
{
	return numerator;
}

// set function for denominator
void Rational::setDenominator(int n, int d)
{
	// call recursive function to find the greatest common divisor
	int gcd = findGCD(n, d);

	// divide denominator by GCD
	d /= gcd;
	denominator = d;
}

// get function for denominator 
int Rational::getDenominator()
{
	return denominator;
}

// a recursive function for finding the GCD
int	Rational::findGCD(int n, int d)
{
	// repeat until the remainder yields zero
	if (d == 0)
	{
		return n;
	}

	// obtain the remainder
	int r = n % d;

	// call the function again
	findGCD(d, r);
}

// function for obtaining the sum
void Rational::addition(int n1, int d1, int n2, int d2)
{
	// use cross multiplication to add the two fractions
	numerator = (n1 * d2) + (n2 * d1);
	denominator = (d1 * d2);

	// call recursive function to find the greatest common divisor
	int gcd = findGCD(numerator, denominator);

	// divide numerator & denominator by GCD
	numerator /= gcd;
	denominator /= gcd;
}

// function for obtaining the difference
void Rational::subtraction(int n1, int d1, int n2, int d2)
{
	// use cross multiplication to subtract the two fractions
	numerator = (n1 * d2) - (n2 * d1);
	denominator = (d1 * d2);

	// call recursive function to find the greatest common divisor
	int gcd = findGCD(numerator, denominator);

	// divide numerator & denominator by GCD
	numerator /= gcd;
	denominator /= gcd;
}

// function for obtaining the product
void Rational::multiplication(int n1, int d1, int n2, int d2)
{
	// multiply the numerators and denominators
	numerator = n1 * n2;
	denominator = d1 * d2;

	// call recursive function to find the greatest common divisor
	int gcd = findGCD(numerator, denominator);

	// divide numerator & denominator by GCD
	numerator /= gcd;
	denominator /= gcd;
}

// function for obtaining the quotient
void Rational::division(int n1, int d1, int n2, int d2)
{
	// multiply by the reciprocal of fraction2
	numerator = n1 * d2;
	denominator = d1 * n2;

	// call recursive function to find the greatest common divisor
	int gcd = findGCD(numerator, denominator);

	// divide numerator & denominator by GCD
	numerator /= gcd;
	denominator /= gcd;
}

// display rational in fraction notation
void Rational::printRational()
{
	std::cout << numerator << "/" << denominator;
}

// display rational in decimal notation
void Rational::printDecimal()
{
	// declare variables
	double dNumerator;
	double dDenominator;
	double dRational;

	// convert integer to double and divide
	dNumerator = numerator;
	dDenominator = denominator;
	dRational = dNumerator / dDenominator;

	// display decimal value
	std::cout << std::setprecision(3) << dRational << std::endl;
}