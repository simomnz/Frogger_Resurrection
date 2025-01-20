#pragma once

#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "struct.h"
#include "utils.h"
#include "menu.h"



#define CROCODILE_SHIFT 15  /* Minimum Space between two Crocodiles */
 
#define  CROCODILE_LENGTH 21   /* Lenght of Crocodile's Sprite and HitBox */
#define  CROCODILE_HEIGHT 4    /* Height of Crocodile's Sprite and HitBox */

#define PROJECTILE_LENGTH 3     /* Lenght of Projectile's Sprite and HitBox */
#define PROJECTILE_HEIGHT 1     /* Height of Projectile's Sprite and HitBox */










void createCrocodile(Crocodile *crocodiles, Game *game);


void *moveCrocodile(void *arg);

void resetCrocodile(Crocodile *crocodile, Game *game);

void createProjectile(Crocodile crocodile, Game *game);

void *moveProjectile(void *arg);

void resetProjectile(Projectile *projectile);