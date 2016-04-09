/***************************************************************************//**
* @file     Salazar_Uriel_SavingsAccount.cpp
* @brief    MIDTERM
* @author   Uriel Salazar
* @date     April 2016
* @details  Member-function definitions for SavingsAccount class
*******************************************************************************/

// system libraries
#include <iomanip>
#include <string>
#include <stdexcept>

// user libraries
#include "Salazar_Uriel_SavingsAccount.h"

// constructor
SavingsAccount::SavingsAccount(
    const std::string &first, const std::string &last, unsigned long rNum,
    unsigned long long aNum, double bal, unsigned short cCount,
    unsigned short dCount, float prcnt)
    :Account(first, last, rNum, aNum, bal, cCount, dCount)
{
    setInterestPrcnt(prcnt);
}

// interestPrcnt; setter/getter
void SavingsAccount::setInterestPrcnt(float prcnt)
{
    interestPrcnt = prcnt;
}
float SavingsAccount::getInterestPrcnt() const
{
    return interestPrcnt;
}

// member function to calculate savings
void SavingsAccount::calculateSavings()
{
    balance *= pow(1 + interestPrcnt / 100 / 12, 12);
}

// member function to withdraw
void SavingsAccount::debit(double d)
{
    if (d > balance)
    {
        throw std::invalid_argument(
            "Insufficient funds for a withdrawal of this amount.");
    }
    balance -= d;
    debitCount++;
}

// overload insertion operator
std::ostream &operator<<(std::ostream &output, const SavingsAccount &savings)
{
    output << "Account #:\t" << savings.accountNumber << "\n";
    output << "Routing #:\t" << savings.routingNumber << "\n";
    output << "Type:\t\t" << "Savings\n";
    output << "Account Holder:\t" << savings.firstName
           << " " << savings.lastName << "\n";
    output << "Balance:\t" << "$" << std::fixed << std::setprecision(2)
           << savings.balance << "\n";
    output << "Interest Rate:\t" << savings.interestPrcnt << "%";

    return output;
}