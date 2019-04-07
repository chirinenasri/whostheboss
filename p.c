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

void init_objet(entitesecondaire *obj)
{
      
obj->positionobj1.x=500;
obj->positionobj1.y=500;
obj->positionobj2.x=300;
obj->positionobj2.y=500;
obj->objet[0]=IMG_Load("cartons1.png");
obj->objet[1]=IMG_Load("cartons.png");
obj->positionobj1.w=obj->objet[0]->w;
obj->positionobj1.h=obj->objet[0]->h;
obj->positionobj2.w=obj->objet[1]->w;
obj->positionobj2.h=obj->objet[1]->h;
}




void afficher_objet(entitesecondaire *obj, SDL_Surface *ecran)
{
SDL_BlitSurface(obj->objet[0], NULL, ecran, &obj->positionobj1);
SDL_BlitSurface(obj->objet[1], NULL, ecran, &obj->positionobj2);
}

int move()
{SDL_Surface *screen=NULL, *image;
SDL_Rect positionecran;
persoprincipal p;
background bg;
entitesecondaire obj, vie;
int collision=-1, test=0, i=-1, sens=0, collision2=-1;
char pause;
//musique
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
{printf("%s", Mix_GetError());}
Mix_Music *music;
music=Mix_LoadMUS("2.mp3");
Mix_PlayMusic(music, -1);


//initialisation
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{  printf("unable to initialize %s\n", SDL_GetError());
return 1;
}
//ajout du detective
SDL_Surface *pp=NULL;
pp=IMG_Load("personnage.jpg");
SDL_Rect positionpp;
positionpp.x=200;
positionpp.y=200;
//ajout du background
image=IMG_Load("bkp.png");
screen= SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL)
{printf ("erreur %s\n", SDL_GetError());
return (1);
}
positionecran.x=0;
positionecran.y=0;
positionecran.w= image->w;
positionecran.h= image->h;
SDL_Rect camera;
camera.x=0;
 camera.y=0;
 camera.h=600;
 camera.w=1000;
//gestion de l'evenement
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
{//scrolling_right(screen, &bg);
if (camera.x<1600 - camera.w)
camera.x-=20;
positionecran.x-=50;
positionpp.x+=50;
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);
sens=1;
}

if(event.key.keysym.sym==SDLK_LEFT)
{//scrolling_left(screen, &bg);
if (camera.x>0)
camera.x+=20;
positionecran.x+=50;
positionpp.x-=50;
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);
sens=2;
}

if(event.key.keysym.sym==SDLK_UP)
{positionpp.y-=50;
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);
sens=3;}

if(event.key.keysym.sym==SDLK_DOWN)
{positionpp.y+=50;
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen, &positionecran);
SDL_Flip(screen);
sens=4;}
}}}

SDL_BlitSurface(image,NULL, screen, &positionecran);
//enlever l'arriere plan du detective
SDL_SetColorKey(pp, SDL_SRCCOLORKEY, SDL_MapRGB(pp->format,255,255,255));
SDL_BlitSurface(pp, NULL, screen, &positionpp);
SDL_Flip(screen);
init_objet(&obj);
afficher_objet(&obj,screen);
SDL_Flip(screen);
init_vie(&vie);
collision=boundingbox (positionpp, &obj);
//SDL_Flip(screen);
//*************** collision pour vie
if (collision==1) {//done=0;
test++;}
//i++;}
SDL_BlitSurface(vie.vie[0], NULL, screen, &vie.positionvie1);
SDL_Flip(screen);
//test=0;
//afficher_vie(&vie,screen,test);
if (test==1)
{test--;
SDL_BlitSurface(vie.vie[1], NULL, screen, &vie.positionvie1);
SDL_Flip(screen);
}
if(test==2)
{test--;
SDL_BlitSurface(vie.vie[2], NULL, screen, &vie.positionvie2);
SDL_Flip(screen);
}
if(test==3)
{test--;
SDL_BlitSurface(vie.vie[3], NULL, screen, &vie.positionvie3);
SDL_Flip(screen);
}
if(test==4)
{test--;
SDL_BlitSurface(vie.vie[3], NULL, screen, &vie.positionvie4);
SDL_Flip(screen);
}
//*************SCORE
/*TTF_Init();
TTF_Font *fontTest;
	fontTest=TTF_OpenFont("angelina.TTF",70);
	SDL_Color fontColor={75,50,100};

	SDL_Surface *texte ;
	texte= TTF_RenderText_Solid(fontTest,"Blood Reign ",fontColor);
	SDL_Rect textePosition ;
	textePosition.x=270;
	textePosition.y=65;
SDL_BlitSurface(texte,NULL,screen,&textePosition);
SDL_Flip(screen);*/

//scroll (sens,&p,&bg);
//display_scroll (screen,bg);
//SDL_Flip(screen);

 /*scrollright(&bg, &p);
scrollleft(&bg, &p);
scrollup(&bg, &p) ;
scrolldown(&bg, &p);
scrollright2(&bg, &p) ;
 scrollleft2(&bg, &p);
scrollup2(&bg, &p);
 scrolldown2(&bg, &p);
SDL_Flip(screen); */
}


SDL_FreeSurface(image);
SDL_FreeSurface(pp);
//SDL_FreeSurface(obj.[1]);
SDL_FreeSurface(image);
freevie(&vie);
//Mix_FreeMusic(music);
SDL_Quit();
return (0);
}
