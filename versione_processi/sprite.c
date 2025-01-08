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


void printMenu() {
    /*
mvprintw(0, 0, "██████╗░██╗░░░░░░█████╗░██╗░░░██╗");
mvprintw(1, 0, "██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝");
mvprintw(2, 0, "██████╔╝██║░░░░░███████║░╚████╔╝░");
mvprintw(3, 0, "██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░");
mvprintw(4, 0, "██║░░░░░███████╗██║░░██║░░░██║░░░");
mvprintw(5, 0, "╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░");
*/
    mvprintw(0, 0, "1. Start");
    mvprintw(1, 0, "2. Score");
    mvprintw(2, 0, "3. Exit");
}




void printDifficultyMenu(Game *game) {
    
    int c = 0;
    while (1)
    {
        mvprintw(0, 0, "1. Easy");
        mvprintw(1, 0, "2. Medium");
        mvprintw(2, 0, "3. Hard");
        switch (c) {

            case 0:
            //Da sostituire con la funzione printCursor
                mvwprintw(stdscr, 0, 0, ">");
                break;
            case 1:
                mvwprintw(stdscr, 1, 0, ">");
                break;
            case 2:
                mvwprintw(stdscr, 2, 0, ">");
                break;
        }

        int ch = getch();
        if(ch == KEY_DOWN && c < 2) {
            c++;
        }else if (ch == KEY_UP && c > 0) {
            c--;
        }
        if (ch == '\n') {
            //return c; nel caso che vogliamo fare una funzione di gestione del menu
            switch (c)
            {
            case 0:
                easyDifficult(game);
                break;
            case 1:
                mediumDifficult(game);
                break;
            case 2:
                hardDifficult(game);
                break;
            }
        }
        refresh();


        
     
    }
    
    
}




//  ▀ █ ▄