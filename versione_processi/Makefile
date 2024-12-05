
frogger: game.o main.o
	gcc main.o game.o colors.o menu.o -lncurses -o frogger

main.o: main.c
	gcc -c main.c -o main.o


game.o: game.c
	gcc -c game.c -o game.o

colors.o: colors.c
	gcc -c colors.c -o colors.o

menu.o: menu.c
	gcc -c menu.c -o menu.o


#per rimuovere 

clean:
	rm -f *.o frogger