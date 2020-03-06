#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main(void)
{

// initialisation des variable
    SDL_Surface *screen;
    SDL_Surface *texte;
    SDL_Surface *background;
    SDL_Rect positionecran;
    SDL_Surface *backoption;
    SDL_Rect positionbackoption;
      //------------------//

    SDL_Surface *newgame;
    SDL_Surface *newgamemotion;
    SDL_Surface *continu;
    SDL_Surface *continumotion;
    SDL_Surface *option;
    SDL_Surface *optionmotion;
    SDL_Surface *exit;
    SDL_Surface *exitmotion;
    
     //------------------//
    
	
    SDL_Rect positionfullson;
    SDL_Rect positionfullsoff;
    SDL_Rect positionnewgame;
    SDL_Rect positioncontinu;
    SDL_Rect positionoption;   
    SDL_Rect positionexit;
    SDL_Surface *backtomenu;
     SDL_Surface *backtomenumotion;
     //------------------//

    SDL_Surface *bar1;
    SDL_Surface *bar2;
    SDL_Surface *bar3;
    SDL_Surface *bar4;
    SDL_Surface *bar5;
    SDL_Surface *plus;
    SDL_Surface *plus1;
    SDL_Surface *mois;
    SDL_Surface *mois1;
    SDL_Rect positionpoint;
    SDL_Rect positionbacktomenu;
    SDL_Rect positionplus;
    SDL_Rect positionplus1;
    SDL_Rect positionmois;
    SDL_Rect positionmois1;
    SDL_Rect positionpoint2;
    SDL_Rect positionon;
    SDL_Rect positiontexte;
    SDL_Surface *fenetre;
    SDL_Surface *on;
    SDL_Surface *off;
    SDL_Surface *new;

      //------------------//


    Mix_Chunk *son;
    Mix_Music *music;
       //------------------//
    int x, y;
    int position=3;
    char pause;
    int a,b;
    int r=0;
    int j=0,i=1;
    SDL_Event event;
    SDL_Event event2;
     int volume=1;
     int sound=1;

SDL_Surface *tabanim[20]; //tableau des images pour l'animation



 /*le tableau des images */

tabanim[1]=IMG_Load("1.png");
tabanim[2]=IMG_Load("2.png");
tabanim[3]=IMG_Load("3.png");
tabanim[4]=IMG_Load("4.png");
tabanim[5]=IMG_Load("5.png");
tabanim[6]=IMG_Load("6.png");
tabanim[7]=IMG_Load("7.png");
tabanim[8]=IMG_Load("8.png");
tabanim[9]=IMG_Load("9.png");
tabanim[10]=IMG_Load("10.png");
tabanim[11]=IMG_Load("11.png");
tabanim[12]=IMG_Load("12.png");
tabanim[13]=IMG_Load("13.png");
tabanim[14]=IMG_Load("14.png");
tabanim[15]=IMG_Load("15.png");
tabanim[16]=IMG_Load("16.png");
tabanim[17]=IMG_Load("17.png");
tabanim[18]=IMG_Load("18.png");
tabanim[19]=IMG_Load("19.png");
tabanim[20]=IMG_Load("20.png");



TTF_Font *police = NULL;
SDL_Color couleur= {255,150, 0};

/* Chargement de la police */
    TTF_Init();
    police = TTF_OpenFont("CHICORY_.TTF",15);


/* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    
texte = TTF_RenderText_Blended(police,"INVICTUS",couleur);
        
        positiontexte.x = 310;
        positiontexte.y = 30;


 // musique
    if ( Mix_OpenAudio ( 44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) == -1 )
    {
        printf ( " %s", Mix_GetError());
    }
    Mix_AllocateChannels(1);
    music= Mix_LoadMUS("music.wav");
    Mix_PlayMusic(music,-1);

 //sound
    son = Mix_LoadWAV("sound.wav");


if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }


// image point(les images taa sound bar)
    bar1=IMG_Load("bar1.png");
    bar2=IMG_Load("bar2.png");
    bar3=IMG_Load("bar3.png");
    bar4=IMG_Load("bar4.png");
    bar5=IMG_Load("bar5.png");

    positionpoint.x=285;
    positionpoint.y=400;
    positionpoint.h=bar1->h;
    positionpoint.w=bar1->w;
    positionpoint2.x=285;
    positionpoint2.y=510;
    positionpoint2.h=bar1->h;
    positionpoint2.w=bar1->w;

// ouverture fenetre option
    fenetre=SDL_SetVideoMode(800,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(fenetre==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }

// background
    backoption=IMG_Load("settingsbackground.png");
    if(backoption==NULL)
    {
        printf("Unable to load picture: %s\n",SDL_GetError());
        return 1;
    }

    positionbackoption.x=0;
    positionbackoption.y=0;
    positionbackoption.w=backoption->w;
// ouverture fenetre
    screen=SDL_SetVideoMode(800,800,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
// background
    background=IMG_Load("background1.png");
    if(background==NULL)
    {
        printf("Unable to load picture: %s\n",SDL_GetError());
        return 1;
    }
    positionecran.x=0;
    positionecran.y=0;
    positionecran.w=background->w;
// image newgame en etat non selectionee
    newgame=IMG_Load("newgame1.png");
    if(newgame==NULL)
    {
        printf("Unable to load picture: %s\n",SDL_GetError());
        return 1;
    }
    positionnewgame.x=285;
    positionnewgame.y=350;
// image newgame en etat selecctionnee
    newgamemotion=IMG_Load("newgame2.png");
    if(newgamemotion==NULL)
    {
        printf("Unable to load picture : %s\n",SDL_GetError());
        return 1;
    }

// image continue 
    continu=IMG_Load("continue1.png");
    if(continu==NULL)
    {
        printf("Unable to load picture : %s\n",SDL_GetError());
        return 1;
    }
    positioncontinu.x=285;
    positioncontinu.y=450;
// image continumotion
    continumotion=IMG_Load("continue2.png");
    if(continumotion==NULL)
    {
        printf("Unable to load picture : %s\n",SDL_GetError());
        return 1;
    }

// image exit
    exit=IMG_Load("exit1.png");
    if(exit==NULL)
    {
        printf("Unable to load picture : %s\n",SDL_GetError());
        return 1;
    }
    positionexit.x=285;
    positionexit.y=650;
// image exitmotion
    exitmotion=IMG_Load("exit2.png");
    if(exitmotion==NULL)
    {
        printf("Unable to load picture : %s\n",SDL_GetError());
        return 1;
    }

// image option
    option=IMG_Load("settings1.png");
    if(option==NULL)
    {
        printf("Unable to load picture: %s\n",SDL_GetError());
        return 1;
    }
    positionoption.x=285;
    positionoption.y=550;
// image optionmotion1
    optionmotion=IMG_Load("settings2.png");
    if(optionmotion==NULL)
    {
        printf("Unable to load picture: %s\n",SDL_GetError());
        return 1;
    }

    // new background
    new=IMG_Load("new2.png");
    if(new==NULL)
    {
        printf("Unable to load new: %s\n",SDL_GetError());
        return 1;
    }
//bonton on pour la resolution
on=IMG_Load("on.png");
    if(on==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;}
 positionon.x=345;
 positionon.y=640;
 positionfullson.x=40;
 positionfullson.y=30;
 positionfullson.h=on->h;
 positionfullson.w=on->w;
//bonton off pour la resolution
off=IMG_Load("off.png");
    if(off==NULL)
    {
        printf("Unable to load offf: %s\n",SDL_GetError());
        return 1;}
 positionfullsoff.x=600;
 positionfullsoff.y=30;
 positionfullsoff.h=off->h;
 positionfullsoff.w=off->w;
//bonton on pour plus   (on a besoin d'une autre photo)
plus=IMG_Load("plus.png");
    if(plus==NULL)
    {
        printf("Unable to load plus: %s\n",SDL_GetError());
        return 1;}
 positionplus.x=485;
 positionplus.y=395;
 positionplus1.x=485;
 positionplus1.y=505;
//bonton on pour mois(on a besoin d'une autre photo)
mois=IMG_Load("mois.png");
    if(mois==NULL)
    {
        printf("Unable to load mois: %s\n",SDL_GetError());
        return 1;}
 positionmois.x=285;
 positionmois.y=410;
 positionmois1.x=285;
 positionmois1.y=520;
//back to menu 
backtomenu=IMG_Load("backtomenu.png");
    if(newgame==NULL)
    {
        printf("Unable to load picture: %s\n",SDL_GetError());
        return 1;
    }
backtomenumotion=IMG_Load("backtomenumotion.png");
    if(newgame==NULL)
    {
        printf("Unable to load picture: %s\n",SDL_GetError());
        return 1;
    }
    positionbacktomenu.x=500;
    positionbacktomenu.y=720;
    int done=1;
    while (done)

    {
       SDL_BlitSurface(background,NULL,screen,&positionecran);
	SDL_BlitSurface(tabanim[i],NULL,screen,&positionecran);
	i++;
	SDL_Delay(20); 
	if (i==20) 
		i=1;
		 

// Blitz taa l interface menu

        SDL_BlitSurface(newgame,&positionecran,screen,&positionnewgame);
	SDL_BlitSurface(continu,&positionecran,screen,&positioncontinu);
        SDL_BlitSurface(option,&positionecran,screen,&positionoption);
        SDL_BlitSurface(on,&positionecran,screen,&positionfullson);
        SDL_BlitSurface(off,&positionecran,screen,&positionfullsoff);
        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
        SDL_BlitSurface(texte, NULL,screen,&positiontexte); /* texte */
	SDL_Flip(screen);}



        j=0;
        while(SDL_PollEvent(&event))
        {


            switch (event.type)
            {

            case SDL_QUIT :
            {
                done=0 ;
                break;
            }
             case SDL_KEYUP:
            { //clavier louta
             if(event.key.keysym.sym==SDLK_DOWN)
             {switch (position)
               {
		case 0 :
                  { SDL_BlitSurface(continumotion,&positionecran,screen,&positioncontinu);
                    Mix_PlayChannel(-1, son, 0);
                   position =1;
                  break;}
                 case 1 :
                 {
                  SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                  Mix_PlayChannel(-1, son, 0);
                  position =2;
                 break;}
                 case 2 :
                 {
                  SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                  Mix_PlayChannel(-1, son, 0);
                  position=3;
                 break;
                  }
                case 3:
               { SDL_BlitSurface(newgamemotion,&positionecran,screen,&positionnewgame);
                 Mix_PlayChannel(-1, son, 0);
                 position =0;
               break;
               }
               }
              }
           //clavier up

            else if ( event.key.keysym.sym == SDLK_UP )
              {
             switch (position)
               {
             case 0 :
             {
               SDL_BlitSurface(newgamemotion,&positionecran,screen,&positionnewgame);
                    Mix_PlayChannel(-1, son, 0);
               position=3;
              break;

              }
 	     case 1:
             {
               SDL_BlitSurface(continumotion,&positionecran,screen,&positioncontinu);
                    Mix_PlayChannel(-1, son, 0);
               position=0;
              break;

              }
              case 2:
               {
             SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
               Mix_PlayChannel(-1, son, 0);

            position =1;
              break;
             }
              case 3 :
             {
            SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
            Mix_PlayChannel(-1, son, 0);

             position=2;
              break;
              }
               }


             }
          }

            case SDL_MOUSEMOTION :
            {
                x=event.motion.x;
                y=event.motion.y;
                if ( x > 285 && x< 500 && y > 350 && y < 406 )
                {
                    SDL_BlitSurface(newgamemotion,&positionecran,screen,&positionnewgame);
                    Mix_PlayChannel(-1, son, 0);
                }
                if ( x > 285 && x< 500 && y > 450 && y < 506 )
                {
                    SDL_BlitSurface(continumotion,&positionecran,screen,&positioncontinu);
                    Mix_PlayChannel(-1, son, 0);
                }
                else if (  x > 285 && x< 500 && y > 550 && y < 606 )
                {
                    SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                    Mix_PlayChannel(-1, son, 0);
                }
                else if (  x > 285 && x< 500 && y > 650 && y < 706 )
                {
                    SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                    Mix_PlayChannel(-1, son, 0);
                }

                break;

            }
            case SDL_MOUSEBUTTONDOWN:
            {
                a=event.button.x;
                b=event.button.y ;
                if(a > positionfullson.x && a < positionfullson.x+positionfullson.w && b>positionfullson.y && b<positionfullson.y+positionfullson.h)
  			  {screen=SDL_SetVideoMode(800,800,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);}
		if(a > positionfullsoff.x && a < positionfullsoff.x+positionfullsoff.w && b>positionfullsoff.y && b<positionfullsoff.y+positionfullsoff.h)
			  { screen=SDL_SetVideoMode(800,800,32,SDL_SWSURFACE|SDL_DOUBLEBUF);}
                else if ( a > 285 && a< 500 && b > 350 && b < 406 )
                {   SDL_BlitSurface(newgamemotion,&positionecran,screen,&positionnewgame);
                     SDL_Flip(screen);
                     SDL_Delay(50);

                    done=0;

                }
                else if ( a > 285 && a< 500 && b > 450 && b < 406 )
                {   SDL_BlitSurface(continumotion,&positionecran,screen,&positioncontinu);
                     SDL_Flip(screen);
                     SDL_Delay(50);

                    done=0;

                }
                else if (  x > 285 && x< 500 && y > 550 && y < 606 )
                {
                    SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                    SDL_Flip(screen);
                    SDL_Delay(50);
                    while (j==0)
                    {
			
                        SDL_BlitSurface(backoption,NULL,fenetre,&positionbackoption);
                        
                        switch (volume)
                        {case 1: {SDL_BlitSurface(bar1,&positionecran,fenetre,&positionpoint); break;}
                        case 2:{SDL_BlitSurface(bar2,&positionecran,fenetre,&positionpoint);break;}
                        case 3:{SDL_BlitSurface(bar3,&positionecran,fenetre,&positionpoint);break;}
                        case 4:{SDL_BlitSurface(bar4,&positionecran,fenetre,&positionpoint);break;}
                        case 5:{SDL_BlitSurface(bar5,&positionecran,fenetre,&positionpoint);break;}
			}
		       
			switch (sound)
                        {case 1: {SDL_BlitSurface(bar1,&positionecran,fenetre,&positionpoint2); break;}
                        case 2:{SDL_BlitSurface(bar2,&positionecran,fenetre,&positionpoint2);break;}
                        case 3:{SDL_BlitSurface(bar3,&positionecran,fenetre,&positionpoint2);break;}
                        case 4:{SDL_BlitSurface(bar4,&positionecran,fenetre,&positionpoint2);break;}
                        case 5:{SDL_BlitSurface(bar5,&positionecran,fenetre,&positionpoint2);break;}
			}
			SDL_BlitSurface(backtomenu,&positionecran,fenetre,&positionbacktomenu);

                        
			if(r==1)
                        	SDL_BlitSurface(on,&positionecran,fenetre,&positionon);
                        else
                        	SDL_BlitSurface(off,&positionecran,fenetre,&positionon);
                        SDL_Flip(fenetre);
                       

			 while(SDL_PollEvent(&event2))
                            {


                            switch (event2.type)
                            {
                            case SDL_QUIT :
                            {
				j=1;                                
				done=0 ;
                                break;
                            }
			/*   case SDL_MOUSEMOTION:
			    {
				x=event2.button.x;
				y=event2.button.y;
				if (x>=posi && x<550 && y>400 && y<450)
				{SDL_BlitSurface(plus,&positionecran,fenetre,&positionplus);}
				else if (x>490 && x<550 && y>510 && y<560)
				{SDL_BlitSurface(plus,&positionecran,fenetre,&positionplus1);}
                               	else if (x>250 && x<300 && y>400 && y<450)
				{SDL_BlitSurface(mois,&positionecran,fenetre,&positionmois);}
                               	else if (x>250 && x<300 && y>510 && y<560)
				{SDL_BlitSurface(mois,&positionecran,fenetre,&positionmois1);}
				else if (x>500 && x<800 && y>720 && y<800)
				{SDL_BlitSurface(backtomenumotion,&positionecran,fenetre,&positionbacktomenu);}
			    }*/
                            case SDL_MOUSEBUTTONDOWN :
                            {
                                x=event2.button.x;
                                y=event2.button.y;
				if (x>positionpoint.x && x<positionpoint.x+20 && y>positionpoint.y && y<positionpoint.y+20)
				{
				//	{SDL_BlitSurface(mois,&positionecran,fenetre,&positionmois);
                                switch (volume)
				{
				case 1:
				
					Mix_VolumeMusic(3*MIX_MAX_VOLUME/4);
					volume=2;
				break;
				case 2:
					Mix_VolumeMusic(MIX_MAX_VOLUME*2);
					volume=3;
				break;
				case 3:
   					Mix_VolumeMusic(MIX_MAX_VOLUME/4);
					volume=4;
				break;
				case 4:
					Mix_VolumeMusic(MIX_MAX_VOLUME*0);
					volume=5;
				break;
					
				} 
				}
				else if (x>positionpoint.w+positionpoint.x-30 && x<positionpoint.w+positionpoint.x && y>positionpoint.y && y<positionpoint.y+20)
				{
				//	{SDL_BlitSurface(plus,&positionecran,fenetre,&positionplus);
                                switch (volume)
				{
				case 5:
					
					Mix_VolumeMusic(MIX_MAX_VOLUME/4);
					volume=4;
				break;
				case 4:
					Mix_VolumeMusic(MIX_MAX_VOLUME*2);
					volume=3;
				break;
				case 3:
   					Mix_VolumeMusic(3*MIX_MAX_VOLUME/4);
					volume=2;
				break;
				case 2:
					Mix_VolumeMusic(MIX_MAX_VOLUME);
					volume=1;
				break;
					
				} 
				}	
			
				else if (x>positionpoint2.x && x<positionpoint2.x+20 && y>positionpoint2.y && y<positionpoint2.y+20)
				{
				//	{SDL_BlitSurface(mois,&positionecran,fenetre,&positionmois1);
                                switch (sound)
				{
				case 1:
					Mix_VolumeChunk(son,MIX_MAX_VOLUME/4);
					sound=2;
				break;
				case 2:
					Mix_VolumeChunk(son,MIX_MAX_VOLUME/2);
					sound=3;
				break;


				case 3:
   					Mix_VolumeChunk(son,3*MIX_MAX_VOLUME/4);
					sound=4;
				break;
				case 4:
					Mix_VolumeChunk(son,MIX_MAX_VOLUME*0);
					sound=5;
				break;
					
				} 
				}
				else if (x>positionpoint2.w+positionpoint2.x-30 && x<positionpoint2.w+positionpoint2.x && y>positionpoint2.y && y<positionpoint2.y+20)
				{
                                //	{SDL_BlitSurface(plus,&positionecran,fenetre,&positionplus1);
                                switch (sound)
				{
				case 5:
					son = Mix_LoadWAV("sound.wav");						
					Mix_VolumeChunk(son,MIX_MAX_VOLUME/4);
					sound=4;
				break;
				case 4:
					Mix_VolumeChunk(son,MIX_MAX_VOLUME/2);
					sound=3;
				break;
				case 3:
   					Mix_VolumeChunk(son,3*MIX_MAX_VOLUME/4);
					sound=2;
				break;
				case 2:
					Mix_VolumeChunk(son,MIX_MAX_VOLUME*0);
					sound=1;
				break;
				}
				}
                                else if (x>500 && x<800 && y>720 && y<800)
                              
                                   { j=1;
                        	     SDL_BlitSurface(backtomenumotion,&positionecran,fenetre,&positionbacktomenu);
				   }
                                else if (  x > 285 && x< 500 && y > 650 && y < 706 )
                                {
                                    if (r==0)
                                {                                   
                                    r=1;
                                }
                                else if (r==1)
                                {                                  
                                    r=0;
                                }
					                               
				}

                                break;
                            }
                            }
                        SDL_Flip(fenetre);

                    }
                }
            }
            else if (  x > 285 && x< 500 && y > 650 && y < 706 )
            {
                SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                done =0;
            }
            break;
            }




        }
        SDL_Flip(screen);

    }


}//we ekhiran liberation des surfaces :'( les comments fel boucle li lfouk mizzel fehom trouchiket khfef taa lmotion w lmousbutton sound; (we need other photos nibba smaller ones)
SDL_FreeSurface(screen);
SDL_FreeSurface(background);
SDL_FreeSurface(newgame);
SDL_FreeSurface(continu);
SDL_FreeSurface(new);
SDL_FreeSurface(option);
SDL_FreeSurface(exit);
SDL_Delay(10);
SDL_Quit();
pause=getchar();
Mix_FreeChunk(son);
TTF_CloseFont(police);
TTF_Quit();
Mix_FreeMusic(music);
return 0;
}
