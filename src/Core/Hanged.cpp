#include <iostream>
#include "Hanged.h"

using namespace std;

Game_Hanged::Game_Hanged()
{
    attempts = MAX_ATTEMPTS;
    tropheeHanged = false;
}

Game_Hanged::~Game_Hanged()
{
    word.clear();
}

bool Game_Hanged::getTropheeHanged()
{
    return tropheeHanged;
}

void Game_Hanged::setTropheeHanged(const bool & t)
{
    tropheeHanged = t;
}

unsigned int Game_Hanged::getAttempts()const
{
    return attempts;
}

void Game_Hanged::setAttempts(const unsigned int & a)
{
    attempts = a;
}

unsigned int Game_Hanged::getWordLength()const
{
    return wordLength;
}

char Game_Hanged::getWordLetter(const unsigned int & i)const
{
    return word[i].letter;
}

bool Game_Hanged::getWordFind(const unsigned int & i)const
{
    return word[i].find;
}

void Game_Hanged::setWordFind(const unsigned int & i,const bool & b)
{
    word[i].find = b;
}

void Game_Hanged::loadWord(const string &filename)
{
    ifstream words(("data/" + filename).c_str());

    if (!words.is_open())
    {
        cout << "Problème dans l'ouverture du fichier" << endl;
        exit(EXIT_FAILURE);
    }

    unsigned int nbWords, random;
    string bin,neword;
    words >> nbWords;

    //tirage aléatoire d'un mot
    int min = 0;
    int max = nbWords - 1;
    int range = max - min + 1;
    random = (rand() % range) + min;
    for (unsigned int i = 0; i < random; i++)
    {
        words >> bin;
    }
    words >> neword;

    words.close();

    wordLength = neword.length();

    for (unsigned int i = 0 ; i < wordLength; i++)
    {
        Letter letter;
        letter.letter = neword[i];
        letter.find = false;
        word.push_back(letter);
    }
}

void Game_Hanged::printWord() const
{
    for (unsigned int i = 0; i < wordLength; i++) //remplacer 8 par le nombre de caractère du mot
    {
        if (word[i].find)
        {
            cout << word[i].letter;
        }
        else
        {
            cout << "*";
        }
    }
    cout << endl;
}

char Game_Hanged::getLetter() const
{
    char l;
    cin >> l;
    return l;
}

bool Game_Hanged::win() const
{
   
    for (unsigned int i=0; i  < wordLength; i++)
    {
        if (!word[i].find)
        {
           return false;
        }
    }
    return true;
}

bool Game_Hanged::isInWord(const char & letter)
{
    bool inWord = false;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        if (word[i].letter == letter)
        {
            word[i].find = true;
            inWord = true;
        }
    }
    return inWord;
}

void Game_Hanged::play()
{
    char letter;
    loadWord("indexWords.txt");


    while (attempts > 0 && !win())
    {
        cout << attempts << " coups restants" << endl;
        printWord();

        letter = getLetter();

        if (!isInWord(letter))
        {
            attempts--;
        }
    }

    if (win())
    {
        printWord();
        cout << "gg" <<endl;
        setTropheeHanged(true);
    }
    else
    {
        cout << "Perdu !" << endl;
    }
    
}