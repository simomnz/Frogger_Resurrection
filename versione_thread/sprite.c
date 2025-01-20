#include "sprite.h"




/*
   ▄████████    ▄███████▄    ▄████████  ▄█      ███        ▄████████    ▄████████ 
  ███    ███   ███    ███   ███    ███ ███  ▀█████████▄   ███    ███   ███    ███ 
  ███    █▀    ███    ███   ███    ███ ███▌    ▀███▀▀██   ███    █▀    ███    █▀  
  ███          ███    ███  ▄███▄▄▄▄██▀ ███▌     ███   ▀  ▄███▄▄▄       ███        
▀███████████ ▀█████████▀  ▀▀███▀▀▀▀▀   ███▌     ███     ▀▀███▀▀▀     ▀███████████ 
         ███   ███        ▀███████████ ███      ███       ███    █▄           ███ 
   ▄█    ███   ███          ███    ███ ███      ███       ███    ███    ▄█    ███ 
 ▄████████▀   ▄████▀        ███    ███ █▀      ▄████▀     ██████████  ▄████████▀  
                            ███    ███                                                                                                                                 
*/


/* Function to print a crocodile sprite on the screen */
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
    
    for (int i = 0; i < 26; i++) {
        
        int baseY = crocodile[i].cords.y - (CROCODILE_HEIGHT - 1);
        if (crocodile[i].cords.direction == 1) { /* Goes to the Right */
            for (int row = 0; row < CROCODILE_HEIGHT; row++) {
                for (int col = CROCODILE_LENGTH - 1; col >= 0; col--) {
                    short xx = crocodile[i].cords.x + (CROCODILE_LENGTH - col);
                    if (crocodileSprite[row][col] != L'n') {
                        USE_COLOR(colors[row][col]);
                        mvaddch(baseY + row, xx, crocodileSprite[row][col]);
                        
                    }
                }
            }
        } else { /* Goes to the Left */
            for (int row = 0; row < CROCODILE_HEIGHT; row++) {
                for (int col = 0; col < CROCODILE_LENGTH; col++) {
                    short xx = crocodile[i].cords.x + col + 1;
                    if (crocodileSprite[row][col] != L'n') {
                        USE_COLOR(colors[row][col]);
                        mvaddch(baseY + row, xx, crocodileSprite[row][col]);
                    }
                }
            }
        }
        
        
    }
}

/* Function to print a frog sprite on the screen */
void printFrog(int x, int y) {

    wchar_t frogSprite[FROG_HEIGHT][FROG_LENGTH] = {
        {L' ', L'n', L' ', L' ', L' ', L'n', L' '}, 
        {L'▀', L' ', L' ', L' ', L' ', L' ', L'▀'}, 
        {L'▄', L' ', L' ', L' ', L' ', L' ', L'▄'}, 
        {L' ', L'▀', L'▀', L'▀', L'▀', L'▀', L' '}  
    };

    short colors[FROG_HEIGHT][FROG_LENGTH] = {
        {FROG_0_1, FROG_0_2, FROG_0_3, FROG_0_4, FROG_0_5, FROG_0_6, FROG_0_7},
        {FROG_1_1, FROG_1_2, FROG_1_3, FROG_1_4, FROG_1_5, FROG_1_6, FROG_1_7},
        {FROG_2_1, FROG_2_2, FROG_2_3, FROG_2_4, FROG_2_5, FROG_2_6, FROG_2_7},
        {FROG_3_1, FROG_3_2, FROG_3_3, FROG_3_4, FROG_3_5, FROG_3_6, FROG_3_7}
    };

    for (int row = 0; row < FROG_HEIGHT; row++) {
        for (int col = 0; col < FROG_LENGTH; col++) {
            
            if (frogSprite[row][col] != L'n') {
                USE_COLOR(colors[row][col]);
                mvprintw(y - (FROG_HEIGHT - 1 - row), x + col, "%lc", frogSprite[row][col]);
            }
        }
    }
}

