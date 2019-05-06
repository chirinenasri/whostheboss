#include <SDL/SDL.h>

#include "defs.h"
#include "background.h"
#include "voiture.h"
#include "bullet.h"
#include "jeu.h"
#include "text.h"

int jouer(SDL_Surface * screen)
{
	int done = 0;
	int i=0;
	Voiture car;
	Background Backg;
	Bullet bullet;
	SDL_Event event;
	int keysHeld[323] = {0}; // everything will be initialized to false
	long ret;
	Uint32 t_prev,dt=1;
	SDL_Color couleur= {255,0,0};
	Text txt;
	TTF_Font *police = NULL;


	if(loadVoitureImages(&car) == -1) {
		printf("Erreuer Chargement Voiture Images\n");
		return(-1);

	}

	if(loadBackground(&Backg) == -1) {
		printf("Erreuer Chargement Background Images\n");
		return(-1);
	}
	if(loadBulletImages(&bullet) == -1) {
		printf("Erreuer Chargement Bullet Images\n");
		return(-1);
	}

	if(loadFont(&police) == EXIT_FAILURE) {
		printf("Erreuer Chargement Font ttf\n");
		return(-1);
	}

	initBackground(&Backg);
	initVoiture(&car);
	initBullet(&bullet,car);
	initText(&txt);

	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) {

		t_prev = SDL_GetTicks();

		if(car.velocity>0) { //when moving
			car.acceleration+=0.005 ;//frottement + vent
			i+=1;
			car.moving=1;
		}

		if(car.velocity <0) {
			car.acceleration=0;
			car.velocity=0;
			car.moving=0;
		}

		while (SDL_PollEvent(&event)) {
			// check for messages
			switch (event.type) {
				// exit if the window is closed
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				car.moving=1; //lets move
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
                                car.moving=0;
				car.velocity=0;
				break;
			default:
				;
			}

		} // end of message processing

		// exit if ESCAPE is pressed
		if (keysHeld[SDLK_ESCAPE])
			done = 1;
		if(keysHeld[SDLK_RIGHT]) { //accelerate
			car.acceleration+=0.00100;
                               car.velocity=5;
				car.direction=0; //right direction
				deplacerVoiture(&car,&Backg,dt);
				i++;
                       
		}
		if(keysHeld[SDLK_SPACE] && car.velocity >0) { //brake
			car.acceleration-=0.99;
		}
		if(keysHeld[SDLK_RETURN] ) {
			car.fire=1;
		}

		/*
		 * car is moving
		 * */

		i=i%4;

		blitBackground(&Backg,screen);
		if(!car.moving)
			i=0;


		if(car.direction == 0)
			SDL_BlitSurface(car.image[i],NULL,screen,&car.position);


		if(car.fire) {
			if(bullet.position.y > 0) { //Fire
				deplacerBullet(&bullet,Backg,car,1);
				SDL_BlitSurface(bullet.image[0],NULL,screen,&bullet.position);
			} else {
				initBullet(&bullet,car);
				car.fire=0;
			}
		}

		displayText(police,&txt,screen,car,Backg,dt);

		//clean screen &&
		//Flip the backbuffer to the primary Hardware Video Memory

		SDL_Flip(screen);

		dt=(SDL_GetTicks()-t_prev);

		if(1000/FPS > SDL_GetTicks() - t_prev)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - t_prev)); //to a constant FPS

	}


// free loaded bitmap

	freeVoiture(&car);
	freeBackground(&Backg);
	freeBullet(&bullet);
	TTF_CloseFont(police);

	return(0);
}
