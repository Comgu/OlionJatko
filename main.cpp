#include <iostream>
#include "stdlib.h"
#include "functions.h"
#include "DataItem.h"
#include "DataItemList.h"
#include "Recipe.h"
#include "ShoppingList.h"
#include "Factory.h"
#include "windows.h"

int main()		// TO DO: Fix Infinite loops. Find recipes by name. Add Switch implementation(?). Persisting database. Include more features to be used to CLI
{
	bool mainMenu = true;
	ShoppingList* shoppingList = new ShoppingList("List 1");
	std::string action = "9";
	std::string str1, str2;
	double num;
	DataItemList *list = DataItemList::getInstance();

	while (mainMenu == true) {
		std::cout << "1 - Add Food Item\n";
		std::cout << "2 - Create new Recipe\n";
		std::cout << "3 - Create Shopping List\n";
		std::cout << "4 - Print Shopping List\n";
		std::cout << "9 - EXIT\n";
		std::cin >> action;
		system("CLS");
		if(action == "1"){
			std::cout << "Enter name and quantity of item (Example: Meat 400g)\n";
			std::cin >> str1;
			std::cin >> num;
			std::cin >> str2;
			DataItem *item = new DataItem{ str1, num, str2 };
			list->addObject(item); 
			continue;
			system("CLS");
			}
		if(action == "2"){
			std::cout << "Enter name of recipe\n";
			std::cin >> str1;
			system("CLS");
			Recipe *recipe = new Recipe{ str1 };
			std::cout << "Add items to recipe\n";
			bool newItems = true;
			while (newItems == true) {
				std::cout << "Enter name and quantity of item (END ends)\n";
				std::cin >> str1;
				if (str1 == "END") {
					newItems = false;
					system("CLS");
					break;
				}
				std::cin >> num;
				std::cin >> str2;
				if(list->findIfObjectExists(str1,num,str2) == true)
					recipe->addObject(list->getObject(list->findObjectPos(str1, num, str2)));
				else {
					DataItem *item = new DataItem{ str1, num, str2 };
					list->addObject(item);
					recipe->addObject(item);
				}

			}
			system("CLS");
			continue;
		}
		if(action == "3") {
			std::cout << "Creating new shopping list\n";
			bool newItems = true;
			std::string action2;
			while (newItems == true) {
				std::cout << "1 - Add a recipe\n";
				std::cout << "2 - Add an item\n";
				std::cout << "9 - List done\n";
				std::cin >> action2;
				if (action2 == "1") {
					std::cout << "Enter recipe name\n";				
					std::cin >> str1;
					system("CLS");
					continue;
				}
				if (action2 == "2") {
					std::cout << "Enter item name and quantity\n";				
					std::cin >> str1;
					std::cin >> num;
					std::cin >> str2;
					if (list->findIfObjectExists(str1, num, str2) == true)
						shoppingList->addObject(list->getObject(list->findObjectPos(str1, num, str2)));
					else {
						DataItem *item = new DataItem{ str1, num, str2 };
						list->addObject(item);
						shoppingList->addObject(item);
						system("CLS");
						continue;
					}
				}
				if (action2 == "9") {
					newItems = false;
					continue;
				}
				std::cout << "Invalid input\n";
			}
			continue;
		}
		if (action == "4") {
			shoppingList->printAllObjects();
			continue;
		}
		if(action == "9") {
			mainMenu = false;
			std::cout << "Exiting...\n";
			Sleep(1000);
			continue;
		}
		std::cout << "Invalid input\n";
	}











	/* Manual Test Code Below
	
	// Testing scanning
	std::cout << "Testing Scanning\n";
	std::string str1, str2;
	double val1;
	std::cout << "Enter item name\n";
	std::cin >> str1;
	std::cout << "Enter quantity and quantity type(Example 400 g)\n";
	std::cin >> val1;
	std::cin >> str2;

	// Testing for DataItem class & DataItemList class
	std::cout << "\nTesting DataItem & DataItemList";
	std::string newName2 = "Kana";
	std::string newQuantityType2 = "g";
	double newQuantity2 = 300;
	std::string newName3 = "kana";
	std::string newQuantityType3 = "g";
	double newQuantity3 = 300;
	DataItem* cmdLineItem = new DataItem(str1, val1, str2);
	DataItem* kana300 = new DataItem(newName2, newQuantity2, newQuantityType2);
	DataItem* kana300dupli = new DataItem(newName3, newQuantity3, newQuantityType3);
	DataItem* porkkana = new DataItem("Porkkana", 6, "kpl");
	DataItem* kaali = new DataItem("Kaali", 1, "kpl");
	DataItemList *testList = DataItemList::getInstance();
	testList->addObject(cmdLineItem);
	testList->addObject(kana300);
	testList->addObject(kana300dupli);
	testList->addObject(porkkana);
	testList->addObject(kaali);
	testList->printAllObjects();
	testList->getObject(0);

	// Testing for Recipe class
	std::cout << "\nTesting Recipe";
	Factory* factory = new ListFactory;
	Recipe * recipe1 = factory->createRecipe();
	recipe1->setName("Baklava");
	recipe1->addObject(kana300dupli);
	recipe1->addObject(kana300);
	recipe1->addObject(porkkana);
	Recipe * recipe2 = factory->createRecipe("Keitto");
	recipe2->addObject(cmdLineItem);
	recipe2->addObject(kana300);
	recipe1->printAllObjects();
	recipe2->printAllObjects();

	// Testing for ShoppingList class
	std::cout << "\nTesting ShoppingList";
	ShoppingList * shopping1 = factory->createShoppingList("Ostoslista 1");
	shopping1->addObject(recipe2);
	shopping1->addObject(cmdLineItem);
	shopping1->addObject(kana300);
	shopping1->addObject(kana300dupli);
	shopping1->addObject(recipe1);
	shopping1->printAllObjects();

	// Testing for Functions template function
	std::cout << "\nTesting template function";
	int elementCount = findListItemCount(shopping1);
	std::cout << "\nElement count in " << shopping1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe1);
	std::cout << "\nElement count in " << recipe1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe2);
	std::cout << "\nElement count in " << recipe2->getName() << " is " << elementCount;
	elementCount = findListItemCount(testList);
	std::cout << "\nElement count of DataItemList"  << " is " << elementCount << "\n";

	// Testing for delete func
	std::cout << "\nTesting delete function";
	shopping1->deleteObject(0);
	shopping1->printAllObjects();
	recipe1->deleteObject(0);
	recipe1->printAllObjects();
	testList->deleteObject(0);
	testList->printAllObjects();

	elementCount = findListItemCount(shopping1);
	std::cout << "\nElement count in " << shopping1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe1);
	std::cout << "\nElement count in " << recipe1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe2);
	std::cout << "\nElement count in " << recipe2->getName() << " is " << elementCount;
	elementCount = findListItemCount(testList);
	std::cout << "\nElement count of DataItemList" << " is " << elementCount << "\n";*/
	
}
