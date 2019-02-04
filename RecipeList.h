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
	std::shared_ptr<Recipe> getObject(int i);
	static RecipeList& getInstance();
	virtual ~RecipeList() = default;
	bool findIfObjectExists(Recipe& recipe);
	bool findIfObjectExists(std::string name);
	int findObjectPos(Recipe& recipe);
	int findObjectPos(std::string name);
};

