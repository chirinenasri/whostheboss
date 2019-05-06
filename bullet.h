#ifndef Bullet_H
#define Bullet_H
#include <SDL/SDL.h>
#include "background.h"
#include "voiture.h"
#include "vector.h"


struct Bullet {
	
	SDL_Rect position;
	SDL_Surface * image[5];
	int score;
	int vie;

	int moving; //0:not moving 1:moving
	float Mass;
	Deplacement dep;
	
};
typedef struct Bullet Bullet;

int loadBulletImages(Bullet * A);

void initBullet(Bullet *A,Voiture B);

void deplacerBullet(Bullet *Bu,Background Backg,Voiture V,Uint32 dt);

void freeBullet(Bullet *A);

#endif
