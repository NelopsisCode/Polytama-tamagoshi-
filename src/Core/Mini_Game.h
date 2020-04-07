#ifndef MINIGAME_H
#define MINIGAME_H

#include "Tictactoe.h"
#include <random>
#include <time.h>
#include <stdlib.h> 



class Mini_Game
{

public:
	Mini_Game();
	unsigned int getReward()const;
	bool getTrophee()const;
	void selectAndPlayMiniGame();
	void generateReward();

private:
	unsigned int reward;
	bool trophee;
};


#endif