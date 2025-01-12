#include "player.h"





void movePlayer(Player *player, int pipeFd, int gameToPlayerFd) {
    usleep(1000);
    // Coordinates message;
    while (1) {
        
        readData(gameToPlayerFd, &player->cords, sizeof(Coordinates));
        int input = getch();

        switch (input) {
            case 'w':
            case 'W':
            case KEY_UP:
                player->cords.y -= FROG_HEIGHT;
                break;
            case 's':
            case 'S':
            case KEY_DOWN:
                player->cords.y += FROG_HEIGHT;
                break;
            case 'a':
            case 'A':
            case KEY_LEFT:
                player->cords.x -= FROG_LENGTH;
                break;
            case 'd':
            case 'D':   
            case KEY_RIGHT:
                player->cords.x += FROG_LENGTH;
                break;
                
            case ' ':
                if(!player->hasLaunchedGrenade) {
                    player->hasLaunchedGrenade = 1;
                    createGrenade(player, pipeFd, RIGHT);
                    createGrenade(player, pipeFd, LEFT);
                }
                break;
            default: 
                
                continue;
        }
        flushinp();

        if(player->cords.y < 0 + FROG_HEIGHT) {
            player->cords.y = 0 + FROG_HEIGHT;
        } else if (player->cords.y > GAME_LINES - 1) {
            player->cords.y = GAME_LINES - 1;
        }

        //la funzione dovrebbe successivamente chiamare sendPlayerCords per inviare l'input al server   
        
        writeData(pipeFd, &player->cords, sizeof(Coordinates));
        // sendPlayerCords(sockfd, player);
        
        
        
        // mvprintw(0, 50, "Player legge x = %d && y = %d", player->cords.x, player->cords.y);
    }
}


//non va un cazzo (dio merda)
int isPlayerOnCroc(Game *game) {
    int totalCrocodiles = (GAME_LINES - 4) * MAX_CROCODILES;

    for (int i = 0; i < totalCrocodiles; i++) {
        Crocodile *croc = &game->crocodiles[i];
        
        int leftX = croc->cords.x;
        int rightX = croc->cords.x + croc->sprite.length - 1;

        /*
        if (croc->cords.direction == -1) {
            // Se va verso sinistra, invertiamo
            leftX = croc->cords.x - (croc->sprite.length - 1);
            rightX = croc->cords.x;
        }
        */


        if (game->player.cords.y == croc->cords.y && 
            game->player.cords.x >= leftX && 
            game->player.cords.x <= rightX) {
            
            int relativeX = game->player.cords.x - leftX;
            
            game->player.isOnCrocodile = 1;
           
            game->player.cords.direction = croc->cords.direction;
            game->player.cords.speed = croc->cords.speed;
            
            /* returning the id of the crocodile we are on */
            return croc->cords.source;
        }
    }
    game->player.cords.direction = 0;
    game->player.cords.speed = 0;
    game->player.isOnCrocodile = 0;
    return 0;
}


int isPlayerOnGrass(Game *game){
    if (game->player.cords.y > GAME_LINES - 5 || game->player.cords.y < 13) {
        return 1;
    }
    return 0;

}


int isPlayerOnDen(Game *game) { 
    
    int distance = (COLS - (DEN_LENGTH * 5)) / 6; //distanza tra le tane
    int denX;
    for (int i = 1; i < 6; i++) {
        denX = (DEN_LENGTH + distance) * i;   //i calcoli sono giusti fidati 

        //non l'ho provato, se da errori è la y==4;
        if (game->player.cords.y == 8 && game->player.cords.x >= denX - DEN_LENGTH -3 && game->player.cords.x <= denX + DEN_LENGTH && game->closedDen[i - 1] == 0) {
            game->closedDen[i - 1] = 1;
            return i;  //ritorna l'id della tana 
        }

    }
    
    return 0;
}


//funzione per il movimento delle granate (da rivedere)


//TODO

void moveGrenade(Grenade *grenade, int pipeFd) {

   do
   {
        grenade->cords.x += grenade->speed * grenade->cords.direction;
        grenade->lifeSpan--;

        if (grenade->lifeSpan == 0) {
            printExplosion(grenade->cords.x - (GRENADE_LENGTH * grenade->cords.direction), grenade->cords.y);
            refresh();
            grenade->cords.x = -10;
            grenade->cords.y = -10;
            
        }
        

        writeData(pipeFd, &grenade->cords, sizeof(Coordinates));

        
        usleep(200000);

    }while (grenade->lifeSpan > 0);
   exit(0);
}

void createGrenade(Player *player, int pipeFd, int direction) {
    
    Grenade grenade;
    grenade.cords.x = player->cords.x + (GRENADE_LENGTH * direction);
    grenade.cords.y = player->cords.y - FROG_HEIGHT / 2;
    grenade.sprite.length = 1;   //da cambiare
    grenade.speed = 5;   

    grenade.lifeSpan = FROG_LENGTH * 2;   //da cambiare

    grenade.cords.direction = direction;

    if (direction == LEFT) {
        grenade.cords.source = GRENAD_LEFT_SOURCE; // 201
    } else if (direction == RIGHT) {
        grenade.cords.source = GRENAD_RIGHT_SOURCE; // 203
    } 

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) { 
        srand(time(NULL) + getpid()); 
        moveGrenade(&grenade, pipeFd);
        exit(0); 
    }

}


