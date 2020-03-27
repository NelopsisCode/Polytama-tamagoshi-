#include <ncurses.h>
#include <Game.h>
#include <cstdlib>
#include <string.h>

int main(void) {
    Polytama polytama;
    
    initscr();
    Game game;
    GameTxtInit(game)
    while(1) {

        refresh();
        if(getch() != 410)
            break;
    }
    
    endwin();
    
    return 0;
}