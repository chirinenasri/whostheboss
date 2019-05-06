#ifndef FICHIER_H
#define FICHIER_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


void init_ennemi( SDL_Rect positionennemi,SDL_Surface *ennemi,SDL_Surface *ecran);
void affiche_ennemi( SDL_Rect positionennemi,SDL_Surface *ennemi,SDL_Surface *ecran);             


#endif
