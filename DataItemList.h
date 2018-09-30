#pragma once
#include "DataItem.h"
#include <vector>

class DataItemList
{
private:
	std::vector<DataItem> objects{};

public:
	DataItemList();
	DataItemList(std::vector<DataItem> newObjects);
	~DataItemList();

	DataItem getObject(DataItemList objectList, int i);
	void addObject(DataItem newObject);
	void printAllObjects(DataItemList objectList);

};

