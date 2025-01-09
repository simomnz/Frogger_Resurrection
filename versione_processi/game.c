#include "game.h"
#include <ncurses.h>

void start(Game *game) {
    initscr();   
    nodelay(stdscr, TRUE);   
    noecho();       
    cbreak();       
    keypad(stdscr, TRUE);   
    curs_set(0);
    start_color();
    //use_default_colors();
    setColors();

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

    initAudio();
    
   
    

    /*set all dens as open*/

    for (int i = 0; i < 5; i++) {
        game->closedDen[i] = 0;
    }

    menu(game);
}


void run(Game *game) {


    //ha rotto il cazzo sta musica

    //startMusic(loadMusic("../music/gameMusic.mp3"));

    Mix_Chunk *jumpSound = loadSound("../music/jumpSound.mp3");
    
    createCrocodile(game->pipeFd, game->crocodiles);
    Player *player = &game->player;
    player->lives = 3;
    player->score = 0;



    Coordinates spawnPoint = {(COLS-1)/2, LINES -1};
    player->cords.x = spawnPoint.x;
    player->cords.y = spawnPoint.y;
    player->cords.speed = 1;
    printCrocodile(game->crocodiles);
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

    int count = 0;
    int playersCroc = 0;
    clear();
    while (game->isRunning) {
        wbkgd(stdscr, COLOR_PAIR(RIVER));
        // recvPlayerCords(player, game->serverSocket);
        readData(game->pipeFd[0], &message, sizeof(Coordinates));
        // mvprintw(0, 25, "Leggo x = %d && y = %d", player->cords.x, player->cords.y);
        if (message.source == 0) {
            player->cords = message;

            //da riattivare
            //stopSound(jumpSound); 
            //playSound(jumpSound);

        } else if (message.source > 0) {
            crocodile[message.source -1].cords = message;
            // if ((crocodile[message.source - 1].PID ==  playersCroc) && (player->isOnCrocodile == 1)) {
            //     player->cords.x += (crocodile[message.source - 1].cords.direction * crocodile[message.source - 1].cords.speed);
            // }

            // 2) If that croc’s PID == the croc we’re “on,” move the player
            if (playersCroc == message.source && player->isOnCrocodile) {
                player->cords.x += (message.direction * message.speed);
            }

        }else if (message.source > 500) {
           //proiettile
           
        }

      
        //scoreCounter(player, 0);
                

        
        playersCroc = isPlayerOnCroc(game);
        
        
        
        

        

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
        if(player->cords.x < 0) {
            player->cords.x = 0;
        } else if (player->cords.x > COLS - FROG_LENGTH) {
            player->cords.x = COLS - FROG_LENGTH;
        }

        //clear();        
        werase(stdscr);
        printRiver();
        printGrass();
        printCrocodile(game->crocodiles);
        
        printFrog(player->cords.x, player->cords.y);
        
        
        writeData(game->gameToPipe[1], &game->player.cords, sizeof(Coordinates));


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
        wnoutrefresh(stdscr); // Se usi finestre aggiuntive, usa wnoutrefresh su quelle

        // Aggiorna effettivamente lo schermo una volta
        doupdate();

        usleep(1000);

        refresh(); 
        
    }
    // Da cambiare con schermata di vittoria e sconfitta
}

void stop(Game *game) {
    game->isRunning = 0;
    stopMusic();
    endwin();
    close(game->serverSocket);
    close(game->pipeFd[0]);
    close(game->gameToPipe[1]);
    close(game->gameToPipe[0]);
    close(game->pipeFd[1]);
    exit(0);

}




