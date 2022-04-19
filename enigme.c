
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <math.h>
#include <time.h> 

void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;


}

 void display (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	
 *alea =  rand()%3 +1;
 sprintf(image ,"%d.jpg",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p));
  SDL_Flip(screen) ;
}

 void solution_e1 (char image [],int *x)
 {      
 	
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
       *x=2;
     
  }
 	if(strcmp(image,"2.jpg")==0)
 	{
       *x=1;
     
  }	

	if(strcmp(image,"3.jpg")==0)
 	{
       *x=2;
     
  }
 	

 }


int resolution1 (int * running,int *run )
{
	SDL_Event event ;
 int r=-1;
               SDL_WaitEvent(&event);
							    if( event.type == SDL_QUIT)
                 {
                * running= 0 ;
                *run = 0;
								 }
							    if( event.type == SDL_KEYDOWN )
                 {

            if( ( event.key.keysym.unicode >= ((Uint16)48) ) && ( event.key.keysym.unicode <= ((Uint16)57)	 ) )
            { 
							r=event.key.keysym.unicode-48  ;
							
						} 
								 }	
return r;

                 
	} 



 void 	display_result (SDL_Surface * screen,int r,enigme *en,int x)
 {
  FILE *f ;  
f=fopen("enigme_file","a") ;	 
 	if (r==x)
 	{
 		en->img=IMG_Load("10.png");
 fprintf(f,"*correct answer* \n the answer is %d \n",r) ;				 
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
fprintf(f,"*wrong answer*: \n the answer is %d\n",r) ; 
 		en->img=IMG_Load("01.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
	 fclose(f);
 }


int enigme_version_f(SDL_Surface *screen)
{
	enigme e;
	int r=10,run =1,running=1,alea,cond=0;
	int x;
	char image[30]="";
	SDL_Event event;
        srand(time(NULL));
 	FILE *f ;  
	f=fopen("valeur","a") ;	 
	SDL_Init ( SDL_INIT_VIDEO ) ;
 	SDL_EnableUNICODE( SDL_ENABLE );
	screen=SDL_SetVideoMode(500,625,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
/*init enigma*/
	init_enigme(&e);
	srand(time(NULL));
	 while (run)
	 {
	    running=1 ;
	    SDL_PollEvent(&event);
 	    if( event.type == SDL_QUIT)
                 {
                  run = 0;
		 }
			  
            /*display enigma*/
       	     display ( screen  , image ,&e,&alea) ;
	     solution_e1 (image,&x) ;
	   if(cond!=1)
	   {
	   cond=1 ;	
	   do {
	   r=resolution1 (&running,&run ) ;
	   }
	   while(r<0 || r>4) ;
           } 


	 fprintf(f,"1= %d \n r=%d\n alea: %d",x,r,alea) ;
	 
	display_result(screen,r,&e,x);SDL_Flip(screen);SDL_Delay(2000);return 1;			
         while(running){
	 SDL_WaitEvent(&event);
         switch(event.type)
                       {

		       case SDL_QUIT :
                       running =0 ;
		       run=0 ;
		        break ;

                       case SDL_KEYDOWN :
                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE: 
			                           running= 0 ;
	                			 display ( screen  , image ,&e,&alea) ; 
						cond=0 ;
			
			                        break ;
			          }
			     break ;
                       }
                    }
   } 
	 fclose(f) ;
      SDL_FreeSurface(e.img);}

