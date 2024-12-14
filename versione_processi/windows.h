#pragma once
#include <stdlib.h>
#include <time.h>   
#include <ncurses.h>

#define COLUMN_BORDER 50
#define LINES_BORDER 100
//void initMainWindow();    giàfatto nel main (lascio qua per sicurezza)

WINDOW *createWindow(int height, int width, int starty, int startx);

void deleteWindow(WINDOW *win);

void setupGameWindow();

void updateScoreWindow(WINDOW *scoreWindow, int score);

void updateGameWindow(WINDOW *gameWindow);