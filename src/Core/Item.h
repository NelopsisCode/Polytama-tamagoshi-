
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
using namespace std;

class Item {
public:
	
	//Constructeur/Destructeur
	Item();
	Item(const string & nameIt, const unsigned int & idIt);
	~Item();
	
	//SET/GET
	string getNameItem()const;
	void setNameItem (const string & nameIt);
	unsigned int getIdItem ()const;
	void setIdItem(const unsigned int & idIt);
	unsigned int getNumberItem()const;
	void setNumberItem(const unsigned int &nbItem);
	
	//Fonctions membres
	void printItem()const;//permet d'afficher l'item
	
protected:
	string nameItem;
	unsigned int idItem;
	unsigned int numberItem;

};

#endif /* ITEM_H */

