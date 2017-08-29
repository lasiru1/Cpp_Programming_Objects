/***************************************************************************//**
* @file     Salazar_Uriel_CheckingAccount.cpp
* @brief    MIDTERM
* @author   Uriel Salazar
* @date     April 2016
* @details  Member-function definitions for CheckingAccount class
*******************************************************************************/

// system libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

// user libraries
#include "Salazar_Uriel_CheckingAccount.h"

// constructor
CheckingAccount::CheckingAccount(
    const std::string &first, const std::string &last, unsigned long rNum,
    unsigned long long aNum, double bal, unsigned short cCount,
    unsigned short dCount, unsigned short fee)
    :Account(first, last, rNum, aNum, bal, cCount, dCount)
{
    setOverdraftFee(fee);
}

// overdraftFee; setter/getter
void CheckingAccount::setOverdraftFee(unsigned short fee)
{
    overdraftFee = fee;
}
unsigned short CheckingAccount::getOverdraftFee() const
{
    return overdraftFee;
}

// balance; setter/getter
void CheckingAccount::setBalance(double bal)
{
    if (bal < 500)
    {
        throw std::invalid_argument(
            "A minimum of $500.00 is needed to open a checking account.");
    }
    balance = bal;
}
double CheckingAccount::getBalance() const
{
    return balance;
}

// member function to deposit
void CheckingAccount::credit(double c)
{
    balance += c;
    creditCount++;
}

// member function to withdraw
void CheckingAccount::debit(double d)
{
    if (d > (balance + 300))
    {
        throw std::invalid_argument(
            "Overdraft amount is limited to $300.00, cannot make withdrawal.");
    }
    if (d > balance)
    {
        balance -= (d + 35);
        std::cout << "An overdraft fee of $35.00 has been debited "
                     "from your account." << std::endl;
        debitCount++;
    }
    else
    {
        balance -= d;
        debitCount++;
    }
}

// overload insertion operator
std::ostream &operator<<(std::ostream &output, const CheckingAccount &checking)
{
    output << "Account #:\t" << checking.accountNumber << "\n";
    output << "Routing #:\t" << checking.routingNumber << "\n";
    output << "Type:\t\t" << "Checking\n";
    output << "Account Holder:\t" << checking.firstName
        << " " << checking.lastName << "\n";
    output << "Balance:\t" << "$" << std::fixed << std::setprecision(2)
        << checking.balance << "\n";

    return output;
}