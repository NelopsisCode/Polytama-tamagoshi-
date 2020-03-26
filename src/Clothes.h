
#ifndef CLOTHES_H
#define CLOTHES_H
#include "Item.h"

enum IdBody{ HEAD,CHEST,ACCESSORY };

class Clothes : public Item {
public:
	
	//Constructeur/Destructeur
	Clothes();
	Clothes(const IdBody & slotC, const unsigned int & idIt, 
		const string & nameIt, const int & nbIt);
	~Clothes();
	
	//SET/GET
	void setSlotClothes (const IdBody & slotC);
	IdBody getSlotClothes ()const; //renvoie l'empla�ement du v�tement
	
	
 	Clothes operator=(const Clothes& cloth);// surcharge du =
private:
	IdBody slotClothes; //emplacement du v�tement (T�te, corps, accessoire)

};

#endif /* CLOTHES_H */

