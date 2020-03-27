
#include "Consommable.h"
using namespace std;

Consommable::Consommable()
{
	food=0;
	hydration=0;
	hygiene=0;
	happiness=0;
}

Consommable::Consommable(const unsigned int& idIt,const string& nameIt,
		const int& nbIt,const int & foo, const int & hydra, 
		const int & hyg, const int & happi)
{
	idItem=idIt;
	nameItem=nameIt;
	numberItem=nbIt;
	food=foo;
	hydration=hydra;
	hygiene=hyg;
	happiness=happi;
}

Consommable::~Consommable()
{
	food=0;
	hydration=0;
	hygiene=0;
	happiness=0;
}

void Consommable::setFood (const int& foo)
{
	food=foo;	
}

int Consommable::getFood()const
{
	return food;
}

void Consommable::setHydration(const int & hydra)
{
	hydration=hydra;
}

int Consommable::getHydration ()const
{
	return hydration;
}

void Consommable::setHygiene(const int& hyg)
{
	hygiene=hyg;
}

int Consommable::getHygiene ()const 
{
	return hygiene;
}

void Consommable::setHappiness (const int & happi)
{
	happiness=happi;
}

int Consommable::getHappiness ()const
{
	return happiness;
}

Consommable Consommable::operator=(const Consommable& conso)
{
	this->numberItem=conso.numberItem;
	this->idItem=conso.idItem;
	this->nameItem=conso.nameItem;
	this->food=conso.food;
	this->hygiene=conso.hygiene;
	this->happiness=conso.happiness;
	this->hydration=conso.hydration;
	return *this;
}
