#pragma once
#include "DataItem.h"
#include <vector>
#include "ItemList.h"

class DataItemList : public ItemList
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
	int findObjectPos(DataItem* object);
	bool findIfObjectExists(DataItem* object);
};