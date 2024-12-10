#pragma once


//da togliere (?)
#include <sys/types.h>






typedef struct {
    unsigned int isRunning;
    Player *player;
    Crocodile crocodiles;
} Game;



//boh poi si vedrà


//utile per la communicazione tra client e server
typedef struct {
    short x;
    short y;
} Coordinates;


//serve per la grafica (? da capire)
typedef struct {

    short width;
    short height;
    
} Frog;

typedef struct {
    
    pid_t PID;
    short x;            /* cordinate in x */
    short y;            /* cordinate in y */
    short speed;        /* velocità */
    short direction;    /* direzione */
    short length;       /* lunghezza */
    short genTime;      /* tempo di generazione */
    short shotTime;     /* tempo per sparare */
} Crocodile;


typedef struct {
    pid_t PID;    /* PID del proiettile */
    short x;
    short y;
    short speed;   //aumetabile con la difficoltà
    short direction;

} Projectile;



typedef struct {
    pid_t PID;    /* PID della granata */
    short x;
    short y;
    short speed;    //???
    short direction;
    short life;    //tempo di vita ( o passi compiuti)
} Grenade;




//può avere senso?
typedef struct {
    Frog frog;
    Coordinates cords;
    short lives;
    short score;
    unsigned short int isOnCrocodile;
    
} Player;