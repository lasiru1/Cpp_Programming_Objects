/***************************************************************************//**
* @file		Salazar_Uriel_CheckingAccount.h
* @brief	MIDTERM
* @author	Uriel Salazar
* @date		April 2016
* @details	Member-function declarations for CheckingAccount class
*******************************************************************************/

// prevent multiple inclusions
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

// system libraries
#include <string>

// user libraries
#include "Salazar_Uriel_Account.h"

// declare class "CheckingAccount"
class CheckingAccount : public Account
{
public:
    // constructor
    CheckingAccount(const std::string &, const std::string &, unsigned long,
                    unsigned long long, double, unsigned short = 0,
                    unsigned short = 0, unsigned short = 35);

    // overdraftFee; setter/getter
    void			setOverdraftFee(unsigned short);
    unsigned short	getOverdraftFee() const;

    // balance; setter/getter
    void			setBalance(double);
    double			getBalance() const;

    // member function to deposit
    void			credit(double);

    // member function to withdraw
    void			debit(double);

    // overload insertion operator
    friend std::ostream &operator<<(std::ostream &, const CheckingAccount &);

private:
    double			balance;
    unsigned short	overdraftFee;
};

#endif