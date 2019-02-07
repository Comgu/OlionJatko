#pragma once
#include "itemlist.h"
#include "functions.h"

/*! DataItemList class, subclass of ItemList

	Class is a Singleton class, that should include all DataItem objects in its vector. Essentially a constructed database for all unique DataItem objects.

	Attributes: vector<std::shared_ptr<DataItem>> objects

	Methods: Constructor, Destructor, getObject, getContents, addObject, deleteObject, printAllObjects, getInstance, findObjectPos and findIfObjectExists.

*/
class DataItemList : public ItemList
{
private:
	//static DataItemList* instance;						/*!< Used with Singleton design pattern to ensure only one instance of class*/
	DataItemList() {}
	DataItemList(DataItemList const&);						/*!< Private default constructor, so only class itself can access it (Singleton)*/
public:
	void addObject(std::shared_ptr<DataItem> newObject) override;			/*!< Adds a DataItem object to vector. Checks if object exists already and doesn't add it if duplicate*/
	std::string toString() override;										/*!< Prints all objects in vector using function toString from DataItem class*/
	static DataItemList& getInstance();										/*!< Creates a Singleton instance of class*/
	int findObjectPos(std::shared_ptr<DataItem> object);					/*!< Finds position of DataItem* object and returns it in int type. Should only be used if object exists*/
	int findObjectPos(std::string name, double quant, std::string quantType);
	bool findIfObjectExists(std::shared_ptr<DataItem> object);				/*!< Finds if duplicate object exists in vector and returns true if it does. Compares objects by name, quantity and quantityType*/
	bool findIfObjectExists(std::string name, double quant, std::string quantType);
};

void readCsv(DataItemList& itemList);