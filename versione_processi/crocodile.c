#include "crocodile.h"
#include "struct.h"
#include "utils.h"
#include "menu.h"




/*
void createCrocodile(int *pipe, Crocodile *crocodiles, Game *game) {
    Crocodile newCroc;
    srand(time(NULL));

    int randDir = (rand() % 2 == 0) ? 1 : -1;

    
    for (int j = 0; j < GAME_LINES - 20; j++) { // Evita righe 0-4 e LINES-5 a LINES-1
        int rowspeed = rand () % 2 + game->crocSpeed; // Velocità casuale
        int rowSpawn = j + 12;
        // if index % (numCroc per riga) != 0 = nesimo coccodrillo sulla stessa riga index - 1 
        if ((rowSpawn + 4) % 4 == 0) {
            randDir = randDir * (-1);
            for (int i = 0; i < game->numCroc / (GAME_LINES - 20); i++) {
                // Inizializza i valori prima di fork()
              int validPosition = 0;

                while (!validPosition) {
                    // Genera una posizione casuale
                    newCroc.cords.x = rand() % (COLS - CROCODILE_LENGTH) + 1; // Evita spawn oltre COLS
                    newCroc.cords.y = rowSpawn + 4;
                    newCroc.cords.direction = randDir;
                    newCroc.cords.source = (j * MAX_CROCODILES) + i + 1;
                    newCroc.cords.speed = rowspeed;
                    newCroc.sprite.length = CROCODILE_LENGTH;
                    newCroc.sprite.height = CROCODILE_HEIGHT;

                    // Assume che la posizione sia valida finché non si dimostra il contrario
                    validPosition = 1;

                    // Controlla se la posizione è occupata
                    for (int k = 0; k < game->numCroc; k++) {
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
                    moveCrocodile(pipe, newCroc);
                    exit(0);
                } else {
                    newCroc.PID = pid;
                    crocodiles[(j * MAX_CROCODILES) + i] = newCroc;
                }
            }
        }
    }
}
*/


void createCrocodile(int *pipe, Crocodile *crocodiles, Game *game) {
    Crocodile newCroc;
    srand(time(NULL));

    int randDir = (rand() % 2 == 0) ? 1 : -1;
    int validPosition;

    int rowspeed = rand () % 2 + game->crocSpeed; 
    int rowSpawn = 12;
    for(int i= 0; i < game->numCroc; i++) {

        validPosition = 0;
        if(i % 2 == 0) {
            randDir = randDir * (-1);
            rowSpawn += 4;
        }

        while (!validPosition) {
            // Genera una posizione casuale
            newCroc.cords.x = rand() % (COLS - CROCODILE_LENGTH) + 1; // Evita spawn oltre COLS
            newCroc.cords.y = rowSpawn;
            newCroc.cords.direction = randDir;
            newCroc.cords.source = i + 1;
            newCroc.cords.speed = rowspeed;
            newCroc.sprite.length = CROCODILE_LENGTH;
            newCroc.sprite.height = CROCODILE_HEIGHT;
            newCroc.cords.type = 'c';
            validPosition = 1;
            for (int k = 0; k < game->numCroc; k++) {
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
            crocodiles[i] = newCroc;
        }
    }

}




void moveCrocodile(int *pipe, Crocodile crocodile, Game *game) {

    int projectChance = 0;
    // open(pipe[1]);
    close(pipe[0]);
    Coordinates msg;
    while (1) {
        // readData(pipeToCroc, &msg, sizeof(Coordinates));
        // if (msg.source == crocodile.cords.source) {
        //     crocodile.cords = msg;
        // }
        
        crocodile.cords.x += (crocodile.cords.direction * crocodile.cords.speed);

        //vari controlli per vedere se esce dallo schermo

        //da cambiare con le MACRO
        if (crocodile.cords.x >= COLS + 1 + CROCODILE_LENGTH) { 
            //aspetto un quanto di tempo random

            usleep((rand() % 200000) + 100000); 
            crocodile.cords.x = 0 - CROCODILE_LENGTH;
            
        } else if (crocodile.cords.x < -2 - CROCODILE_LENGTH) {
            
            //funzionerà con lo sleep?ridondante

            usleep((rand() % 200000) + 100000);
            crocodile.cords.x = COLS - 1 + CROCODILE_LENGTH;
        }

        projectChance = rand() % 300;
        
        // TODO trovare una soluzione per settare crocodile.cords.flag

        if(projectChance == 1 && crocodile.cords.flag == 0) {
            crocodile.cords.flag = 1;
        }
         

        writeData(pipe[1], &crocodile.cords, sizeof(Coordinates));
        
        crocodile.cords.flag = 0;
        usleep(200000);
    }   

}



void resetCrocodile(Crocodile *crocodile, Game *game) {

    srand(time(NULL));
    int reverse = rand() % 2;
    int direction = (reverse == 1) ? 1 : -1;
    int validPosition = 0;

    for (int i = 0; i < game->numCroc; i++) {
        if (crocodile[i].PID && crocodile[i].cords.type == 'c') {
            kill(crocodile[i].PID, SIGKILL);
            waitpid(crocodile[i].PID, NULL, 0);

        }
    }
    
}



void createProjectile(int *pipe, Crocodile crocodile, Game *game) {
   
    Projectile project;
    project.cords.x = crocodile.cords.x + (crocodile.cords.direction * CROCODILE_LENGTH);
    project.cords.y = crocodile.cords.y - CROCODILE_HEIGHT /2;
    project.cords.direction = crocodile.cords.direction;
    project.cords.source = crocodile.cords.source;
    project.speed = crocodile.cords.speed + 2;
    project.sprite.length = PROJECTILE_LENGTH;
    project.sprite.height = PROJECTILE_HEIGHT;
    project.cords.type = 'p';

    project.cords.source = 300 + crocodile.cords.source;


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

        projectile->cords.x += projectile->speed * projectile->cords.direction;

        if (projectile->cords.x > COLS + 8 || projectile->cords.x < -8) {

            projectile->cords.x = -10;
            projectile->cords.y = -10;
            projectile->cords.flag = 0;
            exit(0);
        }

        writeData(pipe, &projectile->cords, sizeof(Coordinates));
        usleep(200000);
    }
}

void resetProjectile(Projectile *projectile) {

    for(int i=0; i < (NUM_PROJECTILES +1); i++) {
        if (projectile[i].PID && projectile[i].cords.type == 'p') {
            projectile[i].cords.x = -10;
            projectile[i].cords.y = -10;
            projectile[i].cords.flag = 0;
            kill(projectile[i].PID, SIGKILL);
            waitpid(projectile[i].PID, NULL, 0);
        }
    }
  
}