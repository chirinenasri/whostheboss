#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
typedef struct input
{
int right;
int left;
int up;
int down;
int exit;
}input;


typedef struct background
{ SDL_Surface* bg;
SDL_Surface* maskbg; //pour la collision pixel parfait
SDL_Rect positionbg;
SDL_Rect positionmask;
int sens;
int speed;
int stage;
SDL_Surface* fenetre;
SDL_Rect camera;
SDL_Surface *map;
SDL_Rect posmap;
}background;

typedef struct  persoprincipal
{SDL_Surface* pp; //une seule image pour le moment. NB:changer en tableau d'images pour l'animation
SDL_Rect positionpp;
int time;
int vie;
int score;
SDL_Surface *nokta;
SDL_Rect posnokta;

}persoprincipal;

//**animation oiseau youssef
typedef struct 
{
	SDL_Surface *img[4];
	SDL_Rect pos;
	int direction; 

}Perso;

typedef struct entitesecondaire
{SDL_Surface* ennemi;
SDL_Rect positionennemi;
SDL_Surface* objet[3];
SDL_Rect positionobj1;
SDL_Rect positionobj2;
SDL_Rect positionobj3;
SDL_Surface* vie[4];
SDL_Rect positionvie;
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

typedef struct score
{
SDL_Surface *texte;
SDL_Rect posscore;
int sc;
}score;

typedef struct chrono
{
SDL_Surface *texte;
SDL_Rect poschrono;
}chrono;

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
void affichermap (persoprincipal *p, background *b, SDL_Surface *screen);

//******************personnage principal**********
void init_persoP(persoprincipal *p);
void afficher_personnageinit(persoprincipal *p, SDL_Surface *ecran);
int deplacement_clavier(persoprincipal *p, SDL_Surface *ecran);
void afficher_personnage(persoprincipal *p, SDL_Surface *screen);

//******************afficher objet***************
 void init_objet(entitesecondaire *obj);
void afficher_objet1(entitesecondaire *obj, SDL_Surface *ecran);
void afficher_objet22(entitesecondaire *obj, SDL_Surface *ecran);
void afficher_objet3(entitesecondaire *obj, SDL_Surface *ecran);
void maj_objet(entitesecondaire *obj, int x);

//**************collision BOUNDINGBOX personnage avec objet*******
int boundingbox (SDL_Rect positionpp, entitesecondaire *obj);//1ers cartons pour score
int boundingbox2 (SDL_Rect positionpp, entitesecondaire *obj); //2eme cartons pour enigme
int boundingbox3 (SDL_Rect positionpp, entitesecondaire *obj);

//***************chrono****************
void initialiser_chrono(chrono *c);
void afficher_chrono(chrono *c,SDL_Surface *screen, int done, background bg);
//***************vie***************
 void init_vie(entitesecondaire *vie);
void afficher_vie3(entitesecondaire *vie, SDL_Surface *ecran);
void afficher_vie2(entitesecondaire *vie, SDL_Surface *ecran);
void afficher_vie1(entitesecondaire *vie, SDL_Surface *ecran);
void freevie(entitesecondaire *vie);

//************oiseau de youssef
void deplacer_objet (Perso * objet, int min, int max);
void afficher_objet2 (Perso *objet, SDL_Surface *ecran);

//********************score********
void initialiser_score(score *s);
void afficher_score(score *s, SDL_Surface *screen);

//****************ennemiii*******
void init_ennemi(entitesecondaire *e);
void afficher_ennemi(entitesecondaire *e, SDL_Surface *ecran);

#endif
