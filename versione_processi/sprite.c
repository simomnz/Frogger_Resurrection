#include "sprite.h"



/*
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
*/


void printCrocodile(Crocodile *crocodile) {
    
    wchar_t crocodileSprite[CROCODILE_HEIGHT][CROCODILE_LENGTH] = {
        {L'n', L'n', L'n', L'n', L'n', L'n', L'▄', L'▄', L'▄', L'▄', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n'},
        {L'▄', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'▄', L'▄'},
        {L'▀', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'▀', L'▀'},
        {L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'▀', L'▀', L'▀', L'n', L'n', L'n', L'n', L'▀', L'▀', L'▀', L'n', L'n', L'n', L'n'}
    };
    short colors[CROCODILE_HEIGHT][CROCODILE_LENGTH] = {
        {CROC_0_1, CROC_0_2, CROC_0_3, CROC_0_4, CROC_0_5, CROC_0_6, CROC_0_7, CROC_0_8, CROC_0_9, CROC_0_10, CROC_0_11, CROC_0_12, CROC_0_13, CROC_0_14, CROC_0_15, CROC_0_16, CROC_0_17, CROC_0_18, CROC_0_19, CROC_0_20, CROC_0_21},
        {CROC_1_0, CROC_1_1, CROC_1_2, CROC_1_3, CROC_1_4, CROC_1_5, CROC_1_6, CROC_1_7, CROC_1_8, CROC_1_9, CROC_1_10, CROC_1_11, CROC_1_12, CROC_1_13, CROC_1_14, CROC_1_15, CROC_1_16, CROC_1_17, CROC_1_18, CROC_1_19, CROC_1_20},
        {CROC_2_1, CROC_2_2, CROC_2_3, CROC_2_4, CROC_2_5, CROC_2_6, CROC_2_7, CROC_2_8, CROC_2_9, CROC_2_10, CROC_2_11, CROC_2_12, CROC_2_13, CROC_2_14, CROC_2_15, CROC_2_16, CROC_2_17, CROC_2_18, CROC_2_19, CROC_2_20, CROC_2_21},
        {CROC_3_1, CROC_3_2, CROC_3_3, CROC_3_4, CROC_3_5, CROC_3_6, CROC_3_7, CROC_3_8, CROC_3_9, CROC_3_10, CROC_3_11, CROC_3_12, CROC_3_13, CROC_3_14, CROC_3_15, CROC_3_16, CROC_3_17, CROC_3_18, CROC_3_19, CROC_3_20, CROC_3_21}
    };
    
    for (int i = 0; i < (MAX_CROCODILES * ((COLS -20)/4)); i++) {
        
        int baseY = crocodile[i].cords.y - (CROCODILE_HEIGHT - 1); // Aggiustiamo y per l'altezza dello sprite
        if (crocodile[i].cords.direction == 1) { // vanno a destra
            for (int row = 0; row < CROCODILE_HEIGHT; row++) {
                for (int col = CROCODILE_LENGTH - 1; col >= 0; col--) {
                    short xx = crocodile[i].cords.x + (CROCODILE_LENGTH - col);
                    if (crocodileSprite[row][col] != L'n') {
                        USE_COLOR(colors[row][col]);
                        mvaddch(baseY + row, xx, crocodileSprite[row][col]);
                        //attroff(COLOR_PAIR(colors[row][col]));
                    }
                }
            }
        } else { // vanno a sinistra
            for (int row = 0; row < CROCODILE_HEIGHT; row++) {
                for (int col = 0; col < CROCODILE_LENGTH; col++) {
                    short xx = crocodile[i].cords.x + col + 1;
                    if (crocodileSprite[row][col] != L'n') {
                        USE_COLOR(colors[row][col]);
                        mvaddch(baseY + row, xx, crocodileSprite[row][col]);
                        //attroff(COLOR_PAIR(colors[row][col]));
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
                mvprintw(y - (FROG_HEIGHT - 1 - row), x + col, "%lc", frogSprite[row][col]);
                //attroff(COLOR_PAIR(colors[row][col]));
            }
        }
    }
}

void printDen(Game *game) {
    wchar_t denOpenSprite[DEN_HEIGHT][DEN_LENGTH] = {
        {L'▄', L' ', L' ', L' ', L' ', L' ', L'▄'}, // Riga 0 (superiore)
        {L'▀', L' ', L' ', L' ', L' ', L' ', L'▀'}, // Riga 1
        {L' ', L' ', L' ', L' ', L' ', L' ', L' '}, // Riga 2
        {L'n', L'▀', L' ', L' ', L' ', L'▀', L'n'}  // Riga 3 (inferiore)
    };

    short colorsOpen[DEN_HEIGHT][DEN_LENGTH] = {
        {DEN_0_1, DEN_0_2, DEN_0_3, DEN_0_4, DEN_0_5, DEN_0_6, DEN_0_7},
        {DEN_1_1, DEN_1_2, DEN_1_3, DEN_1_4, DEN_1_5, DEN_1_6, DEN_1_7},
        {DEN_2_1, DEN_2_2, DEN_2_3, DEN_2_4, DEN_2_5, DEN_2_6, DEN_2_7},
        {DEN_3_1, DEN_3_2, DEN_3_3, DEN_3_4, DEN_3_5, DEN_3_6, DEN_3_7}
    };

    wchar_t denClosedSprite[DEN_HEIGHT][DEN_LENGTH] = {
        {L'n', L' ', L' ', L'▄', L' ', L' ', L'n'}, // Riga 0 (superiore)
        {L'n', L' ', L' ', L' ', L' ', L' ', L'n'}, // Riga 1
        {L'▄', L' ', L' ', L' ', L' ', L' ', L'▄'}, // Riga 2
        {L' ', L' ', L' ', L' ', L' ', L' ', L' '}  // Riga 3 (inferiore)
    };

    short colorsClosed[DEN_HEIGHT][DEN_LENGTH] = {
        {OCC_DEN_0_1, OCC_DEN_0_2, OCC_DEN_0_3, OCC_DEN_0_4, OCC_DEN_0_5, OCC_DEN_0_6, OCC_DEN_0_7},
        {OCC_DEN_1_1, OCC_DEN_1_2, OCC_DEN_1_3, OCC_DEN_1_4, OCC_DEN_1_5, OCC_DEN_1_6, OCC_DEN_1_7},
        {OCC_DEN_2_1, OCC_DEN_2_2, OCC_DEN_2_3, OCC_DEN_2_4, OCC_DEN_2_5, OCC_DEN_2_6, OCC_DEN_2_7},
        {OCC_DEN_3_1, OCC_DEN_3_2, OCC_DEN_3_3, OCC_DEN_3_4, OCC_DEN_3_5, OCC_DEN_3_6, OCC_DEN_3_7}
    };


    // Calcolo delle posizioni
    int numDens = 5; // Numero di tane
    int distance = (COLS - (DEN_LENGTH * numDens)) / (numDens + 1); // Spaziatura tra le tane
    int y = 8; // Posizione verticale fissa
    int startX = distance; // Posizione iniziale per la prima tana

    for (int den = 0; den < numDens; den++) { // Itera per ogni tana
        int currentX = startX + den * (DEN_LENGTH + distance); // Posizione x della tana corrente
        if(game->closedDen[den] == 0) {

            for (int row = 0; row < DEN_HEIGHT; row++) {
                for (int col = 0; col < DEN_LENGTH; col++) {
                    if (denOpenSprite[row][col] != L'n') {
                        // Imposta il colore
                        USE_COLOR(colorsOpen[row][col]);
                        // Stampa il carattere nella posizione corretta
                        mvprintw(y - DEN_HEIGHT + row, currentX + col, "%lc", denOpenSprite[row][col]);
                        // Disattiva il colore
                        attroff(COLOR_PAIR(colorsOpen[row][col]));
                    }
                }
            }
        }else {
            for (int row = 0; row < DEN_HEIGHT; row++) {
                for (int col = 0; col < DEN_LENGTH; col++) {
                    if (denClosedSprite[row][col] != L'n') {
                        // Imposta il colore
                        USE_COLOR(colorsClosed[row][col]);
                        mvprintw(y - DEN_HEIGHT + row, currentX + col, "%lc", denClosedSprite[row][col]);
                        attroff(COLOR_PAIR(colorsClosed[row][col]));
                    }
                }
            }
        }
    }
}


/*
void printFrogger() {

    wchar_t froggerSprite[FROGGER_HEIGHT][FROGGER_LENGTH] = {
        {L'▄', L' ', L' ', L' ', L' ', L'n', L'▄', L' ', L' ', L' ', L' ', L'n', L'▄', L' ', L' ', L' ', L' ', L'n', L'▄', L' ', L' ', L' ', L' ', L'n', L'▄', L' ', L' ', L' ', L' ', L'n', L'▄', L' ', L' ', L' ', L' ', L'n', L'▄', L' ', L' ', L' ', L' ', L'n'},
        {L' ', L' ', L' ', L'▄', L'▄', L'n', L' ', L' ', L'▄', L' ', L' ', L'n', L' ', L' ', L'n', L' ', L' ', L'n', L' ', L' ', L'n', L'n', L'n', L'n', L' ', L' ', L'n', L'n', L'n', L'n', L' ', L' ', L' ', L'▄', L'▄', L'n', L' ', L' ', L'▄', L' ', L'▀', L'n'},
        {L' ', L' ', L' ', L'▀', L'▀', L'n', L' ', L' ', L'▀', L' ', L'▀', L'n', L' ', L' ', L'n', L' ', L' ', L'n', L' ', L' ', L'▄', L' ', L' ', L'n', L' ', L' ', L'▄', L' ', L' ', L'n', L' ', L' ', L' ', L'▀', L'▀', L'n', L' ', L' ', L'n', L' ', L' ', L'n'},
        {L' ', L' ', L' ', L'n', L'n', L'n', L' ', L' ', L'n', L' ', L' ', L'n', L' ', L' ', L' ', L' ', L' ', L'n', L' ', L' ', L' ', L' ', L' ', L'n', L' ', L' ', L' ', L' ', L' ', L'n', L' ', L' ', L' ', L' ', L' ', L'n', L' ', L' ', L'n', L' ', L' ', L'n'}
    };

    short colors[FROGGER_HEIGHT][FROGGER_LENGTH] = {
        {FROGGER_0_1, FROGGER_0_2, FROGGER_0_3, FROGGER_0_4, FROGGER_0_5, FROGGER_0_6, FROGGER_0_7, FROGGER_0_8, FROGGER_0_9, FROGGER_0_10, FROGGER_0_11, FROGGER_0_12, FROGGER_0_13, FROGGER_0_14, FROGGER_0_15, FROGGER_0_16, FROGGER_0_17, FROGGER_0_18, FROGGER_0_19, FROGGER_0_20, FROGGER_0_21, FROGGER_0_22, FROGGER_0_23, FROGGER_0_24, FROGGER_0_25, FROGGER_0_26, FROGGER_0_27, FROGGER_0_28, FROGGER_0_29, FROGGER_0_30, FROGGER_0_31, FROGGER_0_32, FROGGER_0_33, FROGGER_0_34, FROGGER_0_35, FROGGER_0_36, FROGGER_0_37, FROGGER_0_38, FROGGER_0_39, FROGGER_0_40, FROGGER_0_41, FROGGER_0_42},
        {FROGGER_1_1, FROGGER_1_2, FROGGER_1_3, FROGGER_1_4, FROGGER_1_5, FROGGER_1_6, FROGGER_1_7, FROGGER_1_8, FROGGER_1_9, FROGGER_1_10, FROGGER_1_11, FROGGER_1_12, FROGGER_1_13, FROGGER_1_14, FROGGER_1_15, FROGGER_1_16, FROGGER_1_17, FROGGER_1_18, FROGGER_1_19, FROGGER_1_20, FROGGER_1_21, FROGGER_1_22, FROGGER_1_23, FROGGER_1_24, FROGGER_1_25, FROGGER_1_26, FROGGER_1_27, FROGGER_1_28, FROGGER_1_29, FROGGER_1_30, FROGGER_1_31, FROGGER_1_32, FROGGER_1_33, FROGGER_1_34, FROGGER_1_35, FROGGER_1_36, FROGGER_1_37, FROGGER_1_38, FROGGER_1_39, FROGGER_1_40, FROGGER_1_41, FROGGER_1_42},
        {FROGGER_2_1, FROGGER_2_2, FROGGER_2_3, FROGGER_2_4, FROGGER_2_5, FROGGER_2_6, FROGGER_2_7, FROGGER_2_8, FROGGER_2_9, FROGGER_2_10, FROGGER_2_11, FROGGER_2_12, FROGGER_2_13, FROGGER_2_14, FROGGER_2_15, FROGGER_2_16, FROGGER_2_17, FROGGER_2_18, FROGGER_2_19, FROGGER_2_20, FROGGER_2_21, FROGGER_2_22, FROGGER_2_23, FROGGER_2_24, FROGGER_2_25, FROGGER_2_26, FROGGER_2_27, FROGGER_2_28, FROGGER_2_29, FROGGER_2_30, FROGGER_2_31, FROGGER_2_32, FROGGER_2_33, FROGGER_2_34, FROGGER_2_35, FROGGER_2_36, FROGGER_2_37, FROGGER_2_38, FROGGER_2_39, FROGGER_2_40, FROGGER_2_41, FROGGER_2_42},
        {FROGGER_3_1, FROGGER_3_2, FROGGER_3_3, FROGGER_3_4, FROGGER_3_5, FROGGER_3_6, FROGGER_3_7, FROGGER_3_8, FROGGER_3_9, FROGGER_3_10, FROGGER_3_11, FROGGER_3_12, FROGGER_3_13, FROGGER_3_14, FROGGER_3_15, FROGGER_3_16, FROGGER_3_17, FROGGER_3_18, FROGGER_3_19, FROGGER_3_20, FROGGER_3_21, FROGGER_3_22, FROGGER_3_23, FROGGER_3_24, FROGGER_3_25, FROGGER_3_26, FROGGER_3_27, FROGGER_3_28, FROGGER_3_29, FROGGER_3_30, FROGGER_3_31, FROGGER_3_32, FROGGER_3_33, FROGGER_3_34, FROGGER_3_35, FROGGER_3_36, FROGGER_3_37, FROGGER_3_38, FROGGER_3_39, FROGGER_3_40, FROGGER_3_41, FROGGER_3_42}
    };

    

      for (int row = 0; row < FROGGER_HEIGHT; row++) {
        for (int col = 0; col < FROGGER_LENGTH; col++) {
            if (froggerSprite[row][col] != L'n') {
                USE_COLOR(colors[row][col]);
                mvprintw((LINES/2) - (FROGGER_HEIGHT - 1 - row), (COLS/7) + col, "%lc", froggerSprite[row][col]);
                attroff(COLOR_PAIR(colors[row][col]));
            }
        }
    }
}
*/
/*
void printMenu() {

    printStart();
    printScore();
    printExit();
}

void printStart() {

    
}
*/
void printTime(time_t time) {
    USE_COLOR(WRITES);
    mvprintw(0, COLS - 10, "TIME: %ld", time);
}


void printCenteredArt(const char *art[], int numRows, int startRow, int color) {
    switch (color)
    {
    case 1 :
        USE_COLOR(BLUE_SIGN);
        break;
    case 2 :
        USE_COLOR(YELLOW_SIGN);
        break;
    case 3 :
        USE_COLOR(RED_SIGN);
        break;
    }
    for (int i = 0; i < numRows; i++) {
        int len = strlen(art[i]);
        int startCol = (COLS - len) / 2; // Calcola colonna per centrare orizzontalmente
        mvprintw(startRow + i, startCol, "%s", art[i]);
    }
}

void printMenu() {
    // Definizione delle pixel art

    USE_COLOR(MENU);
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
    attroff(COLOR_PAIR(MENU));

    const char *startArt[] = {
        "   SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTT         AAA               RRRRRRRRRRRRRRRRR   TTTTTTTTTTTTTTTTTTTTTTT",
        " SS:::::::::::::::ST:::::::::::::::::::::T        A:::A              R::::::::::::::::R  T:::::::::::::::::::::T",
        "S:::::SSSSSS::::::ST:::::::::::::::::::::T       A:::::A             R::::::RRRRRR:::::R T:::::::::::::::::::::T",
        "S:::::S     SSSSSSST:::::TT:::::::TT:::::T      A:::::::A            RR:::::R     R:::::RT:::::TT:::::::TT:::::T",
        "S:::::S            TTTTTT  T:::::T  TTTTTT     A:::::::::A             R::::R     R:::::RTTTTTT  T:::::T  TTTTTT",
        "S:::::S                    T:::::T            A:::::A:::::A            R::::R     R:::::R        T:::::T        ",
        " S::::SSSS                 T:::::T           A:::::A A:::::A           R::::RRRRRR:::::R         T:::::T        ",
        "  SS::::::SSSSS            T:::::T          A:::::A   A:::::A          R:::::::::::::RR          T:::::T        ",
        "    SSS::::::::SS          T:::::T         A:::::A     A:::::A         R::::RRRRRR:::::R         T:::::T        ",
        "       SSSSSS::::S         T:::::T        A:::::AAAAAAAAA:::::A        R::::R     R:::::R        T:::::T        ",
        "            S:::::S        T:::::T       A:::::::::::::::::::::A       R::::R     R:::::R        T:::::T        ",
        "            S:::::S        T:::::T      A:::::AAAAAAAAAAAAA:::::A      R::::R     R:::::R        T:::::T        ",
        "SSSSSSS     S:::::S      TT:::::::TT   A:::::A             A:::::A   RR:::::R     R:::::R      TT:::::::TT      ",
        "S::::::SSSSSS:::::S      T:::::::::T  A:::::A               A:::::A  R::::::R     R:::::R      T:::::::::T      ",
        "S:::::::::::::::SS       T:::::::::T A:::::A                 A:::::A R::::::R     R:::::R      T:::::::::T      ",
        " SSSSSSSSSSSSSSS         TTTTTTTTTTTAAAAAAA                   AAAAAAARRRRRRRR     RRRRRRR      TTTTTTTTTTT      ",
    };

    const char *scoreArt[] = {
        "SSSSSSSSSSSSSSS         CCCCCCCCCCCCC     OOOOOOOOO     RRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEE",
        " SS:::::::::::::::S     CCC::::::::::::C   OO:::::::::OO   R::::::::::::::::R  E::::::::::::::::::::E",
        "S:::::SSSSSS::::::S   CC:::::::::::::::C OO:::::::::::::OO R::::::RRRRRR:::::R E::::::::::::::::::::E",
        "S:::::S     SSSSSSS  C:::::CCCCCCCC::::CO:::::::OOO:::::::ORR:::::R     R:::::REE::::::EEEEEEEEE::::E",
        "S:::::S             C:::::C       CCCCCCO::::::O   O::::::O  R::::R     R:::::R  E:::::E       EEEEEE",
        "S:::::S            C:::::C              O:::::O     O:::::O  R::::R     R:::::R  E:::::E             ",
        " S::::SSSS         C:::::C              O:::::O     O:::::O  R::::RRRRRR:::::R   E::::::EEEEEEEEEE   ",
        "  SS::::::SSSSS    C:::::C              O:::::O     O:::::O  R:::::::::::::RR    E:::::::::::::::E   ",
        "    SSS::::::::SS  C:::::C              O:::::O     O:::::O  R::::RRRRRR:::::R   E:::::::::::::::E   ",
        "       SSSSSS::::S C:::::C              O:::::O     O:::::O  R::::R     R:::::R  E::::::EEEEEEEEEE   ",
        "            S:::::SC:::::C              O:::::O     O:::::O  R::::R     R:::::R  E:::::E             ",
        "            S:::::S C:::::C       CCCCCCO::::::O   O::::::O  R::::R     R:::::R  E:::::E       EEEEEE",
        "SSSSSSS     S:::::S  C:::::CCCCCCCC::::CO:::::::OOO:::::::ORR:::::R     R:::::REE::::::EEEEEEEE:::::E",
        "S::::::SSSSSS:::::S   CC:::::::::::::::C OO:::::::::::::OO R::::::R     R:::::RE::::::::::::::::::::E",
        "S:::::::::::::::SS      CCC::::::::::::C   OO:::::::::OO   R::::::R     R:::::RE::::::::::::::::::::E",
        " SSSSSSSSSSSSSSS           CCCCCCCCCCCCC     OOOOOOOOO     RRRRRRRR     RRRRRRREEEEEEEEEEEEEEEEEEEEEE",
    };

    const char *exitArt[] = {
        "EEEEEEEEEEEEEEEEEEEEEEXXXXXXX       XXXXXXXIIIIIIIIIITTTTTTTTTTTTTTTTTTTTTTT",
        "E::::::::::::::::::::EX:::::X       X:::::XI::::::::IT:::::::::::::::::::::T",
        "E::::::::::::::::::::EX:::::X       X:::::XI::::::::IT:::::::::::::::::::::T",
        "EE::::::EEEEEEEEE::::EX::::::X     X::::::XII::::::IIT:::::TT:::::::TT:::::T",
        "  E:::::E       EEEEEEXXX:::::X   X:::::XXX  I::::I  TTTTTT  T:::::T  TTTTTT",
        "  E:::::E                X:::::X X:::::X     I::::I          T:::::T        ",
        "  E::::::EEEEEEEEEE       X:::::X:::::X      I::::I          T:::::T        ",
        "  E:::::::::::::::E        X:::::::::X       I::::I          T:::::T        ",
        "  E:::::::::::::::E        X:::::::::X       I::::I          T:::::T        ",
        "  E::::::EEEEEEEEEE       X:::::X:::::X      I::::I          T:::::T        ",
        "  E:::::E                X:::::X X:::::X     I::::I          T:::::T        ",
        "  E:::::E       EEEEEEXXX:::::X   X:::::XXX  I::::I          T:::::T        ",
        "EE::::::EEEEEEEE:::::EX::::::X     X::::::XII::::::II      TT:::::::TT      ",
        "E::::::::::::::::::::EX:::::X       X:::::XI::::::::I      T:::::::::T      ",
        "E::::::::::::::::::::EX:::::X       X:::::XI::::::::I      T:::::::::T      ",
        "EEEEEEEEEEEEEEEEEEEEEEXXXXXXX       XXXXXXXIIIIIIIIII      TTTTTTTTTTT      ",
    };


    // Calcola le posizioni verticali per ogni blocco di pixel art
    int startArtRow = (LINES - (sizeof(startArt) / sizeof(startArt[0]) + sizeof(scoreArt) / sizeof(scoreArt[0]) + sizeof(exitArt) / sizeof(exitArt[0]))) / 4;
    int scoreArtRow = startArtRow + sizeof(startArt) / sizeof(startArt[0]) + startArtRow;
    int exitArtRow = scoreArtRow + sizeof(scoreArt) / sizeof(scoreArt[0]) + startArtRow;

    // Stampa le tre arti centrate, una sotto l'altra
    printCenteredArt(startArt, sizeof(startArt) / sizeof(startArt[0]), startArtRow, 1);
    printCenteredArt(scoreArt, sizeof(scoreArt) / sizeof(scoreArt[0]), scoreArtRow, 2);
    printCenteredArt(exitArt, sizeof(exitArt) / sizeof(exitArt[0]), exitArtRow, 3);
    refresh();
}



void printDifficultyMenu(Game *game) {
    
    int c = 0;
    while (1)
    {
       USE_COLOR(MENU);
        for (int i = 0; i < LINES; i++) {
            for (int j = 0; j < COLS; j++) {
                mvprintw(i, j, " ");
            }
        }
        attroff(COLOR_PAIR(MENU));

        const char *easyArt[] = {
            "                                                                                                ",
            "                                                                                                ",
            "EEEEEEEEEEEEEEEEEEEEEE               AAA                  SSSSSSSSSSSSSSS YYYYYYY       YYYYYYY",
            "E::::::::::::::::::::E              A:::A               SS:::::::::::::::SY:::::Y       Y:::::Y",
            "E::::::::::::::::::::E             A:::::A             S:::::SSSSSS::::::SY:::::Y       Y:::::Y",
            "EE::::::EEEEEEEEE::::E            A:::::::A            S:::::S     SSSSSSSY::::::Y     Y::::::Y",
            "  E:::::E       EEEEEE           A:::::::::A           S:::::S            YYY:::::Y   Y:::::YYY",
            "  E:::::E                       A:::::A:::::A          S:::::S               Y:::::Y Y:::::Y   ",
            "  E::::::EEEEEEEEEE            A:::::A A:::::A          S::::SSSS             Y:::::Y:::::Y    ",
            "  E:::::::::::::::E           A:::::A   A:::::A          SS::::::SSSSS         Y:::::::::Y     ",
            "  E:::::::::::::::E          A:::::A     A:::::A           SSS::::::::SS        Y:::::::Y      ",
            "  E::::::EEEEEEEEEE         A:::::AAAAAAAAA:::::A             SSSSSS::::S        Y:::::Y       ",
            "  E:::::E                  A:::::::::::::::::::::A                 S:::::S       Y:::::Y       ",
            "  E:::::E       EEEEEE    A:::::AAAAAAAAAAAAA:::::A                S:::::S       Y:::::Y       ",
            "EE::::::EEEEEEEE:::::E   A:::::A             A:::::A   SSSSSSS     S:::::S       Y:::::Y       ",
            "E::::::::::::::::::::E  A:::::A               A:::::A  S::::::SSSSSS:::::S    YYYY:::::YYYY    ",
            "E::::::::::::::::::::E A:::::A                 A:::::A S:::::::::::::::SS     Y:::::::::::Y    ",
            "EEEEEEEEEEEEEEEEEEEEEEAAAAAAA                   AAAAAAA SSSSSSSSSSSSSSS       YYYYYYYYYYYYY    "
        };

        const char *mediumArt[] = {
            "                                                                                                                                         ",
            "                                                                                                                                         ",
            "MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEEDDDDDDDDDDDDD        IIIIIIIIIIUUUUUUUU     UUUUUUUUMMMMMMMM               MMMMMMMM",
            "M:::::::M             M:::::::ME::::::::::::::::::::ED::::::::::::DDD     I::::::::IU::::::U     U::::::UM:::::::M             M:::::::M",
            "M::::::::M           M::::::::ME::::::::::::::::::::ED:::::::::::::::DD   I::::::::IU::::::U     U::::::UM::::::::M           M::::::::M",
            "M:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::EDDD:::::DDDDD:::::D  II::::::IIUU:::::U     U:::::UUM:::::::::M         M:::::::::M",
            "M::::::::::M       M::::::::::M  E:::::E       EEEEEE  D:::::D    D:::::D   I::::I   U:::::U     U:::::U M::::::::::M       M::::::::::M",
            "M:::::::::::M     M:::::::::::M  E:::::E               D:::::D     D:::::D  I::::I   U:::::D     D:::::U M:::::::::::M     M:::::::::::M",
            "M:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE     D:::::D     D:::::D  I::::I   U:::::D     D:::::U M:::::::M::::M   M::::M:::::::M",
            "M::::::M M::::M M::::M M::::::M  E:::::::::::::::E     D:::::D     D:::::D  I::::I   U:::::D     D:::::U M::::::M M::::M M::::M M::::::M",
            "M::::::M  M::::M::::M  M::::::M  E:::::::::::::::E     D:::::D     D:::::D  I::::I   U:::::D     D:::::U M::::::M  M::::M::::M  M::::::M",
            "M::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE     D:::::D     D:::::D  I::::I   U:::::D     D:::::U M::::::M   M:::::::M   M::::::M",
            "M::::::M    M:::::M    M::::::M  E:::::E               D:::::D     D:::::D  I::::I   U:::::D     D:::::U M::::::M    M:::::M    M::::::M",
            "M::::::M     MMMMM     M::::::M  E:::::E       EEEEEE  D:::::D    D:::::D   I::::I   U::::::U   U::::::U M::::::M     MMMMM     M::::::M",
            "M::::::M               M::::::MEE::::::EEEEEEEE:::::EDDD:::::DDDDD:::::D  II::::::II U:::::::UUU:::::::U M::::::M               M::::::M",
            "M::::::M               M::::::ME::::::::::::::::::::ED:::::::::::::::DD   I::::::::I  UU:::::::::::::UU  M::::::M               M::::::M",
            "M::::::M               M::::::ME::::::::::::::::::::ED::::::::::::DDD     I::::::::I    UU:::::::::UU    M::::::M               M::::::M",
            "MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEEDDDDDDDDDDDDD        IIIIIIIIII      UUUUUUUUU      MMMMMMMM               MMMMMMMM"
        };

        const char *hardArt[] = {
            "                                                                                                 ",
            "                                                                                                 ",
            "HHHHHHHHH     HHHHHHHHH               AAA               RRRRRRRRRRRRRRRRR   DDDDDDDDDDDDD        ",
            "H:::::::H     H:::::::H              A:::A              R::::::::::::::::R  D::::::::::::DDD     ",
            "H:::::::H     H:::::::H             A:::::A             R::::::RRRRRR:::::R D:::::::::::::::DD   ",
            "HH::::::H     H::::::HH            A:::::::A            RR:::::R     R:::::RDD:::::DDDDD:::::D  ",
            "  H:::::H     H:::::H             A:::::::::A             R::::R     R:::::R  D:::::D    D:::::D ",
            "  H:::::H     H:::::H            A:::::A:::::A            R::::R     R:::::R  D:::::D     D:::::D",
            "  H::::::HHHHH::::::H           A:::::A A:::::A           R::::RRRRRR:::::R   D:::::D     D:::::D",
            "  H:::::::::::::::::H          A:::::A   A:::::A          R:::::::::::::RR    D:::::D     D:::::D",
            "  H:::::::::::::::::H         A:::::A     A:::::A         R::::RRRRRR:::::R   D:::::D     D:::::D",
            "  H::::::HHHHH::::::H        A:::::AAAAAAAAA:::::A        R::::R     R:::::R  D:::::D     D:::::D",
            "  H:::::H     H:::::H       A:::::::::::::::::::::A       R::::R     R:::::R  D:::::D     D:::::D",
            "  H:::::H     H:::::H      A:::::AAAAAAAAAAAAA:::::A      R::::R     R:::::R  D:::::D    D:::::D ",
            "HH::::::H     H::::::HH   A:::::A             A:::::A   RR:::::R     R:::::RDD:::::DDDDD:::::D  ",
            "H:::::::H     H:::::::H  A:::::A               A:::::A  R::::::R     R:::::RD:::::::::::::::DD   ",
            "H:::::::H     H:::::::H A:::::A                 A:::::A R::::::R     R:::::RD::::::::::::DDD     ",
            "HHHHHHHHH     HHHHHHHHHAAAAAAA                   AAAAAAARRRRRRRR     RRRRRRRDDDDDDDDDDDDD        "
        };

        // Calcola le posizioni verticali per ogni blocco di pixel art
        int easyArtRow = (LINES - (sizeof(easyArt) / sizeof(easyArt[0]) + sizeof(mediumArt) / sizeof(mediumArt[0]) + sizeof(hardArt) / sizeof(hardArt[0]))) / 4;
        int mediumArtRow = easyArtRow + sizeof(easyArt) / sizeof(easyArt[0]) + easyArtRow;
        int hardArtRow = mediumArtRow + sizeof(mediumArt) / sizeof(mediumArt[0]) + easyArtRow;

        // Stampa le tre arti centrate, una sotto l'altra
        printCenteredArt(easyArt, sizeof(easyArt) / sizeof(easyArt[0]), easyArtRow, 1);
        printCenteredArt(mediumArt, sizeof(mediumArt) / sizeof(mediumArt[0]), mediumArtRow, 2);
        printCenteredArt(hardArt, sizeof(hardArt) / sizeof(hardArt[0]), hardArtRow, 3);
        refresh();

        switch (c) {

            case 0:
                printFrog(10, LINES/5);

                break;
            case 1:
                printFrog(10, LINES/2);
                break;
            case 2:
                printFrog(10, LINES -12);
                break;
        }

        int ch = getch();
        if(ch == KEY_DOWN && c < 2) {
            c++;
        }else if (ch == KEY_UP && c > 0) {
            c--;
        }
        if (ch == '\n') {
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

    }
    
    
}


//  ▀ █ ▄

void printRiver() {
                
    USE_COLOR(RIVER);
    for (int i = 12; i < LINES -4; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
    attroff(COLOR_PAIR(RIVER));
    

}

void printDenRiver() {
                
    USE_COLOR(RIVER);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
    attroff(COLOR_PAIR(GRASS));

}

void printGrass() {
                
    USE_COLOR(GRASS);
    for (int i = 8; i < 13; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
        
    }
    for(int i = LINES -1; i > LINES - 5; i--) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
    //attroff(COLOR_PAIR(GRASS));

}


void printScoreBoard(int score, int lives) {
    USE_COLOR(WRITES);
    mvprintw(0, 0, "LIVES: %d", lives);
    mvprintw(0, COLS/2 -5, "SCORE: %d", score);
}


void printGrenade(int x, int y) {
    wchar_t grenadeSprite[GRENADE_HEIGHT][GRENADE_LENGTH] = {
        {L'▄', L' ', L' '},
        {L' ', L' ', L' '}
    };
    
    short colors[GRENADE_HEIGHT][GRENADE_LENGTH] = {
        {GRENADE_0_1, GRENADE_0_2, GRENADE_0_3},
        {GRENADE_1_1, GRENADE_1_2, GRENADE_1_3}
    };

    for (int row = 0; row < GRENADE_HEIGHT; row++) {
        for (int col = 0; col < GRENADE_LENGTH; col++) {
            if (grenadeSprite[row][col] != L'n') {
                USE_COLOR(colors[row][col]);
                mvprintw(y + row, x + col, "%lc", grenadeSprite[row][col]);
                attroff(COLOR_PAIR(colors[row][col]));
            }
        }
    }



}


void printProjectile(int x, int y) {
    wchar_t projectileSprite[PROJECTILE_HEIGHT][PROJECTILE_LENGTH] = {
        {L'▀', L'▀', L'▀'}, 
    };

    short colors[PROJECTILE_HEIGHT][PROJECTILE_LENGTH] = {
        {PROJECTILE_0_1, PROJECTILE_0_2, PROJECTILE_0_3}
    };

    for (int row = 0; row < PROJECTILE_HEIGHT; row++) {
        for (int col = 0; col < PROJECTILE_LENGTH; col++) {
            if (projectileSprite[row][col] != L'n') {
                USE_COLOR(colors[row][col]);
                mvprintw(y + row, x + col, "%lc", projectileSprite[row][col]);
                attroff(COLOR_PAIR(colors[row][col]));
            }
        }
    } 
}


void printExplosion(int x, int y) {

    wchar_t explosionSprite[EXPLOSION_HEIGHT][EXPLOSION_LENGHT] = {
        {L' ', L' ', L' '}, 
        {L' ', L' ', L' '}, 
    };

    short colors[EXPLOSION_HEIGHT][EXPLOSION_LENGHT] = {
        {EXPLOSION_0_1, EXPLOSION_0_2, EXPLOSION_0_3},
        {EXPLOSION_1_1, EXPLOSION_1_2, EXPLOSION_1_3}
    };

    for (int row = 0; row < EXPLOSION_HEIGHT; row++) {
        for (int col = 0; col < EXPLOSION_LENGHT; col++) {
            if (explosionSprite[row][col] != L'n') {
                USE_COLOR(colors[row][col]);
                mvprintw(y + row, x + col, "%lc", explosionSprite[row][col]);
                attroff(COLOR_PAIR(colors[row][col]));
            }
        }
    }
}

void printShield(int x, int y) {
    wchar_t shieldSprite[SHIELD_HEIGHT][SHIELD_LENGHT] = {
        //è una matrice 13x6
        {L'n', L' ', L' ', L' ', L' ', L'n'}, 
        {L' ', L'n', L'n', L'n', L'n', L' '}, 
        {L' ', L'n', L'n', L'n', L'n', L' '}, 
        {L' ', L'n', L'n', L'n', L'n', L' '}, 
        {L' ', L'n', L'n', L'n', L'n', L' '}, 
        {L'n', L' ', L' ', L' ', L' ', L'n'},  
    };

    short colors[SHIELD_HEIGHT][SHIELD_LENGHT] = {
        {0, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, 0},
        {SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER},
        {SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER},
        {SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER},
        {SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER},
        {0, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, 0}
    };

    for (int row = 0; row < SHIELD_HEIGHT; row++) {
        for (int col = 0; col < SHIELD_LENGHT; col++) {
            if (shieldSprite[row][col] != L'n') {
                USE_COLOR(colors[row][col]);
                mvprintw(y + row, x + col, "%lc", shieldSprite[row][col]);
                attroff(COLOR_PAIR(colors[row][col]));
            }
        }
    } 

}

