game:function.o main.o
	gcc main.o function.o -o game -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
function.o:function.c
	gcc -c function.c -g
