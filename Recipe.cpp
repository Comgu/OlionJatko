#include "Recipe.h"
#include <iostream>



Recipe::Recipe(const std::string& newName)
{
	name = newName;
}

Recipe::~Recipe()
{
}

std::string Recipe::getName()
{
	return name;
}

void Recipe::setName(const std::string& newName)
{
	name = newName;
}

std::vector<DataItem*> Recipe::getContents()
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

void Recipe::deleteObject(int pos)
{
	objects.erase(objects.begin() + pos);
}

void Recipe::printAllObjects()
{
	std::cout << "\n" << name << " contents:\n";
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		std::cout  << objects[i]->toString() << "\n";
	}
}