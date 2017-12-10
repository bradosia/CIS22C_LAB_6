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

#ifndef STRING_HELPER_H
#define STRING_HELPER_H

#include <string>
#include <locale>
#include "List.h"

/**
@class StringHelper
A collection of static string manipulating methods
*/
class StringHelper
{
public:
	static List<std::string>* split(std::string target, std::string delim);
	static std::string join(List<std::string>* target, std::string delim);

	/** converts a title and year to an alphanumeric ID with underscores\n
	spaces and non-alphanumeric characters become underscores
	@param title Movie title
	@param year Movie year made
	@return alphanumeric ID with underscores
	*/
	static std::string toID(std::string title, int year);

	/** replaces non-alphanumeric characters
	@param str unsanitized string
	@return sanitized string
	*/
	static std::string sanitize(std::string str, char replace);
	static std::string sanitize255(std::string str);

	/** replaces all strings matching "from" with string "to"
	@pre str is not empty
	@post str is replaced
	@param str Original string
	@param from match string
	@param to replace string
	*/
	static void replaceAll(std::string& str, const std::string& from, const std::string& to);

	static std::string toLower(std::string str);

	/** creates a hash table index from a string
	uses prime number multiplication
	@param str the hash key
	@param size the size of the hash table
	@return the index less than size
	*/
	static unsigned int hashStr(std::string str, unsigned int size);
	/** creates a hash table index from a birthday
	So, today's date of 2017-12-04 will reduce as 2+0+1+7+1+2+0+4 = 17
	which will further reduce as 1+7 = 8
	@param str the birthday in form YYYY-MM-DD
	@param size the size of the hash table
	@return the index less than size
	*/
	static unsigned int hashBirthday(std::string str, unsigned int size);
	static unsigned int hashBirthday(std::string str);

	static std::string center(std::string str, unsigned int size);
	static std::string repeatToLength(std::string s, unsigned len);
	static bool isNumeric(std::string str);
	static std::string trim(const std::string& str, const std::string& whitespace);
	static std::string reduce(const std::string& str, const std::string& fill, const std::string& whitespace);

	/** trims and removes excessive whitespace from an entire list 
	of strings.
	*/
	static void reduce(List<std::string>* target);
};
#endif