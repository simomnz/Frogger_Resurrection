#include "windows.h"



// void initMainWindows()
// { 
//     initscr();  /* Inizializza ncurses */
//     noecho();   /* Non visualizzare i caratteri digitati */
//     cbreak();   /* Disabilita il buffer di linea */
//     keypad(stdscr, TRUE);   /* Abilita i tasti funzione */
//     curs_set(0);    /* Nasconde il cursore */
// }


void createWindow(int height, int width, int starty, int startx)
{ 
    /* La funzione non crea il bordo della finestra, che, appena creata (sarà invisibile) */
    WINDOW *win;
    win = newwin(height, width, starty, startx);
    wrefresh(win);   
}

void deleteWindow(WINDOW *win)
{ 
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');  /* Rimuove i bordi */
    wrefresh(win);  /* Aggiorna la finestra */
    delwin(win);    /* Elimina la finestra */
}

