#pragma once
#include <string>
/*! DataItem class

	Class creates item objects with attributes to be used for list classes.

	Attributes: string name, double quantity and string quantityType.

	Methods: Constructors, Destructor, get/setName, get/setQuantityType, get/setQuantity and toString.
*/
class DataItem
{
private:
	std::string name;				/*!< Name in string type*/
	double quantity;				/*!< quantity in double type*/
	std::string quantityType;		/*!< quantity type in string type, e.g. "gram" or "g"*/

public:															
	DataItem() {}					/*!< Default constructor with no param*/
	DataItem(const std::string& newName);																/*!< Constructor with just name*/
	DataItem(const std::string& newName, double newQuantity, const std::string& newQuantityType);		/*!< Constructor with all attributes*/
	~DataItem();					/*!< Default destructor*/
	std::string getName();											/*!< Gets string name from DataItem attributes*/
	void setName(const std::string& newName);						/*!< Sets a new name for string name*/
	std::string getQuantityType();									/*!< Gets string quantityType from DataItem attributes*/
	void setQuantityType(const std::string& newQuantityType);		/*!< Sets a new quantityType for string quantityType*/
	double getQuantity();											/*!< Gets double quantity from DataItem attributes*/
	void setQuantity(double newQuantity);							/*!< Sets a new quantity for double quantity*/
	std::string toString();											/*!< Returns a string format of a class object with its attributes*/
};