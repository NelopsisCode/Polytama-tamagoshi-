#ifndef POLYTAMA_H
#define POLYTAMA_H

#include <cassert>
#include <string>
#include <iostream>
#include "Bar.h"
#include "Item.h" //consommable + clothes
#include "Consommable.h"
#include "Clothes.h"

using namespace std;


class Polytama
{

public:

//Constructeur
	Polytama();
	
	~Polytama();

//Accesseur et mutateur
	string getName()const;

	Bar getHealth()const;

	Bar getHunger()const;

	Bar getJoy()const;

	Bar getHygiene()const;

//Fonction membres
	void consume(const Consommable & c);

	void removeClothes(const IdBody & IdClo);// permet d'enlever un vetement du tama

	void wearClothes(Clothes c);//permet de mettre un vetement au tama et d'enlever celui deja porté

	void dab();

	void takeAbath();

	void printPolytama()const;

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