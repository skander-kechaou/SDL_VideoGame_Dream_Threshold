#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include <time.h>
#include <unistd.h>

void initminimap(minimap *m)
{
	m->mini_map=NULL;
	m->point=NULL;
	m->point=SDL_LoadBMP("minidet.bmp");
	m->mini_map=IMG_Load("miniback.png");
}
void MAJminimap(SDL_Rect p, minimap *m, int resize)
{
	
	m->pospoint.x=(p.x)*0.2;
	m->pospoint.y=(p.y)*0.2;
	SDL_SetColorKey(m->point,SDL_SRCCOLORKEY,SDL_MapRGB((m->point)->format,255,255,255));
}
void displayminimap(minimap m, SDL_Surface * screen)
{
	SDL_BlitSurface(m.mini_map,NULL,screen,0);
	SDL_BlitSurface(m.point,NULL,screen,&m.pospoint);
}
void freeminimap(minimap *m)
{
	SDL_FreeSurface(m->mini_map);
	SDL_FreeSurface(m->point);
}
void initializerTime(Time *time)
{
	time->font = TTF_OpenFont("outils/avocado.ttf", 100);
	time->time = 0;
	sprintf(time->timeString,"00:00");
	SDL_Color color = {255,255,255};
	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
        time->positiontemps.x=100;
        time->positiontemps.y=300;
}

void afficherTime(Time *time, SDL_Surface *screen)
{
	SDL_Color color = {0,255,255};
	time->time++;
	if(time->time % 60 == 0){
		sprintf(time->timeString,"%02d:%02d\n",time->time/60/60,(time->time/60)%60);
		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
	}
	SDL_BlitSurface(time->msg,NULL,screen,&time->positiontemps);
}

