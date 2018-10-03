#pragma once
#include "ItemList.h"

class ShoppingList : public ItemList
{
private:

public:
	ShoppingList();
	~ShoppingList();
	DataItem* getObject(int i) override;
	void addObject(DataItem* newObject) override;
	void printAllObjects() override;
	int findObjectPos(DataItem* object);
	bool findIfObjectExistsName(DataItem* object);

};