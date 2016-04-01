/***************************************************************************//**
* @file		Main.cpp
* @brief	HW#3 (HugeInt Class)
* @author	Uriel Salazar
* @date		March 2016
* @include	Main.cpp, Hugeint.h, HugeInt.cpp
* @details	Use overloaded operators to utilize a wider range of integers
*******************************************************************************/

// system libraries
#include <iostream>

using namespace std;

// user libraries
#include "HugeInt.h"

// function prototypes
void displayAddition();
void displayMultiplication();
void displayRelationInequality();

// execution begins
int main()
{
	// declare variable
	unsigned short choice = 0;

	// print user menu
	cout << "1. Overloading the addition operator\n2. Overloading the "
			"multiplication operator\n3. Overloading the relational/equality "
			"operators\n\nEnter any other key to exit the program.\n\n"
			"Select a program to test: ";
	cin >> choice;

	if (choice == 1)
	{
		displayAddition();
	}
	else if (choice == 2)
	{
		displayMultiplication();
	}
	else if (choice == 3)
	{
		displayRelationInequality();
	}
	else
	{
		cout << "\n\n";
		return 0;
	}

	// execution ends
	cin.ignore();
	cin.get();
	return 0;
}

/***************************************************************************//**
* @fn		void displayAddition()
* @brief	Outputs test for addition with objects, integers, and strings
* @param	none
* @return	void
*******************************************************************************/
void displayAddition()
{
	// declare objects
	HugeInt n1(7654321);
	HugeInt n2(7891234);
	HugeInt n3("99999999999999999999999999999");
	HugeInt n4("1");
	HugeInt n5;

	// print objects
	cout << "\n\nn1 is: " << n1 << "\nn2 is: " << n2
		<< "\nn3 is: " << n3 << "\nn4 is: " << n4
		<< "\nn5 is: " << n5 << "\n\n";

	// print addition operations
	n5 = n1 + n2;
	cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

	cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

	n5 = n1 + 9;
	cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << endl;
	cout << "\n\n";
}

/***************************************************************************//**
* @fn		void displayMultiplication()
* @brief	Outputs test for multiplication with objects, integers, and strings
* @param	none
* @return	void
*******************************************************************************/
void displayMultiplication()
{
	// declare objects
	HugeInt n1(7654321);
	HugeInt n2(7891234);
	HugeInt n3("99999999999999999999999999999");
	HugeInt n4("1");
	HugeInt n5;

	// print objects
	cout << "\n\nn1 is: " << n1 << "\nn2 is: " << n2
		<< "\nn3 is: " << n3 << "\nn4 is: " << n4
		<< "\nn5 is: " << n5 << "\n\n";

	// print addition operations
	n5 = n1 * n2;
	cout << n1 << " * " << n2 << " = " << n5 << "\n\n";

	cout << n3 << " * " << n4 << "\n= " << (n3 * n4) << "\n\n";

	n5 = n1 * 9;
	cout << n1 << " * " << 9 << " = " << n5 << "\n\n";

	n5 = n2 * "10000";
	cout << n2 << " * " << "10000" << " = " << n5 << endl;
	cout << "\n\n";
}

/***************************************************************************//**
* @fn		void displayRelationInequality()	
* @brief	Outputs overloaded relational/equality operators for objects
* @param	none
* @return	void
*******************************************************************************/
void displayRelationInequality()
{
	// declare objects
	HugeInt n1(7654321);
	HugeInt n2(7891234);

	// print objects
	cout << "\n\nn1 is: " << n1 << "\nn2 is: " << n2 << "\n\n";

	// print relational and equality operators
	// "less than" operator
	if (n1 < n2)
	{
		cout << n1 << " is less than " << n2 << "\n\n";
	}
	else
	{
		cout << n1 << " is greater than " << n2 << "\n\n";
	}

	// "less than or equal to" operator
	if (n1 <= n2)
	{
		cout << n1 << " is less than or equal to " << n2 << "\n\n";
	}
	else
	{
		cout << n1 << " is greater than and not equal to " << n2 << "\n\n";
	}

	// "greater than" operator
	if (n1 > n2)
	{
		cout << n1 << " is greater than " << n2 << "\n\n";
	}
	else
	{
		cout << n1 << " is less than " << n2 << "\n\n";
	}

	// "greater than or equal to" operator
	if (n1 >= n2)
	{
		cout << n1 << " is greater than or equal to " << n2 << "\n\n";
	}
	else
	{
		cout << n1 << " is less than and not equal to " << n2 << "\n\n";
	}

	// "equal to" operator
	if (n1 == n2)
	{
		cout << n1 << " is equal to " << n2 << "\n\n";
	}
	else
	{
		cout << n1 << " is not equal to " << n2 << "\n\n";
	}

	// "not equal to" operator
	if (n1 != n2)
	{
		cout << n1 << " is not equal to " << n2 << "\n\n";
	}
	else
	{
		cout << n1 << " is equal to " << n2 << "\n\n";
	}
}