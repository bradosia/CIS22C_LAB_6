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

#include "commandLineUI.h"

using namespace std;

void CommandLineUI::enterLoop()
{
	unsigned int maxItems = 10;
	bool menuFlag = true;
	// welcome and setup
	cout << "Welcome to the name and birthday hash table! " << endl;
	HashMap <NodeMain*> *storageMapPtr = new HashMap <NodeMain*>(maxItems);
	List<NodeMain*> *mainList = new List<NodeMain*>();
	std::string inputPath, inputBirthday, inputRetry;
	unsigned int i, n, operations;
	operations = 0;
	// prompt for input file and parse as BST
	cout << "Enter the path for input file: " << endl;
	getline(cin, inputPath);
	bool flag0 = FileIO::fileToList(inputPath, mainList);
	if (flag0)
	{
		// insert into the hash table
		n = mainList->size();
		for (i = 0; i < n; i++) {
			storageMapPtr->insert((*mainList)[i]->getBirthday(), (*mainList)[i], operations);
		}
		// display table stats
		displayHashTable(storageMapPtr);
		// prompt user to find birthday
		while (menuFlag) {
			cout << "Enter a birthday to find: " << endl;
			getline(cin, inputBirthday);
			birthdayFind(storageMapPtr, inputBirthday);
			cout << "Would you like to find another birthday?" << endl
				<< "1. Yes" << endl
				<< "2. No and Quit" << endl;
			getline(cin, inputRetry);
			if (inputRetry != "1" && StringHelper::toLower(inputRetry) != "yes") {
				menuFlag = false;
			}
		}
	}
	else
	{
		cout << "Error: input file \"" << inputPath << "\" not found!" << endl;
	}
}

void CommandLineUI::displayHashTable(HashMap <NodeMain*> *storageMapPtr) {
	unsigned int hashId, loadFactor;
	int initialId;
	bool flagCollision;
	std::string hashKey;
	HashMapNode<NodeMain*>* hashMapNodePtr;
	NodeMain *nodeMainPtr;
	// headers
	std::cout << std::left << std::setw(12) << "Hash Key" << std::setw(17) << "Name"
		<< std::setw(3) << "ID" 
		<< std::setw(2) << "X"
		// K = the initial collision id before collision resolution
		<< std::setw(4) << "K" 
		<< std::endl;
	// custom iterator saves lots of nested loops
	HashMap <NodeMain*>::iterator it = storageMapPtr->begin();
	HashMap <NodeMain*>::iterator itend = storageMapPtr->end();
	for (; it != itend; it++)
	{
		// get the hash table nodes from the list
		hashMapNodePtr = it->getSelf();
		hashId = hashMapNodePtr->getId();
		flagCollision = hashMapNodePtr->isCollision();
		initialId = hashMapNodePtr->getInitialId();
		hashKey = hashMapNodePtr->getKey();
		nodeMainPtr = hashMapNodePtr->getValue();
		std::cout << std::left << std::setw(12) << hashKey.substr(0, 10) << std::setw(17) << nodeMainPtr->getName().substr(0, 16)
			<< std::setw(3) << hashId 
			<< std::setw(2) << (flagCollision ? "X" : "")
			// show the initial collision id before collision resolution
			<< std::setw(4) << (flagCollision ? to_string(initialId) : "")
			<< std::endl;
	}
	// legend
	std::cout << "X = collision, K = hash index before collision" << std::endl << std::endl;
	// hash map statistics
	loadFactor = (unsigned int)(((double)storageMapPtr->bucketsUsed() / (double)storageMapPtr->max_size()) * 100.00);
	std::cout << "Hash Table Stats" << std::endl;
	std::cout << "Inserted " << storageMapPtr->size() << " of " << storageMapPtr->insertAttempts() << " attempts" << std::endl;
	std::cout << "Max Size: " << storageMapPtr->max_size() << std::endl;
	std::cout << "Load Factor: " << std::fixed << std::setprecision(0) << loadFactor << "%" << std::endl;
	std::cout << "Collision Count: " << storageMapPtr->collisions() << std::endl;
	std::cout << "______________________________________________" << std::endl;
}

void CommandLineUI::birthdayFind(HashMap <NodeMain*> *storageMapPtr, std::string inputBirthday) {
	unsigned int operations;
	int pos;
	HashMapNode<NodeMain*>* hashMapNodePtr;
	NodeMain *nodeMainPtr;
	pos = storageMapPtr->find(inputBirthday, operations);
	if (pos > -1) {
		hashMapNodePtr = storageMapPtr->getHash(pos);
		nodeMainPtr = hashMapNodePtr->getValue();
		std::cout << "Found Result for Search: " << std::endl;
		std::cout  << nodeMainPtr->getBirthday() << " " << nodeMainPtr->getName() << std::endl;
	}
	else {
		std::cout << "Invalid Data" << std::endl;
	}
	std::cout << "______________________________________________" << std::endl;
}

//******************************************************
// operator<<        
//******************************************************
template <class T>
std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr)
{
	int n = ListPtr->size();
	for (int i = 0; i < n; i++)
	{
		foo << (*ListPtr)[i] << endl;
	}
	return foo;
}

std::ostream& operator<< (std::ostream &foo, NodeMain *NodePtr)
{
	foo << NodePtr->getName() << " " << NodePtr->getBirthday();
	return foo;
}