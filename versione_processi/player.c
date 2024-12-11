#include "player.h"
 



void movePlayer(Player *player, int sockfd) {

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
        
    }

    //la funzione dovrebbe successivamente chiamare sendPlayerCords per inviare l'input al server   

    sendPlayerCords(sockfd, player);
}


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



