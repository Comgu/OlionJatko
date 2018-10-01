#include "DataItemList.h"
#include <iostream>

DataItemList* DataItemList::instance = NULL;

DataItemList::DataItemList()
{
}

DataItemList::~DataItemList()
{
}

DataItem* DataItemList::getObject(int i)
{
	return objects[i];
}

void DataItemList::addObject(DataItem* newObject)
{
	objects.push_back(newObject);
}

void DataItemList::printAllObjects()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		std::cout << i+1 << " " << objects[i]->toString() << "\n";
	}
}

DataItemList* DataItemList::getInstance()
{
	if (instance == NULL)
		instance = new DataItemList();
	return instance;
}