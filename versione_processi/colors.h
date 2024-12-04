

/* Moltiplicando un valore RGB compreso tra 0 e 255 per questa costante, si converte il valore nella scala [0 - 1000] utilizzata da ncurses */
#define RGB_CONVERTER 3.921569




/* Prende il colore "c" e lo inizializza con i valori rgb */
void initColors(short c, short r, short g, short b);    //short o int?

void setColors();



/* Inizializzazione Colori Singoli*/

/* si inizia dal numero 9 per evitare conflitti con i colori predefiniti di ncurses (da 0 a 7, 8 come std )*/

//non sono sicuro che 8 sia lo standard color, per sicurezza lo evito

#define BLU 9
#define CELESTE 10   




/* Colori Elementi del gioco */

#define FIUME 1


