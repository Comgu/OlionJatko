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

DataItem DataItemList::getObject(int i)
{
	return objects[i];
}

void DataItemList::addObject(DataItem newObject)
{
	objects.push_back(newObject);
}

void DataItemList::printAllObjects()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		std::cout << "Object: " << "\n"; // TODO: To string objects
	}
}