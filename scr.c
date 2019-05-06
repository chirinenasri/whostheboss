#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scr.h" 
SDL_Surface* Charger(const char* fic)
{
    SDL_Surface *res;
    SDL_Surface* tmp = IMG_Load(fic);
    if (tmp==NULL)
    {
        printf("Erreur chargement %s\n",fic);
        exit(-1);
    }
    res = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    return res;
}

int negatmodulo(int x,int mod)
{
    if (x>=0)
        return x%mod;
    return (x%mod)+mod;
}

