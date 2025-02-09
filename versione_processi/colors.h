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



#define GRASS 1
#define RIVER 2

#define GRASS_GREEN 1
#define RIVER_BLUE 2

#define RED_SIGN 3
#define BLUE_SIGN 4
#define YELLOW_SIGN 5
#define MENU 6
#define WRITES 7
#define INFO 8

#define RED 3
#define BLUE 4
#define SCORE 5
#define WHITE 7





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

#define FROGGER_GREEN 44
#define FROGGER_DARK_GREEN 45
#define RESURRECTION_COLOR 46
#define LETTER_BORDER 47
#define START_LIGHT_BLUE 48
#define START_BLUE 49
#define START_DARK_BLUE 50
#define SCORE_LIGHT_YELLOW 51
#define SCORE_YELLOW 52
#define SCORE_DARK_YELLOW 53
#define EXIT_LIGHT_RED 54
#define EXIT_RED 55
#define EXIT_DARK_RED 56



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


#define SHIELD_BORDER 206




//lettere del menu


/*

#define FROGGER_0_1 205
#define FROGGER_0_2 206
#define FROGGER_0_3 207
#define FROGGER_0_4 208
#define FROGGER_0_5 209
#define FROGGER_0_6 210
#define FROGGER_0_7 211
#define FROGGER_0_8 212
#define FROGGER_0_9 213
#define FROGGER_0_10 214
#define FROGGER_0_11 215
#define FROGGER_0_12 216
#define FROGGER_0_13 217
#define FROGGER_0_14 218
#define FROGGER_0_15 219
#define FROGGER_0_16 220
#define FROGGER_0_17 221
#define FROGGER_0_18 222
#define FROGGER_0_19 223
#define FROGGER_0_20 224
#define FROGGER_0_21 225
#define FROGGER_0_22 226
#define FROGGER_0_23 227
#define FROGGER_0_24 228
#define FROGGER_0_25 229
#define FROGGER_0_26 230
#define FROGGER_0_27 231
#define FROGGER_0_28 232
#define FROGGER_0_29 233
#define FROGGER_0_30 234
#define FROGGER_0_31 235
#define FROGGER_0_32 236
#define FROGGER_0_33 237
#define FROGGER_0_34 238
#define FROGGER_0_35 239
#define FROGGER_0_36 240
#define FROGGER_0_37 241
#define FROGGER_0_38 242
#define FROGGER_0_39 243
#define FROGGER_0_40 244
#define FROGGER_0_41 245
#define FROGGER_0_42 246
#define FROGGER_1_1 247
#define FROGGER_1_2 248
#define FROGGER_1_3 249
#define FROGGER_1_4 250
#define FROGGER_1_5 251                                         
#define FROGGER_1_6 252
#define FROGGER_1_7 253
#define FROGGER_1_8 254
#define FROGGER_1_9 255
#define FROGGER_1_10 256
#define FROGGER_1_11 257
#define FROGGER_1_12 258
#define FROGGER_1_13 259
#define FROGGER_1_14 260
#define FROGGER_1_15 261
#define FROGGER_1_16 262
#define FROGGER_1_17 263
#define FROGGER_1_18 264
#define FROGGER_1_19 265
#define FROGGER_1_20 266
#define FROGGER_1_21 267
#define FROGGER_1_22 268
#define FROGGER_1_23 269
#define FROGGER_1_24 270
#define FROGGER_1_25 271
#define FROGGER_1_26 272
#define FROGGER_1_27 273
#define FROGGER_1_28 274
#define FROGGER_1_29 275
#define FROGGER_1_30 276
#define FROGGER_1_31 277
#define FROGGER_1_32 278
#define FROGGER_1_33 279
#define FROGGER_1_34 280
#define FROGGER_1_35 281
#define FROGGER_1_36 282
#define FROGGER_1_37 283
#define FROGGER_1_38 284
#define FROGGER_1_39 285
#define FROGGER_1_40 286
#define FROGGER_1_41 287
#define FROGGER_1_42 288
#define FROGGER_2_1 289
#define FROGGER_2_2 290
#define FROGGER_2_3 291
#define FROGGER_2_4 292
#define FROGGER_2_5 293
#define FROGGER_2_6 294
#define FROGGER_2_7 295
#define FROGGER_2_8 296
#define FROGGER_2_9 297
#define FROGGER_2_10 298
#define FROGGER_2_11 299
#define FROGGER_2_12 300
#define FROGGER_2_13 301
#define FROGGER_2_14 302
#define FROGGER_2_15 303
#define FROGGER_2_16 304
#define FROGGER_2_17 305
#define FROGGER_2_18 306
#define FROGGER_2_19 307
#define FROGGER_2_20 308
#define FROGGER_2_21 309
#define FROGGER_2_22 310
#define FROGGER_2_23 311
#define FROGGER_2_24 312
#define FROGGER_2_25 313
#define FROGGER_2_26 314
#define FROGGER_2_27 315
#define FROGGER_2_28 316
#define FROGGER_2_29 317
#define FROGGER_2_30 318
#define FROGGER_2_31 319
#define FROGGER_2_32 320
#define FROGGER_2_33 321
#define FROGGER_2_34 322
#define FROGGER_2_35 323
#define FROGGER_2_36 324
#define FROGGER_2_37 325
#define FROGGER_2_38 326
#define FROGGER_2_39 327
#define FROGGER_2_40 328
#define FROGGER_2_41 329
#define FROGGER_2_42 330
#define FROGGER_3_1 331
#define FROGGER_3_2 332
#define FROGGER_3_3 333
#define FROGGER_3_4 334
#define FROGGER_3_5 335
#define FROGGER_3_6 336
#define FROGGER_3_7 337
#define FROGGER_3_8 338
#define FROGGER_3_9 339
#define FROGGER_3_10 340
#define FROGGER_3_11 341
#define FROGGER_3_12 342
#define FROGGER_3_13 343
#define FROGGER_3_14 344
#define FROGGER_3_15 345
#define FROGGER_3_16 346
#define FROGGER_3_17 347
#define FROGGER_3_18 348
#define FROGGER_3_19 349
#define FROGGER_3_20 350
#define FROGGER_3_21 351
#define FROGGER_3_22 352
#define FROGGER_3_23 353
#define FROGGER_3_24 354
#define FROGGER_3_25 355
#define FROGGER_3_26 356
#define FROGGER_3_27 357
#define FROGGER_3_28 358
#define FROGGER_3_29 359
#define FROGGER_3_30 360
#define FROGGER_3_31 361
#define FROGGER_3_32 362
#define FROGGER_3_33 363
#define FROGGER_3_34 364
#define FROGGER_3_35 365
#define FROGGER_3_36 366
#define FROGGER_3_37 367
#define FROGGER_3_38 368
#define FROGGER_3_39 369
#define FROGGER_3_40 370
#define FROGGER_3_41 371
#define FROGGER_3_42 372
#define FROGGER_4_1 373
#define FROGGER_4_2 374
#define FROGGER_4_3 375
#define FROGGER_4_4 376
#define FROGGER_4_5 377
#define FROGGER_4_6 378
#define FROGGER_4_7 379
#define FROGGER_4_8 380
#define FROGGER_4_9 381
#define FROGGER_4_10 382
#define FROGGER_4_11 383
#define FROGGER_4_12 384
#define FROGGER_4_13 385
#define FROGGER_4_14 386
#define FROGGER_4_15 387
#define FROGGER_4_16 388
#define FROGGER_4_17 389
#define FROGGER_4_18 390
#define FROGGER_4_19 391
#define FROGGER_4_20 392
#define FROGGER_4_21 393
#define FROGGER_4_22 394
#define FROGGER_4_23 395
#define FROGGER_4_24 396
#define FROGGER_4_25 397
#define FROGGER_4_26 398
#define FROGGER_4_27 399
#define FROGGER_4_28 400
#define FROGGER_4_29 401
#define FROGGER_4_30 402
#define FROGGER_4_31 403
#define FROGGER_4_32 404
#define FROGGER_4_33 405
#define FROGGER_4_34 406
#define FROGGER_4_35 407
#define FROGGER_4_36 408
#define FROGGER_4_37 409
#define FROGGER_4_38 410
#define FROGGER_4_39 411
#define FROGGER_4_40 412
#define FROGGER_4_41 413
#define FROGGER_4_42 414


// Play
#define PLAY_0_1 415
#define PLAY_0_2 416
#define PLAY_0_3 417
#define PLAY_0_4 418
#define PLAY_0_5 419
#define PLAY_0_6 420
#define PLAY_0_7 421
#define PLAY_0_8 422
#define PLAY_0_9 423
#define PLAY_0_10 424
#define PLAY_0_11 425
#define PLAY_0_12 426
#define PLAY_0_13 427
#define PLAY_0_14 428
#define PLAY_0_15 429
#define PLAY_0_16 430
#define PLAY_0_17 431
#define PLAY_0_18 432
#define PLAY_0_19 433
#define PLAY_0_20 434
#define PLAY_0_21 435
#define PLAY_0_22 436
#define PLAY_0_23 437
#define PLAY_0_24 438
#define PLAY_0_25 439
#define PLAY_0_26 440
#define PLAY_0_27 441
#define PLAY_0_28 442
#define PLAY_1_1 443
#define PLAY_1_2 444
#define PLAY_1_3 445
#define PLAY_1_4 446
#define PLAY_1_5 447
#define PLAY_1_6 448
#define PLAY_1_7 449
#define PLAY_1_8 450
#define PLAY_1_9 451
#define PLAY_1_10 452
#define PLAY_1_11 453
#define PLAY_1_12 454
#define PLAY_1_13 455
#define PLAY_1_14 456
#define PLAY_1_15 457
#define PLAY_1_16 458
#define PLAY_1_17 459
#define PLAY_1_18 460
#define PLAY_1_19 461
#define PLAY_1_20 462
#define PLAY_1_21 463
#define PLAY_1_22 464
#define PLAY_1_23 465
#define PLAY_1_24 466
#define PLAY_1_25 467
#define PLAY_1_26 468
#define PLAY_1_27 469
#define PLAY_1_28 470
#define PLAY_2_1 471
#define PLAY_2_2 472
#define PLAY_2_3 473
#define PLAY_2_4 474
#define PLAY_2_5 475
#define PLAY_2_6 476
#define PLAY_2_7 477
#define PLAY_2_8 478
#define PLAY_2_9 479
#define PLAY_2_10 480
#define PLAY_2_11 481
#define PLAY_2_12 482
#define PLAY_2_13 483
#define PLAY_2_14 484
#define PLAY_2_15 485
#define PLAY_2_16 486
#define PLAY_2_17 487
#define PLAY_2_18 488
#define PLAY_2_19 489
#define PLAY_2_20 490
#define PLAY_2_21 491
#define PLAY_2_22 492
#define PLAY_2_23 493
#define PLAY_2_24 494
#define PLAY_2_25 495
#define PLAY_2_26 496
#define PLAY_2_27 497
#define PLAY_2_28 498
#define PLAY_3_1 499
#define PLAY_3_2 500
#define PLAY_3_3 501
#define PLAY_3_4 502
#define PLAY_3_5 503
#define PLAY_3_6 504
#define PLAY_3_7 505
#define PLAY_3_8 506
#define PLAY_3_9 507
#define PLAY_3_10 508
#define PLAY_3_11 509
#define PLAY_3_12 510
#define PLAY_3_13 511
#define PLAY_3_14 512
#define PLAY_3_15 513
#define PLAY_3_16 514
#define PLAY_3_17 515
#define PLAY_3_18 516
#define PLAY_3_19 517
#define PLAY_3_20 518
#define PLAY_3_21 519
#define PLAY_3_22 520
#define PLAY_3_23 521
#define PLAY_3_24 522
#define PLAY_3_25 523
#define PLAY_3_26 524
#define PLAY_3_27 525
#define PLAY_3_28 526
#define PLAY_4_1 527
#define PLAY_4_2 528
#define PLAY_4_3 529
#define PLAY_4_4 530
#define PLAY_4_5 531
#define PLAY_4_6 532
#define PLAY_4_7 533
#define PLAY_4_8 534
#define PLAY_4_9 535
#define PLAY_4_10 536
#define PLAY_4_11 537
#define PLAY_4_12 538
#define PLAY_4_13 539
#define PLAY_4_14 540
#define PLAY_4_15 541
#define PLAY_4_16 542
#define PLAY_4_17 543
#define PLAY_4_18 544
#define PLAY_4_19 545
#define PLAY_4_20 546
#define PLAY_4_21 547
#define PLAY_4_22 548
#define PLAY_4_23 549
#define PLAY_4_24 550
#define PLAY_4_25 551
#define PLAY_4_26 552
#define PLAY_4_27 553
#define PLAY_4_28 554
#define PLAY_5_1 555
#define PLAY_5_2 556
#define PLAY_5_3 557
#define PLAY_5_4 558
#define PLAY_5_5 559
#define PLAY_5_6 560
#define PLAY_5_7 561
#define PLAY_5_8 562
#define PLAY_5_9 563
#define PLAY_5_10 564
#define PLAY_5_11 565
#define PLAY_5_12 566
#define PLAY_5_13 567
#define PLAY_5_14 568
#define PLAY_5_15 569
#define PLAY_5_16 570
#define PLAY_5_17 571
#define PLAY_5_18 572
#define PLAY_5_19 573
#define PLAY_5_20 574
#define PLAY_5_21 575
#define PLAY_5_22 576
#define PLAY_5_23 577
#define PLAY_5_24 578
#define PLAY_5_25 579
#define PLAY_5_26 580
#define PLAY_5_27 581
#define PLAY_5_28 582


// Score
#define SCORE_0_1 583
#define SCORE_0_2 584
#define SCORE_0_3 585
#define SCORE_0_4 586
#define SCORE_0_5 587
#define SCORE_0_6 588
#define SCORE_0_7 589
#define SCORE_0_8 590
#define SCORE_0_9 591
#define SCORE_0_10 592
#define SCORE_0_11 593
#define SCORE_0_12 594
#define SCORE_0_13 595
#define SCORE_0_14 596
#define SCORE_0_15 597
#define SCORE_0_16 598
#define SCORE_0_17 599
#define SCORE_0_18 600
#define SCORE_0_19 601
#define SCORE_0_20 602
#define SCORE_0_21 603
#define SCORE_0_22 604
#define SCORE_0_23 605
#define SCORE_0_24 606
#define SCORE_0_25 607
#define SCORE_0_26 608
#define SCORE_0_27 609
#define SCORE_0_28 610
#define SCORE_1_1 611
#define SCORE_1_2 612
#define SCORE_1_3 613
#define SCORE_1_4 614
#define SCORE_1_5 615
#define SCORE_1_6 616
#define SCORE_1_7 617
#define SCORE_1_8 618
#define SCORE_1_9 619
#define SCORE_1_10 620
#define SCORE_1_11 621
#define SCORE_1_12 622
#define SCORE_1_13 623
#define SCORE_1_14 624
#define SCORE_1_15 625
#define SCORE_1_16 626
#define SCORE_1_17 627
#define SCORE_1_18 628
#define SCORE_1_19 629
#define SCORE_1_20 630
#define SCORE_1_21 631
#define SCORE_1_22 632
#define SCORE_1_23 633
#define SCORE_1_24 634
#define SCORE_1_25 635
#define SCORE_1_26 636
#define SCORE_1_27 637
#define SCORE_1_28 638
#define SCORE_2_1 639
#define SCORE_2_2 640
#define SCORE_2_3 641
#define SCORE_2_4 642
#define SCORE_2_5 643
#define SCORE_2_6 644
#define SCORE_2_7 645
#define SCORE_2_8 646
#define SCORE_2_9 647
#define SCORE_2_10 648
#define SCORE_2_11 649
#define SCORE_2_12 650
#define SCORE_2_13 651
#define SCORE_2_14 652
#define SCORE_2_15 653
#define SCORE_2_16 654
#define SCORE_2_17 655
#define SCORE_2_18 656
#define SCORE_2_19 657
#define SCORE_2_20 658
#define SCORE_2_21 659
#define SCORE_2_22 660
#define SCORE_2_23 661
#define SCORE_2_24 662
#define SCORE_2_25 663
#define SCORE_2_26 664
#define SCORE_2_27 665
#define SCORE_2_28 666
#define SCORE_3_1 667
#define SCORE_3_2 668
#define SCORE_3_3 669
#define SCORE_3_4 670
#define SCORE_3_5 671
#define SCORE_3_6 672
#define SCORE_3_7 673
#define SCORE_3_8 674
#define SCORE_3_9 675
#define SCORE_3_10 676
#define SCORE_3_11 677
#define SCORE_3_12 678
#define SCORE_3_13 679
#define SCORE_3_14 680
#define SCORE_3_15 681
#define SCORE_3_16 682
#define SCORE_3_17 683
#define SCORE_3_18 684
#define SCORE_3_19 685
#define SCORE_3_20 686
#define SCORE_3_21 687
#define SCORE_3_22 688
#define SCORE_3_23 689
#define SCORE_3_24 690
#define SCORE_3_25 691
#define SCORE_3_26 692
#define SCORE_3_27 693
#define SCORE_3_28 694
#define SCORE_4_1 695
#define SCORE_4_2 696
#define SCORE_4_3 697
#define SCORE_4_4 698
#define SCORE_4_5 699
#define SCORE_4_6 700
#define SCORE_4_7 701
#define SCORE_4_8 702
#define SCORE_4_9 703
#define SCORE_4_10 704
#define SCORE_4_11 705
#define SCORE_4_12 706
#define SCORE_4_13 707
#define SCORE_4_14 708
#define SCORE_4_15 709
#define SCORE_4_16 710
#define SCORE_4_17 711
#define SCORE_4_18 712
#define SCORE_4_19 713
#define SCORE_4_20 714
#define SCORE_4_21 715
#define SCORE_4_22 716
#define SCORE_4_23 717
#define SCORE_4_24 718
#define SCORE_4_25 719
#define SCORE_4_26 720
#define SCORE_4_27 721
#define SCORE_4_28 722

// Exit
#define EXIT_0_1 723
#define EXIT_0_2 724
#define EXIT_0_3 725
#define EXIT_0_4 726
#define EXIT_0_5 727
#define EXIT_0_6 728
#define EXIT_0_7 729
#define EXIT_0_8 730
#define EXIT_0_9 731
#define EXIT_0_10 732
#define EXIT_0_11 733
#define EXIT_0_12 734
#define EXIT_0_13 735
#define EXIT_0_14 736
#define EXIT_0_15 737
#define EXIT_0_16 738
#define EXIT_0_17 739
#define EXIT_0_18 740
#define EXIT_0_19 741
#define EXIT_0_20 742
#define EXIT_0_21 743
#define EXIT_0_22 744
#define EXIT_0_23 745
#define EXIT_0_24 746
#define EXIT_0_25 747
#define EXIT_0_26 748
#define EXIT_0_27 749
#define EXIT_0_28 750
#define EXIT_1_1 751
#define EXIT_1_2 752
#define EXIT_1_3 753
#define EXIT_1_4 754
#define EXIT_1_5 755
#define EXIT_1_6 756
#define EXIT_1_7 757
#define EXIT_1_8 758
#define EXIT_1_9 759
#define EXIT_1_10 760
#define EXIT_1_11 761
#define EXIT_1_12 762
#define EXIT_1_13 763
#define EXIT_1_14 764
#define EXIT_1_15 765
#define EXIT_1_16 766
#define EXIT_1_17 767
#define EXIT_1_18 768
#define EXIT_1_19 769
#define EXIT_1_20 770
#define EXIT_1_21 771
#define EXIT_1_22 772
#define EXIT_1_23 773
#define EXIT_1_24 774
#define EXIT_1_25 775
#define EXIT_1_26 776
#define EXIT_1_27 777
#define EXIT_1_28 778
#define EXIT_2_1 779
#define EXIT_2_2 780
#define EXIT_2_3 781
#define EXIT_2_4 782
#define EXIT_2_5 783
#define EXIT_2_6 784
#define EXIT_2_7 785
#define EXIT_2_8 786
#define EXIT_2_9 787
#define EXIT_2_10 788
#define EXIT_2_11 789
#define EXIT_2_12 790
#define EXIT_2_13 791
#define EXIT_2_14 792
#define EXIT_2_15 793
#define EXIT_2_16 794
#define EXIT_2_17 795
#define EXIT_2_18 796
#define EXIT_2_19 797
#define EXIT_2_20 798
#define EXIT_2_21 799
#define EXIT_2_22 800
#define EXIT_2_23 801
#define EXIT_2_24 802
#define EXIT_2_25 803
#define EXIT_2_26 804
#define EXIT_2_27 805
#define EXIT_2_28 806
#define EXIT_3_1 807
#define EXIT_3_2 808
#define EXIT_3_3 809
#define EXIT_3_4 810
#define EXIT_3_5 811
#define EXIT_3_6 812
#define EXIT_3_7 813
#define EXIT_3_8 814
#define EXIT_3_9 815
#define EXIT_3_10 816
#define EXIT_3_11 817
#define EXIT_3_12 818
#define EXIT_3_13 819
#define EXIT_3_14 820
#define EXIT_3_15 821
#define EXIT_3_16 822
#define EXIT_3_17 823
#define EXIT_3_18 824
#define EXIT_3_19 825
#define EXIT_3_20 826
#define EXIT_3_21 827
#define EXIT_3_22 828
#define EXIT_3_23 829
#define EXIT_3_24 830
#define EXIT_3_25 831
#define EXIT_3_26 832
#define EXIT_3_27 833
#define EXIT_3_28 834
#define EXIT_4_1 835
#define EXIT_4_2 836
#define EXIT_4_3 837
#define EXIT_4_4 838
#define EXIT_4_5 839
#define EXIT_4_6 840
#define EXIT_4_7 841
#define EXIT_4_8 842
#define EXIT_4_9 843
#define EXIT_4_10 844
#define EXIT_4_11 845
#define EXIT_4_12 846
#define EXIT_4_13 847
#define EXIT_4_14 848
#define EXIT_4_15 849
#define EXIT_4_16 850
#define EXIT_4_17 851
#define EXIT_4_18 852
#define EXIT_4_19 853
#define EXIT_4_20 854
#define EXIT_4_21 855
#define EXIT_4_22 856
#define EXIT_4_23 857
#define EXIT_4_24 858
#define EXIT_4_25 859
#define EXIT_4_26 860
#define EXIT_4_27 861
#define EXIT_4_28 862

*/