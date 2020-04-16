#include "GameSDL.h"

void GameSdlInit(SDL_Window *&window, SDL_Renderer *&renderer, SDL_Texture *&texture)
{

	//Initialisation SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Erreur: Initialisation SDL");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

	window = SDL_CreateWindow("Polytama", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_BORDERLESS);

	//Création fenêtre
	if (window == NULL)
	{
		SDL_Log("ERREUR : Creation de la fenetre");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	//Création rendu
	if (renderer == NULL)
	{
		SDL_Log("ERREUR : Creation du renderer");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}
	//initialisation du texte
	if (TTF_Init() == -1)
	{
		SDL_Log("Erreur: Initialisation TTF");
		cout << TTF_GetError() << endl;
		exit(EXIT_FAILURE);
	}
	//musique
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
	{
		SDL_Log("Erreur: Initialisation Mixer");
		cout << Mix_GetError() << endl;
	}
}

void GameStart(SDL_Window *&window, SDL_Renderer *&renderer, Polytama &polytama)
{

	CreateImage("data/image/Background.png", window, renderer, 0, 0, true);
	SDL_Color white = {0, 0, 0};
	CreateImage("data/image/Title.png", window, renderer, 0, 0, true);
	CreateText("Continuer la partie", window, renderer, white, "font.ttf", 50, 230, 200, false);
	CreateText("Nouvelle partie", window, renderer, white, "font.ttf", 50, 270, 300, false);
	SDL_RenderPresent(renderer);

	bool startScreen = true;
	while (startScreen)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				cout << event.button.x << "/" << event.button.y << endl;
				//Continuer
				if (event.button.x > 250 and event.button.x < 555 and event.button.y > 213 and event.button.y < 255)
				{
					long int initTime;
					polytama.loadSave("save.txt", initTime);
					polytama.pastTime(initTime);
					startScreen = false;
				}
				//Nouvelle partie
				else if (event.button.x > 250 and event.button.x < 555 and event.button.y > 314 and event.button.y < 352)
				{
					CreateImage("data/image/Background.png", window, renderer, 0, 0, true);
					CreateText("Etes vous sur?", window, renderer, white, "font.ttf", 70, 0, -200, true);
					CreateText("Oui", window, renderer, white, "font.ttf", 70, 250, 200, false);
					CreateText("Non", window, renderer, white, "font.ttf", 70, 250, 300, false);
					SDL_RenderPresent(renderer);
					bool verif = true;
					while (verif)
					{


						while (SDL_PollEvent(&event))
						{
							switch (event.type)
							{
							case SDL_MOUSEBUTTONDOWN:
								cout << event.button.x << "/" << event.button.y << endl;
								//oui
								if (event.button.x > 235 and event.button.x < 319 and event.button.y > 212 and event.button.y < 251)
								{
									verif = false;
									createTama(polytama, window, renderer);
								}
								//non
								else if (event.button.x > 247 and event.button.x < 323 and event.button.y > 311 and event.button.y < 353)
								{
									verif = false;
									GameStart(window, renderer, polytama);
								}

								break;
							}
						}
					}
					startScreen = false;
				}
				break;

			case SDL_QUIT:
				startScreen = false;
				break;

			default:
				break;
			}
		}
	}
}

string getTxt(SDL_Window *&window, SDL_Renderer *&renderer)
{
	string res = "";
	SDL_Surface *text = NULL;
	SDL_Texture *texture = NULL;

	SDL_Color black = {0, 0, 0};
	TTF_Font *font = NULL;
	font = TTF_OpenFont("font.ttf", 50);
	bool write = true;
	SDL_Event event;
	while (write)
	{
		string temp = res;
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_TEXTINPUT:
		{
			if (res.length() <= 16)
			{
				res += event.text.text;
			}
		}
		case SDL_KEYDOWN:
		{
			if ((event.key.keysym.sym == SDLK_BACKSPACE) && (res.length() != 0))
			{
				//Remove a character from the end
				res.erase(res.length() - 1);
			}
			if (event.key.keysym.sym == SDLK_RETURN)
			{
				write = false;
			}
		}
		}

		CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
		CreateText("Premierement, vous devez lui choisir un nom !", window, renderer, black, "font.ttf", 30, 0, -220, true);
		CreateText("(Utilisez le clavier pour saisir le nom de votre tama)",window,renderer, black, "font.ttf",15,0,270,true);
		CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
		CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
		if (res != temp)
		{
			text = TTF_RenderUTF8_Blended(font, res.c_str(), black);
		}
		if (text != NULL)
		{
			SDL_Rect dim;
			texture = SDL_CreateTextureFromSurface(renderer, text);
			SDL_QueryTexture(texture, NULL, NULL, &dim.w, &dim.h);

			dim.x = (800 - dim.w) / 2;
			dim.y = (600 - dim.h) / 2 - 180;

			SDL_RenderCopy(renderer, texture, NULL, &dim);
		}
		SDL_RenderPresent(renderer);
	}
	TTF_CloseFont(font);
	SDL_FreeSurface(text);
	return res;
}

