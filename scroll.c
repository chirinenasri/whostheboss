#define SPEED -1
#define IMX 368
#define IMY 388
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scroll.h" 
SDL_Surface* Charger(const char* fic)
{
    SDL_Surface *res;
    SDL_Surface* tmp = IMG_Load("bkp.png");
    if (tmp==NULL)
    {
        printf("Erreur chargement %s\n",fic);
        exit(-1);
    }
    res = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    return res;
}

int KeyHit()
{
    SDL_Event e;
    if (SDL_PollEvent(&e))
        if (e.type == SDL_KEYDOWN)
            return 1;
    return 0;
}

int negatmodulo(int x,int mod)
{
    if (x>=0)
        return x%mod;
    return (x%mod)+mod;
}

