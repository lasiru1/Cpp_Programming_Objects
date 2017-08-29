/***************************************************************************//**
* @file		Date.h
* @brief	Lab #3 (Enhancing class Date)
* @author	Uriel Salazar
* @date		March 2016
* @details	Date class declarations, member-functions are defined in Date.cpp
*******************************************************************************/

// prevent multiple inclusions of header
#ifndef DATE_H
#define DATE_H

// class Date definition
class Date
{
public:
	static const unsigned int monthsPerYear = 12;
	Date(int = 1, int = 1, int = 0);		// default constructor
	void setDate(int, int, int);
	void print();
	void nextDay();
private:
	unsigned int month;
	unsigned int day;
	unsigned int year;
	unsigned int checkDay(int) const;
};

#endif