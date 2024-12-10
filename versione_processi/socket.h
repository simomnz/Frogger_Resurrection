#pragma once
#include <stdlib.h>
#include <sys/socket.h>  
#include <sys/un.h>       /* per i socket unix */
#include <ncurses.h>


#define SOCKET_PATH "/tmp/mysocket"  /* Path del socket */



int createSocket();


char recvPlayerInput();

//void sendPlayerInput(char input); da capire al volo

