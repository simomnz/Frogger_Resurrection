frogger: game.o main.o colors.o menu.o player.o socket.o windows.o sprite.o utils.o projectile.o
	gcc main.o game.o colors.o player.o socket.o windows.o sprite.o utils.o projectile.o crocodile.o -lncurses -o frogger   

#aggiungere menu.o

main.o: main.c struct.h
	gcc -c main.c -o main.o

game.o: game.c struct.h
	gcc -c game.c -o game.o

colors.o: colors.c struct.h
	gcc -c colors.c -o colors.o

#menu.o: menu.c struct.h
#	gcc -c menu.c -o menu.o

player.o: player.c struct.h
	gcc -c player.c -o player.o

socket.o: socket.c struct.h
	gcc -c socket.c -o socket.o

windows.o: windows.c struct.h
	gcc -c windows.c -o windows.o

sprite.o: sprite.c struct.h
	gcc -c sprite.c -o sprite.o

utils.o: utils.c struct.h
	gcc -c utils.c -o utils.o

projectile.o: projectile.c struct.h
	gcc -c projectile.c -o projectile.o

crocodile.o: crocodile.c struct.h
	gcc -c crocodile.c -o crocodile.o

# Clean command to remove compiled files
clean:
	rm -f *.o frogger
