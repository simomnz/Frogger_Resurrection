#pragma once

#include <sys/types.h>
#include <pthread.h>

#include "sounds.h"

#define NUM_PROJECTILES 26

/* Structure to hold coordinates and related information */
typedef struct {
    short x;               /* X coordinate */
    short y;               /* Y coordinate */
    short direction;       /* Direction */
    unsigned short source; /* Source to Communicate*/
    short speed;           /* Speed */
    short flag;            /* Flag To Shoot */
    char type;             /* Type Of Object */
} Coordinates;

/* Structure to hold sprite dimensions */
typedef struct {
    short length;          /* Length of the sprite */
    short height;          /* Height of the sprite */
} Sprite;

/* Structure to hold player information */
typedef struct {
    Coordinates cords;     /* Player coordinates */
    Sprite sprite;         /* Player sprite */
    short lives;           /* Number of lives */
    short score;           /* Player score */
    unsigned short int isOnCrocodile; /* Is player on a crocodile */
} Player;

/* Structure to hold crocodile information */
typedef struct {
    pthread_t thread;             /* Process ID of the crocodile */
    Coordinates cords;     /* Crocodile coordinates */
    Sprite sprite;         /* Crocodile sprite */
} Crocodile;

/* Structure to hold projectile information */
typedef struct {
    pthread_t thread;             /* Process ID of the projectile */
    Coordinates cords;     /* Projectile coordinates */
    Sprite sprite;         /* Projectile sprite */
    short speed;           /* Speed of the projectile */
} Projectile;

/* Structure to hold grenade information */
typedef struct {
    pthread_t thread;            /* Process ID of the grenade */
    Coordinates cords;     /* Grenade coordinates */
    Sprite sprite;         /* Grenade sprite */
    short speed;           /* Speed of the grenade */
    short lifeSpan;        /* Lifespan of the grenade */
} Grenade;

/* Structure to hold game information */
typedef struct {
    int pipeFd[2];                     /* Pipe file descriptors */
    unsigned int isRunning;            /* Is the game running */
    Player player;                     /* Player information */
    Crocodile *crocodiles;             /* Array of crocodiles */
    Projectile *projectiles;           /* Array of projectiles */
    int serverSocket;                  /* Server socket */
    unsigned short int closedDen[5];   /* Closed dens */
    unsigned short int crocSpeed;      /* Speed of crocodiles */
    time_t timeDifficulty;             /* Time difficulty */
    unsigned int numCroc;              /* Number of crocodiles */
    short difficulty;                  /* Game difficulty */
} Game;
