#include "GameSDL.h"


void GameSdlInit(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture)
{
	

//Initialisation SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Erreur: Initialisation SDL");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

	window = SDL_CreateWindow("Polytama", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);

//Création fenêtre
	if(window == NULL)
	{
		SDL_Log("ERREUR : Creation de la fenetre");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

	renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_SOFTWARE);

//Création rendu
	if(renderer == NULL)
	{
		SDL_Log("ERREUR : Creation du renderer");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

//Création texture
	
	CreateImage("data/image/Background.png",window,renderer,0,0);

	SDL_RenderPresent(renderer);
//+40 dim y
	CreateImage("data/image/Tamacorps.png",window,renderer, 0, 40);
//-25 dim y
	CreateImage("data/image/Tamatete1.png",window,renderer, 0, -25);
	

	SDL_RenderPresent(renderer);

}


//Crée une texture, et la place sur la fenetre par rapport au centre.
void CreateImage(const string & filename, SDL_Window*&  window, SDL_Renderer*& renderer, const int & posx,const int & posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;

	image = IMG_Load(filename.c_str());

	if(image == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		SDL_Log("ERREUR : Creation de l'image");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(texture == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("ERREUR : Creation de la texture");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}


	SDL_Rect dim;

	if ( SDL_QueryTexture(texture,NULL,NULL,&dim.w,&dim.h) != 0)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("ERREUR : Creation de la texture");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

	dim.x = (800 - dim.w)/2 + posx;
	dim.y = (600 - dim.h)/2 + posy;

	if(SDL_RenderCopy(renderer, texture, NULL, &dim) != 0)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("ERREUR : Chargement de l'image");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}
	//J'ai un doute sur ce SDL_Destroytexture
	SDL_DestroyTexture(texture);
}


void GameSdlDestruct(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture)
{
	if(texture != NULL)
	{
		SDL_DestroyTexture(texture);
		cout << "texture détruite" << endl;
	}
	if(renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
		cout << "rendu détruit" << endl;
	}
	
	if(window != NULL)
	{
		SDL_DestroyWindow(window);
		cout << "fenetre détruite" << endl;
	}



	window       = NULL;
	renderer     = NULL;
	texture = NULL;

	SDL_Quit();
}

void GameSdlLoop(SDL_Window*&  window, SDL_Renderer*& renderer, SDL_Texture*& texture,Polytama & polytama)
{
	bool program_launched = true;

	while(program_launched)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_MOUSEBUTTONDOWN:
				cout << event.button.x << "/" << event.button.y <<endl;
				break;

				case SDL_QUIT:
				program_launched = false;
				break;

				default:
				break;

			}
		}
	}

}