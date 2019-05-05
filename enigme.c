#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enigmes.h"

int afficher_enigmes(enigmes* ES,SDL_Surface *fenetre)
{int i=0;srand(time(NULL));
i=rand()%(ES->nbenigmes);
SDL_BlitSurface(ES->E[i].answer[1],NULL,fenetre,&ES->E[0].posans1);
SDL_BlitSurface(ES->E[i].answer[2],NULL,fenetre,&ES->E[0].posans2); 
SDL_BlitSurface(ES->E[i].answer[3],NULL,fenetre,&ES->E[0].posans3);
SDL_BlitSurface(ES->E[i].texte,NULL,fenetre,&ES->E[0].postxt);
return i;
}


void initialiser_enigmes(enigmes *ES)
{
TTF_Init();
TTF_Font *police ;
int i,j;
police = TTF_OpenFont("Indy Women.ttf",54 );
char txt[400],an1[400],an2[400],an3[400];
SDL_Color couleurBlanc = {29, 156, 4 };
char NOM_FICH[] = "e.txt" ;

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

int ResolutionEniges(enigmes ES,int IndiceEnigme,char an[])
{int reponse=0;int i;
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


void enigmi()
{SDL_Init (SDL_INIT_VIDEO);
char NOM_FICH[] = "e.txt" ;
int continuer=1,reponse=-1,IndiceEnigme,j,i;
TTF_Font *shine ;
TTF_Font *not ;
char txt[400],an1[400],an2[400],an3[400];
   SDL_Surface *fenetre;
   SDL_Surface *background;
    SDL_Color fontblack={0,0,0};
    SDL_Color fontred={ 255, 0, 0 };
    SDL_Color fontgreen={0,255,0};
    SDL_Color fontbleu={0,0,255};
   SDL_Event event;
enigmes ES;

   fenetre=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE);
   SDL_Rect positionbg;
   positionbg.x=0;
   positionbg.y=0;

          if (SDL_Init(SDL_INIT_VIDEO))
   {
       fprintf (stderr,"ERROR %s",SDL_GetError());
   }

   background=IMG_Load ("images.jpeg");
   SDL_BlitSurface(background,NULL,fenetre,&positionbg);
   SDL_Flip(fenetre);
  initialiser_enigmes(&ES);
IndiceEnigme=afficher_enigmes(&ES,fenetre);

///////////////////////////////////////////////

FILE *FICHIER;
FICHIER = fopen(NOM_FICH, "r+");
  if (!FICHIER)
     {  
      printf("\aERREUR: Impossible d'ouvrir "
             "le fichier: %s.\n", NOM_FICH);
      exit(-1);
     }

for(i=0;i<=IndiceEnigme;i++)
{
fscanf (FICHIER, "%s %s %s %s\n", txt, an1, an2, an3);
}
fclose(FICHIER);    

///////////////////////////////////////////////

   while (continuer!=0&&reponse==-1)
{;
 SDL_WaitEvent(&event);
       switch(event.type)
       {

          case SDL_QUIT:

               continuer = 0;

          break;
          
         case SDL_KEYDOWN:
         switch (event.key.keysym.sym)
         {
          case SDLK_ESCAPE:
            continuer=0;
          break;

          case SDLK_UP:
          if (continuer==1)
          {
       not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(shine,an1,fontbleu);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(not,an2,fontred);
    ES.E[IndiceEnigme].answer[3]=TTF_RenderText_Solid(not,an3,fontred); 
     SDL_BlitSurface(background,NULL,fenetre,&positionbg);
     SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2); 
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[3],NULL,fenetre,&ES.E[0].posans3);
     SDL_Flip (fenetre);
     i=1;
     continuer=3;
          }
     else if (continuer==2)
          {
        not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
     SDL_BlitSurface(background,NULL,fenetre,&positionbg);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(not,an1,fontred);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(shine,an2,fontbleu);
    ES.E[IndiceEnigme].answer[3]=TTF_RenderText_Solid(not,an3,fontred); 
    SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2); 
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[3],NULL,fenetre,&ES.E[0].posans3);
     SDL_Flip (fenetre);
     i=2;
     continuer=1;
          }
     else if (continuer==3)
          {
        not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(not,an1,fontred);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(not,an2,fontred);
    ES.E[IndiceEnigme].answer[3]=TTF_RenderText_Solid(shine,an3,fontbleu); 
       SDL_BlitSurface(background,NULL,fenetre,&positionbg);
      SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2); 
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[3],NULL,fenetre,&ES.E[0].posans3);
     SDL_Flip (fenetre);
     i=3;
     continuer=2;
          }
          break;

          case SDLK_DOWN:
          if (continuer==1)
          {
        not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(shine,an1,fontbleu);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(not,an2,fontred);
    ES.E[IndiceEnigme].answer[3]=TTF_RenderText_Solid(not,an3,fontred); 
       SDL_BlitSurface(background,NULL,fenetre,&positionbg);
       SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2); 
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[3],NULL,fenetre,&ES.E[0].posans3);
     SDL_Flip (fenetre);
     i=1;
     continuer=2;
          }
     else if (continuer==2)
          {
        not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
     SDL_BlitSurface(background,NULL,fenetre,&positionbg);
SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(not,an1,fontred);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(shine,an2,fontbleu);
    ES.E[IndiceEnigme].answer[3]=TTF_RenderText_Solid(not,an3,fontred); 
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2); 
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[3],NULL,fenetre,&ES.E[0].posans3);
     SDL_Flip (fenetre);
     i=2;
     continuer=3;
          }
     else if (continuer==3)
          {
          not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(not,an1,fontred);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(not,an2,fontred);
    ES.E[IndiceEnigme].answer[3]=TTF_RenderText_Solid(shine,an3,fontbleu); 
       SDL_BlitSurface(background,NULL,fenetre,&positionbg);
       SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2); 
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[3],NULL,fenetre,&ES.E[0].posans3);
     SDL_Flip (fenetre);
     i=3;
     continuer=1;
          }
            break;

     case SDLK_RETURN :
          switch (i)
          {
              case 1 :
reponse=ResolutionEniges(ES,IndiceEnigme,an1);
              break;
              case 2:
reponse=ResolutionEniges(ES,IndiceEnigme,an2);
              break;
              case 3:
reponse=ResolutionEniges(ES,IndiceEnigme,an3);
              break;
          }
          break;
         }         
       }
}

if (reponse==1)
{ SDL_Flip (fenetre);
printf ("\nbravo\n");
}
else
{ 
  printf ("\nperdu\n");

}

}
