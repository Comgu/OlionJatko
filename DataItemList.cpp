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

void DataItemList::addObject(DataItem* newObject)
{
	//if (findIfObjectExists(newObject->getName(), newObject->getQuantity(), newObject->getQuantityType()) == false)
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

int DataItemList::findObjectPos(DataItem* object)
{
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			if (object->getName() == objects[i]->getName())
				if (object->getQuantity() == objects[i]->getQuantity())
					if (object->getQuantityType() == objects[i]->getQuantityType())
						return i;
		}
	return 0;
}

bool DataItemList::findIfObjectExists(DataItem* object)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (object->getName() == objects[i]->getName())
			if (object->getQuantity() == objects[i]->getQuantity())
				if (object->getQuantityType() == objects[i]->getQuantityType())
					return true;
	}
	return false;
}
