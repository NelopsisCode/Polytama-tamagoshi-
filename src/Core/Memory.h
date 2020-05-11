#ifndef MEMORY_H
#define MEMORY_H
#include <iostream>
#include <string>
#include <cassert>
#include <time.h>
#include "Mini_Game.h"
using namespace std;

/**
 * @struct <Image>
 * @brief Une Image est un lien vers un fichier contenant l'image et un booleen specifiant si l'image est visible
 * @param open True si l'image est visible
 * @param filename Nom du fichier contenant l'image a afficher
 * @param find True si l'image est trouvee
 * @param idImage Identifiant de l'image
 */
struct Image
{
	bool find;
	bool open;
	string filename;
	unsigned int idImage;
};
/**
 * @class <Game_Memory>
 * @brief Un Game_Memory est un mini-jeu de memoire
 * @param attempts Nombre de tentatives
 * @param tropheeMemory True si victoire
 * @param memoryBoard tableau de jeu 
 */
class Game_Memory 
{
public:
	
	/**
	 * @brief Constructeur par default
	 */
	Game_Memory();
	
	/**
	 * @brief Accesseur du nombre de tentatives
	 * @return Nombre de tentatives
	 */
	int getAttempts()const;
	
	/**
	 * @brief Accesseur du booleen victoire
	 * @return Booleen victoire
	 */
	bool getTropheeMemory()const;

	/**
	 * @brief Mutateur du booleen victoire
	 * @param t Nouveau booleen
	 */
	void setTropheeMemory(const bool & t);

	/**
	 * @brief Accesseur du booleen trouver de l'image à la position x,y dans le tableau
	 * @param x Coordonnee x
	 * @param y Coordonnee y
	 * @return Booleen trouver
	 */
	bool getOpen(const unsigned int& x, const unsigned int& y)const;

	/**
	 * @brief Mutateur du booleen trouver de l'image à la position x,y dans le tableau
	 * @param b Nouveau booleen
	 * @param x Coordonnee x
	 * @param y Coordonnee y
	 */
	void setOpen(const bool & b, const unsigned int & x,const unsigned int & y);

	/**
	 * @brief Accesseur du nom de fichier de l'image à la position x,y dans le tableau
	 * @param x Coordonnee x
	 * @param y Coordonnee y
	 * @return Nom du fichier
	 */
	string getFilename(const unsigned int& x, const unsigned int& y);

	/**
	 * @brief Mutateur de l'image en poistion x,y du tableau
	 * @param x Coordonnee x
	 * @param y Coordonnee y
	 * @param image Nouvelle image 
	 */
	void setCaseMemory (const unsigned int& x, const unsigned int& y, const Image& image);
	
	/**
	 * @brief Chargement du tableau 
	 * @param filenameGlobal Fichier de sauvegarde des images
	 */
	void initMemory(const string& filenameGlobal);
	
	/**
	 * @brief Affichage du tableau
	 */
	void printBoardMemory();
	
	/**
	 * @brief Test de correspondance des 2 images retournees
	 */
	void winTest();
	
	/**
	 * @brief Retourne la case demandee par le joueur
	 */
	void choicePlayer();
	
	/**
	 * @brief Boucle de jeu
	 */
	void play();
	
	/**
	 * @brief Test de la victoire totale
	 * @return True si victoire
	 */
	bool win();
	
	
	
private:
	
	int attempts;
	Image memoryBoard [4][4];
	bool tropheeMemory;
	
};

#endif /* MEMORY_H */
