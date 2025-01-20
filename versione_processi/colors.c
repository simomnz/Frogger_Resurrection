#include "colors.h"


/* Initialize RGB colors to ncurses standards */
void initColors(short c, short r, short g, short b){

    init_color(c, r * RGB_CONVERTER, g * RGB_CONVERTER, b * RGB_CONVERTER);   
} 


/* Create Colors and Colors Pair */
void setColors()
{
    initColors(COLOR_BLACK, 0, 0, 0);
    initColors(WHITE, 254, 254, 254); 
    initColors(GRASS_GREEN, 129, 212, 26);
    initColors(RIVER_BLUE, 0, 147, 217);
    initColors(RED, 255, 0, 0);
    initColors(BLUE, 0, 0, 255);
    initColors(SCORE, 126, 252, 236);


    
    

    init_pair(GRASS, GRASS_GREEN, GRASS_GREEN);
    init_pair(RIVER, RIVER_BLUE, RIVER_BLUE);

    init_pair(RED_SIGN, RED, COLOR_BLACK);
    init_pair(BLUE_SIGN, BLUE, COLOR_BLACK);
    init_pair(YELLOW_SIGN, SCORE, COLOR_BLACK);
    init_pair(LOSE, RED, COLOR_BLACK);
    init_pair(WIN, BLUE, COLOR_BLACK);

    init_pair(MENU, COLOR_BLACK, COLOR_BLACK);
    init_pair(WRITES, WHITE, RIVER_BLUE);








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
    init_pair(CROC_1_1, WHITE, CROC_BORDER_GRAY);
    init_pair(CROC_1_2, CROC_GRAY, CROC_BORDER_GRAY);
    init_pair(CROC_1_3, WHITE, CROC_BORDER_GRAY);
    init_pair(CROC_1_4, CROC_GRAY, CROC_BORDER_GRAY);
    init_pair(CROC_1_5, WHITE, CROC_BORDER_GRAY);
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
    init_pair(CROC_2_3, CROC_BORDER_GRAY, WHITE);
    init_pair(CROC_2_4, CROC_BORDER_GRAY, CROC_GRAY);
    init_pair(CROC_2_5, CROC_BORDER_GRAY, WHITE);
    init_pair(CROC_2_6, CROC_BORDER_GRAY, CROC_GRAY);
    init_pair(CROC_2_7, CROC_BORDER_GRAY, WHITE);
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
    init_pair(OCC_DEN_0_2, FROG_GREEN, COLOR_BLACK);
    init_pair(OCC_DEN_0_3, FROG_GREEN, FROG_ORANGE);
    init_pair(OCC_DEN_0_4, FROG_MIDDLE_EYE_GREEN, 0);
    init_pair(OCC_DEN_0_5, FROG_GREEN, FROG_ORANGE);
    init_pair(OCC_DEN_0_6, FROG_GREEN, COLOR_BLACK);
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

    initColors(PROJECTILE_DARK_YELLOW, 202, 153, 5);
    initColors(PROJECTILE_YELLOW, 220, 166, 5);
    initColors(PROJECTILE_LIGHT_YELLOW, 240, 180, 3);

    init_pair(PROJECTILE_0_1, PROJECTILE_DARK_YELLOW, PROJECTILE_DARK_YELLOW);
    init_pair(PROJECTILE_0_2, PROJECTILE_YELLOW, PROJECTILE_YELLOW);
    init_pair(PROJECTILE_0_3, PROJECTILE_LIGHT_YELLOW, PROJECTILE_LIGHT_YELLOW);


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

    //shield

    initColors(SHIELD_YELLOW, 255, 255, 166);

    init_pair(SHIELD_BORDER, SHIELD_YELLOW, SHIELD_YELLOW);

    //frogger


    initColors(FROGGER_GREEN, 129, 212, 26);
    initColors(FROGGER_DARK_GREEN, 0, 169, 51);
    /*
    //F_0
    init_pair(FROGGER_0_1, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_0_2, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_3, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_4, FROGGER_DARK_GREEN, FROGGER_GREEN);    
    init_pair(FROGGER_0_5, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_6, 0, 0);
    //R_0
    init_pair(FROGGER_0_7, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_0_8, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_9, FROGGER_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_0_10, FROGGER_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_0_11, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_12, 0, 0);
    //O_0
    init_pair(FROGGER_0_13, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_0_14, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_15, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_16, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_17, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_18, 0, 0);
    //G_0
    init_pair(FROGGER_0_19, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_0_20, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_21, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_22, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_23, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_24, 0, 0);
    //G_0
    init_pair(FROGGER_0_25, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_0_26, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_27, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_28, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_29, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_30, 0, 0);
    //E_0
    init_pair(FROGGER_0_31, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_0_32, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_33, FROGGER_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_0_34, FROGGER_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_0_35, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_36, 0, 0);
    //R_0
    init_pair(FROGGER_0_37, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_0_38, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_39, FROGGER_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_0_40, FROGGER_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_0_41, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_0_42, 0, 0);

    //F_1
    init_pair(FROGGER_1_1, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_2, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_3, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_4, FROGGER_GREEN, 0);    
    init_pair(FROGGER_1_5, FROGGER_GREEN, 0);
    init_pair(FROGGER_1_6, 0, 0);
    //R_1
    init_pair(FROGGER_1_7, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_8, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_9, FROGGER_GREEN, 0);
    init_pair(FROGGER_1_10, FROGGER_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_11, FROGGER_GREEN, 0);
    init_pair(FROGGER_1_12, 0, 0);
    //O_1
    init_pair(FROGGER_1_13, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_14, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_15, 0, 0);
    init_pair(FROGGER_1_16, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_17, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_18, 0, 0);
    //G_1
    init_pair(FROGGER_1_19, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_20, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_21, 0, 0);
    init_pair(FROGGER_1_22, 0, 0);
    init_pair(FROGGER_1_23, 0, 0);
    init_pair(FROGGER_1_24, 0, 0);
    //G_1
    init_pair(FROGGER_1_25, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_26, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_27, 0, 0);
    init_pair(FROGGER_1_28, 0, 0);
    init_pair(FROGGER_1_29, 0, 0);
    init_pair(FROGGER_1_30, 0, 0);

    //E_1
    init_pair(FROGGER_1_31, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_32, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_33, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_34, FROGGER_GREEN, 0);
    init_pair(FROGGER_1_35, FROGGER_GREEN, 0);
    init_pair(FROGGER_1_36, 0, 0);
    //R_1
    init_pair(FROGGER_1_37, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_38, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_1_39, FROGGER_GREEN, 0);
    init_pair(FROGGER_1_40, FROGGER_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_1_41, FROGGER_GREEN, 0);
    init_pair(FROGGER_1_42, 0, 0);

    //F_2
    init_pair(FROGGER_2_1, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_2, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_3, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_4, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_2_5, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_2_6, 0, 0);
    //R_2
    init_pair(FROGGER_2_7, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_8, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_9, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_2_10, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_11, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_12, 0, 0);
    //O_2
    init_pair(FROGGER_2_13, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_14, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_15, 0, 0);
    init_pair(FROGGER_2_16, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_17, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_18, 0, 0);
    //G_2
    init_pair(FROGGER_2_19, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_20, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_21, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_2_22, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_23, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_24, 0, 0);
    //G_2
    init_pair(FROGGER_2_25, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_26, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_27, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_2_28, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_29, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_30, 0, 0);
    //E_2
    init_pair(FROGGER_2_31, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_32, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_33, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_34, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_2_35, FROGGER_DARK_GREEN, 0);
    init_pair(FROGGER_2_36, 0, 0);
    //R_2
    init_pair(FROGGER_2_37, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_38, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_39, 0, 0);
    init_pair(FROGGER_2_40, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_2_41, FROGGER_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_2_42, 0, 0);

    //F_3
    init_pair(FROGGER_3_1, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_2, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_3, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_4, 0, 0);
    init_pair(FROGGER_3_5, 0, 0);
    init_pair(FROGGER_3_6, 0, 0);
    //R_3
    init_pair(FROGGER_3_7, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_8, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_9, 0, 0);
    init_pair(FROGGER_3_10, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_11, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_12, 0, 0);
    //O_3
    init_pair(FROGGER_3_13, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_14, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_15, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_16, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_17, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_18, 0, 0);
    //G_3
    init_pair(FROGGER_3_19, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_20, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_21, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_22, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_23, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_24, 0, 0);
    //G_3
    init_pair(FROGGER_3_25, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_26, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_27, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_28, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_29, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_30, 0, 0);
    //E_3
    init_pair(FROGGER_3_31, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_32, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_33, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_34, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_35, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_36, 0, 0);

    //R_3
    init_pair(FROGGER_3_37, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_38, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_39, 0, 0);
    init_pair(FROGGER_3_40, FROGGER_DARK_GREEN, FROGGER_DARK_GREEN);
    init_pair(FROGGER_3_41, FROGGER_DARK_GREEN, FROGGER_GREEN);
    init_pair(FROGGER_3_42, 0, 0);
    */

    




















    


    //da fare per ogni elemento e colore
}


