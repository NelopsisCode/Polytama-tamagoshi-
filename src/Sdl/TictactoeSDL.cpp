#include "TictactoeSDL.h"

void playSDL(Game_TicTacToe & tictactoe, SDL_Window *&window, SDL_Renderer *&renderer)
{
    printSDLBoardTictactoe(tictactoe, window, renderer);
    SDL_Delay(1500);

    int tour;
    bool fin;
    bool rules = false;
    tour = 0;
    fin = false;

    while (fin == false)
    {
        //On regarde qui est le player en fonction du tour
        if (tour % 2 == 0) //humain
        {
            unsigned int x, y;
            bool isset, choseplay;
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
                            if(!rules)
                            {
                            CreateImage("data/image/minigame/TictactoeRules.png",window,renderer,-80, -50,true);
                            SDL_RenderPresent(renderer);
                            rules = true;
                            }
                            else
                            {
                                printSDLBoardTictactoe(tictactoe,window,renderer);
                                rules = false;
                            }
                            
                        }
                        
                        else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 30 and event.button.y < 190)
                        {
                            x = 1;
                            y = 1;
                            choseplay = false;
                        }
                        else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 30 and event.button.y < 190)
                        {
                            x = 1;
                            y = 2;
                            choseplay = false;
                        }
                        else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 30 and event.button.y < 190)
                        {
                            x = 1;
                            y = 3;
                            choseplay = false;
                        }
                        else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 220 and event.button.y < 380)
                        {
                            x = 2;
                            y = 1;
                            choseplay = false;
                        }
                        else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 220 and event.button.y < 380)
                        {
                            x = 2;
                            y = 2;
                            choseplay = false;
                        }
                        else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 220 and event.button.y < 380)
                        {
                            x = 2;
                            y = 3;
                            choseplay = false;
                        }
                        else if (event.button.x > 230 and event.button.x < 390 and event.button.y > 410 and event.button.y < 570)
                        {
                            x = 3;
                            y = 1;
                            choseplay = false;
                        }
                        else if (event.button.x > 420 and event.button.x < 580 and event.button.y > 410 and event.button.y < 570)
                        {
                            x = 3;
                            y = 2;
                            choseplay = false;
                        }
                        else if (event.button.x > 610 and event.button.x < 770 and event.button.y > 410 and event.button.y < 570)
                        {
                            x = 3;
                            y = 3;
                            choseplay = false;
                        }
                        break;
                    }
                }

                tictactoe.setCase(x, y, HUMAN, isset);
            } while (isset == false);

            fin = tictactoe.gameOver(HUMAN);
        }

        else // IA
        {
            bool isset;
            do
            {
                if (stupidAI())
                {
                    unsigned int xai, yai;
                    int min = 1;
                    int max = 3;
                    int plage = max - min + 1;
                    xai = (rand() % plage) + min;
                    yai = (rand() % plage) + min;
                    tictactoe.setCase(xai, yai, AI, isset);
                }
                else
                {
                    Move AImove = tictactoe.minimax(tictactoe.boardTictactoe);
                    //cout << AImove.x <<endl << AImove.y <<endl;
                    tictactoe.setCase(AImove.x, AImove.y, AI, isset);
                }
            } while (isset == false);

            fin = tictactoe.gameOver(AI);
            SDL_Delay(900);
        }

        printSDLBoardTictactoe(tictactoe, window, renderer);
        tour++;
    }
    if (tictactoe.win(HUMAN))
    {
        tictactoe.setTropheeTictactoe(true);
        CreateImage("data/image/minigame/Winscreen.png",window,renderer,0,0,true);
    }
    else if (tictactoe.win(AI))
    {
        CreateImage("data/image/minigame/Losescreen.png",window,renderer,0,0,true);
    }
    else if (tictactoe.tie())
    {   
        SDL_Color blue {0,0,255};
        CreateText("Egalité...", window,renderer,blue,"data/font/font.ttf",100,0,0,true);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(1500);
}

bool stupidAI()
{
    unsigned int random;
    int min = 1;
    int max = 100;
    int plage = max - min + 1;
    //srand((unsigned int)time(NULL));
    random = (rand() % plage) + min;
    if (random < 52)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void printSDLBoardTictactoe(const Game_TicTacToe & tictactoe, SDL_Window *&window, SDL_Renderer *&renderer)
{
    CreateImage("data/image/minigame/BackgroundTictactoe.png", window, renderer, 0, 0, true);
    CreateImage("data/image/minigame/Help.png", window, renderer, 50, 50, false);
    unsigned int posx, posy;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            switch (j)
            {
            case 0:
                posx = 230;
                break;

            case 1:
                posx = 420;
                break;

            case 2:
                posx = 610;
                break;
            }
            switch (i)
            {
            case 0:
                posy = 30;
                break;

            case 1:
                posy = 220;
                break;

            case 2:
                posy = 410;
                break;
            }

            if (tictactoe.boardTictactoe[i][j] == 'X')
            {
                CreateImage("data/image/minigame/TictactoePlayer.png", window, renderer, posx, posy, false);
            }
            else if (tictactoe.boardTictactoe[i][j] == 'O')
            {
                CreateImage("data/image/minigame/TictactoeAI.png", window, renderer, posx, posy, false);
            }
        }
    }
    SDL_RenderPresent(renderer);
}