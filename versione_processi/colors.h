#pragma once
#include <ncurses.h>

/* Moltiplicando un valore RGB compreso tra 0 e 255 per questa costante, si converte il valore nella scala [0 - 1000] utilizzata da ncurses */
#define RGB_CONVERTER 3.921569


#define USE_COLOR(n) attron(COLOR_PAIR(n))


/* Prende il colore "c" e lo inizializza con i valori rgb */
void initColors(short c, short r, short g, short b);    //short o int?

void setColors();



/* Inizializzazione Colori Singoli*/

/* si inizia dal numero 9 per evitare conflitti con i colori predefiniti di ncurses (da 0 a 7, 8 come std )*/

//non sono sicuro che 8 sia lo standard color, per sicurezza lo evito



#define GRASS 10
#define RIVER 11

//Crocodiles



#define CROC_GRAY 12
#define CROC_YELLOW 13
#define CROC_BORDER_GRAY 14
#define CROC_BORDER_DARK_GRAY 15
#define CROC_BACK_GRAY 16
#define CROC_TUMMY_GRAY 17  //colore usato per la pancia del coccodrillo
#define CROC_DETAILS_GRAY 18   //colore usato per i dettagli


//Frog

#define FROG_GREEN 19
#define FROG_ORANGE 20
#define FROG_BORDER_GREEN 21
#define FROG_DETAILS_GREEN 22
#define FROG_LIGHT_GREEN 23


//Den

#define DEN_BORDER_GREEN 44 //no
#define DEN_MIDDLE_GREEN 24
#define DEN_DETAILS_GREEN 25
#define DEN_BODY_GREEN 26

//Occupied Den (standing frog)

#define FROG_MIDDLE_EYE_GREEN 27
#define FROG_TUMMY_YELLOW 28
#define FROG_LEG_DARKER_GREEN 29
#define FROG_LEG_GREEN 27
#define FROG_LEG_DARK_GREEN 21


//Grenade 

#define GRENADE_LIGHTEST_BLUE 30    //da in basso a sinistra a salire
#define GRENADE_LIGHT_BLUE 31
#define GRENADE_BLUE 32
#define GRENADE_DARK_BLUE 33
#define GRENADE_DARKEST_BLUE 34
#define GRENADE_FUSE_BROWN 35
#define GRENADE_FIRE_RED 36

//PROJECTILE

#define PROJECTILE_DARK_YELLOW 37
#define PROJECTILE_YELLOW 38
#define PROJECTILE_LIGHT_YELLOW 39



//EXPLOSION

#define EXPLOSION_RED 40
#define EXPLOSION_DARK_ORANGE 41
#define EXPLOSION_ORANGE 36
#define EXPLOSION_YELLOW 42

//Shield

#define SHIELD_YELLOW 43


//coppie di colori
//(fino a 21)
// Crocodile
#define CROC_0_1 10
#define CROC_0_2 11
#define CROC_0_3 12
#define CROC_0_4 13
#define CROC_0_5 14
#define CROC_0_6 15
#define CROC_0_7 16
#define CROC_0_8 17
#define CROC_0_9 18
#define CROC_0_10 19
#define CROC_0_11 20
#define CROC_0_12 21
#define CROC_0_13 22
#define CROC_0_14 23
#define CROC_0_15 24
#define CROC_0_16 25
#define CROC_0_17 26
#define CROC_0_18 27
#define CROC_0_19 28
#define CROC_0_20 29
#define CROC_0_21 30
#define CROC_1_0 31
#define CROC_1_1 32
#define CROC_1_2 33
#define CROC_1_3 34
#define CROC_1_4 35
#define CROC_1_5 36
#define CROC_1_6 37
#define CROC_1_7 38
#define CROC_1_8 39
#define CROC_1_9 40
#define CROC_1_10 41
#define CROC_1_11 42
#define CROC_1_12 43
#define CROC_1_13 44
#define CROC_1_14 45
#define CROC_1_15 46
#define CROC_1_16 47
#define CROC_1_17 48
#define CROC_1_18 49
#define CROC_1_19 50
#define CROC_1_20 51
#define CROC_2_1 53
#define CROC_2_2 54
#define CROC_2_3 55
#define CROC_2_4 56
#define CROC_2_5 57
#define CROC_2_6 58
#define CROC_2_7 59
#define CROC_2_8 60
#define CROC_2_9 61
#define CROC_2_10 62
#define CROC_2_11 63
#define CROC_2_12 64
#define CROC_2_13 65
#define CROC_2_14 66
#define CROC_2_15 67
#define CROC_2_16 68
#define CROC_2_17 69
#define CROC_2_18 70
#define CROC_2_19 71
#define CROC_2_20 72
#define CROC_2_21 73
#define CROC_3_1 74
#define CROC_3_2 75
#define CROC_3_3 76
#define CROC_3_4 77
#define CROC_3_5 78
#define CROC_3_6 79
#define CROC_3_7 80
#define CROC_3_8 81
#define CROC_3_9 82
#define CROC_3_10 83
#define CROC_3_11 84
#define CROC_3_12 85
#define CROC_3_13 86
#define CROC_3_14 87
#define CROC_3_15 88
#define CROC_3_16 89
#define CROC_3_17 90
#define CROC_3_18 91
#define CROC_3_19 92
#define CROC_3_20 93
#define CROC_3_21 94

