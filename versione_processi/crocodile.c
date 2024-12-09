#include "crocodile.h"
#include "struct.h"
#include "utils.h"
#include "menu.h"

//li ho messi qua perchè poi verranno
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30


void moveCrocodile(Crocodile *crocodile, int pipe) {




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
        writeData(pipe, &crocodile, sizeof(Crocodile));

    }   

    usleep(200000);


}





int getRespawnCrocTime() {
    return (rand() % (CROCODILE_RESPAWN_MAX - CROCODILE_RESPAWN_MIN + 1)) + CROCODILE_RESPAWN_MIN;
}


//da cambiare la matrice (?)
void createCrocodile(int pipe, Crocodile *crocodiles) {


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
            newCroc.sprite.lenght = CROCODILE_LENGTH;  //valore a caso
            newCroc.sprite.height = CROCODILE_HEIGHT;  

            newCroc.cords.y = j;

        }

    }
    exit(0);   
}

