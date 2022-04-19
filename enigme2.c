#include "enigme2.h"


void generate(enigme2 *e){
	
	srand(time(NULL));
	e->d=rand()%7; 
}

void InitEnigme(enigme2 *e,char *filename[]){

	char im[100],imr1[100],imr2[100],imr3[100];
	filename[100];
 	e->pos_image.x=200;
  	e->pos_image.y=50;
  	
  	e->pos_response.x=200;
  	e->pos_response.y=50;

	sprintf(*filename,"fileenigme/%d.txt",e->d); 
	sprintf(imr1,"response/%d/1.png",e->d); 
    	sprintf(imr2,"response/%d/2.png",e->d); 
    	sprintf(imr3,"response/%d/3.png",e->d); 
	
     
	FILE * f  = fopen(*filename,"r");   
	if(f==NULL){
		printf("cant open file");
	}
	else{
	    	fscanf(f,"%s",im);  
	    	fclose(f);
	    	
	    	e->image= IMG_Load(im);      
		e->response1= IMG_Load(imr1);
		e->response2= IMG_Load(imr2);
    		e->response3= IMG_Load(imr3);
    		e->image=e->response3;
    		
	    
	    }
	
	
	(*e).image_clock=IMG_Load("clock1.png");  

	e->pos_image_clock.x=0;
	e->pos_image_clock.y=0;
	
	e->single_Clock.w=143;
	e->single_Clock.h=202;
	e->single_Clock.x=0;
	e->single_Clock.y=0;

	e->clock_num=0;                        
}


void displayClock(enigme2 e,SDL_Surface *screen){
			
 		SDL_BlitSurface(e.image_clock,&(e.single_Clock), screen, &e.pos_image_clock);
}
void correct(SDL_Surface *screen,enigme2 *e){

	char im[100];
 
	sprintf(im,"correct.png");
	e->correct= IMG_Load(im);
	e->pos_correct.x=200;
	e->pos_correct.y=50;
	SDL_BlitSurface(e->correct,NULL,screen,&e->pos_correct);
	SDL_Flip(screen);
	SDL_Delay(1000);

}

void wrong(SDL_Surface *screen,enigme2 *e){
 	char im[100];
     
    	e->wrong= IMG_Load("wrong.png");
    	e->pos_wrong.x=200;
    	e->pos_wrong.y=50;
    	SDL_BlitSurface(e->wrong,NULL,screen,&e->pos_wrong);
    	SDL_Flip(screen);
    	SDL_Delay(1000);
    	sprintf(im,"solution/%d.png",e->d);
	e->solution= IMG_Load(im);
	e->pos_solution.x=200;
	e->pos_solution.y=50;
    	SDL_BlitSurface(e->solution,NULL,screen,&e->pos_solution);
    	SDL_Flip(screen);
    	SDL_Delay(1000);

}

void animateEnigme(enigme2 *e){
		 	
	if (e->clock_num >=0 && e->clock_num <8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num++;
	
	}
	
	if ( e->clock_num == 8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num=0;
	
	}
	//printf("%d ",e->clock_num);
	

 
}

void displayEnigme(enigme2 e,SDL_Surface *screen){
		SDL_BlitSurface(e.image,NULL,screen,&e.pos_image);
	    	SDL_Delay(1000); 
 		SDL_BlitSurface(e.response1,NULL, screen, &e.pos_response);
		SDL_Flip(screen);
		SDL_Delay(1000);				
		






















resolution(screen,&e);


}































