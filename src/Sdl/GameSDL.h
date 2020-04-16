#ifndef GAME_SDL_H
#define GAME_SDL_H

#include <string>
#include <iostream>
#include "../Core/Polytama.h"
#include "../Core/Tictactoe.h"
#include "TictactoeSDL.h"
#include "../Core/Mini_Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_mixer.h> //son
#include <SDL2/SDL_ttf.h> //police
using namespace std;


void printSdlInventoryClothes(SDL_Window *&window, SDL_Renderer *&renderer, const InventoryClothes &clo);
void printSdlInventoryConsommable(SDL_Window*&  window,SDL_Renderer*& renderer,const InventoryConsommable & conso);
void GameSdlPrintTama(const Polytama & polytama, SDL_Window*&  window,SDL_Renderer*& renderer );
void createTama(Polytama & polytama, SDL_Window*&  window, 
	SDL_Renderer*& renderer );
//Initialise le terrain de jeu avec le polytama.
void GameSdlInit(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture);

void CreateText(const string & text,
	SDL_Window*&  window, 
	SDL_Renderer*& renderer,
	const SDL_Color & color,
	const string & fontname,
	const int & fontsize, 
	const int & posx,
	const int & posy, 
	const bool & centered);

void CreateImage(const string & filename, 
	SDL_Window*&  window, 
	SDL_Renderer*& renderer, 
	const int & posx,
	const int & posy, 
	const bool & centered);
//Détruit les éléments de SDL et libère la mémoire.
void GameSdlDestruct(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture);

void GameSdlLoop(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture,Polytama & polytama);

void GameStart(SDL_Window*&  window, SDL_Renderer*& renderer,Polytama & polytama);

string getTxt(SDL_Window*&  window, SDL_Renderer*& renderer);

#endif