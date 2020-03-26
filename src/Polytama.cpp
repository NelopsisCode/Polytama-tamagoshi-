#include "Polytama.h"

using namespace std;

Polytama::Polytama()
{
	//à changer d'emplacement (faire une fonction de création du Tama)
	//cout <<"Comment s'appel le PolyTama? " <<endl;
	//cin >> tamaName ;
	tamaName = "Boris";
	tamaHealth.setValue(100);
	tamaJoy.setValue(100);
	tamaHunger.setValue(100);
	tamaThirst.setValue(100);
	tamaHygiene.setValue(100);

	tamaClothes[0] = nullptr;
	tamaClothes[1] = nullptr;
	tamaClothes[2] = nullptr;


}


Polytama::~Polytama()
{

}

string Polytama::getName()const
{
	return tamaName;
}

Bar Polytama::getHealth()const
{
	return tamaHealth;
}

Bar Polytama::getHunger()const
{
	return tamaHunger;
}

Bar Polytama::getJoy()const
{
	return tamaJoy;
}

Bar Polytama::getHygiene()const
{
	return tamaHygiene;
}


void Polytama::consume(const Consommable & c)
{
	tamaHunger += c.getFood();
	tamaThirst += c.getHydration();
	tamaHygiene += c.getHygiene();
	tamaJoy += c.getHappiness();
}

void Polytama::removeClothes(const IdBody & IdClo)
{
	tamaClothes[IdClo] = nullptr;
}	

void Polytama::wearClothes(Clothes c)
{
	if (tamaClothes[c.getSlotClothes()] != nullptr)
	{
		removeClothes(c.getSlotClothes()); //suppression du vêtement
	}

	tamaClothes[c.getSlotClothes()] = &c;	
}




void Polytama::dab()
{
	cout << tamaName << " effectue le dab (dans un endroit inadéquat..)" << endl << endl;

	tamaJoy += 10;
	tamaHygiene -=10; 
}

void Polytama::takeAbath()
{
	cout << tamaName << " va prendre un bain." << endl;

	//Peut être amélioré en ajoutant de le rng
	cout << tamaName << " est tout propre!" << endl << endl;
	tamaHygiene.setValue(100);
}


void Polytama::printPolytama()const
{
	cout << "Prénom: " << tamaName << endl;
	cout << "Faim: " << tamaHunger.getValue() << endl;
	cout << "Soif: " << tamaThirst.getValue() <<endl;
	cout << "Joie: " << tamaJoy.getValue() << endl;
	cout << "Hygiene: " << tamaHygiene.getValue() << endl;
	cout << "Vie: " << tamaHealth.getValue() << endl << endl;
}

void Polytama::save (const string & filename )const
{
	ofstream savefile(("data/" + filename).c_str());

	if (!savefile.is_open())
	{
		cout << "Problème dans l'ouverture du fichier" << endl;
		exit(EXIT_FAILURE);
	}
//écrit dans le fichier save
	savefile << tamaName << " " ;
	savefile << tamaHealth.getValue() << " " ; 
	savefile << tamaHunger.getValue() << " " ; 
	savefile << tamaJoy.getValue() << " " ; 
	savefile << tamaHygiene.getValue() << " " ; 
	savefile << tamaThirst.getValue() << " " ; 
	for (int i = 0; i<3 ; i++)
	{
		if(tamaClothes[i] != nullptr)
		{
			savefile << tamaClothes[i]->getIdItem() << " " ; 
		}
		else
		{
			savefile << "nullptr" << " " ; 
		}
	}

	savefile << (double) time(NULL); //temps passé depuis le 1er janvier 1970

	savefile.close();
}


void Polytama::loadSave (const string & filename, double & time)
{

	ifstream savefile(("data/" + filename).c_str());

	if (!savefile.is_open())
	{
		cout << "Problème dans l'ouverture du fichier" << endl;
		exit(EXIT_FAILURE);
	}

	savefile >> tamaName;

	unsigned int a;

	savefile >> a;
	tamaHealth.setValue(a);
	savefile >> a;
	tamaHunger.setValue(a);
	savefile >> a;
	tamaJoy.setValue(a);
	savefile >> a;
	tamaHygiene.setValue(a);
	savefile >> a;
	tamaThirst.setValue(a);

	string clothes;

	for(int i = 0 ; i < 3 ; i++)
	{
		savefile >> clothes;

		if (clothes != "nullptr")
		{
			unsigned int a = atoi(clothes.c_str());

			Clothes c((IdBody)i, a, "", 1);
			tamaClothes[i] = &c;
		}
	}
	
	savefile >> time; //le temps passé depuis le 1er janvier 1970 à la dernière sauvegarde

	savefile.close();
}


void Polytama::pastTime(const double & initTime)
{
	double pasttime = (double) time(NULL) - initTime;
	
	cout << pasttime << "sec" << endl;

	pasttime = pasttime / 60;

	cout << pasttime << "min" << endl;

	unsigned int drop = pasttime / DROPRATE;

	cout << drop <<endl;

	tamaHygiene -= drop;

	tamaHunger -= drop;

	tamaJoy -= drop;

	tamaThirst -= drop;


}




void Polytama::polytamaTest()
{
	double initTime;
	loadSave("testsave.txt",initTime);

	cout << initTime << endl;

	pastTime(initTime);

	printPolytama();
	//Inventory manger;
	//manger.loadIndexConsommable("src/index.txt");
	cout << "Vous pouvez :"<<endl;
	cout<<"1 : Faire dabber "<<tamaName<<endl;
	cout<<"2 : Lui donner un bain "<<endl;
	cout<<"3 : Jouer avec lui "<<endl;
	cout<<"4 : lui donner à manger"<<endl;
	cout<<"5 : afficher l'inventaire"<<endl;
	cout<<"6 : Ne rien faire"<<endl;
	unsigned int i=0;
	cin>>i;
	switch (i) {
		case 1 : { 
			dab();
			printPolytama();
		} break;
		case 2 : { 
			takeAbath();
			printPolytama();
		}break;
		case 3 : {
			//minigame();
			cout<<"impossible pour l'instant"<<endl;
		}break;
		case 4 : {
			//avec l'inventaire
			cout<<"impossible pour l'instant"<<endl;
		}break;
		case 5 : {	
			//manger.printInventory();
		}break;	
		
		default : {
			cout<<"Veuillez choisir une proposition ci-dessus"<<endl;
		}break;
	}

	save("testsave.txt");
}