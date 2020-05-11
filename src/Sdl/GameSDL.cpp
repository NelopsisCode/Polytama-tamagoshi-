#include "GameSDL.h"

void GameSdlInit(SDL_Window *&window, SDL_Renderer *&renderer, SDL_Texture *&texture)
{

	//Initialisation SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
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

	CreateImage("data/image/Backgroundstart.png", window, renderer, 0, 0, true);
	SDL_Color white = {0, 0, 0};
	CreateImage("data/image/Title.png", window, renderer, 0, 0, true);
	CreateImage("data/image/ContinueButton.png", window, renderer, 0, 0, true);
	CreateImage("data/image/NewgameButton.png", window, renderer, 0, 0, true);
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
				//cout << event.button.x << "/" << event.button.y << endl;
				//Continuer
				if (event.button.x > 197 and event.button.x < 633 and event.button.y > 270 and event.button.y < 371)
				{
					long int initTime;
					polytama.loadSave("save.txt", initTime);
					polytama.pastTime(initTime);
					startScreen = false;
				}
				//Nouvelle partie
				else if (event.button.x > 238 and event.button.x < 581 and event.button.y > 393 and event.button.y < 566)
				{
					CreateImage("data/image/Backgroundstart.png", window, renderer, 0, 0, true);
					CreateText("Êtes vous sûr?", window, renderer, white, "data/font/font.ttf", 70, 0, -220, true);
					CreateText("(cela supprimera la sauvegarde actuelle)", window, renderer, white, "data/font/font.ttf", 20, 0, -180, true);
					CreateImage("data/image/Yesbutton.png", window, renderer, 0, -60, true);
					CreateImage("data/image/Nobutton.png", window, renderer, 0, 60, true);
					SDL_RenderPresent(renderer);
					bool verif = true;
					while (verif)
					{

						while (SDL_PollEvent(&event))
						{
							switch (event.type)
							{
							case SDL_MOUSEBUTTONDOWN:
								//oui
								if (event.button.x > 334 and event.button.x < 463 and event.button.y > 195 and event.button.y < 282)
								{
									verif = false;
									createTama(polytama, window, renderer);
								}
								//non
								else if (event.button.x > 334 and event.button.x < 463 and event.button.y > 315 and event.button.y < 404)
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
	font = TTF_OpenFont("data/font/font.ttf", 50);
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
		CreateText("Premierement, vous devez lui choisir un nom !", window, renderer, black, "data/font/font.ttf", 30, 0, -220, true);
		CreateText("(Utilisez le clavier pour saisir le nom de votre tama)", window, renderer, black, "data/font/font.ttf", 15, 0, 270, true);
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
	CreateText("Bonjour et bienvenue dans Polytama!", window, renderer, white, "data/font/font.ttf", 30, 0, -220, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
	CreateText("Ici vous allez vous occuper d'une petite creature appellée Polytama !", window, renderer, white, "data/font/font.ttf", 25, 0, -220, true);
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
		CreateText("Premierement, vous devez lui choisir un nom !", window, renderer, white, "data/font/font.ttf", 30, 0, -220, true);
		CreateText("(Utilisez le clavier pour saisir le nom de votre tama)", window, renderer, white, "data/font/font.ttf", 15, 0, 270, true);
		CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
		CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
		SDL_RenderPresent(renderer);
		//Choix du nom

		name = getTxt(window, renderer);
		CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
		CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
		CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
		CreateText("Voulez vous que votre Polytama porte le nom", window, renderer, white, "data/font/font.ttf", 30, 0, -210, true);
		CreateText(name + " ?", window, renderer, white, "data/font/font.ttf", 50, 0, -180, true);
		CreateImage("data/image/Yesbutton.png", window, renderer, -180, -70, true);
		CreateImage("data/image/Nobutton.png", window, renderer, 180, -70, true);

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
					//oui
					if (event.button.x > 148 and event.button.x < 288 and event.button.y > 179 and event.button.y < 275)
					{
						verif = false;
						choice = false;
					}
					//non
					else if (event.button.x > 504 and event.button.x < 652 and event.button.y > 179 and event.button.y < 275)
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
	CreateText("Amusez vous bien avec " + name + "!", window, renderer, white, "data/font/font.ttf", 40, 0, -220, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(800);
	CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
	CreateImage("data/image/tama/Tamachestdab106.png", window, renderer, 0, 40, true);
	CreateImage("data/image/tama/Tamaheaddab.png", window, renderer, 0, -50, true);
	CreateText("Amusez vous bien avec " + name + "!", window, renderer, white, "data/font/font.ttf", 40, 0, -220, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(800);
	CreateImage("data/image/Beginning.png", window, renderer, 0, 0, true);
	CreateImage("data/image/tama/Tamachest106.png", window, renderer, 0, 40, true);
	CreateImage("data/image/tama/Tamaheadj.png", window, renderer, 0, -50, true);
	CreateText("Amusez vous bien avec " + name + "!", window, renderer, white, "data/font/font.ttf", 40, 0, -220, true);
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

Uint32 dropBar(Uint32 interval, void *param)
{
	Polytama *tama = (Polytama *)param;

	tama->setHunger(tama->getHunger().getValue() - 1);
	tama->setJoy(tama->getJoy().getValue() - 1);
	tama->setThirst(tama->getThirst().getValue() - 1);
	tama->setHygiene(tama->getHygiene().getValue() - 1);

	return interval;
}

void GameSdlLoop(SDL_Window *&window, SDL_Renderer *&renderer, SDL_Texture *&texture, Polytama &polytama)
{
	Mix_AllocateChannels(3);
	//Lancement de la musique
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

	//Lancement du timer (perte d'un point par jauge toutes les 2 minutes) 120000 ms
	SDL_TimerID timer;
	timer = SDL_AddTimer(120000, dropBar, &polytama);

	//lancement de la boucle de jeu
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
				if (!polytama.dead())
				{
					//dab
					if (event.button.x > 395 and event.button.x < 415 and event.button.y > 352 and event.button.y < 366)
					{
						//Chest
						string chest, head, accessory;
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
						if (polytama.getClothes(2) == nullptr)
						{
							accessory = "data/image/tama/Tamaheaddab.png";
						}
						else
						{
							string id = to_string(polytama.getClothes(2)->getIdItem());
							accessory = "data/image/tama/Tamaheaddab" + id + ".png";
						}

						CreateImage(accessory, window, renderer, 0, -50, true);
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
						Mix_Chunk *bath;
						bath = Mix_LoadWAV("data/sound/bath.wav");
						Mix_VolumeChunk(bath,volume/2);			
						polytama.takeABath();
						CreateImage("data/image/Takeabath1.png", window, renderer, 0, 0, true);
						SDL_RenderPresent(renderer);
						Mix_PlayChannel(2,bath,0);
						SDL_Delay(4000);
						Mix_HaltChannel(2);
						Mix_FreeChunk(bath);
						SDL_Color blue = {0, 0, 255};
						CreateImage("data/image/Takeabath2.png", window, renderer, 0, 0, true);
						CreateText(polytama.getName() + " est tout propre!", window, renderer, blue, "data/font/font.ttf", 60, 0, 250, true);
						SDL_RenderPresent(renderer);
						SDL_Delay(2000);
						CreateImage("data/image/Takeabath3.png", window, renderer, 0, 0, true);
						CreateText(polytama.getName() + " est tout propre!", window, renderer, blue, "data/font/font.ttf", 60, 0, 250, true);
						SDL_RenderPresent(renderer);
						SDL_Delay(1000);
						GameSdlPrintTama(polytama, window, renderer);
					}

					//jeu
					if (event.button.x > 270 and event.button.x < 320 and event.button.y > 500 and event.button.y < 550)
					{
						CreateImage("data/image/MinigameMenu.png", window, renderer, 0, 0, true);
						CreateImage("data/image/back3.png", window, renderer, 50, 50, false);
						CreateImage("data/image/Tictactoe.png", window, renderer, 400, 50, false);
						CreateImage("data/image/Hanged.png", window, renderer, 275, 325, false);
						CreateImage("data/image/Memory.png", window, renderer, 525, 325, false);
						SDL_RenderPresent(renderer);
						Mini_Game game;
						bool inMg = true;
						bool quit = false;
						bool trophee = false;

						while (inMg)
						{
							SDL_Event event;

							SDL_WaitEvent(&event);

							switch (event.type)
							{
							case SDL_MOUSEBUTTONDOWN:
								if (event.button.x > 50 and event.button.x < 150 and event.button.y > 50 and event.button.y < 150)
								{
									inMg = false;
									quit = true;
								}
								else if (event.button.x > 400 and event.button.x < 600 and event.button.y > 50 and event.button.y < 250)
								{
									Game_TicTacToe ttt;
									playSDL(ttt, window, renderer);
									trophee = ttt.getTropheeTictactoe();
									inMg = false;
								}
								else if (event.button.x > 275 and event.button.x < 475 and event.button.y > 325 and event.button.y < 525)
								{
									Game_Hanged hg;
									playHangedSDL(hg, window, renderer);
									trophee = hg.getTropheeHanged();
									inMg = false;
								}
								else if (event.button.x > 525 and event.button.x < 725 and event.button.y > 325 and event.button.y < 525)
								{
									Game_Memory memo;
									playMemorySDL(memo, window, renderer);
									trophee = memo.getTropheeMemory();
									inMg = false;
								}

								break;
							}
						}

						GameSdlPrintTama(polytama, window, renderer);

						if (trophee == true)
						{
							polytama.addJoy(30);
							SDL_Color black = {0, 0, 0};
							game.generateReward();
							unsigned int reward = game.getReward();

							if (alreadyGot(reward, polytama, clo))
							{
								reward = 9;
							}

							if (reward < 100)
							{
								Consommable consom = conso.searchIdInInventoryConsommable(reward);
								conso.addInInventoryConsommable(consom);
								CreateText("Vous avez gagné", window, renderer, black, "data/font/font.ttf", 90, 0, -20, true);
								CreateImage("data/image/items/" + to_string(consom.getIdItem()) + ".png", window, renderer, 0, 150, true);
								SDL_RenderPresent(renderer);
								SDL_Delay(1500);

								conso.saveIndexConsommable("data/indexConsommable.txt");
							}
							else
							{
								Clothes clot = clo.searchIdInInventoryClothes(reward);
								clo.addInInventoryClothes(clot);
								CreateText("Vous avez gagné", window, renderer, black, "data/font/font.ttf", 90, 0, -20, true);
								CreateImage("data/image/items/" + to_string(clot.getIdItem()) + ".png", window, renderer, 0, 100, true);
								SDL_RenderPresent(renderer);
								SDL_Delay(1500);

								clo.saveIndexClothes("data/indexClothes.txt");
							}
						}
						else
						{
							if (!quit)
							{
								polytama.addJoy(-30);
							}
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

									if (conso.getConsommableBoard()[8].getNumberItem() != 0)
									{
										word = conso.getConsommableBoard()[8].getNameItem();
										inInventory = false;
									}
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
						printSdlInventoryClothes(window, renderer, clo, polytama);
						string word = "yarien";
						IdBody body;
						bool remove = false;
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

										inInventory = false;
									}
								}
								else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 30 and event.button.y < 190)
								{
									if (clo.getClothesBoard()[1].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[1].getNameItem();

										inInventory = false;
									}
								}
								else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 30 and event.button.y < 190)
								{
									if (clo.getClothesBoard()[2].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[2].getNameItem();
										inInventory = false;
									}
								}
								else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 220 and event.button.y < 380)
								{
									if (clo.getClothesBoard()[3].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[3].getNameItem();
										inInventory = false;
									}
								}
								else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 220 and event.button.y < 380)
								{
									if (clo.getClothesBoard()[4].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[4].getNameItem();
										inInventory = false;
									}
								}
								else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 220 and event.button.y < 380)
								{
									if (clo.getClothesBoard()[5].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[5].getNameItem();
										inInventory = false;
									}
								}
								else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 410 and event.button.y < 570)
								{
									if (clo.getClothesBoard()[6].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[6].getNameItem();

										inInventory = false;
									}
								}
								else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 410 and event.button.y < 570)
								{
									if (clo.getClothesBoard()[7].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[7].getNameItem();
										inInventory = false;
									}
								}
								else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 410 and event.button.y < 570)
								{
									if (clo.getClothesBoard()[8].getNumberItem() != 0)
									{
										word = clo.getClothesBoard()[8].getNameItem();
										inInventory = false;
									}
								}
								else if (event.button.x > 38 and event.button.x < 166 and event.button.y > 202 and event.button.y < 277)
								{
									if (polytama.getClothes(0) != nullptr)
									{
										remove = true;
										body = HEAD;
										inInventory = false;
									}
								}
								else if (event.button.x > 38 and event.button.x < 166 and event.button.y > 438 and event.button.y < 544)
								{
									if (polytama.getClothes(1) != nullptr)
									{
										remove = true;
										body = CHEST;
										inInventory = false;
									}
								}
								else if (event.button.x > 38 and event.button.x < 166 and event.button.y > 311 and event.button.y < 385)
								{
									remove = true;
									body = ACCESSORY;
									inInventory = false;
								}

								break;
							}
						}

						if (word != "yarien" or remove == true)
						{
							if (remove)
							{
								Clothes toRemove;
								toRemove = *(polytama.getClothes(body));
								clo.addInInventoryClothes(toRemove);
								polytama.removeClothes(body);
								clo.saveIndexClothes("data/indexClothes.txt");
							}
							else
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
						}
						GameSdlPrintTama(polytama, window, renderer);
					}
					//crédit
					if (event.button.x > 267 and event.button.x < 522 and event.button.y > 68 and event.button.y < 177)
					{
						CreateImage("data/image/Crédits.png",window,renderer,0,0,true);
						SDL_RenderPresent(renderer);
						SDL_Delay(6000);
						CreateImage("data/image/Thanks.png",window,renderer,0,0,true);
						SDL_RenderPresent(renderer);
						SDL_Delay(6000);
						GameSdlPrintTama(polytama, window, renderer);
					}
					//prise
					if (event.button.x > 98 and event.button.x < 104 and event.button.y > 273 and event.button.y < 275)
					{
						Mix_Chunk *elec;
						elec = Mix_LoadWAV("data/sound/elec.wav");
						Mix_VolumeChunk(elec,volume);
						CreateImage("data/image/tama/Thunder.png",window,renderer,0,0,true);
						SDL_RenderPresent(renderer);
						Mix_PlayChannel(2,elec,0);
						SDL_Delay(6000);
						Mix_HaltChannel(2);
						Mix_FreeChunk(elec);
						polytama.electrocute();
						GameSdlPrintTama(polytama, window, renderer);
					}

				}
				else
				{
					if (event.button.x > 301 and event.button.x < 569 and event.button.y > 101 and event.button.y < 420)
					{
						polytama.revive();
						SdlReviveAnimation(polytama.getName(), window, renderer);
						Mix_PlayMusic(music, -1);
						GameSdlPrintTama(polytama, window, renderer);
					}
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

			case SDL_QUIT:
				program_launched = false;
				break;

			default:
				break;
			}
		}
	}
	SDL_RemoveTimer(timer);
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
			CreateText(quantity, window, renderer, black, "data/font/font.ttf", 25, posx + 120, posy, false);
		}
	}
	SDL_RenderPresent(renderer);
}

