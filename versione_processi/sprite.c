#include "sprite.h"



/*
void printFrog(int x, int y) {
    mvprintw(y, x, "#"); //player->sprite.texture);
}
*/

/*
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
*/


void printCrocodile(Crocodile *crocodile) {
    for (int i = 0; i < (MAX_CROCODILES * 12); i++) {
        if (crocodile[i].cords.x > 0 && crocodile[i].cords.x < COLS) {
            wchar_t crocodileSprite[CROCODILE_HEIGHT][CROCODILE_LENGTH] = {
                { L'n', L'n', L'n', L'n', L'n', L'n', L'▄', L'▄', L'▄', L'▄', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n' },
                { L'▄', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'▄', L'▄' },
                { L'▀', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'▀', L'▀' },
                { L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'▀', L'▀', L'▀', L'n', L'n', L'n', L'n', L'▀', L'▀', L'▀', L'n', L'n', L'n', L'n' }
            };

            short colors[CROCODILE_HEIGHT][CROCODILE_LENGTH] = {
                {CROC_0_1, CROC_0_2, CROC_0_3, CROC_0_4, CROC_0_5, CROC_0_6, CROC_0_7, CROC_0_8, CROC_0_9, CROC_0_10, CROC_0_11, CROC_0_12, CROC_0_13, CROC_0_14, CROC_0_15, CROC_0_16, CROC_0_17, CROC_0_18, CROC_0_19, CROC_0_20, CROC_0_21},
                {CROC_1_0, CROC_1_1, CROC_1_2, CROC_1_3, CROC_1_4, CROC_1_5, CROC_1_6, CROC_1_7, CROC_1_8, CROC_1_9, CROC_1_10, CROC_1_11, CROC_1_12, CROC_1_13, CROC_1_14, CROC_1_15, CROC_1_16, CROC_1_17, CROC_1_18, CROC_1_19, CROC_1_20},
                {CROC_2_1, CROC_2_2, CROC_2_3, CROC_2_4, CROC_2_5, CROC_2_6, CROC_2_7, CROC_2_8, CROC_2_9, CROC_2_10, CROC_2_11, CROC_2_12, CROC_2_13, CROC_2_14, CROC_2_15, CROC_2_16, CROC_2_17, CROC_2_18, CROC_2_19, CROC_2_20, CROC_2_21},
                {CROC_3_1, CROC_3_2, CROC_3_3, CROC_3_4, CROC_3_5, CROC_3_6, CROC_3_7, CROC_3_8, CROC_3_9, CROC_3_10, CROC_3_11, CROC_3_12, CROC_3_13, CROC_3_14, CROC_3_15, CROC_3_16, CROC_3_17, CROC_3_18, CROC_3_19, CROC_3_20, CROC_3_21}
            };

            if (crocodile[i].cords.direction == 1) {  // vanno a destra
                for (int row = 0; row < CROCODILE_HEIGHT; row++) {
                    for (int col = CROCODILE_LENGTH - 1; col >= 0; col--) {
                        short xx = crocodile[i].cords.x + (CROCODILE_LENGTH - col);
                        if (crocodileSprite[row][col] != L'n') {
                            USE_COLOR(colors[row][col]);
                            mvaddch(crocodile[i].cords.y + row, xx, crocodileSprite[row][col]);
                            attroff(COLOR_PAIR(colors[row][col]));
                        }
                    }
                }
            } else {  // vanno a sinistra
                for (int row = 0; row < CROCODILE_HEIGHT; row++) {
                    for (int col = 0; col < CROCODILE_LENGTH; col++) {
                        short xx = crocodile[i].cords.x + col + 1;
                        if (crocodileSprite[row][col] != L'n') {
                            USE_COLOR(colors[row][col]);
                            mvaddch(crocodile[i].cords.y + row, xx, crocodileSprite[row][col]);
                            attroff(COLOR_PAIR(colors[row][col]));
                        }
                    }
                }
            }
        }
    }
}

void printFrog(int x, int y) {
    // Definizione dello sprite della rana
    wchar_t frogSprite[FROG_HEIGHT][FROG_LENGTH] = {
        {L' ', L'n', L' ', L' ', L' ', L'n', L' '}, // Riga 0 (superiore)
        {L'▀', L' ', L' ', L' ', L' ', L' ', L'▀'}, // Riga 1
        {L'▄', L' ', L' ', L' ', L' ', L' ', L'▄'}, // Riga 2
        {L' ', L'▀', L'▀', L'▀', L'▀', L'▀', L' '}  // Riga 3 (inferiore)
    };

    // Definizione dei colori - nota: cambiato da wchar_t a short perché sono colori
    short colors[FROG_HEIGHT][FROG_LENGTH] = {
        {FROG_0_1, FROG_0_2, FROG_0_3, FROG_0_4, FROG_0_5, FROG_0_6, FROG_0_7},
        {FROG_1_1, FROG_1_2, FROG_1_3, FROG_1_4, FROG_1_5, FROG_1_6, FROG_1_7},
        {FROG_2_1, FROG_2_2, FROG_2_3, FROG_2_4, FROG_2_5, FROG_2_6, FROG_2_7},
        {FROG_3_1, FROG_3_2, FROG_3_3, FROG_3_4, FROG_3_5, FROG_3_6, FROG_3_7}
    };

    // Stampa dello sprite con (x, y) come angolo in basso a sinistra
    for (int row = 0; row < FROG_HEIGHT; row++) {
        for (int col = 0; col < FROG_LENGTH; col++) {
            if (frogSprite[row][col] != L'n') {
                USE_COLOR(colors[row][col]);
                // Calcola la coordinata Y in modo che la prima riga dello sprite sia stampata più in alto
                mvprintw(y - (FROG_HEIGHT - 1 - row), x + col, "%lc", frogSprite[row][col]);
                attroff(colors[row][col]);
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