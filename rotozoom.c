#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>


#define PATH_IMAGE "image.bmp"        /* chemin de l'image (bitmap) à faire tourner */
#define FPS_DISP_RATE 2000             /* Temps en ms entre deux affichages des fps */
#define VITESSE_ANGULAIRE M_PI / 10.0f /* Vitesse angulaire en radians par seconde*/

/* Etat des touches du clavier. true pour enfoncée. */
_Bool etatClavier[512];

/* Fonction de copie de pixels pour ne pas trop dépendre du format de l'image */
void inline SDL_CopyPixel(SDL_Surface* src, int x, int y, SDL_Surface* dest, int i, int j) {
    int bpp = src->format->BytesPerPixel;
    Uint8 *srcPixel = (Uint8 *)src->pixels + y * src->pitch + x * bpp;
    Uint8 *destPixel = (Uint8 *)dest->pixels + j * dest->pitch + i * bpp;

    switch(bpp) { 
        case 1: 
            *destPixel = *srcPixel; 
            break; 

        case 2: 
            *(Uint16 *)destPixel = *(Uint16 *)srcPixel; 
            break; 

        case 3:
            /* L'opération sur 24 bits est lente */
            destPixel[0] = srcPixel[0];
            destPixel[1] = srcPixel[1];
            destPixel[2] = srcPixel[2];
            break; 

        case 4: 
            *(Uint32 *)destPixel = *(Uint32 *)srcPixel; 
            break; 
    }  
}

/* Effectue une rotation centrale plus un changement d'échelle, alloue automatiquement la mémoire.*/
SDL_Surface* SDL_RotoZoom(SDL_Surface* origine, float angle_radian, float rapport) {
    SDL_Surface* destination;     /* Surface de destination, allouée ici et retournée */
    int mx, my, mxdest, mydest;   /* Coordonnées des centres des surfaces */
    int i, j;                     /* Coordonnées de travail lors du parcourt de la surface de destination */
    int bx, by;                   /* Coordonnées de travail, correspondent à i et j dans l'image d'origine */
    float tcos, tsin;             /* cos et sin de angle_radian */
    int largeurdest, hauteurdest; /* Dimentions de la surface de destination */

    /*pour éviter pleins d'appels, on stocke les valeurs*/
    tcos = cos(angle_radian);
    tsin = sin(angle_radian);

    /*calcul de la taille de l'image de destination*/
    largeurdest= (int) ceil( (origine->w * fabs(tcos) + origine->h * fabs(tsin)) * rapport );
    hauteurdest= (int) ceil( (origine->w * fabs(tsin) + origine->h * fabs(tcos)) * rapport );

    /* 
     * alloue la mémoire à l'espace de destination
     */
    destination = SDL_CreateRGBSurface(SDL_HWSURFACE, largeurdest, hauteurdest, origine->format->BitsPerPixel,
            origine->format->Rmask, origine->format->Gmask, origine->format->Bmask, origine->format->Amask);

    /*on vérifie que la mémoire a été allouée*/
    if(destination==NULL)
        return NULL;

    /*calcul des centres des images*/
    mxdest = (int) destination->w/2;
    mydest = (int) destination->h/2;
    mx = (int) origine->w/2;
    my = (int) origine->h/2;

    /* Coeur de l'algo
     * On parcourt la surface de destination pour la remplir
     */
    for(j=0; j<destination->h; j++)
        for(i=0; i<destination->w; i++) {
            /*
             * on détermine la valeur de pixel qui correspond le mieux pour la position
             * i,j de la surface de destination 
             *
             * on détermine la meilleure position sur la surface d'origine en appliquant
             * une matrice de rotation inverse
             */
            bx = mx + (int)( ( tcos*(i-mxdest) + tsin*(j-mydest)) / rapport );
            by = my + (int)( (-tsin*(i-mxdest) + tcos*(j-mydest)) / rapport );
            /* on vérifie que l'on ne sort pas des bords */
            if (bx>=0 && bx< origine->w && by>=0 && by< origine->h)
                SDL_CopyPixel(origine, bx, by, destination, i, j);
        }

    return destination;
}

