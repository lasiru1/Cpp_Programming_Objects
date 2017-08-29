/*
Programmer:	Uriel Salazar
Created:	February 29, 2016
Purpose:	Homework #1 (Employee Class)
Included:	Main.cpp, Employee.cpp, Employee.h
*/

//System Libraries
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

//Begin Program
int main()
{
	//Declare variables
	string inputFirst;
	string inputLast;
	float inputSalary;
	float raise;

	//Prompt user for EMPLOYEE 1 input
	cout << "Enter EMPLOYEE 1's first name: ";
	cin >> inputFirst;
	cout << "Enter EMPLOYEE 1's last name: ";
	cin >> inputLast;
	cout << "Enter EMPLOYEE 1's monthly salary: $";
	cin >> inputSalary;

	//Call Employee class and create object "employeeOne"
	Employee employeeOne(inputFirst, inputLast, inputSalary);

	//Print "employeeOne"
	cout << "EMPLOYEE 1: " << employeeOne.getFirstName()
		 << " " << employeeOne.getLastName() << endl;
	cout << "Monthly Salary: $" << employeeOne.getMonthlySalary() << endl;
	employeeOne.displayAnnualSalary();
	cout << endl;

	//Prompt user for EMPLOYEE 2 input
	cout << "Enter EMPLOYEE 2's first name: ";
	cin >> inputFirst;
	cout << "Enter EMPLOYEE 2's last name: ";
	cin >> inputLast;
	cout << "Enter EMPLOYEE 2's monthly salary: $";
	cin >> inputSalary;

	//Call Employee class and create object "employeeTwo"
	Employee employeeTwo(inputFirst, inputLast, inputSalary);

	//Print "employeeTwo"
	cout << "EMPLOYEE 2: " << employeeTwo.getFirstName()
		 << " " << employeeTwo.getLastName() << endl;
	cout << "Monthly Salary: $" << employeeTwo.getMonthlySalary() << endl;
	employeeTwo.displayAnnualSalary();
	cout << endl;

	//Print all salaries after 10% raise
	cout << endl;
	employeeOne.displayRaisedSalary();
	cout << endl;
	employeeTwo.displayRaisedSalary();
	cout << endl;

	//End Program
	return 0;
}