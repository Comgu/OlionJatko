#pragma once
#include <vector>
#include "DataItem.h"
#include "functions.h"


/*! ItemList class, parent class of Recipe, ShoppingList and DataItemList

	Class stores pointers to DataItem objects in a vector. Also has virtual functions for subclasses.

	Attributes: vector<DataItem*> objects.

	Methods: Constructors.

	Virtual Methods: Destructor, getObject, getContents, addObject, deleteObject, printAllObjects.
*/
class ItemList
{
protected:
	std::vector<DataItem*> objects{};					/*!< objects is a vector consisting of pointers to DataItem objects*/
	ItemList();											/*!< default constructor*/
public:
	virtual ~ItemList();								/*!< Virtual destructor*/
	virtual DataItem* getObject(int i) = 0;				/*!< Virtual getObject method with no implementation*/
	virtual std::vector<DataItem*> getContents() = 0;	/*!< Virtual getContents method with no implementation*/
	virtual void addObject(DataItem* newObject) = 0;	/*!< Virtual addObject method with no implementation*/
	virtual void deleteObject(int pos) = 0;				/*!< Virtual deleteObject method with no implementation*/
	virtual void printAllObjects() = 0;					/*!< Virtual printAllObjects method with no implementation*/
};