#include "DataItemList.h"
#include <iostream>

DataItemList::DataItemList()
{
}

DataItemList::DataItemList(std::vector<DataItem> newObjects)
{
	objects = newObjects;
}

DataItemList::~DataItemList()
{
}

DataItem DataItemList::getObject(DataItemList objectList, int i)
{
	DataItem* dataItem = new DataItem();
	//dataItem = objectList[i];

	return *dataItem;
}

void DataItemList::addObject(DataItem newObject)
{
	objects.push_back(newObject);
}

void DataItemList::printAllObjects(DataItemList objectList)
{
	
}