/* Function to print the den on the screen */
void printDen(Game *game) {
    wchar_t denOpenSprite[DEN_HEIGHT][DEN_LENGTH] = {
        {L'▄', L' ', L' ', L' ', L' ', L' ', L'▄'},
        {L'▀', L' ', L' ', L' ', L' ', L' ', L'▀'},
        {L' ', L' ', L' ', L' ', L' ', L' ', L' '},
        {L'n', L'▀', L' ', L' ', L' ', L'▀', L'n'} 
    };

    short colorsOpen[DEN_HEIGHT][DEN_LENGTH] = {
        {DEN_0_1, DEN_0_2, DEN_0_3, DEN_0_4, DEN_0_5, DEN_0_6, DEN_0_7},
        {DEN_1_1, DEN_1_2, DEN_1_3, DEN_1_4, DEN_1_5, DEN_1_6, DEN_1_7},
        {DEN_2_1, DEN_2_2, DEN_2_3, DEN_2_4, DEN_2_5, DEN_2_6, DEN_2_7},
        {DEN_3_1, DEN_3_2, DEN_3_3, DEN_3_4, DEN_3_5, DEN_3_6, DEN_3_7}
    };

    wchar_t denClosedSprite[DEN_HEIGHT][DEN_LENGTH] = {
        {L'n', L' ', L' ', L'▄', L' ', L' ', L'n'}, 
        {L'n', L' ', L' ', L' ', L' ', L' ', L'n'},
        {L'▄', L' ', L' ', L' ', L' ', L' ', L'▄'},
        {L' ', L' ', L' ', L' ', L' ', L' ', L' '}  
    };

    short colorsClosed[DEN_HEIGHT][DEN_LENGTH] = {
        {OCC_DEN_0_1, OCC_DEN_0_2, OCC_DEN_0_3, OCC_DEN_0_4, OCC_DEN_0_5, OCC_DEN_0_6, OCC_DEN_0_7},
        {OCC_DEN_1_1, OCC_DEN_1_2, OCC_DEN_1_3, OCC_DEN_1_4, OCC_DEN_1_5, OCC_DEN_1_6, OCC_DEN_1_7},
        {OCC_DEN_2_1, OCC_DEN_2_2, OCC_DEN_2_3, OCC_DEN_2_4, OCC_DEN_2_5, OCC_DEN_2_6, OCC_DEN_2_7},
        {OCC_DEN_3_1, OCC_DEN_3_2, OCC_DEN_3_3, OCC_DEN_3_4, OCC_DEN_3_5, OCC_DEN_3_6, OCC_DEN_3_7}
    };


    int numDens = 5;
    int distance = (COLS - (DEN_LENGTH * numDens)) / (numDens + 1); 
    int y = 8;
    int startX = distance; 

    for (int den = 0; den < numDens; den++) { 
        int currentX = startX + den * (DEN_LENGTH + distance); 
        if(game->closedDen[den] == 0) {

            for (int row = 0; row < DEN_HEIGHT; row++) {
                for (int col = 0; col < DEN_LENGTH; col++) {
                    if (denOpenSprite[row][col] != L'n') {
                        USE_COLOR(colorsOpen[row][col]);
                        mvprintw(y - DEN_HEIGHT + row, currentX + col, "%lc", denOpenSprite[row][col]);
                    }
                }
            }
        }else {
            for (int row = 0; row < DEN_HEIGHT; row++) {
                for (int col = 0; col < DEN_LENGTH; col++) {
                    if (denClosedSprite[row][col] != L'n') {
                        USE_COLOR(colorsClosed[row][col]);
                        mvprintw(y - DEN_HEIGHT + row, currentX + col, "%lc", denClosedSprite[row][col]);
                    }
                }
            }
        }
    }
}

/* Function to print the remaining time on the screen */
void printTime(time_t time) {
    USE_COLOR(WRITES);
    mvprintw(0, COLS - 10, "TIME: %ld", time);
}


