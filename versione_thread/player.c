#include "player.h"

/*
▗▄▄▖ ▗▖    ▗▄▖▗▖  ▗▖▗▄▄▄▖▗▄▄▖ 
▐▌ ▐▌▐▌   ▐▌ ▐▌▝▚▞▘ ▐▌   ▐▌ ▐▌
▐▛▀▘ ▐▌   ▐▛▀▜▌ ▐▌  ▐▛▀▀▘▐▛▀▚▖
▐▌   ▐▙▄▄▖▐▌ ▐▌ ▐▌  ▐▙▄▄▖▐▌ ▐▌                     

*/

/* Function to check if the player is on a crocodile */
int isPlayerOnCroc(Game *game) {
    for (int i = 0; i < game->numCroc; i++) {
        Crocodile *croc = &game->crocodiles[i];
        
        int leftX = croc->cords.x;
        int rightX = croc->cords.x + croc->sprite.length - 1;

        if (game->player.cords.y == croc->cords.y && 
            game->player.cords.x >= leftX && 
            game->player.cords.x <= rightX) {
            
            int relativeX = game->player.cords.x - leftX;
            
            game->player.isOnCrocodile = 1;
           
            game->player.cords.direction = croc->cords.direction;
            game->player.cords.speed = croc->cords.speed;
            
            /* returning the id of the crocodile we are on */
            return croc->cords.source;
        }
    }
    game->player.cords.direction = 0;
    game->player.cords.speed = 0;
    game->player.isOnCrocodile = 0;
    return 0;
}

/* Function to check if the player is on grass */
int isPlayerOnGrass(Game *game){
    if (game->player.cords.y > GAME_LINES - 5 || (game->player.cords.y < 13 && game->player.cords.y > 8)) {
        return 1;
    }
    return 0;
}

/* Function to check if the player is on a den */
int isPlayerOnDen(Game *game) { 
    int distance = (COLS - (DEN_LENGTH * 5)) / 6; // distance between dens
    int denX;
    for (int i = 0; i < 5; i++) {
        denX = (DEN_LENGTH + distance) * (i +1);   // calculations are correct, trust me

        // not tested, if errors occur it's the y==4;
        if (game->player.cords.y == 8 && game->player.cords.x >= denX - DEN_LENGTH -3 && game->player.cords.x <= denX + DEN_LENGTH && game->closedDen[i] == 0) {
            game->closedDen[i] = 1;
            return i;  // returns the id of the den
        } else if(game->player.cords.y == 8 && game->player.cords.x >= denX - DEN_LENGTH -3 && game->player.cords.x <= denX + DEN_LENGTH +1 && game->closedDen[i] == 1) {
            return 10;
        }
    }
    return -1;
}

/*
 ▗▄▄▖▗▄▄▖ ▗▄▄▄▖▗▖  ▗▖ ▗▄▖ ▗▄▄▄ ▗▄▄▄▖
▐▌   ▐▌ ▐▌▐▌   ▐▛▚▖▐▌▐▌ ▐▌▐▌  █▐▌   
▐▌▝▜▌▐▛▀▚▖▐▛▀▀▘▐▌ ▝▜▌▐▛▀▜▌▐▌  █▐▛▀▀▘
▝▚▄▞▘▐▌ ▐▌▐▙▄▄▖▐▌  ▐▌▐▌ ▐▌▐▙▄▄▀▐▙▄▄▖
                                    
*/

/* Function to create a grenade */
Grenade createGrenade(Player *player, int direction) {
    Grenade* grenade = malloc(sizeof(Grenade));
    *grenade = (Grenade){
        .cords.x = player->cords.x + (GRENADE_LENGTH * direction),
        .cords.y = player->cords.y - FROG_HEIGHT / 2,
        .sprite.length = GRENADE_LENGTH,
        .sprite.height = GRENADE_HEIGHT,
        .speed = 5,
        .cords.type = 'g',
        .lifeSpan = FROG_LENGTH * 2,
        .cords.direction = direction,
        .cords.source = (direction == LEFT) ? GRENAD_LEFT_SOURCE : GRENAD_RIGHT_SOURCE,
    };
    pthread_create(&grenade->thread, NULL, (void *)moveGrenade, (void *)grenade);
    return *grenade;
}

/* Function to move the grenade */
void *moveGrenade(Grenade *grenade) {
    do {
        grenade->cords.x += grenade->speed * grenade->cords.direction;
        grenade->lifeSpan--;

        if (grenade->lifeSpan == 0 || grenade->cords.x > (COLS + 4) || grenade->cords.x < -4) {
            grenade->cords.x = -15;
            grenade->cords.y = -15;
            grenade->lifeSpan = 0;
        }

        writeData(grenade->cords);
        usleep(200000);
    } while (grenade->lifeSpan > 0);

    free(grenade); // Free grenade memory after thread completes
    pthread_exit(0);
}

/* Function to check if a projectile hits the player */
int doesProjectileHitPlayer(Game *game) {
    for (int i = 0; i < NUM_PROJECTILES; i++) {
        Projectile projectile = game->projectiles[i];
        if (projectile.cords.y <=  game->player.cords.y && projectile.cords.y >=  ((game->player.cords.y - FROG_HEIGHT) + 1) && projectile.cords.x  >= game->player.cords.x && projectile.cords.x <= game->player.cords.x + FROG_LENGTH) {
            return 1;
        }
    }
    return 0;
}

/* Function to check if a projectile hits a grenade */
int doesProjectileHitGrenade(Game *game, Grenade grenade) {
    for (int i = 0; i < NUM_PROJECTILES; i++) {
        Projectile projectile = game->projectiles[i];
        if (projectile.cords.y <=  grenade.cords.y && projectile.cords.y >=  ((grenade.cords.y - FROG_HEIGHT) + 2) && projectile.cords.x  >= grenade.cords.x && projectile.cords.x <= grenade.cords.x + FROG_LENGTH) {
            return i;
        }
    }
    return -1;
}
