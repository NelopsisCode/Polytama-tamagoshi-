
#ifndef INVENTORYCLOTHES_H
#define INVENTORYCLOTHES_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "Item.h"
#include "Clothes.h"


using namespace std;
class InventoryClothes {
public:
	
	//Constructeur/Destructeur
	InventoryClothes();
	InventoryClothes(const vector <Clothes>& clothesBo);
	~InventoryClothes();
	
	//GET/SET
	void setClothesBoard(const vector <Clothes> & clothesBo);
	vector<Clothes> getClothesBoard()const;
	
	//Fonctions membres
	void loadIndexClothes (const string & Index);// charger un fichier de vetements dans l'inventaire
	void saveIndexClothes (const string & Index)const;// sauver l'inventaire dans un fichier
	void printInventoryClothes()const;// afficher l'inventaire
	void addInInventoryClothes(const Clothes & clot);// ajouter un objet dans l'inventaire
	void deleteFromInventoryClothes(const unsigned int & idIt);//enlever un objet de l'inventaire
	unsigned int calculNumberClothes()const; // compte le nombre de clothes
	
private:
	vector<Clothes> clothesBoard;
	
};

#endif /* INVENTORYCLOTHES_H */

