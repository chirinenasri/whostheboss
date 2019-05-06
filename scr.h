#ifndef FICHIER_H
#define FICHIER_H
#define SPEED 1
#define IMX 368
#define IMY 388

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface* Charger(const char* fic);
int negatmodulo(int x,int mod);

#endif
