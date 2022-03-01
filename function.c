#include "header.h"
#include <stdbool.h>



void initText(Text *t)
{
    t->position.x = 730;
    t->position.y = 20;
    t->textColor.r = 218;
    t->textColor.g = 165;
    t->textColor.b = 32;
    t->font = TTF_OpenFont("pol.ttf", 70);
}
void freeText(Text A)
{
    SDL_FreeSurface(A.surfaceText);
}
void displayText(Text t, SDL_Surface *screen)
{
    t.surfaceText = TTF_RenderText_Solid(t.font, "WELCOME", t.textColor); //specify the text,pos and color 
    SDL_BlitSurface(t.surfaceText, NULL, screen, &t.position); //display
}
void NewGame(SDL_Surface *screen)
{
    SDL_Surface *NGame = NULL;

    SDL_Rect positionNGame;

    SDL_Event event;

    int done = 1;
    Text t;
   TTF_Init();

    NGame = IMG_Load("NewGame.jpg");
    // screen = SDL_SetVideoMode(1000, 666, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    // SDL_WM_SetCaption("Game Menu", NULL);

    positionNGame.x = 0;
    positionNGame.y = 0;
    while (done)
    {
      
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            done = 0;
        
            screen = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
            SDL_WM_SetCaption("Game Menu", NULL);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done = 0;
                screen = SDL_SetVideoMode(1366,768, 32, SDL_HWSURFACE );
                SDL_WM_SetCaption("Game Menu", NULL);
                break;
            }
            break;
        }
        SDL_BlitSurface(NGame, NULL, screen, &positionNGame);
        SDL_Flip(screen);
    }

}

///volume

/*void save_volume(int volume)
{
    FILE *file = NULL;
    file = fopen("volume.txt", "w");
    fprintf(file, "%d", volume);
    fclose(file);
}

int get_volume()
{
    int volume;
    FILE *file = NULL;
    file = fopen("volume.txt", "r");
    while (!feof(file))
        fscanf(file, "%d", &volume);
    fclose(file);
    return volume;
}*/

void volumee(int *done,SDL_Surface *screen)
{
int n=1,volume=128;

SDL_Event event;
while (done)
{
SDL_PollEvent(&event);
switch(event.type)
    {
	case SDL_KEYDOWN:

	    switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
    		done=0 ;
               
		
    			break ;
		case SDLK_UP :
		    volume = volume + 2 ;
			break ;
		case SDLK_DOWN :
		    volume = volume - 2 ;
			break ;
		case SDLK_KP_PLUS :
		    volume = volume + 2 ;
			break ;
		case SDLK_KP_MINUS :
		    volume = volume - 2 ;
			break ;
		case SDLK_p :
		    switch(n)
			{
			case 1:
			Mix_PauseMusic();
			n=2;
				break ;
			case 2:
			Mix_ResumeMusic();
			n=1 ;
				break ;
			}
		}
		break ;
	}
Mix_VolumeMusic(volume);
}
}	

void Settings(SDL_Surface *screen)

