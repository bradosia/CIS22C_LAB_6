/*
Branden Lee
CIS 22C
Fall 2017
Lab 6

Used Microsoft Visual Studio 2017
Windows SDK Version: 10.0.16299.0
Use SDK Version: 10.0.15063.0 for De Anza Computers
USE DOXYGEN COMPLIANT DOCUMENTATION
*/
#ifndef HASH_MAP_ITERATOR_H
#define HASH_MAP_ITERATOR_H

#include "List.h"
#include "HashMapNode.h"

/**
@class HashMapIterator
Used to iterate through a hash table.
@param T data type
*/
template <class T>
class HashMapIterator
{
private:
	List<HashMapNode<T>*>* mapNodes;
	int position;
	unsigned int operations;
public:
	HashMapIterator();
	HashMapIterator(List<HashMapNode<T>*>* ptr, int pos);
	~HashMapIterator();
	HashMapIterator<T> operator++() { HashMapIterator<T> i = *this; position++; return i; }
	HashMapIterator<T> operator++(int junk) { position++; return *this; }
	HashMapNode<T>& operator*() { return *((*mapNodes)[position]); }
	HashMapNode<T>* operator->() { return (*mapNodes)[position]; }
	bool operator==(const HashMapIterator<T>& rhs) { return position == rhs.position; }
	bool operator!=(const HashMapIterator<T>& rhs) { return position != rhs.position; }
};

//******************************************************
// CONSTRUCTORS/DESTRUCTORS    
//******************************************************
template <class T>
HashMapIterator<T>::HashMapIterator()
{
	mapNodes = nullptr;
	position = 0;
}

template <class T>
HashMapIterator<T>::HashMapIterator(List<HashMapNode<T>*>* ptr, int pos) {
	mapNodes = ptr;
	position = pos;
}

template <class T>
HashMapIterator<T>::~HashMapIterator() {}
#endif