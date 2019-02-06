#include "recipe.h"
#include <iostream>
#include <sstream>


Recipe::Recipe()
{

}

Recipe::Recipe(const std::string& newName)
{
	name = newName;
}

std::string Recipe::getName()
{
	return name;
}

void Recipe::setName(const std::string& newName)
{
	name = newName;
}

std::vector<std::shared_ptr<DataItem>> Recipe::getContents()
{
	return objects;
}

std::shared_ptr<DataItem> Recipe::getObject(int i)
{
	return objects[i];
}

void Recipe::addObject(std::shared_ptr<DataItem> newObject)
{
	objects.push_back(newObject);
}

void Recipe::deleteObject(int pos)
{
	objects.erase(objects.begin() + pos);
}

std::string Recipe::toString()
{
	std::stringstream outputString;
	outputString << name << " contents:\n";
	for (unsigned int i = 0; i < objects.size(); i++)
		outputString << objects[i]->toString();							// Prints output from toString function

	return outputString.str();
}