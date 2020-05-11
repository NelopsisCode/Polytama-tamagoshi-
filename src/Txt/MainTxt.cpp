#include <ncurses.h>
#include <cstdlib>
#include <string.h>
#include "GameTxt.h"
#include "../Core/Polytama.h"
#include "../Core/Mini_Game.h"
#include "TictactoeTxt.h"

int main(void) {
    Polytama polytama;
    
	initscr();
    attroff(A_UNDERLINE | A_BOLD);
    printw("\n\n");
    char choice =' ';
    long int initTime;
    printw("Bienvenue dans la version demo de Polytama\n");
    printw("Dans cette version les données ne sont pas sauvegardées.\n");
    printw("Pour jouer au vrai jeu lancez la version SDL !\n");
	printw("1 : Commencer une nouvelle partie ?\n");
    printw("2 : Charger l'ancienne partie ?\n");
	printw("3 : Quitter ?\n");
    refresh();
	
	printw("\n");

    choice = getch();
	switch (choice) {
		case '1' : { 
            clear();
            refresh();
			GameTxtInit(polytama);
            clear();
            refresh();
            GameTxtLoop(polytama);
            clear();
            refresh();
		}break;
		case '2' : { 
			clear();
            refresh();
            polytama.loadSave("../data/save.txt",initTime);
            polytama.pastTime(initTime);
            GameTxtLoop(polytama);
            clear();
            refresh();
		}break;
		case '3' :{
			
		}break;

		default : {
			printw("Veuillez choisir une proposition ci-dessous\n");
			refresh();
		}break;
	}
    
    endwin();
    
    return 0;
}