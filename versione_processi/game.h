#pragma once

#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "struct.h"
#include "crocodile.h"
#include "sprite.h"
#include "player.h"
#include "menu.h"
#include "sounds.h"
#include "socket.h"
#include <ncurses.h>







void start(Game *game);

void run(Game *game);

void stop(Game *game);
