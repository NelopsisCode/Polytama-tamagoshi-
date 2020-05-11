#include "Memory.h"
using namespace std;

Game_Memory::Game_Memory()
{
	for(unsigned int i=0; i<4; i++)
	{
		for(unsigned int j=0; j<4; j++)
		{
			memoryBoard[i][j].filename="NULL";
			memoryBoard[i][j].idImage=0;
			memoryBoard[i][j].open=false;
			memoryBoard[i][j].find=false;
		}
	}
	tropheeMemory = false;
	attempts = 20;
}


int Game_Memory::getAttempts()const
{
	return attempts;
}
bool Game_Memory::getTropheeMemory()const
{
	return tropheeMemory;
}

void Game_Memory::setTropheeMemory(const bool & t)
{
	tropheeMemory = t;
}

bool Game_Memory::getOpen(const unsigned int& x, const unsigned int& y)const
{
	return memoryBoard[x][y].open;
}

void Game_Memory::setOpen(const bool & b, const unsigned int & x,const unsigned int & y)
{
	memoryBoard[x][y].open = b;
}

string Game_Memory::getFilename(const unsigned int& x, const unsigned int& y)
{
	return memoryBoard[x][y].filename;
}

void Game_Memory::initMemory(const string & filenameGlobal){
	
	//srand(time(NULL));
	ifstream index(filenameGlobal.c_str());
	assert(index.is_open());
	Image empty[16];
	string name;
	unsigned int id;
	for(unsigned int i=0; i<8; i++)
		{
				index>>id>>name;
				empty[i].filename=name;
				empty[i].idImage=id;
				empty[i].open=false;
				empty[i].find=false;
		}
	for(unsigned int i=8; i<16;i++)
		{
			empty[i].filename=empty[i-8].filename;
			empty[i].idImage=empty[i-8].idImage;
			empty[i].open=empty[i-8].open;
			empty[i].find=empty[i-8].find;
		}
	for(unsigned int i=0; i<4; i++)
		{
		for(unsigned int j=0; j<4; j++)
			{
				unsigned int a;
				do 
				{
					a = (rand()%16);
					if(empty[a].open == false){
						setCaseMemory(i,j,empty[a]);
					}
				}while(empty[a].open);
				empty[a].open=true;
				
			}
		}
}

void Game_Memory::printBoardMemory(){
	for(unsigned int i=0; i<4; i++)
	{
		for(unsigned int j=0; j<4; j++)
		{
			if (memoryBoard[i][j].open)
			{
				cout<<memoryBoard[i][j].filename<<" ";
				
			}else{
				cout<<"_ ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

void Game_Memory::setCaseMemory (const unsigned int& x, const unsigned int& y, const Image& image)
{
		memoryBoard[x][y].filename=image.filename;
		memoryBoard[x][y].idImage=image.idImage;
		memoryBoard[x][y].open=image.open;
		memoryBoard[x][y].find=image.find;
}

void Game_Memory::winTest()
{
	Image image1, image2;
	unsigned int a,b,c,d;
	for(unsigned int i=0; i<4; i++)
	{
		for(unsigned j=0; j<4; j++)
		{
			if ((memoryBoard[i][j].open)&&(!memoryBoard[i][j].find))
			{
				a=i;
				b=j;
				image1.idImage=memoryBoard[i][j].idImage;
				j=4;
				i=4;
			}
		}
	}
	for(unsigned int i=0; i<4; i++)
	{
		for(unsigned j=0; j<4; j++)
		{
			if ((memoryBoard[i][j].open)&&((a!=i)||(b!=j))&&(!memoryBoard[i][j].find))
			{
				c=i;
				d=j;
				image2.idImage=memoryBoard[i][j].idImage;
				j=4;
				i=4;
			}
		}
	}
	if (image1.idImage!=image2.idImage)
	{
		attempts --;
		memoryBoard[a][b].open=false;
		memoryBoard[c][d].open=false;
	}else
	{
		memoryBoard[a][b].find=true;
		memoryBoard[c][d].find=true;
	}
}

bool Game_Memory::win()
{
	bool win=true;
	for(unsigned int i=0; i<4; i++)
	{
		for (unsigned int j=0; j<4; j++)
		{
			if (!(memoryBoard[i][j].find))
			{
				win=false;
			}
		}
	}
	return win;
}
void Game_Memory::choicePlayer()
{
	unsigned int x,y;
	bool choice=false;
	do{
		cout<<"Quelle image voulez-vous retourner"<<endl;
		cout<<"Ligne :"<<endl;
		cin>>x;
		cout<<"Colonne :"<<endl;
		cin>>y;
		if ((y>4)||(x>4))
		{
			cout<<"Mauvaises coordonn�es. Recommencez"<<endl;
		}
		else if (memoryBoard[x-1][y-1].open)
		{
			cout<<"Cette Image est deja retourn�e, veuillez en choisir une autre"<<endl;
		}
		else
		{
			memoryBoard[x-1][y-1].open=true;
			choice=true;
		}
	}while (!choice);
}


void Game_Memory::play()
{
	initMemory("data/minigame/indexMemory.txt");
	do{
		printBoardMemory();
		choicePlayer();
		printBoardMemory();
		choicePlayer();
		printBoardMemory();
		winTest();
	}while(win()==false);
	cout<<"Vous avez gagné!" << endl;
}