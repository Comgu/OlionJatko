#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "ItemList.h"

// For use in classes derived from ItemList class (ShoppingList, Recipe, DataItemList)
template<typename T>
int findListItemCount(const T& list)
{
	std::vector<DataItem*> tempVector;
	tempVector = list->getContents();
	return tempVector.size();
}

bool compareStrings(std::string str1, std::string str2);
