#include "game.h"
#include <ncurses.h>

void start(Game *game) {
    initscr();      
    noecho();       
    cbreak();       
    keypad(stdscr, TRUE);   
    curs_set(0);
    game->isRunning = 1;
}

void run(Game *game) {
    while (game->isRunning) {
        
    }
    
}

void stop(Game *game) {
    game->isRunning = 0;
    endwin();

}

