#include "sprite.h"




void printFrog(Player *player) {
    mvprintw(player->cords.y, player->cords.x, "#"); //player->sprite.texture);
}


void printCrocodile(Crocodile *crocodile, int numCroc) {
    for (int i = 0; i < numCroc; i++) {
        mvprintw(crocodile[i].cords.y, crocodile[i].cords.x, "---"); //crocodile[i].sprite.texture);
    }
}