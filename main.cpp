#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "functions.h"
#include "dataitem.h"
#include "dataitemlist.h"
#include "recipe.h"
#include "recipelist.h"
#include "shoppinglist.h"
#include "windows.h"

int main()		// TO DO: Fix Infinite loops (related to str1, num, str2). Add Switch implementation(?). Organize Shopping List
{
	DataItemList& itemList = DataItemList::getInstance();
	RecipeList& recipeList = RecipeList::getInstance();
	ShoppingList shoppingList{ "Shopping List" };
	
	readCsv(itemList);									// Reading Both .csv files to create lists to itemList and recipeList
	readCsv(recipeList, itemList);
	
	bool mainMenu = true;
	std::string action = "9";

	while (mainMenu == true) {							// Main Menu implementation
		std::cout << "1 - Add Food Item\n";
		std::cout << "2 - Create new Recipe\n";
		std::cout << "3 - Create Shopping List\n";
		std::cout << "4 - Print Shopping List\n";
		std::cout << "9 - EXIT\n";
		std::cin >> action;
		system("CLS");
		if(action == "1"){					
			std::string str1, str2="", tempString;
			double num=NULL;
			bool numberGone = false, endof = false;
			std::cout << "Enter name and quantity of item (Example: Meat 400g)\n";
			std::cin >> std::ws >> str1;
			while (std::cin.good() == true && endof == false) {							// Needs Error handling (after str2 specifically)
				std::cin >> std::ws;
				int c = std::cin.peek();
				if (std::isdigit(c) != 0) {
					std::cin >> num;
					numberGone = true;
					continue;
				}
				else if (numberGone == false) {
					str1.append(" ");
					std::cin >> tempString;
					str1.append(tempString);
					continue;
				}
				else {
					std::cin >> str2;
					endof = true;
				}
			}
			std::shared_ptr<DataItem> item{ new DataItem{str1,num,str2} };
			if (itemList.findIfObjectExists(item) == false) {
				std::ofstream onfile;
				onfile.open("items.csv", std::ios_base::app);
				onfile.seekp(0, std::ios::end);
				onfile << std::endl << str1 << "," << num << "," << str2;
				onfile.close();
				itemList.addObject(item);
			}
			system("CLS");
			std::cout << "Added " << str1 << "\n";
			continue;
			}
		if(action == "2"){
			std::string str1, str2 = "", tempString, line;
			double num = NULL;
			bool numberGone = false, endof = false;
			std::cout << "Enter name of recipe\n";
			std::cin >> std::ws;
			getline(std::cin, str1);
			system("CLS");
			if (recipeList.findIfObjectExists(str1)) {
				std::cout << "Recipe " << str1 << " already exists\n";
				continue;
			}
			std::shared_ptr<Recipe> recipe{ new Recipe{str1} };
			std::cout << "Add items to recipe\n";
			bool newItems = true;
			while (newItems == true) {				// Infinite Loop with multi word str1
				std::cout << "Enter name and quantity of item or END if no items left (Example: Meat 400g)\n";
				std::cin >> std::ws >> str1;
				if (str1 == "END") {
					newItems = false;
					system("CLS");
					break;
				}
				while (std::cin.good() == true && endof == false) {							// Needs Error handling (after str2 specifically)
					std::cin >> std::ws;
					int c = std::cin.peek();
					if (std::isdigit(c) != 0) {
						std::cin >> num;
						numberGone = true;
						continue;
					}
					else if (numberGone == false) {
						str1.append(" ");
						std::cin >> tempString;
						str1.append(tempString);
						continue;
					}
					else {
						std::cin >> str2;
						endof = true;
					}
				}
				if (itemList.findIfObjectExists(str1, num, str2) == true)
					recipe->addObject(itemList.getObject(itemList.findObjectPos(str1, num, str2)));
				else {
					std::shared_ptr<DataItem> item{ new DataItem{str1,num,str2} };
					std::ofstream onfile;
					onfile.open("items.csv", std::ios_base::app);
					onfile.seekp(0, std::ios::end);
					onfile << std::endl << str1 << "," << num << "," << str2;
					onfile.close();
					itemList.addObject(item);
					recipe->addObject(item);
				}
			}
			if (recipeList.findIfObjectExists(recipe) == false) {
				std::ofstream onfile;
				onfile.open("recipes.csv", std::ios_base::app);
				onfile.seekp(0, std::ios::end);
				onfile << std::endl << recipe->getName() << ",";
				std::vector<std::shared_ptr<DataItem>> recipeItems = recipe->getContents();
				for (unsigned int i = 0; i < recipe->getContents().size(); i++) {
					if (i + 1 == recipe->getContents().size())
						onfile << recipeItems[i]->getName() << " " << recipeItems[i]->getQuantity() << recipeItems[i]->getQuantityType();
					else
					onfile << recipeItems[i]->getName() << " " << recipeItems[i]->getQuantity() << recipeItems[i]->getQuantityType() << ",";
				}
				onfile.close();

				recipeList.addObject(recipe);
			}
			system("CLS");
			continue;
		}
		if(action == "3") {
			std::string str1, str2="";
			double num=NULL;
			std::cout << "Creating new shopping list\n";
			bool newItems = true;
			std::string action2;
			while (newItems == true) {
				std::cout << "1 - Add a recipe\n";
				std::cout << "2 - Add an item\n";
				std::cout << "3 - Show all recipes\n";
				std::cout << "9 - List done\n";
				std::cin >> action2;
				if (action2 == "1") {
					std::cout << recipeList.toStringNames();
					std::cout << "Enter recipe name\n";				
					std::cin >> str1;
					if (recipeList.findIfObjectExists(str1) == true) {
						std::shared_ptr<Recipe> temp{ recipeList.getObject(recipeList.findObjectPos(str1)) };
						shoppingList.addObject(temp);			
						system("CLS");
						std::cout << "Added " << str1 << "\n";
					}
					else 
						std::cout << "Cannot find recipe: " << str1 << "\n";
					continue;
				}
				if (action2 == "2") {			// Infinite Loop with multi word str1	
					std::string str1, str2 = "", tempString;
					double num = NULL;
					bool numberGone = false, endof = false;
					std::cout << "Enter name and quantity of item (Example: Meat 400g)\n";
					std::cin >> std::ws >> str1;
					if (str1 == "END") {
						newItems = false;
						system("CLS");
						break;
					}
					while (std::cin.good() == true && endof == false) {							// Needs Error handling (after str2 specifically)
						std::cin >> std::ws;
						int c = std::cin.peek();
						if (std::isdigit(c) != 0) {
							std::cin >> num;
							numberGone = true;
							continue;
						}
						else if (numberGone == false) {
							str1.append(" ");
							std::cin >> tempString;
							str1.append(tempString);
							continue;
						}
						else {
							std::cin >> str2;
							endof = true;
						}
					}
					if (itemList.findIfObjectExists(str1, num, str2) == true)
						shoppingList.addObject(itemList.getObject(itemList.findObjectPos(str1, num, str2)));
					else {
						std::shared_ptr<DataItem> item{ new DataItem{str1,num,str2} };
						std::ofstream onfile;
						onfile.open("items.csv", std::ios_base::app);
						onfile.seekp(0, std::ios::end);
						onfile << std::endl << str1 << "," << num << "," << str2;
						onfile.close();
						itemList.addObject(item);
						shoppingList.addObject(item);
						system("CLS");
						std::cout << "Added " << str1 << "\n";
					}
					continue;
				}
				if (action2 == "3") {
					system("CLS");
					std::cout << recipeList.toStringNames();
					continue;
				}
				if (action2 == "9") {
					newItems = false;
					continue;
				}
				std::cout << "Invalid input\n";
			}
			system("CLS");
			continue;
		}
		if (action == "4") {
			std::cout << shoppingList.toString();
			continue;
		}
		if(action == "9") {
			mainMenu = false;
			std::cout << "Exiting...\n";
			Sleep(500);
			continue;
		}
		std::cout << "Invalid input\n";
	}
}
