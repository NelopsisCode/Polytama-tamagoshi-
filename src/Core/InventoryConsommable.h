#ifndef INVENTORYCONSOMMABLE_H
#define INVENTORYCONSOMMABLE_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <assert.h>
#include "Item.h"
#include "Consommable.h"

using namespace std;
/**
 @class <InventoryConsommable>
 * 
 * @brief Un InventoryConsommable est un inventaire de consommables, c'est-a-dire de denrées alimentaires
 * 
 * @param consommableBoard Tableau de consommables
 
 */
class InventoryConsommable {
public:
	
	//Constructeur/Destructeur
	/**
	 * @brief Constructeur par défaut
	 */
	InventoryConsommable();
	
	/**
	 * @brief Constructeur par copie
	 * @param consoBo Tableau de consommables a copier
	 */
	InventoryConsommable(const vector <Consommable>& consoBo);
	
	/**
	 * @brief Destructeur
	 */
	~InventoryConsommable();
	
	//GET/SET
	/**
	 * @brief Mutateur du tableau de consommables
	 * @param consoBo Tableau de consommables
	 */
	void setConsommableBoard(const vector <Consommable> & consoBo);
	
	/**
	 * @brief Accesseur du tableau de consommables
	 * @return Tableau de consommables
	 */
	vector<Consommable> getConsommableBoard()const;
	
	//Fonctions membres
	/**
	 * @brief Chargement d'un fichier de consommables dans l'inventaire
	 * @param Index Fichier de consommables
	 */
	void loadIndexConsommable (const string & Index);
	
	/**
	 * @brief Chargement de l'inventaire dans un fichier de consommables
	 * @param Index Fichier de consommables
	 */
	void saveIndexConsommable (const string & Index)const;
	
	/**
	 * @brief Affichage de l'inventaire, tous les consommables dont le nombre est different de 0 sont affichés
	 */
	void printInventoryConsommable()const;
	
	/**
	 * @brief Ajout d'un consommable dans l'inventaire, son nombre augmente de 1
	 * @param conso Consommable a ajouter
	 */
	void addInInventoryConsommable(const Consommable & conso);
	
	/**
	 * @brief Suppression d'un consommable, son nombre diminue de 1
	 * @param idIt Identifiant du consommable a supprimer
	 */
	void deleteFromInventoryConsommable(const unsigned int & idIt);
	
	/**
	 * @brief Calcul du nombre de types de consommables dans l'inventaire
	 * @return Nombre de types de consommables dans l'inventaire
	 */
	unsigned int calculNumberConsommable()const;
	
	/**
	 * @brief Calcul du nombre total de consommables dans l'inventaire
	 * @return Nombre total de consommables dans l'inventaire
	 */
	unsigned int NumberConsommable()const; 
	
	/**
	 * @brief Recherche d'un consommable d'apres le nom dans l'inventaire
	 * @param name Nom du consommable a chercher
	 * @return Consommable 
	 */
	Consommable searchInInventoryConsommable(const string& name)const;
	
	/**
	 * @brief Recherche d'un consommable d'apres l'indentifiant dans l'inventaire
	 * @param id Identifiant du consommable a chercher
	 * @return Consommable
	 */
	Consommable searchIdInInventoryConsommable(const unsigned int& idIt)const; //cherche un objet dans l'inventaire d'apres son id
	
private:
	vector<Consommable> consommableBoard;
	
};

#endif /* INVENTORY_H */

