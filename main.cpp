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

int main()		// TO DO: Organize a Shopping List
{
	DataItemList& itemList = DataItemList::getInstance();
	RecipeList& recipeList = RecipeList::getInstance();
	ShoppingList shoppingList{ "Shopping List" };

	readCsv(itemList);									// Reading Both .csv files to create lists to itemList and recipeList
	readCsv(recipeList, itemList);

	bool mainMenu = true;
	std::string action = "9";

	while (mainMenu == true) {							// Main Menu implementation
		std::cout << "1 - Create recipe or item\n";
		std::cout << "2 - Add recipes and items to Shopping List\n";
		std::cout << "3 - Print Shopping List\n";
		std::cout << "4 - QUIT\n";
		std::cout << "\nNavigation is done with inputs 1-4\n";
		std::cin >> action;
		system("CLS");
		if (action == "1") {							// Main Menu choices start here (1)		
			bool stayInMenu = true;
			while (stayInMenu != false) {
				std::string action2;
				std::cout << "Creator menu\n";
				std::cout << "1 - Add a recipe\n";
				std::cout << "2 - Add an item\n";
				std::cout << "3 - Edit recipe\n";
				std::cout << "4 - Back\n";
				std::cin >> action2;
				if (action2 == "1") {					// Menu1 choice 1
					std::string recipeName = "";
					std::cout << "Enter recipe name\n";
					std::cin >> std::ws;
					getline(std::cin, recipeName);
					system("CLS");
					if (checkBack(recipeName))
						break;
					if (recipeList.findIfObjectExists(recipeName)) {
						std::cout << "Recipe " << recipeName << " already exists\n";
						continue;
					}
					std::shared_ptr<Recipe> recipe{ new Recipe{recipeName} };
					std::cout << "Add items to recipe\n";
					bool newItems = true;
					while (newItems == true) {
						std::string str1 = "", str2 = "";
						double num = NULL;
						std::cout << "Enter name and quantity of item or END if no items left (Example: Meat 400g)\n";
						std::cin >> std::ws >> str1;
						if (str1 == "END") {
							newItems = false;
							system("CLS");
							break;
						}
						processItemInput(str1, str2, num, std::cin);
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
						std::cout << "Added " << str1 << " to recipe\n";
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
					continue;
				}
				if (action2 == "2") {									// Menu1 choice 2
					std::string str1 = "", str2 = "";
					double num = NULL;
					system("CLS");
					std::cout << "Enter name and quantity of item (Example: Meat 400g)\n";
					std::cin >> std::ws >> str1;
					if (checkBack(str1))
						break;
					processItemInput(str1, str2, num, std::cin);
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
				if (action2 == "3") {
					std::string recipeName = "";
					std::cout << recipeList.toStringNames();
					std::cout << "Enter recipe name to edit\n";
					std::cin >> std::ws;
					getline(std::cin, recipeName);
					system("CLS");
					if (checkBack(recipeName))
						break;
					if (recipeList.findIfObjectExists(recipeName) == true) {
						bool editing = true;
						while (editing == true) {
							std::string str1 = "", str2 = "";
							double num = NULL;
							std::cout << "Enter ADD or REMOVE or END editing is done(Example: REMOVE Meat 400g )\n";
							std::cin >> std::ws >> str1;
							if (str1 == "END") {
								editing = false;
								system("CLS");
								break;
							}

						}
					}
				}
				if (action2 == "4" || checkBack(action2))		// Menu1 choice 4 (back)
					stayInMenu = false;
			}
			system("CLS");
			continue;
		}
		if (action == "2") {								// Menu choice 2
			std::cout << "Shopping List menu\n";
			bool newItems = true;
			std::string action2;
			while (newItems == true) {
				std::cout << "1 - Add a recipe\n";
				std::cout << "2 - Add an item\n";
				std::cout << "3 - Show all known recipes\n";
				std::cout << "4 - Apply changes/Back\n";
				std::cin >> action2;
				if (action2 == "1") {						// Menu2 choice 1
					std::string recipeName;
					system("CLS");
					std::cout << recipeList.toStringNames();
					std::cout << "\nEnter recipe name\n";
					std::cin >> std::ws;
					getline(std::cin, recipeName);
					if (checkBack(recipeName))
						break;
					if (recipeList.findIfObjectExists(recipeName) == true) {
						std::shared_ptr<Recipe> temp{ recipeList.getObject(recipeList.findObjectPos(recipeName)) };
						shoppingList.addObject(temp);
						system("CLS");
						std::cout << "Added " << recipeName << "\n";
					}
					else
						std::cout << "Cannot find recipe: " << recipeName << "\n";
					continue;
				}
				if (action2 == "2") {						// Menu2 choice 2
					std::string str1 = "", str2 = "";
					double num = NULL;
					std::cout << "Enter name and quantity of item (Example: Meat 400g)\n";
					std::cin >> std::ws >> str1;
					if (checkBack(str1))
						break;
					processItemInput(str1, str2, num, std::cin);
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
					system("CLS");
					std::cout << "Added " << str1 << "\n";
					continue;
				}
				if (action2 == "3") {						// Menu2 choice 3
					system("CLS");
					std::cout << recipeList.toStringNames();
					continue;
				}
				if (action2 == "4" || checkBack(action2)) {		// Menu2 choice 4 (back)
					newItems = false;
					continue;
				}
				std::cout << "Invalid input\n";
			}
			system("CLS");
			std::cout << shoppingList.toString();
			continue;
		}
		if (action == "3") {		// Menu choice 3
			std::cout << shoppingList.toString();
			continue;
		}
		if (action == "4" || action == "QUIT" || action == "quit" || action == "Quit") {		// Menu choice 4 (quit)
			mainMenu = false;
			std::cout << "Exiting...\n";
			Sleep(500);
			continue;
		}
		std::cout << "Invalid input\n";
	}
}
