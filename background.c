
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
b->positionbg.y=-10;
b->speed=15;
//b->positionmaskbg.x=0;
//b->positionmaskbg.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=800;
b->camera.h=600;
b->stage=1;
b->bg=IMG_Load("TUNISbg.png");
b->positionbg.w=4096;
b->positionbg.h=514;
b->map=IMG_Load("map.jpg");
b->posmap.x=200;
b->posmap.y=464;
}

void afficher_background(background *b, SDL_Surface *fenetre)
{
 SDL_BlitSurface(b->bg, NULL, fenetre, &b->positionbg);	
}

void affichermap (persoprincipal *p, background *b, SDL_Surface *screen)
{
SDL_BlitSurface(b->map,NULL,screen,&b->posmap);
SDL_BlitSurface(p->nokta,NULL,screen,&p->posnokta);
}

