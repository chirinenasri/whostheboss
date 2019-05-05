
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
 void init_persoP(persoprincipal *p)
{
p->pp=NULL;      
p->positionpp.x=0;
p->positionpp.y=350;
p->time=0;
p->score=0;
p->vie=4;
p->pp=IMG_Load("personnage.png");
p->positionpp.w=p->pp->w;
p->positionpp.h=p->pp->h;
p->nokta=IMG_Load("nokta.png");
p->posnokta.x=205;
p->posnokta.y=500;
  

}


void afficher_personnage(persoprincipal *p, SDL_Surface *screen)
{
SDL_BlitSurface(p->pp, NULL, screen, &p->positionpp);
//SDL_Flip(screen);
}


void afficher_personnageinit(persoprincipal *p, SDL_Surface *ecran)
{
SDL_BlitSurface(p->pp, NULL, ecran, &p->positionpp);
}






