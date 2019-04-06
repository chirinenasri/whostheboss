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

int boundingbox (persoprincipal *pp, entitesecondaire *obj)
{int collision=0; 

if ((pp->positionpp.x + pp->positionpp.w < obj->positionobj1.x) || (pp->positionpp.x > obj->positionobj1.x + obj->positionobj1.w) || (pp->positionpp.y + pp->positionpp.h < obj->positionobj1.y ) || (pp->positionpp.y > obj->positionobj1.y + obj->positionobj1.h))
collision = 0;
else {collision =1;}

return collision;
}
