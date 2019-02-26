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
	void addObject(const std::shared_ptr<DataItem>& newObject) override;			/*!< Adds a DataItem object to vector. Checks if object exists already and doesn't add it if duplicate*/
	std::string toString() const override;										/*!< Prints all objects in vector using function toString from DataItem class*/
	static DataItemList& getInstance();										/*!< Creates a Singleton instance of class*/
	int findObjectPos(const std::shared_ptr<DataItem>& object) const;					/*!< Finds position of DataItem* object and returns it in int type. Should only be used if object exists*/
	int findObjectPos(const std::string& name, const double& quant, const std::string& quantType) const;
	bool findIfObjectExists(const std::shared_ptr<DataItem>& object) const;				/*!< Finds if duplicate object exists in vector and returns true if it does. Compares objects by name, quantity and quantityType*/
	bool findIfObjectExists(const std::string& name, const  double& quant, const std::string& quantType) const;
};

void readCsv(DataItemList& itemList);