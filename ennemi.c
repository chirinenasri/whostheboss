
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


 void init_objet(entitesecondaire *e)
{
      
e->positionennemi.x=500;
e->positionennemi.y=500;

e->ennemi=IMG_Load("personnage.png");
}




void afficher_objet(entitesecondaire *e, SDL_Surface *ecran)
{
SDL_BlitSurface(e->ennemi, NULL, ecran, &e->positionennemi);
}




  


