#pragma once
#include <vector>
#include "DataItem.h"

class ItemList
{
protected:
	std::vector<DataItem*> objects{};

public:
	virtual ~ItemList();
	virtual DataItem* getObject(int i) = 0;
	virtual void addObject(DataItem* newObject) = 0;
	virtual void printAllObjects() = 0;

protected:
	ItemList();
};

