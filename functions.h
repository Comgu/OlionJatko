#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "ItemList.h"

/*! Contains template class function findListItemCount and helper function compareStrings.
*/
template<typename T>
int findListItemCount(const T& list)			/*!< Finds list object count and returns it in int type. To be used with different types of ItemList classes*/
{
	std::vector<DataItem*> tempVector;
	tempVector = list->getContents();
	return tempVector.size();
}

bool compareStrings(std::string str1, std::string str2);		/*!< Compares strings by using tolower. Therefore uppercase characters and lowercase characters are equal. Returns true if strings are equal*/
