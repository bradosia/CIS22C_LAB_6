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
#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>
#include <iostream>
#include <fstream>
#include "NodeMain.h"
#include "List.h"

/**
@class FileIO
contains file writing methods.
*/

class FileIO
{
public:
	/** writes the string to the file path
	@pre file path exists
	@post writes to file
	@param str data to write
	@param filePath file path
	@return true on success false on failure */
	static bool strToFile (std::string str, std::string filePath);

	/** parses the file as a list
	@pre file path exists
	@post list is appended to with new data
	@param filePath file path
	@param listPtr list to fill
	@return true on success false on failure */
	static bool fileToList (std::string filePath, List<NodeMain*>* listPtr);
};
#endif