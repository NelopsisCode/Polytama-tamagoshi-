#include "HangedSDL.h"

void playHangedSDL(Game_Hanged &hanged, SDL_Window *&window, SDL_Renderer *&renderer)
{
    char letter;
    hanged.loadWord("minigame/indexWords.txt");

    while (hanged.getAttempts() > 0 && !hanged.win())
    {
        printSDLWord(hanged, window, renderer);

        letter = getSDLletter(hanged, window, renderer);

        if (!hanged.isInWord(letter))
        {
            hanged.setAttempts(hanged.getAttempts() - 1);
        }
    }

    if (hanged.win())
    {
        printSDLWord(hanged, window, renderer);
        CreateImage("data/image/minigame/Winscreen.png", window, renderer, 0, 0, true);
        hanged.setTropheeHanged(true);
    }
    else
    {
        string toPrint;
        for (unsigned int i = 0; i < hanged.getWordLength(); i++)
        {
            toPrint += hanged.getWordLetter(i);
        }
        SDL_Color black = {0, 0, 0};
        CreateImage("data/image/minigame/HangedBackground_0.png", window, renderer, 0, 0, true);
        CreateText(toPrint, window, renderer, black, "data/font/font.ttf", 70, 0, 250, true);
        CreateImage("data/image/minigame/Losescreen.png", window, renderer, 0, 0, true);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(1500);
}

void printSDLWord(const Game_Hanged &hanged, SDL_Window *&window, SDL_Renderer *&renderer)
{
    string toPrint;

    for (unsigned int i = 0; i < hanged.getWordLength(); i++)
    {
        if (hanged.getWordFind(i))
        {
            toPrint += hanged.getWordLetter(i);
        }
        else
        {
            toPrint += "_";
        }
        toPrint += " ";
    }

    SDL_Color black = {0, 0, 0};
    string hang = "data/image/minigame/HangedBackground_" + to_string(hanged.getAttempts()) + ".png";
    CreateImage(hang, window, renderer, 0, 0, true);
    CreateImage("data/image/minigame/Help.png", window, renderer, 50, 50, false);
    CreateText(toPrint, window, renderer, black, "data/font/font.ttf", 70, 0, 250, true);
    SDL_RenderPresent(renderer);
}

char getSDLletter(const Game_Hanged &hanged, SDL_Window *&window, SDL_Renderer *&renderer)
{
    char l;

    SDL_Event event;
    bool choseLetter = true;
    bool rules = false;

    while (choseLetter)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_TEXTINPUT:
        {
            l = *(event.text.text);
            int ascii = (int)l;

            // si la lettre saisie est minuscule on la met en majuscule
            if (ascii >= 97 and ascii <= 122)
            {
                l = (char)(ascii - 32);
                choseLetter = false;
            }
            //si l'utilisateur n'a pas saisi une lettre on attend une autre saise
            else if (ascii < 65 || (ascii >= 91 and ascii <= 96) || ascii > 122)
            {
                choseLetter = true;
            }
            else
            {
                choseLetter = false;
            }
        }
        break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.x > 50 and event.button.x < 150 and event.button.y > 50 and event.button.y < 150)
            {
                if (!rules)
                {
                    CreateImage("data/image/minigame/HangedRules.png", window, renderer, -80, -50, true);
                    SDL_RenderPresent(renderer);
                    rules = true;
                }
                else
                {
                    printSDLWord(hanged, window, renderer);
                    rules = false;
                }
            }
            break;

                default : 
                break;
        }
    }

    return l;
}