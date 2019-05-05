
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "fichier.h"
 void init_vie(entitesecondaire *vie)
{
      
vie->positionvie.x=0;
vie->positionvie.y=5;
vie->vie[0]=IMG_Load("3.png");
vie->vie[1]=IMG_Load("2.png");
vie->vie[2]=IMG_Load("1.png");
//vie->vie[3]=IMG_Load("vie4.png");
}

void afficher_vie3(entitesecondaire *vie, SDL_Surface *ecran)
{
SDL_BlitSurface(vie->vie[0], NULL, ecran, &vie->positionvie);
}

void afficher_vie2(entitesecondaire *vie, SDL_Surface *ecran)
{
SDL_BlitSurface(vie->vie[1], NULL, ecran, &vie->positionvie);
}

void afficher_vie1(entitesecondaire *vie, SDL_Surface *ecran)
{
SDL_BlitSurface(vie->vie[2], NULL, ecran, &vie->positionvie);
}


void freevie(entitesecondaire *vie)
{SDL_FreeSurface(vie->vie[1]);
SDL_FreeSurface(vie->vie[2]);
SDL_FreeSurface(vie->vie[3]);
SDL_FreeSurface(vie->vie[0]);
}
