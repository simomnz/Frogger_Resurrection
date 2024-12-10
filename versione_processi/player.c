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

            //TODO

            break;
    }

    //la funzione dovrebbe successivamente chiamare sendPlayerCords per inviare l'input al server   

    sendPlayerCords(sockfd, player);
}