void createTama(Polytama &polytama, SDL_Window *&window,
				SDL_Renderer *&renderer)
{
	Mix_Music *music = NULL;
	music = Mix_LoadMUS("data/sound/Opening.mp3");
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	if (music == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("Erreur: Chargement de la musique");
	}
	Mix_PlayMusic(music, -1);

	CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
	SDL_Color white = {0, 0, 0};
	CreateText("Bonjour et bienvenue dans Polytama!", window, renderer, white, "font.ttf",  30, 0, -220, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
	CreateText("Ici vous allez vous occuper d'une petite creature appellée Polytama !", window, renderer, white, "font.ttf",  25, 0, -220, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
	CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(1000);
	bool verif = true;
	string name;
	do
	{
		CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
		CreateText("Premierement, vous devez lui choisir un nom !", window, renderer, white, "font.ttf", 30, 0, -220, true);
		CreateText("(Utilisez le clavier pour saisir le nom de votre tama)",window,renderer, white, "font.ttf",15,0,270,true);
		CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
		CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
		SDL_RenderPresent(renderer);
		//Choix du nom

		name = getTxt(window, renderer);
		CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
		CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
		CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
		CreateText("Voulez vous que votre Polytama porte le nom", window, renderer, white, "font.ttf", 30, 0, -220, true);
		CreateText(name + " ?", window, renderer, white, "font.ttf", 50, 0, -180, true);
		CreateText("Oui", window, renderer, white, "font.ttf", 60, -80, -130, true);
		CreateText("Non", window, renderer, white, "font.ttf", 60, 80, -130, true);
		
		SDL_RenderPresent(renderer);
		//bouton de verif
		bool choice = true;
		while (choice)
		{
			SDL_Event event;

			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_MOUSEBUTTONDOWN:
					cout << event.button.x << "/" << event.button.y << endl;
					//oui
					if (event.button.x > 272 and event.button.x < 365 and event.button.y > 146 and event.button.y < 192)
					{
						verif = false;
						choice = false;
					}
					//non
					else if (event.button.x > 429 and event.button.x < 531 and event.button.y > 146 and event.button.y < 192)
					{
						choice = false;
					}

					break;
				}
			}
		}

	} while (verif);

	polytama.setName(name);
	polytama.setHunger(50);
	polytama.setHygiene(50);
	polytama.setJoy(50);
	polytama.setThirst(50);
	
	InventoryConsommable conso;
	conso.loadIndexConsommable("data/initIndexConsommable.txt");
	conso.saveIndexConsommable("data/indexConsommable.txt");
	InventoryClothes clo;
	clo.loadIndexClothes("data/initIndexClothes.txt");
	clo.saveIndexClothes("data/indexClothes.txt");
	
	CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
	CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
	CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
	CreateText("Amusez vous bien avec " + name + "!", window, renderer, white, "font.ttf",  40, 0, -220, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(800);
	CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
	CreateImage("data/image/tama/Tamachestdab106.png", window, renderer, 0, 40, true);
	CreateImage("data/image/tama/Tamaheaddab.png", window, renderer, 0, -50, true);
	CreateText("Amusez vous bien avec " + name + "!", window, renderer, white, "font.ttf",  40, 0, -220, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(800);
	CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
	CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
	CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
	CreateText("Amusez vous bien avec " + name + "!", window, renderer, white, "font.ttf",  40, 0, -220, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);
	Mix_FreeMusic(music);

}

//Crée une texture, et la place sur la fenetre par rapport au centre si centered est true, par rapport au 0 0 si centered est false.
void CreateImage(const string &filename,
				 SDL_Window *&window,
				 SDL_Renderer *&renderer,
				 const int &posx,
				 const int &posy,
				 const bool &centered)
{
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;

	image = IMG_Load(filename.c_str());

	if (image == NULL)
	{
		cout << "Missing texture" << endl;
		image = IMG_Load("data/image/missing.png");
		/*
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		SDL_Log("ERREUR : Creation de l'image");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
		*/
	}

	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if (texture == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("ERREUR : Creation de la texture");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

	SDL_Rect dim;

	if (SDL_QueryTexture(texture, NULL, NULL, &dim.w, &dim.h) != 0)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("ERREUR : Creation de la texture");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}

	if (centered)
	{
		dim.x = (800 - dim.w) / 2 + posx;
		dim.y = (600 - dim.h) / 2 + posy;
	}
	else
	{
		dim.x = posx;
		dim.y = posy;
	}

	if (SDL_RenderCopy(renderer, texture, NULL, &dim) != 0)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("ERREUR : Chargement de l'image");
		cout << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}
	SDL_DestroyTexture(texture);
}

void CreateText(const string &textToWrite,
				SDL_Window *&window,
				SDL_Renderer *&renderer,
				const SDL_Color &color,
				const string &fontname,
				const int &fontsize,
				const int &posx,
				const int &posy,
				const bool &centered)
{
	TTF_Font *font = NULL;
	SDL_Surface *text = NULL;
	SDL_Texture *texture = NULL;
	font = TTF_OpenFont(fontname.c_str(), fontsize);
	if (font == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("Erreur: Création de la police");
		cout << SDL_GetError() << endl;
	}

	text = TTF_RenderUTF8_Blended(font, textToWrite.c_str(), color);

	if (text == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("Erreur: Création du texte");
		cout << SDL_GetError() << endl;
	}

	SDL_Rect dim;

	texture = SDL_CreateTextureFromSurface(renderer, text);
	SDL_FreeSurface(text);
	SDL_QueryTexture(texture, NULL, NULL, &dim.w, &dim.h);

	if (centered)
	{
		dim.x = (800 - dim.w) / 2 + posx;
		dim.y = (600 - dim.h) / 2 + posy;
	}
	else
	{
		dim.x = posx;
		dim.y = posy;
	}

	SDL_RenderCopy(renderer, texture, NULL, &dim);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}

void GameSdlDestruct(SDL_Window *&window, SDL_Renderer *&renderer, SDL_Texture *&texture)
{
	TTF_Quit();
	Mix_CloseAudio();
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		cout << "texture détruite" << endl;
	}
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
		cout << "rendu détruit" << endl;
	}

	if (window != NULL)
	{
		SDL_DestroyWindow(window);
		cout << "fenetre détruite" << endl;
	}
	SDL_RenderClear(renderer);

	window = NULL;
	renderer = NULL;
	texture = NULL;

	SDL_Quit();
}

