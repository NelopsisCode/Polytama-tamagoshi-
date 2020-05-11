#include "GameSDL.h"

using namespace std;
/**
 * @mainpage
 * @brief Bienvenue sur la documentation du projet Polytama ! <br> 
 * Nous nous appelons Mathias Flagey, Thomas Piscione et Catherine Vanden Hende.
 * <br>
 * Nous sommes trois etudiants de deuxieme annee a Polytech et nous avons cree 
 * un jeu s'inspirant du celebre tamagotchi.<br>
 * Notre polytama est un petit etre dont il faut s'occuper tous les jours. 
 * Vous pouvez le nourrir, le laver et jouer avec lui afin de gagner des vetements
 *  ou de la nourriture.<br>
 * Pour plus de details sur le code, consultez le README dans Related Pages et 
 * les differentes classes que nous avons documentees.
 * 
 */
int main(int argc, char** argv)
{
	SDL_Window  * window = NULL;
	SDL_Renderer* renderer= NULL;
	SDL_Texture *texture = NULL;
	Polytama p;
	srand((unsigned int)time(NULL));
	GameSdlInit(window, renderer,texture);
	GameStart(window,renderer,p);
	GameSdlLoop(window,renderer,texture, p);
	GameSdlDestruct(window, renderer,texture);
	return 0;
}