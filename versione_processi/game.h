#pragma once
#include <stdio.h>
#include "player.h"

typedef struct
{
    unsigned int isRunning;
    Player *player;
    Crocodiles crocodiles;
} Game;

void start(Game *game);

void run(Game *game);

void stop(Game *game);
