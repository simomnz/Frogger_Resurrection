//da togliere (?)
#include <ncurses.h>

//void initMainWindow();    giàfatto nel main (lascio qua per sicurezza)

WINDOW *createWindow(int height, int width, int starty, int startx);

void deleteWindow(WINDOW *win);

void setupGameWindow();

void updateScoreWindow(WINDOW *scoreWindow, int score);

void updateGameWindow(WINDOW *gameWindow);