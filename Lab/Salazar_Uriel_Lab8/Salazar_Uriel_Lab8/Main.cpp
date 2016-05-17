/***************************************************************************//**
* @file     Main.cpp
* @brief    Lab#8 (Copying a List in Reverse Order)
* @author   Uriel Salazar
* @date     May 2016
* @details  Create two linked list objects; one that holds 10 characters and
			another that's a copy of the first in reverse order.
* @include	List.h, ListNode.h, Main.cpp
*******************************************************************************/

// system libraries
#include <iostream>
#include <string>
using namespace std;

// user libraries
#include "List.h"

// function prototypes
template<typename T>
void reverseLinkedList(List<T> &, List<T> &);

// begin execution
int main()
{
	// declare variables
	List<char> myList;
	List<char> reverseList;

	// fill "myList" with 10 characters
	for (char i = 'a'; i <= 'j'; i++)
	{
		myList.insertAtBack(i);
	}

	// display contents of "myList"
	myList.print();

	// function call to copy a list in reverse order
	reverseLinkedList(reverseList, myList);

	// display contents of "reverseList"
	cout << "Copying a list in reverse order...\n";
	reverseList.print();

	// end execution
	return 0;
}

/***************************************************************************//**
* @fn		void reverseLinkedList(List<T> &copy, List<T> &original)
* @brief	Makes a copy of myList onto reverseList in reverse order
* @param	copy of type List, original of type List
* @return	void
*******************************************************************************/
template<typename T>
void reverseLinkedList(List<T> &copy, List<T> &original)
{
	List<T> temp(original);
	T value;

	while (!temp.isEmpty())
	{
		temp.removeFromFront(value);
		copy.insertAtFront(value);
	}
}