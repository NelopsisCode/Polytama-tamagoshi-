#ifndef SNAKE_H
#define SNAKE_H

/**
 * @struct <Snake>
 * @brief Un Snake est un serpent 
 * @param x Coordonnee en abscisse du serpent
 * @param y Coordonnee en ordonnee du serpent
 * @param length Taille du serpent
 * @param is_dead true Si le serpent est mort
 */
struct Snake
{
	int x;
	int y;
	int length;
	bool is_dead;

}

/**
 * @class <Game_Snake>
 * @brief Un Game_Snake est un mini-jeu inspire du snake classique
 */
class Game_Snake
{

private:
	

};

#endif