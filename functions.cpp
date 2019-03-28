#include "functions.h"
#include <iostream>
#include <cctype>

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


void processItemInput(std::string& str1, std::string& str2, double& num, std::istream& stream) {
	std::string tempString = "";
	bool numberGone = false, endof = false;
	while (stream.good() == true && endof == false) {							// Needs Error handling (after str2 specifically)
		stream >> std::ws;
		int c = std::cin.peek();
		if (std::isdigit(c) != 0) {
			stream >> num;
			numberGone = true;
			continue;
		}
		else if (numberGone == false) {
			str1.append(" ");
			stream >> tempString;
			str1.append(tempString);
			continue;
		}
		else {
			stream >> str2;
			endof = true;
		}
	}
}