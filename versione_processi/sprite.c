#include "sprite.h"




void printFrog(int x, int y) {
    mvprintw(y, x, "#"); //player->sprite.texture);
}


void printCrocodile(Crocodile *crocodile) { 
    for (int i = 0; i < (MAX_CROCODILES * (LINES -4)); i++) {
        if (crocodile[i].cords.x > 0 && crocodile[i].cords.x < COLS) {

            //da cambiare con gli sprite
            if(crocodile[i].cords.direction == 1) {
                mvprintw(crocodile[i].cords.y, crocodile[i].cords.x, "C");
                mvprintw(crocodile[i].cords.y, crocodile[i].cords.x + 1, "r");
                mvprintw(crocodile[i].cords.y, crocodile[i].cords.x + 2, "o");
            } else {
                mvprintw(crocodile[i].cords.y, crocodile[i].cords.x, "C"); 
                mvprintw(crocodile[i].cords.y, crocodile[i].cords.x - 1, "r");
                mvprintw(crocodile[i].cords.y, crocodile[i].cords.x - 2, "o");
            }
        }
    }
}

