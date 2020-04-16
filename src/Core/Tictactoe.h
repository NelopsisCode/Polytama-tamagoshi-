#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include "Mini_Game.h"

using namespace std;

#define TAILLE 3
#define HUMAN 'X'
#define AI 'O'

/**
 * @struct <Move> 
 * @brief Un Move est un choix de case en abscisse et en ordonnee
 * @param x Coordonnee en abscisse
 * @param y Coordonnee en ordonnee
 */
struct Move 
{
	unsigned int x = 1;
	unsigned int y = 1;
		
};


/**
 * @class <Game_TicTacToe>
 * @brief Game_TicTacToe est un morpion qui se joue contre une intelligence artificielle
 * @param boardTictactoe Plateau de jeu (3x3 cases)
 * @param tropheeTictactoe Victoire ou Defaite du joueur principal
 */
class Game_TicTacToe
{

public:

//Game
	/**
	 * @brief Constructeur par defaut, initialisation des cases
	 */
	Game_TicTacToe();

	/**
	 * @brief Accesseur du plateau de jeu
	 * @return Adresse de la premiere case du tableau
	 */
const char * getBoard()const;

	/**
	 * @brief Accesseur de la victoire
	 * @return Victoire ou defaite du joueur principal
	 */
	bool getTropheeTictactoe()const;

	void setTropheeTictactoe(const bool & t);
	/**
	 * @brief Affichage du plateau de jeu
	 */
	void printBoardTictactoe()const;

	/**
	 * @brief Mutateur d'une case du plateau de jeu
	 * @param x Coordonnee en abscisse
	 * @param y Coordonnee en 
	 * @param player Pion a inscrire dans la case (o pour l'IA, x pour le joueur)
	 * @param isset Case libre ou non
	 */
	void setCase(const unsigned int & x, const unsigned int & y, const char & player,bool & isset);

	/**
	 * @brief Test du tableau (vide ou non)
	 * @return false si le tableau est vide
	 */
	bool tie()const;

	/**
	 * @brief Test de victoire
	 * @param player Pion (o pour l'IA, x pour le joueur)
	 * @return true si le joueur selectionne a gagne
	 */
	bool win(const char & player)const;

	/**
	 * @brief Test de fin de partie
	 * @param player Pion (o pour l'IA, x pour le joueur)
	 * @return true si quelqu'un a gagne ou si il a egalite
	 */
	bool gameOver(const char & player)const;

//AI
	/**
	 * @brief Recherche du meilleur choix de l'IA
	 * @param AIboard Plateau de jeu de l'IA
	 * @return Choix de case de l'IA
	 */
	Move minimax(char AIboard[3][3])const;

	/**
	 * @brief Recherche du meilleur choix en descendant
	 * @param AIboard Plateau de jeu de l'IA
	 * @return Meilleur choix pour l'IA
	 */
	int maxSearch(char AIboard[3][3])const;

	/**
	 * @brief Recherche d'un choix en montant
	 * @param AIboard Plateau de jeu de l'IA
	 * @return Meilleur choix de l'IA
	 */
	int minSearch(char AIboard[3][3])const;

//Game loop
	/**
	 * @brief Boucle de jeu
	 */
	void play();

	char boardTictactoe[TAILLE][TAILLE];


private:
	
	bool tropheeTictactoe;
	
		

};


#endif