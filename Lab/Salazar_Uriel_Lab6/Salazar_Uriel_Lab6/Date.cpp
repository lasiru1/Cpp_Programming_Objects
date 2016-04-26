#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

// initialize static member
const int Date::days[] = 
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// date constructor
Date::Date(int month, int day, int year)
{
    setDate(month, day, year);
}

// setDate function
void Date::setDate(int mm, int dd, int yy)
{
    if (mm >= 1 && mm <= 12)
    {
        month = mm;
    }
    else
    {
        throw invalid_argument("Month must be 1-12");
    }
    if(yy >= 1900 && yy <= 2100)
    {
        year = yy;
    }
    else
    {
        throw invalid_argument("Year must be >= 1900 and <= 2100");
    }
    if ((month == 2 && leapYear(year) && dd >= 1 && dd <= 29) ||
        (dd >= 1 && dd <= days[month]))
    {
        day = dd;
    }
    else
    {
        throw invalid_argument(
            "Day is out of range for current month and year");
    }
}

// overloaded prefix increment operator
Date &Date::operator++()
{
    helpIncrement();
    return *this;   // reference a return to create an lvalue
}

// overloaded postfix increment operator
Date Date::operator++(int)
{
    Date temp = *this;  // hold current state of object
    helpIncrement();

    return temp;
}

// add specified number of days to date
const Date &Date::operator+=(int additionalDays)
{
    for (int i = 0; i < additionalDays; ++i)
    {
        helpIncrement();
    }

    return *this;   // enables cascading
}

// if the year is a leap year, return true; otherwise return false
bool Date::leapYear(int testYear)
{
    if(testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const
{
    if(month == 2 && leapYear(year))
    {
        return testDay == 29;   // last day if Feb. of leap year
    }
    else
    {
        return testDay == days[month];
    }
}

int Date::getMonth() const
{
    return month;
}


// function to help increment the date
void Date::helpIncrement()
{
    if(!endOfMonth(day))
    {
        ++day;
    }
    else
    {
        if(month < 12)
        {
            ++month;
            day = 1;
        }
        else
        {
            ++year;
            month = 1;
            day = 1;
        }
    }
}

// overloaded output operator
ostream &operator<<(ostream &output, const Date &d)
{
    static string monthName[13] =
        {"", "January", "February", "March", "April", "May", "June", "July",
         "August", "September", "October", "November", "December"};
    output << monthName[d.month] << ' ' << d.day << ", " << d.year;

    return output;
}
