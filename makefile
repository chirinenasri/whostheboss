Prog:partage.o main.o
	gcc partage.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
partage.o:partage.c
	gcc -c partage.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
