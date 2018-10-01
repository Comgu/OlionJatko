#include "DataItem.h"
#include <iostream>
#include <sstream>

DataItem::DataItem()
{
}

DataItem::DataItem(std::string newName, double newQuantity, std::string newQuantityType)
{
	name = newName;
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
	outputString << "Name: " << name << " | Quantity: " << quantity << " " << quantityType;

	std::string returnString = outputString.str();

	return returnString;
}