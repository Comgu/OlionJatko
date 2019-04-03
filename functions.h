#pragma once
#include <string>

/*! Contains helper functions
*/

bool compareStrings(const std::string& str1, const std::string& str2);		/*!< Compares strings by using tolower. Therefore uppercase characters and lowercase characters are equal. Returns true if strings are equal*/

void processItemInput(std::string& str1, std::string& str2, double& num, std::istream& stream);		// Function that modifies str1, str2 and num values based on the stream input. Used in interface, when user inputs a dataitem using std::cin.

bool checkBack(std::string str);