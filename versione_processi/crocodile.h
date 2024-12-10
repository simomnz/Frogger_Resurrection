#pragma once
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>


#define CROCODILE_RESPAWN_MAX 10
#define CROCODILE_RESPAWN_MIN 2
#define MAX_LINE_CROCODILES 10
#define MIN_LINE_CROCODILES 4



void moveCrocodile(Crocodile *crocodile, int pipe);

int getRespawnCrocTime();

