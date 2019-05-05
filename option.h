#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include "main.h"

typedef struct
{
    SDL_Surface *op[3];
    SDL_Surface *backbutton[3];
    SDL_Rect pos;
}opt;

void option(SDL_Surface *screen);

#endif // OPTIONS_H_INCLUDED
