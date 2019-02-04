#pragma once

#include "Recipe.h"
#include <vector>

class RecipeList
{
private:
	std::vector<std::shared_ptr<Recipe>> recipes;
	RecipeList(RecipeList const&);
	RecipeList() {}
public:
	void addObject(std::shared_ptr<Recipe> newObject);
	std::shared_ptr<Recipe> getObject(int i);
	static RecipeList& getInstance();
	void printAllObjects();
	virtual ~RecipeList() = default;
	int findObjectPos(std::shared_ptr<Recipe> recipe);
	int findObjectPos(std::string name);
	bool findIfObjectExists(std::shared_ptr<Recipe> recipe);
	bool findIfObjectExists(std::string name);
};

