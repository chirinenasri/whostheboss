#include "main.h"
#include "instructions.h"
#include "option.h"
#include "quit.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "fichier.h"

int main ( int argc, char** argv )
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen=NULL;
    SDL_Surface *background=NULL;
    buttons b;
    screen=SDL_SetVideoMode (800,600,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("limitless",NULL);//titre de la fenetre
    SDL_WarpMouse(screen->w / 2, screen->h / 2);
    SDL_EnableKeyRepeat(100,100);
    background =SDL_LoadBMP("bg.bmp");
    SDL_Rect background_pos;
    SDL_Rect pxy,pxin,pxset,pxexit;
    SDL_Event event;
    int z;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
{printf("%s", Mix_GetError());}
Mix_Music *music;
music=Mix_LoadMUS("2.mp3");
Mix_PlayMusic(music, -1);


    background_pos.x=0;
    background_pos.y=0;
    pxy.x=500;
    pxy.y=10;

    pxin.x=500;
    pxin.y=170;

    pxset.x=500;
    pxset.y=320;

    pxexit.x=500;
    pxexit.y=435;
 //pxy.x=328;
    //pxy.y=443;
/*pxy.x=500;
    pxy.y=10;

 
    pxin.x=328;
    pxin.y=481;

    pxset.x=328;
    pxset.y=519;
 
    pxexit.x=328;
    pxexit.y=557;*/
    int pp=2,op=0,ex=0,ins=0,t;
    int done=1;
    int motion=330;
    b.play[0]=SDL_LoadBMP("1.bmp");
    b.play[1]=SDL_LoadBMP("play.bmp");
    //b.play[2]=SDL_LoadBMP("play2.bmp");
    b.instructions[0]=SDL_LoadBMP("3.bmp");
    b.instructions[1]=SDL_LoadBMP("sans titre.bmp");
   // b.instructions[2]=SDL_LoadBMP("instructions2.bmp");
    b.setting[0]=SDL_LoadBMP("2.bmp");
    b.setting[1]=SDL_LoadBMP("set.bmp");
    b.setting[2]=SDL_LoadBMP("setting2.bmp");
    b.exit[0]=SDL_LoadBMP("4.bmp");
    b.exit[1]=SDL_LoadBMP("ex.bmp");
    b.exit[2]=SDL_LoadBMP("exit2.bmp");

while (done!=0)
    {
        SDL_BlitSurface(background,NULL,screen,NULL);
        SDL_BlitSurface(b.play[pp],NULL,screen,&pxy);
        SDL_BlitSurface(b.instructions[ins],NULL,screen,&pxin);
        SDL_BlitSurface(b.setting[op],NULL,screen,&pxset);
        SDL_BlitSurface(b.exit[ex],NULL,screen,&pxexit);
        SDL_Flip(screen);
        t=0;
        if (SDL_WaitEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT :
                if (quit(screen)==1)
                    done=0;
                break;
            case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                   if (quit(screen)==1)
                        done=0;
                    break;
                case SDLK_UP:
                    if (pp==1 && t==0)
                    {
                        ex=1;
                        pp=0;
                        op=0;
                        ins=0;
                        t=1;
                    }
                    else if(ins==1 && t==0)
                    {
                        pp=1;
                        op=0;
                        ex=0;
                        ins=0;
                        t=1;
                    }
                    else if (op==1 && t==0)
                    {
                        ins=1;
                        ex=0;
                        pp=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    {
                        op=1;
                        ex=0;
                        pp=0;
                        ins=0;
                        t=0;
                    }
                    break;
                case SDLK_DOWN:
                    if (pp==1 && t==0)
                    {
                        ins=1;
                        ex=0;
                        op=0;
                        pp=0;
                        t=1;
                    }
                    else if(ins==1 && t==0)
                    {
                        pp=0;
                        op=1;
                        ex=0;
                        ins=0;
                        t=1;
                    }
                    else if (op==1 && t==0)
                    {
                        ex=1;
                        pp=0;
                        ins=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    {
                        pp=1;
                        op=0;
                        ins=0;
                        ex=0;
                        t=1;
                    }
                    break;
                case SDLK_RETURN:
                    if (pp==1)
                    {
                        SDL_BlitSurface(b.play[2],NULL,screen,&pxy);
                        SDL_Flip(screen);
                        //SDL_Delay(200);
                        //return NEW_GAME;
                    }
                    else if (ins==1)
                    {
                         SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                      instructions(screen);
                       ins=0;

                        //SDL_Delay(200);

                        //return OPTION;
                    }
                    else if (op==1)
                    {
                        SDL_BlitSurface(b.setting[2],NULL,screen,&pxset);
                        SDL_Flip(screen);
                        SDL_Delay(200);
                        option(screen);
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                    if (quit(screen)==1)
                            done=0;
                        //SDL_Delay(200);
                    }
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                ex=0;
                pp=0;
                op=0;
                t=0;
 //printf("%d,%d\n",event.motion.x,event.motion.y);
               // if ((event.motion.x>motion)&&(event.motion.y>motion+117)&&(event.motion.x<motion+131)&&(event.motion.y<motion+145) && (t==0) && (pp==0))
               if ((event.motion.x>500) && (event.motion.y>30) && (event.motion.x<700) && (event.motion.y<170)&& (t==0) && (pp==0))
 {
                    pp=1;
                    ex=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                else if ((event.button.x>500)&&(event.button.x<700)&&(event.button.y>320)&&(event.button.y<400) &&(t==0)&& (ins==0))
                {
                    ex=0;
                    pp=0;
                    //ins=1;
ins=0; 
                    op=1;
                    t=1;
                }
                else if ((event.motion.x>500) && (event.motion.y>180) && (event.motion.x<700) && (event.motion.y<300)&&(t==0)&& (op==0))
                {
                    ex=0;
                    pp=0;
                    ins=1;
                    op=0;
                    t=1;
                }
                else if ((event.button.x>500)&&(event.button.x<700)&&(event.button.y>450)&&(event.button.y<600)&&(t==0)&& (ex==0))
                {
                    ex=1;
                    pp=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    //if ((event.motion.x>motion) && (event.motion.y>motion+117) && (event.motion.x<motion+131) && (event.motion.y<motion+145)&&(pp==1))
                          if ((event.motion.x>500) && (event.motion.y>30) && (event.motion.x<700) && (event.motion.y<170)&&(pp==1))
                    {
                        pp=2;
//if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
//{printf("%s", Mix_GetError());}
Mix_Music *music;
music=Mix_LoadMUS("g.mp3");
Mix_PlayMusic(music, -1);
z=move();


                        //SDL_Delay (200);
                        //play(screen);
                        //return NEW_GAME;
                    }
                    else if ((event.button.x>500)&&(event.button.x<700)&&(event.button.y>320)&&(event.button.y<400)&&(ins==1))
                    {Mix_Music *music;
music=Mix_LoadMUS("g.mp3");
Mix_PlayMusic(music, -1);


                        SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                        instructions(screen);
                       //ins=0;



                        //SDL_Delay (200);
                        //return OPTION;
                    }//Mix_CloseAudio();
                    else if ((event.motion.x>500) && (event.motion.y>180) && (event.motion.x<700) && (event.motion.y<300)&&(op==1))
                    {
                        op=2;
                        option(screen);
                        //SDL_Delay (200);
                        //return OPTION;
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                        //SDL_Delay (200);
                        if (quit(screen)==1)
                            done=0;

                    }
                }
                break;
            }
        }
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.instructions[2]);
Mix_CloseAudio();Mix_CloseAudio();
    SDL_Quit();
    return 0 ;
    }
void cleanmenu(SDL_Surface *background)
{
    buttons b;
    SDL_FreeSurface(background);
    SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.instructions[2]);

}
