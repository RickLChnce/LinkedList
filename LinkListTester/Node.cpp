/**
	Node data structure implementation file
	Author: R.LaChance
*/

#include "Node.h"
#include <cstddef>


template<class ItemType>
Node<ItemType>::Node() : next(nullptr){
} // End default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr){
} // End constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr){
} // End constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem){
	item = anItem;
} // End setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr){
	next = nextNodePtr;
} // End setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const{
	return item;
} // End getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const{
	return next;
} // End getNext