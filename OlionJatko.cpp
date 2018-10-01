#include <iostream>
#include "functions.h"
#include "DataItem.h"
#include "DataItemList.h"

int main()
{
	std::string newName = "Jauheliha";
	std::string newDate = "12.11.2018";
	std::string newQuantityType = "g";
	double newQuantity = 400;
	std::string newName2 = "Kana";
	std::string newDate2 = "13.11.2018";
	std::string newQuantityType2 = "g";
	double newQuantity2 = 300;
	DataItem* test = new DataItem(newName, newDate, newQuantityType, newQuantity);
	DataItem* test2 = new DataItem(newName2, newDate2, newQuantityType2, newQuantity2);
	DataItemList *testList = DataItemList::getInstance();
	testList->addObject(test);
	testList->addObject(test2);
	testList->printAllObjects();
	testList->getObject(0);
}
