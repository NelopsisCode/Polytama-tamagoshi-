#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include "Mini_Game.h"

using namespace std;

const int TAILLE = 3;
const char HUMAN = 'X';
const char AI = 'O';


struct Move 
{
	unsigned int x = 1;
	unsigned int y = 1;
		
};



class Game_TicTacToe
{

public:

//Game
	Game_TicTacToe();

	char * getBoard();

	void printBoardTictactoe()const;

	void setCase(const unsigned int & x, const unsigned int & y, const char & player,bool & isset);

	bool tie()const;

	bool win(const char & player)const;

	bool gameOver(const char & player)const;

//AI
	Move minimax(char AIboard[3][3])const;

	int maxSearch(char AIboard[3][3])const;

	int minSearch(char AIboard[3][3])const;

//Game loop
	void play();

	bool tropheeTictactoe;

private:
	
	char boardTictactoe[TAILLE][TAILLE];
	

};


#endif