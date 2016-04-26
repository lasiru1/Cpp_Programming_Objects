#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee
{
public:
    Employee(const std::string &, const std::string &, const std::string &,
             int, int, int);
    virtual ~Employee() {}

    void setFirstName(const std::string &);
    std::string getFirstName() const;

    void setLastName(const std::string &);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string &);
    std::string getSocialSecurityNumber() const;

    void setBirthDate(int, int, int);
    Date getBirthDate() const;

    virtual double earnings() const = 0; //pure virtual
    virtual void print() const; //virtual
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    Date        birthDate;
};

#endif