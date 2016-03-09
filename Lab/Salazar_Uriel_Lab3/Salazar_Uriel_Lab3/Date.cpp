/***************************************************************************//**
* @file		Date.cpp
* @brief	Lab #3 (Enhancing class Date)
* @author	Uriel Salazar
* @date		March 2016
* @details	Date class member-function definitions.
*******************************************************************************/

// system libraries
#include <iostream>
#include <stdexcept>
#include <array>
#include "Windows.h"
#include "Date.h"	// include definition of class Date from Date.h
using namespace std;

// default constructor
Date::Date(int m, int d,  int y)
{
	month = m;
	day = d;
	year = y;
}

// setter function
void Date::setDate(int m, int d, int y)
{
	year = y;
	if (m > 0 && m <= monthsPerYear)
	{
		month = m;
	}		
	else
	{
		throw invalid_argument(
			"month number must be 1-12.\nmonth variable set to 1 ");
	}
	day = checkDay(d);
}

// print Date in the format mm/dd/yyyy
void Date::print()
{
	cout << month << '/' << day << '/' << year;
}

// increment the day by one
void Date::nextDay()
{
	// initialize daysPerMonth array
	static const array<int, monthsPerYear + 1> daysPerMonth =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// increment the day by one
	day++;

	// reset the day to one if it falls out of range
	if (day > daysPerMonth[month])
	{
		day = 1;
		month++;
	}
	// reset the month to one if falls out of range
	if (month > monthsPerYear)
	{
		month = 1;
		year++;
	}
}

// validate correct day for given month/year
unsigned int Date::checkDay(int testDay) const
{
	// initialize daysPerMonth array
	static const array<int, monthsPerYear + 1> daysPerMonth =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (testDay > 0 && testDay <= daysPerMonth[month])
	{
		return testDay;
	}

	// check for leap year
	else if (month == 2 && testDay == 29 &&
		(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
	{
		return testDay;
	}
	else
	{
		throw invalid_argument(
			"Invalid day number for current month and year."
			"\nday variable set to 1 ");
	}
}