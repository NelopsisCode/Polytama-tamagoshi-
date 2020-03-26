
#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H
#include "Item.h"
#include "Bar.h"
using namespace std;

class Consommable : public Item {
public:
	
	//Constructeur/Destructeur
	Consommable();
	Consommable(const unsigned int& idIt,const string& nameIt,
		const int& nbIt,const int &foo, const int& hydra, 
		const int& hyg, const int& happi);
	~Consommable();
	
	//SET/GET
	void setFood (const int& foo);
	int getFood()const;
	void setHydration(const int & hydra);
	int getHydration ()const;
	void setHygiene(const int& hyg);
	int getHygiene ()const;
	void setHappiness (const int & happi);
	int getHappiness ()const;
	
	//surcharge =
	Consommable operator=(const Consommable& conso);
	

	
private:
	int food;
	int hydration;
	int hygiene;
	int happiness;

};

#endif /* CONSOMMABLE_H */

