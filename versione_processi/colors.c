#include "colors.h"


void initColors(short c, short r, short g, short b){

    /* init_color e' una funzione di ncurses*/

    init_color(c, r * RGB_CONVERTER, g * RGB_CONVERTER, b * RGB_CONVERTER);   
} 

void setColors()
{
    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_WHITE, 1000, 1000, 1000);

    //inizializzazione colori singoli

    //CROCODILES
    init_color(CROC_GREEN,0, 128, 0);
    init_color(CROC_YELLOW, 255, 255, 163);
    init_color(CROC_BORDER_GREEN, 18, 118, 34);
    init_color(CROC_BORDER_DARK_GREEN, 19, 108, 19);
    init_color(CROC_BACK_GREEN, 34, 75, 18);
    init_color(CROC_TAMMY_GREEN, 119, 188, 101);
    init_color(CROC_DETAILS_GREEN, 70, 138, 26);


    //spazio per le coppie di colori

    init_color(RIVER, 89, 131, 176);

    //frog
    init_color(FROG_GREEN, 0, 176, 80);
    init_color(FROG_ORANGE, 232, 162, 2);
    init_color(FROG_BORDER_GREEN, 22, 130, 80);
    init_color(FROG_DETAILS_GREEN, 63, 175, 70);
    init_color(FROG_LIGHT_GREEN, 119, 188, 101);

    //den
    init_color(DEN_BORDER_GREEN, 18, 118, 34);
    init_color(DEN_MIDDLE_GREEN, 6, 154, 46);
    init_color(DEN_DETAILS_GREEN, 63, 175, 70);
    init_color(DEN_BODY_GREEN, 94, 185, 30);

    //occupied den
    init_color(FROG_MIDDLE_EYE_GREEN, 6, 118, 6);
    init_color(FROG_TUMMY_YELLOW, 212, 234, 107);
    init_color(FROG_LEG_DARKER_GREEN, 17, 101, 65);
    init_color(FROG_LEG_DARK_GREEN, 22, 130, 83);
    init_color(FROG_LEG_GREEN, 6, 118, 6);

    init_pair(OCC_DEN_0_1, RIVER, RIVER);
    init_pair(OCC_DEN_0_2, COLOR_BLACK, FROG_GREEN);
    init_pair(OCC_DEN_0_3, FROG_ORANGE, FROG_GREEN);
    init_pair(OCC_DEN_0_4, FROG_MIDDLE_EYE_GREEN, RIVER);
    init_pair(OCC_DEN_0_5, FROG_ORANGE, FROG_GREEN);
    init_pair(OCC_DEN_0_6, COLOR_BLACK, FROG_GREEN);
    init_pair(OCC_DEN_0_7, RIVER, RIVER);
    init_pair(OCC_DEN_1_1, RIVER, RIVER);
    init_pair(OCC_DEN_1_2, FROG_DETAILS_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_1_3, FROG_TUMMY_YELLOW, FROG_GREEN);
    init_pair(OCC_DEN_1_4, FROG_TUMMY_YELLOW, FROG_GREEN);
    init_pair(OCC_DEN_1_5, FROG_TUMMY_YELLOW, FROG_GREEN);
    init_pair(OCC_DEN_1_6, FROG_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_1_7, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(OCC_DEN_2_1, FROG_LEG_DARKER_GREEN, RIVER);
    init_pair(OCC_DEN_2_2, FROG_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_2_3, FROG_DETAILS_GREEN, FROG_TUMMY_YELLOW);
    init_pair(OCC_DEN_2_4, FROG_TUMMY_YELLOW, FROG_TUMMY_YELLOW);
    init_pair(OCC_DEN_2_5, FROG_DETAILS_GREEN, FROG_TUMMY_YELLOW);
    init_pair(OCC_DEN_2_6, FROG_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_2_7, FROG_LEG_DARK_GREEN, RIVER);
    init_pair(OCC_DEN_3_1, FROG_LEG_DARK_GREEN, FROG_LEG_GREEN);
    init_pair(OCC_DEN_3_2, FROG_DETAILS_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_3_3, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(OCC_DEN_3_4, FROG_TUMMY_YELLOW, FROG_GREEN);
    init_pair(OCC_DEN_3_5, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(OCC_DEN_3_6, FROG_DETAILS_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_3_7, FROG_LEG_GREEN, FROG_LEG_DARK_GREEN);





    //grenade

    init_color(GRENADE_LIGHTEST_BLUE, 151,183,217);
    init_color(GRENADE_LIGHT_BLUE, 75, 127, 183);
    init_color(GRENADE_BLUE, 42, 96, 153);
    init_color(GRENADE_DARK_BLUE,11, 58, 107);
    init_color(GRENADE_DARKEST_BLUE, 6, 27, 49);
    init_color(GRENADE_FUSE_BROWN, 68, 50, 5);
    init_color(GRENADE_FIRE_RED, 255, 64, 0);

    //projectile

    init_color(PROJECTILE_DARK_YELLOW, 202, 153, 5);
    init_color(PROJECTILE_YELLOW, 220, 166, 5);
    init_color(PROJECTILE_LIGHT_YELLOW, 240, 180, 3);

    init_pair(PROJECTILE_0_1, PROJECTILE_DARK_YELLOW, RIVER);
    init_pair(PROJECTILE_0_2, PROJECTILE_YELLOW, RIVER);
    init_pair(PROJECTILE_0_3, PROJECTILE_LIGHT_YELLOW, RIVER);


    //explosion

    init_color(EXPLOSION_YELLOW, 255, 255, 0);
    init_color(EXPLOSION_ORANGE, 255, 191, 0);
    init_color(EXPLOSION_RED, 255, 64, 0);
    init_color(EXPLOSION_DARK_ORANGE, 255, 128, 0);

    init_pair(EXPLOSION_0_1, EXPLOSION_RED, EXPLOSION_DARK_ORANGE);
    init_pair(EXPLOSION_0_2, EXPLOSION_DARK_ORANGE, EXPLOSION_ORANGE);
    init_pair(EXPLOSION_0_3, EXPLOSION_ORANGE, EXPLOSION_YELLOW);
    init_pair(EXPLOSION_0_4, EXPLOSION_RED, EXPLOSION_DARK_ORANGE);
    init_pair(EXPLOSION_1_1, EXPLOSION_RED, EXPLOSION_DARK_ORANGE);
    init_pair(EXPLOSION_1_2, EXPLOSION_ORANGE, EXPLOSION_RED);
    init_pair(EXPLOSION_1_3, EXPLOSION_DARK_ORANGE, EXPLOSION_RED);
    init_pair(EXPLOSION_1_4, EXPLOSION_RED, EXPLOSION_DARK_ORANGE);











    //da fare per ogni elemento e colore
}


