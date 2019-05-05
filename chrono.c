#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fichier.h"

void initialiser_chrono(chrono *c)
{
//c->texte=NULL;
c->poschrono.x=550;
c->poschrono.y=50;
}

/*void afficher_chrono(chrono *c,SDL_Surface *screen, int done)
{
TTF_Font *police=NULL;
SDL_Color couleurNoire={0,0,0}, couleurBlanche = {255, 255, 255};
char temps[20] = "";
int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
police= TTF_OpenFont("LionCub-Regular-2.ttf", 55);
TTF_Init();
tempsActuel = SDL_GetTicks();
sprintf(temps, "Temps : %d", compteur);
c->texte = TTF_RenderText_Blended(police, temps, couleurNoire);

while (done)
 {tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) /* Si 100 ms au moins se sont écoulées */
        //{
            //compteur += 100; /* On rajoute 100 ms au compteur */
           // sprintf(temps, "chrono : %d", compteur); /* On écrit dans la chaîne "temps" le nouveau temps */
            //SDL_FreeSurface(c->texte); /* On supprime la surface précédente */
          //  c->texte = TTF_RenderText_Blended(police, temps, couleurNoire); /* On écrit la chaîne temps dans la SDL_Surface */
        //    tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
      /*  }


SDL_BlitSurface(c->texte,NULL,screen,&c->poschrono);
SDL_Flip(screen);}
TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(c->texte);
    SDL_Quit();
}
*/
void afficher_chrono(chrono *c,SDL_Surface *screen, int done, background bg)
{   SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    char temps[20] = ""; /* Tableau de char suffisamment grand */

    TTF_Init();
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

    /* Chargement de la police */
    police = TTF_OpenFont("LionCub-Regular-2.ttf", 65);

    /* Initialisation du temps et du texte */
    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    c->texte = TTF_RenderText_Blended(police, temps, couleurNoire);

    while (done)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                done = 0;
                break;
        }
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) /* Si 100 ms au moins se sont écoulées */
        {
            compteur += 100; /* On rajoute 100 ms au compteur */
            sprintf(temps, "Temps : %d", compteur); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(c->texte); /* On supprime la surface précédente */
            c->texte = TTF_RenderText_Blended(police, temps, couleurNoire); /* On écrit la chaîne temps dans la SDL_Surface */
            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }
        c->poschrono.x = 180;
        c->poschrono.y = 210;
        afficher_background(&bg, screen);
            SDL_Flip(screen);
        
        SDL_BlitSurface(c->texte, NULL, screen, &c->poschrono); /* Blit du texte */
        SDL_Flip(screen);

    }
}