void printCenteredArt(const char *art[], int numRows, int startRow, int color) {
    switch (color)
    {
    case 1 :
        attron(COLOR_PAIR(BLUE_SIGN) | A_BOLD);
        break;
    case 2 :
        attron(COLOR_PAIR(YELLOW_SIGN) | A_BOLD);
        break;
    case 3 :
        attron(COLOR_PAIR(RED_SIGN) | A_BOLD);
        break;
    }
    for (int i = 0; i < numRows; i++) {
        int len = strlen(art[i]);
        int startCol = (COLS - len) / 2;
        mvprintw(startRow + i, startCol, "%s", art[i]);
    }
}

void printMenu() {

    USE_COLOR(MENU);
    for (int i = 0; i < GAME_LINES; i++) {
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


    int startArtRow = (GAME_LINES - (sizeof(startArt) / sizeof(startArt[0]) + sizeof(scoreArt) / sizeof(scoreArt[0]) + sizeof(exitArt) / sizeof(exitArt[0]))) / 4;
    int scoreArtRow = startArtRow + sizeof(startArt) / sizeof(startArt[0]) + startArtRow;
    int exitArtRow = scoreArtRow + sizeof(scoreArt) / sizeof(scoreArt[0]) + startArtRow;

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
        for (int i = 0; i < GAME_LINES; i++) {
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

        int easyArtRow = (GAME_LINES - (sizeof(easyArt) / sizeof(easyArt[0]) + sizeof(mediumArt) / sizeof(mediumArt[0]) + sizeof(hardArt) / sizeof(hardArt[0]))) / 4;
        int mediumArtRow = easyArtRow + sizeof(easyArt) / sizeof(easyArt[0]) + easyArtRow;
        int hardArtRow = mediumArtRow + sizeof(mediumArt) / sizeof(mediumArt[0]) + easyArtRow;

        printCenteredArt(easyArt, sizeof(easyArt) / sizeof(easyArt[0]), easyArtRow, 1);
        printCenteredArt(mediumArt, sizeof(mediumArt) / sizeof(mediumArt[0]), mediumArtRow, 2);
        printCenteredArt(hardArt, sizeof(hardArt) / sizeof(hardArt[0]), hardArtRow, 3);
        refresh();

        switch (c) {

            case 0:
                printFrog(10, GAME_LINES/5);

                break;
            case 1:
                printFrog(10, GAME_LINES/2);
                break;
            case 2:
                printFrog(10, GAME_LINES -12);
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
                return;
                break;
            case 1:
                mediumDifficult(game);
                return;
                break;
            case 2:
                hardDifficult(game);
                return;
                break;
            }
        }

    }
    
    
}
/* Function to print the river on the screen */
void printRiver() {
    USE_COLOR(RIVER);
    for (int i = 12; i < GAME_LINES - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
    attroff(COLOR_PAIR(RIVER));
}

/* Function to print the den river on the screen */
void printDenRiver() {
    USE_COLOR(RIVER);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
    attroff(COLOR_PAIR(GRASS));
}

/* Function to print the grass on the screen */
void printGrass() {
    USE_COLOR(GRASS);
    for (int i = 8; i < 13; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
    for (int i = GAME_LINES - 1; i > GAME_LINES - 5; i--) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
}

/* Function to print the scoreboard on the screen */
void printScoreBoard(int score, int lives) {
    USE_COLOR(WRITES);
    mvprintw(0, 0, "LIVES: %d", lives);
    mvprintw(0, COLS / 2 - 5, "SCORE: %d", score);
}

/* Function to print a grenade sprite on the screen */
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

/* Function to print projectiles on the screen */
void printProjectile(Projectile *projectile) {
    wchar_t projectileSprite[PROJECTILE_HEIGHT][PROJECTILE_LENGTH] = {
        {L' ', L' ', L' '}
    };

    short colors[PROJECTILE_HEIGHT][PROJECTILE_LENGTH] = {
        {PROJECTILE_0_1, PROJECTILE_0_2, PROJECTILE_0_3}
    };

    for (int i = 0; i < NUM_PROJECTILES; i++) {
        for (int row = 0; row < PROJECTILE_HEIGHT; row++) {
            for (int col = 0; col < PROJECTILE_LENGTH; col++) {
                if (projectileSprite[row][col] != L'n') {
                    USE_COLOR(colors[row][col]);
                    mvprintw(projectile[i].cords.y + row, projectile[i].cords.x + col, "%lc", projectileSprite[row][col]);
                    attroff(COLOR_PAIR(colors[row][col]));
                }
            }
        }
    }
}

/* Function to print an explosion sprite on the screen */
void printExplosion(int x, int y) {
    wchar_t explosionSprite[EXPLOSION_HEIGHT][EXPLOSION_LENGHT] = {
        {L' ', L' ', L' '},
        {L' ', L' ', L' '}
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

/* Function to print a shield sprite on the screen */
void printShield(int x, int y) {
    wchar_t shieldSprite[SHIELD_HEIGHT][SHIELD_LENGHT] = {
        {L'n', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'n'},
        {L' ', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L' '},
        {L' ', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L' '},
        {L' ', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L' '},
        {L' ', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L'n', L' '},
        {L'n', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'n'}
    };

    short colors[SHIELD_HEIGHT][SHIELD_LENGHT] = {
        {0, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, 0},
        {SHIELD_BORDER, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SHIELD_BORDER},
        {SHIELD_BORDER, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SHIELD_BORDER},
        {SHIELD_BORDER, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SHIELD_BORDER},
        {SHIELD_BORDER, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SHIELD_BORDER},
        {0, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, SHIELD_BORDER, 0}
    };

    int startY = y + 1;
    int startX = x - 3;

    for (int row = 0; row < SHIELD_HEIGHT; row++) {
        for (int col = 0; col < SHIELD_LENGHT; col++) {
            if (shieldSprite[row][col] != L'n') {
                USE_COLOR(colors[row][col]);
                mvprintw(startY - row, startX + col, "%lc", shieldSprite[row][col]);
                attroff(COLOR_PAIR(colors[row][col]));
            }
        }
    }
}

/* Function to display the lose menu */
void loseMenu() {
    clear();

    const char *youLoseArt[] = {
        "YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     LLLLLLLLLLL                  OOOOOOOOO        SSSSSSSSSSSSSSS EEEEEEEEEEEEEEEEEEEEEE",
        "Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     L:::::::::L                OO:::::::::OO    SS:::::::::::::::SE::::::::::::::::::::E",
        "Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     L:::::::::L              OO:::::::::::::OO S:::::SSSSSS::::::SE::::::::::::::::::::E",
        "Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     LL:::::::LL             O:::::::OOO:::::::OS:::::S     SSSSSSSEE::::::EEEEEEEEE::::E",
        "YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U        L:::::L               O::::::O   O::::::OS:::::S              E:::::E       EEEEEE",
        "   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OS:::::S              E:::::E             ",
        "    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O S::::SSSS           E::::::EEEEEEEEEE   ",
        "     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O  SS::::::SSSSS      E:::::::::::::::E   ",
        "      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O    SSS::::::::SS    E:::::::::::::::E   ",
        "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O       SSSSSS::::S   E::::::EEEEEEEEEE   ",
        "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O            S:::::S  E:::::E             ",
        "       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U        L:::::L         LLLLLLO::::::O   O::::::O            S:::::S  E:::::E       EEEEEE",
        "       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U      LL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::OSSSSSSS     S:::::SEE::::::EEEEEEEE:::::E",
        "    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU       L::::::::::::::::::::::L OO:::::::::::::OO S::::::SSSSSS:::::SE::::::::::::::::::::E",
        "    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU         L::::::::::::::::::::::L   OO:::::::::OO   S:::::::::::::::SS E::::::::::::::::::::E",
        "    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU           LLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO      SSSSSSSSSSSSSSS   EEEEEEEEEEEEEEEEEEEEEE",
        NULL
    };

    int artLines = 0;
    while (youLoseArt[artLines] != NULL) {
        artLines++;
    }

    int maxLength = 0;
    for (int i = 0; i < artLines; i++) {
        int len = strlen(youLoseArt[i]);
        if (len > maxLength) {
            maxLength = len;
        }
    }

    int start_y = (GAME_LINES / 2) - (artLines / 2);
    int start_x = (COLS / 2) - (maxLength / 2);

    if (start_y < 0) start_y = 0;
    if (start_x < 0) start_x = 0;

    for (int i = 0; i < artLines; i++) {
        attron(COLOR_PAIR(RED_SIGN) | A_BOLD);
        mvprintw(start_y + i, start_x, "%s", youLoseArt[i]);
    }

    refresh();

    timeout(-1);
    getch();
}


void winMenu() {
    clear();

    const char *youWinArt[] = {
        "YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN",
        "Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N",
        "Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N",
        "Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N",
        "YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N",
        "   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N",
        "    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N",
        "     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N",
        "      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N",
        "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N",
        "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N",
        "       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N",
        "       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N",
        "    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N",
        "    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N",
        "    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN",
        NULL 
    };
    

    int artLines = 0;
    while (youWinArt[artLines] != NULL) {
        artLines++;
    }

    int maxLength = 0;
    for (int i = 0; i < artLines; i++) {
        int len = strlen(youWinArt[i]);
        if (len > maxLength) {
            maxLength = len;
        }
    }

    int start_y = (GAME_LINES / 2) - (artLines / 2);
    int start_x = (COLS / 2) - (maxLength / 2);

    if (start_y < 0) start_y = 0;
    if (start_x < 0) start_x = 0;

    for (int i = 0; i < artLines; i++) {
        attron(COLOR_PAIR(BLUE_SIGN) | A_BOLD);
        mvprintw(start_y + i, start_x, "%s", youWinArt[i]);
        attroff(COLOR_PAIR(BLUE_SIGN) | A_BOLD);
    }


    refresh();

    timeout(-1);
    getch();
}



  
void printInfoMenu() {
    clear();
    USE_COLOR(MENU);
    for (int i = 0; i < GAME_LINES; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }

    
    const char *infoArt[] = {
    "                                                                            ",
    "IIIIIIIIIINNNNNNNN        NNNNNNNNFFFFFFFFFFFFFFFFFFFFFF     OOOOOOOOO     ",
    "I::::::::IN:::::::N       N::::::NF::::::::::::::::::::F   OO:::::::::OO   ",
    "I::::::::IN::::::::N      N::::::NF::::::::::::::::::::F OO:::::::::::::OO ",
    "II::::::IIN:::::::::N     N::::::NFF::::::FFFFFFFFF::::FO:::::::OOO:::::::O",
    "  I::::I  N::::::::::N    N::::::N  F:::::F       FFFFFFO::::::O   O::::::O",
    "  I::::I  N:::::::::::N   N::::::N  F:::::F             O:::::O     O:::::O",
    "  I::::I  N:::::::N::::N  N::::::N  F::::::FFFFFFFFFF   O:::::O     O:::::O",
    "  I::::I  N::::::N N::::N N::::::N  F:::::::::::::::F   O:::::O     O:::::O",
    "  I::::I  N::::::N  N::::N:::::::N  F:::::::::::::::F   O:::::O     O:::::O",
    "  I::::I  N::::::N   N:::::::::::N  F::::::FFFFFFFFFF   O:::::O     O:::::O",
    "  I::::I  N::::::N    N::::::::::N  F:::::F             O:::::O     O:::::O",
    "  I::::I  N::::::N     N:::::::::N  F:::::F             O::::::O   O::::::O",
    "II::::::IIN::::::N      N::::::::NFF:::::::FF           O:::::::OOO:::::::O",
    "I::::::::IN::::::N       N:::::::NF::::::::FF            OO:::::::::::::OO ",
    "I::::::::IN::::::N        N::::::NF::::::::FF              OO:::::::::OO   ",
    "IIIIIIIIIINNNNNNNN         NNNNNNNFFFFFFFFFFF                OOOOOOOOO     ",
    "                                                                            "
    };

    int infoArtRow = (GAME_LINES - (sizeof(infoArt) / sizeof(infoArt[0]) + sizeof(infoArt) / sizeof(infoArt[0]) + sizeof(infoArt) / sizeof(infoArt[0]))) / 4;
    printCenteredArt(infoArt, sizeof(infoArt) / sizeof(infoArt[0]), infoArtRow, 3);


    

    const char *description[] = {
        "Frogger Resurrection",
        "By Simone Manunza & Simone Sulis (IADA)",
        "",
        "Frogger Resurrection is a modern reinterpretation of the legendary Frogger arcade game. This",
        "project combines nostalgia with innovation, offering players an exciting and challenging",
        "gameplay experience. Developed as a part of the SOPR course, it showcases our programming",
        "skills and creativity, designed to run entirely on a terminal-based environment using ncurses.",
        "",
        "Your goal is simple yet thrilling: guide the frog across a dangerous map to its dens, avoiding",
        "dynamic hazards like crocodile's projectiles, and treacherous rivers, all while racing against",
        "the clock.",
        "",
        "    - Three Game Modes:",
        "        Easy: Relaxed pace, giving players 3 minutes per level.",
        "        Medium: Balanced speed and challenge, with 2 minutes per level.",
        "        Hard: Fast-paced action with only 1 minute per level.",
        "",
        "    - Immersive Audio:",
        "        Each mode features its own unique soundtrack:",
        "            Easy: Calm and serene music.",
        "            Medium: A balanced and adventurous theme.",
        "            Hard: Intense, high-energy metal tracks.",
        "        Sound effects add life to every moment, with explosions, splashes, and more.",
        "",
        "    - Dynamic Gameplay:",
        "        - Use grenades to destroy obstacles and threats.",
        "        - Avoid fast-moving crocodiles and projectiles.",
        "        - Navigate rivers and reach dens safely.",
        "",
        "    Players are rewarded based on:",
        "        - The difficulty level selected (higher difficulty means more points).",
        "        - Time remaining upon reaching the dens.",
        "        - Lives left at the end of the level.",
        "        - Destroying projectiles and hazards using grenades.",
        "",
        "    The game features a carefully designed map that adapts dynamically to terminal size.",
        "    Every element, from the frog to the crocodiles, is represented with unique sprites",
        "    created entirely using matrix-based character art.",
        "",
        "    Inspired by the original Frogger, this game adds a modern twist with advanced mechanics,",
        "    diverse difficulty levels, and a fully immersive experience tailored for terminal gameplay.",
        "",
        "Get ready for the challenge. Can you guide your frog to safety and master the chaos?",
        "",
        "Good Luck!",
        NULL
    };

    int artLines = 0, maxLength = 0;
    while (description[artLines] != NULL) {
        int len = strlen(description[artLines]);
        if (len > maxLength) {
            maxLength = len;
        }
        artLines++;
    }

    int start_y = (GAME_LINES/2 +10) - (artLines / 2);
    int start_x = (COLS / 2) - (maxLength / 2);

    if (start_y < 0) start_y = 0;
    if (start_x < 0) start_x = 0;

    for (int i = 0; i < artLines; i++) {
        attron(COLOR_PAIR(INFO) | A_BOLD);
        mvprintw(start_y + i, start_x, "%s", description[i]);
        attroff(COLOR_PAIR(INFO) | A_BOLD);
    }

  
    refresh();
    timeout(-1);
    getch();


}