void printSdlInventoryClothes(SDL_Window *&window, SDL_Renderer *&renderer, const InventoryClothes &clo, const Polytama &polytama)
{
	CreateImage("data/image/inventoryclothes.png", window, renderer, 0, 0, true);
	CreateImage("data/image/back2.png", window, renderer, 50, 50, false);
	string head, chest, accessory;
	for (unsigned int i = 0; i < clo.calculNumberClothes(); i++)
	{
		vector<Clothes> tab = clo.getClothesBoard();
		if (tab[i].getNumberItem() != 0)
		{
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
	if (polytama.getClothes(0) != nullptr)
	{
		head = "data/image/items/" + to_string((polytama.getClothes(0))->getIdItem()) + ".png";
		CreateImage(head, window, renderer, -300, -50, true);
	}

	if (polytama.getClothes(1) != nullptr)
	{
		chest = "data/image/items/" + to_string((polytama.getClothes(1))->getIdItem()) + ".png";
		CreateImage(chest, window, renderer, -300, 190, true);
	}

	if (polytama.getClothes(2) != nullptr)
	{
		accessory = "data/image/items/" + to_string((polytama.getClothes(2))->getIdItem()) + ".png";
		CreateImage(accessory, window, renderer, -300, 50, true);
	}

	SDL_RenderPresent(renderer);
}

void GameSdlPrintTama(const Polytama &polytama, SDL_Window *&window, SDL_Renderer *&renderer)
{
	//print terrain
	CreateImage("data/image/Background.png", window, renderer, 0, 0, true);
	if (!polytama.dead())
	{
		CreateImage("data/image/Consoinventory.png", window, renderer, 500, 500, false);
		CreateImage("data/image/Clothinventory.png", window, renderer, 570, 500, false);
		CreateImage("data/image/Bath.png", window, renderer, 200, 500, false);
		CreateImage("data/image/Minigame.png", window, renderer, 270, 500, false);
	}
	CreateImage("data/image/quit.png", window, renderer, 720, 10, false);
	CreateImage("data/image/music.png", window, renderer, 720, 70, false);
	//print bars
	SDL_Color blue = {0, 0, 255};
	CreateText(polytama.getName(), window, renderer, blue, "data/font/font.ttf", 60, 0, -265, true);
	//Joie
	CreateImage("data/image/Joy.png", window, renderer, 0, 0, false);
	CreateText(to_string((polytama.getJoy()).getValue()), window, renderer, blue, "data/font/font.ttf", 40, 60, 0, false);
	//Faim
	CreateImage("data/image/Hunger.png", window, renderer, 0, 60, false);
	CreateText(to_string((polytama.getHunger()).getValue()), window, renderer, blue, "data/font/font.ttf", 40, 60, 60, false);
	//Soif
	CreateImage("data/image/Thirst.png", window, renderer, 0, 120, false);
	CreateText(to_string((polytama.getThirst()).getValue()), window, renderer, blue, "data/font/font.ttf", 40, 60, 120, false);
	//Hygiène
	CreateImage("data/image/Hygiene.png", window, renderer, 0, 180, false);
	CreateText(to_string((polytama.getHygiene()).getValue()), window, renderer, blue, "data/font/font.ttf", 40, 60, 180, false);

	if (!polytama.dead())
	{
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

		//Propreté
		if (polytama.getHygiene().getValue() < 30)
		{
			CreateImage("data/image/tama/Tupu.png", window, renderer, 0, 50, true);
		}
		else if (polytama.getHygiene().getValue() > 90)
		{
			CreateImage("data/image/tama/Clean.png", window, renderer, 0, 0, true);
		}
	}
	else
	{
		SDL_Color black = {0, 0, 0};
		CreateImage("data/image/BackgroundRIP.png", window, renderer, 0, 0, true);
		CreateText("Oh non..." + polytama.getName() + " est mort...", window, renderer, black, "data/font/font.ttf", 40, 0, -250, true);
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
		CreateImage("data/image/BackgroundRIP.png", window, renderer, 0, 0, true);
		CreateText("Il faut plus prendre soin de ton Polytama!", window, renderer, black, "data/font/font.ttf", 40, 0, -250, true);
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
		CreateImage("data/image/BackgroundRIP.png", window, renderer, 0, 0, true);
		CreateText("Heureusement que ces petites créatures sont resistantes.", window, renderer, black, "data/font/font.ttf", 30, 0, -250, true);
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
		CreateImage("data/image/BackgroundRIP.png", window, renderer, 0, 0, true);
		CreateText("Clic sur le fantôme de " + polytama.getName() + " pour le faire revenir à la vie.", window, renderer, black, "data/font/font.ttf", 30, 0, -250, true);
	}

	SDL_RenderPresent(renderer);
}

//Fonction pour éviter de pouvoir gagner un vêtement déjà acquis
bool alreadyGot(const unsigned int &reward, const Polytama &polytama, const InventoryClothes &clo)
{
	//Si l'objet est un consommable on renvoie faux
	if (reward < 100)
	{
		return false;
	}

	//Si l'objet est porté par le tama on renvoie vrai
	for (unsigned int i = 0; i < 3; i++)
	{
		if (polytama.getClothes(i) != nullptr)
		{
			if (polytama.getClothes(i)->getIdItem() == reward)
			{

				return true;
			}
		}
	}

	//Si l'objet est dans l'inventaire on renvoie vrai

	if (clo.searchIdInInventoryClothes(reward).getNumberItem() == 1)
	{

		return true;
	}

	//Si l'objet n'est pas un consommable, n'est pas porté par le tama et n'est pas dans l'inventaire on renvoie faux
	return false;
}

void SdlReviveAnimation(const string &name, SDL_Window *&window, SDL_Renderer *&renderer)
{
	Mix_AllocateChannels(4);
	Mix_Chunk *storm;
	Mix_Chunk *thunder;
	Mix_Chunk *elec;
	storm = Mix_LoadWAV("data/sound/rain.wav");
	thunder = Mix_LoadWAV("data/sound/thunder.wav");
	elec = Mix_LoadWAV("data/sound/elec.wav");

	Mix_VolumeChunk(thunder, MIX_MAX_VOLUME / 2);
	Mix_VolumeChunk(elec, MIX_MAX_VOLUME / 2);

	Mix_Music *revive = NULL;
	revive = Mix_LoadMUS("data/sound/Revive.mp3");
	Mix_VolumeMusic(28);

	if (revive == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Log("Erreur: Chargement de la musique");
	}
	Mix_PlayMusic(revive, -1);
	Mix_PlayChannel(1, storm, 0);

	CreateImage("data/image/ReviveBackground1.png", window, renderer, 0, 0, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	Mix_PlayChannel(2, thunder, 0);
	CreateImage("data/image/ReviveBackground2.png", window, renderer, 0, 0, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);

	Mix_VolumeChunk(storm, MIX_MAX_VOLUME / 2);
	CreateImage("data/image/ReviveBackground3.png", window, renderer, 0, 0, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(2500);

	CreateImage("data/image/ReviveBackground4.png", window, renderer, 0, 0, true);
	SDL_Color white = {255,255,255};
	CreateText("Clic sur " + name + " pour commencer la résurrection.", window, renderer, white, "data/font/font.ttf", 30, 0, 280, true);
	SDL_RenderPresent(renderer);

	bool notres = true;

	while (notres)
	{
		SDL_Event event;
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			notres = false;
		}
	}

	Mix_PlayChannel(2, elec, 0);
	Mix_PlayChannel(3, thunder, 0);
	CreateImage("data/image/ReviveBackground5.png", window, renderer, 0, 0, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(6000);
	Mix_HaltChannel(2);

	CreateImage("data/image/ReviveBackground6.png", window, renderer, 0, 0, true);
	CreateText(name + " est de retour !", window, renderer, white, "data/font/font.ttf", 40, 0, 280, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);

	CreateImage("data/image/ReviveBackground7.png", window, renderer, 0, 0, true);
	CreateText(name + " est de retour !", window, renderer, white, "data/font/font.ttf", 40, 0, 280, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(800);

	CreateImage("data/image/ReviveBackground6.png", window, renderer, 0, 0, true);
	CreateText("Malheureusement ses affaires n'ont pas resisté à l'experience...", window, renderer, white, "data/font/font.ttf", 20, 0, 280, true);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	Mix_FreeChunk(thunder);
	Mix_FreeChunk(storm);
	Mix_FreeChunk(elec);
	Mix_FreeMusic(revive);
}