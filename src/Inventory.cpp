
#include "Inventory.h"
using namespace std;


void Inventory::loadIndex(const string & Index1,  InventoryConsommable & inventConso,
		const string & Index2,  InventoryClothes & inventClot)//charge les fichiers dans les inventaires respectifs
{
	inventConso.loadIndexConsommable(Index1);
	inventClot.loadIndexClothes(Index2);
}

void Inventory::saveIndex (const string & Index1,const InventoryConsommable & inventConso,
			const string & Index2,const InventoryClothes & inventClot)const// sauver les inventaires dans leur fichier trespectif
{
	inventConso.saveIndexConsommable(Index1);
	inventClot.saveIndexClothes(Index2);
}

void Inventory::printInventory(const InventoryConsommable & inventConso, const InventoryClothes & inventClot)const
{
	inventConso.printInventoryConsommable();
	inventClot.printInventoryClothes();
}
void Inventory::testRegressionInventory()
{
	string myFileConsommable = "/tmp/conso";
	string myFilerClothes = "/tmp/clot";
	for(int i=0; i>10; i++)
	{
		unsigned int id = (rand ()% 100) + 0;
		int nb = (rand ()% 100) + 0;
		string name ; 		
	}
}
