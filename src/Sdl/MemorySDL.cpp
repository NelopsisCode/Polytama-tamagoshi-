#include "MemorySDL.h"

void playMemorySDL(Game_Memory &memo, SDL_Window *&window, SDL_Renderer *&renderer)
{
    memo.initMemory("data/minigame/indexMemory.txt");
    do
    {
        printSDLMemory(memo, window, renderer);
        choiceSDL(memo,window,renderer);
        printSDLMemory(memo, window, renderer);
        choiceSDL(memo,window,renderer);
        printSDLMemory(memo, window, renderer);
        SDL_Delay(500);
        memo.winTest();
    } while (memo.win() == false and memo.getAttempts() > 0);
    if(memo.win())
    {
        memo.setTropheeMemory(true);
        CreateImage("data/image/minigame/Winscreen.png",window,renderer,0,0,true);
    }
    else
    {
        CreateImage("data/image/minigame/Losescreen.png",window,renderer,0,0,true);
    }
    
    SDL_RenderPresent(renderer);
    SDL_Delay(1500);
}

void choiceSDL(Game_Memory &memo, SDL_Window *&window, SDL_Renderer *&renderer)
{
    unsigned int x,y;
    bool isset, choseplay,rules;
    rules = false;
    choseplay = true;

    do
    {
        choseplay = true;
        SDL_Event event;
        while (choseplay)
        {
            SDL_WaitEvent(&event);

            switch (event.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.x > 50 and event.button.x < 150 and event.button.y > 50 and event.button.y < 150)
                {
                        if (!rules)
                        {
                            CreateImage("data/image/minigame/MemoryRules.png", window, renderer, -80, -50, true);
                            SDL_RenderPresent(renderer);
                            rules = true;
                        }
                        else
                        {
                            printSDLMemory(memo,window,renderer);
                            rules = false;
                        }
                }
                else if (event.button.x > 240 and event.button.x < 340 and event.button.y > 40 and event.button.y < 140)
                {
                    x = 1;
                    y = 1;
                    choseplay = false;
                }
                else if (event.button.x > 380 and event.button.x < 480 and event.button.y > 40 and event.button.y < 140)
                {
                    x = 1;
                    y = 2;
                    choseplay = false;
                }
                else if (event.button.x > 520 and event.button.x < 620 and event.button.y > 40 and event.button.y < 140)
                {
                    x = 1;
                    y = 3;
                    choseplay = false;
                }
                else if (event.button.x > 660 and event.button.x < 760 and event.button.y > 40 and event.button.y < 140)
                {
                    x = 1;
                    y = 4;
                    choseplay = false;
                }
                else if (event.button.x > 240 and event.button.x < 340 and event.button.y > 180 and event.button.y < 280)
                {
                    x = 2;
                    y = 1;
                    choseplay = false;
                }
                else if (event.button.x > 380 and event.button.x < 480 and event.button.y > 180 and event.button.y < 280)
                {
                    x = 2;
                    y = 2;
                    choseplay = false;
                }
                else if (event.button.x > 520 and event.button.x < 620 and event.button.y > 180 and event.button.y < 280)
                {
                    x = 2;
                    y = 3;
                    choseplay = false;
                }
                else if (event.button.x > 660 and event.button.x < 760 and event.button.y > 180 and event.button.y < 280)
                {
                    x = 2;
                    y = 4;
                    choseplay = false;
                }
                else if (event.button.x > 240 and event.button.x < 340 and event.button.y > 320 and event.button.y < 420)
                {
                    x = 3;
                    y = 1;
                    choseplay = false;
                }
                else if (event.button.x > 380 and event.button.x < 480 and event.button.y > 320 and event.button.y < 420)
                {
                    x = 3;
                    y = 2;
                    choseplay = false;
                }
                else if (event.button.x > 520 and event.button.x < 620 and event.button.y > 320 and event.button.y < 420)
                {
                    x = 3;
                    y = 3;
                    choseplay = false;
                }
                else if (event.button.x > 660 and event.button.x < 760 and event.button.y > 320 and event.button.y < 420)
                {
                    x = 3;
                    y = 4;
                    choseplay = false;
                }
                else if (event.button.x > 240 and event.button.x < 340 and event.button.y > 460 and event.button.y < 560)
                {
                    x = 4;
                    y = 1;
                    choseplay = false;
                }
                else if (event.button.x > 380 and event.button.x < 480 and event.button.y > 460 and event.button.y < 560)
                {
                    x = 4;
                    y = 2;
                    choseplay = false;
                }
                else if (event.button.x > 520 and event.button.x < 620 and event.button.y > 460 and event.button.y < 560)
                {
                    x = 4;
                    y = 3;
                    choseplay = false;
                }
                else if (event.button.x > 660 and event.button.x < 760 and event.button.y > 460 and event.button.y < 560)
                {
                    x = 4;
                    y = 4;
                    choseplay = false;
                }
                break;
            }
        }

        if ((y>4)||(x>4))
		{
			isset=false;
		}
		else if (memo.getOpen(x-1,y-1))
		{
			isset=false;
		}
		else
		{
			memo.setOpen(true,x-1,y-1);
			isset=true;
		}
        
    } while (isset == false);
}

void printSDLMemory(Game_Memory &memo, SDL_Window *&window, SDL_Renderer *&renderer)
{
    CreateImage("data/image/minigame/MemoryBackground.png", window, renderer, 0, 0, true);
    CreateImage("data/image/minigame/Help.png", window, renderer, 50, 50, false);
    SDL_Color black = {0,0,0};
    CreateText(to_string(memo.getAttempts()),window,renderer,black,"data/font/font.ttf",60,-300,0,true);
    if (memo.getAttempts() > 15)
    {
        CreateImage("data/image/tama/Tamaheadj.png", window, renderer,-300, 100, true);
    }
    else if (memo.getAttempts() > 8 and memo.getAttempts() <= 15)
    {
        CreateImage("data/image/tama/Tamaheadn.png", window, renderer,-300, 100, true);
    }
    else
    {
        CreateImage("data/image/tama/Tamaheads.png", window, renderer,-300, 100, true);
    }
    
    unsigned int posx, posy;
    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            switch (j)
            {
            case 0:
                posx = 240;
                break;

            case 1:
                posx = 380;
                break;

            case 2:
                posx = 520;
                break;

            case 3:
                posx = 660;
                break;
            }
            switch (i)
            {
            case 0:
                posy = 40;
                break;

            case 1:
                posy = 180;
                break;

            case 2:
                posy = 320;
                break;

            case 3:
                posy = 460;
                break;
            }

            if (memo.getOpen(i, j))
            {
                string file = "data/image/minigame/Card" + memo.getFilename(i, j) + ".png";
                CreateImage(file, window, renderer, posx, posy, false);
            }
            else
            {
                CreateImage("data/image/minigame/CardRoboto.png", window, renderer, posx, posy, false);
            }
        }
    }
    SDL_RenderPresent(renderer);
}