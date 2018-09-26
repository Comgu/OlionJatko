#pragma once

class DataItem
{
	char name, date, quantityType;
	double quantity;

public:
	DataItem();																	// Constructor & Overload
	DataItem(char newName, char newDate, char newQuantityType, double newQuantity);

	~DataItem();	 // Destructor

	char getName();																// Get & Set
	void setName(char newName);
	char getDate();
	void setDate(char newDate);
	char getQuantityType();
	void setQuantityType(char newQuantityType);
	double getQuantity();
	void setQuantity(double newQuantity);

};

