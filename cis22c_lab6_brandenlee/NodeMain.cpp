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

#include "NodeMain.h"

//******************************************************
// Default Constructor        
//******************************************************
NodeMain::NodeMain ()
{
	name = "FIRST LAST";
	birthday = "YYYY-MM-DD";
}

NodeMain::NodeMain (std::string nameFirstObj, std::string nameLastObj, std::string birthdayObj)
{
	std::string nameObj;
	std::stringstream nameSS;
	nameSS << nameFirstObj << " " << nameLastObj;
	name = nameSS.str ();
	birthday = birthdayObj;
}

//******************************************************
// Destructor          
//******************************************************
NodeMain::~NodeMain ()
{
}

std::string NodeMain::getName ()
{
	return name;
}
std::string NodeMain::getBirthday ()
{
	return birthday;
}