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
    wrongTerminalSize(game);

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
    
    // menu(game);
}


void run(Game *game) {


    //ha rotto il cazzo sta musica

    //startMusic(loadMusic("../music/gameMusic.mp3"));

    
    //clear();
    while (game->isRunning) {
        //wbkgd(stdscr, COLOR_PAIR(RIVER));
        // recvPlayerCords(player, game->serverSocket);
        
        int wannaPlay = menu(game);
        if (!wannaPlay) {
            break;
        }
        
        createCrocodile(game->pipeFd, game->crocodiles, game);
        //resetCrocodile(game->crocodiles, game->pipeToCroc[1]);
        Mix_Chunk *jumpSound = loadSound("../music/jumpSound.mp3");
    
        
        Player *player = &game->player;
        player->lives = 3;
        player->score = 0;



        Coordinates spawnPoint = {(COLS-1)/2, GAME_LINES -1};
        player->cords.x = spawnPoint.x;
        player->cords.y = spawnPoint.y;
        player->cords.speed = 1;
    

        

        
        pid_t pidPlayer = fork();
        if (pidPlayer == 0) {
            close(game->pipeFd[0]);
            close(game->gameToPipe[1]);
            movePlayer(player, game->pipeFd[1], game->gameToPipe[0]);
            exit(0);
        }

        //close(game->pipeFd[1]);
        close(game->gameToPipe[0]);

        
        Coordinates message; // = {0, 0, 0, 0};

        Crocodile *crocodile = game->crocodiles;

        Projectile *projectile = game->projectiles;


        Grenade grenadeLeft;
        Grenade grenadeRight;
        
        time_t mancheTime;

        int count = 0;
        int playersCroc = 0;
        int playersDen = 0;
        int clearCounter = 0;
        time_t timeCounter = time(NULL) + game->timeDifficulty;

        while (1) {
            
            clearCounter++;
            readData(game->pipeFd[0], &message, sizeof(Coordinates));
            // mvprintw(0, 25, "Leggo x = %d && y = %d", player->cords.x, player->cords.y);
            if (message.source == 0) {
                player->cords = message;

                //da riattivare
                //stopSound(jumpSound); 
                //playSound(jumpSound);

            } else if (message.source > 0 && message.source < 200) {
                crocodile[message.source -1].cords = message;
                // if ((crocodile[message.source - 1].PID ==  playersCroc) && (player->isOnCrocodile == 1)) {
                //     player->cords.x += (crocodile[message.source - 1].cords.direction * crocodile[message.source - 1].cords.speed);
                // }
                if (crocodile[message.source - 1].cords.flag == 1) {
                    createProjectile(game->pipeFd, crocodile[message.source - 1], game);
                }

                // 2) If that croc’s PID == the croc we’re “on,” move the player
                if (playersCroc == message.source && player->isOnCrocodile) {
                    player->cords.x += (message.direction * message.speed);
                }

            }else if (message.source > 200 && message.source < 300) {
                if(message.x == -10 && message.y == -10) {
                    player->cords.flag = 0;
                } 
                
                if(message.source == 201 ) {
                    grenadeLeft.cords = message;
                } else if (message.source == 203) {
                    grenadeRight.cords = message;
                }
            }else if (message.source >= 300 && message.source < 350) { //proiettile
                
                // if (message.x == -10 && message.y == -10) {
                //     crocodile[message.source - 301].cords.flag = 0;
                // }
                projectile[message.source - 301].cords = message;
            }
            
            
            
            playersCroc = isPlayerOnCroc(game);
            
            playersDen = isPlayerOnDen(game);


            //funzionante   
            if(playersDen) {
                scoreCounter(player, 100);
                scoreCounter(player, (GAME_LINES - player->cords.y)/4 * 10);
                scoreCounter(player, (timeCounter - mancheTime) * 10);
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
            }

            //se vuoi fai funzione isPlayerOnWater       
            
            
            if(player->isOnCrocodile == 0 && !isPlayerOnGrass(game) && GODMODE || (timeCounter - mancheTime) == 0) {  //aggiungere is player on den (in realtà non necessario)
                if (player->lives == 0) {
                    resetCrocodile(game->crocodiles, game);
                    free(game->crocodiles);
                    free(game->projectiles);
                    break;
                }

                player->lives--;
                scoreCounter(player, (GAME_LINES - player->cords.y)/4 * 10);
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
                resetCrocodile(game->crocodiles, game);
                free(game->projectiles);
                createCrocodile(game->pipeFd, game->crocodiles, game);
                clear();
                
                timeCounter = time(NULL) + game->timeDifficulty;
            }
            
            if(clearCounter == 1000) {
                clear();
                clearCounter = 0;
            }
        
            

            if(player->cords.x < 0) {
                player->cords.x = 0;
            } else if (player->cords.x > COLS - FROG_LENGTH) {
                player->cords.x = COLS - FROG_LENGTH;
            }
        
            werase(stdscr);
            
            printRiver();
            printCrocodile(game->crocodiles);
            printGrass();
            printGrenade(grenadeLeft.cords.x, grenadeLeft.cords.y);
            printGrenade(grenadeRight.cords.x, grenadeRight.cords.y);
            printDenRiver();
            printDen(game);
            mancheTime = time(NULL);
            printProjectile(game->projectiles);
            printTime(timeCounter - mancheTime);
            printScoreBoard(player->score, player->lives);

            int projectHit = doesProjectileHitPlayer(game);

            if(projectHit >= 0) {
                player->lives--;
                kill(game->projectiles[projectHit].PID, SIGKILL);
                waitpid(game->projectiles[projectHit].PID, NULL, 0);
                game->projectiles[projectHit].cords.x = -10;
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
            }


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
            wnoutrefresh(stdscr); 

            doupdate();

            usleep(1000);

            refresh(); 
        }
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




