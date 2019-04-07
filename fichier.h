#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

typedef struct background
{ SDL_Surface* bg;
SDL_Surface* maskbg; //pour la collision pixel parfait
SDL_Rect positionbg;
SDL_Rect positionmask;
SDL_Rect scroll;
int sens;
int speed;
int stage;
SDL_Surface* fenetre;
SDL_Rect camera;
}background;

typedef struct  persoprincipal
{SDL_Surface* pp; //une seule image pour le moment. NB:changer en tableau d'images pour l'animation
SDL_Rect positionpp;
int time;
int vie;
int score;
}persoprincipal;

typedef struct entitesecondaire
{SDL_Surface* ennemi;
SDL_Rect positionennemi;
SDL_Surface* objet[2];
SDL_Rect positionobj1;
SDL_Rect positionobj2;
SDL_Surface* vie[4];
SDL_Rect positionvie1;
SDL_Rect positionvie2;
SDL_Rect positionvie3;
SDL_Rect positionvie4;
}entitesecondaire;

typedef struct vie
{SDL_Surface vie[4];
SDL_Rect posvie;
int nb;
}vie;

typedef struct enigme
{
SDL_Surface *texte;
SDL_Surface *answer[4];
SDL_Rect postxt;
SDL_Rect posans1;
SDL_Rect posans2;
SDL_Rect posans3;
}enigme;

typedef struct enigmes
{
int nbenigmes;
enigme E[30];
}enigmes;

/*typedef struct 
{
SDL_Rect posenig;
}enigme;*/
void initialisier_enig(enigme *enig);	
void afficher_enigme(enigme enig);

//***************************enigme*******************
void enigmi ();
void initialiser_enigmes(enigmes *ES);
int  afficher_enigmes(enigmes *ES,SDL_Surface *fenetre);
int ResolutionEniges(enigmes ES,int IndiceEnigme,char an[]);


//P.c
int move();

//*******************background******************
void init_background(background* b);
void afficher_background(background *b, SDL_Surface *fenetre);
void scrolling_right(SDL_Surface *screen, background *b);
void scrolling_left(SDL_Surface *screen, background *b);

//void scrollingbg(int sens, background *b , persoprincipal *p);
//SDL_Rect scrolling(int d, SDL_Rect camera, persoprincipal *pp);
//mohamed
//void scroll (int direction,persoprincipal *j,background *map); 
//void display_scroll (SDL_Surface *ecran,background map);


//************SCROLLING***********
void scrollright(background *B1, persoprincipal *p1);
void scrollleft(background *B1,persoprincipal *p1);
void scrollup(background *B1,persoprincipal *p1) ;
void scrolldown(background *B1,persoprincipal *p1);
void scrollright2(background *B1,persoprincipal *p1) ;
void scrollleft2(background *B1,persoprincipal *p1);
void scrollup2(background *B1,persoprincipal *p1);
void scrolldown2(background *B1,persoprincipal *p1);


//******************personnage principal**********
void init_persoP(persoprincipal *p);
void afficher_personnageinit(persoprincipal *p, SDL_Surface *ecran);
int deplacement_clavier(persoprincipal *p, SDL_Surface *ecran);
void afficher_personnage(persoprincipal *p, SDL_Surface *ecran, int sens);

//******************afficher objet***************
 void init_objet(entitesecondaire *obj);
void afficher_objet(entitesecondaire *obj, SDL_Surface *ecran);

//**************collision BOUNDINGBOX personnage avec objet*******
int boundingbox (SDL_Rect positionpp, entitesecondaire *obj);//1ers cartons pour score
int boundingbox2 (SDL_Rect positionpp, entitesecondaire *obj); //2eme cartons pour enigme

//***************chrono****************

//***************vie***************
 void init_vie(entitesecondaire *vie);
void afficher_vie(entitesecondaire *vie, SDL_Surface *ecran, int test);
void freevie(entitesecondaire *vie);

#endif
