#pragma once
#include <stdlib.h>
#include <sys/socket.h>  
#include <sys/un.h>       /* per i socket unix */
#include <ncurses.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "struct.h"
#include <asm-generic/socket.h>


#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define SOCKET_PATH "/tmp/mysocket"  /* Path del socket */



//int createSocket(); 
int startServer();

int connectToServer();

void recvPlayerCords(Player *player, int sockfd);

void sendPlayerCords(Player *player, int sockfd);
