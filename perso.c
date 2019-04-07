
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
 void init_persoP(persoprincipal *p)
{
      
p->positionpp.x=10;
p->positionpp.y=500;
p->time=0;
p->score=0;
p->vie=4;
p->pp=IMG_Load("personnage.png");
p->positionpp.w=p->pp->w;
p->positionpp.h=p->pp->h;

}


void afficher personnage()
{
int done=1;
SDL_Event event;
while(done)
{

if (SDL_PollEvent(&event))
  { switch (event.type)
    { case SDL_KEYDOWN : {
if (event.key.keysym.sym==SDLK_ESCAPE)
done=0;

if(event.key.keysym.sym==SDLK_RIGHT)
{positionpp.x+=50;
afficher_personnageinit(&p, ecran)
SDL_Flip(ecran);
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);}

if(event.key.keysym.sym==SDLK_LEFT)
{positionpp.x-=50;
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);}

if(event.key.keysym.sym==SDLK_UP)
{positionpp.y-=50;
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);}

if(event.key.keysym.sym==SDLK_DOWN)
{positionpp.y+=50;
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);}
}}}
SDL_BlitSurface(image,NULL, screen, &positionecran);
//enlever l'arriere plan du detective
SDL_SetColorKey(pp, SDL_SRCCOLORKEY, SDL_MapRGB(pp->format,255,255,255));
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
}
SDL_FreeSurface(image);
SDL_FreeSurface(pp);
}

void afficher_personnageinit(persoprincipal *p, SDL_Surface *ecran)
{
SDL_BlitSurface(p->pp, NULL, ecran, &p->positionpp);
}




int deplacement_clavier(persoprincipal *p, SDL_Surface *ecran)
{SDL_Event event2;
int done;
while(done!=0)
                   { if (SDL_PollEvent(&event2))
                    {
                     switch(event2.type)
                     {               
                     case SDL_KEYDOWN : {
                        if ((event2.key.keysym.sym==SDLK_ESCAPE))
                        { done =0;
                         return 0;}

                        if(event2.key.keysym.sym==SDLK_RIGHT)
                        {return 1;

                        } //droite

                        if(event2.key.keysym.sym==SDLK_LEFT)
                        {return 2;
} //gauche

                        if(event2.key.keysym.sym==SDLK_UP)
                        {return 3;

} //haut

                        if(event2.key.keysym.sym==SDLK_DOWN)
                        {return 4;

} //bas

                         }//fin case
                      break;} //fin switch event 2
                             }//fin while
                         }//fin if

}

void afficher_personnage(persoprincipal *p, SDL_Surface *ecran, int sens)
{
switch (sens)
{
case 1: 
p->positionpp.x+=50;
SDL_BlitSurface(p->pp, NULL, ecran, &p->positionpp);
SDL_Flip(ecran);
break;
case 2:
p->positionpp.x-=50;
SDL_BlitSurface(p->pp, NULL, ecran, &p->positionpp);
SDL_Flip(ecran);
break;
case 3:
p->positionpp.y-=50;
SDL_BlitSurface(p->pp, NULL, ecran, &p->positionpp);
SDL_Flip(ecran);
break;
case 4:
p->positionpp.y+=50;
SDL_BlitSurface(p->pp, NULL, ecran, &p->positionpp);
SDL_Flip(ecran);
break;
}//fin switch
}//fin fonction
  


