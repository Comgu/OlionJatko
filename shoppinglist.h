#pragma once
#include "itemlist.h"
#include "recipe.h"
#include "functions.h"


/*! ShoppingList class, subclass of ItemList

	Class stores DataItem objects in a vector for one ShoppingList. Objects are combined by name and quantityType if possible. 

	Attributes: vector<DataItem*> objects, string name.

	Methods: Constructors, Destructor, get/setName, getObject, getContents, addObject(DataItem*), addObject(Recipe*), deleteObject, printAllObjects, findObjectPos, findIfObjectExists.
*/
class ShoppingList : public ItemList
{
private:
	std::string name;													/*!< Name in string type*/
	std::vector<std::shared_ptr<Recipe>> recipes;
public:
	ShoppingList(const std::string& newName);							/*!< Constructor with name*/
	ShoppingList() {};													/*!< Default constructor with no param*/
	std::string getName() const;												/*!< Gets string name from ShoppingList attributes*/
	void setName(const std::string& newName);							/*!< Sets a new name for string name*/
	void addObject(const std::shared_ptr<DataItem>& newObject) override;						/*!< Adds a DataItem object to vector. Checks if object exists already and combines its quantity with existing if possible. Overloaded function with DataItem* parameter*/
	void addObject(const std::shared_ptr<Recipe>& recipe);								/*!< Adds all DataItem objects from a Recipe objects to vector. Checks if object exists already and combines its quantity with existing if possible. Overloaded function with Recipe* parameter*/
	std::string toString() const override;									/*!< Prints all objects in vector using function toString from DataItem class*/
	int findObjectPos(const std::shared_ptr<DataItem>& object) const;								/*!< Finds position of DataItem* object and returns it in int type. Should only be used if object exists*/
	bool findIfObjectExistsName(const std::shared_ptr<DataItem>& object) const;						/*!< Finds if duplicate object exists in vector and returns true if it does. Compares objects by name*/

};