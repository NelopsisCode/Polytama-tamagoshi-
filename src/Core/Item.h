
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
using namespace std;

/**
 @class <Item>
 * 
 * @brief Un Item est un objet qui permet de construire ensuite des vetements et des consommables
 * 
 * @param nameItem Nom de l'objet
 * @param idItem Identifiant de l'objet
 * @param numberItem Nombre d'objets
 * 
 * */
class Item {
public:
	
	//Constructeur/Destructeur
	/**
	 * @brief Constructeur par défaut
	 */
	Item();
	
	/**
	 * @brief Constructeur par copie
	 * @param nameIt Nom de l'objet à copier
	 * @param idIt Identifiant de l'objet à copier
	 */
	Item(const string & nameIt, const unsigned int & idIt);
	
	//SET/GET
	/**
	 * @brief Accesseur du nom de l'objet
	 * @return nom de l'objet
	 */
	string getNameItem()const;
	
	/**
	 * @brief Mutateur du nom de l'objet
	 * @param nameIt Nom de l'objet
	 */
	void setNameItem (const string & nameIt);
	
	/**
	 * @brief Accesseur de l'identifiant de l'objet
	 * @return identifiant de l'objet
	 */
	unsigned int getIdItem ()const;
	
	/**
	 * @brief Mutateur de l'identifiant de l'objet
	 * @param idIt idnetifiant de l'objet
	 */
	void setIdItem(const unsigned int & idIt);
	
	/**
	 * @brief Accesseur du nombre d'objets
	 * @return Nombre d'objets
	 */
	unsigned int getNumberItem()const;
	
	/**
	 * @brief Mutateur du nombre d'objets
	 * @param nbItem nombre d'objets
	 */
	void setNumberItem(const unsigned int &nbItem);
	
	//Fonctions membres
	/**
	 * @brief Affichage de l'objet
	 */
	void printItem()const;//permet d'afficher l'item
	
protected:
	string nameItem;
	unsigned int idItem;
	unsigned int numberItem;

};

#endif /* ITEM_H */

