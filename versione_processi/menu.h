#include <ncurses.h>
#include "game.h"
#include "colors.h"

//bisogna decidere se utilizzare le windows oppure no (io voto si)


#define EASY_MODE_CROC_SPEED 1
#define MEDIUM_MODE_CROC_SPEED 2
#define HARD_MODE_CROC_SPEED 3

//void printCursor(short x, short y);


//resituisce la difficoltà
short menu(Game *game);

void easyDifficult(Game *game);

void mediumDifficult(Game *game);

void hardDifficult(Game *game);

int scoreCounter(Player *player, int points);

void wrongTerminalSize(Game *game);