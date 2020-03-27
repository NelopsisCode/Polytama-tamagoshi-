#ifndef POLYTAMA_H
#define POLYTAMA_H

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>

#include "Bar.h"
#include "Item.h" //consommable + clothes
#include "Consommable.h"
#include "Clothes.h"
#include "InventoryConsommable.h"
#include "InventoryClothes.h"


using namespace std;

const unsigned int DROPRATE = 1 ; //(chaque bar perd 1 toutes les DROPRATE min)

class Polytama
{

public:

//Constructeur
	Polytama();

	Polytama(const string & name);
	
	~Polytama();

//Accesseur
	string getName()const;

	Bar getHealth()const;

	Bar getHunger()const;

	Bar getJoy()const;

	Bar getHygiene()const;

	Bar getThirst()const;

	void setName(const string & name);

//Fonction membres
	void consume(const Consommable & c);

	void removeClothes(const IdBody & IdClo);// permet d'enlever un vetement du tama

	void wearClothes(Clothes c);//permet de mettre un vetement au tama et d'enlever celui deja porté

	void dab();

	void takeAbath();

	void printPolytama()const;

	void save(const string & filename)const;

	void loadSave (const string & filename, long int & time);

	void pastTime(const long int & time);

	void polytamaTestRegression();

	void polytamaTest();

private:

	string tamaName;

	Clothes * tamaClothes[3];

	Bar tamaHealth;
	Bar tamaHunger;
	Bar tamaJoy;
	Bar tamaHygiene;
	Bar tamaThirst;

};

#endif