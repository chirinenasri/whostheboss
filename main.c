#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "animation.h"
int main(int argc, char *argv[])
{int done =1;
char pause();
SDL_Surface *ecran=NULL, *background = NULL;
perso p1;
int test;

SDL_Event event;
int keysHeld[323] = {0};
 SDL_Rect positionbackground;
positionbackground.x=0;
positionbackground.y=0;
init_perso(&p1) ;
background=IMG_Load("bkp.png");
loadimg(&p1);

SDL_Init (SDL_INIT_VIDEO);
ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_BlitSurface (background,NULL,ecran,&positionbackground);

//displayperso(p1,ecran,test);
//updateperso(&p1,ecran, test);

//displayperso(p1,ecran,test);
SDL_Flip(ecran);
while(done)
{
if (SDL_PollEvent(&event))
  { switch (event.type)
    { case SDL_KEYDOWN : 

keysHeld[event.key.keysym.sym] = 1;
break;
case SDL_KEYUP:
keysHeld[event.key.keysym.sym] = 0;
break;
default:
;
}
if (keysHeld[SDLK_ESCAPE])
done = 1;
/*if(event.key.keysym.sym==SDLK_RIGHT)
{
//test=1;

displayperso(p1,ecran,test);
updateperso(&p1,ecran, test);
SDL_BlitSurface (background,NULL,ecran,&positionbackground);
displayperso(p1,ecran,test);
SDL_Flip(ecran);

}*/


if(keysHeld[SDLK_RIGHT])
{

test=2;

//displayperso(p1,ecran,test);
updateperso(&p1,ecran, test);
//displayperso(p1,ecran,test);
SDL_BlitSurface (background,NULL,ecran,&positionbackground);
displayperso(p1,ecran,test);
SDL_Flip(ecran);

}


/*if(event.key.keysym.sym==SDLK_UP)
{
 //test=4;

displayperso(p1,ecran,test);
updateperso(&p1,ecran, test);
SDL_BlitSurface (background,NULL,ecran,&positionbackground);
displayperso(p1,ecran,test);
SDL_Flip(ecran);

}

if(event.key.keysym.sym==SDLK_DOWN)
{

test=3;

displayperso(p1,ecran,test);
updateperso(&p1,ecran, test);
SDL_BlitSurface (background,NULL,ecran,&positionbackground);
displayperso(p1,ecran,test);
SDL_Flip(ecran);
}*/
}
}
//}
//SDL_BlitSurface(image,NULL, screen, &positionecran);
pause();
perso_freeperso1(&p1) ;
SDL_FreeSurface (background);
SDL_Flip(ecran);

SDL_Quit();
return (0);
}
