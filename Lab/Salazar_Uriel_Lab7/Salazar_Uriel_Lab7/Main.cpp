/***************************************************************************//**
* @file     Main.cpp
* @brief    Lab#7 (Handed out)
* @author   Uriel Salazar
* @date     May 2016
* @details  Have a user create 5 vectors, fit each vector to it's size, save the
            sizes of the vectors to a priority queue, and output it's contents. 
* @include  Main.cpp
*******************************************************************************/

// system libraries
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;

// function prototypes
template <typename T>
void printVectors(const vector<T> &, const vector<T> &, const vector<T> &,
                  const vector<T> &, const vector<T> &);

// begin execution
int main()
{

    // declare variables
    vector<int>         vector1, vector2, vector3, vector4, vector5;
    priority_queue<int> vectorSizes;
    string              numbers;
    int                 value;

    // prompt user for input
    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter the integers for vector #" << i << ": ";
        getline(cin, numbers);
        istringstream stream(numbers);
        if(i == 1)
        {
            while (stream >> value)
            {
                vector1.push_back(value);
            }
        }
        else if(i == 2)
        {
            while (stream >> value)
            {
                vector2.push_back(value);
            }
        }
        else if (i == 3)
        {
            while (stream >> value)
            {
                vector3.push_back(value);
            }
        }
        else if (i == 4)
        {
            while (stream >> value)
            {
                vector4.push_back(value);
            }
        }
        else
        {
            while (stream >> value)
            {
                vector5.push_back(value);
            }
        }
    }

    // fit each vector to the size of it's elements
    vector1.shrink_to_fit();
    vector2.shrink_to_fit();
    vector3.shrink_to_fit();
    vector4.shrink_to_fit();
    vector5.shrink_to_fit();

    // function call to display all vectors and contents
    cout << endl << endl;
    printVectors(vector1, vector2, vector3, vector4, vector5);
    cout << endl << endl;

    // save vector sizes to the priority queue
    vectorSizes.push(vector1.size());
    vectorSizes.push(vector2.size());
    vectorSizes.push(vector3.size());
    vectorSizes.push(vector4.size());
    vectorSizes.push(vector5.size());

    // output priority queue
    cout << "Vector sizes from greatest to least: ";
    while(!vectorSizes.empty())
    {
        cout << vectorSizes.top();
        vectorSizes.pop();
        cout << ", ";
    }
    cout << endl << endl;

    // end execution
    return 0;
}

/***************************************************************************//**
* @fn       void printVectors(const vector<T> &v1, const vector<T> &v2,
                const vector<T> &v3, const vector<T> &v4, const vector<T> &v5)
* @brief    Outputs the contents of a vector using iteration
* @param    v1, v2, v3, v4, and v5, all of type vector
* @return   void
*******************************************************************************/
template <typename T>
void printVectors(const vector<T> &v1, const vector<T> &v2, const vector<T> &v3,
                  const vector<T> &v4, const vector<T> &v5)
{
    for (int j = 1; j <= 5; j++)
    {
        cout << "Vector #" << j << ": ";
        if (j == 1)
        {
            copy(v1.begin(), v1.end(), ostream_iterator<T>(cout, " "));
            cout << endl;
        }
        else if (j == 2)
        {
            copy(v2.begin(), v2.end(), ostream_iterator<T>(cout, " "));
            cout << endl;
        }
        else if (j == 3)
        {
            copy(v3.begin(), v3.end(), ostream_iterator<T>(cout, " "));
            cout << endl;
        }
        else if (j == 4)
        {
            copy(v4.begin(), v4.end(), ostream_iterator<T>(cout, " "));
            cout << endl;
        }
        else
        {
            copy(v5.begin(), v5.end(), ostream_iterator<T>(cout, " "));
            cout << endl;
        }
    } 
}