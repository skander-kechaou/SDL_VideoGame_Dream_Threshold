#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"


void initialiser_background(background *bckg1 )
{

	bckg1->background=NULL;
	bckg1->background=IMG_Load("background.jpg");
	bckg1->pos_camera.x=0;
	bckg1->pos_camera.y=0;
	bckg1->pos_camera.h=600;
	bckg1->pos_camera.w=3200;

       /* bckg1->anim[1]=IMG_Load("1.jpg");
        bckg1->anim[2]=IMG_Load("2.jpg");
        bckg1->anim[3]=IMG_Load("3.jpg");*/

}



void afficher_background(background *bckg1,SDL_Surface *screen,SDL_Rect posbg1)
{
	
SDL_BlitSurface(bckg1->background,&(bckg1->pos_camera),screen,&posbg1);
//SDL_BlitSurface(bckg1.anim[bckg1.frame],NULL,screen,&bckg1.posanim);

}

/*void animeBackground(Background *e)
{   
    if(e->frame==3)
        e->frame=0;
    else e->frame++;
}*/





void scrollToLeft (background * b)
{ 
if (b->pos_camera.x!=0)
{
b->pos_camera.x-=10;
}

} 

void scrollDown (background * b)
{ 
if (b->pos_camera.y!=0)
{
b->pos_camera.y+=10;
}

} 


void scrollToRight (background * b)
{ 
 if (b->pos_camera.w - b->pos_camera.x != LARGEUR_FENETRE) 
 b->pos_camera.x+=10; 
}

void scrollUP (background * b)
{ 
 if (b->pos_camera.h - b->pos_camera.y != LARGEUR_FENETRE) 
 b->pos_camera.y-=10; 
}




SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	
	char* pPosition = ( char* ) surface->pixels ;

	
	pPosition += ( surface->pitch * y ) ;

	
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}

int collision_Parfaite1(SDL_Surface *masque,SDL_Rect posperso,SDL_Rect posmap)
{

SDL_Color col,col2,col22,col1;
 
	col=GetPixel(masque,posperso.x+100+posmap.x,posperso.y+220);
	col2=GetPixel(masque,posperso.x+50+posmap.x,posperso.y+230);
	col22=GetPixel(masque,posperso.x+100+posmap.x,posperso.y+180);
	col1=GetPixel(masque,posperso.x+100+posmap.x,posperso.y+220);


   printf("%d    %d   /////////// \n",posperso.x+100+posmap.x+601,posperso.y+220 );
  printf("%d    %d   %d\n",col.r,col.b,col.g );
  //SDL_Delay(250);
if ((col.r==90)&&(col.b==90)&&(col.g==90))
  return 1;//obstacle
else if ((col22.r==254)&&(col22.b==0)&&(col22.g==0))
  return 2;//chouk
else if ((col22.r==23)&&(col22.b==237)&&(col22.g==51))
  return 3;//door enigme

else
{
	return 0;
}

}
int collision_Parfaite2(SDL_Surface *masque,SDL_Rect posperso,SDL_Rect posmap)
{

SDL_Color col,col2,col22,col1;

	col=GetPixel(masque,posperso.x+100+posmap.x-600,posperso.y+220);
	col2=GetPixel(masque,posperso.x+50+posmap.x-600,posperso.y+230);
	col22=GetPixel(masque,posperso.x+100+posmap.x-600,posperso.y+180);
	col1=GetPixel(masque,posperso.x+100+posmap.x-600,posperso.y+220);



   printf("%d    %d   /////////// \n",posperso.x+100+posmap.x+601,posperso.y+220 );
  printf("%d    %d   %d\n",col.r,col.b,col.g );
  //SDL_Delay(250);
if ((col.r==90)&&(col.b==90)&&(col.g==90))
  return 1;//obstacle
else if ((col22.r==254)&&(col22.b==0)&&(col22.g==0))
  return 2;//chouk
else if ((col22.r==23)&&(col22.b==237)&&(col22.g==51))
  return 3;//door enigme

else
{
	return 0;
}


}





