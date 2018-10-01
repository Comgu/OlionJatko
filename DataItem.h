#pragma once
#include <string>
#include <ostream>

class DataItem
{
private:
	std::string name;
	double quantity;
	std::string quantityType;

public:
	DataItem();																	// Constructor & Overload
	DataItem(std::string newName, double newQuantity, std::string newQuantityType);

	~DataItem();	 // Destructor

	std::string getName();																// Get & Set
	void setName(std::string newName);
	std::string getQuantityType();
	void setQuantityType(std::string newQuantityType);
	double getQuantity();
	void setQuantity(double newQuantity);
	std::string toString();
};