#ifndef HANGED_SDL_H
#define HANGED_SDL_H

#include "../Core/Hanged.h"
#include "GameSDL.h"

#include <SDL.h>
#include <SDL_image.h>

#include <SDL_mixer.h> //son
#include <SDL_ttf.h> //police

/**
 * @interface <HangedSDL>
 * @brief HangedSDL est l'adapation graphique de la classe Game_Hanged
 */
/**
 * @brief Boucle de jeu sous SDL
 * @param hanged Jeu de pendu
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 */
void playHangedSDL(Game_Hanged & hanged,SDL_Window *&window, SDL_Renderer *&renderer);

/**
 * @brief Affichage du mot sous SDL
 * @param hanged Jeu de pendu
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 */
void printSDLWord(const Game_Hanged & hanged,SDL_Window *&window, SDL_Renderer *&renderer);

/**
 * @brief Choix de la lettre par le joueur sous SDL
 * @param hanged
 * @param window
 * @param renderer
 * @return 
 */
char getSDLletter(const Game_Hanged & hanged,SDL_Window *&window, SDL_Renderer *&renderer);


#endif