#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "enigmes.h"


int ResolutionEniges(enigmes ES,int IndiceEnigme,char an[])
{int reponse=0,i;
char NomFichier[]="FichierReponse.txt";
char rep[400];
FILE *FICHIER;


FICHIER = fopen(NomFichier, "r+");
for (i=0;i<=IndiceEnigme;i++)
{
    fscanf (FICHIER, "%s \n", rep);
}
fclose(FICHIER);


if (strcmp(an,rep)==0)
{
    reponse=1;
}


return reponse ;
}


