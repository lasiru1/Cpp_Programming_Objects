/************************************************************//**
* @file		Main.cpp
* @brief	Lab #1 (Shopping Cart Program)
* @author	Uriel Salazar
* @date		February 2016
****************************************************************/

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

//Gloabal Constants
const int MAX = 100;

//Function Prototypes
int userValidation(int);
void displayMenu();
int calculateSum(const int[], int);
void printReceipt(const int[], const string[], int, int);
void clearScreen();
char* colorString(int color = 7, char* message = "");

//Execute Program
int main()
{
	//Declare variables
	int * myPrices;
	myPrices = new int[MAX];
	string * myList;
	myList = new string[MAX];
	int choice = 1;
	char response;
	bool revert = false;
	bool exit = false;
	int itemCount;
	int sum;

	//Output title
	cout << setw(10) << colorString(2, "Welcome to VeggieShop.com!") << endl;
	colorString();
	cout << endl;


	//for-loop for gathering customer information
	for (int i = 0; choice != 0; i++)
	{
		if (revert == true)
		{
			i--;
		}
		revert = false;

		//Call display function & prompt user for input
		displayMenu();

		//Call user validation function
		choice = userValidation(choice);

		//Clear screen
		clearScreen();

		//Switch statement for the customer's choice
		switch(choice)
		{
			case 0:
				cout << "Are you finished adding items to your cart? (Y/N) ";
				cin >> response;
				if ((response == 'Y') || (response == 'y'))
				{
					exit = true;
				}
				else
				{
					choice = 1;
					revert = true;
				}
				break;
			case 1:
				myList[i] = "Soy Milk";
				myPrices[i] = 4;
				cout << "Soy Milk has been added to your cart! ";
				break;
			case 2:
				myList[i] = "Almond Milk";
				myPrices[i] = 5;
				cout << "Almond Milk has been added to your cart! ";
				break;
			case 3:
				myList[i] = "Banana";
				myPrices[i] = 1;
				cout << "A Banana has been added to your cart! ";
				break;
			case 4:
				myList[i] = "Pita Chips";
				myPrices[i] = 4;
				cout << "Pita Chips have been added to your cart! ";
				break;
			case 5:
				myList[i] = "Oatmeal";
				myPrices[i] = 3;
				cout << "Oatmeal has been added to your cart! ";
				break;
			case 6:
				myList[i] = "Avocado";
				myPrices[i] = 2;
				cout << "An Avocado has been added to your cart! ";
				break;
			case 7:
				myList[i] = "Tofu";
				myPrices[i] = 5;
				cout << "Tofu has been added to your cart! ";
				break;
			case 8:
				myList[i] = "Orange";
				myPrices[i] = 1;
				cout << "An Orange has been added to your cart! ";
				break;
			case 9:
				myList[i] = "Peanut Butter";
				myPrices[i] = 5;
				cout << "Peanut Butter has been added to your cart! ";
				break;
			case 10:
				myList[i] = "Hummus";
				myPrices[i] = 5;
				cout << "Hummus has been added to your cart! ";
				break;
		}
		//Record the number of items purchased
		itemCount = i;

		//Pause screen for 2 seconds
		if ((exit != true) && (revert != true))
		{
			Sleep(3000);
		}

		//Clear screen
		clearScreen();
	}

	//Call sum function
	sum = calculateSum(myPrices, itemCount);

	//Call print function
	printReceipt(myPrices, myList, itemCount, sum);

	//Delete memory
	delete[] myPrices;
	delete[] myList;

	//End Program
	cout << endl;
	return 0;
}

/************************************************************//**
* @fn		int userValidation(int number)	
* @brief	Validates that the user has enterd an integer from 0 to 10
* @param	number an integer
* @return	number an integer
****************************************************************/
int userValidation(int number)
{
	while (!(cin >> number) || number < 0 || number >= 11)
	{
		clearScreen();
		cerr << colorString(12, "ERROR: Please enter a valid item number. ");
		colorString();
		Sleep(3000);
		clearScreen();
		displayMenu();
		cin.clear();
		cin.ignore(1e9, '\n');
	}

	return(number);
}

/************************************************************//**
* @fn		void displayMenu()	
* @brief	Outputs the main menu of the program to the user
* @param	none
* @return	void
****************************************************************/
void displayMenu()
{
	cout << "1. Soy Milk $4" << endl;
	cout << "2. Almond Milk $5" << endl;
	cout << "3. Banana $1" << endl;
	cout << "4. Pita Chips $4" << endl;
	cout << "5. Oatmeal $3" << endl;
	cout << "6. Avocado $2" << endl;
	cout << "7. Tofu $5" << endl;
	cout << "8. Orange $1" << endl;
	cout << "9. Peanut Butter $5" << endl;
	cout << "10. Hummus $5" << endl << endl;
	cout << "0. Checkout" << endl;
	cout << endl;
	cout << "Enter the item number to add it to your cart: ";
}

/************************************************************//**
* @fn		int calculateSum(const int myPrices[], int items)	
* @brief	Add all of the elements within the dynamic array
* @param	myPrices a constant integer array, items an integer
* @return	total an integer
****************************************************************/
int calculateSum(const int myPrices[], int items)
{
	//Declare varaible
	int total = 0;

	//Loop through the array and add all elements
	for (int j = 0; j < items; j++)
	{
		total += myPrices[j];
	}

	return(total);
}

/************************************************************//**
* @fn		void printReceipt(const int myPrices[], const string myList[], int items, int sum)	
* @brief	Outputs the items ordered, their associated prices, and the sum of all items
* @param	myPrices a constant integer array, myList a constant string array,
			items an integer, sum an integer
* @return	void
****************************************************************/
void printReceipt(const int myPrices[], const string myList[], int items, int sum)
{
	cout << "Here is your order:" << endl << endl;

	//Loop through the arrays and print all elements
	for (int c = 0; c < items; c++)
	{
		cout << myList[c] << " $" << myPrices[c] << endl;
	}

	cout << endl;
	cout << "Your total is: $" << sum << endl;
	cout << colorString(2, "Thank you for using VeggieShop.com!") << endl;
	colorString();
}

/************************************************************//**
* @fn		void clearScreen()	
* @brief	Writes a space character to every cell on the screen and
			returns the cursor to (0, 0)
* @param	none
* @return	void
****************************************************************/
void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	//Get the number of cells in the current buffer
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	//Fill the entire buffer with spaces
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	//Fill the entire buffer with the current colors and attributes
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	//Move the cursor home
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

/************************************************************//**
* @fn		char colorString(int color	
* @brief	Changes the color of text until the default is called
* @param	color an integer, message a string
* @return	message a sting (char*)
****************************************************************/
char* colorString(int color, char* message)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	return message;
}