/***************************************************************************//**
* @file     Salazar_Uriel_Account.h
* @brief    MIDTERM
* @author   Uriel Salazar
* @date     April 2016
* @details  Member-function declarations for Account class
*******************************************************************************/

// prevent multiple inclusions
#ifndef ACCOUNT_H
#define ACCOUNT_H

// system libraries
#include <string>

// declare class "Account"
class Account
{
public:
    // default constructor
    Account();

    // constructor
    Account(const std::string &, const std::string &, unsigned long,
            unsigned long long, double, unsigned short, unsigned short);

    // firstName; setter/getter
    void                setFirstName(const std::string &);
    std::string         getFirstName() const;

    // lastName; setter/getter
    void                setLastName(const std::string &);
    std::string         getLastName() const;

    // routingNumber; setter/getter
    void                setRoutingNumber(unsigned long);
    unsigned long       getRoutingNumber() const;

    // accountNumber; setter/getter
    void                setAccountNumber(unsigned long long);
    unsigned long long  getAccountNumber() const;

    // balance; setter/getter
    void                setBalance(double);
    double              getBalance() const;

    // creditCount; setter/getter
    void                setCreditCount(unsigned short);
    unsigned short      getCreditCount() const;

    // debitCount; setter/getter
    void                setDebitCount(unsigned short);
    unsigned short      getDebitCount() const;

    // member function to deposit
    void                credit(double);

    // member function to withdraw
    void                debit(double);

protected:
    std::string         firstName;
    std::string         lastName;
    unsigned long       routingNumber;
    unsigned long long  accountNumber;
    double              balance;
    unsigned short      creditCount;
    unsigned short      debitCount;
};

#endif