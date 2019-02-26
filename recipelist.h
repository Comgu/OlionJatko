#pragma once
#include "recipe.h"
#include "dataitemlist.h"

class RecipeList
{
private:
	std::vector<std::shared_ptr<Recipe>> recipes;
	RecipeList(RecipeList const&);
	RecipeList() {}
public:
	void addObject(std::shared_ptr<Recipe> newObject);
	std::shared_ptr<Recipe> getObject(int i) const;
	static RecipeList& getInstance();
	std::string toString() const;
	std::string toStringNames() const;
	virtual ~RecipeList() = default;
	int findObjectPos(const std::shared_ptr<Recipe>& recipe) const;
	int findObjectPos(const std::string& name) const;
	bool findIfObjectExists(const std::shared_ptr<Recipe>& recipe) const;
	bool findIfObjectExists(const std::string& name) const;
};

void readCsv(RecipeList& recipeList, DataItemList& itemList);