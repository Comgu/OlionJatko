#pragma once
#include "ItemList.h"
#include "ShoppingList.h"
#include "Recipe.h"

/*! Factory class, parent class of ListFactory

	Class is an abstract factory design pattern, which can create objects of Recipe and ShoppingList.

	Virtual Methods: createShoppingList(), createShoppingList(string newName), createRecipe(), createRecipe(string newName)
*/
class Factory
{
public:
	virtual ShoppingList* createShoppingList() = 0;										/*!< Virtual method with no implementation. Overloaded functions with no parameter*/
	virtual ShoppingList* createShoppingList(std::string newName) = 0;					/*!< Virtual method with no implementation. Overloaded functions with std::string parameter*/
	virtual Recipe* createRecipe() = 0;													/*!< Virtual method with no implementation. Overloaded functions with no parameter*/
	virtual Recipe* createRecipe(std::string newName) = 0;								/*!< Virtual method with no implementation. Overloaded functions with std::string parameter*/
};


/*! ListFactory class, subclass of Factory

	Class which can create objects of Recipe and ShoppingList. 

	Methods: createShoppingList(), createShoppingList(string newName), createRecipe(), createRecipe(string newName)
*/
class ListFactory : public Factory
{
public:
	ShoppingList* createShoppingList()									/*!< Creates a new ShoppingList object with no attributes*/
	{
		return new ShoppingList;
	}

	ShoppingList* createShoppingList(std::string newName)				/*!< Creates a new ShoppingList object with a name attribute*/
	{
		return new ShoppingList(newName);
	}

	Recipe* createRecipe()												/*!< Creates a new Recipe object with no attributes*/
	{
		return new Recipe;
	}

	Recipe* createRecipe(std::string newName)							/*!< Creates a new Recipe object with a name attribute*/
	{
		return new Recipe(newName);
	}

};