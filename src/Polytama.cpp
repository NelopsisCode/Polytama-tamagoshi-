#include "Polytama.h"

using namespace std;

Polytama::Polytama()
{
	cout <<"Comment s'appel le PolyTama? " <<endl;
	cin >> tamaName ;

	tamaHealth.setValue(100);
	tamaJoy.setValue(100);
	tamaHunger.setValue(100);
	tamaThirst.setValue(100);
	tamaHygiene.setValue(100);

	tamaClothes[0] = nullptr;
	tamaClothes[1] = nullptr;
	tamaClothes[2] = nullptr;


}

	
Polytama::~Polytama()
{

}

string Polytama::getName()const
{
	return tamaName;
}

Bar Polytama::getHealth()const
{
	return tamaHealth;
}

Bar Polytama::getHunger()const
{
	return tamaHunger;
}

Bar Polytama::getJoy()const
{
	return tamaJoy;
}

Bar Polytama::getHygiene()const
{
	return tamaHygiene;
}


void Polytama::consume(const Consommable & c)
{
	tamaHunger += c.getFood();
	tamaThirst += c.getHydration();
	tamaHygiene += c.getHygiene();
	tamaJoy += c.getHappiness();
}

void Polytama::removeClothes(const IdBody & IdClo)
{
	tamaClothes[IdClo] = nullptr;
}	

void Polytama::wearClothes(Clothes c)
{
	if (tamaClothes[c.getClothes()] != nullptr)
	{
		removeClothes(c.getClothes()); //suppression du vêtement
	}

	tamaClothes[c.getClothes()] = &c;	
}




void Polytama::dab()
{
	cout << tamaName << " effectue le dab (dans un endroit inadéquat..)" << endl << endl;
	tamaJoy += 10;
	tamaHygiene -=10; 
}

void Polytama::takeAbath()
{
	cout << tamaName << " va prendre un bain." << endl;

	//Peut être amélioré en ajoutant de le rng
	cout << tamaName << " est tout propre!" << endl << endl;
	tamaHygiene.setValue(100);
}


void Polytama::printPolytama()const
{
	cout << "Prénom: " << tamaName << endl;
	cout << "Faim: " << tamaHunger.getValue() << endl;
	cout << "Soif: " << tamaThirst.getValue() <<endl;
	cout << "Joie: " << tamaJoy.getValue() << endl;
	cout << "Hygiene: " << tamaHygiene.getValue() << endl;
	cout << "Vie: " << tamaHealth.getValue() << endl << endl;
}

void Polytama::polytamaTest()
{
	printPolytama();
	cout << "Le temps passe... " << tamaName << " s'ennuie... Il perd de la joie... :'(" << endl; 
	tamaJoy -= 30 ; 
	printPolytama();
	dab();
	printPolytama();
	assert (tamaJoy.getValue() == 80 and tamaHygiene.getValue() == 90);
	takeAbath();
	assert(tamaHygiene.getValue() == 100);
	printPolytama();
}