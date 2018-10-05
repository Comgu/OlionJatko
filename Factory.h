#pragma once
#include "ItemList.h"
#include "ShoppingList.h"
#include "Recipe.h"

class Factory
{
public:
	virtual ShoppingList* createShoppingList() = 0;
	virtual ShoppingList* createShoppingList(std::string newName) = 0;
	virtual Recipe* createRecipe() = 0;
	virtual Recipe* createRecipe(std::string newName) = 0;
};

class ListFactory : public Factory
{
public:
	ShoppingList* createShoppingList()
	{
		return new ShoppingList;
	}

	ShoppingList* createShoppingList(std::string newName)
	{
		return new ShoppingList(newName);
	}

	Recipe* createRecipe()
	{
		return new Recipe;
	}

	Recipe* createRecipe(std::string newName)
	{
		return new Recipe(newName);
	}

};