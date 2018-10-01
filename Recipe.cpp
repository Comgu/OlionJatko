#include "Recipe.h"
#include <iostream>



Recipe::Recipe()
{
}

Recipe::~Recipe()
{
}

std::string Recipe::getName()
{
	return name;
}

void Recipe::setName(std::string newName)
{
	name = newName;
}

std::vector<DataItem*> Recipe::getRecipe()
{
	return objects;
}

DataItem* Recipe::getObject(int i)
{
	return objects[i];
}

void Recipe::addObject(DataItem* newObject)
{
	objects.push_back(newObject);
}

void Recipe::printAllObjects()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		std::cout << i + 1 << " " << objects[i]->toString() << "\n";
	}
}