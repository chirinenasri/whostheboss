//#include "scrolling.h"
#include <SDL/SDL_image.h> 
#include <SDL/SDL.h>
//#include "defs.h"
#include "fichier.h"


void scrollright(background *B1, persoprincipal *p1) 
{  
 if (p1->positionpp.x>=150)
					{
					p1->positionpp.x=150;
                    B1->positionbg.x=B1->positionbg.x+5;
						} 
                               // B1->back_Pos.x=B1->back_Pos.x+5;
}


void scrollleft(background *B1,persoprincipal *p1) 
{  
 //B1->back_Pos.x=B1->back_Pos.x-5;
 if (p1->positionpp.x<=140)
					{
					p1->positionpp.x=140;
                    B1->positionbg.x=B1->positionbg.x-5;
						} 
}



void scrollup(background *B1,persoprincipal *p1) 
{  
 if (p1->positionpp.y<=150)
					{
					p1->positionpp.y=150;
                    B1->positionbg.y=B1->positionbg.y-5;
						} 
 //B1->back_Pos.y=B1->back_Pos.y-5;
}



void scrolldown(background *B1,persoprincipal *p1) 
{  
 if (p1->positionpp.y>=200)
					{
					p1->positionpp.y=200;
                    B1->positionbg.y=B1->positionbg.y+5;
						} 
                               // B1->back_Pos.y=B1->back_Pos.y+5;
}


void scrollright2(background *B1,persoprincipal *p1) 
{  
 if (p1->positionpp.x>=700)
					{
					p1->positionpp.x=700;
                    B1->positionbg.x=B1->positionbg.x+5;
						} 
                               // B1->back_Pos.x=B1->back_Pos.x+5;
}


void scrollleft2(background *B1,persoprincipal *p1) 
{  
 //B1->back_Pos.x=B1->back_Pos.x-5;
 if (p1->positionpp.x<=400)
					{
					p1->positionpp.x=400;
                    B1->positionbg.x=B1->positionbg.x-5;
						} 
}



void scrollup2(background *B1,persoprincipal *p1) 
{  
 if (p1->positionpp.y<=0)
					{
					p1->positionpp.y=0;
                    B1->positionbg.y=B1->positionbg.y-5;
						} 
 //B1->back_Pos.y=B1->back_Pos.y-5;
}



void scrolldown2(background *B1,persoprincipal *p1) 
{  
 if (p1->positionpp.y>=450)
					{
					p1->positionpp.y=450;
                    B1->positionbg.y=B1->positionbg.y+5;
						} 
                               // B1->back_Pos.y=B1->back_Pos.y+5;
}







