#ifndef TICTACTOE_SDL_H
#define TICTACTOE_SDL_H

#include "../Core/Tictactoe.h"
#include "GameSDL.h"
#include <random>
#include <time.h>
#include <stdlib.h> 

#include <SDL.h>
#include <SDL_image.h>

#include <SDL_mixer.h> //son
#include <SDL_ttf.h> //police

/**
 * @interface <TictactoeSDL>
 * @brief TictactoeSDL est l'adapation graphique de la classe Game_TicTacToe
 */
/**
 * @brief Boucle de jeu sous SDL
 * @param tictactoe Jeu de morpion
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 */
void playSDL(Game_TicTacToe & tictactoe,SDL_Window *&window, SDL_Renderer *&renderer);

/**
 * @brief Affichage du morpion sous SDL
 * @param tictactoe Jeu de morpion
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 */
void printSDLBoardTictactoe(const Game_TicTacToe & tictactoe,SDL_Window *&window, SDL_Renderer *&renderer);

/**
 * @brief Calcul de la difficulte du jeu
 * @return True si le jeu est facile
 */
bool stupidAI();

#endif