#include "menu.h"




short menu(Game *game)
{   
   

    int c = 0;

    while(1) {

        printMenu();

        switch (c)
        {
        case 0:
            printFrog(10, LINES/5);
            break;
        case 1:
            printFrog(10, LINES/2);
            break;
        case 2:
            printFrog(10, LINES - 12);
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
                clear();
                printDifficultyMenu(game);
                break;
            case 1:
                //score
                break;
            case 2:
                stop(game);
                break;
            }
        }
        refresh();


    }

}


void easyDifficult(Game *game) {

    game->crocSpeed = EASY_MODE_CROC_SPEED;
    run(game);
}

void mediumDifficult(Game *game) {
    game->crocSpeed = MEDIUM_MODE_CROC_SPEED;
    run(game);
}

void hardDifficult(Game *game) {
    game->crocSpeed = HARD_MODE_CROC_SPEED;
    run(game);
}


//è una merda giusto per mettere un punteggio
int scoreCounter(Player *player, int points) {
    player->score += points;
    player->score += (LINES - player->cords.y)/4 * 10;
    //mvprintw(0, COLS - 15, "Score: %d", player->score);
}



void wrongTerminalSize(Game *game) {

    if ((LINES - 1) % 4 != 0) {
        clear();
        mvprintw(0, 0, "Error: The terminal must have a number of rows such that (LINES - 1) %% 4 == 0.");
        mvprintw(1, 0, "Currently, the terminal has %d rows and %d columns.", LINES, COLS);
        mvprintw(2, 0, "Please resize the terminal and restart the program.");
        mvprintw(3, 0, "You can see your terminal size with stty size.");
        mvprintw(4, 0, "Press any key to exit...");
        refresh();
        timeout(-1);
        getch();

        stop(game);
        

    }
}