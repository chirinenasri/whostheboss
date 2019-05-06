#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h" 
#include "ennemi.c" 

 
int main ( int argc, char *argv[])
{ int continuer =1;
char pause();
 
SDL_Surface *ecran=NULL, *ennemi=NULL, *background = NULL;
 SDL_Rect positionennemi,positionbackground;

positionbackground.x=0;
positionbackground.y=0;

positionennemi.x=400;
positionennemi.y=300;

background=IMG_Load("bkp.png");
ennemi =IMG_Load("personnage.png");
SDL_Init (SDL_INIT_VIDEO);
ecran=SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


SDL_BlitSurface (background,NULL,ecran,&positionbackground);

SDL_BlitSurface (ennemi,NULL,ecran,&positionennemi);
SDL_Flip(ecran);
pause();
SDL_FreeSurface (ennemi);
SDL_FreeSurface (background);
SDL_Quit() ;

return EXIT_SUCCESS;
 
}
