#include "Polytama.h"

using namespace std;

Polytama::Polytama()
{

	tamaName = "Bernard";
	tamaHealth.setValue(100);
	tamaJoy.setValue(100);
	tamaHunger.setValue(100);
	tamaThirst.setValue(100);
	tamaHygiene.setValue(100);

	for (unsigned int i = 0; i < 3; i++)
	{
		tamaClothes[i] = nullptr;
	}
}

Polytama::Polytama(const string &name)
{
	tamaName = name;
	tamaHealth.setValue(100);
	tamaJoy.setValue(50);
	tamaHunger.setValue(50);
	tamaThirst.setValue(50);
	tamaHygiene.setValue(50);

	for (unsigned int i = 0; i < 3; i++)
	{
		tamaClothes[i] = nullptr;
	}
}

Polytama::~Polytama()
{
	for (unsigned int i = 0; i < 3; i++)
	{
		if (tamaClothes[i] != nullptr)
		{
			delete (tamaClothes[i]);
		}
	}
}

string Polytama::getName() const
{
	return tamaName;
}

Bar Polytama::getHealth() const
{
	return tamaHealth;
}

Bar Polytama::getHunger() const
{
	return tamaHunger;
}

Bar Polytama::getJoy() const
{
	return tamaJoy;
}

void Polytama::addJoy(const int &val)
{
	if (val >= 0)
	{
		tamaJoy += val;
	}
	else
	{
		tamaJoy -= val;
	}
}

string Polytama::getMood() const
{
	string mood;
	if (tamaJoy.getValue() < 35)
	{
		mood = 's';
	}
	else if (tamaJoy.getValue() >= 35 and tamaJoy.getValue() < 70)
	{
		mood = 'n';
	}
	else
	{
		mood = 'j';
	}
	return mood;
}

Bar Polytama::getHygiene() const
{
	return tamaHygiene;
}

Bar Polytama::getThirst() const
{
	return tamaThirst;
}

Clothes *Polytama::getClothes(const int &body) const
{
	return tamaClothes[body];
}

void Polytama::setName(const string &name)
{
	tamaName = name;
}

void Polytama::setHunger(const unsigned int &val)
{
	if(val>=0 and val<=100)
	{
		tamaHunger.setValue(val);
	}
	else
	{
		tamaHunger.setValue(0);
	}	
	
}

void Polytama::setJoy(const unsigned int &val)
{
	if(val>=0 and val<=100)
	{
		tamaJoy.setValue(val);
	}
	else
	{
		tamaJoy.setValue(0);
	}	
}
void Polytama::setHygiene(const unsigned int &val)
{
	if(val>=0 and val<=100)
	{
		tamaHygiene.setValue(val);
	}
	else
	{
		tamaHygiene.setValue(0);
	}		
}

void Polytama::setThirst(const unsigned int &val)
{
	if(val>=0 and val<=100)
	{
		tamaThirst.setValue(val);
	}
	else
	{
		tamaThirst.setValue(0);
	}		
}
void Polytama::consume(const Consommable &c)
{

	if (c.getFood() >= 0)
	{
		tamaHunger += c.getFood();
	}
	else
	{
		tamaHunger -= -(c.getFood());
	}

	if (c.getHydration() >= 0)
	{
		tamaThirst += c.getHydration();
	}
	else
	{
		tamaThirst -= -(c.getHydration());
	}

	if (c.getHygiene() >= 0)
	{
		tamaHygiene += c.getHygiene();
	}
	else
	{
		tamaHygiene -= -(c.getHygiene());
	}

	if (c.getHappiness() >= 0)
	{
		tamaJoy += c.getHappiness();
	}
	else
	{
		tamaJoy -= -(c.getHappiness());
	}
}

void Polytama::removeClothes(const IdBody &IdClo)
{
	tamaClothes[IdClo] = nullptr;
}

void Polytama::wearClothes(Clothes c)
{
	if (tamaClothes[c.getSlotClothes()] != nullptr)
	{
		removeClothes(c.getSlotClothes()); //suppression du vêtement
	}

	Clothes *clo = new Clothes;
	*clo = c;
	tamaClothes[c.getSlotClothes()] = clo;
}

void Polytama::dab()
{
	//cout << tamaName << " effectue le dab (dans un endroit inadéquat..)" << endl << endl;
	tamaJoy += 10;
	tamaHygiene -= 10;
}