SDL_Surface* SDL_RotoZoom_Opt(SDL_Surface* origine, float angle_radian, float rapport) {
	SDL_Surface* destination;     /* Surface de destination, allouée ici et retournée */
	int mx, my, mxdest, mydest;   /* Coordonnées des centres des surfaces */
	int i, j;                     /* Coordonnées de travail lors du parcourt de la surface de destination */
	int bx, by;                   /* Coordonnées de travail, correspondent à i et j dans l'image d'origine */
	int x, y;                   /* valeurs de travail (bx et by avant arrondit */
	int ligne_x, ligne_y;       /* valeurs au debut des lignes (retour de i à 0) */
	int dxi, dyi, dxj, dyj;     /* increments des x et y suivant i et j (compteurs des x et y) */
	float tcos, tsin;             /* cos et sin de angle_radian */
	int largeurdest, hauteurdest; /* Dimentions de la surface de destination */

	/*pour éviter pleins d'appel, on stocke les valeurs*/
	tcos = cos(angle_radian);
	tsin = sin(angle_radian);

	/*calcul de la taille de l'image de destination*/
	largeurdest= (int) ceil( (origine->w * fabs(tcos) + origine->h * fabs(tsin)) * rapport );
	hauteurdest= (int) ceil( (origine->w * fabs(tsin) + origine->h * fabs(tcos)) * rapport );

	/* 
	* alloue la mémoire à l'espace de destination, attention, 
	* la surface est de même taille
	*/
	destination = SDL_CreateRGBSurface(SDL_HWSURFACE, largeurdest, hauteurdest, origine->format->BitsPerPixel,
			origine->format->Rmask, origine->format->Gmask, origine->format->Bmask, origine->format->Amask);

	/*on vérifie que la mémoire a été allouée*/
	if(destination==NULL)
		return NULL;

	/* calcul des centres des images */
	mxdest = (int) destination->w/2;
	mydest = (int) destination->h/2;
	mx = (int) origine->w/2;
	my = (int) origine->h/2;

	/* Initialisation et calculs des incréments */
	ligne_x = (int) (mx*65536 + (-tcos * mxdest - tsin * mydest) / rapport * 65536.0);
	ligne_y = (int) (my*65536 + ( tsin * mxdest - tcos * mydest) / rapport * 65536.0);
	dxi =  (int) (tcos / rapport * 65536.0);
	dxj =  (int) (tsin / rapport * 65536.0);
	dyi =  (int) (-tsin / rapport * 65536.0);
	dyj =  (int) (tcos / rapport * 65536.0);

	/* Coeur de l'algo
	 * On parcourt la surface de destination pour la remplir
	 */
	for(j=0;j<destination->h;j++){
		x = ligne_x; 
		y = ligne_y;
		for(i=0;i<destination->w;i++) {
			bx = ((unsigned int) x) >> 16;
			by = ((unsigned int) y) >> 16;
			/* on vérifie que l'on ne sort pas des bords*/
			if (bx < origine->w && by< origine->h)
				SDL_CopyPixel(origine, bx, by, destination, i, j);

			/* On incrémente les coordonnées dans l'image d'origine */
			x += dxi;
   			y += dyi;
		}
		/* incrément pour le changement de ligne */
		ligne_x += dxj;
		ligne_y += dyj;
	}

	return destination;
}
/* Gestion des évènements SDL.
 * On se contente de tenir à jour le tableau des touches appuyées même si c'est peu utile ici.
 * On ferme sur un SDL_QUIT (arrive en cas de fermeture de la fenêtre par ex).
 */
void GestionEvenements(void) {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_KEYUP:
                etatClavier[e.key.keysym.sym]="false";
                break;

            case SDL_KEYDOWN:
                etatClavier[e.key.keysym.sym]="true";
                break;

            case SDL_QUIT:
                /* Dans l'absolu il faudrait libérer nos surfaces */
                SDL_Quit();
                exit(EXIT_SUCCESS);

            default:
                break;
        }
    }
}


int main(int argc, char* argv[])
{
    unsigned int currentFrm;
    unsigned int lastFrm;

    unsigned int lastFpsDisplay; /* instant du dernier affichage des fps */

    float tempsEcoule = 0.0f;    /* temps écoulé depuis la dernière image, en secondes */ 
    float fpsCounter = 0;        /* compteur des images affichées depuis le dernier calcul de fps */ 
    float angle = 0.0f;          /* angle courrant pour la rotation (en radians) */ 


    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)<0) {
        exit(EXIT_FAILURE);
    }

    SDL_Surface* fenetre = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | /*SDL_FULLSCREEN |*/ SDL_DOUBLEBUF);
    if (fenetre==NULL) {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    /* Initialisation du clavier */
    for(int i=0; i<512; i++)
        etatClavier[i]="false";

    /* Lecture de l'image que l'on va torturer */
    SDL_Surface* tmpimageOriginale = SDL_LoadBMP(PATH_IMAGE);
    if (tmpimageOriginale==NULL) {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    /* On recupere l'image dans le format de l'ecran */
    SDL_Surface* imageOriginale = SDL_DisplayFormat(tmpimageOriginale);
    if (tmpimageOriginale==NULL) {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    SDL_FreeSurface(tmpimageOriginale);
    
    /* Boucle principale */
    currentFrm = SDL_GetTicks();
    lastFrm = currentFrm;
    lastFpsDisplay = currentFrm;
    while (1) {
        /* gestion du temps */
        lastFrm = currentFrm;
        currentFrm = SDL_GetTicks();
        tempsEcoule = (currentFrm-lastFrm)/1000.0f;

        /* Affichage du frame rate sur la console */
        if(currentFrm-lastFpsDisplay>FPS_DISP_RATE) {
            printf("%f\n", fpsCounter*1000.0f/(currentFrm-lastFpsDisplay));
            lastFpsDisplay = currentFrm;
            fpsCounter = 0;
        }

        GestionEvenements();
        if(etatClavier[SDLK_ESCAPE]) {
            /* On quitte sur "échap", avec un évènement SDL_QUIT lancé à la main
             * pour arriver au même point d'arrêt qu'avec la fermeture de la fenêtre par exemple.
             */
            SDL_Event ev;
            ev.type = SDL_QUIT;
            SDL_PushEvent(&ev);
        }

        angle += VITESSE_ANGULAIRE * tempsEcoule;
        if(angle>2*M_PI)
            angle-=2*M_PI;

        /* Effacer l'écran. Utiliser une couleur particulière permet de voir ce qui a été affiché et ce qui est vide */
        SDL_FillRect(fenetre, NULL, 0x000f0fff);

        SDL_Surface* surfRot = SDL_RotoZoom_Opt(imageOriginale, angle, 1.2);
        SDL_BlitSurface(surfRot, NULL, fenetre, NULL);
        SDL_FreeSurface(surfRot); /* Très très très important si on ne veut pas manger toute sa ram et plus en 2 minutes */

        fpsCounter++;
        SDL_Flip(fenetre);
    }

    /* Jamais atteint */
    (void) argc;
    (void) argv;
    return EXIT_SUCCESS;
}
