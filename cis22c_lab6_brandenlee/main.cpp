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
@mainpage Binary Search Tree Example
Prompts user for a file with alternating names and birthdays delimitted by newlines.
For example:\n\n
Kimberly Henley\n
1971-06-12\n
Claudette Leflore\n
1959-07-12\n
Richard Boyd\n
1987-07-10\n\n
Uses a two different binary search trees for names and birthdays. 
After constructing the BST, the user is promted for the output file
for 
- listing of everyone by name using a post-order traversal mechanism.
- listing of everyone by birthday using a breadth-first traversal mechanism.
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