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
	if (findIfObjectExistsName(newObject) == false)
		objects.push_back(newObject);
	else
	{
		int pos = findObjectPos(newObject);
		if (objects[pos]->getQuantityType() == newObject->getQuantityType())
		{
			objects[pos] = new DataItem(newObject->getName(), newObject->getQuantity() + objects[pos]->getQuantity(), newObject->getQuantityType());
		}
		else
			objects.push_back(newObject);
	}
}

void ShoppingList::printAllObjects()
{
	std::cout << "\nShopping list contents:\n";
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		std::cout << i + 1 << " " << objects[i]->toString() << "\n";
	}
}

int ShoppingList::findObjectPos(DataItem* object)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (object->getName() == objects[i]->getName())
					return i;
	}
	return 0;
}

bool ShoppingList::findIfObjectExistsName(DataItem* object)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (object->getName() == objects[i]->getName())
					return true;
	}
	return false;
}
