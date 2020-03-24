
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
	IdBody getClothes ()const; //renvoie l'emplaçement du vêtement
	
	
 	Clothes operator=(const Clothes& cloth);// surcharge du =
private:
	IdBody slotClothes; //emplacement du vêtement (Tête, corps, accessoire)

};

#endif /* CLOTHES_H */

