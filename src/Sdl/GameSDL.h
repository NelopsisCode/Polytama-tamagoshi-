#ifndef GAME_SDL_H
#define GAME_SDL_H

#include <string>
#include <iostream>
#include "../Core/Polytama.h"
#include "TictactoeSDL.h"
#include "../Core/Mini_Game.h"
#include "HangedSDL.h"
#include "../Core/Memory.h"
#include "MemorySDL.h"
#include <SDL.h>
#include <SDL_image.h>

#include <SDL_mixer.h> //son
#include <SDL_ttf.h>   //police
using namespace std;

/**
 * @interface <GameSDL>
 * @brief GameSDL est l'adapation graphique des classes InventoryClothes, InventoryConsommable, Polytama ainsi que la mise en place des outils SDL
 */
/**
 * @brief Affichage de l'inventaire de vetements ainsi que les vetements portes par le polytama sous SDL
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @param clo Inventaire de vetements
 * @param polytama Polytama
 */
void printSdlInventoryClothes(SDL_Window *&window,
							  SDL_Renderer *&renderer,
							  const InventoryClothes &clo,
							  const Polytama &polytama);

/**
 * @brief Affichage de l'inventaire de consommables sous SDL
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @param conso inventaire de consommables
 */
void printSdlInventoryConsommable(SDL_Window *&window,
								  SDL_Renderer *&renderer,
								  const InventoryConsommable &conso);

/**
 * @brief Affichage du terrain, des boutons, des jauges et du tama sous SDL
 * @param polytama Polytama
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 */
void GameSdlPrintTama(const Polytama &polytama,
					  SDL_Window *&window,
					  SDL_Renderer *&renderer);

/**
 * @brief Creation du polytama sous SDL
 * @param polytama Polytama
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 */
void createTama(Polytama &polytama,
				SDL_Window *&window,
				SDL_Renderer *&renderer);

/**
 * @brief Initialisation de la SDL (avec mixer et ttf) 
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @param texture Texture sous SDL
 */
void GameSdlInit(SDL_Window *&window,
				 SDL_Renderer *&renderer,
				 SDL_Texture *&texture);

/**
 * @brief Affichage d'un texte a la postion posx,posy sous SDL
 * @param text Texte a ecrire
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @param color Couleur du texte
 * @param fontname Police du texte
 * @param fontsize Taille du texte
 * @param posx Coordonnee x
 * @param posy Coordonnee y
 * @param centered True si centre
 */
void CreateText(const string &text,
				SDL_Window *&window,
				SDL_Renderer *&renderer,
				const SDL_Color &color,
				const string &fontname,
				const int &fontsize,
				const int &posx,
				const int &posy,
				const bool &centered);

/**
 * @brief Affichage de l'image a la  postion posx,posy sous SDL
 * @param filename Nom du fichier image
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @param posx Coordonnee x
 * @param posy Coordonnee y
 * @param centered True si centree
 */
void CreateImage(const string &filename,
				 SDL_Window *&window,
				 SDL_Renderer *&renderer,
				 const int &posx,
				 const int &posy,
				 const bool &centered);

/**
 * @brief Destructeur des elements SDL et Liberateur de memoire
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @param texture Texture SDL
 */
void GameSdlDestruct(SDL_Window *&window,
					 SDL_Renderer *&renderer,
					 SDL_Texture *&texture);

/**
 * @brief Boucle de gestion des elements SDL et de jeu
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @param texture Texture SDL
 * @param polytama Polytama
 */
void GameSdlLoop(SDL_Window *&window,
				 SDL_Renderer *&renderer,
				 SDL_Texture *&texture,
				 Polytama &polytama);

/**
 * @brief Demarrage du jeu sous SDL
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @param polytama Polytama
 */ 
void GameStart(SDL_Window *&window,
			   SDL_Renderer *&renderer,
			   Polytama &polytama);

/**
 * @brief Saisie de texte sous SDL
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 * @return Texte
 */
string getTxt(SDL_Window *&window,
			  SDL_Renderer *&renderer);

//Fonction qui permet de ne pas donner au polytama un vêtement déjà gagné
/**
 * @brief Test de recompense 
 * @param reward Recompense
 * @param polytama Polytama
 * @param clos Inventaire de vetement
 * @return True si le vetement gagne est deja possede
 */
bool alreadyGot(const unsigned int &reward,
				const Polytama &polytama,
				const InventoryClothes &clos);
/**
 * @brief Animation de la resurrection du polytama
 * @param name Nom du polytama
 * @param window Fenetre d'affichage
 * @param renderer Moteur de rendu
 */
void SdlReviveAnimation(const string & name,SDL_Window *&window,
			  SDL_Renderer *&renderer);
/**
 * @brief Diminution des jauges du polytama au cours du temps
 * @param interval
 * @param param
 * @return 
 */
Uint32 dropBar(Uint32 interval, void *param);
#endif