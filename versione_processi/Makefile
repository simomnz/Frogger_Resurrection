
frogger: game.o main.o
	gcc main.o game.o colors.o menu.o player.o socket.o windows.o sprite.o -lncurses -o frogger

main.o: main.c
	gcc -c main.c -o main.o


game.o: game.c
	gcc -c game.c -o game.o

colors.o: colors.c
	gcc -c colors.c -o colors.o

menu.o: menu.c
	gcc -c menu.c -o menu.o

player.o: player.c
	gcc -c player.c -o player.o

socket.o: socket.c
	gcc -c socket.c -o socket.o

windows.o: windows.c
	gcc -c windows.c -o windows.o

sprite.o: sprite.c
	gcc -c sprite.c -o sprite.o


#per rimuovere 

clean:
	rm -f *.o frogger