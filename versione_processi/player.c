#include "player.h"
 



void movePlayer(Player *player, int sockfd) {

    char input = tolower(getch());      /* gestisco così anche le casistiche maiuscole (CAPS LOCK attivo) */

    switch (input) {
        case 'w':
            player->cords.y--;
            break;
        case 's':
            player->cords.y++;
            break;
        case 'a':
            player->cords.x--;
            break;
        case 'd':
            player->cords.x++;
            break;
        case ' ':

            //gestione delle granate

            //TODO

            break;
    }

    //la funzione dovrebbe successivamente chiamare sendPlayerCords per inviare l'input al server   

    sendPlayerCords(sockfd, player);

}

