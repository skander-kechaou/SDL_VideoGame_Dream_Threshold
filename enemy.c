#include <stdbool.h>
#include "enemy.h"
#define POSMIN 0
#define POSMAX 1000

SDL_Rect initSDL_Rect(int x, int y, int w, int h)
{
    SDL_Rect R;
    R.x = x;
    R.y = y;
    R.w = w;
    R.h = h;
    return R;
}

void initEnemy(Enemy *e)
{

    e->spriteSheet = IMG_Load("SpriteSheet.png");
    e->direction = 0; // 0 facing right | 1 facing left
    e->posScreen = initSDL_Rect(500,450, 108, 100);
    e->posSprite = initSDL_Rect(0, 0, 108, 100);
}

void afficherEnemy(Enemy *e, SDL_Surface *screen)
{
    if (e->posScreen.x > 0 && e->posScreen.x < screen->w)
    {
        SDL_BlitSurface(e->spriteSheet, &e->posSprite, screen, &e->posScreen);
    }
}

void animerEnemy(Enemy *e)
{
    e->posSprite.y = e->direction * 108;
    // look back if the sprite sheet edge is reached
    e->posSprite.x = (e->posSprite.x == 300) ? 0 : e->posSprite.x + 100;
    SDL_Delay(10);
}

void move(Enemy *e)
{
    // Should turn if movement will overflow
    if (e->posScreen.x + 10 > POSMAX || e->posScreen.x - 10 < POSMIN)
    {
        e->direction = 1 - e->direction;
    }
    e->posScreen.x = (e->direction == 0) ? e->posScreen.x + 10 : e->posScreen.x - 10;
}
     //still working on it
int collisionBB(SDL_Rect posp, SDL_Rect pos)
{
    int flag = 1;
    if ((abs(pos.x - posp.x) <= ((pos.w + posp.w) / 2)) && (abs(pos.y - posp.y) <= ((pos.h + posp.h) / 2)))
    {
        flag = 0;
    }
    return flag;
}
     //integration because i need the player(still working on it)
void moveIA(Enemy *e, SDL_Rect posPlayer)
{
    // player in aggro range and to the left of the enemy
    if (((e->posScreen.x - posPlayer.x) < 200) && ((e->posScreen.x - posPlayer.x) > 100))
    {
        e->direction = 1;
        e->posScreen.x -= 10;
    }
    // player in aggro range and to the right of the enemy
    else if (((e->posScreen.x - posPlayer.x) > -200) && ((e->posScreen.x - posPlayer.x) < -100))
    {
        e->direction = 0;
        e->posScreen.x += 10;
    }
    // player out of aggro range
    else
    {
        move(e);
    }
}
