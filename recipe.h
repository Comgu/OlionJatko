#pragma once
#include "itemlist.h"
#include "functions.h"


/*! Recipe class, subclass of ItemList

	Class stores and includes DataItem objects in a vector for one recipe. 

	Attributes: vector<DataItem*> objects, string name.

	Methods: Constructors, Destructor, get/setName, getObject, getContents, addObject, deleteObject, printAllObjects.
*/
class Recipe : public ItemList
{
private:
	std::string name;							/*!< Name in string type*/
public:
	Recipe() {};									/*!< Default constructor with no param*/
	Recipe(const std::string& newName);			/*!< Constructor with name*/
	void setName(const std::string& newName);							/*!< Sets a new name for string name*/
	std::string getName() const;												/*!< Gets string name from Recipe attributes*/		
	void addObject(const std::shared_ptr<DataItem>& newObject) override;						/*!< Adds a DataItem object to vector*/
	std::string toString() const override;									/*!< Prints all objects in vector using function toString from DataItem class*/
};
