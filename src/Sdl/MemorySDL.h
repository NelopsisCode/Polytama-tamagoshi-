#ifndef Memory_SDL_H
#define Memory_SDL_H

#include "../Core/Memory.h"
#include "GameSDL.h"

#include <SDL.h>
#include <SDL_image.h>

#include <SDL_mixer.h> //son
#include <SDL_ttf.h> //police
/**
 * @interface <MemorySDL>
 * @brief MemorySDL est l'adapation graphique de la classe Game_Memory
 */
/**
 * @brief Boucle de jeu sous SDL
 * @param memo Jeu de memory
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 */
void playMemorySDL(Game_Memory & memo,SDL_Window *&window, SDL_Renderer *&renderer);

/**
 * @brief Choix de l'image a retourner sous SDL
 * @param memo Jeu de memory
 * @param window Fenetre de jeu
 * @param renderer Moteur de rendu
 */
void choiceSDL(Game_Memory &memo, SDL_Window *&window, SDL_Renderer *&renderer);

/**
 * @brief Affichage du tableau sous SDL
 * @param memo Jeu de memory
 * @param window Fenetre de jeu
 * @param renderer moteur de rendu
 */
void printSDLMemory(Game_Memory & memo,SDL_Window *&window, SDL_Renderer *&renderer);


#endif