void Polytama::takeABath()
{
	cout << tamaName << " va prendre un bain." << endl;

	//Peut être amélioré en ajoutant de le rng
	cout << tamaName << " est tout propre!" << endl
		 << endl;
	tamaHygiene.setValue(100);
}

void Polytama::printPolytama() const
{
	cout << "Prénom: " << tamaName << endl;
	cout << "Faim: " << tamaHunger.getValue() << endl;
	cout << "Soif: " << tamaThirst.getValue() << endl;
	cout << "Joie: " << tamaJoy.getValue() << endl;
	cout << "Hygiene: " << tamaHygiene.getValue() << endl;
	cout << "Vie: " << tamaHealth.getValue() << endl
		 << endl;
}

void Polytama::save(const string &filename) const
{
	ofstream savefile(("data/" + filename).c_str());

	if (!savefile.is_open())
	{
		cout << "Problème dans l'ouverture du fichier" << endl;
		exit(EXIT_FAILURE);
	}
	//écrit dans le fichier save
	savefile << tamaName << " ";
	savefile << tamaHealth.getValue() << " ";
	savefile << tamaHunger.getValue() << " ";
	savefile << tamaJoy.getValue() << " ";
	savefile << tamaHygiene.getValue() << " ";
	savefile << tamaThirst.getValue() << " ";
	//cout << "ok" << endl;
	for (int i = 0; i < 3; i++)
	{
		if (tamaClothes[i] != nullptr)
		{
			savefile << tamaClothes[i]->getIdItem() << " ";
			//savefile << tamaClothes[i]->getNameItem() << " ";
		}
		else
		{
			savefile << "nullptr"
					 << " ";
		}
		//cout << "ok" << endl;
	}

	savefile << (long int)time(NULL); //temps passé depuis le 1er janvier 1970

	savefile.close();
}

void Polytama::loadSave(const string &filename, long int &time)
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

	for (int i = 0; i < 3; i++)
	{
		savefile >> clothes;

		if (clothes != "nullptr")
		{
			//string nameClo;
			//savefile >> nameClo;
			unsigned int a = atoi(clothes.c_str());

			Clothes *c = new Clothes((IdBody)i, a, "", 1);

			if (tamaClothes[i] != nullptr)
			{
				delete tamaClothes[i];
			}
			tamaClothes[i] = c;
		}
	}

	savefile >> time; //le temps passé depuis le 1er janvier 1970 à la dernière sauvegarde

	savefile.close();
}

void Polytama::pastTime(const long int &initTime)
{

	long int pasttime = (long int)time(NULL) - initTime;

	//cout << pasttime << "sec" << endl;

	pasttime = pasttime / 60;

	//cout << pasttime << "min" << endl;

	unsigned int drop = pasttime / DROPRATE;

	//cout << drop <<endl;

	tamaHygiene -= drop;

	tamaHunger -= drop;

	tamaJoy -= drop;

	tamaThirst -= drop;

	if (tamaThirst.getValue() == 0 || tamaHygiene.getValue() == 0 || tamaHunger.getValue() == 0 || tamaThirst.getValue() == 0)
	{
		tamaHealth -= drop/2;
	}
}


bool Polytama::dead()const
{
	return tamaHealth.getValue() <= 0;
}

void Polytama::revive()
{
	for(unsigned int i = 0 ; i < 3 ;i++)
	{
		if(tamaClothes[i] != nullptr)
		{
			removeClothes((IdBody)i);
		}
	}
	InventoryConsommable conso;
	conso.loadIndexConsommable("data/initIndexConsommable.txt");
	conso.saveIndexConsommable("data/indexConsommable.txt");
	InventoryClothes clo;
	clo.loadIndexClothes("data/initIndexClothes.txt");
	clo.saveIndexClothes("data/indexClothes.txt");
	tamaHealth.setValue(100);
	tamaHunger.setValue(1);
	tamaHygiene.setValue(1);
	tamaJoy.setValue(1);
	tamaThirst.setValue(1);
}

void Polytama::electrocute()
{
	tamaHealth.setValue(0);
}

