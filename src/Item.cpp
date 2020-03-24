
#include "Item.h"
using namespace std;

Item::Item() 
{
	nameItem="Sans nom";
	idItem=0;
	numberItem=0;
}

Item::Item(const string & nameIt, const unsigned int & idIt) 
{
	nameItem=nameIt;
	idItem=idIt;
}

Item::~Item() 
{// je sais pas si il est vraiment nécessaire
}
string Item::getNameItem()const
{
	return nameItem;
}

void Item::setNameItem (const string & nameIt)
{
	nameItem=nameIt;
}

unsigned int Item::getIdItem ()const
{
	return idItem;
}

void Item::setIdItem(const unsigned int & idIt)
{
	idItem=idIt;
}

unsigned int Item::getNumberItem()const
{
	return numberItem;
}

void Item::setNumberItem(const unsigned int & nbItem)
{
	numberItem = nbItem;
}

void Item::printItem()const
{
	cout <<nameItem<<endl;
	cout <<numberItem<<endl;
}