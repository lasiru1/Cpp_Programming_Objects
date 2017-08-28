/***************************************************************************//**
* @file		SALAZAR_URIEL_Main.cpp
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	Create a virtual airport using polymorphism, containers, and queues
* @include	SALAZAR_URIEL_Main.cpp, SALAZAR_URIEL_Aircraft.h,
			SALAZAR_URIEL_Airliner.h, SALAZAR_URIEL_Helicopter.h,
			SALAZAR_URIEL_jet.h, SALAZAR_URIEL_Cargo.h, SALAZAR_URIEL_Blimp.h,
			SALAZAR_URIEL_Aircraft.cpp, SALAZAR_URIEL_Airliner.cpp,
			SALAZAR_URIEL_Helicopter.cpp, SALAZAR_URIEL_Jet.cpp,
			SALAZAR_URIEL_Cargo.cpp, SALAZAR_URIEL_Blimp.cpp
*******************************************************************************/

// system libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <queue>
#include <new>
#include <limits>
using namespace std;

// user libraries
#include "SALAZAR_URIEL_MenuException.h"
#include "SALAZAR_URIEL_NullAircraftException.h"
#include "SALAZAR_URIEL_LaunchException.h"
#include "SALAZAR_URIEL_Aircraft.h"
#include "SALAZAR_URIEL_Airliner.h"
#include "SALAZAR_URIEL_Helicopter.h"
#include "SALAZAR_URIEL_Jet.h"
#include "SALAZAR_URIEL_Cargo.h"
#include "SALAZAR_URIEL_Blimp.h"

// function prototypes
void	displayMainMenu();
void	displayAircraftMenu();
double	menuChoice(double);
double	validateNum();

// begin execution
int main()
{
	// declare variables
	unsigned short				actionCode = 0;
	unsigned short				priorityLevel;
	float						userChoice;
	bool						mainExit = false;
	bool						aircraftExit = false;
	bool						nullChoice = false;
	vector <Aircraft*>			dockedAircraft;
	vector <Aircraft*>			flyingAircraft;
	queue<Aircraft>	launchQueue;

	// print welcome message
	cout << "Welcome to The Virtual Airport Simulation Program!" << endl;

	// repeat menu until user logs out
	do
	{
		// print main menu
		displayMainMenu();

		// try & catch block for user's main menu input
		userChoice = validateNum();
		try
		{
			// check for valid action code
			actionCode = menuChoice(userChoice);

			// check for populated airport
			if ((actionCode == 2 || actionCode == 3 || actionCode == 4 ||
				actionCode == 5) && dockedAircraft.size() == 0)
			{
				nullChoice = true;
				throw NullAircraftException();
			}
			if (actionCode == 2 && dockedAircraft.size() < 3)
			{
				nullChoice = true;
				throw LaunchException();
			}
		}
		catch (MenuException &menuException)
		{
			cerr << "\a\nException Occurred: "
				 << menuException.what() << endl;
		}
		catch (NullAircraftException &nullAircraftException)
		{
			cerr << "\a\nException Occurred: "
				 << nullAircraftException.what() << endl;
		}
		catch (LaunchException &launchException)
		{
			cerr << "\n\nException Occurred: "
				 << launchException.what() << endl;
		}

		// switch statement
		switch (actionCode)
		{
		case 1:

			// repeat menu until user is done creating aircraft
			do
			{
				// print aircraft menu
				displayAircraftMenu();

				// generate a random number
				priorityLevel = rand() % 10 + 1;

				// try & catch block for user's aircraft menu input
				userChoice = validateNum();
				try
				{
					actionCode = menuChoice(userChoice);
				}
				catch (MenuException &menuException)
				{
					cerr << "\a\nException Occurred: "
						<< menuException.what() << endl;
				}
				catch (bad_alloc &memoryAllocationException)
				{
					cerr << "\a\nException Occurred: "
						 << memoryAllocationException.what() << endl;
				}

				// switch statement
				switch (actionCode)
				{
				case 1:

					// create new Airliner object
					dockedAircraft.push_back(
						new Airliner("Boeing 777-200LR Worldliner", 440, 47890,
									 554, 43100, 0.269, priorityLevel, 6, 28,
									 406));
					break;
				case 2:

					// create new Helicopter object
					dockedAircraft.push_back(
						new Helicopter("Mil Mi-8", 24, 196, 149, 14765, 1.015,
									   priorityLevel, 68, 12));
					break;
				case 3:

					// create new Jet object
					dockedAircraft.push_back(
						new Jet("Lockheed Martin F-16 Fighting Falcon", 1, 838,
								1215, 50240, 1.096, priorityLevel,
								"AIM-9 Sidewinder", 6));
					break;
				case 4:

					// create new Cargo object
					dockedAircraft.push_back(
						new Cargo("Antanov An-225 Mriya", 6, 79251,
								  497, 36089, 0.234, priorityLevel, 46000,
								  "Space Shuttle"));
					break;
				case 5:

					// create new Blimp object
					dockedAircraft.push_back(
						new Blimp("Airship Industries Skyship 600", 12, 180,
								  35, 100007, 0.075, priorityLevel, "DirecTV"));
					break;
				case 6:
					aircraftExit = true;
					break;
				}

			// condition for exiting while loop
			} while (aircraftExit == false);

			// reset "aircraftExit" bool
			aircraftExit = false;
			break;
		case 2:

		// check for invalid input
		if (nullChoice == false)
		{
			



		}

			break;
		case 3:



			break;
		case 4:



			break;
		case 5:



			break;
		case 6:

			// declare variable
			char secondUserChoice;

			do
			{
				// prompt user for input
				cout << "\nAre you sure you want to exit? (Y/N) ";
				cin >> secondUserChoice;

				// try & catch block
				try
				{
					 if (secondUserChoice != 'Y' && secondUserChoice != 'y'
						 && secondUserChoice != 'N' && secondUserChoice != 'n')
					 {
						 throw MenuException();
					 }
				}
				catch (MenuException &menuException)
				{
					cerr << "\a\nException Occurred: "
						 << menuException.what() << endl;
				}

			// condition for exiting loop
			} while (secondUserChoice != 'Y' && secondUserChoice != 'y'
					 && secondUserChoice != 'N' && secondUserChoice != 'n');
			
			if (secondUserChoice == 'Y' || secondUserChoice == 'y')
			{
				mainExit = true;
			}
			break;
		}

	// reset "nullChoice" bool
	nullChoice = false; 

	// check condition for exiting the program
	} while (mainExit == false);

	// print goodbye message and pause execution
	cout << "\nThank you for using The Virtual Airport Simulation Program! ";
	cin.clear();
	cin.ignore();
	cin.get();
	cout << endl;

	// end execution
	return 0;
}

