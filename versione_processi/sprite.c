#include "sprite.h"




void printFrog(int x, int y) {
    mvprintw(y, x, "#"); //player->sprite.texture);
}


void printCrocodile(Crocodile *crocodile) { 
    for (int i = 0; i < (MAX_CROCODILES * LINES); i++) {
        if (crocodile[i].cords.x > 0 && crocodile[i].cords.x < COLS &&
            crocodile[i].cords.y > 0 && crocodile[i].cords.y < LINES) {
            mvprintw(crocodile[i].cords.y, crocodile[i].cords.x, "C"); // O sprite.texture
        }
    }
}
  