#pragma once


//da togliere (?)
#include <sys/types.h>






typedef struct {
    unsigned int isRunning;
    Player player;
    Crocodile *crocodiles;
    int serverSocket;
} Game;



//boh poi si vedrà


//utile per la communicazione tra client e server
typedef struct {
    short x;
    short y;
    short direction;
} Coordinates;


//serve per la grafica (? da capire)


typedef struct {
    
    pid_t PID;
    Coordinates cords;   /* cordinate riferite al punto in alto a sinistra del coccodrilo */
    short speed;        /* velocità */
    Sprite sprite;
} Crocodile;


typedef struct {
    pid_t PID;    /* PID del proiettile */
    Coordinates cords;
    Sprite sprite;
    short speed;   //aumetabile con la difficoltà

} Projectile;



typedef struct {
    pid_t PID;    /* PID della granata */
    Coordinates cords;
    Sprite sprite;
    short speed;    //???
    short lifeSpan;    //tempo di vita ( o passi compiuti)
} Grenade;

typedef struct 
{
    short length;
    short height;
    char **texture;

}Sprite;



//può avere senso?
typedef struct {

    Coordinates cords;
    Sprite sprite;
    short lives;
    short score;
    unsigned short int isOnCrocodile;
    
} Player;