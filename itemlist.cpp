#include "itemlist.h"

std::shared_ptr<DataItem> ItemList::getObject(int i)
{
	return objects[i];
}

std::vector<std::shared_ptr<DataItem>> ItemList::getContents()
{
	return objects;
}

void ItemList::deleteObject(int pos)
{
	objects.erase(objects.begin() + pos);
}
