#include "player.h"




void movePlayer(Player *player, int pipeFd) {

    while (1) {
        /* code */
    
        int input = getch();


        //gestione del movimento del giocatore sul coccodrillo


        // if (player->isOnCrocodile) {
        //     player->cords.x += player->cords.direction;
        // }

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
            default: continue;
        }

        //la funzione dovrebbe successivamente chiamare sendPlayerCords per inviare l'input al server   
        writeData(pipeFd, &player->cords, sizeof(Coordinates));
        // sendPlayerCords(sockfd, player);
    }
}

//perchè passare il numero di coccodrilli? già presente in game
int isPlayerOnCroc(Game *game, unsigned short numCroc) {
    for (int i = 0; i < numCroc; i++) {
        Crocodile *croc = &game->crocodiles[i];

        // Controlla se il giocatore è sulla lunghezza del coccodrillo
        unsigned short onX = (game->player.cords.x >= croc->cords.x) &&
                   (game->player.cords.x <= croc->cords.x + croc->sprite.length);

        // Controlla se il giocatore è sulla stessa riga
        unsigned short onY = (game->player.cords.y == croc->cords.y);

        if (onX && onY) {
            game->player.isOnCrocodile = 1;
            game->player.cords.direction = croc->cords.direction;
            return true;
        }
    }

    // Se non è su nessun coccodrillo
    game->player.isOnCrocodile = 0;
    return false;
}


int isPlayerOnGrass(Game *game){
    if (game->player.cords.y == LINES_BORDER - 1) {
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


