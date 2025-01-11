#pragma once 
#include <ctype.h>   //per la funzione tolower
#include <ncurses.h>  //per la funzione getch
#include "socket.h"
#include "utils.h"
#include "struct.h"
#include "menu.h"
#include "sounds.h"


#define RIGHT 1
#define LEFT -1

#define FROG_HEIGHT 4
#define FROG_LENGTH 7


#define DEN_LENGTH 7
#define DEN_HEIGHT 4


void movePlayer(Player *player, int sockfdm, int gameToPlayerFd);

int isPlayerOnCroc(Game *game);

int isPlayerOnDen(Game *game);

int isPlayerOnGrass(Game *game);


void createGrenade(Player *player, int pipe, int direction);

void moveGrenade(Grenade *grenade, int pipe);