/***************************************************************************//**
* @fn       void displayMainMenu()
* @brief    Prints the main menu for the switch statement within the program
* @param    none
* @return   void
*******************************************************************************/
void displayMainMenu()
{
    cout << endl;
    cout << "************************************\n"
            "             MAIN MENU              \n"
            "************************************\n"
            "1. Create Aircraft\n"
            "2. Launch Aircraft\n"
			"3. Land Aircraft\n"
            "4. View Docked Aircraft\n"
            "5. View Flying Aircraft\n"
            "6. Exit Program\n" << endl;
    cout << "Please enter an action code: ";
}

/***************************************************************************//**
* @fn       void displayAircraftMenu()
* @brief    Prints the aircraft menu for the switch statement within the program
* @param    none
* @return   void
*******************************************************************************/
void displayAircraftMenu()
{
    cout << endl;
    cout << "************************************\n"
            "              AIRCRAFT              \n"
            "************************************\n"
            "1. Airliner\n"
            "2. Helicopter\n"
            "3. Jet\n"
            "4. Cargo\n"
			"5. Blimp\n"
            "6. Exit Aircraft Menu\n" << endl;
    cout << "Please enter an action code: ";
}

/***************************************************************************//**
* @fn       double mainMenuChoice(double mChoice)
* @brief    exception handling for user input within the main menu
* @param    mChoice, a double
* @return   mChoice, a double
*******************************************************************************/
double menuChoice(double mChoice)
{
	if(mChoice == 0 || mChoice > 6)
	{
		throw MenuException();
	}

	return mChoice;
}

/***************************************************************************//**
* @fn       double validateNum()
* @brief    Tests the input for any characters and negative values
* @param    none
* @return   number, a double
*******************************************************************************/
double validateNum()
{
    // declare variables
    double	number = 0;
	bool	pass = false;

    // loop until the extraction operator yields a nonnegative integer
    do
    {
        cin >> number;
        if (cin.good() && number >= 0)
        {
            pass = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\a\nError: Invalid input, please reenter: ";
        }
    } while (!pass);

    return number;
}