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

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <iostream>
#include <string>
#include <sstream>
#include "StringHelper.h"
#include "List.h"
#include "HashMapNode.h"
#include "HashMapIterator.h"

/**
@class HashMap
constructor example:\n
HashMap <std::string, MainStorageNode*>* storageMap = new HashMap <std::string, MainStorageNode*>;\n
Only takes keys of type std::string. Implemented as separate chaining with linked lists meaning
each bucket has an overflow linked list for key collisions.
@param T mapped type
*/
template <class T>
class HashMap
{
private:
	HashMapNode<T>** map;
	List<HashMapNode<T>*>* mapNodes;
	unsigned int itemCount;
	unsigned int bucketCount;
	unsigned int maxCount;
	unsigned int collisionCount;
	unsigned int replacementCount;
	unsigned int insertAttempt;
public:
	HashMap(unsigned int size);
	~HashMap();

	//class iterator : public HashMapIterator<T>;
	typedef HashMapIterator<T> iterator;
	//typedef const HashMapNode<T>* const_iterator;

	/** Returns a reference to the mapped value
	of the element with key equivalent to key.
	@param key the key of the element to find
	@return reference to the mapped value
	*/
	T at(std::string key);

	/** Checks if the container has no elements
	@return true if the container is empty, false otherwise
	*/
	bool empty() const;

	/** Returns the number of elements in the container
	@return The number of elements in the container. */
	unsigned int size() const;
	unsigned int max_size() const;
	unsigned int bucketsUsed() const;
	unsigned int collisions() const;
	unsigned int insertAttempts() const;

	/** Removes all elements from the container.
	*/
	void clear();

	/** Inserts element(s) into the container,
	if the container doesn't already contain an element
	with an equivalent key
	@pre None
	@post val is at the given key in the map
	@param key the key of the element to find
	@param val the element to insert
	@return true on success, false otherwise
	*/
	bool insert(std::string key, T val, unsigned int &operations);

	bool erase(std::string key, unsigned int &operations);
	bool erase(unsigned int hashId, unsigned int &operations);
	bool remove(T val, unsigned int &operations);

	/** Finds an element with key equivalent to key
	@param key the key of the element to find
	@return position in the bucket and
	-1 if bucket not initialized or key not found
	*/
	int find(std::string key, unsigned int &operations);
	int search(T val, unsigned int &operations);

	HashMapNode<T>* getHash(int hashId);
	bool existHash(int hashId);
	/** turns the linked list array into a linear
	linked list. this allows the hash table to be
	read with an iterator */
	void linearize(unsigned int &operations);

	iterator begin()
	{
		unsigned int operations = 0;
		linearize(operations);
		return iterator(mapNodes, 0);
	}
	iterator end()
	{
		unsigned int operations = 0;
		linearize(operations);
		return iterator(mapNodes, mapNodes->size());
	}

	//T& operator[] (const std::string key); // write
	//const T& operator[](const std::string key) const // read
};

//******************************************************
// List class constructors/destructors
//******************************************************
template <class T>
HashMap<T>::HashMap(unsigned int size) // Default Constructor
{
	map = new HashMapNode<T>*[size];
	mapNodes = new List<HashMapNode<T>*>;
	itemCount = 0;
	bucketCount = 0;
	maxCount = size;
	collisionCount = 0;
	replacementCount = 0;
	for (unsigned int i = 0; i < maxCount; i++)
		map[i] = nullptr;
}

template <class T>
HashMap<T>::~HashMap() { clear(); } // Destructor

//******************************************************
// List class implementation    
//******************************************************
template <class T>
T HashMap<T>::at(std::string key)
{
	unsigned int operations;
	bool flag = false;
	int hashId = find(key, operations);
	if (hashId > -1) {
		return map[hashId]->getValue();
	}
	throw std::runtime_error("Key " + key + " does not exist!");
}

template <class T>
bool HashMap<T>::empty() const
{
	if (itemCount == 0) return true;
	return false;
}

template <class T>
unsigned int HashMap<T>::size() const
{
	return itemCount;
}

template <class T>
unsigned int HashMap<T>::max_size() const
{
	return maxCount;
}

template <class T>
unsigned int HashMap<T>::bucketsUsed() const
{
	return bucketCount;
}

template <class T>
unsigned int HashMap<T>::collisions() const
{
	return collisionCount;
}


