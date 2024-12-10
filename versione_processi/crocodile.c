#include "crocodile.h"
#include "struct.h"


//li ho messi qua perchè poi verranno
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30


void moveCrocodile(Crocodile *crocodile, int pipe) {

    srand(time(NULL) + crocodile->PID); 


    while(1) {

        crocodile->cords.x += (crocodile->direction * crocodile->speed);

        //vari controlli per vedere se esce dallo schermo

        if  (crocodile->cords.x >= SCREEN_WIDTH) {
            //aspetto un quanto di tempo random

            sleep(getRespawnCrocTime());
            crocodile->cords.x = 0;
        } else if (crocodile->cords.x < 0) {
            
            //funzionerà con lo sleep?

            sleep(getRespawnCrocTime());
            crocodile->cords.x = SCREEN_WIDTH - 1;
        }
        write(pipe, &crocodile, sizeof(Crocodile));

    }   

    usleep(200000);


}


//funzione per il controllo valido dello spawn dei coccodrilli?
int validSpawn(Crocodile *crocodile) {

    //controllo se in quelle x + lunghezza del coccodrillo c'è un altro coccodrillo
    // TODO
    return 1;
}


int getRespawnCrocTime() {
    return (rand() % (CROCODILE_RESPAWN_MAX - CROCODILE_RESPAWN_MIN + 1)) + CROCODILE_RESPAWN_MIN;
}

void createCrocodile(int pipe) {

    for(int i= 0; i < rand() % (MAX_LINE_CROCODILES -MIN_LINE_CROCODILES)+ MIN_LINE_CROCODILES ; i++) {
       
        Crocodile crocodile;
        crocodile.PID = fork();
        crocodile.cords.x = 0;
        crocodile.cords.y = rand() % SCREEN_HEIGHT;   //da cambiare in righe di gioco
        crocodile.speed = 1;    //valore da cambiare in base alla difficoltà    
        crocodile.direction = 1;  //da cambiare in base alla riga
        crocodile.length = 9;  //valore a caso
        crocodile.height = 4;

        int y; 


        do{

            y = rand() % SCREEN_HEIGHT;  //va sostituito con le righe di gioco
            
        }while(!validSpawn(&crocodile));

        crocodile.cords.y = y;

        //aggiungere le cordinate in x (uguali per tutti nella stessa riga)


        moveCrocodile(&crocodile, pipe);

        exit(0);

    }
}