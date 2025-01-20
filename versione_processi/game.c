#include "game.h"

/* Function to start the game */
void start(Game *game) {
    initscr();                        /* Initialize Ncurses */
    nodelay(stdscr, TRUE);            /* Non-blocking input */
    noecho();                         /* Don't echo input */
    cbreak();                         /* Disable line buffering */
    mousemask(ALL_MOUSE_EVENTS, NULL);/* Enable mouse events */
    keypad(stdscr, TRUE);             /* Enable keyboard input */
    curs_set(0);                      /* Hide the cursor */
    start_color();                    /* Start color functionality */
    setColors();                      /* Set colors */
    wrongTerminalSize(game);          /* Check terminal size */

    game->serverSocket = startServer();/* Start the server */
    game->isRunning = 1;              /* Set the game running flag */
    if (pipe(game->pipeFd) < 0) {     /* Create a pipe */
        perror("error in pipe creation");
        exit(-1);
    }

    initAudio();                      /* Initialize audio */
    
    /* Set all dens as open */
    for (int i = 0; i < 5; i++) {
        game->closedDen[i] = 0;
    }
        
    /* The Game start Running */
}

/* Function to run the game */
void run(Game *game) {

    /* Loading Game Effect Sounds */
    Mix_Chunk *explosionSound = Mix_LoadWAV("../music/explosionSound.mp3");
    Mix_Chunk *shieldHit = Mix_LoadWAV("../music/shieldHit.mp3");
    Mix_Chunk *winSound = Mix_LoadWAV("../music/winMusic.mp3");
    Mix_Chunk *loseSound = Mix_LoadWAV("../music/loseMusic.mp3");
    Mix_Chunk *occupiedDen = Mix_LoadWAV("../music/occupiedDen.mp3");
    Mix_Chunk *fallWater = Mix_LoadWAV("../music/fallWater.mp3");

    while (game->isRunning) {

        /* Loading and Playing Menu Music */
        Mix_PlayMusic(Mix_LoadMUS("../music/menuMusic.mp3"), -1);
        
        /* Menu */
        int wannaPlay = menu(game);
        if (!wannaPlay) {
            break;
        }
        Mix_HaltMusic();

        /* Loading and Playing Game Music */
        switch (game->difficulty) {
        case 1: 
            Mix_PlayMusic(Mix_LoadMUS("../music/easyModeMusic.mp3"), -1);    /* Easy Mode */
            break;
        case 2:
            Mix_PlayMusic(Mix_LoadMUS("../music/mediumModeMusic.mp3"), -1);  /* Medium Mode */
            break;
        case 3:
            Mix_PlayMusic(Mix_LoadMUS("../music/hardModeMusic.mp3"), -1);    /* Hard Mode */
            break;        
        }

        /* Creation of Crocodiles */
        createCrocodile(game->pipeFd, game->crocodiles, game);
        
        /* Initialising Player Parameters */
        Player *player = &game->player;
        player->lives = 3;
        player->score = 0;
        player->cords.speed = 1;
        player->cords.type = 'f';

        /* Setting SpawnPoint */
        Coordinates spawnPoint = {(COLS-1)/2, GAME_LINES -1};
        player->cords.x = spawnPoint.x;
        player->cords.y = spawnPoint.y;
        
        /* Initialising Control's Structs and Variables */
        Coordinates message;        
        Crocodile *crocodile = game->crocodiles;
        Projectile *projectile = game->projectiles;
        Grenade grenadeLeft;
        Grenade grenadeRight;
        
        time_t mancheTime;
        short playersCroc = 0;        /* Index of the crocodile where the player stands on, initialized to -1 indicating no crocodile */
        short playersDen = -1;        /* Index of the den where the player stands on, initialized to -1 indicating no den */
        short clearCounter = 0;       /* Counter to clear the screen every 1000 game cycles */
        short grenadeLeftHit = 0;     /* Set to 1 if the left Grenade was hit */
        short grenadeRightHit = 0;    /* Set to 1 if the right Grenade was hit */
        time_t timeCounter = time(NULL) + game->timeDifficulty;  /* Manche Max Time */
        short occupiedDens = 0;       /* Counter for occupied Dens, if equal 5 you win */

        /* Client-Server Communication via Socket */
        sendPlayerCords(player, game->serverSocket);

        /* THE GAME */
        while (1) {
            
            clearCounter++;           /* Increasing the clear counter */

            recvPlayerCords(player, game->serverSocket);   /* Client-Server Communication via Socket */

            /* Check if the player has shot a Grenade */
            if (player->cords.flag == 1) {
                grenadeRight = createGrenade(player, game->pipeFd[1], 1);   
                grenadeLeft = createGrenade(player, game->pipeFd[1], -1);
            }
            
            /* Pipe Communication, reading Cords of Crocodiles, Projectiles and Grenades */
            readData(game->pipeFd[0], &message, sizeof(Coordinates));
            
            /* Message from a Crocodile */
            if (message.source > 0 && message.source < 200 && message.type == 'c') {
                crocodile[message.source -1].cords = message;

                /* Check if the Crocodile has shot a Projectile */
                if (crocodile[message.source - 1].cords.flag == 1) {
                    createProjectile(game->pipeFd, crocodile[message.source - 1], game);
                }

                /* If that croc’s PID == the croc we’re “on,” move the player */
                if (playersCroc == message.source && player->isOnCrocodile) {
                    player->cords.x += (message.direction * message.speed);
                }

            /* Message from a Grenade */
            } else if (message.source > 200 && message.source < 300 && message.type == 'g') {
                if(message.x == -15 && message.y == -15) {  /* If the Grenade is exploded */
                    player->cords.flag = 0;                 /* Set Player flag to 0, he can now shoot again */
                    Mix_PlayChannel(-1, fallWater, 0);      /* Playing fall in water Sound */
                } 
                
                /* Check which Grenade is the message */
                if(message.source == 201 ) {
                    grenadeLeft.cords = message;
                } else if (message.source == 203) {
                    grenadeRight.cords = message;
                }

            /* Message from a Projectile */
            } else if (message.source > 300 && message.source < (300 + NUM_PROJECTILES +1) && message.type == 'p') {
                projectile[message.source - 301].cords = message;
            }
            
            /* Check Collisions */
            playersCroc = isPlayerOnCroc(game);
            playersDen = isPlayerOnDen(game);

            /* If the frog is on a free Den */
            if(playersDen < 10 && playersDen >= 0) {
                scoreCounter(player, 100);
                scoreCounter(player, (GAME_LINES - player->cords.y)/4 * 10);
                scoreCounter(player, (timeCounter - mancheTime) * 10);
                Mix_PlayChannel(-1, occupiedDen, 0);
                occupiedDens++;
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
                timeCounter = time(NULL) + game->timeDifficulty;

            } else if (playersDen == 10) {   /* If the frog is on an occupied Den */
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

            /* If the Player falls in the water */            
            if(player->isOnCrocodile == 0 && !isPlayerOnGrass(game) && GODMODE || (timeCounter - mancheTime) == 0) {
                player->lives--;
                scoreCounter(player, (GAME_LINES - player->cords.y)/4 * 10);
                Mix_PlayChannel(-1, fallWater, 0);
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
                resetCrocodile(game->crocodiles, game);
                resetProjectile(game->projectiles);
                createCrocodile(game->pipeFd, game->crocodiles, game);
                clear();
                
                timeCounter = time(NULL) + game->timeDifficulty;
            }

            /* Lose condition, no life remaining */
            if (player->lives == 0) {
                resetCrocodile(game->crocodiles, game);
                resetProjectile(game->projectiles);
                for (int i = 0; i < 5; i++) {
                    game->closedDen[i] = 0;
                }
                free(game->crocodiles);
                free(game->projectiles);
                grenadeLeft.cords.x = -15;
                grenadeLeft.cords.y = -15;
                kill(grenadeLeft.PID, SIGKILL);
                kill(grenadeRight.PID, SIGKILL);
                Mix_HaltMusic();
                Mix_PlayChannel(-1, loseSound, 0);
                loseMenu();
                
                break;
            }
            
            /* Clearing once in a while */
            if(clearCounter == 1000) {
                clear();
                clearCounter = 0;
            }
        
            /* The player can't go outside the Game Screen */
            if(player->cords.x < 0) {
                player->cords.x = 0;
            } else if (player->cords.x > COLS - FROG_LENGTH) {
                player->cords.x = COLS - FROG_LENGTH;
            }

            /* Screen Erasing */
            werase(stdscr);

            /* Printing all the Game's Sprites */
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

            /* Check Grenade Collisions */
            grenadeLeftHit = doesProjectileHitGrenade(game, grenadeLeft);
            grenadeRightHit = doesProjectileHitGrenade(game, grenadeRight);

            /* Left Grenade and Projectiles collision */
            if(grenadeLeftHit >= 0) {
                game->projectiles[grenadeLeftHit].cords.x = -10;
                game->projectiles[grenadeLeftHit].cords.y = -10;
                printExplosion(grenadeLeft.cords.x, grenadeLeft.cords.y);
                Mix_PlayChannel(-1, explosionSound, 0);
                scoreCounter(player, 100);
                player->score += 150;
                grenadeLeft.cords.x = -15;
                grenadeLeft.cords.y = -15;
                kill(grenadeLeft.PID, SIGKILL);
                kill(game->projectiles[grenadeLeftHit].PID, SIGKILL);
                refresh();
            }
            
            /* Right Grenade and Projectiles collision */
            if(grenadeRightHit >= 0) {
                game->projectiles[grenadeRightHit].cords.x = -10;
                game->projectiles[grenadeRightHit].cords.y = -10;
                printExplosion(grenadeRight.cords.x, grenadeRight.cords.y);
                Mix_PlayChannel(-1, explosionSound, 0);
                scoreCounter(player, 100);
                grenadeRight.cords.x = -15;
                grenadeRight.cords.y = -15;
                kill(grenadeRight.PID, SIGKILL);
                kill(game->projectiles[grenadeRightHit].PID, SIGKILL);
                refresh();
            }

            /* Check if a Projectile hit the Player */
            int projectHit = doesProjectileHitPlayer(game);

            if(projectHit) {
                player->lives--;
                resetCrocodile(game->crocodiles, game);
                createCrocodile(game->pipeFd, game->crocodiles, game);
                resetProjectile(game->projectiles);
                printShield(player->cords.x, player->cords.y);
                printFrog(player->cords.x, player->cords.y);
                Mix_PlayChannel(-1, shieldHit, 0);
                refresh();
                player->cords.x = spawnPoint.x;
                player->cords.y = spawnPoint.y;
                timeCounter = time(NULL) + game->timeDifficulty;
            }

            /* Printing Frog, it has to be the last one */
            printFrog(player->cords.x, player->cords.y);

            /* Client-Server Communication */
            sendPlayerCords(player, game->serverSocket);

            /* Win Condition, no free Den remaining */
            if(occupiedDens == 5) {
                for (int i = 0; i < 5; i++) {
                    game->closedDen[i] = 0;
                }
                occupiedDens = 0;  

                scoreCounter(player, player->lives * 1000);
                resetProjectile(game->projectiles);
                resetCrocodile(game->crocodiles, game);
                free(game->crocodiles);
                free(game->projectiles);
                grenadeLeft.cords.x = -15;
                grenadeLeft.cords.y = -15;
                kill(grenadeLeft.PID, SIGKILL);
                kill(grenadeRight.PID, SIGKILL);
                Mix_HaltMusic();
                Mix_PlayChannel(-1, winSound, 0);
                winMenu();
                break;
            }

            /* Screen Refresh */
            wnoutrefresh(stdscr); 
            doupdate();
            refresh(); 

            /* Little Delay to make the Game Work smooth and well */
            usleep(1000);
        }
    }
    /* Stop Game Music */
    Mix_HaltMusic();
}

/* Close the Game */
void stop(Game *game) {
    game->isRunning = 0;
    Mix_HaltMusic();
    endwin();
    close(game->serverSocket);
    close(game->pipeFd[0]);
    close(game->pipeFd[1]);
    exit(0);
}
