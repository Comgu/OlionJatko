#include "DataItemList.h"
#include "DataItem.h"
#include <iostream>
#include <algorithm>
#include <vector>


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

std::vector<DataItem*> DataItemList::getContents()
{
	return objects;
}

void DataItemList::addObject(DataItem* newObject)
{
	if (findIfObjectExists(newObject) == false)
		objects.push_back(newObject);
	else
		std::cout << "\nObject " << newObject->getName() << " " << newObject->getQuantity() << " " << newObject->getQuantityType() << " already exists\n";
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

int DataItemList::findObjectPos(DataItem* object)
{
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			if (compareStrings(object->getName(), objects[i]->getName()) == true)
				if (object->getQuantity() == objects[i]->getQuantity())
					if (compareStrings(object->getQuantityType(), objects[i]->getQuantityType()) == true)
						return i;
		}
	return 0;
}

bool DataItemList::findIfObjectExists(DataItem* object)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (compareStrings(object->getName(), objects[i]->getName()) == true)
			if (object->getQuantity() == objects[i]->getQuantity())
				if (compareStrings(object->getQuantityType(), objects[i]->getQuantityType()) == true)
					return true;
	}
	return false;
}
