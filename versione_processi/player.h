#pragma once 
#include <ctype.h>   //per la funzione tolower
#include <ncurses.h>  //per la funzione getch
#include "socket.h"
#include "utils.h"
#include "windows.h"
#include "struct.h"




void movePlayer(Player *player, int sockfd);

int isPlayerOnCroc(Game *game, unsigned short numCroc);

int isPlayerOnDen(Game *game);

int isPlayerOnGrass(Game *game);


void createGrenade(Player *player, int pipe);

void moveGrenade(Grenade *grenade, int pipe);


