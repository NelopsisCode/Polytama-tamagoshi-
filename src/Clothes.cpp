
#include "Clothes.h"
using namespace std;

Clothes::Clothes(){}


Clothes::Clothes(const IdBody & slotC, const unsigned int & idIt, 
		const string & nameIt, const int & nbIt)
{
	slotClothes = slotC;
	idItem=idIt;
	nameItem=nameIt;
	numberItem=nbIt;
}

Clothes::~Clothes(){}

void Clothes::setSlotClothes (const IdBody & slotC)
{
	slotClothes=slotC;
}

IdBody Clothes::getSlotClothes ()const
{
	return slotClothes;
}

//surcharge du =
Clothes Clothes::operator=(const Clothes& cloth)
{
	this->slotClothes=cloth.slotClothes;
	this->idItem=cloth.idItem;
	this->nameItem=cloth.nameItem;
	this->numberItem=cloth.numberItem;
	return *this;
}


	
