#include <iostream>
#include "functions.h"
#include "DataItem.h"
#include "DataItemList.h"

int main()
{
	std::string newName = "Jauheliha";
	std::string newQuantityType = "g";
	double newQuantity = 400;
	std::string newName2 = "Kana";
	std::string newQuantityType2 = "g";
	double newQuantity2 = 300;
	std::string newName3 = "Kana";
	std::string newQuantityType3 = "g";
	double newQuantity3 = 300;
	DataItem* test = new DataItem(newName, newQuantity, newQuantityType);
	DataItem* test2 = new DataItem(newName2, newQuantity2, newQuantityType2);
	DataItem* test3 = new DataItem(newName3, newQuantity3, newQuantityType3);
	DataItemList *testList = DataItemList::getInstance();
	testList->addObject(test);
	testList->addObject(test2);
	testList->printAllObjects();
	testList->getObject(0);
	if (testList->findIfObjectExists(test3) == true)
		std::cout << "\nExists\n";
	else
	{
		std::cout << "\nDoesn't exist\n";
		testList->addObject(test3);
	}
}