#pragma once
#include "ItemList.h"

class DataItemList : public ItemList
{
private:
	static DataItemList* instance;
	DataItemList();
public:
	~DataItemList();
	DataItem* getObject(int i) override;
	std::vector<DataItem*> getContents() override;
	void addObject(DataItem* newObject) override;
	void printAllObjects() override;
	static DataItemList* getInstance();
	int findObjectPos(DataItem* object);
	bool findIfObjectExists(DataItem* object);
};