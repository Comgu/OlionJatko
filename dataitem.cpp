#include "dataitem.h"
#include <sstream>

DataItem::DataItem(const std::string& newName)
{
	name = newName;
}

DataItem::DataItem(const std::string& newName, double newQuantity, const std::string& newQuantityType)
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

void DataItem::setName(const std::string& newName)
{
	name = newName;
}

std::string DataItem::getQuantityType()
{
	return quantityType;
}

void DataItem::setQuantityType(const std::string& newQuantityType)
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
	outputString << name << " - " << quantity << " " << quantityType << "\n";		// Forms a string from attributes

	return outputString.str();
}