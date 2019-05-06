#include "background.h"

int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg = SDL_LoadBMP("../images/background.bmp");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}

	Backg->backgroundCollide = SDL_LoadBMP("../images/background2.bmp");
	if (Backg->backgroundCollide == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}
	return (0);
}


void initBackground(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=150;
	Backg->backgroundPos.w=SCREEN_W;
	Backg->backgroundPos.h=SCREEN_H;

       Backg->backgroundPos2.x=0;
	Backg->backgroundPos2.y=-320;
	Backg->backgroundPos2.w=SCREEN_W;
	Backg->backgroundPos2.h=SCREEN_H;
}

void blitBackground(Background*Backg,SDL_Surface *screen)
{
	//Blit the bachground to the backbuffer
	if(Backg->backgroundPos.x > Backg->backgroundImg->w-SCREEN_W)
		Backg->backgroundPos.x=0;
	if(Backg->backgroundPos.x < 0)
		Backg->backgroundPos.x=Backg->backgroundImg->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); //scrolling horizontal

//Blit the bachground to the backbuffer
	if(Backg->backgroundPos2.x > Backg->backgroundCollide->w-SCREEN_W)
		Backg->backgroundPos2.x=0;
	if(Backg->backgroundPos2.x < 0)
		Backg->backgroundPos2.x=Backg->backgroundCollide->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundCollide, &(Backg->backgroundPos2), screen,NULL); //scrolling horizontal

}

void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
	//SDL_FreeSurface(Backg->backgroundCollide);
}
