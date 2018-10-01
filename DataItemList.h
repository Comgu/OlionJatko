#pragma once
#include "DataItem.h"
#include <vector>

class DataItemList
{
private:
	std::vector<DataItem*> objects{};
	static DataItemList* instance;
	DataItemList();

public:
	~DataItemList();
	DataItem* getObject(int i);
	void addObject(DataItem* newObject);
	void printAllObjects();
	static DataItemList* getInstance();

};

