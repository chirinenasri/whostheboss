#include <SDL/SDL.h>
#include "defs.h"
#include "bullet.h"
#include "voiture.h"
#include <math.h>



int loadBulletImages(Bullet * A)
{
	int i;
	char buf[50];
	char buf0[]="../images/bullet";
	char bmp[]=".bmp";

	for(i=0; i<NBRE_SPRITE_BULLET; i++) {
		sprintf(buf,"%s%s",buf0,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		if (A->image[i]== NULL) {
			printf("Unable to load  Bullet bitmap:\n", SDL_GetError());
			return (-1);
		}
		// set the color of Bullet background (white color) as transparent
		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 0, 0, 0) );
	}

	return(0);
}

void initBullet(Bullet *A,Voiture B)
{
	
	A->position.x=B.position.x+POS_X_CANON;
	A->position.y=B.position.y+POS_Y_CANON;

	A->position.w=A->image[0]->w;
	A->position.h=A->image[0]->h;

	A->score=0;
	A->vie=5;

	A->Mass=70;
	A->moving=0;
	
	A->dep.magnitude =5;
	A->dep.angle=-6;

}

void deplacerBullet(Bullet *Bu,Background Backg,Voiture V,Uint32 dt)
{
	/*Dx = vit + ½at2
	 * displacement = initial velocity * time + ½ acceleration * time2
	 * */
	Bu->position.x+=Bu->dep.magnitude*cos(Bu->dep.angle/**M_PI/180*/)*dt; //angle en radian
	Bu->position.y-=Bu->dep.magnitude*sin(Bu->dep.angle/**M_PI/180*/)*dt; //angle en radian

}


void freeBullet(Bullet *A)
{
	int i;
	for(i=0; i<NBRE_SPRITE_BULLET; i++)
		SDL_FreeSurface(A->image[i]);
}
