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
	// welcome and setup
	cout << "Welcome to the name and birthday hash table! " << endl;
	HashMap <NodeMain*> *storageMap = new HashMap <NodeMain*>(maxItems);
	List<NodeMain*> *mainList = new List<NodeMain*>();
	std::string inputPath;
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
			storageMap->insert((*mainList)[i]->getBirthday(), (*mainList)[i], operations);
		}
	}
	else
	{
		cout << "Error: input file \"" << inputPath << "\" not found!" << endl;
	}
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