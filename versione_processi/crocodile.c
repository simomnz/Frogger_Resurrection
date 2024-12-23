#include "crocodile.h"
#include "struct.h"
#include "utils.h"
#include "menu.h"

//li ho messi qua perchè poi verranno eliminati
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30







int getRespawnCrocTime() {
    return (rand() % (CROCODILE_RESPAWN_MAX - CROCODILE_RESPAWN_MIN + 1)) + CROCODILE_RESPAWN_MIN;
}


void createCrocodile(int *pipe, Crocodile *crocodiles) {
    srand(time(NULL));

    Crocodile newCroc;
    for (int j = 0; j < LINES; j++) {
        for (int i = 0; i < MAX_CROCODILES; i++) {
            pid_t pid = fork();

            if (pid < 0) {
                perror("Fork failed");
                exit(1);
            } else if (pid == 0) {
                newCroc.cords.x = rand() % COLS;
                newCroc.cords.y = j;
                newCroc.cords.direction = 1;
                newCroc.cords.source = (j * MAX_CROCODILES) + i + 1;
                newCroc.speed = 1;
                newCroc.sprite.length = CROCODILE_LENGTH;
                newCroc.sprite.height = CROCODILE_HEIGHT;
                

                moveCrocodile(pipe, &newCroc);
                exit(0);
            } else {
                newCroc.PID = pid;
                crocodiles[i] = newCroc;
            }
        }
    }
}



void moveCrocodile(int *pipe, Crocodile *crocodile) {

    

    while (1) {

        crocodile->cords.x += (crocodile->cords.direction * crocodile->speed);

        //vari controlli per vedere se esce dallo schermo

        if (crocodile->cords.x >= SCREEN_WIDTH) {
            //aspetto un quanto di tempo random

            sleep(getRespawnCrocTime());
            crocodile->cords.x = 0;
            
        } else if (crocodile->cords.x < 0) {
            
            //funzionerà con lo sleep?ridondante

            sleep(getRespawnCrocTime());
            crocodile->cords.x = SCREEN_WIDTH - 1;
        }
        writeData(pipe[1], &crocodile->cords, sizeof(Coordinates));



        usleep(200000);
    }   



}