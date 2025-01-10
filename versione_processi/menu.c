#include "menu.h"




short menu(Game *game)
{   
   

    int c = 0;

    while(1) {

        printMenu();

        switch (c)
        {
        case 0:
        //Da sostituire con la funzione printCursor
            //mvwprintw(stdscr, 0, 0, ">");
            break;
        case 1:
            //mvwprintw(stdscr, 1, 0, ">");
            break;
        case 2:
            //mvwprintw(stdscr, 2, 0, ">");
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
    //game->crocodileNumber = EASY_MODE_CROC_NUM;
    //game->crocodileSpeed = EASY_MODE_CROC_SPEED;
    run(game);
}

void mediumDifficult(Game *game) {
    //game->crocodileNumber = MEDIUM_MODE_CROC_NUM;
    //game->crocodileSpeed = MEDIUM_MODE_CROC_SPEED;
    run(game);
}

void hardDifficult(Game *game) {
    //game->crocodileNumber = HARD_MODE_CROC_NUM;
    //game->crocodileSpeed = HARD_MODE_CROC_SPEED;
    run(game);
}


//è una merda giusto per mettere un punteggio
int scoreCounter(Player *player, int points) {
    player->score += points;
    player->score += (LINES - player->cords.y)/4 * 10;
    //mvprintw(0, COLS - 15, "Score: %d", player->score);
}