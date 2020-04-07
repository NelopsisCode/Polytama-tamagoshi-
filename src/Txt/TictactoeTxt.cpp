#include "TictactoeTxt.h"
#include "ncurses.h"

TicTacToeTxt::TicTacToeTxt()
{
	for (unsigned int i=0; i<3 ;i++)
	{
		for(unsigned int j=0; j<3 ;j++)
		{
			boardTictactoeTxt[i][j]='_';
		}
	}

	tropheeTictactoeTxt = false;

}

void TicTacToeTxt::printBoardTictactoeTxt()const
{
	string translate;
	attron(A_NORMAL);
	for (unsigned int i=0; i<3 ;i++)
	{
		for(unsigned int j=0; j<3 ;j++)
		{
			translate=boardTictactoeTxt[i][j];
			printw(translate.c_str());
			printw(" ");
		}
		printw("\n");
	}
	printw("\n");
	refresh();
}

//isset = true si le pion est placÃ©, false sinon
void TicTacToeTxt::setCaseTxt(const unsigned int & x, const unsigned int & y, 
	const char & player, bool & isset)
{
	//1er cas: les coordonnÃ©es sont bonnes
	
	if ((x>=1) && (x<=3) && (y>=1) && (y<=3) && (boardTictactoeTxt[x-1][y-1]=='_'))
	{
		boardTictactoeTxt[x-1][y-1] = player;
		isset = true;
	}

	//2eme cas: les coordonnÃ©es ne sont pas bonne, on indique l'erreur.
	else
	{
		if ((x<1) || (x>3) || (y<1) || (y>3))
		{
			printw("Votre pion est hors du jeu... Recommencez");
			printw("\n");
			isset = false;
		}
		else if ((boardTictactoeTxt[x-1][y-1]=='X') || (boardTictactoeTxt[x-1][y-1]=='O'))
		{
			printw("Un pion se trouve deja sur cette case... Recommencez");
			printw("\n");
			isset = false;
		}
	}
	refresh();
}

bool TicTacToeTxt::tieTxt()const
{
	for (unsigned int i = 0; i < 3; i++)
	{
		if (boardTictactoeTxt[i][0] == '_' || boardTictactoeTxt[i][1] == '_' || boardTictactoeTxt[i][2] == '_')
			return false;
	}
	return true;
}

