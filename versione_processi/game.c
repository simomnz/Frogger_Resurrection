#include "game.h"
#include <ncurses.h>

void start(Game *game) {
    initscr();   
    nodelay(stdscr, TRUE);   
    noecho();       
    cbreak();
    mousemask(ALL_MOUSE_EVENTS, NULL);
    keypad(stdscr, TRUE);   
    curs_set(0);
    start_color();  
    //use_default_colors();
    setColors();
    wrongTerminalSize(game);

    game->serverSocket = startServer();
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
    
   
    for (int i = 0; i < 5; i++) {
        game->closedDen[i] = 0;
    }
        
    

    /*set all dens as open*/

    // menu(game);
}


void run(Game *game) {

    //inserisco l'audio esplosione:
    Mix_Chunk *explosionSound = loadSound("../music/explosionSound.mp3");
    Mix_Chunk *shieldHit = loadSound("../music/shieldHit.mp3");
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
        switch (game->difficulty)
        {
        case 1:
            startMusic(loadMusic("../music/easyModeMusic.mp3")); 
            break;
        case 2:
            startMusic(loadMusic("../music/mediumModeMusic.mp3"));
            break;
        case 3:
            startMusic(loadMusic("../music/hardModeMusic.mp3"));
            break;        
        default:
            break;
        }
        createCrocodile(game->pipeFd, game->crocodiles, game);
        //resetCrocodile(game->crocodiles, game->pipeToCroc[1]);
        Mix_Chunk *winSound = loadSound("../music/winMusic.mp3");
        Mix_Chunk *loseSound = loadSound("../music/loseMusic.mp3");
    
        
        Player *player = &game->player;
        player->lives = 3;
        player->score = 0;



        Coordinates spawnPoint = {(COLS-1)/2, GAME_LINES -1};
        player->cords.x = spawnPoint.x;
        player->cords.y = spawnPoint.y;
        player->cords.speed = 1;
        player->cords.type = 'f';
    

        
            
    

        
        
        // pid_t pidPlayer = fork();
        // if (pidPlayer == 0) {
        //     close(game->pipeFd[0]);
        //     close(game->gameToPipe[1]);
        //     movePlayer(player, game->pipeFd[1], game->gameToPipe[0]);
        //     exit(0);
        // }

        // //close(game->pipeFd[1]);
        // close(game->gameToPipe[0]);

        
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
        int grenadeLeftHit = 0;
        int grenadeRightHit = 0;
        time_t timeCounter = time(NULL) + game->timeDifficulty;
        int occupiedDens = 0;

        
        sendPlayerCords(player, game->serverSocket);

        while (1) {
            
            clearCounter++;

            recvPlayerCords(player, game->serverSocket);
            // mvprintw(0, 25, "Leggo x = %d && y = %d", player->cords.x, player->cords.y);
            
            
            if (player->cords.flag == 1) {
                grenadeRight = createGrenade(player, game->pipeFd[1], 1);
                grenadeLeft = createGrenade(player, game->pipeFd[1], -1);
            }
            
            readData(game->pipeFd[0], &message, sizeof(Coordinates));
            
            if (message.source > 0 && message.source < 200 && message.type == 'c') {
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

            }else if (message.source > 200 && message.source < 300 && message.type == 'g') {
                if(message.x == -15 && message.y == -15) {
                    player->cords.flag = 0;
                    playSound(explosionSound);
                } 
                
                if(message.source == 201 ) {
                    grenadeLeft.cords = message;
                } else if (message.source == 203) {
                    grenadeRight.cords = message;
                }
            }else if (message.source > 300 && message.source < (300 + NUM_PROJECTILES +1) && message.type == 'p') { //proiettile
                // if (message.x == -10 && message.y == -10) {
                //     crocodile[message.source - 301].cords.flag = 0;
                // }
                projectile[message.source - 301].cords = message;
            }
            
            
            
            playersCroc = isPlayerOnCroc(game);
            
            playersDen = isPlayerOnDen(game);


            //funzionante   
            if(playersDen < 10 && playersDen >= 0) {
                scoreCounter(player, 100);
                scoreCounter(player, (GAME_LINES - player->cords.y)/4 * 10);
                scoreCounter(player, (timeCounter - mancheTime) * 10);
                occupiedDens++;
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
                timeCounter = time(NULL) + game->timeDifficulty;
            }else if (playersDen == 10) { //nel caso la tana è chiusa
                player->lives--;
                scoreCounter(player, (GAME_LINES - player->cords.y)/4 * 10);
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
                resetCrocodile(game->crocodiles, game);
                resetProjectile(game->projectiles);
                createCrocodile(game->pipeFd, game->crocodiles, game);
                clear();
                timeCounter = time(NULL) + game->timeDifficulty;
            }

            //se vuoi fai funzione isPlayerOnWater       
            
            
            if(player->isOnCrocodile == 0 && !isPlayerOnGrass(game) && GODMODE || (timeCounter - mancheTime) == 0) {  //aggiungere is player on den (in realtà non necessario)
                player->lives--;

                scoreCounter(player, (GAME_LINES - player->cords.y)/4 * 10);
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
                resetCrocodile(game->crocodiles, game);
                resetProjectile(game->projectiles);
                createCrocodile(game->pipeFd, game->crocodiles, game);
                clear();
                
                timeCounter = time(NULL) + game->timeDifficulty;
            }

            if (player->lives == 0) {
                resetCrocodile(game->crocodiles, game);
                resetProjectile(game->projectiles);
                for (int i = 0; i < 5; i++) {
                    game->closedDen[i] = 0;
                }
                free(game->crocodiles);
                free(game->projectiles);
                stopMusic();
                playSound(loseSound);
                loseMenu();
                
                break;
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
            printCrocodile(crocodile);
            printGrass();
            printGrenade(grenadeLeft.cords.x, grenadeLeft.cords.y);
            printGrenade(grenadeRight.cords.x, grenadeRight.cords.y);
            printDenRiver();
            printDen(game);
            mancheTime = time(NULL);
            printProjectile(projectile);
            printTime(timeCounter - mancheTime);
            printScoreBoard(player->score, player->lives);
            // refresh();
            grenadeLeftHit = doesProjectileHitGrenade(game, grenadeLeft);
            grenadeRightHit = doesProjectileHitGrenade(game, grenadeRight);

            if(grenadeLeftHit >= 0) {
                game->projectiles[grenadeLeftHit].cords.x = -10;
                game->projectiles[grenadeLeftHit].cords.y = -10;
                printExplosion(grenadeLeft.cords.x, grenadeLeft.cords.y);
                playSound(explosionSound);
                scoreCounter(player, 100);
                player->score += 150;
                grenadeLeft.cords.x = -15;
                grenadeLeft.cords.y = -15;
                kill(grenadeLeft.PID, SIGKILL);
                //waitpid(grenadeLeft.PID, NULL, 0);
                kill(game->projectiles[grenadeLeftHit].PID, SIGKILL);
                //waitpid(game->projectiles[grenadeLeftHit].PID, NULL, 0);
                refresh();
            }

            if(grenadeRightHit >= 0) {
                game->projectiles[grenadeRightHit].cords.x = -10;
                game->projectiles[grenadeRightHit].cords.y = -10;
                printExplosion(grenadeRight.cords.x, grenadeRight.cords.y);
                playSound(explosionSound);
                scoreCounter(player, 100);
                grenadeRight.cords.x = -15;
                grenadeRight.cords.y = -15;
                kill(grenadeRight.PID, SIGKILL);
                //waitpid(grenadeRight.PID, NULL, 0);
                kill(game->projectiles[grenadeRightHit].PID, SIGKILL);
                //waitpid(game->projectiles[grenadeRightHit].PID, NULL, 0);
                refresh();
            }


            int projectHit = doesProjectileHitPlayer(game);

            if(projectHit) {
                player->lives--;
                resetCrocodile(game->crocodiles, game);
                createCrocodile(game->pipeFd, game->crocodiles, game);
                //resetProjectile(game->projectiles);
                printShield(player->cords.x, player->cords.y);
                printFrog(player->cords.x, player->cords.y);
                playSound(shieldHit);
                refresh();
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
                timeCounter = time(NULL) + game->timeDifficulty;
            }


            printFrog(player->cords.x, player->cords.y);

            
            


            sendPlayerCords(player, game->serverSocket);

            if(occupiedDens == 5) {
                for (int i = 0; i < 5; i++) {
                    game->closedDen[i] = 0;
                }
                occupiedDens = 0;
      
                resetProjectile(game->projectiles);
                resetCrocodile(game->crocodiles, game);
                free(game->crocodiles);
                free(game->projectiles);
                stopMusic();
                playSound(winSound);
                winMenu();
                break;
            }
            wnoutrefresh(stdscr); 

            doupdate();

            usleep(1000);

            refresh(); 
        }
    }

    stopMusic();
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




