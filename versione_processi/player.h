#pragma once 
#include <ctype.h>   //per la funzione tolower
#include <ncurses.h>  //per la funzione getch
#include "socket.h"
#include "utils.h"
#include "windows.h"
#include "struct.h"
#include "menu.h"
#include "sounds.h"


#define RIGHT 1
#define LEFT -1



void movePlayer(Player *player, int sockfdm, int gameToPlayerFd);

int isPlayerOnCroc(Game *game);

int isPlayerOnDen(Game *game);

int isPlayerOnGrass(Game *game);


void createGrenade(Player *player, int pipe, int direction);

void moveGrenade(Grenade *grenade, int pipe);


