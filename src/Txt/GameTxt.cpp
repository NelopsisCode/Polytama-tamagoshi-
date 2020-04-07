#include "GameTxt.h"
#include "ncurses.h"
#include "../Core/Mini_Game.h"

void GameTxtPrintTama(const Polytama & polytama){
    string translate;
	printw("\n");
    attron(A_UNDERLINE | A_BOLD); // mise en forme Gras + souligné
    printw("Prénom : ");
    printw((polytama.getName()).c_str());
	attroff(A_UNDERLINE | A_BOLD);
    printw("\n");
    printw("\n");
    attron(A_NORMAL); // mise en forme normal
    printw("Faim : %d \n",(polytama.getHunger()).getValue());
    printw("\n");
    printw("Soif : %d \n",(polytama.getThirst()).getValue());
    printw("\n");
    printw("Joie : %d \n",(polytama.getJoy()).getValue());
    printw("\n");
    printw("Hygiène : %d \n",(polytama.getHygiene()).getValue());
    printw("\n");
	printw("Tenue du jour : ");
	for(unsigned int i=0; i<3;i++)
	{
		if (polytama.getClothes(i)!=nullptr)
		{
			printw(polytama.getClothes(i)->getNameItem().c_str());
			printw(", ");
		}else 
		{
			printw("rien a cet endroit, ");
		}
	}
	printw("\n");
	printw("\n");

	refresh();
    
 }

 string get_line(){

	string result;
	while(true)
	{
		int c = getch();
		if(c == ERR || c == '\n') return result;
		else result += c; 
	}
 }

 void printTxtInventoryClothes(const InventoryClothes & sweatshirt)
{
	printw("Voici vos vetements et accessoires restants\n");
	vector <Clothes> vectcloth =sweatshirt.getClothesBoard();
	string translate;
	if(sweatshirt.NumberClothes()==0){
		while(1){
			clear();
			refresh();
			printw("\n");
			printw("Vous n'avez rien dans cet inventaire\n");
			refresh();
			noecho();
				if(getch()!=410){
					echo();
					clear();
					refresh();
					break;
				}
		}
	}
	else{
	for (unsigned int i =0; i<vectcloth.size(); i++)
	{
		if (vectcloth[i].getNumberItem()!=0)
		{
			printw((vectcloth[i].getNameItem()).c_str());
			printw(", nombre : %d", vectcloth[i].getNumberItem());
			printw("\n");
			refresh();
		}
	}
	}
}

 void printTxtInventoryConsommable(const InventoryConsommable & conso)
{
	printw("Voici vos consommables restants\n");
	vector <Consommable> vectconso =conso.getConsommableBoard();
	string translate;
	if(conso.NumberConsommable()==0){
		while(1){
			clear();
			refresh();
			printw("\n");
			printw("Vous n'avez rien dans cet inventaire\n");
			refresh();
			noecho();
				if(getch()!=410){
					echo();
					clear();
					refresh();
					break;
				}
		}
	}
	else{
	for (unsigned int i =0; i<vectconso.size(); i++)
	{
		if (vectconso[i].getNumberItem()!=0)
		{
			printw((vectconso[i].getNameItem()).c_str());
			printw(", nombre : %d",vectconso[i].getNumberItem());
			printw("\n");
			refresh();
		}
	}
	}
}


 void GameTxtInit(Polytama & polytama ) {
    clear();
	printw("Bonjour et bienvenue dans Polytama. Ici vous allez vous occuper d'une petite créature appellée un polytama !\n");
	printw("Premièrement, vous devez lui choisir un nom !\n");
	string key;
	string name;
	do{
	printw("Ecrivez son nom :\n");
	refresh();
	name = get_line();
	printw("Voulez-vous que votre polytama porte le nom de ");
	printw(name.c_str());
	printw(" ?\n");
	refresh();
	key = get_line();
	}while(key != "oui");
	polytama.setName(name);
	printw("Super, maintenant il est temps de jouer avec ");
	printw(name.c_str());
	printw(" !\n");
	printw("Appuyez sur une touche pour continuer");
	refresh();
	
	(polytama.getHunger()).setValue(50);
	(polytama.getThirst()).setValue(50);
	(polytama.getJoy()).setValue(50);
	(polytama.getHygiene()).setValue(50);
    while(1){
		if(getch() != 410)
            break;
	}
 }

 void GameTxtLoop(Polytama & polytama) {
    
	 
	 
	 
	InventoryConsommable manger;
	manger.loadIndexConsommable("data/indexConsommable.txt");
	InventoryClothes sweatshirt;
	sweatshirt.loadIndexClothes("data/indexClothes.txt");
	bool out = false;
    char choice=' ';
    while(out != true){

	GameTxtPrintTama(polytama);

    printw("Vous pouvez :\n");
	printw("1 : Faire dabber votre polytama\n");
    printw("2 : Lui donner un bain \n");
	printw("3 : Jouer avec lui \n");
	printw("4 : Lui donner a manger\n");
	printw("5 : L'habiller autrement\n");
	printw("6 : Afficher l'inventaire\n");
	printw("7 : Ne rien faire\n");
    printw("8 : Quitter\n");
	printw("\n");

	refresh();

	noecho();
	
	choice = getch();
	echo();
	switch (choice) {
		case '1' : {
			while(1){
			clear();
			refresh();
			printw("\n");
			polytama.dab();
			noecho();
			if(getch()!=410){
			echo();
			clear();
			refresh();
			break;
			}
			}
		}break;
		case '2' : { 
			while(1){
			clear();
			refresh();
			printw("\n");
			polytama.takeAbath();
			noecho();
			if(getch()!=410){
			echo();
			clear();
			refresh();
			break;
			}
			}
		}break;
		case '3' : {
			//minigame();
			while(1){
			clear();
			refresh();
			printw("\n");
			printw("Voici le morpion !\n");
			refresh();
			noecho(); 
			Mini_Game game;
			TicTacToeTxt tictactoe;
			tictactoe.playTxt();
			game.generateReward();
			if (tictactoe.tropheeTictactoeTxt == true)
			{
				if(game.getReward() < 100)
				{
					Consommable conso=manger.searchIdInInventoryConsommable(game.getReward());
					manger.addInInventoryConsommable(conso);
					printw("Vous avez gagn� ");
					printw (conso.getNameItem().c_str());
					printw(" !\n");
					manger.saveIndexConsommable("data/indexConsommable.txt");
				}
				else
				{
					Clothes clot=sweatshirt.searchIdInInventoryClothes(game.getReward());
					sweatshirt.addInInventoryClothes(clot);
					printw("Vous avez gagn� ");
					printw (clot.getNameItem().c_str());
					printw(" !\n");
					sweatshirt.saveIndexClothes("data/indexClothes.txt");
				}
			}
			if(getch()!=410){
			echo();
			clear();
			refresh();
			break;
			}
			}
		}break;
		case '4' : {
			string mot;
			Consommable conso;
			
			if(manger.NumberConsommable()==0)
			{
				while(1){
					clear();
					printw("\n");
					printw("Vous n'avez rien � faire manger � votre polytama\n");
					printw("Jouez a des mini-jeux pour gagner des la nourriture !\n");
					refresh();
					noecho();
					if(getch()!=410){
						echo();
					clear();
					refresh();
					break;
					}
				}
			}
			else{
				do{
				clear();
				printTxtInventoryConsommable(manger);
				printw("Que voulez-vous lui donner ?\n");
				refresh();
				mot = get_line();
				conso=manger.searchInInventoryConsommable(mot);
			}while (conso.getNumberItem()==0 && mot != "rien");
			if(mot != "rien"){
			manger.deleteFromInventoryConsommable(conso.getIdItem());
			polytama.consume(conso);
			manger.saveIndexConsommable("data/indexConsommable.txt");
			clear();
			refresh();
			noecho();
			}
			else{
				clear();
				refresh();
			}
			}
		}break;
		case '5' : {
			string mot;
			Clothes clot1;
			if(sweatshirt.NumberClothes()==0)
			{
				while(1){
					clear();
					printw("\n");
					printw("Vous n'avez rien a mettre sur votre Polytama\n");
					printw("Jouez a des mini-jeux pour en gagner !\n");
					refresh();
					noecho();
					if(getch()!=410){
						echo();
					clear();
					refresh();
					break;
					}
				}
			}
			else{
			
				do{
				clear();
				printTxtInventoryClothes(sweatshirt);
				printw("Avec quoi voulez-vous l'habiller \n");
				refresh();
				mot = get_line();
				clot1=sweatshirt.searchInInventoryClothes(mot);
			}while (clot1.getNumberItem()==0 && mot !="rien");
			if(mot !="rien"){
			if(polytama.getClothes(clot1.getSlotClothes())!=nullptr)
			{
				Clothes clot2=*polytama.getClothes(clot1.getSlotClothes());//probleme (fabrique un item bidon)
				sweatshirt.addInInventoryClothes(clot2);
			}
			polytama.wearClothes(clot1);
			sweatshirt.deleteFromInventoryClothes(clot1.getIdItem());
			sweatshirt.saveIndexClothes("data/indexClothes.txt");
			}
			refresh();
			clear();
			}
			}break;	
		case '6' :{
			clear();
			if(manger.NumberConsommable()!=0){
			printTxtInventoryConsommable(manger);
			manger.saveIndexConsommable("data/indexConsommable.txt");
			}else{
				printw("Voici vos consommables restants\n");
				printw("Il n'y a rien !\n");
				printw("Jouez a des mini-jeux pour en gagner !\n");
				refresh();
			}
			printw("\n");
			if(sweatshirt.NumberClothes()!=0){
			printTxtInventoryClothes(sweatshirt);
			sweatshirt.saveIndexClothes("data/indexClothes.txt");
			}else{
				printw("Voici vos vetements et accessoires restants\n");
				printw("Il n'y a rien !\n");
				printw("Jouez a des mini-jeux pour en gagner !\n");
				refresh();
			}
			refresh();
			noecho();
			if(getch()!=410){
			echo();
			clear();
			refresh();
			break;
			}
		}break;
        case '7' :{
			while (1)
			{
				clear();
			refresh();
			printw("\n");
            printw((polytama.getName()).c_str());
			printw(" s'ennuie...");
			refresh();
			noecho();
			if(getch()!=410){
			echo();
			clear();
			refresh();
			break;
			}}
		}break;
		case '8' :{
			out = true;
		}break;

		default : {
			clear();
			refresh();
			printw("\n");
			printw("Veuillez choisir une proposition ci-dessous\n");
			refresh();
			break;
		}break;
	}

    }
	polytama.save("save.txt");
}
