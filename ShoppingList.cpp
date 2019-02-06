#include "shoppinglist.h"
#include <iostream>
#include <sstream>


ShoppingList::ShoppingList(const std::string& newName)
{
	name = newName;
}

ShoppingList::ShoppingList()
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

std::vector<std::shared_ptr<DataItem>> ShoppingList::getContents()
{
	return objects;
}

std::shared_ptr<DataItem> ShoppingList::getObject(int i)
{
	return objects[i];
}

void ShoppingList::addObject(std::shared_ptr<DataItem> newObject)
{
	if (findIfObjectExistsName(newObject) == false)								// If object doesn't exist, adds it to vector
		objects.push_back(newObject);
	else
	{
		int pos = findObjectPos(newObject);										// Finds position of object
		if (compareStrings(objects[pos]->getQuantityType(), newObject->getQuantityType())==true)			/* Compares by quantityType and combines the quantities if true, else adds object to vector without combining*/
		{
			objects[pos] = std::shared_ptr<DataItem>{ new DataItem{newObject->getName(), newObject->getQuantity() + objects[pos]->getQuantity(), newObject->getQuantityType()} };
		}			 
		else
			objects.push_back(newObject);
	}
}

void ShoppingList::addObject(std::shared_ptr<Recipe> recipe)
{
	std::vector<std::shared_ptr<DataItem>> tempVector = recipe->getContents();					// Copies vector to a temporary one

	for (unsigned int i = 0; i < tempVector.size(); i++){
		if (findIfObjectExistsName(tempVector[i]) == false)								// If object doesn't exist, adds it to vector
			objects.push_back(tempVector[i]);
		else
		{
			int pos = findObjectPos(tempVector[i]);										// Finds position of object
			if (compareStrings(objects[pos]->getQuantityType(), tempVector[i]->getQuantityType())==true)		/* Compares by quantityType and combines the quantities if true, else adds object to vector without combining*/
				objects[pos] = std::shared_ptr<DataItem>{ new DataItem{tempVector[i]->getName(), tempVector[i]->getQuantity() + objects[pos]->getQuantity(), tempVector[i]->getQuantityType()} };
			else
				objects.push_back(tempVector[i]);
		}
	}
}

void ShoppingList::deleteObject(int pos)
{
	objects.erase(objects.begin() + pos);
}


std::string ShoppingList::toString()
{
	std::stringstream outputString;
	outputString << name << " contents:\n";
	for (unsigned int i = 0; i < objects.size(); i++)
		outputString << objects[i]->toString();							// Prints output from toString function
	outputString << "\n";
	return outputString.str();
}

int ShoppingList::findObjectPos(std::shared_ptr<DataItem> object)
{
	for (unsigned int i = 0; i < objects.size(); i++)									// Loop for the size of vector objects
	{
		if (compareStrings(object->getName(), objects[i]->getName())==true)				// Compares by name using helper function compareStrings
					return i;
	}
	return 0;
}

bool ShoppingList::findIfObjectExistsName(std::shared_ptr<DataItem> object)
{
	for (unsigned int i = 0; i < objects.size(); i++)									// Loop for the size of vector objects
	{
		if (compareStrings(object->getName(), objects[i]->getName())==true)				// Compares by name using helper function compareStrings
					return true;
	}
	return false;
}
