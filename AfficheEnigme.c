#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include "fichier.h"

int afficher_enigmes(enigmes* ES,SDL_Surface *fenetre)
{int i=0;
i=rand()%(ES->nbenigmes);
SDL_BlitSurface(ES->E[i].answer[1],NULL,fenetre,&ES->E[0].posans1);
SDL_BlitSurface(ES->E[i].answer[2],NULL,fenetre,&ES->E[0].posans2); 
SDL_BlitSurface(ES->E[i].answer[3],NULL,fenetre,&ES->E[0].posans3);
SDL_BlitSurface(ES->E[i].texte,NULL,fenetre,&ES->E[0].postxt);
return i;
}
