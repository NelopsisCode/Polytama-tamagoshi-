#ifndef HANGED_H
#define HANGED_H

#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h> 
#include <fstream>
#include "Mini_Game.h"

#define MAX_ATTEMPTS 11

using namespace std;
/**
 * @struct Letter 
 * @brief Une Letter est une lettre d'un mot
 * @param letter Une lettre d'un mot
 * @param find True si la lettre a ete trouvée
 */
struct Letter
{
    char letter;
    bool find;
};

/**
 * @class Game_Hanged
 * @brief Un Game_Hanged est un mini-jeu de pendu
 * @param attemps Nombre de tentatives
 * @param wordLength Taille du mot
 * @param word Tableau de lettres formant un mot
 * @param tropheeHanged victoire ou defaite
 */
class Game_Hanged
{
public:

	/**
	 * @brief Constructeur par default
	 */
    Game_Hanged();
	
	/**
	 * @brief Destructeur par default
	 */
    ~Game_Hanged();

	/**
	 * @brief Accesseur de la victoire ou defaite
	 * @return Victoire ou defaite
	 */
    bool getTropheeHanged();
	
	/**
	 * @brief Mutateur de la victoire ou defaite
	 * @param t Nouveau booleen
	 */
    void setTropheeHanged(const bool & t);

	/**
	 * @brief Accesseur du nombre de tentatives
	 * @return Nombre de tentatives
	 */
    unsigned int getAttempts()const;
	
	/**
	 * @brief Mutateur du nombre de tentatives
	 * @param a Nouveau nombre de tentatives
	 */
    void setAttempts(const unsigned int & a);

	/**
	 * @brief Accesseur de la longueur du mot
	 * @return Longueur du mot
	 */
    unsigned int getWordLength()const;
    //void setWordLength(const unsigned int & wl);

	/**
	 * @brief Accesseur d'une lettre dans le mot a la position i
	 * @param i Position de la lettre
	 * @return Lettre cherchee
	 */
    char getWordLetter(const unsigned int & i)const;

	/**
	 * @brief Accesseur du booleen trouver de la lettre a la position i
	 * @param i Position de la lettre
	 * @return Booleen trouver de la lettre
	 */
    bool getWordFind(const unsigned int & i)const;

	/**
	 * @brief Mutateur du booleen trouver de la lettre a la position i
	 * @param i Position de la lettre
	 * @param b Nouveau booleen trouver
	 */
    void setWordFind(const unsigned int & i,const bool & b);

	/**
	 * @brief Chargement du mot dans le tableau
	 * @param filename Fichier de sauvegarde du mot
	 */
    void loadWord(const string & filename);

	/**
	 * @brief Recuperation de la lettre choisie par le joueur
	 * @return Lettre choisie par le joueur
	 */
    char getLetter()const;

	/**
	 * @brief Calcul de la victoire
	 * @return Victoire ou defaite
	 */
    bool win()const;

	/**
	 * @brief Affichage du mot
	 */
    void printWord()const;

	/**
	 * @brief Test de la presence de la lettre choisie par le joueur dans le mot
	 * @param letter Lettre choisie par le joueur
	 * @return True si la lettre est presente
	 */
    bool isInWord(const char & letter);

	/**
	 * @brief Boucle de jeu
	 */
    void play();
    
private:

    unsigned int attempts, wordLength;

    vector<Letter> word;

    bool tropheeHanged;

};
#endif