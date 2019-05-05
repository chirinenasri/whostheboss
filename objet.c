
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


 void init_objet(entitesecondaire *obj)
{
      
obj->positionobj1.x=650;
obj->positionobj1.y=400;
obj->positionobj2.x=450;
obj->positionobj2.y=400;
obj->positionobj3.x=250;
obj->positionobj3.y=400;
obj->objet[0]=IMG_Load("cartons.png");
obj->objet[1]=IMG_Load("cartons.png");
obj->objet[2]=IMG_Load("cartons.png");
obj->positionobj1.w=obj->objet[0]->w;
obj->positionobj1.h=obj->objet[0]->h;
obj->positionobj2.w=obj->objet[1]->w;
obj->positionobj2.h=obj->objet[1]->h;
obj->positionobj3.w=obj->objet[2]->w;
obj->positionobj3.h=obj->objet[2]->h;
}

void afficher_objet1(entitesecondaire *obj, SDL_Surface *ecran)
{
SDL_BlitSurface(obj->objet[0], NULL, ecran, &obj->positionobj1);
}

void afficher_objet22(entitesecondaire *obj, SDL_Surface *ecran)
{
SDL_BlitSurface(obj->objet[1], NULL, ecran, &obj->positionobj2);
}

void afficher_objet3(entitesecondaire *obj, SDL_Surface *ecran)
{
SDL_BlitSurface(obj->objet[2], NULL, ecran, &obj->positionobj3);
}

void maj_objet(entitesecondaire *obj, int x)
{
if (x=1)
   {obj->positionobj3.x=-30;
   obj->positionobj3.y=-30;}
if (x=2)
   {obj->positionobj2.x=-30;
   obj->positionobj2.y=-30;}
if (x=3)
   {obj->positionobj1.x=-30;
   obj->positionobj1.y=-30;}
}




  


