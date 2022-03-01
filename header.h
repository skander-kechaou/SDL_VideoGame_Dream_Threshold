#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1366
#define SCREEN_H 768
typedef struct
{
    SDL_Rect position;
    TTF_Font *font;
    SDL_Surface *surfaceText;
    SDL_Color textColor;
    char text[50];
} Text;

void NewGame(SDL_Surface *screen);
void Settings(SDL_Surface *screen);
void initText(Text *t);
void freeText(Text A);
void displayText(Text t, SDL_Surface *screen);

#endif




