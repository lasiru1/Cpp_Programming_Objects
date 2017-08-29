/***************************************************************************//**
* @file     Salazar_Uriel_Account.cpp
* @brief    MIDTERM
* @author   Uriel Salazar
* @date     April 2016
* @details  Member-function definitions for Account class
*******************************************************************************/

// system libraries
#include <stdexcept>

// user libraries
#include "Salazar_Uriel_Account.h"

// default constructor
Account::Account()
{
    firstName       = "Joe";
    lastName        = "Customer";
    routingNumber   = 123456789;
    accountNumber   = 12345678901234;
    balance         = 0;
    creditCount     = 0;
    debitCount      = 0;
}

// constructor
Account::Account(const std::string &first, const std::string &last,
                 unsigned long rNum, unsigned long long aNum, double bal,
                 unsigned short cCount = 0, unsigned short dCount = 0)
{
    firstName       = first;
    lastName        = last;
    routingNumber   = rNum;
    accountNumber   = aNum;
    balance         = bal;
    creditCount     = cCount;
    debitCount      = dCount;
}

// firstName; setter/getter
void Account::setFirstName(const std::string &first)
{
    firstName = first;
}
std::string Account::getFirstName() const
{
    return firstName;
}

// lastName; setter/getter
void Account::setLastName(const std::string &last)
{
    lastName = last;
}
std::string Account::getLastName() const
{
    return lastName;
}

// routingNumber; setter/getter
void Account::setRoutingNumber(unsigned long rNum)
{
    routingNumber = rNum;
}
unsigned long Account::getRoutingNumber() const
{
    return routingNumber;
}

// accountNumber; setter/getter
void Account::setAccountNumber(unsigned long long aNum)
{
    accountNumber = aNum;
}
unsigned long long Account::getAccountNumber() const
{
    return accountNumber;
}

// balance; setter/getter
void Account::setBalance(double bal)
{
    balance = bal;
}
double Account::getBalance() const
{
    return balance;
}

// creditCount; setter/getter
void Account::setCreditCount(unsigned short cCount)
{
    creditCount = cCount;
}
unsigned short Account::getCreditCount() const
{
    return creditCount;
}

// debitCount; setter/getter
void Account::setDebitCount(unsigned short dCount)
{
    debitCount = dCount;
}
unsigned short Account::getDebitCount() const
{
    return debitCount;
}

// member function to deposit
void Account::credit(double c)
{
    balance += c;
    creditCount++;
}

// member function to withdraw
void Account::debit(double d)
{
    balance -= d;
    debitCount++;
}