template <class T>
unsigned int HashMap<T>::insertAttempts() const
{
	return insertAttempt;
}

template <class T>
void HashMap<T>::clear()
{
	unsigned int i, operations;
	for (i = 0; i < maxCount; i++)
	{
		erase(i, operations);
	}
	itemCount = 0;
	bucketCount = 0;
}

template <class T>
bool HashMap<T>::insert(std::string key, T val, unsigned int &operations)
{
	operations += 2;
	insertAttempt++;
	bool flag = false;
	unsigned int j, k, hashId, InitId;
	k = StringHelper::hashBirthday(key);
	hashId = InitId = k % maxCount;
	// compute new index until we find next available space.
	for (j = 0; j < maxCount; j++) {
		operations++;
		hashId = (k + j * j) % maxCount;
		// if not occupied, then add new node
		if (map[hashId] == nullptr)
		{
			operations += 5;
			if (j > 0) {
				collisionCount++;
			}
			map[hashId] = new HashMapNode<T>(key, val, hashId);
			map[hashId]->setInitialId(InitId);
			flag = true;
			itemCount++;
			bucketCount++;
			break;
		}
	}
	return flag;
}

template <class T>
bool HashMap<T>::erase(std::string key, unsigned int &operations)
{
	bool flag = false;
	int hashId = find(key, operations);
	if (hashId > -1) {
		flag = erase(hashId, operations);
	}
	return flag;
}

template <class T>
bool HashMap<T>::erase(unsigned int hashId, unsigned int &operations) {
	bool flag = false;
	if (mapNodes[hashId]) {
		// linearize clear
		mapNodes->clear();
		// collisions reduced
		if (mapNodes[hashId]->isCollision()) {
			collisionCount--;
		}
		// delete bucket
		delete mapNodes[hashId]->getValue();
		delete mapNodes[hashId];
		mapNodes[hashId] = nullptr;
		bucketCount--;
		itemCount--;
		flag = true;
	}
	return flag;
}

template <class T>
bool HashMap<T>::remove(T val, unsigned int &operations)
{
	bool flag = false;
	int hashId = search(val, operations);
	if (hashId > -1) {
		flag = erase(hashId, operations);
	}
	return flag;
}

template <class T>
int HashMap<T>::find(std::string key, unsigned int &operations)
{
	/* this method will overwrite an existing key
	check if a key exists with the find method */
	unsigned int j, k, hashId;
	int pos = -1;
	k = StringHelper::hashBirthday(key);
	for (j = 0; j < maxCount; j++) {
		operations++;
		hashId = (k + j * j) % maxCount;
		// not null and key matches
		if (map[hashId] != nullptr && map[hashId]->getKey() == key)
		{
			operations += 5;
			pos = hashId;
			break;
		}
	}
	return pos;
}

template <class T>
int HashMap<T>::search(T val, unsigned int &operations)
{
	/* this method will overwrite an existing key
	check if a key exists with the find method */
	unsigned int j, k, hashId;
	int pos = -1;
	k = StringHelper::hashBirthday(key);
	for (j = 0; j < maxCount; j++) {
		operations++;
		hashId = (k + j * j) % maxCount;
		// not null and key matches
		if (map[hashId] != nullptr && map[hashId]->getValue() == val)
		{
			operations += 5;
			pos = hashId;
			break;
		}
	}
	return pos;
}

template <class T>
HashMapNode<T>* HashMap<T>::getHash(int hashId)
{
	return map[hashId];
}

template <class T>
bool HashMap<T>::existHash(int hashId)
{
	return map[hashId] == nullptr ? false : true;
}

template <class T>
void HashMap<T>::linearize(unsigned int &operations) {
	unsigned int i, n;
	n = max_size();
	mapNodes->clear();
	operations += 2;
	// loop through the entire hash table and look at the "buckets"
	for (i = 0; i < n; i++)
	{
		operations++;
		// hash table "buckets" might be null. check if they exist.
		if (existHash(i))
		{
			operations++;
			mapNodes->push_back(getHash(i));
		}
	}
}

/*
template <class T>
T& HashMap<T>::operator[] (const std::string key)
{
	//write
	try
	{
		erase (std::string key)
	}
	catch (const std::exception& e)
	{

	}
	return at (std::string key);
}

template <class T>
const T& HashMap<T>::operator[](const std::string key) const
{
	//read
	return at (std::string key);
}*/
#endif