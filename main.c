
#include "header.h"
#include <stdbool.h>

int main(int argc,char* args[] )
{
int done=1;


 TTF_Init();
SDL_Init(SDL_INIT_EVERYTHING); // to initialize everything at once
///declaration of variables
Uint32 start;
const int fps=30;
SDL_Surface *screen=NULL;
SDL_Surface *background=NULL;
SDL_Surface *background2 = NULL;
SDL_Surface *button1=NULL;
SDL_Surface *button2=NULL;
SDL_Surface *button3=NULL;
SDL_Surface *button11=NULL;
SDL_Surface *button22=NULL;
SDL_Surface *button33=NULL;
SDL_Rect positionbackground;
SDL_Rect positionbutton1;
SDL_Rect positionbutton2;
SDL_Rect positionbutton3;
SDL_WM_SetCaption("menu",NULL);
SDL_Event event;

screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
background=IMG_Load("background1.jpg");

background2= IMG_Load("background2.jpg");
positionbackground.x=0;
positionbackground.y=0;

button1=IMG_Load("button1.png");
positionbutton1.x=750;
positionbutton1.y=150;

button2=IMG_Load("button2.png");
positionbutton2.x=750;
positionbutton2.y=350;

button3=IMG_Load("button3.png");
positionbutton3.x=750;
positionbutton3.y=550;

button11=IMG_Load("button11.png");
button22=IMG_Load("button22.png");
button33=IMG_Load("button33.png");

  ///////////////////////////// music and brief sound

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    Mix_Music *music;
    music = Mix_LoadMUS("background sound.mp3");
    Mix_PlayMusic(music, -1);
    Mix_Chunk *gta;
    gta = Mix_LoadWAV("brief_sound.wav");

    /////////////////////////////

 Text t;
 initText(&t);

///game loop
bool state=false;
while(done) //done deja 1 medem done=done ye5dem programme
{ 
  int r=1;
while(r==1)
{
if(state){
SDL_BlitSurface(background2, NULL, screen, &positionbackground);
}
else
{
SDL_BlitSurface(background,NULL,screen,&positionbackground);
displayText(t, screen);
}
state=!state;

SDL_BlitSurface(button1,NULL,screen,&positionbutton1);
SDL_BlitSurface(button2,NULL,screen,&positionbutton2);
SDL_BlitSurface(button3,NULL,screen,&positionbutton3);



SDL_PollEvent(&event);
r=2;
switch(event.type)
{
           case SDL_QUIT: // hia el (x)
            done=0;
               break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done = 0;
                     r=1;
                
                    break;
                case SDLK_g:
                    Mix_PlayChannel(-1, gta,0);
                    NewGame(screen);
                    break;
                case SDLK_s:
                    Mix_PlayChannel(-1, gta,0);
                    Settings(screen);
                    break;
                }
                break;
       ///Mouse motion

            case SDL_MOUSEMOTION:
                if (event.motion.x > 750 && event.motion.x < 1050 && event.motion.y > 150 && event.motion.y < 262)
                {
                    Mix_PlayChannel(-1, gta, 0);
                    SDL_BlitSurface(button11, NULL, screen, &positionbutton1);
                    //SDL_Flip(screen);
                }
                else if (event.motion.x > 750 && event.motion.x < 1050 && event.motion.y > 350 && event.motion.y < 462)
                {
                    Mix_PlayChannel(-1, gta, 0);
                    SDL_BlitSurface(button22, NULL, screen, &positionbutton2);
                    //SDL_Flip(screen);
                }
                else if (event.motion.x > 750 && event.motion.x < 1050 && event.motion.y > 550 && event.motion.y < 662)
                {
                    Mix_PlayChannel(-1, gta, 0);
                    SDL_BlitSurface(button33, NULL, screen, &positionbutton3);
                    //SDL_Flip(screen);
                }
                break;
      
      ///Mouse click
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (event.button.x > 750 && event.button.x < 1050 && event.button.y > 150 && event.button.y < 262)
                    {
                        NewGame(screen);
                    }
                    else if (event.button.x > 750 && event.button.x < 1050 && event.button.y > 350 && event.button.y < 462)
                    {
                      Settings(screen);
                   
                    }
                    else if (event.button.x > 750 && event.button.x < 1050 && event.button.y > 550 && event.button.y < 662)
                    {
                       
                     done = 0;
                        break;
                    }
                }
                break;
            }
          
    //SDL_Flip(screen);
    if(1000/fps>SDL_GetTicks()-start)
    {
    SDL_Delay( 1000/fps-(SDL_GetTicks()-start) );
    }
SDL_Flip(screen);
}

}
SDL_FreeSurface(background);
SDL_FreeSurface(button1);
SDL_FreeSurface(button3);
SDL_FreeSurface(button11);
SDL_FreeSurface(button22);
SDL_FreeSurface(button33);
    Mix_FreeMusic(music);
    Mix_FreeChunk(gta);
    Mix_CloseAudio();
    freeText(t);
    TTF_CloseFont(t.font);
    Mix_Quit();
SDL_Quit();
return 0;
}
