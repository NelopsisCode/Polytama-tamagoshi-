#ifndef TICTACTOE_SDL_H
#define TICTACTOE_SDL_H

#include "../Core/Tictactoe.h"

#include <SDL.h>
#include <SDL_image.h>

#include <SDL_mixer.h> //son
#include <SDL_ttf.h> //police

const unsigned int WIDTH = 10;
const unsigned int LENGTH = 10;


class Image{
    private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

    public:

    Image () ;
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
}


class TictactoeSDL {

private :

	Jeu jeu;

    SDL_Window * window;
    SDL_Renderer * renderer;

/*// à voir 
    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;
//sûr
    Image human;
    Image ai;
    Image grid;

*/

public :

    TictactoeSDL ();
    ~TictactoeSDL ();
    void sdlBoucle ();
    void sdlAff ();

};
#endif