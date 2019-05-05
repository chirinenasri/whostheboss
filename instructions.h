#ifndef INSTRUCTION_H_INCLUDED
#define INSTRUCTION_H_INCLUDED

#include "main.h"
typedef struct
{
    SDL_Surface *instruction;
    SDL_Surface *backbutton[3];
    SDL_Rect pos;
}commands;

void instructions (SDL_Surface *screen);
#endif // INSTRUCTION_H_INCLUDED
