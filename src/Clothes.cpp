
#include "Clothes.h"
using namespace std;

Clothes::Clothes(){}
//revoir pour prendre en compte l'idItem? 
Clothes::Clothes(const IdBody& idClo)
{
	slotClothes = idClo;
}

Clothes::~Clothes(){}

void Clothes::setClothes (const IdBody & idClo)
{
	slotClothes=idClo;
}

IdBody Clothes::getClothes ()const
{
	return slotClothes;
}

//surcharge du =
Clothes Clothes::operator=(const Clothes& cloth)
{
	this->slotClothes=cloth.slotClothes;
	this->idItem=cloth.idItem;
	this->nameItem=cloth.nameItem;
	return *this;
}


	