bool TicTacToeTxt::winTxt(const char & player)const
{
	if (//Horizontal
		(boardTictactoeTxt[0][0]==player && boardTictactoeTxt[0][1]==player && boardTictactoeTxt[0][2]==player) ||
		(boardTictactoeTxt[1][0]==player && boardTictactoeTxt[1][1]==player && boardTictactoeTxt[1][2]==player) ||
		(boardTictactoeTxt[2][0]==player && boardTictactoeTxt[2][1]==player && boardTictactoeTxt[2][2]==player) ||
        //vertical
		(boardTictactoeTxt[0][0]==player && boardTictactoeTxt[1][0]==player && boardTictactoeTxt[2][0]==player) ||
		(boardTictactoeTxt[0][1]==player && boardTictactoeTxt[1][1]==player && boardTictactoeTxt[2][1]==player) ||
		(boardTictactoeTxt[0][2]==player && boardTictactoeTxt[1][2]==player && boardTictactoeTxt[2][2]==player) ||
        //diagonal
		(boardTictactoeTxt[0][0]==player && boardTictactoeTxt[1][1]==player && boardTictactoeTxt[2][2]==player) ||
		(boardTictactoeTxt[0][2]==player && boardTictactoeTxt[1][1]==player && boardTictactoeTxt[2][0]==player))
	{
		return(true);
	}
	else
	{
		return (false);
	}

}

 bool TicTacToeTxt::gameOverTxt(const char & player)const
{

	if (tieTxt())
	{ 
		printw("C'est une égalité ...");
		printw("\n");
		return true;
	}

	if (winTxt(AI))
	{
		printw("L'ordinateur a gangé !");
		printw("\n");
		return true;
	}
	if (winTxt (HUMAN))
	{
		printw("Tu as gagné !");
		printw("\n");
		return true;
	}

	return false;
	refresh();
}
 
 Move TicTacToeTxt::minimaxTxt(char AIboard[3][3]) const
{

	int bestMoveValue = 100;
	Move bestMove;

	for(unsigned int i = 0; i < 3; i++) 
	{
		for(unsigned int j = 0; j < 3; j++) 
		{
			//Pour chaque case vide, on recupÃ¨re la valeur du move et on le compare Ã  la meilleure valeur
			if(AIboard[i][j] == '_') 
			{
				AIboard[i][j] = AI;
				int tempMoveValue = maxSearchTxt(AIboard);
				//cout << "value = " << tempMoveValue <<endl;
				if(tempMoveValue <= bestMoveValue) 
				{
					bestMoveValue = tempMoveValue;
					bestMove.x = i+ 1;
					bestMove.y = j+ 1;
				}
				AIboard[i][j] = '_';
			}
		}
	}

	return bestMove;

}
 
 int TicTacToeTxt::maxSearchTxt(char AIboard[3][3])const
{
	Move bestMove;

	if (winTxt(HUMAN)) { return 10; }
	else if (winTxt(AI)) { return -10; }
	else if (tieTxt()) { return 0; }

	int bestMoveValue = -10000;
	for(unsigned int i = 0; i < 3; i++)
	{
		for(unsigned int j= 0; j < 3; j++)
		{
			if (AIboard[i][j] == '_')
			{
				AIboard[i][j] = HUMAN;
				int tempMoveValue = minSearchTxt(AIboard);
				//cout << "min = " << tempMoveValue <<endl;
				if(tempMoveValue >= bestMoveValue)
				{
					bestMoveValue = tempMoveValue;
					bestMove.x = i;
					bestMove.y = j;
				}
				AIboard[i][j] = '_';
			}

		}
	}
	return bestMoveValue;
}
 
 int TicTacToeTxt::minSearchTxt(char AIboard[3][3])const 
{
	Move bestMove;

	if (winTxt(HUMAN)) 
	{ 
		return 10; 
	}
	else if (winTxt(AI)) 
	{ 
		return -10; 
	}
	else if (tieTxt()) 
	{ 
		return 0; 
	}


	int bestMoveValue = 10000000; 
	for(unsigned int i = 0; i < 3; i++) 
	{
		for(unsigned int j = 0; j < 3; j++) 
		{
			if(AIboard[i][j] == '_') 
			{
				AIboard[i][j] = AI;
				int tempMove = maxSearchTxt(AIboard);
				//cout << "max = " << bestMoveValue <<endl;
				if(tempMove <= bestMoveValue) 
				{
					bestMoveValue = tempMove;
					bestMove.x = i;
					bestMove.y = j;
				}
				AIboard[i][j] = '_';
			}
		}
	}

	return bestMoveValue;
}
 
 void TicTacToeTxt::playTxt()
{
	int tour;

	bool fin;

	tour = 0;
	fin = false;



	while (fin == false)
	{
        //On regarde qui est le player en fonction du tour
        if (tour % 2 == 0) //humain
        {
			printBoardTictactoeTxt();
        	char x,y;
        	bool isset;
        	do{
				echo();
        		printw("Ligne: ") ;
        		x=getch();
        		printw("Colonne: ");
        		y=getch();
				unsigned int t=x-48;
				unsigned int v=y-48;
        		setCaseTxt(t,v, HUMAN, isset);
				
				refresh();
        	}while (isset == false); 
			
        	fin = gameOverTxt(HUMAN);
			clear();
        }

        else // IA
        {
        	bool isset;
        	Move AImove = minimaxTxt(boardTictactoeTxt);
        	//cout << AImove.x <<endl << AImove.y <<endl;
        	setCaseTxt(AImove.x, AImove.y, AI ,isset);
        	fin = gameOverTxt(AI);
			refresh();
        }
        tour ++;
		
    }
    if (winTxt(HUMAN))
    {
    	tropheeTictactoeTxt = true;
    }
	 noecho();
	 refresh();
}

				
