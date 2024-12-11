#include "crocodile.h"
#include "struct.h"
#include "utils.h"

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

//ha senso la matrice (?), 
/*
int validSpawn(Crocodile *newCroc, Crocodile **currCrocs, int numCrocs) {  

    for(int i = 0; i < numCrocs; i++) {  
        
        //usare una matrice ?
        Crocodile *existCroc = &currCrocs[i];

        if(abs(newCroc->cords.x != (existCroc[i][j].cords.x + CROCODILE_LENGTH)) && abs(newCroc->cords.y != (existCroc[i][j].cords.y + CROCODILE_HEIGHT)))  {
                return 1;
        }
        
    }

    // TODO
    return 0;
}
  */



//numCrocs cambiabile con una funzione che restituisce len (?),non sono sicuro possa funzionare con array dinamico
int validSpawn(Crocodile *newCroc, Crocodile *currCrocs, int numCrocs) {  

    for(int i=0; i < numCrocs; i++){ 
        if(abs(newCroc->cords.x == (currCrocs[i].cords.x + CROCODILE_LENGTH)) && abs(newCroc->cords.y == (currCrocs[i].cords.y + CROCODILE_HEIGHT)))  {
            return 0;
        }
    }
    return 1;

}








int getRespawnCrocTime() {
    return (rand() % (CROCODILE_RESPAWN_MAX - CROCODILE_RESPAWN_MIN + 1)) + CROCODILE_RESPAWN_MIN;
}


//da cambiare la matrice (?)
void createCrocodile(int pipe, Crocodile *crocodiles) {

    

    //crea solo su una riga per adesso

    //TODO modificare il numero in base alla difficoltà
    for(int i= 0; i < 4; i++) {
       
        Crocodile newCroc;
        newCroc.PID = fork();
        srand(time(NULL) + newCroc.PID);
        newCroc.cords.x = 0;
        newCroc.cords.y = rand() % SCREEN_HEIGHT;   //da cambiare in righe di gioco


        newCroc.cords.direction = 1;  //da cambiare in base alla riga


        newCroc.speed = 1;    //valore da cambiare in base alla difficoltà    
        newCroc.length = 9;  //valore a caso
        newCroc.height = 4;

        int y; 


        do{

            y = rand() % SCREEN_HEIGHT;  //va sostituito con le righe di gioco
            

            //aggiustare chiamata a funzione
        }while(!validSpawn(&newCroc, ));

        newCroc.cords.y = y;

        //aggiungere le cordinate in x (uguali per tutti nella stessa riga)


        moveCrocodile(&newCroc, pipe);

        exit(0);

    }
}