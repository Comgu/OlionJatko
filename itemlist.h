#pragma once
#include <vector>
#include <memory>
#include "dataitem.h"


/*! ItemList class, parent class of Recipe, ShoppingList and DataItemList

	Class stores pointers to DataItem objects in a vector. Also has virtual functions for subclasses.

	Attributes: vector<DataItem*> objects.

	Methods: Constructors.

	Virtual Methods: Destructor, getObject, getContents, addObject, deleteObject, printAllObjects.
*/
class ItemList
{
protected:
	std::vector<std::shared_ptr<DataItem>> objects{};					/*!< objects is a vector consisting of pointers to DataItem objects*/
	ItemList() {};											/*!< default constructor*/
public:
	virtual ~ItemList() = default;										/*!< Virtual destructor*/
	std::shared_ptr<DataItem> getObject(int i);				/*!< Virtual getObject method with no implementation*/
	std::vector<std::shared_ptr<DataItem>> getContents();	/*!< Virtual getContents method with no implementation*/
	virtual void addObject(std::shared_ptr<DataItem> newObject) = 0;	/*!< Virtual addObject method with no implementation*/
	void deleteObject(int pos);								/*!< Virtual deleteObject method with no implementation*/
	virtual std::string toString() = 0;									/*!< Virtual printAllObjects method with no implementation*/
};