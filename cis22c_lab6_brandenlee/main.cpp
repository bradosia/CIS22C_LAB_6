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

/**
@mainpage Hash table Example
Prompts user for a file with alternating names and birthdays delimitted by newlines.
For example:\n\n
Kimberly Henley\n
1971-06-12\n
Claudette Leflore\n
1959-07-12\n
Richard Boyd\n
1987-07-10\n\n
Adds the text file entries into a small hash table with max 10 entries. 
Items loaded, load factor, and collisions are recorded and displayed to the user. 
User will then be prompted to search for a birthday and be returned matching names.
*/
#include <iostream>
#include "commandLineUI.h"

using namespace std;

int main ()
{
	CommandLineUI::enterLoop ();
	system ("pause");
	return 0;
}