{  
TTF_Init();
SDL_Init(SDL_INIT_EVERYTHING);
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
Text t;
 initText(&t);



    SDL_Surface *Setting = NULL;
    SDL_Surface *NGame=NULL;
    SDL_Surface *fullscreen1= NULL;
    SDL_Surface *fullscreen2= NULL;
    SDL_Surface *fullscreenoff= NULL;
    
    SDL_Surface *volume1= NULL;
    SDL_Surface *volume2= NULL;
    SDL_Surface *goback1= NULL;
    SDL_Surface *goback2= NULL;
   
   

    SDL_Rect positionSetting;
    SDL_Rect positionfullscreen1;
    SDL_Rect positionfullscreenoff;
    SDL_Rect positionvolume1;
    SDL_Rect positiongoback1;
    SDL_Rect positionNGame;
    positionNGame.x = 0;
    positionNGame.y = 0;

    SDL_Event event;

    int done = 1;
    int FS = 1;
    int k=3;
    
    int volume;
    
    Setting = IMG_Load("settings.jpg");
    screen = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    SDL_WM_SetCaption("Game Menu", NULL);

    positionSetting.x = 0;
    positionSetting.y = 0;


fullscreen1=IMG_Load("fullscreen1.png");
positionfullscreen1.x=500;
positionfullscreen1.y=150;

volume1=IMG_Load("volume1.png");
positionvolume1.x=500;
positionvolume1.y=350;

goback1=IMG_Load("goback1.png");
positiongoback1.x=500;
positiongoback1.y=550;

fullscreen2=IMG_Load("fullscreen2.png");
volume2=IMG_Load("volume2.png");
goback2=IMG_Load("goback2.png");

Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    Mix_Music *music;
    music = Mix_LoadMUS("background sound.mp3");
    Mix_PlayMusic(music, -1);
    Mix_Chunk *gta;
    gta = Mix_LoadWAV("brief_sound.wav");

    while (done)
    { 
int s=1;
while(s==1)
{       SDL_BlitSurface(Setting, NULL, screen, &positionSetting);
        SDL_BlitSurface(fullscreen1,NULL,screen,&positionfullscreen1);
        SDL_BlitSurface(volume1,NULL,screen,&positionvolume1);
        SDL_BlitSurface(goback1,NULL,screen,&positiongoback1);
       SDL_Flip(screen);
      
    ////event handeling
        SDL_PollEvent(&event);
       
        switch (event.type)
        {
        case SDL_QUIT:
            done = 0;
            screen = SDL_SetVideoMode(1366,768, 32, SDL_HWSURFACE );
                SDL_WM_SetCaption("Settings", NULL);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done = 0;
                screen = SDL_SetVideoMode(1366,768, 32, SDL_HWSURFACE );
                SDL_WM_SetCaption("Settings", NULL);
                
                break;
            ///keyboadr click f/v
                case SDLK_f:
                    Mix_PlayChannel(-1, gta,0);
                    if(FS==1)
			{
			screen = SDL_SetVideoMode(800, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN );
			FS=2;
			}
			if(FS==2)
			{
			screen = SDL_SetVideoMode(800, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
			FS=1;
			}
			done = 0;

                  break;
                 /* case 1:
                    FS = 0;
                     screen = SDL_SetVideoMode( 600, 400, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
/*
                     fullscreenoff=IMG_Load("fullscreenoff.png");
                    positionfullscreenoff.x=600;
                    positionfullscreenoff.y=400;
                    SDL_BlitSurface(fullscreenoff,NULL,screen,&positionfullscreenoff);
                    SDL_Flip(fullscreenoff);*/
  
                  //break;
                  //default:
                  //break;
                
                   // break;
                case SDLK_v:
                    Mix_PlayChannel(-1, gta,0);
                    /*if(event.key.keysym.sym == SDLK_RIGHT)
           
                       {  if (volume <= 66 )
	                    { k++;

	                        volume += 33;
	                       Mix_VolumeMusic(volume);
	                        save_volume(volume);
	                    }
                         }
                      
                         if(event.key.keysym.sym == SDLK_LEFT)
                        {  if (volume >= 33 )
                
                           { k--;
                    
                                 volume -= 33;
                            Mix_VolumeMusic(volume);
                              save_volume(volume);
                           }
                         }*/
                     
                       volumee(&done,screen);
                    break;
            }
            break;
            ///mouse motion
              case SDL_MOUSEMOTION:
                if (event.motion.x > 500 && event.motion.x < 800 && event.motion.y > 150 && event.motion.y < 262)
                {
                    Mix_PlayChannel(-1, gta, 0);
                    SDL_BlitSurface(fullscreen2, NULL, screen, &positionfullscreen1);
                    SDL_Flip(screen);
                }
                else if (event.motion.x > 500 && event.motion.x < 800 && event.motion.y > 350 && event.motion.y < 462)
                {
                    Mix_PlayChannel(-1, gta, 0);
                    SDL_BlitSurface(volume2, NULL, screen, &positionvolume1);
                    SDL_Flip(screen);
                }
                else if (event.motion.x > 500 && event.motion.x < 800 && event.motion.y > 550 && event.motion.y < 662)
                {
                    Mix_PlayChannel(-1, gta, 0);
                    SDL_BlitSurface(goback2, NULL, screen, &positiongoback1);
                    SDL_Flip(screen);
                }
                break;
      
      ///Mouse click
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (event.button.x > 500 && event.button.x < 800 && event.button.y > 150 && event.button.y < 262)
                    { Mix_PlayChannel(-1, gta , 0);
                
                    if(FS==1)
			{
			screen = SDL_SetVideoMode(800, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN );
			FS=2;
			}
			if(FS==2)
			{
			screen = SDL_SetVideoMode(800, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
			FS=1;
			}
			done = 0;
                      }
                                   
                 
                    else if (event.button.x > 500 && event.button.x < 800 && event.button.y > 350 && event.button.y < 462)
                    { Mix_PlayChannel(-1, gta , 0);
                      /* if(event.key.keysym.sym == SDLK_RIGHT)
           
                       {  if (volume <= 99 )
	                    { k++;

	                        volume += 33;
	                       Mix_VolumeMusic(volume);
	                        save_volume(volume);
	                    }
                         }
                      }
                         if(event.key.keysym.sym == SDLK_LEFT)
                        {  if (volume >= 0 )
                
                           { k--;
                    
                                 volume -= 33;
                            Mix_VolumeMusic(volume);
                              save_volume(volume);
                           }
                         }*/
                    //volumee(&done,screen);
int z=128;
                 SDL_PollEvent(&event);
			switch(event.type)
			    {
				case SDL_QUIT:
				     
				    done = 0 ;
                               screen = SDL_SetVideoMode(1366,768, 32, SDL_HWSURFACE );
                SDL_WM_SetCaption("Game Menu", NULL);
			  		break;

				case SDL_KEYDOWN:

				    switch (event.key.keysym.sym)
				    {
					case SDLK_ESCAPE:
					    done=0 ;
                            screen = SDL_SetVideoMode(1366,768, 32, SDL_HWSURFACE );
                SDL_WM_SetCaption("Game Menu", NULL);
					    	break ;
					case SDLK_UP :
					    z = z + 2 ;
						break ;
					case SDLK_DOWN :
					    z = z - 2 ;
						break ;
					case SDLK_KP_PLUS :
					    z = z + 2 ;
						break ;
					case SDLK_KP_MINUS :
					    z = z - 2 ;
						break ;
                                        }
                                }
                     }
   
                    else if (event.button.x > 500 && event.button.x < 800 && event.button.y > 550 && event.button.y < 662)
                    {
                       //screen = SDL_SetVideoMode(1366,768, 32, SDL_HWSURFACE );
                
                    // SDL_FreeSurface(Setting);
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
}
}
                     
                     
                    
                  SDL_Flip(screen);      
                    
                }
                break;
}
            }
   SDL_Flip(screen);
}
}
}

         
        
SDL_FreeSurface(Setting);
SDL_FreeSurface(fullscreen1);
SDL_FreeSurface(fullscreen2);
SDL_FreeSurface(fullscreenoff);
SDL_FreeSurface(volume1);
SDL_FreeSurface(volume2);
SDL_FreeSurface(goback1);
SDL_FreeSurface(goback2);
Mix_FreeMusic(music);
    Mix_FreeChunk(gta);
    Mix_CloseAudio();
}


