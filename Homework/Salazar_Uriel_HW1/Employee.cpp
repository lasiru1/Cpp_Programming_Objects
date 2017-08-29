//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"

//Default constructor
Employee::Employee()
{
	firstName = "";
	lastName = "";
	monthlySalary = 0;
}

//Initialize setFirstName, setLastName, setMonthlySalary
Employee::Employee(std::string first, std::string last, float salary)
{
	setFirstName(first);
	setLastName(last);
	setMonthlySalary(salary);

}

//Set function for firstName
void Employee::setFirstName(std::string first)
{
	if (first.size() >= 25)
	{
		firstName = first.substr(0, 25);
		std::cerr << "ERROR: Name: \"" << first
			<< "\" exceeds the maximum length (25)." << std::endl;
		std::cerr << "Limiting firstName to first 25 characters..." << std::endl;
	}
	else
	{
		firstName = first;
	}
}

//Get functon for firstName
std::string Employee::getFirstName()
{
	return firstName;
}

//Set function for lastName
void Employee::setLastName(std::string last)
{
	if (last.size() >= 25)
	{
		firstName = last.substr(0, 25);
		std::cerr << "ERROR: Name: \"" << last
			<< "\" exceeds the maximum length (25)." << std::endl;
		std::cerr << "Limiting firstName to first 25 characters..." << std::endl;
	}
	else
	{
		lastName = last;
	}
}

//Get function for lastName
std::string Employee::getLastName()
{
	return lastName;
}

//Set function for monthlySalary
void Employee::setMonthlySalary(float salary)
{
	if (validateMonthlySalary(salary) == 0)
	{
		monthlySalary = 0;
	}
	else
	{
		monthlySalary = salary;
	}
}

//Get function for monthlySalary
float Employee::getMonthlySalary()
{
	return monthlySalary;
}

//Print function for yearlySalary
void Employee::displayAnnualSalary()
{
	yearlySalary = calculateYearlySalary(monthlySalary);
	std::cout << "Calculating yearly salary for: " << firstName
		<< " " << lastName << "..." << std::endl;
	std::cout << "Yearly Salary: $" << std::fixed << std::setprecision(2)
		<< yearlySalary << std::endl;
}

//Print function for raisedSalary
void Employee::displayRaisedSalary()
{
	raisedSalary = calculateRaisedSalary(yearlySalary, raise);
	std::cout << "***** 10% Raise *****" << std::endl;
	std::cout << firstName << " " << lastName << ": $" << std::fixed
		<< std::setprecision(2) << raisedSalary << std::endl;
}

//Validate function for monthlySalary
float Employee::validateMonthlySalary(float salary)
{
	if (salary < 0)
	{
		std::cerr << "ERROR: Salary cannot be less than $0.00." << std::endl;
		std::cerr << "monthlySalary varible set to 0." << std::endl;
		return 0;
	}
}

//Calculation function for yearlySalary
float Employee::calculateYearlySalary(float salary)
{
	yearlySalary = salary * 12;
	return yearlySalary;

}

//Calculation function for raidedSalary
float Employee::calculateRaisedSalary(float salary, float raise)
{
	raisedSalary = salary + (salary * raise);
	return raisedSalary;
}