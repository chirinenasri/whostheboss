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

//*************animation oiseau youssef
void deplacer_objet (Perso * objet, int min, int max)//aléatoirement//
{
	 
	if (objet->pos.x >= max )
		objet->direction = 0;
		
	if (objet->pos.x <= min )
		objet->direction = 1;
		
	if (objet->direction == 1)
		objet->pos.x += 10;
	if (objet->direction == 0)
		objet->pos.x -= 10;
			
}

void afficher_objet2 (Perso *objet, SDL_Surface *ecran)
{
	SDL_Delay(20);
	SDL_BlitSurface (objet->img[0], NULL, ecran, &objet->pos);
}
