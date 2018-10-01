#include "ShoppingList.h"
#include <iostream>


ShoppingList::ShoppingList()
{
}


ShoppingList::~ShoppingList()
{
}

DataItem* ShoppingList::getObject(int i)
{
	return objects[i];
}

void ShoppingList::addObject(DataItem* newObject)
{
	objects.push_back(newObject);
}

void ShoppingList::printAllObjects()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		std::cout << i + 1 << " " << objects[i]->toString() << "\n";
	}
}