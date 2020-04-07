#ifndef TICTACTOETXT_H
#define TICTACTOETXT_H
#include <string>
#include <iostream>
#include "../Core/Tictactoe.h"

using namespace std;




class TicTacToeTxt
{

public:

//Game
	TicTacToeTxt();

	char * getBoardTxt();

	void printBoardTictactoeTxt()const;

	void setCaseTxt(const unsigned int & x, const unsigned int & y, const char & player, bool & isset);

	bool tieTxt()const;

	bool winTxt(const char & player)const;

	bool gameOverTxt(const char & player)const;

//AI
	Move minimaxTxt(char AIboard[3][3])const;

	int maxSearchTxt(char AIboard[3][3])const;

	int minSearchTxt(char AIboard[3][3])const;

//Game loop
	void playTxt();
	
	bool tropheeTictactoeTxt;

private:
	
	char boardTictactoeTxt[TAILLE][TAILLE];

};
#endif /* TICTACTOETXT_H */