#include "Mini_Game.h"

using namespace std;

Mini_Game::Mini_Game()
{
	trophee = true;
	reward = 0;
}

unsigned int Mini_Game::getReward()const
{
	return reward;
}

bool Mini_Game::getTrophee()const
{
	return trophee;
}

void Mini_Game::selectAndPlayMiniGame()
{
	cout << "=== Liste des jeux ===" << endl;
	cout << "1: Morpion" << endl;
	cout << "2: Jeu du serpent" << endl;
	cout << "3: Memory" <<endl;
	cout << "======================" << endl;

	int mg;
	cin >> mg;

	switch (mg) {
		case 1 : { 
			Game_TicTacToe ttt;
			ttt.play();
			trophee = ttt.getTropheeTictactoe();
			if (trophee == true)
			{
				generateReward();
			}
			
		} break;
		case 2 : { 
			cout<<"impossible pour l'instant"<<endl;

			//Game_Snake sn;
			//sn.play();

		}break;
		case 3 : {
			cout<<"impossible pour l'instant"<<endl;

			//Game_Memory mem;
			//mem.play();
		}break;
		default : {
			cout<<"Veuillez choisir une proposition ci-dessus"<<endl;
		}break;
	}


}



void Mini_Game::generateReward()
{
	if (trophee == true)
	{
		unsigned int a, id;
		//tirage aléatoire nombre entre 1 et 100
		int min = 1; 
		int max = 100;
		int plage = max - min + 1;
		srand((unsigned int)time(NULL));
		a = (rand() % plage) + min;

		if(a > 80)
		{
			//tirage d'un Clothes
			min = 100; 
			max = 109; //100+nb de vêtements
			plage = max - min + 1;
			id = (rand() % plage) + min;
		}
		else
		{
			//tirage d'un consommable
			min = 1; 
			max = 10; //1+nb de consommable 
			plage = max - min + 1;
			id = (rand() % plage) + min;
			
		}
		reward = id;
		cout << reward << endl;
	}
	
	
}
