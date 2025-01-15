#pragma once

#include <ncurses.h>

#include "struct.h"
#include "menu.h"





#define EXPLOSION_LENGHT 4
#define EXPLOSION_HEIGHT 2
#define GAME_LINES 69
#define GAME_COLS 255




void printCrocodile(Crocodile *crocodile);


void printFrog(int x, int y);

void printDen(Game *game);

void printMenu();

void printDifficultyMenu(Game *game);

void printRiver();

void printGrass();

void printFrogger();

void printDenRiver();

void printTime(time_t time);

void printCenteredArt(const char *art[], int numRows, int startRow, int color);

void printScoreBoard(int score, int lives);

void printGrenade(int x, int y);

void printProjectile(Projectile *projectile);

void printExplosion(int x, int y);

void printShield(int x, int y);

void loseMenu();

void winMenu();

/*
void printStart();
void printScore();
void printExit();*/