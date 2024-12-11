#pragma once 
#include "struct.h"
#include <ctype.h>   //per la funzione tolower
#include <ncurses.h>  //per la funzione getch
#include "socket.h"

void movePlayer(Player *player, int sockfd);

int isPlayerOnCroc(Game *game, unsigned short numCroc);