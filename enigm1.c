#include"fichier.h"



int  enigme()


{   
 int occ(int tab[],int x)

{ int i,occ=0;
 
   for(i=0;i<6;i++)
   
 {
        if (tab[i]==x)
            occ++;
 
   }
    return occ;
}
   
 SDL_Surface *ecran = NULL , *fond = NULL , *rectange[4] ,*start=NULL;
  
  int x=20,y=10;

    
SDL_Rect position1 ,position2,position3,position4,position5,position6,positionstart;
    
position1.x=147+x; 
position2.x=347+x; 
position3.x=547+x; 
 position4.x=147+x;
 position5.x=347+x;
position6.x=547+x,positionstart.x=350+x;
   
 position1.y=126+y;
position2.y=126+y;
position3.y=126+y;
position4.y=326+y;
position5.y=326+y;
position6.y=326+y;
positionstart.y=10+y;
    SDL_Rect positiont;

    positiont.x=0;
   
 positiont.y=0;
   
 int num;
   
 int continuer = 1,done=1;
 
   int i,nombre = 0;
int j;
   
 const int MIN = 1, MAX = 6;
   
 int tab[6],tab1[6];
        
char n[30];
 	
SDL_Init(SDL_INIT_VIDEO);
 // Initialisation de la SDL

	ecran=SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
 // Ouverture de la fenêtre
   
 	SDL_WM_SetCaption("Menu", NULL);
  

	fond=IMG_Load("fond.png");   
	
start=IMG_Load("start.png");
  
	SDL_BlitSurface(fond,NULL,ecran,&positiont);
	
SDL_BlitSurface(start,NULL,ecran,&positionstart);
	
SDL_Flip(ecran);
	
	
  
  srand(time(NULL));
 // Initialisation de la donnée seed
    nombre = (rand() % (MAX + 1 - MIN)) + MIN;
 // MIN <= nombre <= MAX
    tab[0]=nombre ;
for(i=1;i<5;i++)
{
    sprintf(n,"%d.png",i);
   
 rectange[i]=IMG_Load(n);
}

num=(rand() % (4)) +1;
   
 
   for (i=1; i<6; i++)
   
 {
        nombre = (rand() % (MAX + 1 - MIN)) + MIN;

   
     if(occ(tab, nombre )==0)
       
 {
            tab[i]=nombre;
        }
       
 else
            i--;

    }
   
 SDL_Event event;

		
while (done)

    
{

        SDL_WaitEvent(&event);

   
     switch(event.type)

      
  {

            case SDL_QUIT:

        
        continuer = 0;

             
   break;

            
             
   
     case SDL_MOUSEBUTTONUP:


if (event.button.button == SDL_BUTTON_LEFT && event.motion.x > positionstart.x && event.motion.x < positionstart.x+100 && event.motion.y> positionstart.y &&  event.motion.y < positionstart.y+100)
done = 0;
}}
	
	

		for (j=0;j<6;j++)

		{
		
switch(tab[j])
		
{
		case 1:
		
		
SDL_BlitSurface(rectange[num],NULL,ecran,&position1);
		
SDL_Flip(ecran);
		
		
break;
		
case 2:
		
SDL_BlitSurface(rectange[num],NULL,ecran,&position2);
		
SDL_Flip(ecran);
		
break;
		
case 3:
		
SDL_BlitSurface(rectange[num],NULL,ecran,&position3);
		
SDL_Flip(ecran);
		
break;
		
case 4:
		
SDL_BlitSurface(rectange[num],NULL,ecran,&position4);
		
SDL_Flip(ecran);
		break;
		
case 5:
		
SDL_BlitSurface(rectange[num],NULL,ecran,&position5);
		
SDL_Flip(ecran);
		break;
		
case 6:
		
SDL_BlitSurface(rectange[num],NULL,ecran,&position6);
		
SDL_Flip(ecran);
		
break;
		}


SDL_Delay(800);
	}


 
SDL_BlitSurface(fond,NULL,ecran,&positiont);


SDL_Flip(ecran);

int k=0;
   
SDL_Flip(ecran); 
//Mise à jour de l'écran 
   
SDL_EnableKeyRepeat(20, 20); 
	
while (continuer)

    
{

        SDL_WaitEvent(&event);

        
switch(event.type)

        
{

            
case SDL_QUIT:

                
continuer = 0;

                
break;

            
             
        
case SDL_MOUSEBUTTONUP: 


if (event.button.button == SDL_BUTTON_LEFT && event.motion.x > position1.x && event.motion.x < position1.x+150 && event.motion.y> position1.y &&  event.motion.y < position1.y+150)
   
        
{
SDL_BlitSurface(rectange[num],NULL,ecran,&position1);
 
SDL_Flip(ecran);
tab1[k]=1;
k++;
}

if (event.button.button == SDL_BUTTON_LEFT && event.motion.x > position2.x && event.motion.x < position2.x+150 && event.motion.y> position2.y &&  event.motion.y < position2.y+150)
 
           
{
SDL_BlitSurface(rectange[num],NULL,ecran,&position2);

 SDL_Flip(ecran);
tab1[k]=2;
k++;
}

if (event.button.button == SDL_BUTTON_LEFT && event.motion.x > position3.x && event.motion.x < position3.x+150 && event.motion.y> position3.y &&  event.motion.y < position3.y+150)
    
        
{
SDL_BlitSurface(rectange[num],NULL,ecran,&position3);
 
SDL_Flip(ecran);
tab1[k]=3;
k++;
}


if (event.button.button == SDL_BUTTON_LEFT && event.motion.x > position4.x && event.motion.x < position4.x+150 && event.motion.y> position4.y &&  event.motion.y < position4.y+150)
  
          
{
SDL_BlitSurface(rectange[num],NULL,ecran,&position4);
 
SDL_Flip(ecran);
tab1[k]=4;
k++;
}


if (event.button.button == SDL_BUTTON_LEFT && event.motion.x > position5.x && event.motion.x < position5.x+150 && event.motion.y> position5.y &&  event.motion.y < position5.y+150)
 
           
{
SDL_BlitSurface(rectange[num],NULL,ecran,&position5);
 
SDL_Flip(ecran);
tab1[k]=5;
k++;
}


if (event.button.button == SDL_BUTTON_LEFT && event.motion.x > position6.x && event.motion.x < position6.x+150 && event.motion.y> position6.y &&  event.motion.y < position6.y+150)
  
          
{
SDL_BlitSurface(rectange[num],NULL,ecran,&position6);

 SDL_Flip(ecran);
tab1[k]=6;
k++;
}
        } 

 
}

Background b;

b.stage=2;
int verif=1;

for (k=0;k<i;k++)

{
if (tab[k]!=tab1[k])
verif=0;
}

 

if (verif==0)

return 0;

else
return 1;
        

 
SDL_FreeSurface(fond);
 
//SDL_FreeSurface(rectange);

 
main();
 
SDL_Quit(); 
// Arrêt de la SDL

   EXIT_SUCCESS;
 // Fermeture du programme


}

