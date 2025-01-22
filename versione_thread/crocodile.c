#include "crocodile.h"

/*
 ▗▄▄▖▗▄▄▖  ▗▄▖  ▗▄▄▖ ▗▄▖ ▗▄▄▄ ▗▄▄▄▖▗▖   ▗▄▄▄▖ ▗▄▄▖
▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌  █  █  ▐▌   ▐▌   ▐▌   
▐▌   ▐▛▀▚▖▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌  █  █  ▐▌   ▐▛▀▀▘ ▝▀▚▖
▝▚▄▄▖▐▌ ▐▌▝▚▄▞▘▝▚▄▄▖▝▚▄▞▘▐▙▄▄▀▗▄█▄▖▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘
                                                  
*/

void createCrocodile(Crocodile *crocodiles, Game *game) {
    Crocodile newCroc;
    Crocodile *threadCrocs = malloc(game->numCroc * sizeof(Crocodile));
    srand(time(NULL)); 

    /* Line direction and speed and other Variables */
    int randDir = (rand() % 2 == 0) ? 1 : -1;
    int validPosition;

    int rowspeed = rand () % 2 + game->crocSpeed; 
    int rowSpawn = 12; /* The river starts from the 16th LINE */
    for(int i= 0; i < game->numCroc; i++) {


        validPosition = 0;  

        if(i % 2 == 0) {  /* Every time the River Line Change, the direction is inverted, the RowSpawn increased by 4 (Crocodile Height) and the rowSpeed randomized */
            randDir = randDir * (-1);
            rowSpawn += 4;
            rowspeed = rand () % 2 + game->crocSpeed; 
        }
        /* Check to make sure the Crocodiles do not spawn in the same position (glitched) */
        while (!validPosition) {
            /* Set all the Crocodile Attribute's Values*/
            newCroc.cords.x = rand() % (COLS - CROCODILE_LENGTH) + 1; // Evita spawn oltre COLS
            newCroc.cords.y = rowSpawn;
            newCroc.cords.direction = randDir;
            newCroc.cords.source = i + 1;
            newCroc.cords.speed = rowspeed;
            newCroc.sprite.length = CROCODILE_LENGTH;
            newCroc.sprite.height = CROCODILE_HEIGHT;
            newCroc.cords.type = 'c';
            validPosition = 1;
            for (int k = 0; k < i; k++) {
                if (crocodiles[k].cords.y == newCroc.cords.y && 
                    abs(crocodiles[k].cords.x - newCroc.cords.x) < (CROCODILE_LENGTH) + CROCODILE_SHIFT) {
                    validPosition = 0;
                    break;
                }
            }
        }
        threadCrocs[i] = newCroc;
        crocodiles[i] = newCroc; 
        pthread_create(&threadCrocs[i].thread, NULL, moveCrocodile, (void *)&threadCrocs[i]);    
        crocodiles[i].thread = threadCrocs[i].thread; 
    }
}

void *moveCrocodile(void *arg) {
    Crocodile *crocodile = (Crocodile *)arg;
    int projectChance = 0;
    Coordinates msg;
    int pew = COLS; /* Check to make the Crocodile Shoot*/
    while (1) {
        
        /* Crocodile Moving */
        crocodile->cords.x += (crocodile->cords.direction * crocodile->cords.speed);

        /* If the Crocodile Goes Off Screen */
        if (crocodile->cords.x >= COLS + 1 + CROCODILE_LENGTH) { 

            usleep((rand() % 200000) + 100000); 
            crocodile->cords.x = 0 - CROCODILE_LENGTH;
            
        } else if (crocodile->cords.x < -2 - CROCODILE_LENGTH) {
            
            usleep((rand() % 200000) + 100000);
            crocodile->cords.x = COLS - 1 + CROCODILE_LENGTH;
        }   

        /* Chance to shoot a Projectile */
        projectChance = rand() % 300;
        pew++;

        /* The Crocodile has to respawn to shoot again */
        if(projectChance == 1 && crocodile->cords.flag == 0 && pew > COLS) {
            crocodile->cords.flag = 1; /* Setting Flag on to see if it have shot*/
            pew = 0;
        }
        
        /* Control Communication with Pipe (Writing) */
        writeData(crocodile->cords);

        /* Setting the Flag off*/
        crocodile->cords.flag = 0;

        /* Delay between every Movement*/
        usleep(200000);
    }  
    pthread_exit(NULL);
}

