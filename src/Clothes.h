
#ifndef CLOTHES_H
#define CLOTHES_H
#include "Item.h"

enum IdBody{ Head,Chest,Accessory };

class Clothes : public Item {
public:
	
	//Constructeur/Destructeur
	Clothes();
	Clothes(const IdBody& idClo);
	~Clothes();
	
	//SET/GET
	void setClothes (const IdBody & IdClo);
	IdBody getClothes ()const; //renvoie l'empla�ement du v�tement
	
	
 	Clothes operator=(const Clothes& cloth);// surcharge du =
private:
	IdBody slotClothes; //emplacement du v�tement (T�te, corps, accessoire)

};

#endif /* CLOTHES_H */

