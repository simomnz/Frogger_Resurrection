#include "crocodile.h"


/*
 ▗▄▄▖▗▄▄▖  ▗▄▖  ▗▄▄▖ ▗▄▖ ▗▄▄▄ ▗▄▄▄▖▗▖   ▗▄▄▄▖ ▗▄▄▖
▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌  █  █  ▐▌   ▐▌   ▐▌   
▐▌   ▐▛▀▚▖▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌  █  █  ▐▌   ▐▛▀▀▘ ▝▀▚▖
▝▚▄▄▖▐▌ ▐▌▝▚▄▞▘▝▚▄▄▖▝▚▄▞▘▐▙▄▄▀▗▄█▄▖▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘
                                                  
*/



void createCrocodile(Crocodile *crocodiles, Game *game) {

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
            crocodiles[i].cords.x = rand() % (COLS - CROCODILE_LENGTH) + 1; // Evita spawn oltre COLS
            crocodiles[i].cords.y = rowSpawn;
            crocodiles[i].cords.direction = randDir;
            crocodiles[i].cords.source = i + 1;
            crocodiles[i].cords.speed = rowspeed;
            crocodiles[i].sprite.length = CROCODILE_LENGTH;
            crocodiles[i].sprite.height = CROCODILE_HEIGHT;
            crocodiles[i].cords.type = 'c';
            validPosition = 1;
            for (int k = 0; k < game->numCroc; k++) {
                if (crocodiles[k].cords.y == crocodiles[k].cords.y && 
                    abs(crocodiles[k].cords.x - crocodiles[k].cords.x) < (CROCODILE_LENGTH) + CROCODILE_SHIFT) {
                    validPosition = 0;
                    break;
                }
            }
        }
        // crocodiles[i] = newCroc;
        pthread_create(&crocodiles[i].thread, NULL, (void *) moveCrocodile, (Crocodile *) &crocodiles[i]);
    }

}




void *moveCrocodile(Crocodile *crocodile) {

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

    // for (int i = 0; i < game->numCroc; i++) {
    //     if (crocodile[i].thread && crocodile[i].cords.type == 'c') {

    //         //CATTIVA FUNZIONE
    //         // kill(crocodile[i].thread, SIGKILL);
    //         // waitpid(crocodile[i].thread, NULL, 0);

    //     }
    // }
    
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
    project.cords.x = crocodile.cords.x + (crocodile.cords.direction * CROCODILE_LENGTH);
    project.cords.y = crocodile.cords.y - CROCODILE_HEIGHT /2;
    project.cords.direction = crocodile.cords.direction;
    project.cords.source = crocodile.cords.source;
    project.speed = crocodile.cords.speed + 2;
    project.sprite.length = PROJECTILE_LENGTH;
    project.sprite.height = PROJECTILE_HEIGHT;
    project.cords.type = 'p';
    project.cords.source = 300 + crocodile.cords.source; /* The source is related by the Crocodile That have shoot the Projectile */
 
    pthread_create(&project.thread, NULL, (void *) moveProjectile, (Projectile *)&project);

}


void *moveProjectile(Projectile *projectile) {
    while (1) {
        /* Movement of the Projectile */
        projectile->cords.x += projectile->speed * projectile->cords.direction;

        if (projectile->cords.x > COLS + 8 || projectile->cords.x < -8) {

            projectile->cords.x = -10;
            projectile->cords.y = -10;
            projectile->cords.flag = 0;
            exit(0);
        }
        /* Control Communication with Pipe */
        writeData(projectile->cords);
        usleep(200000);
    }
    pthread_exit(0);
}


/* Function that kills all the Projectiles Proccesses */
void resetProjectile(Projectile *projectile) {
    
    // for(int i=0; i < (NUM_PROJECTILES); i++) {
    //     if (projectile[i].PID && projectile[i]cordstype == 'p') {
    //         projectile[i].cords.x = -10;
    //         projectile[i].cords.y = -10;
    //         projectile[i].cords.flag = 0;

    //     }
    // }
  
}