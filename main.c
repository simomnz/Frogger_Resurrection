#include "game.h"


int main(void) {

    Game *game;
    game->isRunning = 0;
    start(game);

    run(game);
     
    stop(game);

    return 0;
}