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
    if (game->player.cords.y > GAME_LINES - 5 || game->player.cords.y < 13) {
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
Grenade createGrenade(Player *player, int pipeFd, int direction) {
    Grenade grenade;
    grenade.cords.x = player->cords.x + (GRENADE_LENGTH * direction);
    grenade.cords.y = player->cords.y - FROG_HEIGHT / 2;  /* Spawn in the Middle of the River Flow */
    grenade.sprite.length = GRENADE_LENGTH;    
    grenade.sprite.height = GRENADE_HEIGHT;
    grenade.speed = 5;
    grenade.cords.type = 'g';    
    grenade.lifeSpan = FROG_LENGTH * 2; /* Lifespan of Grenade */
    grenade.cords.direction = direction;

    /* Setting Source based on the direction */
    if (direction == LEFT) {
        grenade.cords.source = GRENAD_LEFT_SOURCE; // 201
    } else if (direction == RIGHT) {
        grenade.cords.source = GRENAD_RIGHT_SOURCE; // 203
    } 

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) { 
        srand(time(NULL) + getpid()); 
        moveGrenade(&grenade, pipeFd);
        exit(0); 
    }
    grenade.PID = pid;
    return grenade;
}

/* Function to move the grenade */
void moveGrenade(Grenade *grenade, int pipeFd) {
    do {
        grenade->cords.x += grenade->speed * grenade->cords.direction;
        grenade->lifeSpan--;

        if (grenade->lifeSpan == 0 || grenade->cords.x > COLS || grenade->cords.x < 0) {
            grenade->cords.x = -15;
            grenade->cords.y = -15;
            break;
        }

        writeData(pipeFd, &grenade->cords, sizeof(Coordinates));
        usleep(200000);
    } while (grenade->lifeSpan > 0);

    exit(0);
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