void Polytama::polytamaTestRegression()
{
	//constructeur
	cout << "Vérification du constructeur" << endl;
	assert(tamaName == "Bernard" and
		   tamaHealth.getValue() == 100 and
		   tamaHunger.getValue() == 100 and
		   tamaJoy.getValue() == 100 and
		   tamaHygiene.getValue() == 100 and
		   tamaThirst.getValue() == 100 and
		   tamaClothes[0] == nullptr and
		   tamaClothes[1] == nullptr and
		   tamaClothes[2] == nullptr);
	cout << "constructeur ok" << endl;

	//Accesseur
	cout << "Vérification des accesseurs et mutateur" << endl;
	assert(getName() == tamaName);
	assert(getHealth().getValue() == tamaHealth.getValue());
	assert(getHunger().getValue() == tamaHunger.getValue());
	assert(getJoy().getValue() == tamaJoy.getValue());
	assert(getHygiene().getValue() == tamaHygiene.getValue());
	assert(getThirst().getValue() == tamaThirst.getValue());
	//mutateur
	setName("Tanguy");
	assert(tamaName == "Tanguy");
	cout << "accesseurs et mutateur ok" << endl
		 << endl;

	//fonctions membres
	//consume
	cout << "Vérification de consume()" << endl;
	tamaHunger -= 20;
	assert(tamaHunger.getValue() == 80);
	Consommable c(18, "kebab à la sangria",
				  1, 10, 0,
				  -10, -5);
	consume(c);
	assert(tamaHunger.getValue() == 90 and
		   tamaThirst.getValue() == 100 and
		   tamaHygiene.getValue() == 90 and
		   tamaJoy.getValue() == 95);
	cout << "consume() ok" << endl;

	//wear and remove clothes
	cout << "Vérification de wearClothes() et removeClothes()" << endl;
	Clothes v(CHEST, 124,
			  "maillot 2 foute", 1);

	wearClothes(v);

	assert(tamaClothes[0] == nullptr and
		   tamaClothes[2] == nullptr and
		   tamaClothes[1]->getIdItem() == 124 and
		   tamaClothes[1]->getNameItem() == "maillot 2 foute");

	removeClothes(CHEST);
	assert(tamaClothes[0] == nullptr and
		   tamaClothes[1] == nullptr and
		   tamaClothes[2] == nullptr);

	cout << "wearClothes() et removeClothes() ok" << endl;

	//dab
	cout << "Vérification de dab()" << endl;
	tamaJoy -= 15; // (maintenant tamaJoy = 80)
	dab();
	assert(tamaJoy.getValue() == 90 and
		   tamaHygiene.getValue() == 80);
	cout << "dab() ok" << endl;

	//takeAbath
	cout << "Vérification de takeABath" << endl;
	takeABath();
	assert(tamaHygiene.getValue() == 100);
	cout << "takeABath ok" << endl;

	//print Polytama
	printPolytama();
	cout << "ok" << endl;

	//save et loadSave
	cout << "Vérification de save() et loadSave()" << endl;

	cout << "sauvegarde dans le fichier regressionSave.txt" << endl;
	save("regressionSave.txt");

	cout << "baisse de toutes les jauges à 10" << endl;
	tamaName = "zaezaeaze";
	tamaHealth.setValue(10);
	tamaJoy.setValue(10);
	tamaHunger.setValue(10);
	tamaThirst.setValue(10);
	tamaHygiene.setValue(10);
	cout << "chargement de la sauvegarde" << endl;
	long int a; //a est normalement utilisé pour la fonction pastTime()
	loadSave("regressionSave.txt", a);

	assert(
		tamaName == "Tanguy" and
		tamaHealth.getValue() == 100 and
		tamaHunger.getValue() == 90 and
		tamaJoy.getValue() == 90 and
		tamaThirst.getValue() == 100 and
		tamaHygiene.getValue() == 100);

	cout << "save() et loadSave() ok" << endl;

	//pasttime
	cout << "Vérification de pastTime()" << endl;

	long int t = (long int)time(NULL) - 301; //On simule l'ouverture du programme 5min après la dernière sauvegarde

	unsigned int drop = DROPRATE * 5;
	unsigned int hunger = tamaHunger.getValue() - drop;
	unsigned int joy = tamaJoy.getValue() - drop;
	unsigned int thirst = tamaThirst.getValue() - drop;
	unsigned int hygiene = tamaHygiene.getValue() - drop;

	pastTime(t);
	assert(
		tamaHunger.getValue() == hunger and
		tamaJoy.getValue() == joy and
		tamaThirst.getValue() == thirst and
		tamaHygiene.getValue() == hygiene);
	cout << "pastTime() ok" << endl;

	cout << "test de Regression OK" << endl;
}

