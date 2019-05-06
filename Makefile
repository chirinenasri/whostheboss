

prog:main.o work.o 
	gcc main.c work.c -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g
work.o:work.c
	gcc -c work.c -g



