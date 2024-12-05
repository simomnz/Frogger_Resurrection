
//da togliere (?)
#include <sys/types.h>




//aggiungere la struct game (?)

typedef struct frog
{
    short x;
    short y;

} Frog;

typedef struct crocodile
{
    pid_t PID;
    short x;            /* cordinate in x */
    short y;            /* cordinate in y */
    short speed;        /* velocità */
    short direction;    /* direzione */
    short length;       /* lunghezza */
    short genTime;      /* tempo di generazione */
    short shotTime;     /* tempo per sparare */
} Crocodile;


typedef struct projectile
{
    pid_t PID;    /* PID del proiettile */
    short x;
    short y;
    short speed;   //aumetabile con la difficoltà
    short direction;

} Projectile;


typedef struct grenade
{
    pid_t PID;    /* PID della granata */
    short x;
    short y;
    short speed;    //???
    short direction;
    short life;    //tempo di vita ( o passi compiuti)
} Grenade;