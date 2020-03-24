
#include "Inventory.h"
using namespace std;

Inventory::Inventory(){
}

Inventory::Inventory(const vector <Item>& itemBo){
	itemBoard=itemBo;
}

Inventory::~Inventory(){
	itemBoard.clear();
}

void Inventory::setItemBoard(const vector <Item> & itemBo){
	itemBoard=itemBo;
}

vector<Item> Inventory::getItemBoard()const {
	return itemBoard;
}

void Inventory::loadIndexClothes (const string & Index){
	ifstream index;
	index.open(c_str(Index));
	string nameItem;
	unsigned int idItem;
	string mot;
	if (index.is_open()){
		while(!index.eof()){
		index>>idItem>>mot>>nameItem>>mot>>numberItem>>mot>>idClo;
		Clothes clot;
		clot.setNumberItem(numberItem);
		clot.setNameItem(nameItem);
		clot.setIdItem(idItem);
		clot.setIdClothes(idClo);
		itemBoard.push_back(clot);
		}	
	}else{cout<<"Erreur dans l'ouverture de"<<Index<<endl;}
	index.close();
}

void Inventory::loadIndexConsommable (const string & Index){
	ifstream index;
	index.open(c_str(Index));
	string nameItem;
	unsigned int idItem;
	string mot;
	if (index.is_open()){
		while(!index.eof()){
		index>>idItem>>mot>>nameItem>>mot>>numberItem>>mot>>food>>mot>>hydration
				>>mot>>hygiene>>mot>>happiness>>mot;
		Consommable conso;
		conso.setNumberItem(numberItem);
		conso.setNameItem(nameItem);
		conso.setIdItem(idItem);
		conso.setFood(food);
		conso.setHydration(hydration);
		conso.setHygiene(hygiene);
		conso.setHappiness(happiness);
		itemBoard.push_back(conso);
		}	
	}else{cout<<"Erreur dans l'ouverture de"<<Index<<endl;}
	index.close();
}

void Inventory::printInventory()const {
	for (unsigned int i =0; i<itemBoard.size(), i++){
		if (itemBoard[i].numberItem!=0){
			printItem();
		}
	}
}

void Inventory::addInInventory(const Item & it){
	unsigned int i=0;
	size=itemBoard.size();
	while ((i<size)&&(itemBoard[i].getNameItem()!=it.getNameItem())){ 
			i++;
		};
	if (i<size) {
			itemBoard[i].numberItem ++;
	}else{
		it.setNumberItem(it.getNumberItem()+1);
		itemBoard.push_back(it);
	}
}

void Inventory::deleteFromInventory(const Item & it){
	unsigned int i=0;
	size=itemBoard.size();
	while ((i<size)&&(itemBoard[i].getNameItem()!=it.getNameItem())){
			i++;
		}
		if ((i<size)&&(itemBoard[i].numberItem!=0) ){
			itemBoard[i].setNumberItem(ittemBoard[i].getNumberItem()-1);
		}
}


