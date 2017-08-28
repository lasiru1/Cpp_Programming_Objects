/***************************************************************************//**
* @file     Main.cpp
* @brief    Lab#9 (Recursive Exponentiation)
* @author   Uriel Salazar
* @date     May 2016
* @details  Write a recursive function called power
* @include  Main.cpp
*******************************************************************************/

// system libraries
#include <iostream>
using namespace std;

// function prototypes
unsigned long long power(unsigned long long, unsigned long long);

// begin execution
int main()
{
    // declare variables
    unsigned long long base;
    unsigned long long exponent;
    unsigned long long product;

    // prompt user for input
    cout << "Enter the \"Base\" of the power function: ";
    cin >> base;
    cout << "Enter the \"Exponent\" of the power function: ";
    cin >> exponent;
    cout << endl;

    // for-loop to output visual representation of multiplication
    cout << "power(" << base << ", " << exponent << ") = ";
    if(exponent < 1)
    {
        cout << "1";
    }
    else
    {
        for (int i = 1; i <= exponent; i++)
        {
            if (i == exponent)
            {
                cout << base;
            }
            else
            {
                cout << base << " * ";
            }
        }
    }
    cout << endl << endl;

    // function call to calculate the product
    product = power(base, exponent);
    cout << "The value of the function is: " << product << endl << endl;

    // end execution
    return 0;
}

/***************************************************************************//**
* @fn       unsigned long long power(unsigned long long base,
            unsigned long long exponent)
* @brief    multiples the base by itself x amount of times, where x = exponent
* @param    base and exponent, both unsigned long long ints
* @return   base * power(base, (exponent - 1))
*******************************************************************************/
unsigned long long power(unsigned long long base, unsigned long long exponent)
{
    // return one if exponent is zero
    if(exponent == 0)
    {
        return 1;
    }

    // terminating condition
    if(exponent == 1)
    {
        return base;
    }

    // have the function call itself
    return base * power(base, (exponent - 1));
}