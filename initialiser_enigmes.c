#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "enigmes.h"

void initialiser_enigmes(enigmes *ES)
{
TTF_Init();
TTF_Font *police ;
int i,j;
police = TTF_OpenFont("Indy Women.ttf",54 );
char txt[400],an1[400],an2[400],an3[400];
SDL_Color couleurBlanc = {29, 156, 4 };
char NOM_FICH[] = "ENIGME.TXT" ;

///////saisire nombre enigme /////
ES->nbenigmes=4;


for(i=0;i<ES->nbenigmes;i++)
{
ES->E[i].postxt.x=52;
ES->E[i].postxt.y=66;
ES->E[i].posans1.x=172;
ES->E[i].posans1.y=204;
ES->E[i].posans2.x=172;
ES->E[i].posans2.y=297;
ES->E[i].posans3.x=172;
ES->E[i].posans3.y=390;
}

FILE *FICHIER;
FICHIER = fopen(NOM_FICH, "r+");
  if (!FICHIER)
     {  
      printf("\aERREUR: Impossible d'ouvrir "
             "le fichier: %s.\n", NOM_FICH);
      exit(-1);
     }

for(i=0;i<ES->nbenigmes;i++)
{
fscanf (FICHIER, "%s %s %s %s\n", txt, an1, an2, an3);

for(j=0;j<strlen(txt);j++)
{
  if (txt[j]=='_')
  {
txt[j]=' ';
  }
}

for(j=0;j<strlen(an1);j++)
{
  if (an1[j]=='_')
  {
an1[j]=' ';
  }
}


for(j=0;j<strlen(an2);j++)
{
  if (an2[j]=='_')
  {
an2[j]=' ';
  }
}

for(j=0;j<strlen(an3);j++)
{
  if (an3[j]=='_')
  {
an3[j]=' ';
  }
}

ES->E[i].texte     = TTF_RenderText_Blended(police,txt, couleurBlanc);
ES->E[i].answer[1] = TTF_RenderText_Blended(police,an1, couleurBlanc);
ES->E[i].answer[2] = TTF_RenderText_Blended(police,an2, couleurBlanc);
ES->E[i].answer[3] = TTF_RenderText_Blended(police,an3, couleurBlanc);
}
fclose(FICHIER);
}

