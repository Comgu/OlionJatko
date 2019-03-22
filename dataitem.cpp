#include "dataitem.h"
#include <sstream>

DataItem::DataItem(const std::string& newName) : name(newName) {}

DataItem::DataItem(const std::string& newName, const double& newQuantity, const std::string& newQuantityType): name(newName), quantityType(newQuantityType), quantity(newQuantity) {}

std::string DataItem::getName() const
{
	return name;
}

void DataItem::setName(const std::string& newName)
{
	name = newName;
}

std::string DataItem::getQuantityType() const
{
	return quantityType;
}

void DataItem::setQuantityType(const std::string& newQuantityType)
{
	quantityType = newQuantityType;
}

double DataItem::getQuantity() const
{
	return quantity;
}

void DataItem::setQuantity(double newQuantity)
{
	quantity = newQuantity;
}

std::string DataItem::toString() const
{
	std::stringstream outputString;
	outputString << name << " - " << quantity << " " << quantityType << "\n";		// Forms a string from attributes

	return outputString.str();
}