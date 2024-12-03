#include "game.h"


int main(void) {

    Game *game;
    game->isRunning = 0;
    start(game);

    run(game);
   //sborra 
    stop(game);

    return 0;
}