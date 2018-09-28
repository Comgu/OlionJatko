#include "DataItem.h"
#include <iostream>

DataItem::DataItem()
{
}

DataItem::DataItem(char newName, char newDate, char newQuantityType, double newQuantity)
{
	name = newName;
	date = newDate;
	quantityType = newQuantityType;
	quantity = newQuantity;
}

DataItem::~DataItem()
{
}

char DataItem::getName()
{
	return name;
}

void DataItem::setName(char newName)
{
	name = newName;
}

char DataItem::getDate()
{
	return date;
}

void DataItem::setDate(char newDate)
{
	date = newDate;
}

char DataItem::getQuantityType()
{
	return quantityType;
}

void DataItem::setQuantityType(char newQuantityType)
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