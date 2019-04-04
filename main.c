#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
 
void pause();
 
int main(int argc, char *argv[])
{int x=5;
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *play= NULL, *setting= NULL, *about= NULL,*quit=NULL;
    SDL_Rect positionFond, positionplay, positionsetting,positionabout,positionquit;
 
    positionFond.x = 0;
    positionFond.y = 0;
    positionplay.x = 500;
    positionplay.y = 10;
positionsetting.x=500;
positionsetting.y=170;
positionabout.x=500;
positionabout.y=320;
positionquit.x=530;
positionquit.y=435;

 
    SDL_Init(SDL_INIT_VIDEO);
 
    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
 
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 
    imageDeFond = IMG_Load("bg.png");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 
   
    play = IMG_Load("P.png");
    SDL_BlitSurface(play, NULL, ecran, &positionplay);
setting = IMG_Load("S.png");
    SDL_BlitSurface(setting, NULL, ecran, &positionsetting);
about = IMG_Load("A.png");
    SDL_BlitSurface(about, NULL, ecran, &positionabout);
quit = IMG_Load("E.png");
    SDL_BlitSurface(quit, NULL, ecran, &positionquit);
 
    SDL_Flip(ecran);
    pause();
 
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(play);
SDL_FreeSurface(setting);
SDL_FreeSurface(about);
SDL_FreeSurface(quit);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
 
void pause()
{
    int continuer = 1;
    SDL_Event event;
SDL_Surface *ab=NULL,*ecran=NULL;
SDL_Rect posab,posclic;
posab.x=0;
posab.y=0;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONUP:
               if (event.button.button==SDL_BUTTON_LEFT){
                      posclic.x=event.button.x;
                      posclic.y=event.button.y;}
                 //appuyer sur play
               if ((event.button.x>500)&&(event.button.x<700)&&(event.button.y>30)&&(event.button.y<170)){
                SDL_Init(SDL_INIT_VIDEO);
                SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
 
                ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
                SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
                ab=IMG_Load("3.jpg");
                SDL_BlitSurface(ab, NULL, ecran, &posab);
                SDL_Flip(ecran);}

                 //appuyer sur settings
               if ((event.button.x>500)&&(event.button.x<700)&&(event.button.y>180)&&(event.button.y<300)){
                SDL_Init(SDL_INIT_VIDEO);
                SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
 
                ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
                SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
                ab=IMG_Load("1.jpg");
                SDL_BlitSurface(ab, NULL, ecran, &posab);
                SDL_Flip(ecran);}

                 //appuyer sur about
               if ((event.button.x>500)&&(event.button.x<700)&&(event.button.y>320)&&(event.button.y<400)){
                SDL_Init(SDL_INIT_VIDEO);
                SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
 
                ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
                SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
                ab=IMG_Load("2.jpg");
                SDL_BlitSurface(ab, NULL, ecran, &posab);
                SDL_Flip(ecran);}

                //appuyer sur exit
               if ((event.button.x>500)&&(event.button.x<700)&&(event.button.y>450)&&(event.button.y<600))
                continuer =0;
                break;
        }
    }
}
