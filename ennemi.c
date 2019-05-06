#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h" 

void init_ennemi( SDL_Rect positionennemi,SDL_Surface *ennemi,SDL_Surface *ecran)

{

ennemi =IMG_Load("personnage.png");
positionennemi.x=400;
positionennemi.y=300;
}
void affiche_ennemi( SDL_Rect positionennemi,SDL_Surface *ennemi,SDL_Surface *ecran)
{
SDL_BlitSurface (ennemi,NULL,ecran,&positionennemi);
}


