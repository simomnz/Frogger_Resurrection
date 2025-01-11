#include "crocodile.h"
#include "struct.h"
#include "utils.h"
#include "menu.h"



/*
void createCrocodile(int *pipe, Crocodile *crocodiles) {
    Crocodile newCroc;
    srand(time(NULL));

    int randDir = (rand() % 2 == 0) ? 1 : -1;
    for (int j = 0; j < LINES - 4; j++) {
        int rowspeed = 1; // Velocità fissa per ora
        if((j + 2) % 4 == 0) {


            randDir = randDir *(-1);
            for (int i = 0; i < MAX_CROCODILES; i++) {

                // Inizializza i valori prima di fork()
                newCroc.cords.x = rand() % (COLS - 1) + 1;
                
                
                    
                    newCroc.cords.y = j + 2;
                    newCroc.cords.direction =  randDir;
                    newCroc.cords.source = (j * MAX_CROCODILES) + i + 1;
                    newCroc.cords.speed = rowspeed;
                    newCroc.sprite.length = CROCODILE_LENGTH; // Lunghezza fissa
                    newCroc.sprite.height = CROCODILE_HEIGHT;

                    pid_t pid = fork();
                    
                    if (pid < 0) {
                        perror("Fork failed");
                        exit(1);
                    } else if (pid == 0) { 
                        srand(time(NULL) + getpid()); 
                        moveCrocodile(pipe, &newCroc);
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

    
    for (int j = 0; j < LINES - 20; j++) { // Evita righe 0-4 e LINES-5 a LINES-1
        int rowspeed = rand () % 2 + game->crocSpeed; // Velocità casuale
        int rowSpawn = j + 12;
        
        if ((rowSpawn + 4) % 4 == 0) {
            randDir = randDir * (-1);
            for (int i = 0; i < MAX_CROCODILES; i++) {
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
                    for (int k = 0; k < MAX_CROCODILES * (LINES - 12); k++) {
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
                    moveCrocodile(pipe, &newCroc);
                    exit(0);
                } else {
                    newCroc.PID = pid;
                    crocodiles[(j * MAX_CROCODILES) + i] = newCroc;
                }
            }
        }
    }
}




void moveCrocodile(int *pipe, Crocodile *crocodile) {

    int projectChance= 0;

    while (1) {

        crocodile->cords.x += (crocodile->cords.direction * crocodile->cords.speed);

        //vari controlli per vedere se esce dallo schermo

        //da cambiare con le MACRO
        if (crocodile->cords.x >= COLS + 1 + CROCODILE_LENGTH) { 
            //aspetto un quanto di tempo random

            usleep((rand() % 200000) + 100000); 
            crocodile->cords.x = 0 - CROCODILE_LENGTH;
            
        } else if (crocodile->cords.x < -2 - CROCODILE_LENGTH) {
            
            //funzionerà con lo sleep?ridondante

            usleep((rand() % 200000) + 100000);
            crocodile->cords.x = COLS - 1 + CROCODILE_LENGTH;
        }

        projectChance = rand() % 20;
        
        if(projectChance == 1) {


            //createProjectile(pipe, crocodile);

        }
         


        writeData(pipe[1], &crocodile->cords, sizeof(Coordinates));


        
        usleep(200000);
    }   



}

/*
void resetCrocodile(Crocodile *crocodile, int *pipeFd) {

    srand(time(NULL));
    int reverse = rand() % 2;
    int direction = (reverse == 1) ? 1 : -1;
    int validPosition = 0;

    for (int i = 0; i < MAX_CROCODILES * ((LINES - 20) /4); i++)
    {
        crocodile[i].cords.direction = crocodile[i].cords.direction * direction;
        
        while (!validPosition) {
            // Genera una X casuale (evitando spawn oltre lo schermo)
            int newX = rand() % (COLS - CROCODILE_LENGTH - 1);
            if (newX < 0) {
                newX = 0;
            }

            // Imposta di default che la posizione è valida
            validPosition = 1;

            // (Opzionale) controlla se si sovrappone ad altri coccodrilli nella stessa riga
            for (int j = 0; j < MAX_CROCODILES * ((LINES - 20)/4) ; j++) {
                if (j == i) {
                    // Non confrontare il coccodrillo con se stesso
                    continue;
                }
                // Verifica che sia un coccodrillo attivo
                if (crocodile[j].PID != 0) {
                    // Stessa riga?
                    if (crocodile[j].cords.y == crocodile[i].cords.y) {
                        // Se la distanza in X è troppo piccola, c'è sovrapposizione
                        int distX = abs(crocodile[j].cords.x - newX);
                        if (distX < (CROCODILE_LENGTH + CROCODILE_SHIFT)) {
                            validPosition = 0;
                            break;
                        }
                    }
                }
            }

            
            if (validPosition) {
                crocodile[i].cords.x = newX;
            }
        }
        moveCrocodile(pipeFd, &crocodile[i]);
    }
    
}

*/

void createProjectiles(int *pipe, Crocodile *crocodile) {
   
    Projectile project;
    project.cords.x = crocodile->cords.x + crocodile->cords.direction;
    project.cords.y = crocodile->cords.y;
    project.cords.direction = crocodile->cords.direction;
    project.cords.source = crocodile->cords.source;
    project.speed = crocodile->cords.speed + 2;
    project.sprite.length = 1;

    project.cords.source = 500 + rand () % 1000; //a caso per ora


    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        moveProjectile(pipe[1], &project);
        exit(0);
    }

}


void moveProjectile(int pipe, Projectile *projectile) {
    while (1) {

        projectile->cords.x += projectile->speed * projectile->cords.direction;

        if (projectile->cords.x >= COLS + 1 || projectile->cords.x < -2) {

            //li butto in basso a sinistra (non obbligatorio)
            projectile->cords.x = -4;
            projectile->cords.y = -4;
            exit(0);
        }

        writeData(pipe, &projectile->cords, sizeof(Coordinates));
        usleep(200000);
    }
}