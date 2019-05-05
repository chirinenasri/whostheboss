

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include "fichier.h"

void initialiser_score(score *s)
{
s->texte=NULL;
s->posscore.x=530;
s->posscore.y=0;
s->sc=1000;
}

void afficher_score(score *s,SDL_Surface *screen)
{
TTF_Font *police=NULL;
SDL_Color couleurNoire={0,0,0}, couleurBlanche = {255, 255, 255};
char score[20] = "";
//tempsActuel = SDL_GetTicks();
sprintf(score, "Score : %d", s->sc);
police= TTF_OpenFont("LionCub-Regular-2.ttf", 65);
s->texte= TTF_RenderText_Blended(police, score, couleurNoire);

SDL_BlitSurface(s->texte,NULL,screen,&s->posscore);
SDL_Flip(screen);
}




