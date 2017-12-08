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

#ifndef NODE_MAIN_H
#define NODE_MAIN_H

#include <string>
#include <sstream>

/**
@class NodeMain
The main node to store name and birthday data
*/

class NodeMain
{
private:
	std::string name; //first last
	std::string birthday; //YYYY-MM-DD
public:
	NodeMain ();
	NodeMain (std::string nameFirstObj, std::string nameLastObj, std::string birthdayObj);
	~NodeMain ();
	std::string getName ();
	std::string getBirthday ();

	friend std::ostream& operator<< (std::ostream &foo, NodeMain *NodePtr);
};
#endif