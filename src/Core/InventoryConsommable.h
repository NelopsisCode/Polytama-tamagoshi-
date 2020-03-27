#ifndef INVENTORYCONSOMMABLE_H
#define INVENTORYCONSOMMABLE_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "Item.h"
#include "Consommable.h"

using namespace std;
class InventoryConsommable {
public:
	
	//Constructeur/Destructeur
	InventoryConsommable();
	InventoryConsommable(const vector <Consommable>& consoBo);
	~InventoryConsommable();
	
	//GET/SET
	void setConsommableBoard(const vector <Consommable> & consoBo);
	vector<Consommable> getConsommableBoard()const;
	
	//Fonctions membres
	void loadIndexConsommable (const string & Index);// charger un fichier de consommables dans l'inventaire
	void saveIndexConsommable (const string & Index)const;// sauver l'inventaire dans un fichier
	void printInventoryConsommable()const;// afficher l'inventaire
	void addInInventoryConsommable(const Consommable & conso);// ajouter un objet dans l'inventaire
	void deleteFromInventoryConsommable(const unsigned int & idIt);//enlever un objet de l'inventaire
	unsigned int calculNumberConsommable()const;//calcul le nombre de consommables
	
private:
	vector<Consommable> consommableBoard;
	
};

#endif /* INVENTORY_H */

