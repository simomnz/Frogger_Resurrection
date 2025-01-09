#include "colors.h"


void initColors(short c, short r, short g, short b){

    /* init_color e' una funzione di ncurses*/

    init_color(c, r * RGB_CONVERTER, g * RGB_CONVERTER, b * RGB_CONVERTER);   
} 

void setColors()
{
    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_WHITE, 255, 255, 255);
    init_color(COLOR_BLUE, 0, 0, 255);
    init_color(COLOR_GREEN, 0, 255, 0);
    

    init_pair(GRASS, COLOR_GREEN, COLOR_GREEN);
    init_pair(RIVER, COLOR_BLUE, COLOR_BLUE);






    //inizializzazione colori singoli

    //CROCODILES
    initColors(CROC_GRAY, 102, 102, 102);
    initColors(CROC_YELLOW, 255, 255, 163);
    initColors(CROC_BORDER_GRAY, 80, 80, 80);
    initColors(CROC_BORDER_DARK_GRAY, 80, 78, 78);
    initColors(CROC_BACK_GRAY, 33, 33, 32);
    initColors(CROC_TUMMY_GRAY, 178, 178, 178); 
    initColors(CROC_DETAILS_GRAY, 116, 116, 1116);


    init_pair(CROC_0_1, 0, 0);
    init_pair(CROC_0_2, 0, 0);
    init_pair(CROC_0_3, 0, 0);
    init_pair(CROC_0_4, 0, 0);
    init_pair(CROC_0_5, 0, 0);
    init_pair(CROC_0_6, 0, 0);
    init_pair(CROC_0_7, CROC_BORDER_GRAY, 0);
    init_pair(CROC_0_8, CROC_GRAY, 0);
    init_pair(CROC_0_9, CROC_GRAY, 0);
    init_pair(CROC_0_10, CROC_BORDER_GRAY, 0);
    init_pair(CROC_0_11, 0, 0);
    init_pair(CROC_0_12, 0, 0);
    init_pair(CROC_0_13, 0, 0);
    init_pair(CROC_0_14, 0, 0);
    init_pair(CROC_0_15, 0, 0);
    init_pair(CROC_0_16, 0, 0);
    init_pair(CROC_0_17, 0, 0);
    init_pair(CROC_0_18, 0, 0);
    init_pair(CROC_0_19, 0, 0);
    init_pair(CROC_0_20, 0, 0);
    init_pair(CROC_0_21, 0, 0);
    init_pair(CROC_1_0, CROC_BORDER_GRAY, 0);
    init_pair(CROC_1_1, COLOR_WHITE, CROC_BORDER_GRAY);
    init_pair(CROC_1_2, CROC_GRAY, CROC_BORDER_GRAY);
    init_pair(CROC_1_3, COLOR_WHITE, CROC_BORDER_GRAY);
    init_pair(CROC_1_4, CROC_GRAY, CROC_BORDER_GRAY);
    init_pair(CROC_1_5, COLOR_WHITE, CROC_BORDER_GRAY);
    init_pair(CROC_1_6, CROC_GRAY, CROC_GRAY);
    init_pair(CROC_1_7, CROC_GRAY, COLOR_BLACK);
    init_pair(CROC_1_8, CROC_GRAY, CROC_YELLOW);
    init_pair(CROC_1_9, CROC_GRAY, CROC_GRAY);

    init_pair(CROC_1_10, CROC_BACK_GRAY, CROC_BACK_GRAY);
    init_pair(CROC_1_11, CROC_GRAY, CROC_BACK_GRAY);
    init_pair(CROC_1_12, CROC_GRAY, CROC_BORDER_DARK_GRAY);
    init_pair(CROC_1_13, CROC_BACK_GRAY, CROC_BACK_GRAY);
    init_pair(CROC_1_14, CROC_GRAY, CROC_BORDER_DARK_GRAY);
    init_pair(CROC_1_15, CROC_GRAY, CROC_BACK_GRAY);
    init_pair(CROC_1_16, CROC_GRAY, CROC_BORDER_DARK_GRAY);
    init_pair(CROC_1_17, CROC_BACK_GRAY, CROC_BACK_GRAY);
    init_pair(CROC_1_18, CROC_BORDER_GRAY, CROC_BORDER_DARK_GRAY);
    init_pair(CROC_1_19, CROC_BACK_GRAY, CROC_BORDER_GRAY);
    init_pair(CROC_1_20, CROC_BORDER_GRAY, CROC_BORDER_GRAY);

    init_pair(CROC_2_1, CROC_BORDER_GRAY, 0);
    init_pair(CROC_2_2, CROC_BORDER_GRAY, CROC_GRAY);
    init_pair(CROC_2_3, CROC_BORDER_GRAY, COLOR_WHITE);
    init_pair(CROC_2_4, CROC_BORDER_GRAY, CROC_GRAY);
    init_pair(CROC_2_5, CROC_BORDER_GRAY, COLOR_WHITE);
    init_pair(CROC_2_6, CROC_BORDER_GRAY, CROC_GRAY);
    init_pair(CROC_2_7, CROC_BORDER_GRAY, COLOR_WHITE);
    init_pair(CROC_2_8, CROC_GRAY, CROC_GRAY);
    init_pair(CROC_2_9, CROC_DETAILS_GRAY, CROC_GRAY);
    init_pair(CROC_2_10, CROC_DETAILS_GRAY, CROC_GRAY);
    init_pair(CROC_2_11,  CROC_GRAY, CROC_TUMMY_GRAY);
    init_pair(CROC_2_12,  CROC_GRAY, CROC_TUMMY_GRAY);
    init_pair(CROC_2_13,  CROC_GRAY, CROC_TUMMY_GRAY);
    init_pair(CROC_2_14,  CROC_GRAY, CROC_TUMMY_GRAY);
    init_pair(CROC_2_15, CROC_GRAY, CROC_GRAY);
    init_pair(CROC_2_16, CROC_GRAY, CROC_GRAY);
    init_pair(CROC_2_17, CROC_DETAILS_GRAY, CROC_GRAY);
    init_pair(CROC_2_18, CROC_DETAILS_GRAY, CROC_TUMMY_GRAY);
    init_pair(CROC_2_19, CROC_BORDER_GRAY, CROC_TUMMY_GRAY);
    init_pair(CROC_2_20, CROC_BORDER_GRAY, 0);
    init_pair(CROC_2_21, CROC_BORDER_GRAY, 0);

    init_pair(CROC_3_1, 0, 0);
    init_pair(CROC_3_2, 0, 0);
    init_pair(CROC_3_3, 0, 0);
    init_pair(CROC_3_4, 0, 0);
    init_pair(CROC_3_5, 0, 0);
    init_pair(CROC_3_6, 0, 0);
    init_pair(CROC_3_7, 0, 0);
    init_pair(CROC_3_8, CROC_BORDER_GRAY, 0);
    init_pair(CROC_3_9, CROC_BORDER_GRAY, 0);
    init_pair(CROC_3_10, CROC_BORDER_GRAY, 0);
    init_pair(CROC_3_11, 0, 0);
    init_pair(CROC_3_12, 0, 0);
    init_pair(CROC_3_13, 0, 0);
    init_pair(CROC_3_14, 0, 0);
    init_pair(CROC_3_15, CROC_BORDER_GRAY, 0);
    init_pair(CROC_3_16, CROC_BORDER_GRAY, 0);
    init_pair(CROC_3_17, CROC_BORDER_GRAY, 0);
    init_pair(CROC_3_18, 0, 0);
    init_pair(CROC_3_19, 0, 0);
    init_pair(CROC_3_20, 0, 0);
    init_pair(CROC_3_21, 0, 0);




    //spazio per le coppie di colori


    //frog
    
    initColors(FROG_GREEN, 0, 176, 80);
    initColors(FROG_ORANGE, 232, 162, 2);
    initColors(FROG_BORDER_GREEN, 22, 130, 80);
    initColors(FROG_DETAILS_GREEN, 63, 175, 70);
    initColors(FROG_LIGHT_GREEN, 119, 188, 101);

    init_pair(FROG_0_1, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_0_2, 0, 0);
    init_pair(FROG_0_3, FROG_GREEN, FROG_ORANGE);
    init_pair(FROG_0_4, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_0_5, FROG_GREEN, FROG_ORANGE);
    init_pair(FROG_0_6, 0, 0);
    init_pair(FROG_0_7, FROG_BORDER_GREEN, FROG_GREEN);
    init_pair(FROG_1_1, FROG_BORDER_GREEN, 0);
    init_pair(FROG_1_2, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_1_3, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(FROG_1_4, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_1_5, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_1_6, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(FROG_1_7, FROG_BORDER_GREEN, 0);
    init_pair(FROG_2_1, FROG_GREEN, 0);
    init_pair(FROG_2_2, FROG_DETAILS_GREEN, FROG_BORDER_GREEN);
    init_pair(FROG_2_3, FROG_DETAILS_GREEN, FROG_LIGHT_GREEN);
    init_pair(FROG_2_4, FROG_DETAILS_GREEN, FROG_DETAILS_GREEN);
    init_pair(FROG_2_5, FROG_GREEN, FROG_GREEN);
    init_pair(FROG_2_6, FROG_BORDER_GREEN, FROG_DETAILS_GREEN);
    init_pair(FROG_2_7, FROG_GREEN, 0);
    init_pair(FROG_3_1, FROG_BORDER_GREEN, FROG_BORDER_GREEN);
    init_pair(FROG_3_2, FROG_DETAILS_GREEN, 0);
    init_pair(FROG_3_3, FROG_GREEN, 0);
    init_pair(FROG_3_4, FROG_DETAILS_GREEN, 0);
    init_pair(FROG_3_5, FROG_GREEN, 0);
    init_pair(FROG_3_6, FROG_DETAILS_GREEN, 0);
    init_pair(FROG_3_7, FROG_GREEN, FROG_BORDER_GREEN);





    //den
    initColors(DEN_BORDER_GREEN, 18, 118, 34);
    initColors(DEN_MIDDLE_GREEN, 6, 154, 46);
    initColors(DEN_DETAILS_GREEN, 63, 175, 70);
    initColors(DEN_BODY_GREEN, 94, 185, 30);

    init_pair(DEN_0_1, DEN_BORDER_GREEN, 0);
    init_pair(DEN_0_2, DEN_BODY_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_3, DEN_BODY_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_4, DEN_MIDDLE_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_5, DEN_BODY_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_6, DEN_DETAILS_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_0_7, DEN_BORDER_GREEN, 0);
    init_pair(DEN_1_1, DEN_BORDER_GREEN, 0);
    init_pair(DEN_1_2, DEN_DETAILS_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_1_3, DEN_BODY_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_1_4, DEN_MIDDLE_GREEN, DEN_MIDDLE_GREEN);
    init_pair(DEN_1_5, DEN_BODY_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_1_6, DEN_BORDER_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_1_7, DEN_BORDER_GREEN, 0);
    init_pair(DEN_2_1, DEN_BORDER_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_2_2, DEN_DETAILS_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_2_3, DEN_BODY_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_2_4, DEN_MIDDLE_GREEN, DEN_MIDDLE_GREEN);
    init_pair(DEN_2_5, DEN_BODY_GREEN, DEN_BODY_GREEN);
    init_pair(DEN_2_6, DEN_BODY_GREEN, DEN_DETAILS_GREEN);
    init_pair(DEN_2_7, DEN_BORDER_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_3_1, 0, 0);
    init_pair(DEN_3_2, DEN_BORDER_GREEN, 0);
    init_pair(DEN_3_3, DEN_BORDER_GREEN, DEN_DETAILS_GREEN);
    init_pair(DEN_3_4, DEN_MIDDLE_GREEN, DEN_BORDER_GREEN);
    init_pair(DEN_3_5, DEN_BORDER_GREEN, DEN_DETAILS_GREEN);
    init_pair(DEN_3_6, DEN_BORDER_GREEN, 0);
    init_pair(DEN_3_7, 0, 0);


    //occupied den
    initColors(FROG_MIDDLE_EYE_GREEN, 6, 118, 6);
    initColors(FROG_TUMMY_YELLOW, 212, 234, 107);
    initColors(FROG_LEG_DARKER_GREEN, 17, 101, 65);
    initColors(FROG_LEG_DARK_GREEN, 22, 130, 83);
    initColors(FROG_LEG_GREEN, 6, 118, 6);

    init_pair(OCC_DEN_0_1, 0, 0);
    init_pair(OCC_DEN_0_2, COLOR_BLACK, FROG_GREEN);
    init_pair(OCC_DEN_0_3, FROG_ORANGE, FROG_GREEN);
    init_pair(OCC_DEN_0_4, FROG_MIDDLE_EYE_GREEN, 0);
    init_pair(OCC_DEN_0_5, FROG_ORANGE, FROG_GREEN);
    init_pair(OCC_DEN_0_6, COLOR_BLACK, FROG_GREEN);
    init_pair(OCC_DEN_0_7, 0, 0);
    init_pair(OCC_DEN_1_1, 0, 0);
    init_pair(OCC_DEN_1_2, FROG_DETAILS_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_1_3, FROG_TUMMY_YELLOW, FROG_GREEN);
    init_pair(OCC_DEN_1_4, FROG_TUMMY_YELLOW, FROG_GREEN);
    init_pair(OCC_DEN_1_5, FROG_TUMMY_YELLOW, FROG_GREEN);
    init_pair(OCC_DEN_1_6, FROG_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_1_7, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(OCC_DEN_2_1, FROG_LEG_DARKER_GREEN, 0);
    init_pair(OCC_DEN_2_2, FROG_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_2_3, FROG_DETAILS_GREEN, FROG_TUMMY_YELLOW);
    init_pair(OCC_DEN_2_4, FROG_TUMMY_YELLOW, FROG_TUMMY_YELLOW);
    init_pair(OCC_DEN_2_5, FROG_DETAILS_GREEN, FROG_TUMMY_YELLOW);
    init_pair(OCC_DEN_2_6, FROG_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_2_7, FROG_LEG_DARK_GREEN, 0);
    init_pair(OCC_DEN_3_1, FROG_LEG_DARK_GREEN, FROG_LEG_GREEN);
    init_pair(OCC_DEN_3_2, FROG_DETAILS_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_3_3, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(OCC_DEN_3_4, FROG_TUMMY_YELLOW, FROG_GREEN);
    init_pair(OCC_DEN_3_5, FROG_DETAILS_GREEN, FROG_GREEN);
    init_pair(OCC_DEN_3_6, FROG_DETAILS_GREEN, FROG_DETAILS_GREEN);
    init_pair(OCC_DEN_3_7, FROG_LEG_GREEN, FROG_LEG_DARK_GREEN);





    //grenade

    initColors(GRENADE_LIGHTEST_BLUE, 151,183,217);
    initColors(GRENADE_LIGHT_BLUE, 75, 127, 183);
    initColors(GRENADE_BLUE, 42, 96, 153);
    initColors(GRENADE_DARK_BLUE,11, 58, 107);
    initColors(GRENADE_DARKEST_BLUE, 6, 27, 49);
    initColors(GRENADE_FUSE_BROWN, 68, 50, 5);
    initColors(GRENADE_FIRE_RED, 255, 64, 0);

    init_pair(GRENADE_0_1, GRENADE_BLUE, 0);
    init_pair(GRENADE_0_2, GRENADE_DARK_BLUE, GRENADE_FUSE_BROWN);
    init_pair(GRENADE_0_3, GRENADE_DARKEST_BLUE, GRENADE_FIRE_RED);
    init_pair(GRENADE_1_1, GRENADE_LIGHT_BLUE, GRENADE_LIGHTEST_BLUE);
    init_pair(GRENADE_1_2, GRENADE_LIGHT_BLUE, GRENADE_BLUE);
    init_pair(GRENADE_1_3, GRENADE_DARK_BLUE, GRENADE_DARK_BLUE);

    //projectile

    init_color(PROJECTILE_DARK_YELLOW, 202, 153, 5);
    init_color(PROJECTILE_YELLOW, 220, 166, 5);
    init_color(PROJECTILE_LIGHT_YELLOW, 240, 180, 3);

    init_pair(PROJECTILE_0_1, PROJECTILE_DARK_YELLOW, 0);
    init_pair(PROJECTILE_0_2, PROJECTILE_YELLOW, 0);
    init_pair(PROJECTILE_0_3, PROJECTILE_LIGHT_YELLOW, 0);


    //explosion

    initColors(EXPLOSION_YELLOW, 255, 255, 0);
    initColors(EXPLOSION_ORANGE, 255, 191, 0);
    initColors(EXPLOSION_RED, 255, 64, 0);
    initColors(EXPLOSION_DARK_ORANGE, 255, 128, 0);

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


