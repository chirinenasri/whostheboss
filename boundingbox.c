#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "fichier.h"

int boundingbox (SDL_Rect positionpp, entitesecondaire *obj)
{int collision=0; 

if ((positionpp.x + positionpp.w < obj->positionobj2.x) || (positionpp.x > obj->positionobj2.x + obj->positionobj2.w) || (positionpp.y + positionpp.h < obj->positionobj2.y ) || (positionpp.y > obj->positionobj2.y + obj->positionobj2.h))
collision = 0;
else {collision =1;}

return collision;
}

int boundingbox2 (SDL_Rect positionpp, entitesecondaire *obj)
{int collision=0; 

if ((positionpp.x + positionpp.w < obj->positionobj1.x) || (positionpp.x > obj->positionobj1.x + obj->positionobj1.w) || (positionpp.y + positionpp.h < obj->positionobj1.y ) || (positionpp.y > obj->positionobj2.y + obj->positionobj1.h))
collision = 0;
else {collision =1;}

return collision;
}
