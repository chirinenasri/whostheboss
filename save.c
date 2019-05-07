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
void SaveGame(char* nomFich,persoprincipal p,background b,score score,vie heal)
{
FILE* f=NULL;
f=fopen(nomFich,"w");
fprintf(f,"%d %d %d %hd %hd\n",score.sc,heal.nb,b.sens,p.positionpp.x,p.positionpp.y);
fprintf(f,"%hd %hd\n",b.positionbg.x,b.positionbg.y);
fclose(f);
}
/*-----------------------------------------------------------------------------------------*/
void LoadGame(char* nomFich,persoprincipal *p,background* b,score* score,vie *heal)
{
FILE* f=NULL;
f=fopen(nomFich,"r");
fscanf(f,"%d %d %d %hd %hd\n",&score->sc,&heal->nb,&b->sens,&p->positionpp.x,&p->positionpp.y);
fscanf(f,"%hd %hd\n",&b->positionbg.x,&b->positionbg.y);
fclose(f);
}
void SaveGamestage(char* nomFich,int x)
{
FILE* f=NULL;
f=fopen(nomFich,"w");
fprintf(f,"%d \n",x);
fclose(f);
}
void LoadGamestage(char* nomFich,int *x)
{
FILE* f=NULL;
f=fopen(nomFich,"r");
fscanf(f,"%d \n",x);
fclose(f);
}
