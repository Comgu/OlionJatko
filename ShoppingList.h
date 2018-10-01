#pragma once
#include <vector>
#include "DataItem.h"
#include "ItemList.h"

class ShoppingList : public ItemList
{
private:
	std::vector<DataItem*> objects{};
public:
	ShoppingList();
	~ShoppingList();
	DataItem* getObject(int i);
	void addObject(DataItem* newObject);
	void printAllObjects();
};