#ifndef ENIGME_H
#define ENIGME_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
 SDL_Surface * img; /*!< Surface. */ 
 SDL_Rect p; /*!< rectangle. */ 
}enigme;

void init_enigme(enigme * e) ;
void  display (SDL_Surface * screen, char image [],enigme *e,int *alea) ;
int resolution1 (int * running,int *run );
void solution_e1 (char image [],int *x);
void display_result(SDL_Surface * screen,int r,enigme *en,int x);
void animate(enigme * e);
int enigme_version_f(SDL_Surface * screen);

#endif
