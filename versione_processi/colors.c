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
    init_color(CROC_TUMMY_GREEN, 119, 188, 101);
    init_color(CROC_DETAILS_GREEN, 70, 138, 26);


    init_pair(CROC_0_1, RIVER, RIVER);
    init_pair(CROC_0_2, RIVER, RIVER);
    init_pair(CROC_0_3, RIVER, RIVER);
    init_pair(CROC_0_4, RIVER, RIVER);
    init_pair(CROC_0_5, RIVER, RIVER);
    init_pair(CROC_0_6, RIVER, RIVER);
    init_pair(CROC_0_7, CROC_BORDER_DARK_GREEN, RIVER);
    init_pair(CROC_0_8, CROC_GREEN, RIVER);
    init_pair(CROC_0_9, CROC_GREEN, RIVER);
    init_pair(CROC_0_10, CROC_BORDER_DARK_GREEN, RIVER);
    init_pair(CROC_0_11, RIVER, RIVER);
    init_pair(CROC_0_12, RIVER, RIVER);
    init_pair(CROC_0_13, RIVER, RIVER);
    init_pair(CROC_0_14, RIVER, RIVER);
    init_pair(CROC_0_15, RIVER, RIVER);
    init_pair(CROC_0_16, RIVER, RIVER);
    init_pair(CROC_0_17, RIVER, RIVER);
    init_pair(CROC_0_18, RIVER, RIVER);
    init_pair(CROC_0_19, RIVER, RIVER);
    init_pair(CROC_0_20, RIVER, RIVER);
    init_pair(CROC_0_21, RIVER, RIVER);
    init_pair(CROC_1_0, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_1_1, COLOR_WHITE, CROC_BORDER_GREEN);
    init_pair(CROC_1_2, CROC_GREEN, CROC_BORDER_GREEN);
    init_pair(CROC_1_3, COLOR_WHITE, CROC_BORDER_GREEN);
    init_pair(CROC_1_4, CROC_GREEN, CROC_BORDER_GREEN);
    init_pair(CROC_1_5, COLOR_WHITE, CROC_BORDER_GREEN);
    init_pair(CROC_1_6, CROC_GREEN, CROC_GREEN);
    init_pair(CROC_1_7, CROC_GREEN, COLOR_BLACK);
    init_pair(CROC_1_8, CROC_GREEN, CROC_YELLOW);
    init_pair(CROC_1_9, CROC_GREEN, CROC_GREEN);

    init_pair(CROC_1_10, CROC_BACK_GREEN, CROC_BACK_GREEN);
    init_pair(CROC_1_11, CROC_GREEN, CROC_BACK_GREEN);
    init_pair(CROC_1_12, CROC_GREEN, CROC_BORDER_DARK_GREEN);
    init_pair(CROC_1_13, CROC_BACK_GREEN, CROC_BACK_GREEN);
    init_pair(CROC_1_14, CROC_GREEN, CROC_BORDER_DARK_GREEN);
    init_pair(CROC_1_15, CROC_GREEN, CROC_BACK_GREEN);
    init_pair(CROC_1_16, CROC_GREEN, CROC_BORDER_DARK_GREEN);
    init_pair(CROC_1_17, CROC_BACK_GREEN, CROC_BACK_GREEN);
    init_pair(CROC_1_18, CROC_BORDER_GREEN, CROC_BORDER_DARK_GREEN);
    init_pair(CROC_1_19, CROC_BACK_GREEN, CROC_BORDER_GREEN);
    init_pair(CROC_1_20, CROC_BORDER_GREEN, CROC_BORDER_GREEN);

    init_pair(CROC_2_1, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_2_2, CROC_BORDER_GREEN, CROC_GREEN);
    init_pair(CROC_2_3, CROC_BORDER_GREEN, COLOR_WHITE);
    init_pair(CROC_2_4, CROC_BORDER_GREEN, CROC_GREEN);
    init_pair(CROC_2_5, CROC_BORDER_GREEN, COLOR_WHITE);
    init_pair(CROC_2_6, CROC_BORDER_GREEN, CROC_GREEN);
    init_pair(CROC_2_7, CROC_BORDER_GREEN, COLOR_WHITE);
    init_pair(CROC_2_8, CROC_GREEN, CROC_GREEN);
    init_pair(CROC_2_9, CROC_DETAILS_GREEN, CROC_GREEN);
    init_pair(CROC_2_10, CROC_DETAILS_GREEN, CROC_GREEN);
    init_pair(CROC_2_11, CROC_TUMMY_GREEN, CROC_GREEN);
    init_pair(CROC_2_12, CROC_TUMMY_GREEN, CROC_DETAILS_GREEN);
    init_pair(CROC_2_13, CROC_TUMMY_GREEN, CROC_DETAILS_GREEN);
    init_pair(CROC_2_14, CROC_TUMMY_GREEN, CROC_GREEN);
    init_pair(CROC_2_15, CROC_GREEN, CROC_GREEN);
    init_pair(CROC_2_16, CROC_GREEN, CROC_GREEN);
    init_pair(CROC_2_17, CROC_DETAILS_GREEN, CROC_GREEN);
    init_pair(CROC_2_18, CROC_DETAILS_GREEN, CROC_DETAILS_GREEN);
    init_pair(CROC_2_19, CROC_BORDER_GREEN, CROC_DETAILS_GREEN);
    init_pair(CROC_2_20, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_2_21, CROC_BORDER_GREEN, RIVER);

    init_pair(CROC_3_1, RIVER, RIVER);
    init_pair(CROC_3_2, RIVER, RIVER);
    init_pair(CROC_3_3, RIVER, RIVER);
    init_pair(CROC_3_4, RIVER, RIVER);
    init_pair(CROC_3_5, RIVER, RIVER);
    init_pair(CROC_3_6, RIVER, RIVER);
    init_pair(CROC_3_7, RIVER, RIVER);
    init_pair(CROC_3_8, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_3_9, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_3_10, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_3_11, RIVER, RIVER);
    init_pair(CROC_3_12, RIVER, RIVER);
    init_pair(CROC_3_13, RIVER, RIVER);
    init_pair(CROC_3_14, RIVER, RIVER);
    init_pair(CROC_3_15, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_3_16, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_3_17, CROC_BORDER_GREEN, RIVER);
    init_pair(CROC_3_18, RIVER, RIVER);
    init_pair(CROC_3_19, RIVER, RIVER);
    init_pair(CROC_3_20, RIVER, RIVER);
    init_pair(CROC_3_21, RIVER, RIVER);
    



    //spazio per le coppie di colori

    init_color(RIVER, 89, 131, 176);

    //frog
    init_color(FROG_GREEN, 0, 176, 80);
    init_color(FROG_ORANGE, 232, 162, 2);
    init_color(FROG_BORDER_GREEN, 22, 130, 80);
    init_color(FROG_DETAILS_GREEN, 63, 175, 70);
    init_color(FROG_LIGHT_GREEN, 119, 188, 101);

    init_pair(FROG_0_1, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_0_2, RIVER, RIVER);
    init_pair(FROG_0_3, FROG_GREEN, FROG_ORANGE);
    init_pair(FROG_0_4, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_0_5, FROG_GREEN, FROG_ORANGE);
    init_pair(FROG_0_6, RIVER, RIVER);
    init_pair(FROG_0_7, FROG_BORDER_GREEN, FROG_GREEN);
    init_pair(FROG_1_1, FROG_BORDER_GREEN, RIVER);
    init_pair(FROG_1_2, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_1_3, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(FROG_1_4, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_1_5, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_1_6, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(FROG_1_7, FROG_BORDER_GREEN, RIVER);
    init_pair(FROG_2_1, FROG_GREEN, RIVER);
    init_pair(FROG_2_2, FROG_DETAILS_GREEN, FROG_BORDER_GREEN);
    init_pair(FROG_2_3, FROG_DETAILS_GREEN, FROG_LIGHT_GREEN);
    init_pair(FROG_2_4, FROG_DETAILS_GREEN, FROG_DETAILS_GREEN);
    init_pair(FROG_2_5, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_2_6, FROG_BORDER_GREEN, FROG_DETAILS_GREEN);
    init_pair(FROG_2_7, FROG_GREEN, RIVER);
    init_pair(FROG_3_1, FROG_BORDER_GREEN, FROG_BORDER_GREEN);
    init_pair(FROG_3_2, FROG_DETAILS_GREEN, RIVER);
    init_pair(FROG_3_3, FROG_GREEN, RIVER);
    init_pair(FROG_3_4, FROG_DETAILS_GREEN, RIVER);
    init_pair(FROG_3_5, FROG_GREEN, RIVER);
    init_pair(FROG_3_6, FROG_DETAILS_GREEN, RIVER);
    init_pair(FROG_3_7, FROG_GREEN, FROG_BORDER_GREEN);





    //den
    init_color(DEN_BORDER_GREEN, 18, 118, 34);
    init_color(DEN_MIDDLE_GREEN, 6, 154, 46);
    init_color(DEN_DETAILS_GREEN, 63, 175, 70);
    init_color(DEN_BODY_GREEN, 94, 185, 30);

    init_pair(DEN_0_1, DEN_BORDER_GREEN, RIVER);
    init_pair(DEN_0_2, DEN_BODY_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_3, DEN_BODY_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_4, DEN_MIDDLE_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_5, DEN_BODY_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_6, DEN_DETAILS_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_7, DEN_BORDER_GREEN, RIVER);
    init_pair(DEN_1_1, DEN_BORDER_GREEN, RIVER);
    init_pair(DEN_1_2, DEN_DETAILS_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_1_3, DEN_BODY_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_1_4, DEN_MIDDLE_GREEN, DEN_MIDDLE_GREEN);
    init_pair(DEN_1_5, DEN_BODY_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_1_6, DEN_BORDER_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_1_7, DEN_BORDER_GREEN, RIVER);
    init_pair(DEN_2_1, DEN_BORDER_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_2_2, DEN_DETAILS_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_2_3, DEN_BODY_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_2_4, DEN_MIDDLE_GREEN, DEN_MIDDLE_GREEN);
    init_pair(DEN_2_5, DEN_BODY_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_2_6, DEN_BODY_GREEN, DEN_DETAILS_GREEN);
    init_pair(DEN_2_7, DEN_BORDER_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_3_1, RIVER, RIVER);
    init_pair(DEN_3_2, DEN_BORDER_GREEN, RIVER);
    init_pair(DEN_3_3, DEN_BORDER_GREEN, DEN_DETAILS_GREEN);
    init_pair(DEN_3_4, DEN_MIDDLE_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_3_5, DEN_BORDER_GREEN, DEN_DETAILS_GREEN);
    init_pair(DEN_3_6, DEN_BORDER_GREEN, RIVER);
    init_pair(DEN_3_7, RIVER, RIVER);


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

    init_pair(GRENADE_0_1, GRENADE_BLUE, RIVER);
    init_pair(GRENADE_0_2, GRENADE_DARK_BLUE, GRENADE_FUSE_BROWN);
    init_pair(GRENADE_0_3, GRENADE_DARKEST_BLUE, GRENADE_FIRE_RED);
    init_pair(GRENADE_1_1, GRENADE_LIGHT_BLUE, GRENADE_LIGHTEST_BLUE);
    init_pair(GRENADE_1_2, GRENADE_LIGHT_BLUE, GRENADE_BLUE);
    init_pair(GRENADE_1_3, GRENADE_DARK_BLUE, GRENADE_DARK_BLUE);

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


