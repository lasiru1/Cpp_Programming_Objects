#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"

template <typename NODETYPE>
class List
{
public:

	List() : firstPtr(nullptr), lastPtr(nullptr)
	{

	}

	List(const List<NODETYPE> &copy)
	{
		firstPtr = lastPtr = nullptr;

		ListNode<NODETYPE> *currentPtr = copy.firstPtr;

		while (currentPtr != nullptr)
		{
			insertAtBack(currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
	}

	~List()
	{
		if (!isEmpty())
		{
			std::cout << "Destroying nodes...\n";

			ListNode<NODETYPE> *currentPtr = firstPtr;
			ListNode<NODETYPE> *tempPtr;

			while (currentPtr != nullptr)
			{
				tempPtr = currentPtr;
				std::cout << tempPtr->data << ' ';
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			} // end while
		} //end if

		std::cout << "\nAll nodes destroyed\n\n";
	}

	void insertAtFront(const NODETYPE &value)
	{
		ListNode<NODETYPE> *newPtr = getNewNode(value);

		if (isEmpty())
			firstPtr = lastPtr = newPtr; //new list has only one node
		else
		{
			newPtr->nextPtr = firstPtr;
			firstPtr = newPtr;
		}
	}

	void insertAtBack(const NODETYPE &value)
	{
		ListNode<NODETYPE> *newPtr = getNewNode(value);

		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr; //new list has only one node
		}
		else
		{
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}

	bool removeFromFront(NODETYPE &value)
	{
		if (isEmpty())
			return false;
		else
		{
			ListNode<NODETYPE> *tempPtr = firstPtr;

			if (firstPtr == lastPtr)
				firstPtr = lastPtr = nullptr; //no nodes remain after removal
			else
				firstPtr = firstPtr->nextPtr;

			value = tempPtr->data;
			delete tempPtr;
			return true;
		}
	}

	bool removeFromBack(NODETYPE &value)
	{
		if (isEmpty())
			return false;
		else
		{
			ListNode<NODETYPE> *tempPtr = lastPtr;

			if (firstPtr == lastPtr)
				firstPtr = lastPtr = nullptr; //no nodes remain after removal
			else
			{
				ListNode<NODETYPE> *currentPtr = firstPtr;

				while (currentPtr->nextPtr != lastPtr)
					currentPtr = currentPtr->nextPtr; //move to next nodelastPtr = currentPtr;
				lastPtr = currentPtr;
				currentPtr->nextPtr = nullptr;
			}

			value = tempPtr->data;
			delete tempPtr;
			return true;
		}
	}

	bool isEmpty() const
	{
		return firstPtr == nullptr;
	}

	void print() const
	{
		if (isEmpty())
		{
			std::cout << "The list is empty\n\n";
			return;
		}

		ListNode<NODETYPE> *currentPtr = firstPtr;

		std::cout << "The list is: ";

		while (currentPtr != nullptr)
		{
			std::cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << "\n\n";
	}

private:
	ListNode<NODETYPE> *firstPtr;
	ListNode<NODETYPE> *lastPtr;

	ListNode<NODETYPE> *getNewNode(const NODETYPE &value)
	{
		return new ListNode<NODETYPE>(value);
	}
};

#endif