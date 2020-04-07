#ifndef GAME_SDL_H
#define GAME_SDL_H

#include <string>
#include <iostream>
#include "../Core/Polytama.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_mixer.h> //son
#include <SDL2/SDL_ttf.h> //police
using namespace std;


void printSdlInventoryClothes(SDL_Window*&  window,SDL_Renderer*& renderer,const InventoryClothes & sweatshirt);
void printSdlInventoryConsommable(SDL_Window*&  window,SDL_Renderer*& renderer,const InventoryConsommable & conso);
//void GameSdlPrintTama(const Polytama & polytama);

//Initialise le terrain de jeu avec le polytama.
void GameSdlInit(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture);
//Initialise le terrain de jeu avec le polytama.
void CreateImage(const string & filename, SDL_Window*&  window, SDL_Renderer*& renderer, const int & posx,const int & posy);
//Détruit les éléments de SDL et libère la mémoire.
void GameSdlDestruct(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture);
void GameSdlLoop(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture,Polytama & polytama);

#endif