/* Function to kill all the Crocodiles Proccesses */
void resetCrocodile(Crocodile *crocodile, Game *game) {
    int res;
    for (int i = 0; i < game->numCroc; i++) {
        if (crocodile[i].thread && crocodile[i].cords.type == 'c') {
            res = pthread_cancel(crocodile[i].thread);
            if (res != 0) {
                perror("unlucky thread cancellation");
            }
        }
    }
}

/*
▗▄▄▖ ▗▄▄▖  ▗▄▖    ▗▖▗▄▄▄▖ ▗▄▄▖▗▄▄▄▖▗▄▄▄▖▗▖   ▗▄▄▄▖ ▗▄▄▖
▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌   ▐▌▐▌   ▐▌     █    █  ▐▌   ▐▌   ▐▌   
▐▛▀▘ ▐▛▀▚▖▐▌ ▐▌   ▐▌▐▛▀▀▘▐▌     █    █  ▐▌   ▐▛▀▀▘ ▝▀▚▖
▐▌   ▐▌ ▐▌▝▚▄▞▘▗▄▄▞▘▐▙▄▄▖▝▚▄▄▖  █  ▗▄█▄▖▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘
*/

void createProjectile(Crocodile crocodile, Game *game) {
    /* Setting all the Projectiles Attribute's Values */
    Projectile project;
    game->projectiles[crocodile.cords.source - 1 ].cords.x = crocodile.cords.x + (crocodile.cords.direction * CROCODILE_LENGTH);
    game->projectiles[crocodile.cords.source - 1 ].cords.y = crocodile.cords.y - CROCODILE_HEIGHT /2;
    game->projectiles[crocodile.cords.source - 1 ].cords.direction = crocodile.cords.direction;
    game->projectiles[crocodile.cords.source - 1 ].speed = crocodile.cords.speed + 2;
    game->projectiles[crocodile.cords.source - 1 ].sprite.length = PROJECTILE_LENGTH;
    game->projectiles[crocodile.cords.source - 1 ].sprite.height = PROJECTILE_HEIGHT;
    game->projectiles[crocodile.cords.source - 1 ].cords.type = 'p';
    game->projectiles[crocodile.cords.source - 1 ].cords.source = 300 + crocodile.cords.source;
    game->projectiles[crocodile.cords.source - 1 ].cords.flag = 1;
    pthread_create(&game->projectiles[crocodile.cords.source - 1 ].thread, NULL, moveProjectile, (void *)&game->projectiles[crocodile.cords.source - 1 ]);
}

void *moveProjectile(void *arg) {
    Projectile *projectile = (Projectile *)arg;
    while (1) {
        /* Movement of the Projectile */
        projectile->cords.x += projectile->speed * projectile->cords.direction;

        if (projectile->cords.x > (COLS +4)  || projectile->cords.x < -4) {
            projectile->cords.x = -10;
            projectile->cords.y = -10;
            projectile->cords.flag = 0;
            writeData(projectile->cords);
            break;
        }
        /* Control Communication with Pipe */
        writeData(projectile->cords);
        usleep(200000);
    }
    
    pthread_exit(0);
}

/* Function that kills all the Projectiles Proccesses */
void resetProjectile(Projectile *projectile) {

    int res;
    for(int i=0; i < (NUM_PROJECTILES); i++) {
        if (projectile[i].thread && projectile[i].cords.type == 'p') {
            projectile[i].cords.x = -10;
            projectile[i].cords.y = -10;
            projectile[i].cords.flag = 0;
            res = pthread_cancel(projectile[i].thread);
            if (res != 0) {
                perror("unlucky thread cancellation");
            }
            
        }
    }
}
