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
#ifndef COMMAND_LINE_UI_H
#define COMMAND_LINE_UI_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include "FileIO.h"
#include "List.h"
#include "NodeMain.h"
#include "HashMap.h"

/**
@class CommandLineUI
contains the presentational and interactive interface in the command line for the user.\n
KEEP ALL COUT<< AND CIN>> HERE
*/

class CommandLineUI
{
private:
public:
	/** menu entry point for the program
	@pre None
	@post menu
	@return None */
	static void enterLoop ();

	/** display the hash table and stats */
	static void displayHashTable(HashMap <NodeMain*> *storageMapPtr);

	/** it will ask the user in a loop to enter a birthdate - any date. 
	If the birthdate is found in the hash table, 
	it will print the name associated with that date, 
	otherwise it will print 'Invalid Data'. */
	static void birthdayFind(HashMap <NodeMain*> *storageMapPtr, std::string inputBirthday);
};

#endif