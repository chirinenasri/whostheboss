
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
      
obj->positionobj1.x=300;
obj->positionobj1.y=700;
obj->positionobj2.x=300;
obj->positionobj2.y=500;
obj->objet[0]=IMG_Load("cartons.png");
obj->objet[1]=IMG_Load("cartons.png");
obj->positionobj1.w=obj->objet[0]->w;
obj->positionobj1.h=obj->objet[0]->h;
obj->positionobj2.w=obj->objet[1]->w;
obj->positionobj2.h=obj->objet[1]->h;
}




void afficher_objet(entitesecondaire *obj, SDL_Surface *ecran)
{
SDL_BlitSurface(obj->objet[0], NULL, ecran, &obj->positionobj1);
SDL_BlitSurface(obj->objet[1], NULL, ecran, &obj->positionobj2);
}




  


