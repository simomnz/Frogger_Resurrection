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
                player->cords.y--;
                break;
            case 's':
            case 'S':
            case KEY_DOWN:
                player->cords.y++;
                break;
            case 'a':
            case 'A':
            case KEY_LEFT:
                player->cords.x--;
                break;
            case 'd':
            case 'D':   
            case KEY_RIGHT:
                player->cords.x++;
                break;
                
            case ' ':

                //gestione delle granate
                printf("da implementare");
                //TODO

                break;
            default: 
                
                continue;
        }
            //flushinp();

        //la funzione dovrebbe successivamente chiamare sendPlayerCords per inviare l'input al server   
        writeData(pipeFd, &player->cords, sizeof(Coordinates));
        // sendPlayerCords(sockfd, player);
        
        
        
        // mvprintw(0, 50, "Player legge x = %d && y = %d", player->cords.x, player->cords.y);
    }
}

int isPlayerOnCroc(Game *game) {
    int totalCrocodiles = (LINES - 4) * MAX_CROCODILES;

    for (int i = 0; i < totalCrocodiles; i++) {
        Crocodile *croc = &game->crocodiles[i];
        
        // Se va verso destra
        int leftX = croc->cords.x;
        int rightX = croc->cords.x + croc->sprite.length - 1;
        
        if (croc->cords.direction == -1) {
            // Se va verso sinistra, invertiamo
            leftX = croc->cords.x - (croc->sprite.length - 1);
            rightX = croc->cords.x;
        }


        if (game->player.cords.y == croc->cords.y && 
            game->player.cords.x >= leftX && 
            game->player.cords.x <= rightX) {
            
            int relativeX = game->player.cords.x - leftX;
            
            game->player.isOnCrocodile = 1;
            return croc->cords.x + (croc->cords.direction * croc->cords.speed);
        }
    }
    
    game->player.isOnCrocodile = 0;
    return game->player.cords.x;
}

int isPlayerOnGrass(Game *game){
    if (game->player.cords.y == LINES_BORDER - 1 || game->player.cords.y == LINES_BORDER - 2) {
        return 1;
    }
    return 0;

}


int isPlayerOnDen(Game *game) {
    
    for (int i = 0; i < 5; i++) {

        //da cambiare e implementare l'array closedDen
        if (game->player.cords.x == COLS)  {
            return 1;
        }
    }
    return 0;
}


//funzione per il movimento delle granate (da rivedere)


//TODO

void moveGrenade(Grenade *grenade, int pipe) {

   do
   {
        grenade->cords.x += grenade->speed;
        grenade->lifeSpan--;

        if (grenade->lifeSpan == 0) {
            //TODO
            //kill(grenade->PID, SIGKILL);
        }

        writeData(pipe, grenade, sizeof(Grenade));

        //tempo di attesa (da cambiare)
        //usleep(200000);/* condition */

    }while (grenade->lifeSpan > 0);
   exit(0);
}

void createGrenade(Player *player, int pipe) {
    
    Grenade grenade;
    grenade.cords.x = player->cords.x;
    grenade.cords.y = player->cords.y;
    grenade.sprite.length = 1;   //da cambiare
    grenade.sprite = player->sprite;   //giusto per non dare errori (da cambiare)
    grenade.speed = 1;   //da 
    
    grenade.lifeSpan = 5;   //da cambiare

    moveGrenade(&grenade, pipe);
}