void GameSdlLoop(SDL_Window *&window, SDL_Renderer *&renderer, SDL_Texture *&texture, Polytama &polytama)
{
	int volume = MIX_MAX_VOLUME / 2;
	Mix_Music *music = NULL;
	music = Mix_LoadMUS("data/sound/Polytama.mp3");
	Mix_VolumeMusic(volume);
	if (music == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("Erreur: Chargement de la musique");
	}

	Mix_PlayMusic(music, -1);
	GameSdlPrintTama(polytama, window, renderer);
	bool program_launched = true;
	InventoryConsommable conso;
	conso.loadIndexConsommable("data/indexConsommable.txt");
	InventoryClothes clo;
	clo.loadIndexClothes("data/indexClothes.txt");
	bool menuS = false;

	while (program_launched)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				cout << event.button.x << "/" << event.button.y << endl;
				//dab
				if (event.button.x > 395 and event.button.x < 415 and event.button.y > 352 and event.button.y < 366)
				{
					//Chest
					string chest, head;
					if (polytama.getClothes(1) == nullptr)
					{
						chest = "data/image/tama/Tamachestdab.png";
					}
					else
					{
						string id = to_string(polytama.getClothes(1)->getIdItem());
						chest = "data/image/tama/Tamachestdab" + id + ".png";
					}
					CreateImage("data/image/Background.png", window, renderer, 0, 0, true);
					CreateImage(chest, window, renderer, 0, 40, true);
					CreateImage("data/image/tama/Tamaheaddab.png", window, renderer, 0, -50, true);
					//Head (hat)
					if (polytama.getClothes(0) != nullptr)
					{
						string id = to_string(polytama.getClothes(0)->getIdItem());
						head = "data/image/tama/Tamahead" + id + ".png";
						CreateImage(head, window, renderer, 0, -50, true);
					}
					SDL_RenderPresent(renderer);
					polytama.dab();
					SDL_Delay(800);
					GameSdlPrintTama(polytama, window, renderer);
				}
				//bain
				if (event.button.x > 200 and event.button.x < 250 and event.button.y > 500 and event.button.y < 550)
				{
					polytama.takeABath();
					CreateImage("data/image/Takeabath.png", window, renderer, 0, 0, true);
					SDL_RenderPresent(renderer);
					SDL_Delay(4000);
					SDL_Color blue = {0,0,255};
					CreateText(polytama.getName() + " est tout propre!",window,renderer,blue, "font.ttf",60,0,250,true);
					SDL_RenderPresent(renderer);
					SDL_Delay(2000);	
					GameSdlPrintTama(polytama, window, renderer);
				}

				//jeu
				if (event.button.x > 270 and event.button.x < 320 and event.button.y > 500 and event.button.y < 550)
				{
					Mini_Game game;
					Game_TicTacToe tictactoe;
					playSDL(tictactoe,window,renderer);
					GameSdlPrintTama(polytama, window, renderer);
					
					if (tictactoe.getTropheeTictactoe() == true)
					{
						polytama.addJoy(30);
						SDL_Color black = {0,0,0};
						game.generateReward();
						if(game.getReward() < 100)
						{
							Consommable consom=conso.searchIdInInventoryConsommable(game.getReward());
							conso.addInInventoryConsommable(consom);
							CreateText("Vous avez gagné",window,renderer,black,"font.ttf",90,0,-20,true);
							CreateImage("data/image/items/"+to_string(consom.getIdItem())+".png",window,renderer,0,150,true);
							SDL_RenderPresent(renderer);
							SDL_Delay(1500);

							conso.saveIndexConsommable("data/indexConsommable.txt");
						}
						else
						{
							Clothes clot = clo.searchIdInInventoryClothes(game.getReward());
							clo.addInInventoryClothes(clot);
							CreateText("Vous avez gagné",window,renderer,black,"font.ttf",90,0,-20,true);
							CreateImage("data/image/items/"+to_string(clot.getIdItem())+".png",window,renderer,0,100,true);
							SDL_RenderPresent(renderer);
							SDL_Delay(1500);

							clo.saveIndexClothes("data/indexClothes.txt");
						}
					}
					else
					{
						polytama.addJoy(-30);
					}
					
					GameSdlPrintTama(polytama, window, renderer);
			}

				//Bouton inventaire consommable pour consommer un item
				if (event.button.x > 500 and event.button.x < 550 and event.button.y > 500 and event.button.y < 550)
				{
					printSdlInventoryConsommable(window, renderer, conso);
					string word = "yarien";
					bool inInventory = true;
					while (inInventory)
					{
						SDL_Event event;

						SDL_WaitEvent(&event);

						switch (event.type)
						{
						case SDL_MOUSEBUTTONDOWN:
							if (event.button.x > 50 and event.button.x < 150 and event.button.y > 50 and event.button.y < 150)
							{
								inInventory = false;
							}
							else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 30 and event.button.y < 190)
							{
								if (conso.getConsommableBoard()[0].getNumberItem() != 0)
								{
									word = conso.getConsommableBoard()[0].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 30 and event.button.y < 190)
							{
								if (conso.getConsommableBoard()[1].getNumberItem() != 0)
								{
									word = conso.getConsommableBoard()[1].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 30 and event.button.y < 190)
							{
								if (conso.getConsommableBoard()[2].getNumberItem() != 0)
								{
									word = conso.getConsommableBoard()[2].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 220 and event.button.y < 380)
							{
								if (conso.getConsommableBoard()[3].getNumberItem() != 0)
								{
									word = conso.getConsommableBoard()[3].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 220 and event.button.y < 380)
							{
								if (conso.getConsommableBoard()[4].getNumberItem() != 0)
								{
									word = conso.getConsommableBoard()[4].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 220 and event.button.y < 380)
							{
								if (conso.getConsommableBoard()[5].getNumberItem() != 0)
								{
									word = conso.getConsommableBoard()[5].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 410 and event.button.y < 570)
							{
								if (conso.getConsommableBoard()[6].getNumberItem() != 0)
								{
									word = conso.getConsommableBoard()[6].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 410 and event.button.y < 570)
							{
								if (conso.getConsommableBoard()[7].getNumberItem() != 0)
								{
									word = conso.getConsommableBoard()[7].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 410 and event.button.y < 570)
							{
								/*
									if (conso.getConsommableBoard()[8].getNumberItem() != 0)
									{
										word = conso.getConsommableBoard()[8].getNameItem();
										inInventory = false;
									}	
									*/
							}
							break;
						}
					}

					if (word != "yarien")
					{
						Consommable toConsume;
						toConsume = conso.searchInInventoryConsommable(word);
						conso.deleteFromInventoryConsommable(toConsume.getIdItem());
						polytama.consume(toConsume);
						conso.saveIndexConsommable("data/indexConsommable.txt");
					}
					GameSdlPrintTama(polytama, window, renderer);
				}

				//Bouton inventaire clothes pour changer de vêtement
				if (event.button.x > 570 and event.button.x < 620 and event.button.y > 500 and event.button.y < 550)
				{
					printSdlInventoryClothes(window, renderer, clo);
					string word = "yarien";
					bool inInventory = true;
					while (inInventory)
					{
						SDL_Event event;

						SDL_WaitEvent(&event);

						switch (event.type)
						{
						case SDL_MOUSEBUTTONDOWN:
							if (event.button.x > 50 and event.button.x < 150 and event.button.y > 50 and event.button.y < 150)
							{
								inInventory = false;
							}
							else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 30 and event.button.y < 190)
							{
								if (clo.getClothesBoard()[0].getNumberItem() != 0)
								{
									word = clo.getClothesBoard()[0].getNameItem();
									cout << "sweat" << endl;
									inInventory = false;
								}
							}
							else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 30 and event.button.y < 190)
							{
								if (clo.getClothesBoard()[1].getNumberItem() != 0)
								{
									word = clo.getClothesBoard()[1].getNameItem();
									cout << "sombrero" << endl;
									inInventory = false;
								}
							}
							else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 30 and event.button.y < 190)
							{
								if (clo.getClothesBoard()[2].getNumberItem() != 0)
								{
									//word = clo.getClothesBoard()[2].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 220 and event.button.y < 380)
							{
								if (clo.getClothesBoard()[3].getNumberItem() != 0)
								{
									//word = clo.getClothesBoard()[3].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 220 and event.button.y < 380)
							{
								if (clo.getClothesBoard()[4].getNumberItem() != 0)
								{
									//word = clo.getClothesBoard()[4].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 220 and event.button.y < 380)
							{
								if (clo.getClothesBoard()[5].getNumberItem() != 0)
								{
									//word = clo.getClothesBoard()[5].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 410 and event.button.y < 570)
							{
								if (clo.getClothesBoard()[6].getNumberItem() != 0)
								{
									word = clo.getClothesBoard()[6].getNameItem();
									cout << "t-shirt polytech" << endl;
									inInventory = false;
								}
							}
							else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 410 and event.button.y < 570)
							{
								if (clo.getClothesBoard()[7].getNumberItem() != 0)
								{
									//word = clo.getClothesBoard()[7].getNameItem();
									inInventory = false;
								}
							}
							else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 410 and event.button.y < 570)
							{
								/*
									if (conso.getConsommableBoard()[8].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[8].getNameItem();
										inInventory = false;
									}	
									*/
							}
							break;
						}
					}

					if (word != "yarien")
					{
						Clothes toWear;
						toWear = clo.searchInInventoryClothes(word);
						if (polytama.getClothes(toWear.getSlotClothes()) != nullptr)
						{
							Clothes clot2 = *polytama.getClothes(toWear.getSlotClothes());
							clo.addInInventoryClothes(clot2);
						}
						polytama.wearClothes(toWear);
						clo.deleteFromInventoryClothes(toWear.getIdItem());
						clo.saveIndexClothes("data/indexClothes.txt");
					}
					GameSdlPrintTama(polytama, window, renderer);
				}

				//Bouton menu musique
				if (event.button.x > 720 and event.button.x < 770 and event.button.y > 70 and event.button.y < 120)
				{
					if (menuS == false)
					{
						CreateImage("data/image/Pause.png", window, renderer, 680, 140, false);
						CreateImage("data/image/soundlow.png", window, renderer, 710, 140, false);
						CreateImage("data/image/soundup.png", window, renderer, 740, 140, false);
						SDL_RenderPresent(renderer);
						menuS = true;
					}
					else
					{
						GameSdlPrintTama(polytama, window, renderer);
						menuS = false;
					}
				}
				//menu musique
				if (menuS)
				{ //play/pause
					if (event.button.x > 684 and event.button.x < 705 and event.button.y > 143 and event.button.y < 166)
					{
						if (Mix_PausedMusic() != 1)
						{
							Mix_PauseMusic();
						}
						else
						{
							Mix_ResumeMusic();
						}
					}
					//bouton -
					if (event.button.x > 713 and event.button.x < 730 and event.button.y > 145 and event.button.y < 165)
					{
						if (volume > 20)
						{
							volume -= 20;
						}
						else
						{
							volume = 0;
						}
						Mix_VolumeMusic(volume);
					}
					//bouton +
					if (event.button.x > 742 and event.button.x < 768 and event.button.y > 143 and event.button.y < 168)
					{
						if (volume < 108)
						{
							volume += 20;
						}
						else
						{
							volume = 128;
						}
						Mix_VolumeMusic(volume);
					}
				}
				//Bouton quitter
				if (event.button.x > 720 and event.button.x < 770 and event.button.y > 10 and event.button.y < 60)
				{
					program_launched = false;
				}
				break;

			case SDL_MOUSEMOTION:
				//cout << event.motion.x << "/" << event.motion.y << endl;
				/*
				{
					SDL_Color black = {0, 0, 0};
					if (event.motion.x > 720 and event.motion.x < 770 and event.motion.y > 10 and event.motion.y < 60)
					{


						CreateText("Quitter",window,renderer,black,"font.ttf",20,650,20,false);
						SDL_RenderPresent(renderer);
					
					}
					
				}
				*/
				break;

			case SDL_QUIT:
				program_launched = false;
				break;

			default:
				break;
			}
		}
	}
	Mix_FreeMusic(music);
	polytama.save("save.txt");
}

void printSdlInventoryConsommable(SDL_Window *&window, SDL_Renderer *&renderer, const InventoryConsommable &conso)
{
	CreateImage("data/image/inventoryconsommable.png", window, renderer, 0, 0, true);
	CreateImage("data/image/back1.png", window, renderer, 50, 50, false);
	for (unsigned int i = 0; i < conso.calculNumberConsommable(); i++)
	{
		vector<Consommable> tab = conso.getConsommableBoard();
		if (tab[i].getNumberItem() != 0)
		{
			string id = to_string(tab[i].getIdItem());
			string image = "data/image/items/" + id + ".png";
			string quantity = to_string(tab[i].getNumberItem());
			int posx, posy;
			switch (i)
			{
			case 0:
				posx = 230;
				posy = 30;
				break;

			case 1:
				posx = 420;
				posy = 30;
				break;

			case 2:
				posx = 610;
				posy = 30;
				break;

			case 3:
				posx = 230;
				posy = 220;
				break;

			case 4:
				posx = 420;
				posy = 220;
				break;

			case 5:
				posx = 610;
				posy = 220;
				break;

			case 6:
				posx = 230;
				posy = 410;
				break;
			case 7:
				posx = 420;
				posy = 410;
				break;
			case 8:
				posx = 610;
				posy = 410;
				break;
			}
			SDL_Color black = {0, 0, 0};
			CreateImage(image, window, renderer, posx, posy, false);
			CreateText(quantity, window, renderer, black, "font.ttf", 25, posx + 120, posy, false);
		}
	}
	SDL_RenderPresent(renderer);
}

void printSdlInventoryClothes(SDL_Window *&window, SDL_Renderer *&renderer, const InventoryClothes &clo)
{
	CreateImage("data/image/inventoryclothes.png", window, renderer, 0, 0, true);
	CreateImage("data/image/back2.png", window, renderer, 50, 50, false);

	for (unsigned int i = 0; i < clo.calculNumberClothes(); i++)
	{
		vector<Clothes> tab = clo.getClothesBoard();
		if (tab[i].getNumberItem() != 0)
		{
			cout << tab[i].getIdItem() << endl;
			string id = to_string(tab[i].getIdItem());
			string image = "data/image/items/" + id + ".png";
			int posx, posy;
			switch (i)
			{
			case 0:
				posx = 230;
				posy = 30;
				break;

			case 1:
				posx = 420;
				posy = 30;
				break;

			case 2:
				posx = 610;
				posy = 30;
				break;

			case 3:
				posx = 230;
				posy = 220;
				break;

			case 4:
				posx = 420;
				posy = 220;
				break;

			case 5:
				posx = 610;
				posy = 220;
				break;

			case 6:
				posx = 230;
				posy = 410;
				break;
			case 7:
				posx = 420;
				posy = 410;
				break;
			case 8:
				posx = 610;
				posy = 410;
				break;
			}
			CreateImage(image, window, renderer, posx, posy, false);
		}
	}
	SDL_RenderPresent(renderer);
}

void GameSdlPrintTama(const Polytama &polytama, SDL_Window *&window, SDL_Renderer *&renderer)
{
	//print terrain
	CreateImage("data/image/Background.png", window, renderer, 0, 0, true);

	CreateImage("data/image/Consoinventory.png", window, renderer, 500, 500, false);
	CreateImage("data/image/iconclothes.png", window, renderer, 570, 500, false);
	CreateImage("data/image/Bath.png", window, renderer, 200, 500, false);
	CreateImage("data/image/minigame.png", window, renderer, 270, 500, false);
	CreateImage("data/image/quit.png", window, renderer, 720, 10, false);
	CreateImage("data/image/music.png", window, renderer, 720, 70, false);

	//print bars
	SDL_Color blue = {0, 0, 255};
	CreateText(polytama.getName(), window, renderer, blue, "font.ttf", 60, 0, -265, true);
	//Joie
	CreateImage("data/image/Joy.png", window, renderer, 0, 0, false);
	CreateText(to_string((polytama.getJoy()).getValue()), window, renderer, blue, "font.ttf", 40, 60, 0, false);
	//Faim
	CreateImage("data/image/Hunger.png", window, renderer, 0, 60, false);
	CreateText(to_string((polytama.getHunger()).getValue()), window, renderer, blue, "font.ttf", 40, 60, 60, false);
	//Soif
	CreateImage("data/image/Thirst.png", window, renderer, 0, 120, false);
	CreateText(to_string((polytama.getThirst()).getValue()), window, renderer, blue, "font.ttf", 40, 60, 120, false);
	//Hygiène
	CreateImage("data/image/Hygiene.png", window, renderer, 0, 180, false);
	CreateText(to_string((polytama.getHygiene()).getValue()), window, renderer, blue, "font.ttf", 40, 60, 180, false);

	//print des vêtements
	string head, chest, accessory;
	//Chest
	if (polytama.getClothes(1) == nullptr)
	{
		chest = "data/image/tama/Tamachest.png";
	}
	else
	{
		string id = to_string(polytama.getClothes(1)->getIdItem());
		chest = "data/image/tama/Tamachest" + id + ".png";
	}
	//Accessory
	string mood = polytama.getMood();
	if (polytama.getClothes(2) == nullptr)
	{
		accessory = "data/image/tama/Tamahead" + mood + ".png";
	}
	else
	{
		string id = to_string(polytama.getClothes(2)->getIdItem());
		accessory = "data/image/tama/Tamahead" + mood + id + ".png";
	}
	CreateImage(chest, window, renderer, 0, 40, true);
	CreateImage(accessory, window, renderer, 0, -50, true);
	//Head (hat)
	if (polytama.getClothes(0) != nullptr)
	{
		string id = to_string(polytama.getClothes(0)->getIdItem());
		head = "data/image/tama/Tamahead" + id + ".png";
		CreateImage(head, window, renderer, 0, -50, true);
	}

	SDL_RenderPresent(renderer);
}