#pragma once

#include <stdio.h>
#include <time.h>

#include "struct.h"
#include "crocodile.h"
#include "sprite.h"
#include "player.h"
#include "menu.h"
#include "sounds.h"
#include "socket.h"



#define GODMODE 0 //0 se attivo, 1 se disattivo



void start(Game *game);

void run(Game *game);

void stop(Game *game);
