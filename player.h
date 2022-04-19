#ifndef player_H_INCLUDED
#define player_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct player
{ 
 int nb; // number of the player 
 SDL_Surface *spritesheet;
 SDL_Rect position; // position of the player in the background
 SDL_Rect pos_sprite;
//animation
 int direction;
//movement
 double speed,acceleration; // speed:the speed of the player  // double khater tekhou akther arkam baid el virgule
 int speedV; // speedV : the speed of the jump
// life
 SDL_Surface *image_life[3];
 SDL_Rect position_life;
 int val; 
 SDL_Rect position_text;
// score
  char number[20];//khater baid chenhotha fel surface b sdl_render text eli heya tekhou ken textes
  SDL_Rect position_textt;
  SDL_Rect position_number;
  int value_score;
int up;
}Player;


void initPlayer(Player *p);
void displayPlayer(Player p,SDL_Surface *screen);
void movePlayer(Player *p,int dt);
void animePlayer(Player* p);
void jump(Player* p);


#endif
