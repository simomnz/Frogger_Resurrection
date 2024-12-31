#include "game.h"
#include <ncurses.h>

void start(Game *game) {
    initscr();   
    nodelay(stdscr, TRUE);   
    noecho();       
    cbreak();       
    keypad(stdscr, TRUE);   
    curs_set(0);

    game->serverSocket = createSocket();
    game->isRunning = 1;
    if (pipe(game->pipeFd) < 0) {
        perror("error in pipe creation");
        exit(-1);
    }
    if (pipe(game->gameToPipe) < 0) {
        perror("error in pipe creation");
        exit(-1);
    }
    

    createCrocodile(game->pipeFd, game->crocodiles);
    printCrocodile(game->crocodiles);

    /*set all dens as open*/

    for (int i = 0; i < 5; i++) {
        game->closedDen[i] = 0;
    }

}


void run(Game *game) {
    Player *player = &game->player;
    player->lives = 3;


    Coordinates spawnPoint = {(COLS-1)/2, LINES -1};
    player->cords.x = spawnPoint.x;
    player->cords.y = spawnPoint.y;
    player->cords.source = 0;
    printFrog(player->cords.x, player->cords.y);
    
    pid_t pidPlayer = fork();
    if (pidPlayer == 0) {
        close(game->pipeFd[0]);
        close(game->gameToPipe[1]);
        movePlayer(player, game->pipeFd[1], game->gameToPipe[0]);
        exit(0);
    }

    close(game->pipeFd[1]);
    close(game->gameToPipe[0]);

    
    Coordinates message; // = {0, 0, 0, 0};

    Crocodile *crocodile = game->crocodiles;

    while (game->isRunning) {
        clear();
        // recvPlayerCords(player, game->serverSocket);
        readData(game->pipeFd[0], &message, sizeof(Coordinates));
        // mvprintw(0, 25, "Leggo x = %d && y = %d", player->cords.x, player->cords.y);
        if (message.source == 0) {
            player->cords = message;
        } else if (message.source > 0) {
            crocodile[message.source -1].cords = message;
        }

        if(isPlayerOnCroc(game)) {
            mvprintw(0, COLS/2, "Sei sul coccodrillo");
        }
        




        writeData(game->gameToPipe[1], &player->cords, sizeof(Coordinates));
        // mvprintw(1, 0, "Scrivo x = %d && y = %d", player->cords.x, player->cords.y);


        /*
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


        printCrocodile(game->crocodiles);
        
        printFrog(player->cords.x, player->cords.y);
        

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
        //mvprintw(0, 0, "x = %d && y = %d", player->cords.x, player->cords.y);
        usleep(1000);
        refresh(); 
        
    }
    // Da cambiare con schermata di vittoria e sconfitta
}

void stop(Game *game) {
    game->isRunning = 0;
    endwin();
}




