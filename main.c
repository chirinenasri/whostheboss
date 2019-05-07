#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "IA.h"


#define width 1360 
#define height 760

int main()
{
  SDL_Surface *screen=NULL ;
  int running=1,collision,i,temp_prec,temp_actu,test ;
  float D ;
  SDL_TimerID timer ;

  Objet perso,robot ;

   SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    intialiser(&perso ,&robot) ;
    setup (screen,&perso,&robot) ;
    
    SDL_EnableKeyRepeat(10, 10);

    while(running){
     deplacement_objet(&perso,&running) ;
     calculer_centre_rayon (&perso,&robot) ;
     D=calculer_distance (&perso,&robot) ;
     collision=verif_collision (&perso,&robot,D ) ;
     if(collision)
     {
       

         temp_prec=SDL_GetTicks();

         if(temp_prec-temp_actu>1000)
         {
           
         do{

           temp_actu=SDL_GetTicks() ;
           
           if(perso.pos.x>robot.pos.x)
           robot.pos.x+=1 ;
           if(perso.pos.x<robot.pos.x)
           robot.pos.x-=1 ;
            deplacement_objet(&perso,&running) ;
            SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
            SDL_BlitSurface(perso.img,NULL,screen,&(perso.pos)) ;
            SDL_BlitSurface(robot.img,NULL,screen,&(robot.pos)) ;
            SDL_Flip(screen);
        
         }while(robot.pos.x!=perso.pos.x && (temp_actu-temp_prec<2000)) ;
          
       deplacement_objet(&perso,&running) ;
       SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
       SDL_BlitSurface(perso.img,NULL,screen,&(perso.pos)) ;
       SDL_BlitSurface(robot.img,NULL,screen,&(robot.pos)) ;
       SDL_Flip(screen);
         }
       deplacement_objet(&perso,&running) ;
       SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
       SDL_BlitSurface(perso.img,NULL,screen,&(perso.pos)) ;
       SDL_BlitSurface(robot.img,NULL,screen,&(robot.pos)) ;
       SDL_Flip(screen);
       


     }
     else
     {
       deplacement_objet(&perso,&running) ;
       SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
       SDL_BlitSurface(perso.img,NULL,screen,&(perso.pos)) ;
       SDL_BlitSurface(robot.img,NULL,screen,&(robot.pos)) ;
       SDL_Flip(screen);
     }
     


    }
    




    return EXIT_SUCCESS;
}


