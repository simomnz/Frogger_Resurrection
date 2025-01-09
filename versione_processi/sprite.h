#pragma once
#include "struct.h"
#include <ncurses.h>
#include "menu.h"


#define PLAY_X 


#define FROG_HEIGHT 4
#define FROG_LENGTH 7

void printCrocodile(Crocodile *crocodile);


void printFrog(int x, int y);

void printMenu();

void printDifficultyMenu();