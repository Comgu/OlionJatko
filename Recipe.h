#pragma once
#include <vector>
#include "DataItem.h"
#include "ItemList.h"

class Recipe : public ItemList
{
private:
	std::string name;
public:
	Recipe(const std::string& newName);
	~Recipe();

	std::string getName();															// Get & Set
	void setName(const std::string& newName);
	std::vector<DataItem*> getRecipe();
	DataItem* getObject(int i) override;
	void addObject(DataItem* newObject) override;
	void printAllObjects() override;
};
