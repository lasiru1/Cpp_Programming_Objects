#ifndef LISTNODE_H
#define LISTNODE_H

template<typename NODETYPE> class List; //forward declaration of class list...kinda like a function prototype

template<typename NODETYPE>
class ListNode
{
	friend class List<NODETYPE>; //make list a friend

public:
	explicit ListNode(const NODETYPE &info) : data(info), nextPtr(nullptr)
	{

	}

	NODETYPE getData() const //; included in book. error?
	{
		return data;
	}

private:
	NODETYPE data;
	ListNode<NODETYPE> *nextPtr;
};

#endif

