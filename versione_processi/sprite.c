#include "sprite.h"




void printFrog(int x, int y) {
    mvprintw(y, x, "#"); //player->sprite.texture);
}


void printCrocodile(Crocodile *crocodile, int numCroc) {
    for (int i = 0; i < numCroc; i++) {
        mvprintw(crocodile[i].cords.y, crocodile[i].cords.x, "COCCODRILLO"); //crocodile[i].sprite.texture);
    }


}