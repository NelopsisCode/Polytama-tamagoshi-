
#ifndef GAME_H
#define GAME_H

#include "Polytama.h"

class Game {

private :

	Polytama polytama;

public :

    Game();

    Polytama& getPolytama ();

};

#endif