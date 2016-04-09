/***************************************************************************//**
* @file		Salazar_Uriel_Main.cpp
* @brief	MIDTERM
* @author	Uriel Salazar
* @date		April 2016
* @details	Create a bank account system using derived classes
* @include	Salazar_Uriel_Main.cpp, Salazar_Uriel_Account.h,
            Salazar_Uriel_Account.cpp, Salazar_Uriel_SavingsAccount.h,
            Salazar_Uriel_SavingsAccount.cpp, Salazar_Uriel_CheckingAccount.h,
            CheckingAccount.cpp
*******************************************************************************/

// system libraries
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// user libraries
#include "Salazar_Uriel_SavingsAccount.h"
#include "Salazar_Uriel_CheckingAccount.h"

// function prototypes
void	displayMenu();
double	validateNum();


// begin execution
int main()
{
    // declare variables
    string				fName, lName;
    double				savingsAmount = 0, checkingAmount = 0;
    double				debit, credit;
    unsigned long		saveRout = 0, checkRout = 0;
    unsigned long long	saveAccnt = 0, checkAccnt = 0;
    bool				savingsLock = false;
    bool				checkingLock = false;
    bool				exit = false;
    unsigned short		choice;
    unsigned short		account;

    // declare objects
    SavingsAccount mySavingsAccount(
        fName, lName, saveRout, saveAccnt, savingsAmount);
    CheckingAccount myCheckingAccount(
        fName, lName, checkRout, checkAccnt, checkingAmount);

    // print welcome message
    cout << "Welcome to the Online Bank Account System!" << endl;

    // repeat menu until user logs out
    do
    {
        // print menu
        displayMenu();

        // switch statement
        choice = validateNum();
        switch (choice)
        {
        case 1:
            // check for existing savings account
            if (savingsLock == false)
            {
                // prompt user for input
                cout << "\nPlease enter the account holder's first name: ";
                cin >> fName;
                cout << "Please enter the account holder's last name: ";
                cin >> lName;
                cout << "Please enter the opening deposit amount: $";
                saveRout = 830512984;
                saveAccnt = 54247985240763;
                savingsAmount = validateNum();

                // call setter functions for SavingsAccount object
                mySavingsAccount.setFirstName(fName);
                mySavingsAccount.setLastName(lName);
                mySavingsAccount.setRoutingNumber(saveRout);
                mySavingsAccount.setAccountNumber(saveAccnt);
                mySavingsAccount.setBalance(savingsAmount);
                mySavingsAccount.calculateSavings();

                // prevent multiple savings accounts
                cout << "\nYour Savings has been created." << endl;
                savingsLock = true;
            }
            else
            {
                cerr << "\a\nError: A Savings account already exists." << endl;
            }
            break;
        case 2:
            // check for existing checking account
            if (checkingLock == false)
            {
                // prompt user for input
                cout << "\nPlease enter the account holder's first name: ";
                cin >> fName;
                cout << "Please enter the account holder's last name: ";
                cin >> lName;
                cout << "Please enter the opening deposit amount: $";
                checkRout = 939647834;
                checkAccnt = 84392812178564;
                checkingAmount = validateNum();

                // call setter functions for SavingsAccount object
                myCheckingAccount.setFirstName(fName);
                myCheckingAccount.setLastName(lName);
                myCheckingAccount.setRoutingNumber(checkRout);
                myCheckingAccount.setAccountNumber(checkAccnt);

                // try & catch block to validate opening deposit amount
                try
                {
                    myCheckingAccount.setBalance(checkingAmount);
                }
                catch (invalid_argument &e)
                {
                    cerr << "\a\nError: " << e.what() << endl;
                }

                // check condition for opening a checking account
                if (myCheckingAccount.getBalance() >= 500)
                {
                    // prevent multiple checking accounts
                    cout << "\nYour Checking account has been created." << endl;
                    checkingLock = true;
                }
            }
            else
            {
                cerr << "\a\nError: A Checking account already exists." << endl;
            }
            break;
        case 3:
            // prompt user for input
            cout << "\n1. Savings\n"
                    "2. Checking\n\n"
                    "Select an account: ";
            account = validateNum();

            if (account == 1 && savingsLock == true)
            {
                cout << "\nEnter the amount you would like to deposit: $";
                credit = validateNum();
                mySavingsAccount.credit(credit);
                mySavingsAccount.calculateSavings();
            }
            else if (account == 1 && savingsLock == false)
            {
                cerr << "\a\nError: You do not have an open savings account."
                    << endl;
            }
            else if (account == 2 && checkingLock == true)
            {
                cout << "\nEnter the amount you would like to deposit: $";
                credit = validateNum();
                myCheckingAccount.credit(credit);
            }
            else if (account == 2 && checkingLock == false)
            {
                cerr << "\a\nError: You do not have an open checking account."
                     << endl;
            }
            else
            {
                cerr << "\a\nError: You have entered an invalid number."
                     << endl;
            }		
            break;
        case 4:
            // prompt user for input
            cout << "\n1. Savings\n"
                    "2. Checking\n\n"
                    "Select an account: ";
            account = validateNum();

            if (account == 1 && savingsLock == true)
            {
                cout << "\nEnter the amount you would like to withdraw: $";
                debit = validateNum();

                // try & catch block to validate withdraw amount
                try
                {
                    mySavingsAccount.debit(debit);
                }
                catch (invalid_argument &e)
                {
                    cerr << "\a\nError: " << e.what() << endl;
                }
            }
            else if (account == 1 && savingsLock == false)
            {
                cerr << "\a\nError: You do not have an open savings account."
                    << endl;
            }
            else if (account == 2 && checkingLock == true)
            {
                cout << "\nEnter the amount you would like to withdraw: $";
                debit = validateNum();

                // try & catch block to validate withdraw amount
                try
                {
                    myCheckingAccount.debit(debit);
                }
                catch (invalid_argument &e)
                {
                    cerr << "\a\nError: " << e.what() << endl;
                }
            }
            else if (account == 2 && checkingLock == false)
            {
                cerr << "\a\nError: You do not have an open checking account."
                     << endl;
            }
            else
            {
                cerr << "\a\nError: You have entered an invalid number."
                     << endl;
            }	
            break;
        case 5:
            // prompt user for input
            cout << "\n1. Savings\n"
                    "2. Checking\n\n"
                    "Select an account: ";
            account = validateNum();

            if (account == 1 && savingsLock == true)
            {
                cout << "\n" << mySavingsAccount << "\n";
            }
            else if (account == 1 && savingsLock == false)
            {
                cerr << "\a\nError: You do not have an open savings account."
                    << endl;
            }
            else if (account == 2 && checkingLock == true)
            {
                cout << "\n" << myCheckingAccount << "\n";
            }
            else if (account == 2 && checkingLock == false)
            {
                cerr << "\a\nError: You do not have an open checking account."
                     << endl;
            }
            else
            {
                cerr << "\a\nError: You have entered an invalid number."
                     << endl;
            }	
            break;
        case 6:
            // prompt user for input
            cout << "\n1. Savings\n"
                    "2. Checking\n\n"
                    "Select an account: ";
            account = validateNum();

            if (account == 1 && savingsLock == true)
            {
                cout << "\nDeposits:\t" << mySavingsAccount.getCreditCount();
                cout << "\nWithdrawals:\t" << mySavingsAccount.getDebitCount();
                cout << endl;
            }
            else if (account == 1 && savingsLock == false)
            {
                cerr << "\a\nError: You do not have an open savings account."
                    << endl;
            }
            else if (account == 2 && checkingLock == true)
            {
                cout << "\nDeposits:\t" << myCheckingAccount.getCreditCount();
                cout << "\nWithdrawals:\t" << myCheckingAccount.getDebitCount();
                cout << endl;
            }
            else if (account == 2 && checkingLock == false)
            {
                cerr << "\a\nError: You do not have an open checking account."
                     << endl;
            }
            else
            {
                cerr << "\a\nError: You have entered an invalid number."
                     << endl;
            }	
            break;
        case 7:
            exit = true;
            break;
        default:
            cerr << "\a\nError: You have entered an invalid key." << endl;
        }

    // check condition for ending execution
    } while (exit == false);

    // print goodbye message and pause execution
    cout << "\n\nThank you for using the Online Bank Account System! ";
    cin.clear();
    cin.ignore();
    cin.get();
    cout << endl;

    // end execution
    return 0;
}

/***************************************************************************//**
* @fn		void displayMenu()
* @brief	Prints the main menu for the switch statement within the program
* @param	none
* @return	void
*******************************************************************************/
void displayMenu()
{
    cout << endl;
    cout <<	"************************************\n"
            "             MAIN MENU              \n"
            "************************************\n"
            "1. Open a Savings account\n"
            "2. Open a Checking account\n"
            "3. Make a Deposit\n"
            "4. Make a Withdrawal\n"
            "5. View Balance\n"
            "6. View Transaction History\n"
            "7. Log Out\n" << endl;
    cout << "Please enter a transaction number: ";
}

/***************************************************************************//**
* @fn		double validateNum()
* @brief	Tests the input for any characters, negative values, etc.
* @param	none
* @return	number, a double
*******************************************************************************/
double validateNum()
{
    // declare variables
    bool	pass = false;
    double	number = 0;

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