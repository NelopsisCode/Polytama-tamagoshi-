
#ifndef INVENTORY_H
#define INVENTORY_H
#include <bits/stl_vector.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Item.h"

using namespace std;
class Inventory {
public:
	
	//Constructeur/Destructeur
	Inventory();
	Inventory(const vector <Item>& itemBo);
	~Inventory();
	
	//GET/SET
	void setItemBoard(const vector <Item> & itemBo);
	vector<Item> getItemBoard()const;
	
	//Fonctions membres
	void loadIndexClothes (const string & Index);// charger un fichier de vetements dans l'inventaire
	void loadIndexConsommable (const string & Index);// charger un fichier de consommables dans l'inventaire
	void saveIndex (const string & Index);// sauver l'inventaire dans un fichier
	void printInventory()const;// afficher l'inventaire
	void addInInventory(const Item & it);// ajouter un objet dans l'inventaire
	void deleteFromInventory(const unsigned int & idItem);//enlever un objet de l'inventaire
	
private:
	vector<Item> itemBoard;
	
};

#endif /* INVENTORY_H */

