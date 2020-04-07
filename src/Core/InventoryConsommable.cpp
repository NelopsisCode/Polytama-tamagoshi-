
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
				index>>idIt>>nameIt>>nbIt>>foo>>hydra>>hyg>>happi;
				Consommable conso(idIt, nameIt, nbIt, foo, hydra, hyg, happi);
				consommableBoard.push_back(conso);
			}
		}else 
		{
			cout << "Ce n'est pas le bon fichier consommable"<<endl;
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

unsigned int InventoryConsommable::NumberConsommable()const
{
	unsigned int a = 0, size;
	size=consommableBoard.size();
	for (unsigned int i=0; i<size; i++)
	{
		a=a+consommableBoard[i].getNumberItem();
	}
	return a;
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
			index<<endl;
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
			cout<<"Ce n'est pas le bon fichier consommable"<<endl;
		}
	}else
	{
		cout<<"Erreur dans l'ouverture du fichier consommable"<<endl;
	}
	index.close();
}

void InventoryConsommable::printInventoryConsommable()const 
{
	cout<<"Voici vos denr�es alimentaires restants"<<endl;
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
	assert(i<size);
	if (consommableBoard[i].getNumberItem()!=0)
	{
		consommableBoard[i].setNumberItem(consommableBoard[i].getNumberItem()-1);
	}
}

Consommable InventoryConsommable::searchInInventoryConsommable(const string& name)const
{
	unsigned int i=0;
	unsigned int size=consommableBoard.size();
	while((i<size)&&(consommableBoard[i].getNameItem()!=name))
	{
		i++;
	}
	if(i<size)
	{
		return consommableBoard[i];
	}else 
	{
		Consommable conso(0,"null",0,0,0,0,0);
		return conso;
	}
}

Consommable InventoryConsommable::searchIdInInventoryConsommable(const unsigned int& id)const
{
	unsigned int i=0;
	unsigned int size=consommableBoard.size();
	while((i<size)&&(consommableBoard[i].getIdItem()!=id))
	{
		i++;
	}
	if(i<size)
	{
		return consommableBoard[i];
	}else 
	{
		Consommable conso(0,"null",0,0,0,0,0);
		return conso;
	}
}