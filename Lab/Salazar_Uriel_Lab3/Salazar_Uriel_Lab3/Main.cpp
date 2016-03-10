/***************************************************************************//**
* @file		Main.cpp
* @brief	Lab #3 (Enhancing class Date)
* @author	Uriel Salazar
* @date		March 2016
* @details	Increment the day in Date class and print during each iteration
*******************************************************************************/

// system libraries
#include <iostream>
#include "Windows.h"
#include "Date.h"	// include definition of class Date from Date.h
using namespace std;

// function prototypes
void clearScreen();
char* stringColor(int color = 7, char* message = "");

// execute main
int main()
{
	// declare variables
	unsigned int inputMonth;
	unsigned int inputDay;
	unsigned int inputYear;
	unsigned int cycles;

	// call Date class and create object "myDate"
	Date myDate;

	// prompt user for date
	cout << "Enter month number: ";
	cin >> inputMonth;
	cout << "Enter day number: ";
	cin >> inputDay;
	cout << "Enter year number: ";
	cin >> inputYear;

	for (int c = 0; c < 2; c++)
	{
		try
		{
			// set myDate with given values
			myDate.setDate(inputMonth, inputDay, inputYear);
		}
		catch (invalid_argument &e)
		{
			cout << endl;
			stringColor(12, "");
			cout << "Exception: " << e.what();
			stringColor();
			Sleep(3000);
			cout << endl;
		}
		if (inputMonth < 0 || inputMonth > 12)
		{
			inputMonth = 1;
		}
	}

	// print entered information
	cout << endl;
	cout << "Entered Date: ";
	stringColor(10, "");
	myDate.print();
	stringColor();
	cout << endl << endl;

	// prompt user for number of iterations
	cout << "Enter the number of days to increment: ";
	cin >> cycles;
	clearScreen();

	// test the function nextDay in a for-loop
	for (int i = 0; i < cycles; i++)
	{
		// call nextDay function
		myDate.nextDay();

		// print iteration
		myDate.print();
		cout << endl;
		Sleep(500);
	}

	// end main
	cout << endl;
	return 0;
}

/***************************************************************************//**
* @fn		void clearScreen()	
* @brief	Writes a space character to every cell on the screen
* @param	none
* @return	void
*******************************************************************************/
void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	// get the number of cells in the current buffer
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	// fill the entire buffer with spaces
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	// fill the entire buffer with the current colors and attributes
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	// move the cursor home
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

/***************************************************************************//**
* @fn		char stringColor(int color, char* message)
* @brief	Changes the color of the output console text
* @param	color an integer, message a string
* @return	message a sting (char*)
*******************************************************************************/
char* stringColor(int color, char* message)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	return message;
}