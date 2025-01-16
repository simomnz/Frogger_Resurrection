#include <ncurses.h>
#include "game.h"
#include "colors.h"


#define EASY_MODE_CROC_SPEED 1
#define MEDIUM_MODE_CROC_SPEED 2
#define HARD_MODE_CROC_SPEED 3


short menu(Game *game);

void easyDifficult(Game *game);

void mediumDifficult(Game *game);

void hardDifficult(Game *game);

int scoreCounter(Player *player, int points);

void wrongTerminalSize(Game *game);