// Frog

#define FROG_0_1 95
#define FROG_0_2 96
#define FROG_0_3 97
#define FROG_0_4 98
#define FROG_0_5 99
#define FROG_0_6 100
#define FROG_0_7 101
#define FROG_1_1 102
#define FROG_1_2 103
#define FROG_1_3 104
#define FROG_1_4 105
#define FROG_1_5 106
#define FROG_1_6 107
#define FROG_1_7 108
#define FROG_1_8 109
#define FROG_2_1 110
#define FROG_2_2 111
#define FROG_2_3 112
#define FROG_2_4 113
#define FROG_2_5 114
#define FROG_2_6 115
#define FROG_2_7 116
#define FROG_2_8 117
#define FROG_3_1 118
#define FROG_3_2 119
#define FROG_3_3 120
#define FROG_3_4 121
#define FROG_3_5 122
#define FROG_3_6 123
#define FROG_3_7 124
#define FROG_3_8 125

// Den
#define DEN_0_1 126
#define DEN_0_2 127
#define DEN_0_3 128
#define DEN_0_4 129
#define DEN_0_5 130
#define DEN_0_6 131
#define DEN_0_7 132
#define DEN_1_1 133
#define DEN_1_2 134
#define DEN_1_3 135
#define DEN_1_4 136
#define DEN_1_5 137
#define DEN_1_6 138
#define DEN_1_7 139
#define DEN_1_8 140
#define DEN_2_1 141
#define DEN_2_2 142
#define DEN_2_3 143
#define DEN_2_4 144
#define DEN_2_5 145
#define DEN_2_6 146
#define DEN_2_7 147
#define DEN_2_8 148
#define DEN_3_1 149
#define DEN_3_2 150
#define DEN_3_3 151
#define DEN_3_4 152
#define DEN_3_5 153
#define DEN_3_6 154
#define DEN_3_7 155
#define DEN_3_8 156

// Occupied Den
#define OCC_DEN_0_1 157
#define OCC_DEN_0_2 158
#define OCC_DEN_0_3 159
#define OCC_DEN_0_4 160
#define OCC_DEN_0_5 161
#define OCC_DEN_0_6 162
#define OCC_DEN_0_7 163
#define OCC_DEN_1_0 164
#define OCC_DEN_1_1 165
#define OCC_DEN_1_2 166
#define OCC_DEN_1_3 167
#define OCC_DEN_1_4 168
#define OCC_DEN_1_5 169
#define OCC_DEN_1_6 170
#define OCC_DEN_1_7 171
#define OCC_DEN_2_1 172
#define OCC_DEN_2_2 173
#define OCC_DEN_2_3 174
#define OCC_DEN_2_4 175
#define OCC_DEN_2_5 176
#define OCC_DEN_2_6 177
#define OCC_DEN_2_7 178
#define OCC_DEN_2_8 179
#define OCC_DEN_3_1 180
#define OCC_DEN_3_2 181
#define OCC_DEN_3_3 182
#define OCC_DEN_3_4 183
#define OCC_DEN_3_5 184
#define OCC_DEN_3_6 185
#define OCC_DEN_3_7 186
#define OCC_DEN_3_8 187

// Grenade
#define GRENADE_0_1 188
#define GRENADE_0_2 189
#define GRENADE_0_3 190
#define GRENADE_1_1 191
#define GRENADE_1_2 192
#define GRENADE_1_3 193

// Projectile
#define PROJECTILE_0_1 194
#define PROJECTILE_0_2 195
#define PROJECTILE_0_3 196

// Explosion
#define EXPLOSION_0_1 197
#define EXPLOSION_0_2 198
#define EXPLOSION_0_3 199
#define EXPLOSION_0_4 200
#define EXPLOSION_1_1 201
#define EXPLOSION_1_2 202
#define EXPLOSION_1_3 203
#define EXPLOSION_1_4 204










