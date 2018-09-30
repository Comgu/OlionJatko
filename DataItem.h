#pragma once
#include <string>

class DataItem
{
private:
	std::string name;
	std::string date;
	std::string quantityType;
	double quantity;

public:
	DataItem();																	// Constructor & Overload
	DataItem(std::string newName, std::string newDate, std::string newQuantityType, double newQuantity);

	~DataItem();	 // Destructor

	std::string getName();																// Get & Set
	void setName(std::string newName);
	std::string getDate();
	void setDate(std::string newDate);
	std::string getQuantityType();
	void setQuantityType(std::string newQuantityType);
	double getQuantity();
	void setQuantity(double newQuantity);

};

