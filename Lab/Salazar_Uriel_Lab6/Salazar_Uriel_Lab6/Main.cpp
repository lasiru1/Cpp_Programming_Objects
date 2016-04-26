/***************************************************************************//**
* @file     Main.cpp
* @brief    Lab#6 (Payroll System Modification)
* @author   Uriel Salazar
* @date     April 2016
* @include  Employee.h, Employee.cpp, CommissionEmployee.h,
            CommissionEmployee.cpp, BasePlusCommissionEmployee.h,
            BasePlusCommissionEmployee.cpp, SalariedEmployee.h,
            SalariedEmployee.cpp, Date.h, Date.cpp, Main.cpp
* @details  Modify a payroll system to include the employee's birthday and add a
            $100 bonus if the current month is an employee's birth month.
*******************************************************************************/

// system libraries
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

// user libraries
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

int validateMonth();
void virtualViaReference(const Employee &, int);

int main()
{
    // declare variables
    int currentMonth;

    // prompt user for input
    cout << "Enter the current month: ";
    currentMonth = validateMonth();
    cout << endl;

    cout << fixed << setprecision(2);

    SalariedEmployee salariedEmployee(
        "John", "Smith", "111-11-1111", 10, 20, 1985, 800);
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "333-33-3333", 4, 8, 1988, 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "444-44-4444", 1, 13, 1967, 5000, .04, 300);

    // create vector of 3 base-class pointers
    vector <Employee *> employees(3);

    // initialize vector with employees
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;

    cout << "Employees processed polymorphically via dynamic binding:\n\n";

    cout << "Virtual function calls made off base-class references:\n\n";

    for (size_t i = 0; i < employees.size(); ++i)
    {
        virtualViaReference(*employees[i], currentMonth);
    }

    return 0;
}

int validateMonth()
{
    // declare variables
    bool    pass = false;
    int     month;

    // loop until the extraction operator yields a nonnegative integer
    do
    {
        cin >> month;
        if (cin.good() && month >= 0 && month <= 12)
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

    return month;
}

void virtualViaReference(const Employee &baseClassRef, int cMonth)
{
    baseClassRef.print();
    Date dateOfBirth = baseClassRef.getBirthDate();
    if(dateOfBirth.getMonth() == cMonth)
    {
        cout << "\nBirthday Bonus: $100.00\nearned $"
             << (baseClassRef.earnings() + 100) << "\n\n";
    }
    else
    {
        cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
    }
}