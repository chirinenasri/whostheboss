#ifndef scroll_H
#define scroll_H
#define SPEED -1
#define IMX 368
#define IMY 388

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface* Charger(const char* fic);
int KeyHit();
int negatmodulo(int x,int mod);

#endif
