
#ifndef CLOTHES_H
#define CLOTHES_H
#include "Item.h"
/**
 @enum IdBody
 */
enum IdBody{ HEAD,CHEST,ACCESSORY };

/**
 @class <Clothes>
 * 
 * @brief Un Clothes est un vetement que peut porter le polytama
 * @param slotClothes Position du vetement sur le corps du polytama
 */
class Clothes : public Item {
public:
	
	//Constructeur/Destructeur
	/**
	 * @brief Constructeur par défaut
	 */
	Clothes();
	
	/**
	 * @brief Constructeur par copie
	 * @param slotC Position du vetement sur le corps du polytama a copier
	 * @param idIt Identifiant du vetement a copier
	 * @param nameIt Nom du vetement a copier
	 * @param nbIt Nombre du vetement a copier
	 */
	Clothes(const IdBody & slotC, const unsigned int & idIt, 
		const string & nameIt, const int & nbIt);
	
	//SET/GET
	/**
	 * @brief Mutateur de la position du vetement
	 * @param slotC Position du vetement
	 */
	void setSlotClothes (const IdBody & slotC);
	
	/**
	 * @brief Accesseur de la position du vetement
	 * @return Position du vetement
	 */
	IdBody getSlotClothes ()const; //renvoie l'emplaçement du vêtement
	
	/**
	 * @brief Affichage du vetement
	 */
	void printClothes()const;
	
	/**
	 * @brief Surchage d'operateur =
	 * @param cloth vetement a copier
	 * @return Vetement
	 */
 	Clothes operator=(const Clothes& cloth);// surcharge du =
private:
	IdBody slotClothes; //emplacement du vêtement (Tête, corps, accessoire)

};

#endif