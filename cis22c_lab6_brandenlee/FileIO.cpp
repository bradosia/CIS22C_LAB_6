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

#include "FileIO.h"

bool FileIO::strToFile (std::string str, std::string filePath)
{
	bool flag = false;
	std::ofstream myFile;
	myFile.open (filePath);
	if (myFile)
	{
		flag = true;
		myFile << str;
		myFile.close ();
	}
	return flag;
}

bool FileIO::fileToList (std::string filePath, List<NodeMain*>* listPtr)
{
	std::string nameFirst, nameLast, birthday;
	bool flag = false;
	std::ifstream myFile;
	myFile.open (filePath);
	if (myFile.is_open ())
	{
		flag = true;
		// While the file is good
		while (myFile.good ())
		{
			myFile >> nameFirst >> nameLast >> birthday;
			listPtr->push_back (new NodeMain (nameFirst, nameLast, birthday));
		}
		myFile.close ();
	}
	return flag;
}