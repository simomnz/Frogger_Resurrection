#include "crocodile.h"


/*
 ▗▄▄▖▗▄▄▖  ▗▄▖  ▗▄▄▖ ▗▄▖ ▗▄▄▄ ▗▄▄▄▖▗▖   ▗▄▄▄▖ ▗▄▄▖
▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌  █  █  ▐▌   ▐▌   ▐▌   
▐▌   ▐▛▀▚▖▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌  █  █  ▐▌   ▐▛▀▀▘ ▝▀▚▖
▝▚▄▄▖▐▌ ▐▌▝▚▄▞▘▝▚▄▄▖▝▚▄▞▘▐▙▄▄▀▗▄█▄▖▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘
                                                  
*/



void createCrocodile(int *pipe, Crocodile *crocodiles, Game *game) {
    Crocodile newCroc;  
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
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            srand(time(NULL) + getpid());
            moveCrocodile(pipe, newCroc, game);
            exit(0);
        } else {
            newCroc.PID = pid;
            crocodiles[i] = newCroc;  /* Adding the Crocodile to the Crocodile  Game Array */
        }
    }

}




void moveCrocodile(int *pipe, Crocodile crocodile, Game *game) {

    int projectChance = 0;
    close(pipe[0]);  /* Closing Reading Pipe */
    Coordinates msg;
    int pew = COLS; /* Check to make the Crocodile Shoot*/
    while (1) {
        
        /* Crocodile Moving */
        crocodile.cords.x += (crocodile.cords.direction * crocodile.cords.speed);

        /* If the Crocodile Goes Off Screen */
        if (crocodile.cords.x >= COLS + 1 + CROCODILE_LENGTH) { 

            usleep((rand() % 200000) + 100000); 
            crocodile.cords.x = 0 - CROCODILE_LENGTH;
            
        } else if (crocodile.cords.x < -2 - CROCODILE_LENGTH) {
            
            usleep((rand() % 200000) + 100000);
            crocodile.cords.x = COLS - 1 + CROCODILE_LENGTH;
        }   

        /* Chance to shoot a Projectile */
        projectChance = rand() % 300;
        
        pew++;

        /* The Crocodile has to respawn to shoot again */
        if(projectChance == 1 && crocodile.cords.flag == 0 && pew > COLS) {
            crocodile.cords.flag = 1; /* Setting Flag on to see if it have shot*/
            pew = 0;
        }
        
        /* Control Communication with Pipe (Writing) */
        writeData(pipe[1], &crocodile.cords, sizeof(Coordinates));

        /* Setting the Flag off*/
        crocodile.cords.flag = 0;

        /* Delay between every Movement*/
        usleep(200000);
    }   

}


/* Function to kill all the Crocodiles Proccesses */

void resetCrocodile(Crocodile *crocodile, Game *game) {

    for (int i = 0; i < game->numCroc; i++) {
        if (crocodile[i].PID && crocodile[i].cords.type == 'c') {
            kill(crocodile[i].PID, SIGKILL);
            waitpid(crocodile[i].PID, NULL, 0);

        }
    }
    
}


/*
▗▄▄▖ ▗▄▄▖  ▗▄▖    ▗▖▗▄▄▄▖ ▗▄▄▖▗▄▄▄▖▗▄▄▄▖▗▖   ▗▄▄▄▖ ▗▄▄▖
▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌   ▐▌▐▌   ▐▌     █    █  ▐▌   ▐▌   ▐▌   
▐▛▀▘ ▐▛▀▚▖▐▌ ▐▌   ▐▌▐▛▀▀▘▐▌     █    █  ▐▌   ▐▛▀▀▘ ▝▀▚▖
▐▌   ▐▌ ▐▌▝▚▄▞▘▗▄▄▞▘▐▙▄▄▖▝▚▄▄▖  █  ▗▄█▄▖▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘

*/


void createProjectile(int *pipe, Crocodile crocodile, Game *game) {
   
    /* Setting all the Projectiles Attribute's Values */
    Projectile project;
    project.cords.x = crocodile.cords.x + (crocodile.cords.direction * CROCODILE_LENGTH);
    project.cords.y = crocodile.cords.y - CROCODILE_HEIGHT /2;
    project.cords.direction = crocodile.cords.direction;
    project.speed = crocodile.cords.speed + 2;
    project.sprite.length = PROJECTILE_LENGTH;
    project.sprite.height = PROJECTILE_HEIGHT;
    project.cords.type = 'p';
    project.cords.source = 300 + crocodile.cords.source; /* The source is related by the Crocodile That have shoot the Projectile */
 

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        moveProjectile(pipe[1], &project);
        exit(0);
    }else {
        project.PID = pid;
        game->projectiles[crocodile.cords.source - 1] = project;
    }

}


void moveProjectile(int pipe, Projectile *projectile) {
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
        writeData(pipe, &projectile->cords, sizeof(Coordinates));
        usleep(200000);
    }
}


/* Function that kills all the Projectiles Proccesses */
void resetProjectile(Projectile *projectile) {
    
    for(int i=0; i < (NUM_PROJECTILES); i++) {
        if (projectile[i].PID && projectile[i].cords.type == 'p') {
            projectile[i].cords.x = -10;
            projectile[i].cords.y = -10;
            projectile[i].cords.flag = 0;
            kill(projectile[i].PID, SIGKILL);
            waitpid(projectile[i].PID, NULL, 0);
        }
    }
  
}