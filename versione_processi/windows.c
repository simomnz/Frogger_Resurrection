#include "windows.h"



// void initMainWindows()
// { 
//     initscr();  /* Inizializza ncurses */
//     noecho();   /* Non visualizzare i caratteri digitati */
//     cbreak();   /* Disabilita il buffer di linea */
//     keypad(stdscr, TRUE);   /* Abilita i tasti funzione */
//     curs_set(0);    /* Nasconde il cursore */
// }

time_t start_time;

WINDOW *createWindow(int height, int width, int starty, int startx)
{ 
    /* La funzione non crea il bordo della finestra, che, appena creata (sarà invisibile) */
    WINDOW *win;
    win = newwin(height, width, starty, startx);
    //wrefresh(win);
    return win;   
}

void deleteWindow(WINDOW *win)
{ 
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');  /* Rimuove i bordi */
    wrefresh(win);  /* Aggiorna la finestra */
    delwin(win);    /* Elimina la finestra */
}

void setupGameWindow()
{
    WINDOW *scoreWindow, *gameWindow;
    scoreWindow = createWindow(3, COLS, 0, 0);  //i parametri sono: altezza, larghezza, coordinata y, coordinata x
    gameWindow = createWindow(LINES - 3, COLS, 3, 0);  //i parametri sono: altezza, larghezza, coordinata y, coordinata x
}

void updateScoreWindow(WINDOW *scoreWindow, int score)
{
    wclear(scoreWindow);
    wprintw(scoreWindow, "Score: %d", score);
    wrefresh(scoreWindow);
}

void updateGameWindow(WINDOW *gameWindow)
{
    wclear(gameWindow);
    wprintw(gameWindow, "Time: %d", (int)difftime(time(NULL), start_time));
    wrefresh(gameWindow);
}