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


    //tutto da aggiustare
    //createCrocodile(game->pipeFd, game->crocodiles);
    /*set all dens as open*/
    for (int i = 0; i < 5; i++) {
        game->closedDen[i] = 0;
    }
    
}



//questa funzione non funziona neanche per il cazzo

void run(Game *game) {
    Player *player = &game->player;
    player->lives = 3;


    if (pipe(game->pipeFd) < 0) {
        perror("error in pipe creation");
        exit(-1);
    }

    pid_t pidPlayer = fork();
    if (pidPlayer == 0) {
        close(game->pipeFd[0]);
        movePlayer(player, game->pipeFd[1]);
        exit(0);
    }

    close(game->pipeFd[1]);

    Coordinates spawnPoint = {10, 5};
    player->cords.x = spawnPoint.x;
    player->cords.y = spawnPoint.y;
    while (game->isRunning) {
        clear();
        // recvPlayerCords(player, game->serverSocket);
        readData(game->pipeFd[0], &player->cords, sizeof(Coordinates));
        int numCroc = 4;

        /*
        if (isPlayerOnCroc(game, numCroc)) {
            // spostamento del coccodrillo (da capire il numero)
            int new_x = player->cords.x + (CROCODILE_SHIFT * player->cords.direction);
            if (new_x <= COLUMN_BORDER && new_x >= 0) {
                player->cords.x = new_x;
            } 
            
        }else if (isPlayerOnDen(game)) {
            // TODO
            // update score
            // update screenprintFrog(player);
            // create global variable for spawn point
            //let the frog restart from spawnpoint
            // player->lives--; (?)
            player->cords.x = spawnPoint.x;
            player->cords.y = spawnPoint.y;

        }else if (!isPlayerOnGrass(game)) {
            player->cords.x = spawnPoint.x;
            player->cords.y = spawnPoint.y;
            player->lives--;
        }
        */

        printFrog(player->cords.x, player->cords.y);

        
        //printCrocodile(game->crocodiles, numCroc);

        /*if (game->player.lives > 0) {
            mvprintw(0, 0, "Hai vinto");
            usleep(100000);
            break;
        }else {
            mvprintw(0, 0, "Hai perso"); 
            usleep(100000);
            stop(game);
            //exit(0);

        }*/
        refresh();
        usleep(10000);
            
        
    }
    // Da cambiare con schermata di vittoria e sconfitta
}

void stop(Game *game) {
    game->isRunning = 0;
    endwin();
}

