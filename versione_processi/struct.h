#pragma once

#include <sys/types.h>


#define MAX_CROCODILES 2



typedef struct {
    short x;
    short y;
    short direction;
    unsigned short source;
    short speed;
} Coordinates;

typedef struct {
    short length;
    short height;
    char **texture;
} Sprite;

typedef struct {
    Coordinates cords;
    Sprite sprite;
    short lives;
    short score;
    unsigned short int isOnCrocodile;
} Player;

typedef struct {
    pid_t PID;
    Coordinates cords;
    Sprite sprite;
} Crocodile;

typedef struct {
    pid_t PID;
    Coordinates cords;
    Sprite sprite;
    short speed;
} Projectile;

typedef struct {
    pid_t PID;
    Coordinates cords;
    Sprite sprite;
    short speed;
    short lifeSpan;
} Grenade;


typedef struct {
    int pipeFd[2];
    int gameToPipe[2];
    unsigned int isRunning;
    Player player;
    Crocodile crocodiles[MAX_CROCODILES];
    int serverSocket;
    unsigned short int closedDen[5];
    unsigned short int crocSpeed;
} Game;
