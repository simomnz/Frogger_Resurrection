#include "game.h"


int main(void) {
    
    /* Make the game Start, Run and Stop */
    Game game;
    game.isRunning = 0;
    start(&game);

    run(&game);
     
    stop(&game);
    
    return 0; 
}