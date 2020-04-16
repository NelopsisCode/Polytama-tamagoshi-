#ifndef TICTACTOE_SDL_H
#define TICTACTOE_SDL_H

#include "../Core/Tictactoe.h"
#include "GameSDL.h"
#include <random>
#include <time.h>
#include <stdlib.h> 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_mixer.h> //son
#include <SDL2/SDL_ttf.h> //police

const unsigned int WIDTH = 10;
const unsigned int LENGTH = 10;

void playSDL(Game_TicTacToe & tictactoe,SDL_Window *&window, SDL_Renderer *&renderer);


void printSDLBoardTictactoe(Game_TicTacToe tictactoe,SDL_Window *&window, SDL_Renderer *&renderer);

bool stupidAI();

#endif