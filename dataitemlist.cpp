#include "dataitemlist.h"
#include <iostream>
#include <sstream>
#include <fstream>

void DataItemList::addObject(const std::shared_ptr<DataItem>& newObject)
{
	if (findIfObjectExists(newObject) == false)				// If object doesn't exist, adds it to vector, else outputs warning message
		objects.push_back(newObject);
	else
		std::cout << "Object " << newObject->getName() << " " << newObject->getQuantity() << " " << newObject->getQuantityType() << " already exists\n";
}

std::string DataItemList::toString() const
{
	std::stringstream outputString;
	for (unsigned int i = 0; i < objects.size(); i++)
		outputString << objects[i]->toString();							// Prints output from toString function

	return outputString.str();
}

DataItemList& DataItemList::getInstance()
{
	static DataItemList instance;

	return instance;
}

int DataItemList::findObjectPos(const std::shared_ptr<DataItem>& object) const
{
		for (unsigned int i = 0; i < objects.size(); i++)													// Loop for the size of vector objects
		{
			if (compareStrings(object->getName(), objects[i]->getName()) == true)							// Compares by name using helper function compareStrings
				if (object->getQuantity() == objects[i]->getQuantity())										// Compares by quantity
					if (compareStrings(object->getQuantityType(), objects[i]->getQuantityType()) == true)	// Compares by quantityType using helper function compareStrings
						return i;																			// Returns position
		}
	return 0;			// Should not happen 
}

int DataItemList::findObjectPos(const std::string& name, const double& quant, const std::string& quantType) const
{
	for (unsigned int i = 0; i < objects.size(); i++)													// Loop for the size of vector objects
	{
		if (compareStrings(name, objects[i]->getName()) == true)							// Compares by name using helper function compareStrings
			if (quant == objects[i]->getQuantity())										// Compares by quantity
				if (compareStrings(quantType, objects[i]->getQuantityType()) == true)	// Compares by quantityType using helper function compareStrings
					return i;																			// Returns position
	}
	return 0;			// Should not happen 
}

bool DataItemList::findIfObjectExists(const std::shared_ptr<DataItem>& object) const
{
	for (unsigned int i = 0; i < objects.size(); i++)														// Loop for the size of vector objects
	{
		if (compareStrings(object->getName(), objects[i]->getName()) == true)								// Compares by name using helper function compareStrings
			if (object->getQuantity() == objects[i]->getQuantity())											// Compares by quantity
				if (compareStrings(object->getQuantityType(), objects[i]->getQuantityType()) == true)		// Compares by quantityType using helper function compareStrings
					return true;
	}
	return false;
}

bool DataItemList::findIfObjectExists(const std::string& name, const double& quant, const std::string& quantType) const
{
	for (unsigned int i = 0; i < objects.size(); i++)														// Loop for the size of vector objects
	{
		if (compareStrings(name, objects[i]->getName()) == true)								// Compares by name using helper function compareStrings
			if (quant == objects[i]->getQuantity())											// Compares by quantity
				if (compareStrings(quantType, objects[i]->getQuantityType()) == true)		// Compares by quantityType using helper function compareStrings
					return true;
	}
	return false;
}

void readCsv(DataItemList& itemList) 
{
	std::ifstream infile("items.csv");
	std::string line;
	char delim;
	bool isName = true;
	std::string cName;
	double cQuant = 0;
	std::string cQt;

	while (infile.good()) {
		while (getline(infile, line)) {
			std::stringstream ss;
			ss << line;
			while (std::getline(ss, line, ',')) {
				delim = line.at(0);
				if (isdigit(delim) != 0) {
					cQuant = std::stoi(line);
					continue;
				}
				if (isName == true) {
					cName = line;
					isName = false;
				}
				else {
					cQt = line;
					isName = true;
				}
			}
			std::shared_ptr<DataItem> item{ new DataItem{cName,cQuant,cQt} };
			itemList.addObject(item);
		}
	}
	infile.close();
}