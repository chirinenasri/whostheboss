#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct
{
    SDL_Surface *play[3];
    SDL_Surface *instructions[3];
    SDL_Surface *setting[3];
    SDL_Surface *exit[3];
}buttons;

int main ( int argc, char** argv );
void cleanmenu(SDL_Surface *background);

#endif // MAIN_H_INCLUDED
