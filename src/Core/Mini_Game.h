#ifndef MINIGAME_H
#define MINIGAME_H

#include "Tictactoe.h"
#include "Hanged.h"
#include "Memory.h"
#include <random>
#include <time.h>
#include <stdlib.h> 


/**
 * @class <Mini_Game>
 * @brief Un Mini_Game est un mini-jeu dans Polytama. En gagnant un mini-jeu, le joueur gagne un objet
 * @param reward Identifiant de la recompense (objet)
 * @param trophee true Si le joueur a gagne, false Sinon
 */
class Mini_Game
{

public:
	/**
	 * @brief Constructeur par defaut
	 */
	Mini_Game();
	
	/**
	 * @brief Accesseur de l'identifiant de la recompense
	 * @return Identifiant de la recompense (objet)
	 */
	unsigned int getReward()const;
	
	/**
	 * @brief Accesseur de la victoire du joeur
	 * @return Victoire ou non du joueur
	 */
	bool getTrophee()const;
	
	/**
	 * @brief Boucle de mini-jeu (choix du mini-jeu, recompense)
	 */
	void selectAndPlayMiniGame();
	
	/**
	 * @brief Generateur de recompense
	 */
	void generateReward();

private:
	unsigned int reward;
	bool trophee;
};


#endif