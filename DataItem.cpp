#include "DataItem.h"
#include <iostream>
#include <sstream>

DataItem::DataItem()
{
}

DataItem::DataItem(std::string newName, std::string newDate, std::string newQuantityType, double newQuantity)
{
	name = newName;
	date = newDate;
	quantityType = newQuantityType;
	quantity = newQuantity;
}

DataItem::~DataItem()
{
}

std::string DataItem::getName()
{
	return name;
}

void DataItem::setName(std::string newName)
{
	name = newName;
}

std::string DataItem::getDate()
{
	return date;
}

void DataItem::setDate(std::string newDate)
{
	date = newDate;
}

std::string DataItem::getQuantityType()
{
	return quantityType;
}

void DataItem::setQuantityType(std::string newQuantityType)
{
	quantityType = newQuantityType;
}

double DataItem::getQuantity()
{
	return quantity;
}

void DataItem::setQuantity(double newQuantity)
{
	quantity = newQuantity;
}

std::string DataItem::toString()
{
	std::stringstream outputString;
	outputString << "Name: " << name << " Date: " << date << " Quantity: " << quantity << " " << quantityType;

	std::string returnString = outputString.str();

	return returnString;
}