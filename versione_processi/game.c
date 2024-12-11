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
    createCrocodile(game->crocodiles);
}



//funzione per contare numero di coccodrilli attivi(?)
void run(Game *game) {
    Player *player = &game->player;
    
    
    while (game->isRunning) {
        recvPlayerCords(player, game->serverSocket);
        mvprintw(player->cords.y, player->cords.x, player->sprite.texture);
        int numCroc = 4;

        if (isPlayerOnCroc(&game, numCroc)) {
            /* code */
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

