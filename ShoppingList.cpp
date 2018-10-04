#include "ShoppingList.h"
#include <iostream>


ShoppingList::ShoppingList(const std::string& newName)
{
	name = newName;
}

ShoppingList::ShoppingList()
{
}


ShoppingList::~ShoppingList()
{
}

std::string ShoppingList::getName()
{
	return name;
}

void ShoppingList::setName(const std::string& newName)
{
	name = newName;
}

std::vector<DataItem*> ShoppingList::getContents()
{
	return objects;
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
		if (compareStrings(objects[pos]->getQuantityType(), newObject->getQuantityType())==true)
		{
			objects[pos] = new DataItem(newObject->getName(), newObject->getQuantity() + objects[pos]->getQuantity(), newObject->getQuantityType());
		}
		else
			objects.push_back(newObject);
	}
}

void ShoppingList::addObject(Recipe* recipeObjects)
{
	std::vector<DataItem*> tempVector = recipeObjects->getContents();
	for (unsigned int i = 0; i < tempVector.size(); i++)
	{
		if (findIfObjectExistsName(tempVector[i]) == false)
			objects.push_back(tempVector[i]);
		else
		{
			int pos = findObjectPos(tempVector[i]);
			if (compareStrings(objects[pos]->getQuantityType(), tempVector[i]->getQuantityType())==true)
			{
				objects[pos] = new DataItem(tempVector[i]->getName(), tempVector[i]->getQuantity() + objects[pos]->getQuantity(), tempVector[i]->getQuantityType());
			}
			else
				objects.push_back(tempVector[i]);
		}
	}
}

void ShoppingList::printAllObjects()
{
	std::cout << "\n" << name << " contents:\n";
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		std::cout << i + 1 << " " << objects[i]->toString() << "\n";
	}
}

int ShoppingList::findObjectPos(DataItem* object)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (compareStrings(object->getName(), objects[i]->getName())==true)
					return i;
	}
	return 0;
}

bool ShoppingList::findIfObjectExistsName(DataItem* object)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (compareStrings(object->getName(), objects[i]->getName())==true)
					return true;
	}
	return false;
}
