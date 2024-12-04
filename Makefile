
frogger: game.o main.o
	gcc main.o game.o -lncurses -o frogger

main.o: main.c
	gcc -c main.c -o main.o


game.o: game.c
	gcc -c game.c -o game.o
