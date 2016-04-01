/***************************************************************************//**
* @file		HugeInt.cpp
* @brief	HW#3 (HugeInt Class)
* @author	Uriel Salazar
* @date		March 2016
* @details	HugeInt class member-function and friend-function definitions
*******************************************************************************/

// system libraries
#include <cctype>

using namespace std;

// user libraries
#include "HugeInt.h"

//**************************** CONSTRUCTORS **********************************//

// default constructor
//conversion constructor that converts a long integer into a HugeInt object
HugeInt::HugeInt(long value)
{
	// initialize array to zero
	for (int i = 0; i < digits; i++)
	{
		integer[i] = 0;
	}

	// place digits of argument into array
	for (int j = digits - 1; value != 0 && j >= 0; j--)
	{
		integer[j] = value % 10;
		value /= 10;
	}
}

// conversion constructor that converts a character string representing a large
// integer into a HugeInt object
HugeInt::HugeInt(const string &number)
{
	// initialize array to zero
	for (int i = 0; i < digits; ++i)
	{
		integer[i] = 0;
	}

	// place digits of argument into array
	int length = number.size();

	for (int j = digits - length, k = 0; j < digits; ++j, ++k)
	{
		if(isdigit(number[k]))
		{
			integer[j] = number[k] - '0';
		}
	}
}

//******************************* ADDITION ***********************************//

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt &op2) const
{
	HugeInt temp;	// temporary result
	int carry = 0;

	for (int i = digits - 1; i >= 0; i--)
	{
		temp.integer[i] = integer[i] + op2.integer[i] + carry;

		// determine whether to carry a 1
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10;	// reduce to 0 - 9
			carry = 1;
		}
		else
		{
			carry = 0;	// no carry
		}
	}

	return temp;	// return copy of temporary object
}

// addition operator; HugeInt + int
HugeInt HugeInt::operator+(int op2) const
{
	// convert op2 to a HugeInt, then invoke operator+ for two HugeInt objects
	return *this + HugeInt(op2);
}

// addition operator;
// HugeInt + string that represent large integer value
HugeInt HugeInt::operator+(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke operator+ for two HugeInt objects
	return *this + HugeInt(op2);
}

//************************* MULTIPLICATION ***********************************//

// multiplication operator; HugeInt * HugeInt
HugeInt HugeInt::operator*(const HugeInt &op2) const
{
	HugeInt temp;
	int product;
	int carry = 0;
	int remainder = 0;

	for (int i = digits - 1; i >= 0; i--)
	{
		for (int j = digits - 1; j >= 0; j--)
		{
			product = integer[i] * op2.integer[j];
			product += carry;

			if (product >= 10)
			{
				carry = (product / 10);
				product %= 10;
			}
			else
			{
				carry = 0;
			}

			temp.integer[i + j - (digits - 1)] += product;

			if (temp.integer[i + j - (digits - 1)] >= 10)
			{
				remainder = (temp.integer[i + j - (digits - 1)] / 10);
				temp.integer[i + j - (digits - 1)] -= remainder * 10;
				carry += remainder;
			}
		}
	}

	return temp;
}

// multiplication operator; HugeInt * int
HugeInt HugeInt::operator*(int op2) const
{
	// convert op2 to a HugeInt, then invoke operator+ for two HugeInt objects
	return *this * HugeInt(op2);
}

// multiplication operator;
// HugeInt * string that represent large integer value
HugeInt HugeInt::operator*(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke operator+ for two HugeInt objects
	return *this * HugeInt(op2);
}

//******************************* RELATIONAL *********************************//

// "less than" operator; HugeInt < HugeInt
bool HugeInt::operator<(const HugeInt &op2) const
{
	for (int i = 0; i < digits; i++)
	{
		if (integer[i] < op2.integer[i])
		{
			return true;
		}
		else if (integer[i] > op2.integer[i])
		{
			return false;
		}
	}

	return false;
}

// "less than" operator; HugeInt < int
bool HugeInt::operator<(int op2) const
{
	return *this < HugeInt(op2);
}

// "less than" operator;
// HugeInt < string that represents large integer value
bool HugeInt::operator<(const std::string &op2) const
{
	return *this < HugeInt(op2);
}

// "less than or equal to" operator; HugeInt <= HugeInt
bool HugeInt::operator<=(const HugeInt &op2) const
{
	if (*this < op2 || *this == op2)
	{
		return true;
	}
		
	return false;
}

// "less than or equal to" operator; HugeInt <= int
bool HugeInt::operator<=(int op2) const
{
	return *this < HugeInt(op2);
}

// "less than or equal to" operator;
// HugeInt <= string that represents large integer value
bool HugeInt::operator<=(const std::string &op2) const
{
	return *this < HugeInt(op2);
}

// "greater than" operator; HugeInt > HugeInt
bool HugeInt::operator>(const HugeInt &op2) const
{
	for (int i = 0; i < digits; i++)
	{
		if (integer[i] > op2.integer[i])
		{
			return true;
		}
			
		else if (integer[i] < op2.integer[i])
		{
			return false;
		}
	}

	return false;
}

// "greater than" operator; HugeInt > int
bool HugeInt::operator>(int op2) const
{
	return *this < HugeInt(op2);
}

// "greater than" operator;
// HugeInt > string that represents large integer value
bool HugeInt::operator>(const std::string &op2) const
{
	return *this < HugeInt(op2);
}

// "greater than or equal to" operator; HugeInt >= HugeInt
bool HugeInt::operator>=(const HugeInt &op2) const
{
	if (*this > op2 || *this == op2)
	{
		return true;
	}
		
	return false;
}

// "greater than or equal to" operator; HugeInt >= int
bool HugeInt::operator>=(int op2) const
{
	return *this < HugeInt(op2);
}

// "greater than or equal to" operator;
// HugeInt >= string that represents large integer value
bool HugeInt::operator>=(const std::string &op2) const
{
	return *this < HugeInt(op2);
}

//******************************** EQUALITY **********************************//

// "equal to" operator; HugeInt == HugeInt
bool HugeInt::operator==(const HugeInt &op2) const
{
	for (int i = digits - 1; i >= 0; i--)
	{
		if (integer[i] != op2.integer[i])
		{
			return false;
		}
	}

	return true;
}

// "equal to" operator; HugeInt == int
bool HugeInt::operator==(int op2) const
{
	return *this < HugeInt(op2);
}

// "equal to" operator;
// HugeInt == string that represents large integer value
bool HugeInt::operator==(const std::string &op2) const
{
	return *this < HugeInt(op2);
}

// "not equal to" operator; HugeInt != HugeInt
bool HugeInt::operator!=(const HugeInt &op2) const
{
	for (int i = digits - 1; i >= 0; i--)
	{
		if (integer[i] != op2.integer[i])
		{
			return true;
		}
	}

	return false;
}

// "not equal to" operator; HugeInt != int
bool HugeInt::operator!=(int op2) const
{
	return *this < HugeInt(op2);
}

// "not equal to" operator;
// HugeInt != string that represents large integer value
bool HugeInt::operator!=(const std::string &op2) const
{
	return *this < HugeInt(op2);
}

//********************************* OUTPUT ***********************************//

// overloaded output operator
ostream& operator<<(ostream &output, const HugeInt &num)
{
	int i;

	for (i = 0; (num.integer[i] == 0) && (i <= HugeInt::digits); ++i)
	{
		;	// skip leading zeros
	}

	if(i == HugeInt::digits)
	{
		output << 0;
	}
	else
	{
		for (; i < HugeInt::digits; ++i)
		{
			output << num.integer[i];
		}
	}

	return output;
}