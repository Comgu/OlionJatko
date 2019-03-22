#include "shoppinglist.h"
#include <sstream>


ShoppingList::ShoppingList(const std::string& newName) : name(newName) {}

std::string ShoppingList::getName() const
{
	return name;
}

void ShoppingList::setName(const std::string& newName)
{
	name = newName;
}

void ShoppingList::addObject(const std::shared_ptr<DataItem>& newObject)
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

void ShoppingList::addObject(const std::shared_ptr<Recipe>& recipe)
{
	recipes.push_back(recipe);				// Add recipe to recipes 
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

std::string ShoppingList::toString() const
{
	std::stringstream outputString;
	outputString << name << " contents:\n";
	if (recipes.size() > 0)
		outputString << "Recipes in list: ";
	for (unsigned int i = 0; i < recipes.size(); i++) {
		outputString << recipes[i]->getName() << " ";
	}
	outputString << "\n";
	for (unsigned int i = 0; i < objects.size(); i++)
		outputString << objects[i]->toString();							// Prints output from toString function
	outputString << "\n";
	return outputString.str();
}

int ShoppingList::findObjectPos(const std::shared_ptr<DataItem>& object) const
{
	for (unsigned int i = 0; i < objects.size(); i++)									// Loop for the size of vector objects
	{
		if (compareStrings(object->getName(), objects[i]->getName())==true)				// Compares by name using helper function compareStrings
					return i;
	}
	return 0;
}

bool ShoppingList::findIfObjectExistsName(const std::shared_ptr<DataItem>& object) const
{
	for (unsigned int i = 0; i < objects.size(); i++)									// Loop for the size of vector objects
	{
		if (compareStrings(object->getName(), objects[i]->getName())==true)				// Compares by name using helper function compareStrings
					return true;
	}
	return false;
}
