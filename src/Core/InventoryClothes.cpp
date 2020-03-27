
#include "InventoryClothes.h"
using namespace std;

InventoryClothes::InventoryClothes()
{
}

InventoryClothes::InventoryClothes(const vector <Clothes>& clothesBo)
{
	clothesBoard=clothesBo;
}

InventoryClothes::~InventoryClothes()
{
	clothesBoard.clear();
}

void InventoryClothes::setClothesBoard(const vector <Clothes> & clothesBo)
{
	clothesBoard=clothesBo;
}

vector<Clothes> InventoryClothes::getClothesBoard()const 
{
	return clothesBoard;
}

void InventoryClothes::loadIndexClothes (const string & Index)
{
	ifstream index(Index.c_str());
	if (index.is_open())
	{
		string type;
		index>>type;
		if (type=="clothes")
		{
			unsigned int idIt, nbIt, slClo, endFile;
			string nameIt;
			IdBody slotC;
			index>>endFile;
			for(unsigned int i; i<endFile; i++)
			{
				index>>idIt>>nameIt>>nbIt>>slClo;
				slotC=(IdBody) slClo ;
				Clothes clot(slotC,idIt,nameIt,nbIt);
				clothesBoard.push_back(clot);
			}
		}else 
		{
			cout << "Ce n'est pas le bon fichier clothes"<<endl;
		}
	}else
	{
		cout<<"Erreur dans l'ouverture de"<<Index<<endl;
	}
	index.close();
}



unsigned int InventoryClothes::calculNumberClothes()const
{
	return clothesBoard.size();
}

void InventoryClothes::saveIndexClothes (const string & Index)const
{
	fstream index (Index.c_str());
	if(index.is_open())
	{
		string mot;
		index>>mot;
		if(mot=="clothes")
		{
			index<<mot<<endl;
			index<<calculNumberClothes()<<endl;
			for(unsigned int i=0; i<clothesBoard.size(); i++)
			{
					index<<clothesBoard[i].getIdItem()<<" "<<clothesBoard[i].getNameItem()
						<<" "<<clothesBoard[i].getNumberItem()<<" "<<clothesBoard[i].getSlotClothes()
						<<endl;
			}
		}else
		{
			cout<<"Ce n'est pas le bon fichier clothes"<<endl;
		}
	}else
	{
		cout<<"Erreur dans l'ouverture du fichier clothes"<<endl;
	}
	index.close();
}

void InventoryClothes::printInventoryClothes()const 
{
	cout<<"Voici vos vétements et accessoires"<<endl;
	for (unsigned int i =0; i<clothesBoard.size(); i++)
	{
		if (clothesBoard[i].getNumberItem()!=0)
		{
			clothesBoard[i].printItem();
		}
	}
}

void InventoryClothes::addInInventoryClothes(const Clothes & clot)
{
	unsigned int i=0;
	unsigned int size=clothesBoard.size();
	while ((i<size)&&(clothesBoard[i].getNameItem()!=clot.getNameItem()))
	{ 
		i++;
	};
	if (i<size) 
	{
			clothesBoard[i].setNumberItem(clothesBoard[i].getNumberItem()+1);
	}else
	{
		clothesBoard.push_back(clot);
	}
}

void InventoryClothes::deleteFromInventoryClothes(const unsigned int & idIt)
{
	unsigned int i=0;
	unsigned int size=clothesBoard.size();
	while ((i<size)&&(clothesBoard[i].getIdItem()!=idIt))
	{
		i++;
	}
	if ((i<size)&&(clothesBoard[i].getNumberItem()!=0))
	{
		clothesBoard[i].setNumberItem(clothesBoard[i].getNumberItem()-1);
	}
}


