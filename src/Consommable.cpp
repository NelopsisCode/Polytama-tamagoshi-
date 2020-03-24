
#include "Consommable.h"
using namespace std;

Consommable::Consommable()
{
	food=0;
	hydration=0;
	hygiene=0;
	happiness=0;
}

Consommable::Consommable(const int & foo, const int & hydra, const int & hyg, const int & happi)
{
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


