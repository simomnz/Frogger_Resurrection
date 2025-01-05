#pragma once
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "struct.h"


#define CROCODILE_RESPAWN_MAX 10
#define CROCODILE_RESPAWN_MIN 2
#define MAX_LINE_CROCODILES 10
#define MIN_LINE_CROCODILES 4
#define CROCODILE_SHIFT 1

#define  CROCODILE_LENGTH 3   //valori a caso da cambiare
#define  CROCODILE_HEIGHT 1


//DA TOGLIERE

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30






void createCrocodile(int *pipe, Crocodile *crocodiles);


void moveCrocodile(int *pipe, Crocodile *crocodile );

void createProjectile(int *pipe, Crocodile *crocodile);

void moveProjectile(int pipe, Projectile *projectile);