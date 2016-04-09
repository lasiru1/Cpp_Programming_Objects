/***************************************************************************//**
* @file     Salazar_Uriel_SavingsAccount.h
* @brief    MIDTERM
* @author   Uriel Salazar
* @date     April 2016
* @details  Member-function declarations for SavingsAccount class
*******************************************************************************/

// prevent multiple inclusions
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

// system libraries
#include <string>

// user libraries
#include "Salazar_Uriel_Account.h"

// declare class "SavingsAccount"
class SavingsAccount : public Account
{
public:
    // constructor
    SavingsAccount(const std::string &, const std::string &, unsigned long,
                   unsigned long long, double, unsigned short = 0,
                   unsigned short = 0, float = 1.04);

    // interestPrcnt; setter/getter
    void    setInterestPrcnt(float);
    float   getInterestPrcnt() const;

    // member function to calculate savings
    void    calculateSavings();

    // member function to withdraw
    void    debit(double);

    // overload insertion operator
    friend std::ostream &operator<<(std::ostream &, const SavingsAccount &);

private:
    float   interestPrcnt;
};

#endif