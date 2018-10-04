#pragma once
#include "ItemList.h"
#include "Recipe.h"

class ShoppingList : public ItemList
{
private:
	std::string name;
public:
	ShoppingList(const std::string& newName);
	ShoppingList();
	~ShoppingList();
	std::string getName();															// Get & Set
	void setName(const std::string& newName);
	DataItem* getObject(int i) override;
	std::vector<DataItem*> getContents() override;
	void addObject(DataItem* newObject) override;
	void addObjectsFromRecipe(Recipe* recipeObjects);
	void printAllObjects() override;
	int findObjectPos(DataItem* object);
	bool findIfObjectExistsName(DataItem* object);

};