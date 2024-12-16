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


//da cambiare la matrice (?)
void createCrocodile(int *pipe, Crocodile *crocodiles) {


    //sostituire le righe 
    for(int j; j < LINES; j++)  {
        
        //TODO modificare il numero in base alla difficoltà
        for(int i= 0; i < 4; i++) {
        
            Crocodile newCroc;
            newCroc.PID = fork();
            srand(time(NULL) + newCroc.PID);
            newCroc.cords.x = 0;
            newCroc.cords.y = rand() % SCREEN_HEIGHT;   //da cambiare in righe di gioco


            newCroc.cords.direction = 1;  //da cambiare in base alla riga


            newCroc.speed = 1;    //valore da cambiare in base alla difficoltà    
            newCroc.sprite.length = CROCODILE_LENGTH;  //valore a caso
            newCroc.sprite.height = CROCODILE_HEIGHT;  

            newCroc.cords.y = j;


            //TODO
            moveCrocodile (pipe, &newCroc);
        }

    }
    exit(0);   
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
        writeData(pipe[1], &crocodile, sizeof(Crocodile));

    }   

    usleep(200000);


}