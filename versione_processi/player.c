#include "player.h"
 



void movePlayer(Player *player, int sockfd) {

    char input = tolower(getch());      /* gestisco così anche le casistiche maiuscole (CAPS LOCK attivo) */

    switch (input) {
        case 'w':
        case KEY_UP:
            player->cords.y--;
            break;
        case 's':
        case KEY_DOWN:
            player->cords.y++;
            break;
        case 'a':
        case KEY_LEFT:
            player->cords.x--;
            break;
        case 'd':
        case KEY_RIGHT:
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

