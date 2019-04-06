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
}entitesecondaire;

typedef struct vie
{SDL_Surface vie[4];
SDL_Rect posvie;
int nb;
}vie;

//*******************background******************
void init_background(background* b);
void afficher_background(background *b, SDL_Surface *fenetre);
void scrollingbg(int sens, background *b , persoprincipal *p);
//SDL_Rect scrolling(int d, SDL_Rect camera, persoprincipal pp);

//******************personnage principal**********
void init_persoP(persoprincipal *p);
void afficher_personnageinit(persoprincipal *p, SDL_Surface *ecran);
int deplacement_clavier(persoprincipal *p, SDL_Surface *ecran);
void afficher_personnage(persoprincipal *p, SDL_Surface *ecran, int sens);

//******************afficher objet***************
 void init_objet(entitesecondaire *obj);
void afficher_objet(entitesecondaire *obj, SDL_Surface *ecran);

//**************collision BOUNDINGBOX personnage avec objet1: banc *******
int boundingbox (persoprincipal *pp, entitesecondaire *obj);



#endif
