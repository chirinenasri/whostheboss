
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "fichier.h"

void init_background(background* b)
{
char ch[35];
b->positionbg.x=0;
b->positionbg.y=-548;
b->speed=5;
//b->positionmaskbg.x=0;
//b->positionmaskbg.y=0;
b->scroll.x=1020;
b->scroll.y=4167;
b->scroll.w=800;
b->scroll.h=600;
b->stage=1;
b->bg=IMG_Load("TUNISbg.jpg");
//b->maskbg=IMG_Load("");


}

void afficher_background(background *b, SDL_Surface *fenetre)
{
	
	//SDL_BlitSurface(b->bg, &(b->scroll), fenetre,NULL);
         SDL_BlitSurface(b->bg, NULL, fenetre, &b->positionbg);
	
}

void scrolling_right(SDL_Surface *screen, background *b)
{
if (b->camera.x<1600 - b->camera.w)
b->camera.x+=20;
}

void scrolling_left(SDL_Surface *screen, background *b)
{
if (b->camera.x>0)
b->camera.x-=20;
}
	
/*void scrollingbg(int sens, background *b , persoprincipal *p)
{
	if(sens==1) //droite
	{ 
		b->scroll.x += b->speed;
		b->positionbg.x += b->speed;
		
		if(b->scroll.x <= 0)
			b->scroll.x = 0;
		if(b->scroll.x >= 8000-800)
			b->scroll.x = 8000-800;
	}
	else if(sens==2) //gauche
	{ 
		b->positionbg.x -= b->speed;
		b->scroll.x -= b->speed;
		if(b->scroll.x <= 0)
			b->scroll.x = 0;
		if(b->scroll.x >= 8000-800)
			b->scroll.x = 8000-800;
		
	}
else if(sens==3)//haut
	{ 
		b->positionbg.y += b->speed;
		b->scroll.y += b->speed;
		if(b->scroll.y <= 0)
			b->scroll.y=0;
		if(b->scroll.y>=8000-600)
			b->scroll.y=8000-600;
		
	}
else if(sens==4)//bas
	{ 
		b->positionbg.y -= b->speed;
		b->scroll.y -= b->speed;
		if(b->scroll.y <= 0)
			b->scroll.y = 0;
		if(b->scroll.y >= 8000-600)
			b->scroll.y = 8000-600;
		
	}
}*/

/*SDL_Rect scrolling(int d, SDL_Rect camera, persoprincipal *pp)
{
if(camera.x<=0) camera.x=0;

if(camera.x>=7000) camera.x=7000;
if(d==1 && pp->positionpp.x>=500)
{
camera.x=camera.x+20;
}
if(d==2 && pp->positionpp.x<=500 )
{
camera.x=camera.x-20;
}


return camera ;
}*/

//****************************************************************

/*void scroll(int direction, persoprincipal *j,background *map) 
{

  if (direction==1 && j->positionpp.y + j->positionpp.h/2  <= map->camera.h/2 - 10) 
  {
                              map->camera.y-=10;
                           (j->positionpp).y+=10;
  }
  else if (direction==2 && j->positionpp.y + j->positionpp.h/2 +100 >= map->camera.h/2 + 10) 
  {
			map->camera.y+=10;
                               (j->positionpp).y-=10;
  }
  else if (direction==4 && j->positionpp.x + j->positionpp.w/2  <= map->camera.w/2 - 10) 
  {
                   map->camera.x-=10;
                    (j->positionpp).x+=10;
  }
  else if (direction==3 && j->positionpp.x + j->positionpp.w/2 +200 >= map->camera.w/2 + 10) 
  {
		   map->camera.x+=10;
                    (j->positionpp).x-=10;
  }


  if( map->camera.x < 0 )
    {
        map->camera.x = 0;
                           (j->positionpp).x-=10;
    }
    if( map->camera.y < 0 )
    {
        map->camera.y = 0;
                           (j->positionpp).y-=10;
    }


  if( map->camera.x > map->bg->w - map->camera.w )
    {
        map->camera.x = map->bg->w - map->camera.w ;
	             (j->positionpp).x+=10;
    }
    if( map->camera.y > map->bg->h - map->camera.h  )
    {
        map->camera.y = map->bg->h - map->camera.h ;
                  (j->positionpp).y+=10;
    }

}


  




void display_scroll (SDL_Surface *ecran,background map)
{
SDL_BlitSurface(map.bg, &map.camera, ecran, NULL);

}*/
