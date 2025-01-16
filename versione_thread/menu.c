#include "menu.h"


/*
▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▖ ▗▖
▐▛▚▞▜▌▐▌   ▐▛▚▖▐▌▐▌ ▐▌
▐▌  ▐▌▐▛▀▀▘▐▌ ▝▜▌▐▌ ▐▌
▐▌  ▐▌▐▙▄▄▖▐▌  ▐▌▝▚▄▞▘
                     
*/

short menu(Game *game) {   
   
    /* Cursor Position */
    int c = 0;

    while(1) {

        printMenu();
        
        /* Start, Score and Exit Position */
        switch (c)
        {
        case 0:
            printFrog(10, GAME_LINES/5);
            break;
        case 1:
            printFrog(10, GAME_LINES/2);
            break;
        case 2:
            printFrog(10, GAME_LINES - 12);
            break;
        }

        /* Moving the Cursor Up and Down*/
        int ch = getch();

        if(ch == KEY_DOWN && c < 2) {
            c++;
        }else if (ch == KEY_UP && c > 0) {
            c--;
        }

        /* If the Player Press Enter */
        if (ch == '\n') {
            
            switch (c)
            {
            case 0:  /* Start Button */
                clear();
                printDifficultyMenu(game);
                return 1;
                break;
            case 1:  /* Score Button */
                printInfoMenu();
                break;
                // return 1;
                break;
            case 2:  /* Exit Button */
                return 0;
                break;
            }
        }
        refresh();
    }

}

/*
▗▄▄▄▖ ▗▄▖  ▗▄▄▖▗▖  ▗▖
▐▌   ▐▌ ▐▌▐▌    ▝▚▞▘ 
▐▛▀▀▘▐▛▀▜▌ ▝▀▚▖  ▐▌  
▐▙▄▄▖▐▌ ▐▌▗▄▄▞▘  ▐▌ 
*/
void easyDifficult(Game *game) {

    /* Set all the Game Difficulty Parameters*/
    game->crocSpeed = EASY_MODE_CROC_SPEED;
    game->timeDifficulty = 180;
    game->player.score = 0;
    game->numCroc = 26;
    game->crocodiles = malloc(sizeof(Crocodile) * game->numCroc);
    game->projectiles = malloc(sizeof(Projectile) * NUM_PROJECTILES);
    for(int i=0; i< (NUM_PROJECTILES); i++) {
        game->projectiles[i].cords.x = -10;
        game->projectiles[i].cords.y = -10;
        game->projectiles[i].cords.flag = 0;
    }
    game->difficulty = 1;
    
}
/*
▗▖  ▗▖▗▄▄▄▖▗▄▄▄ ▗▄▄▄▖▗▖ ▗▖▗▖  ▗▖
▐▛▚▞▜▌▐▌   ▐▌  █  █  ▐▌ ▐▌▐▛▚▞▜▌
▐▌  ▐▌▐▛▀▀▘▐▌  █  █  ▐▌ ▐▌▐▌  ▐▌
▐▌  ▐▌▐▙▄▄▖▐▙▄▄▀▗▄█▄▖▝▚▄▞▘▐▌  ▐▌
*/

void mediumDifficult(Game *game) {
    
    /* Set all the Game Difficulty Parameters*/
    game->crocSpeed = MEDIUM_MODE_CROC_SPEED;
    game->timeDifficulty = 120;
    game->numCroc = 26;
    game->player.score = 250;
    game->crocodiles = malloc(sizeof(Crocodile) * game->numCroc);
    game->projectiles = malloc(sizeof(Projectile) * NUM_PROJECTILES);
    for(int i=0; i< (NUM_PROJECTILES); i++) {
        game->projectiles[i].cords.x = -10;
        game->projectiles[i].cords.y = -10;
        game->projectiles[i].cords.flag = 0;
    }
    game->difficulty = 2;


    // run(game);
}

/*
▗▖ ▗▖ ▗▄▖ ▗▄▄▖ ▗▄▄▄ 
▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌  █
▐▛▀▜▌▐▛▀▜▌▐▛▀▚▖▐▌  █
▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▙▄▄▀                
*/
void hardDifficult(Game *game) {
    
    /* Set all the Game Difficulty Parameters*/
    game->crocSpeed = HARD_MODE_CROC_SPEED;
    game->timeDifficulty = 60;
    game->numCroc = 26;
    game->player.score = 500;
    game->crocodiles = malloc(sizeof(Crocodile) * game->numCroc);
    game->projectiles = malloc(sizeof(Projectile) * NUM_PROJECTILES);
    for(int i=0; i< NUM_PROJECTILES; i++) {
        game->projectiles[i].cords.x = -10;
        game->projectiles[i].cords.y = -10;
        game->projectiles[i].cords.flag = 0;
    }
    game->difficulty = 3;
}


/* Add Score to The Player*/
int scoreCounter(Player *player, int points) {
    player->score += points;
}


/* Set the Game Size to 69 Lines, COLS*/
void wrongTerminalSize(Game *game) {

    if ((GAME_LINES - 1) % 4 != 0) {
    
        int valid_GAME_LINES = 69; 
        int valid_clm = 255;
        resizeterm(valid_GAME_LINES, COLS);
        clear();
        refresh();

    }
}