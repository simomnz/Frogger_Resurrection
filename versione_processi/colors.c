#include "colors.h"


void initColors(int c, int r, int g, int b){

    /* init_color e' una funzione di ncurses*/

    init_color(c, r * RGB_CONVERTER, g * RGB_CONVERTER, b * RGB_CONVERTER);   
} 

void setColors()
{
    /*funzione per settare i colori ad ogni elemento del gioco, esempio:*/

    initColors(BLU, 0, 0, 255);   //da controllare la correttezza dei valori
    initColors(CELESTE, 135, 206, 235);
    init_pair(FIUME, BLU, CELESTE);




    //da fare per ogni elemento e colore
}


