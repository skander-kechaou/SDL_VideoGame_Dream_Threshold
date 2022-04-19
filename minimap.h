#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

typedef struct minimap{
	SDL_Surface *mini_map;
	SDL_Rect posminimap;
	SDL_Surface *point;
	SDL_Rect pospoint;
}minimap;
typedef struct Time{
	SDL_Surface *msg;
	TTF_Font *font;
        SDL_Rect positiontemps;
	int time;
	char timeString[10];
}Time;


void initminimap(minimap *m);
void MAJminimap(SDL_Rect p, minimap *m, int resize);
void displayminimap(minimap m, SDL_Surface * screen);
void freeminimap(minimap *m);
void initializerTime(Time *time);
void afficherTime(Time *time, SDL_Surface *screen);

