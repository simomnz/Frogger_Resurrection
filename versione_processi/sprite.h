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

void printDifficultyMenu(Game *game);

void printRiver();

void printGrass();

void printFrogger();

void printDenRiver();


void printCenteredArt(const char *art[], int numRows, int startRow, int color);

void printScoreBoard(int score, int lives);

/*
void printStart();
void printScore();
void printExit();*/