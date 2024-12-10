#pragma once
#include <stdlib.h>
#include <sys/socket.h>  
#include <sys/un.h>       /* per i socket unix */
#include <ncurses.h>
#include "struct.h"

#define SOCKET_PATH "/tmp/mysocket"  /* Path del socket */



int createSocket();


void recvPlayerCords(Player *player, int sockfd);

void sendPlayerInput(Player *player, int sockfd);
