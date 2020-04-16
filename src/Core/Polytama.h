#ifndef POLYTAMA_H
#define POLYTAMA_H

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>

#include "Bar.h"
#include "Item.h" //consommable + clothes
#include "Consommable.h"
#include "Clothes.h"
#include "InventoryConsommable.h"
#include "InventoryClothes.h"
#include "Mini_Game.h"


using namespace std;

const unsigned int DROPRATE = 1 ; //(chaque bar perd 1 toutes les DROPRATE min)


/**
\class <Polytama>

@brief Un Polytama est un petit être doté de besoins et de sentiments. 
Il peut aussi porter des vêtements pour briller en société.

@param tamaName Le nom du Polytama \n
@param TamaHealth Contient la santé du Polytama. Si cette barre atteint 0, c'est la fin... \n
@param TamaHunger La barre de faim du Polytama. Il faut penser à le nourir! \n	 
@param TamaJoy La barre de joie du Polytama. Ce petit être est sensible, il ne faut pas le contrarier...  \n	
@param TamaHygiene La barre de d'Hygiène du Polytama. Un bon bain de temps en temps ne lui fera pas de mal! \n	
@param TamaThirst La barre de soif du Polytam. L'eau c'est bon. Dans 20/30 ans y'en aura plus. \n	
@param TamaClothes Un tableau de pointeurs sur vêtements. 
*/
class Polytama
{

public:

//Constructeur

/**
@brief Constructeur par défaut du Polytama

Construit une Polytama nommé Bernard. Il est nu mais en bonne santé!
*/
	Polytama();

/**
@brief Constructeur à paramètre du Polytama

Construit un Polytama avec le nom souhaité. Il est nu mais en bonne santé!

@param [in] name Le nom du Polytama
*/
	Polytama(const string & name);
	
	~Polytama();

//Accesseur

/**
@brief Accesseur nom

Retourne le nom du Polytama.

*/	
	string getName()const;
/**
@brief Accesseur santé

Retourne la barre de santé du Polytama.

*/	
	Bar getHealth()const;
/**
@brief Accesseur faim

Retourne la barre de faim du Polytama.

*/	
	Bar getHunger()const;
/**
@brief Accesseur joie

Retourne la barre de joie du Polytama.

*/	
	Bar getJoy()const;

	void addJoy(const int & val);
	
	string getMood()const;
/**
@brief Accesseur hygiene

Retourne la barre d'hygiene du Polytama.

*/	
	Bar getHygiene()const;
/**
@brief Accesseur soif

Retourne la barre de soif du Polytama.

*/	
	Bar getThirst()const;

	Clothes * getClothes(const int & body)const;

/**
@brief Mutateur nom

Modifie le nom du Polytama.

@param [in] name Le nom à donner au Polytama
*/
	void setName(const string & name);

	void setHunger(const unsigned int & val);

	void setJoy(const unsigned int & val);

	void setHygiene(const unsigned int & val);

	void setThirst(const unsigned int & val);
	
//Fonction membres

/**
@brief Consomme un consommable et applique les effets au Polytama

@param [in] c l'aliment à consommer. Il contient les effets à appliquer au Polytama.
*/
	void consume(const Consommable & c);

/**
@brief Enlève un vêtement au Polytama.

@param [in] IdClo contient l'emplacement du vêtement à enlever.
*/
	void removeClothes(const IdBody & IdClo);// permet d'enlever un vetement du tama
/**
@brief Donne un vêtement au Polytama

@param [in] c est le vêtement à donner au Polytama.
*/
	void wearClothes(Clothes c);//permet de mettre un vetement au tama et d'enlever celui deja porté

/**
@brief Le Polytama effectue un dab. 
Cela le met de bonne humeur mais le fait transpirer un peu.
*/
	void dab();
/**
@brief Le Polytama prend un bain. 
Il est de nouveau tout propre ! 
*/
	void takeABath();

/**
@brief Afficher les jauges et le prénom du Polytama.
*/
	void printPolytama()const;
/**
@brief Sauvegarde l'état du Polytama dans un fichier.

@param [in] filename est le nom du fichier où le Polytama sera sauvegardé.
*/
	void save(const string & filename)const;
/**
@brief Charge l'état du Polytama depuis un fichier.
La fonction récupère les informations dans le fichier et les applique au Polytama.

@param [in] filename est le nom du fichier à charger.
@parama [in-out] time est un entier récupéré pour être utilisé dans la fonction pastTime().
*/
	void loadSave (const string & filename, long int & time);
/**
@brief Cette fonction gère le temps écoulé depuis la dernière fermeture du programme.

Elle applique ensuite les effets du temps passé au Polytama.

@param [in] time correspond à une durée. Plus précisement il s'agit de la durée (en sec) entre le 1er janvier 1970 et la dernière fermeture du programme.
*/
	void pastTime(const long int & time);
/**
@brief Test de regression de la classe Polytama.

Test toutes les fonctions de la classe et renvoie une erreur si une des fonctions ne fonctionne pas correctement.
*/
	void polytamaTestRegression();

	void polytamaTest();

private:

	string tamaName;

	Clothes * tamaClothes[3];

	Bar tamaHealth;
	Bar tamaHunger;
	Bar tamaJoy;
	Bar tamaHygiene;
	Bar tamaThirst;

};

#endif