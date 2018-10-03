#pragma once
#include <string>

class DataItem
{
private:
	std::string name;
	double quantity;
	std::string quantityType;

public:															// Constructor & Overload
	DataItem();
	DataItem(const std::string& newName);
	DataItem(const std::string& newName, double newQuantity, const std::string& newQuantityType);
	~DataItem();	 // Destructor

	std::string getName();																// Get & Set
	void setName(const std::string& newName);
	std::string getQuantityType();
	void setQuantityType(const std::string& newQuantityType);
	double getQuantity();
	void setQuantity(double newQuantity);
	std::string toString();
};