void resolution(SDL_Surface *screen,enigme2 *e){
	SDL_Event event;
	int continuee =1;
	int i=0;
	while (continuee)
	    {
		SDL_WaitEvent(&event);
		switch(event.type)
		{
		case SDL_QUIT:
		    continuee=0;
		    break;

		case SDL_KEYDOWN:
		    switch(event.key.keysym.sym)
		    {

		    case SDLK_RETURN:
		        if(i>=1 && i<=3)
		        {

		            if (i==1 && e->d%3==1)
		            {
				correct(screen,e);
				continuee=0;
		            }
		            else if (i==2 && e->d%3==2)
		            {
				correct(screen,e);
				continuee=0;
		            }
		            else if (i==3 && e->d%3==0)
		            {
				correct(screen,e);
				continuee=0;
		            }
		            else
		            {
				wrong(screen,e);
				SDL_Delay(1000);
				continuee=0;
		            }
		        }
		        break;

		    case SDLK_DOWN:
		        i++;
		        if(i>=4)
		        {
		            i=1;
		        }
		        if(i==1)
		        {		          
		            e->image=e->response1;
		        }
		        if(i==2)
		        {		       
		         e->image=e->response2;		            
		        }
		        if(i==3)
		        {
		        	e->image=e->response3;		            
		        }
		        ;
		        break;
		    case SDLK_UP:
		        i--;
		        if(i<=0)
		        {
		            i=3;
		        }
		        if(i>=4)
		        {
		            i=1;
		        }
		        if(i==1)
		        {
		        	e->image = e->response1;
		        }
		        if(i==2)
		        {
		        	e->image = e->response2;
		        }
		        if(i==3)
		        {
		        	e->image=e->response3;		     
		        }
		        break;
		    }
		}
		SDL_BlitSurface(e->image,NULL,screen,&e->pos_image);
		SDL_Flip(screen);
    	}

}




int enigmef(SDL_Surface *screen){
		char *filename[100];
	SDL_Surface *backg = IMG_Load("enigma backg.jpg");
	SDL_Rect backg_pos;
	backg_pos.x = 0;
	backg_pos.y = 0;
screen=SDL_SetVideoMode (1366,768,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 //initialisation 
 	enigme2 ee;
	ee.d=1;
	generate(&ee);
	int height_window = 768,width_window = 1366;
        int done=1,dt=0,i=0,continuee=1,yes=1;
	SDL_Event event;
	SDL_Event event2;		InitEnigme(&ee ,&filename[100]);

 	 while (done)
	{ 	
	 
	SDL_PollEvent(&event2);

        switch(event2.type)
        {
            case SDL_QUIT:
                done = 0;
                break;

            case SDL_KEYDOWN:
                switch(event2.key.keysym.sym)
                {		
              
		case SDLK_RETURN:
		    
		        if(i>=1 && i<=3)
		        {
		            if (i==1 && ee.d%3==1)
		            {
				correct(screen,&ee);
				return 1;
		            }
		            else if (i==2 && ee.d%3==2)
		            {
				correct(screen,&ee);
				return 1;
		            }
		            else if (i==3 && ee.d%3==0)
		            {
				correct(screen,&ee);
				return 1;
		            }
		            else
		            {
				wrong(screen,&ee);
				SDL_Delay(1000);
				return -1;
		            }
		        }
		        break;

		    case SDLK_DOWN:
		        i++;
		        if(i>=4)
		        {
		            i=1;
		        }
		        if(i==1)
		        {		          
			ee.image=ee.response1;
		        }
		        if(i==2)
		        {		       
		         ee.image=ee.response2;		            
		        }
		        if(i==3)
		        {
			ee.image=ee.response3;		            
		        }
		        ;
		        break;
		    case SDLK_UP:
		        i--;
		        if(i<=0)
		        {
		            i=3;
		        }
		        if(i>=4)
		        {
		            i=1;
		        }
		        if(i==1)
		        {
		        	ee.image = ee.response1;
		        }
		        if(i==2)
		        {
		        	ee.image = ee.response2;
		        }
		        if(i==3)
		        {
		        	ee.image=ee.response3;		     
		        }
		        break;
		        
		         
		    }
    
		}
			
 		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
 		SDL_BlitSurface(ee.image,NULL,screen,&ee.pos_image);
		animateEnigme(&ee);
		SDL_Delay(100);
		displayClock(ee,screen);
 		
		SDL_Flip(screen);
 
       }
		SDL_FreeSurface(backg);
		SDL_Quit();

	return 0;}

