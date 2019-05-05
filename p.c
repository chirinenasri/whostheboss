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

typedef enum bool 

{ false,true} bool;

int move()
{SDL_Surface *screen=NULL, *image;
 SDL_Rect positionecran;
const int speed=8;
Uint32 start;
const int FPS=30;
 int collision=-1, test=0, test1=0, i=-1, sens=0, collision2=-1,  collision3=-1, arret=0,x=0,y=0,maj=0;
 SDL_Rect positionlost;
positionlost.x=0; 
positionlost.y=0;
   persoprincipal p;
   background bg;
   entitesecondaire obj, vie;
   score s;
   chrono c;
   char pause;
bool b[4]= {0,0,0.0} ; 
//******************************************
    //initialisation score
    /*TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    char temps[20] = ""; /* Tableau de char suffisamment grand */

    //TTF_Init();
    //SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

    /* Chargement de la police */
    //police = TTF_OpenFont("LionCub-Regular-2.ttf", 65);

    /* Initialisation du temps et du texte */
    /*tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    c.texte = TTF_RenderText_Blended(police, temps, couleurNoire);*/
//******************************************
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{  printf("unable to initialize %s\n", SDL_GetError());
return 1;}

init_persoP(&p);          //initialiser personnage principal
init_background(&bg);     //initialiser background
init_objet(&obj);         //initialiser objet
init_vie(&vie);           //initialiser vie
initialiser_score(&s);    //initialiser score
//initialiser_chrono(&c);   //initialiser chrono

//screen= SDL_SetVideoMode(1000, 514, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
screen=SDL_SetVideoMode(800,514,32,SDL_SWSURFACE|SDL_DOUBLEBUF); 
if (screen==NULL)
{printf ("erreur %s\n", SDL_GetError());
return (1);
}
//oiseau youssef

	Perso objet;
	SDL_Rect posBack;
	int min=300, max = 500;	

	objet.img[0] = IMG_Load("objet.png");
	if(objet.img[0]==NULL)
		exit(EXIT_FAILURE);

	objet.pos.x=300;
	objet.pos.y=0;
	objet.direction = 1;


//gestion de l'evenement
int done=1;
int z;
SDL_Event event;
while(done){
start=SDL_GetTicks();
if (SDL_PollEvent(&event)){
  switch (event.type){ 
    case SDL_KEYDOWN : {
      switch(event.key.keysym.sym){
         case SDLK_ESCAPE:
            done=0;
            
            break;
          case SDLK_RIGHT:
            p.positionpp.x+=50;
            b[0]=1;
            //if (p.positionpp.x<1200 - p.pp->w){
             //p.positionpp.x+=7;
             //p.posnokta.x+=2;
            //}
            break;
          case SDLK_LEFT:
           p.positionpp.x-=50;
           b[1]=1;
           //if (p.positionpp.x>0){
           //p.positionpp.x-=7;
           //p.posnokta.x-=2;
            //}
           break;
          case SDLK_UP:
           p.positionpp.y-=50;
           b[2]=1;
           break;
          case SDLK_DOWN:
           p.positionpp.y+=50;
           b[3]=1;
  
           break;
          }//end switch(event.key.keysym.sym)
          }//end case SDL_KEYDOWN 
          }//end switch (event.type)
          }//end if (SDL_PollEvent(&event))


//scrolling mohamed
if (b[0])
{
	x+=speed;
	bg.camera.x+=speed;
        p.posnokta.x+=1;
		if(bg.camera.x>=4096-800)
			bg.camera.x=0;
} 
else if (b[1])
{ 
	x-=speed;
	bg.camera.x-=speed;
        p.posnokta.x-=1;
		if(bg.camera.x<=0)
			bg.camera.x=4096-800;
}
else if (b[2])
{
	y-=speed;
	bg.camera.y-=speed;
		if(bg.camera.y<=0)
			bg.camera.y=8000-600;
}
else if(b[3])
{
	y+=speed;
	bg.camera.y+=speed;
		if(bg.camera.y>=8000-600)
			bg.camera.y=0;
}
//SDL_BlitSurface(bg.bg,NULL,screen,&bg.positionbg);
SDL_BlitSurface(bg.bg,&bg.camera,screen,NULL);
if(1000/FPS>SDL_GetTicks()-start)
 SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       

//afficher_background(&bg, screen);
afficher_personnage(&p,screen);  //apres mise a jour de la position

//afficher petite map
affichermap(&p, &bg, screen);
//***********affichage oiseau youssef***************************
deplacer_objet (&objet, min, max);	
afficher_objet2(&objet, bg.bg);
//afficher_background(&bg, screen);


afficher_objet1(&obj,screen);
afficher_objet22(&obj,screen);
afficher_objet3(&obj,screen);
if (test1==0)
{afficher_vie3(&vie, screen);
}

collision3=boundingbox3(p.positionpp, &obj);
maj=1;
if(collision3==1) { p.positionpp.x+=30;
                    test1++;}
//maj_objet(&obj,maj);
if (test1==2) {afficher_vie2(&vie, screen);}
if (test1==6) {afficher_vie1(&vie, screen);}
if (test1==10) {//ouverture dune fenetre game over
SDL_Surface* fenetre, *backgroundx;
SDL_Rect positionlost;
positionlost.x=0;
positionlost.y=0;
backgroundx= IMG_Load("gameover.png");
SDL_BlitSurface(backgroundx, NULL, screen, &positionlost);
//SDL_Flip(fenetre);
//done=0;
}
/*
tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100)
        {
            compteur += 100; 
            sprintf(temps, "Temps : %d", compteur); 
            SDL_FreeSurface(c.texte); 
            c.texte = TTF_RenderText_Blended(police, temps, couleurNoire);
            tempsPrecedent = tempsActuel;
        }
        c.poschrono.x = 500;
        c.poschrono.y = 50;
        afficher_background(&bg, screen);
            SDL_Flip(screen);
        
        SDL_BlitSurface(c.texte, NULL, screen, &c.poschrono); /* Blit du texte */
        //SDL_Flip(screen);*/

//afficher_chrono(&c,screen, done, bg);
//SDL_Flip(screen);
//afficher_background(&bg, screen);
//SDL_Flip(screen);
        //SDL_BlitSurface(c.texte, NULL, screen, &c.poschrono); /* Blit du texte */
        //SDL_Flip(screen);

//*************collision score**********************************
collision=boundingbox(p.positionpp, &obj);  //RQ: l'image de l'objet doit disparaitre apres collision, mais comment?
maj=2;
if (collision==1) 
        {s.sc -=100;
        p.positionpp.x+=50; 
        //SDL_FreeSurface(obj.objet[1]);
//maj_objet(&obj,maj);
}

afficher_score(&s,screen);
//SDL_Flip(screen);

//**************collision enigme******************************** ca marche: ne pas effacer!!!!!!!!!!!!!!
collision2=boundingbox2(p.positionpp, &obj);
if(collision2==1)
enigmi();




SDL_Flip(screen);
}//end while(done)
SDL_FreeSurface(vie.vie[0]);
SDL_FreeSurface(vie.vie[1]);
SDL_FreeSurface(image);
SDL_FreeSurface(bg.bg);
SDL_FreeSurface(p.pp);
SDL_FreeSurface(objet.img[0]);
SDL_FreeSurface(screen);;
SDL_FreeSurface(c.texte);
SDL_FreeSurface(s.texte);
//TTF_CloseFont(police);
//TTF_Quit();
SDL_Quit();
return (0);
}
