
#include "InventoryConsommable.h"
using namespace std;

InventoryConsommable::InventoryConsommable()
{
}

InventoryConsommable::InventoryConsommable(const vector <Consommable>& consoBo)
{
	consommableBoard=consoBo;
}

InventoryConsommable::~InventoryConsommable()
{
	consommableBoard.clear();
}

void InventoryConsommable::setConsommableBoard(const vector <Consommable> & consoBo)
{
	consommableBoard=consoBo;
}

vector<Consommable> InventoryConsommable::getConsommableBoard()const 
{
	return consommableBoard;
}

void InventoryConsommable::loadIndexConsommable (const string & Index)
{
	ifstream index (Index.c_str());
	if (index.is_open()){
		string type;
		index>>type;
		if (type=="consommable")
		{
			string mot,nameIt;
			int nbIt, foo, hydra, hyg, happi;
			unsigned int idIt;
			unsigned int endFile;
			index>>endFile;
			for(unsigned int i=0; i<endFile; i++)
			{
				cout << "je suis la"<<endl;
				index>>idIt>>nameIt>>nbIt>>foo>>hydra>>hyg>>happi;
				Consommable conso(idIt, nameIt, nbIt, foo, hydra, hyg, happi);
				consommableBoard.push_back(conso);
			}
		}else 
		{
			cout << "Ce n'est pas le bon fichier"<<endl;
		}
	}else
	{
		cout<<"Erreur dans l'ouverture de"<<Index<<endl;
	}
	index.close();
}
unsigned int InventoryConsommable::calculNumberConsommable()const
{
	return consommableBoard.size();
}


void InventoryConsommable::saveIndexConsommable (const string & Index)const
{
	fstream index (Index.c_str());
	if(index.is_open())
	{
		string mot;
		index>>mot;
		if (mot=="consommable")
		{
			index<<mot<<endl;
			index<<calculNumberConsommable()<<endl;
			for(unsigned int i=0; i<consommableBoard.size(); i++)
			{
				index<<consommableBoard[i].getIdItem()<<" "<<consommableBoard[i].getNameItem()<<
						" "<<consommableBoard[i].getNumberItem()<<" "<<consommableBoard[i].getFood()
						<<" "<<consommableBoard[i].getHydration()<<" "<<consommableBoard[i].getHygiene()
						<<" "<<consommableBoard[i].getHappiness()<<endl;
			}
		}else
		{
			cout<<"Ce ne sont pas les bons fichiers"<<endl;
		}
	}else
	{
		cout<<"Erreur dans l'ouverture des fichiers"<<endl;
	}
	index.close();
}

void InventoryConsommable::printInventoryConsommable()const 
{
	cout<<"Voici vos denrées alimentaires"<<endl;
	for (unsigned int i =0; i<consommableBoard.size(); i++)
	{
		if (consommableBoard[i].getNumberItem()!=0)
		{
			consommableBoard[i].printItem();
		}
	}
}

void InventoryConsommable::addInInventoryConsommable(const Consommable & conso)
{
	unsigned int i=0;
	unsigned int size=consommableBoard.size();
	while ((i<size)&&(consommableBoard[i].getNameItem()!=conso.getNameItem()))
	{ 
		i++;
	};
	if (i<size) 
	{
			consommableBoard[i].setNumberItem(consommableBoard[i].getNumberItem()+1);
	}else
	{
		consommableBoard.push_back(conso);
	}
}

void InventoryConsommable::deleteFromInventoryConsommable(const unsigned int & idIt)
{
	unsigned int i=0;
	unsigned int size=consommableBoard.size();
	while ((i<size)&&(consommableBoard[i].getIdItem()!=idIt))
	{
		i++;
	}
	if ((i<size)&&(consommableBoard[i].getNumberItem()!=0))
	{
		consommableBoard[i].setNumberItem(consommableBoard[i].getNumberItem()-1);
	}
}


