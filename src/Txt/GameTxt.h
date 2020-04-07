#ifndef GAMETXT_H
#define GAMETXT_H
#include <string>
#include "../Core/Polytama.h"
#include "TictactoeTxt.h"
using namespace std;

void printTxtInventoryClothes(const InventoryClothes & sweatshirt);
void printTxtInventoryConsommable(const InventoryConsommable & conso);
void GameTxtPrintTama(const Polytama & polytama);
string get_line();

void GameTxtInit(Polytama & polytama);
void GameTxtLoop(Polytama & polytama);

#endif /* GAMETXT_H */