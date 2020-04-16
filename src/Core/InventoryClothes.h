
#ifndef INVENTORYCLOTHES_H
#define INVENTORYCLOTHES_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <assert.h>
#include "Item.h"
#include "Clothes.h"


using namespace std;
/**
 * @class <InventoryClothes>
 * 
 * @brief Un InventoryClothes est un inventaire de vetements
 * 
 * @param clothesBoard Tableau de vetements
 */
class InventoryClothes {
public:
	
	//Constructeur/Destructeur
	/**
	 * @brief Constructeur par defaut
	 */
	InventoryClothes();
	
	/**
	 * @brief Constrcuteur par copie
	 * @param clothesBo Tableau de vetements a copier
	 */
	InventoryClothes(const vector <Clothes>& clothesBo);
	
	/**
	 * @brief  Destructeur
	 */
	~InventoryClothes();
	
	//GET/SET
	/**
	 * @brief Mutateur du tableau de vetements
	 * @param clothesBo Tableau de vetements
	 */
	void setClothesBoard(const vector <Clothes> & clothesBo);
	
	/**
	 * @brief Accesseur du tableau de vetements
	 * @return Tableau de vetements
	 */
	vector<Clothes> getClothesBoard()const;
	
	//Fonctions membres
	/**
	 * @brief Chargement d'un fichier de vetements dans l'inventaire
	 * @param Index Fichier de vetement
	 */
	void loadIndexClothes (const string & Index);
	
	/**
	 * @brief Chargement de l'inventaire dans un fichier de clothes
	 * @param Index Fichier de vetement
	 */
	void saveIndexClothes (const string & Index)const;
	
	/**
	 * @brief Affichage de l'inventaire, si le nombre de vetements est a 0, il n'est pas affiche
	 */
	void printInventoryClothes()const;
	
	/**
	 * @brief Ajout d'un vetement dans l'inventaire, son nombre augmente de 1
	 * @param clot Vetement a ajouter
	 */
	void addInInventoryClothes(const Clothes & clot);
	
	/**
	 * @brief Suppresssion du vetement de l'inventaire, son nombre diminue de 1
	 * @param idIt Identifiant du vetement a suppprimer
	 */
	void deleteFromInventoryClothes(const unsigned int & idIt);
	
	/**
	 * @brief Calcul du nombre de types de vetements presents dans l'inventaire
	 * @return Nombre de types de vetements
	 */
	unsigned int calculNumberClothes()const; 
	
	/**
	 * @brief Calcul du nombre total de vetements dans l'inventaire
	 * @return Nombre tital de vetements 
	 */
	unsigned int NumberClothes()const;
	
	/**
	 * @brief Recherche d'un vetement dans l'inventaire d'apres son nom
	 * @param name Nom du vetement a chercher
	 * @return Vetement( vetement null si il n'est pas present dans l'inventaire)
	 */
	Clothes searchInInventoryClothes(const string& name)const;//cherche l'item dans l'inventaire d'apres son nom
	
	/**
	 * @brief Recherche d'un vetement dans l'inventaire d'apres son identifiant
	 * @param id Identifiant d'un vetement a chercher
	 * @return Vetement( vetement null si il n'est pas present dans l'inventaire)
	 */
	Clothes searchIdInInventoryClothes(const unsigned int & idIt)const;//cherche l'item dans l'inventaire d'apres son id
	
private:
	vector<Clothes> clothesBoard;
	
};

#endif /* INVENTORYCLOTHES_H */

