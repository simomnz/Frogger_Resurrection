#include "game.h"
#include <ncurses.h>

void start(Game *game) {
    initscr();      
    noecho();       
    cbreak();       
    keypad(stdscr, TRUE);   
    curs_set(0);
    game->serverSocket = createSocket();
    game->isRunning = 1;
    Crocodile **crocodiles;
    createCrocodile(crocodiles);
}

void run(Game *game) {
    while (game->isRunning) {
        recvPlayerCords(game->player, game->serverSocket);
        mvprintw(game->player.cords.y, game->player.cords.x, game->player.frog.sprite);
        int direction = 0;
        for (int i = 0; i < sizeof(crocodiles); i++) {
            for (int j = 0; j < sizeof(crocodiles[i]); j++) {
                if ((game->player.cords.x == crocodiles[i][j].x) && (game->player.cords.y == crocodiles[i][j].y)) {
                    game->player.isOnCrocodile = 1;
                    direction = crocodiles[i][j].direction;
                }
            }
        }
    }
    // Da cambiare con schermata di vittoria e sconfitta
    if (game->player.lives > 0) {
        mvprintw(0, 0, "Hai vinto");
    }else {
        mvprintw(0, 0, "Hai perso"); 
    }
    
    
}

void stop(Game *game) {
    game->isRunning = 0;
    endwin();

}

