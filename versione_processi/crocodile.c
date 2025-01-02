#include "crocodile.h"
#include "struct.h"
#include "utils.h"
#include "menu.h"









/*
void createCrocodile(int *pipe, Crocodile *crocodiles) {
    

    Crocodile newCroc;
    for (int j = 0; j < LINES -4; j++) {

        //int rowspeed = (rand() % 3) + 1;
        int rowspeed = 1;

        for (int i = 0; i < MAX_CROCODILES; i++) {
            pid_t pid = fork();

            if (pid < 0) {
                perror("Fork failed");
                exit(1);
            } else if (pid == 0) {

                srand(time(NULL) + getpid());
                newCroc.cords.x = rand() % (COLS -1) + 1;
                newCroc.cords.y = j +2;

                newCroc.cords.direction = (j % 2 == 0) ? 1 : -1;
                newCroc.cords.source = (j * MAX_CROCODILES) + i + 1;
                newCroc.speed = rowspeed;
                newCroc.sprite.length = 3; //CROCODILE_LENGTH * newCroc.cords.direction;
                newCroc.sprite.height = CROCODILE_HEIGHT;
                
                
                moveCrocodile(pipe, &newCroc);
                exit(0);
            } else {
                newCroc.PID = pid;
                crocodiles[(j * MAX_CROCODILES) + i ] = newCroc;
            }
        }
    }
}
*/

void createCrocodile(int *pipe, Crocodile *crocodiles) {
    Crocodile newCroc;

    for (int j = 0; j < LINES - 4; j++) {
        int rowspeed = 1; // Velocità fissa per ora

        for (int i = 0; i < MAX_CROCODILES; i++) {
            // Inizializza i valori prima di fork()
            newCroc.cords.x = rand() % (COLS - 1) + 1;
            newCroc.cords.y = j + 2;
            newCroc.cords.direction = (j % 2 == 0) ? 1 : -1;
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



void moveCrocodile(int *pipe, Crocodile *crocodile) {

    

    while (1) {

        crocodile->cords.x += (crocodile->cords.direction * crocodile->cords.speed);

        //vari controlli per vedere se esce dallo schermo

        //da cambiare con le MACRO
        if (crocodile->cords.x >= COLS + 1) { 
            //aspetto un quanto di tempo random

            usleep((rand() % 200000) + 100000); 
            crocodile->cords.x = 0;
            
        } else if (crocodile->cords.x < -2) {
            
            //funzionerà con lo sleep?ridondante

            usleep((rand() % 200000) + 100000);
            crocodile->cords.x = COLS - 1;
        }
        writeData(pipe[1], &crocodile->cords, sizeof(Coordinates));


        
        usleep(200000);
    }   



}