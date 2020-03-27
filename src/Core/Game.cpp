#include "Game.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

Game::Game(){
    Polytama polytama;
}

Polytama& Game::getPolytama () {return polytama; }