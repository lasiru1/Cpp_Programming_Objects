/***************************************************************************//**
* @file		Main.cpp
* @brief	HW#2 (Rational Class)
* @author	Uriel Salazar
* @date		March 2016
* @details	performing arithmetic with fractions using Rational class.
*******************************************************************************/

// system libraries
#include <iostream>
#include "Rational.h"

using namespace std;

// function prototypes
void displayMenu();

// execution begins
int main()
{
	// declare variables
	int				n1;
	int				d1;
	int				n2;
	int				d2;
	Rational		fraction1;
	Rational		fraction2;
	Rational		fraction3;
	unsigned short	choice;
	char			again = 'N';

	// do-while loop for entire program
	do
	{
		// create new line if repeating the program
		if (again == 'y' || again == 'Y')
		{
			cout << endl;
		}

		// prompt user for input
		cout << "Enter numerator for 1st rational: ";
		cin >> n1;
		cout << "Enter denominator for 1st rational: ";
		cin >> d1;
		cout << "Enter numerator for 2nd rational: ";
		cin >> n2;
		cout << "Enter denominator for 2nd rational: ";
		cin >> d2;
		cout << endl;

		// create object fraction1
		try
		{
			fraction1.setRational(n1, d1);
		}
		catch (invalid_argument &e)
		{
			cerr << "\aERROR (Rational 1): " << e.what();
			cout << endl << endl;
		}

		// create object fraction2
		try
		{
			fraction2.setRational(n2, d2);
		}
		catch (invalid_argument &e)
		{
			cerr << "\aERROR (Rational 2): " << e.what();
			cout << endl << endl;
		}

		// print objects fraction1 & fraction2 in fraction form
		cout << "Rational 1: ";
		fraction1.printRational();
		cout << endl;
		cout << "Rational 2: ";
		fraction2.printRational();
		cout << endl << endl;

		// extract the numerator and denominator for arithmetic operations
		n1 = fraction1.getNumerator();
		d1 = fraction1.getDenominator();
		n2 = fraction2.getNumerator();
		d2 = fraction2.getDenominator();

		// print menu and prompt for input
		displayMenu();
		cin >> choice;

		// switch statement for arithmetic operations
		switch (choice)
		{
		case 1:
			fraction3.addition(n1, d1, n2, d2);
			cout << endl;
			cout << "The sum is: ";
			fraction3.printRational();
			cout << endl;
			cout << "Decimal conversion: ";
			fraction3.printDecimal();
			break;
		case 2:
			fraction3.subtraction(n1, d1, n2, d2);
			cout << endl;
			cout << "The difference is: ";
			fraction3.printRational();
			cout << endl;
			cout << "Decimal conversion: ";
			fraction3.printDecimal();
			break;
		case 3:
			fraction3.multiplication(n1, d1, n2, d2);
			cout << endl;
			cout << "The product is: ";
			fraction3.printRational();
			cout << endl;
			cout << "Decimal conversion: ";
			fraction3.printDecimal();
			break;
		case 4:
			fraction3.division(n1, d1, n2, d2);
			cout << endl;
			cout << "The quotient is: ";
			fraction3.printRational();
			cout << endl;
			cout << "Decimal conversion: ";
			fraction3.printDecimal();
			break;
		default:
			cout << endl;
			cout << "Goodbye!" << endl << endl;
			return 0;
		}

		// prompt user to repeat the program
		cout << endl << endl;
		cout << "Would you like to run the program again? (Y/N) ";
		cin >> again;
		if (again != 'y' && again != 'Y')
		{
			cout << endl;
			cout << "Goodbye!";
		}
		cout << endl;

	// check for condition to continue looping
	} while (again == 'Y' || again == 'y');

	cout << endl;
	return 0;
}

/***************************************************************************//**
* @fn		void displayMenu()	
* @brief	Outputs the main menu of the program to the user
* @param	none
* @return	void
*******************************************************************************/
void displayMenu()
{
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << endl;
	cout << "Press any other key to exit the program" << endl;
	cout << endl;
	cout << "Select an arithmetic operation: ";
}