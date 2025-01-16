

#aggiungere check-deps all'inizio (dopo frogger:)
frogger:  game.o main.o colors.o menu.o player.o socket.o sprite.o utils.o crocodile.o sounds.o
	gcc game.o main.o colors.o player.o socket.o sprite.o utils.o crocodile.o menu.o sounds.o -o frogger -lncurses `sdl2-config --cflags --libs` -lSDL2_mixer

# check-deps:
# 	@which sdl2-config > /dev/null || (echo "libsdl2-dev not found! Installing..."; sudo apt-get update && sudo apt-get install -y libsdl2-dev)
# 	@dpkg -l | grep libsdl2-mixer-dev > /dev/null || (echo "libsdl2-mixer-dev not found! Installing..."; sudo apt-get install -y libsdl2-mixer-dev)
# 	@dpkg -l | grep libncurses-dev > /dev/null || (echo "libncurses-dev not found! Installing..."; sudo apt-get install -y libncurses-dev)


main.o: main.c struct.h
	gcc -c main.c -o main.o `sdl2-config --cflags`

game.o: game.c struct.h
	gcc -c game.c -o game.o `sdl2-config --cflags`

colors.o: colors.c struct.h
	gcc -c colors.c -o colors.o `sdl2-config --cflags`

menu.o: menu.c struct.h
	gcc -c menu.c -o menu.o `sdl2-config --cflags`
<
player.o: player.c struct.h
	gcc -c player.c -o player.o `sdl2-config --cflags`

socket.o: socket.c struct.h
	gcc -c socket.c -o socket.o `sdl2-config --cflags`

sprite.o: sprite.c struct.h
	gcc -c sprite.c -o sprite.o `sdl2-config --cflags`

utils.o: utils.c struct.h
	gcc -c utils.c -o utils.o `sdl2-config --cflags`

crocodile.o: crocodile.c struct.h
	gcc -c crocodile.c -o crocodile.o `sdl2-config --cflags`

sounds.o: sounds.c struct.h
	gcc -c sounds.c -o sounds.o `sdl2-config --cflags`

clean:
	rm -f *.o frogger
