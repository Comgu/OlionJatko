#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include "DataItem.h"
#include "DataItemList.h"
#include "Recipe.h"
#include "ShoppingList.h"
#include "Factory.h"

DataItem* dataItem = new DataItem("Chicken", 300, "g");
Recipe * recipe = new Recipe("Recipe");
ShoppingList * shoppingList = new ShoppingList("ShoppingList");
DataItemList * dataItemList = DataItemList::getInstance();
Factory* factory = new ListFactory;

TEST_CASE( "functions tests", "[functions]" )
{
	REQUIRE(findListItemCount(recipe) == 0);
	REQUIRE(findListItemCount(shoppingList) == 0);
	recipe->addObject(dataItem);
	REQUIRE(findListItemCount(recipe) == 1);
	REQUIRE(compareStrings("Testi2", "tESti2") == true);
	REQUIRE(compareStrings("Testi2", "tESti3") == false);
}

TEST_CASE( "ShoppingList tests", "[shoppinglist]" )
{
	REQUIRE(shoppingList->getName() == "ShoppingList");
	shoppingList->addObject(dataItem);
	std::vector<DataItem*> testObjects = { dataItem };
	REQUIRE(shoppingList->getContents() == testObjects);
	REQUIRE(shoppingList->getObject(0) == dataItem);
	REQUIRE(shoppingList->findIfObjectExistsName(dataItem) == true);
	REQUIRE(shoppingList->findObjectPos(dataItem) == 0);
	shoppingList->deleteObject(0);
	shoppingList->addObject(recipe);
	REQUIRE(shoppingList->getObject(0) == dataItem);
}

TEST_CASE( "Recipe tests", "[recipe]" )
{
	recipe->deleteObject(0);
	REQUIRE(recipe->getName() == "Recipe");
	recipe->addObject(dataItem);
	std::vector<DataItem*> testObjects = { dataItem };
	REQUIRE(recipe->getContents() == testObjects);
	REQUIRE(recipe->getObject(0) == dataItem);
	REQUIRE(recipe->getName() == "Recipe");
	recipe->setName("Recipe 2");
	REQUIRE(recipe->getName() == "Recipe 2");
}
TEST_CASE("DataItemList tests", "[dataitemlist]")
{
	dataItemList->addObject(dataItem);
	std::vector<DataItem*> testObjects = { dataItem };
	REQUIRE(dataItemList->getContents() == testObjects);
	REQUIRE(dataItemList->getObject(0) == dataItem);
	REQUIRE(dataItemList->findIfObjectExists(dataItem) == true);
	REQUIRE(dataItemList->findObjectPos(dataItem) == 0);
	dataItemList->addObject(dataItem);
	REQUIRE(findListItemCount(dataItemList) == 1);
}

TEST_CASE( "DataItem tests", "[dataitem]" )
{
	REQUIRE(dataItem->getName() == "Chicken");
	REQUIRE(dataItem->getQuantity() == 300);
	REQUIRE(dataItem->getQuantityType() == "g");
	REQUIRE(dataItem->toString() == "Name: Chicken | Quantity: 300 g");
	dataItem->setName("Beef");
	dataItem->setQuantity(400);
	dataItem->setQuantityType("kg");
	REQUIRE(dataItem->getName() == "Beef");
	REQUIRE(dataItem->getQuantity() == 400);
	REQUIRE(dataItem->getQuantityType() == "kg");
	REQUIRE(dataItem->toString() == "Name: Beef | Quantity: 400 kg");
}

TEST_CASE("Factory tests", "[factory]")
{
	Recipe * recipeFactory = factory->createRecipe("Factory recipe");
	REQUIRE(recipeFactory->getName() == "Factory recipe");
	ShoppingList * shoppingFactory = factory->createShoppingList("Factory list");
	REQUIRE(shoppingFactory->getName() == "Factory list");
}