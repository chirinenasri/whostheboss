prog:main.o voiture.o jeu.o background.o bullet.o text.o
	gcc main.o voiture.o jeu.o background.o bullet.o text.o -o prog -lSDL -lSDL_ttf -lm -g
main.o:main.c
	gcc -c main.c -g
jeu.o:jeu.c
	gcc -c jeu.c -g
voiture.o:voiture.c
	gcc -c voiture.c -g
background.o:background.c
	gcc -c background.c -g
bullet.o:bullet.c
	gcc -c bullet.c
text.o:text.c
	gcc -c text.c
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
