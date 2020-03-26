
#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "InventoryConsommable.h"
#include "InventoryClothes.h"


using namespace std;
class Inventory {
public:

	void loadIndex(const string & Index1,InventoryConsommable & inventConso,
			const string & Index2,InventoryClothes & inventClot);//charge les fichiers dans les inventaires respectifs
	void saveIndex (const string & Index1,const InventoryConsommable & inventConso,
			const string & Index2,const InventoryClothes & inventClot)const;// sauver les inventaires dans leur fichier trespectif
	void printInventory(const InventoryConsommable & inventConso, const InventoryClothes & inventClot)const;// afficher l'inventaire
	void testRegressionInventory();//test fonctions
	
};

#endif /* INVENTORY_H */

