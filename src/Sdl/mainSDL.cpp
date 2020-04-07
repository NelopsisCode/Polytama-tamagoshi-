#include "GameSDL.h"

using namespace std;

int main(int argc, char** argv)
{
	SDL_Window  * window = NULL;
	SDL_Renderer* renderer= NULL;
	SDL_Texture *texture = NULL;
	Polytama p;
	GameSdlInit(window, renderer,texture);
	GameSdlLoop(window,renderer,texture, p);
	GameSdlDestruct(window, renderer,texture);
	return 0;
}