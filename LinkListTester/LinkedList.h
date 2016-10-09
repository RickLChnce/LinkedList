/**
	LinkedList header file
*/


#pragma once


#include "ListInterface.h"
#include "Node.h"


template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to the first node in the chain
	int itemCount;			 // Current count of the list items
	Node<ItemType>* getNodeAt(int position) const;

public:
	LinkedList();
	virtual ~LinkedList(); // Destructor

	bool isEmpty() const;
	int getLength() const;
	void insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void reverse();
	void clear();
	void outputList() const;
	ItemType getEntry(int position) const;
	void setEntry(int position, const ItemType& newEntry);
};

#include "LinkedList.cpp"