/**
	Virtual interface 
*/


#pragma once


template<class ItemType>
class ListInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
	virtual void insert(int newPosition, const ItemType& newEntry) = 0;
	virtual bool remove(int position) = 0;
	virtual void reverse() = 0;
	virtual void clear() = 0;
	virtual void outputList() const = 0;
	virtual ItemType getEntry(int position) const = 0;
	virtual void setEntry(int position, const ItemType& newEntry) = 0;
}; // End ListInterface
