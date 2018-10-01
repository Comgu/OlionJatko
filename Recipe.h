#pragma once
#include <vector>
#include "DataItem.h"
#include "ItemList.h"

class Recipe : public ItemList
{
private:
	std::vector<DataItem*> objects{};
	std::string name;
public:
	Recipe();
	~Recipe();

	std::string getName();															// Get & Set
	void setName(std::string newName);
	std::vector<DataItem*> getRecipe();
	DataItem* getObject(int i);
	void addObject(DataItem* newObject);
	void printAllObjects();

};
