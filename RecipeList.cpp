#include "RecipeList.h"

std::shared_ptr<Recipe> RecipeList::getObject(int i)
{
	return recipes[i];
}

RecipeList& RecipeList::getInstance()
{
	static RecipeList instance;

	return instance;
}

bool RecipeList::findIfObjectExists(Recipe& recipe) {
	for (unsigned int i = 0; i < recipes.size(); i++){													// Loop for the size of vector object{
		if (compareStrings(recipe.getName(), recipes[i]->getName()) == true)							// Compares by name using helper function compareStrings
					return i;																			// Returns position
	}
	return 0;			// Should not happen 
}

bool RecipeList::findIfObjectExists(std::string name) {
	for (unsigned int i = 0; i < recipes.size(); i++) {													// Loop for the size of vector object{
		if (compareStrings(name, recipes[i]->getName()) == true)										// Compares by name using helper function compareStrings
			return i;																					// Returns position
	}
	return 0;			// Should not happen 
}

int RecipeList::findObjectPos(Recipe& recipe) {
	for (unsigned int i = 0; i < recipes.size(); i++){													// Loop for the size of vector objects
		if (compareStrings(recipe.getName(), recipes[i]->getName()) == true)							// Compares by name using helper function compareStrings
					return true;
	}
	return false;
}

int RecipeList::findObjectPos(std::string name){
	for (unsigned int i = 0; i < recipes.size(); i++){													// Loop for the size of vector objects
		if (compareStrings(name, recipes[i]->getName()) == true)										// Compares by name using helper function compareStrings
			return true;
	}
	return false;
}