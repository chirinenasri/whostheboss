
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
      
vie->positionvie1.x=0;
vie->positionvie1.y=0;
vie->positionvie2.x=0;
vie->positionvie2.y=0;
vie->positionvie3.x=0;
vie->positionvie3.y=0;
vie->positionvie4.x=0;
vie->positionvie4.y=0;
vie->vie[0]=IMG_Load("vie1.png");
vie->vie[1]=IMG_Load("vie2.png");
vie->vie[2]=IMG_Load("vie3.png");
vie->vie[3]=IMG_Load("vie4.png");
}




void afficher_vie(entitesecondaire *vie, SDL_Surface *ecran, int test)
{
switch(test)
{case 0:
SDL_BlitSurface(vie->vie[0], NULL, ecran, &vie->positionvie1);
break;
case 1:
SDL_BlitSurface(vie->vie[1], NULL, ecran, &vie->positionvie2);
break;
case 2:
SDL_BlitSurface(vie->vie[2], NULL, ecran, &vie->positionvie3);
break;
case 3:
SDL_BlitSurface(vie->vie[3], NULL, ecran, &vie->positionvie4);
break;
}
}

void freevie(entitesecondaire *vie)
{SDL_FreeSurface(vie->vie[1]);
SDL_FreeSurface(vie->vie[2]);
SDL_FreeSurface(vie->vie[3]);
SDL_FreeSurface(vie->vie[0]);
}
