#ifndef ENIGME2_H_INCLUDED
#define ENIGME2_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>     
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>

typedef struct{  
	
	SDL_Surface *image;  
	SDL_Rect pos_image;
	
	SDL_Surface *image_clock;  
	SDL_Rect pos_image_clock;
	
	SDL_Rect single_Clock;
	
	SDL_Surface *response1; 
	SDL_Surface *response2; 
	SDL_Surface *response3; 
	SDL_Rect pos_response;
	
	SDL_Surface *correct; 
	SDL_Rect pos_correct;
	
	SDL_Surface *wrong; 
	SDL_Rect pos_wrong;
	
	SDL_Surface *solution; 
	SDL_Rect pos_solution;
	
	int d; 

	int clock_num;
}enigme2;

void InitEnigme(enigme2 *e ,char *filename[]);
void displayEnigme(enigme2 e,SDL_Surface *screen);
void correct(SDL_Surface *screen,enigme2 *e);
void wrong(SDL_Surface *screen,enigme2 *e);
void generate(enigme2 *e);
void displayClock(enigme2 e,SDL_Surface *screen);
void animateEnigme(enigme2 *e);
int enigmef(SDL_Surface *screen);









void resolution(SDL_Surface *screen,enigme2 *e);
#endif  

