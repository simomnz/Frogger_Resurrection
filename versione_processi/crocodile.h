#pragma once

#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#include "struct.h"


#define CROCODILE_RESPAWN_MAX 10
#define CROCODILE_RESPAWN_MIN 2
#define MAX_LINE_CROCODILES 10
#define MIN_LINE_CROCODILES 4
#define CROCODILE_SHIFT 15

#define  CROCODILE_LENGTH 21  
#define  CROCODILE_HEIGHT 4

#define PROJECTILE_LENGTH 3
#define PROJECTILE_HEIGHT 1










void createCrocodile(int *pipe, Crocodile *crocodiles, Game *game);


void moveCrocodile(int *pipe, Crocodile crocodile, Game *game);

void resetCrocodile(Crocodile *crocodile, Game *game);

void createProjectile(int *pipe, Crocodile crocodile, Game *game);

void moveProjectile(int pipe, Projectile *projectile);

void resetProjectile(Projectile *projectile);