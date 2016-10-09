/**
	LinkedList implementation file 
*/

#pragma once

#include "LinkedList.h"


/**
	Default constructor
	@post - The headPtr is set to nullptr and itemCount is initialized to 0.
*/
template<class ItemType>
LinkedList<ItemType>::LinkedList(){
	headPtr = nullptr;
	itemCount = 0;
} // End default constructor


/**
	Destructor - Calls the clear function, which calls the remove function until the Linked List is empty.
	@post - The first item in the list is removed until the Linked List is empty.
*/
template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} // End destructor


/**
	Function of type ItemType that returns the data for an element at a given position.
	@param position - An integer value that represents the position of the desired data.
	@return - The data of the Linked List's type, at the position given or NULL if no entry is available.
*/
template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const{
	bool ableToGet = (position >= 1) && (position <= itemCount);

	if (ableToGet){
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}

	return NULL;
} // End getEntry()


/**
	Void function that sets the data for the given position to a new 
	@param position - An integer value that represents the position of the data to be altered.
	@param newEntry - Of the list's type (ItemType), the new data to be set at the position. 
*/
template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry){
	bool ableToSet = (position >= 1) && (position <= itemCount + 1);

	if (ableToSet){
		Node<ItemType>* nodeToAlter = getNodeAt(position);
		nodeToAlter->setItem(newEntry);
	}
} // End setEntry()

/**
	Function that returns the node at the position passed in to the function.
	@param position - An integer value that represents the position in the list of the desired node
	@return - The node at the position passed into the function
*/
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
	if((position >= 1) && (position <= itemCount)){
		Node<ItemType>* currentPtr = headPtr;
		
		for (int before = 1; before < position; before++){
			currentPtr = currentPtr->getNext();
		}
		return currentPtr;
	}
} // End getNodeAt()

/**
	Void function that adds an entry to the Linked List at the position passed to it.
	@param newPosition - Integer value that represents the position at which the new entry is to be added.
	@param newEntry - Of ItemType that represents the data to be added to the list.
	@post - The new data is added to the Linked List at the position passed in.
*/
template<class ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

	if (newPosition == 1){
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else{
		Node<ItemType>* previousPtr = getNodeAt(newPosition - 1);
		newNodePtr->setNext(previousPtr->getNext());
		previousPtr->setNext(newNodePtr);
	} // End if

	itemCount++;
} // End insert

/**
	Bool function that removes an item from the Linked List at the passed in position.
	@param position - An integer value that represents the position of the item to remove
	@return - True if passed in position falls within the range of 1 and the item count,
				false if not
*/
template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);

	if (ableToRemove){
		Node<ItemType>* currentPtr = nullptr;

		if (position == 1){
			currentPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else{
			Node<ItemType>* previousPtr = getNodeAt(position - 1);
			currentPtr = previousPtr->getNext();
			previousPtr->setNext(currentPtr->getNext());
		} // End if

		currentPtr->setNext(nullptr);
		delete currentPtr;

		itemCount--;
	} // End if

	return ableToRemove;
}

/**
	Void function that reverses the linked list.
	@pre - The linked list is in its originial order.
	@post - The order of the linked list is reversed by altering the pointers to point at the previous
			node instead of the next and then setting the headPtr equal to resulting list. 
*/
template<class ItemType>
void LinkedList<ItemType>::reverse(){
	Node<ItemType>* previousPtr = NULL;
	Node<ItemType>* nextPtr = NULL; 
	Node<ItemType>* currentPtr = headPtr;
	
	while (currentPtr != NULL){
		nextPtr = currentPtr->getNext();
		currentPtr->setNext(previousPtr);  
		previousPtr = currentPtr; 
		currentPtr = nextPtr;
	}	

	headPtr = previousPtr;
}

/**
	Void function that calls the remove function until isEmpty returns true. 
	@post - The linked list is function isEmpty is called until the linked list is empty. 
*/
template<class ItemType>
void LinkedList<ItemType>::clear(){
	while (!isEmpty()){
		remove(1);
	}
} // End clear()

/**
	Interger function that returns the item count of the linked list. This item count represents
	the length of the linked list.
	@return - The itemCount of the linked list.  This does indicate the length of the linked list.
*/
template<class ItemType>
int LinkedList<ItemType>::getLength() const{
	return itemCount;
} // End getLength

/**
	Boolean function that returns whether the linked list is empty or not
	@return - True if the itemCount is equal to zero, false is not
*/
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
	return itemCount == 0;
} // End isEmpty()

/**
	Void function that outputs the linked list
	@post - The elements of the linked list are outputted to the user
*/
template<class ItemType>
void LinkedList<ItemType>::outputList() const{
	
	Node<ItemType>* currentPtr = headPtr;

	if (currentPtr == NULL){
		std::cout << "Empty list!\n";
	}
	
	while (currentPtr != NULL){
		std::cout << currentPtr->getItem() << " ";
		currentPtr = currentPtr->getNext();
	}	

	std::cout << std::endl;
} // End print()