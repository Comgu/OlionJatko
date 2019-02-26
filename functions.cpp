#include "functions.h"

bool compareStrings(const std::string& str1, const std::string& str2)
{
	std::string tempStr1 = str1;
	std::string tempStr2 = str2;
	std::transform(tempStr1.begin(), tempStr1.end(), tempStr1.begin(), ::tolower);				// Transforms string to lowercases
	std::transform(tempStr2.begin(), tempStr2.end(), tempStr2.begin(), ::tolower);
	if (tempStr1 == tempStr2)																	// Compares lowercase strings
		return true;
	else
		return false;
}