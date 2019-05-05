#ifndef QUIT_H_INCLUDED
#define QUIT_H_INCLUDED

#include "main.h"

typedef struct
{
    SDL_Surface *exit[7];
}quitter;

int quit(SDL_Surface *screen);
#endif // QUIT_H_INCLUDED
