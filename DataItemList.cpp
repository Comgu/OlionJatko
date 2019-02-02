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
	for (auto p : objects)
		delete p;
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
	if (findIfObjectExists(newObject) == false)				// If object doesn't exist, adds it to vector, else outputs warning message
		objects.push_back(newObject);
	else
		std::cout << "\nObject " << newObject->getName() << " " << newObject->getQuantity() << " " << newObject->getQuantityType() << " already exists\n";
}

void DataItemList::deleteObject(int pos)
{
	objects.erase(objects.begin() + pos);
}

void DataItemList::printAllObjects()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		std::cout << i+1 << " " << objects[i]->toString() << "\n";							// Prints output from toString function
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
		for (unsigned int i = 0; i < objects.size(); i++)													// Loop for the size of vector objects
		{
			if (compareStrings(object->getName(), objects[i]->getName()) == true)							// Compares by name using helper function compareStrings
				if (object->getQuantity() == objects[i]->getQuantity())										// Compares by quantity
					if (compareStrings(object->getQuantityType(), objects[i]->getQuantityType()) == true)	// Compares by quantityType using helper function compareStrings
						return i;																			// Returns position
		}
	return 0;			// Should not happen 
}

int DataItemList::findObjectPos(std::string name, double quant, std::string quantType)
{
	for (unsigned int i = 0; i < objects.size(); i++)													// Loop for the size of vector objects
	{
		if (compareStrings(name, objects[i]->getName()) == true)							// Compares by name using helper function compareStrings
			if (quant == objects[i]->getQuantity())										// Compares by quantity
				if (compareStrings(quantType, objects[i]->getQuantityType()) == true)	// Compares by quantityType using helper function compareStrings
					return i;																			// Returns position
	}
	return 0;			// Should not happen 
}

bool DataItemList::findIfObjectExists(DataItem* object)
{
	for (unsigned int i = 0; i < objects.size(); i++)														// Loop for the size of vector objects
	{
		if (compareStrings(object->getName(), objects[i]->getName()) == true)								// Compares by name using helper function compareStrings
			if (object->getQuantity() == objects[i]->getQuantity())											// Compares by quantity
				if (compareStrings(object->getQuantityType(), objects[i]->getQuantityType()) == true)		// Compares by quantityType using helper function compareStrings
					return true;
	}
	return false;
}
