#pragma once
#include "struct.h"
#include <ncurses.h>
#include "menu.h"


#define PLAY_X 
#define FROGGER_HEIGHT 4
#define FROGGER_LENGTH 42



void printCrocodile(Crocodile *crocodile);


void printFrog(int x, int y);

void printDen();

void printMenu();

void printDifficultyMenu();

void printRiver();

void printGrass();
void printFrogger();