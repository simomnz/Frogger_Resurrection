#include "player.h"





void movePlayer(Player *player, int pipeFd, int gameToPlayerFd) {
    usleep(1000);
    // Coordinates message;
    while (1) {
        
        readData(gameToPlayerFd, &player->cords, sizeof(Coordinates));
        int input = getch();

        switch (input) {
            case 'w':
            case 'W':
            case KEY_UP:
                player->cords.y -= FROG_HEIGHT;
                break;
            case 's':
            case 'S':
            case KEY_DOWN:
                player->cords.y += FROG_HEIGHT;
                break;
            case 'a':
            case 'A':
            case KEY_LEFT:
                player->cords.x -= FROG_LENGTH;
                break;
            case 'd':
            case 'D':   
            case KEY_RIGHT:
                player->cords.x += FROG_LENGTH;
                break;
                
            case ' ':
                //creare una granata sia a destra che a sinistra
                createGrenade(player, pipeFd, RIGHT);
                createGrenade(player, pipeFd, LEFT);
                break;
            default: 
                
                continue;
        }
        flushinp();

        if(player->cords.y < 0) {
            player->cords.y = 0;
        } else if (player->cords.y > LINES - 1) {
            player->cords.y = LINES - 1;
        }

        //la funzione dovrebbe successivamente chiamare sendPlayerCords per inviare l'input al server   
        
        writeData(pipeFd, &player->cords, sizeof(Coordinates));
        // sendPlayerCords(sockfd, player);
        
        
        
        // mvprintw(0, 50, "Player legge x = %d && y = %d", player->cords.x, player->cords.y);
    }
}


//non va un cazzo (dio merda)
int isPlayerOnCroc(Game *game) {
    int totalCrocodiles = (LINES - 4) * MAX_CROCODILES;

    for (int i = 0; i < totalCrocodiles; i++) {
        Crocodile *croc = &game->crocodiles[i];
        
        // Se va verso destra
        int leftX = croc->cords.x;
        int rightX = croc->cords.x + croc->sprite.length - 1;
        /*
        if (croc->cords.direction == -1) {
            // Se va verso sinistra, invertiamo
            leftX = croc->cords.x - (croc->sprite.length - 1);
            rightX = croc->cords.x;
        }
        */


        if (game->player.cords.y == croc->cords.y && 
            game->player.cords.x >= leftX && 
            game->player.cords.x <= rightX) {
            
            int relativeX = game->player.cords.x - leftX;
            
            game->player.isOnCrocodile = 1;
            // int displacement = rightX - game->player.cords.x; 
            // game->player.cords.x = leftX + displacement;
            game->player.cords.direction = croc->cords.direction;
            game->player.cords.speed = croc->cords.speed;
            //return game->player.cords.x + (croc->cords.direction * croc->cords.speed);
            /* returning the id of the crocodile we are on */
            return croc->cords.source;
        }
    }
    game->player.cords.direction = 0;
    game->player.cords.speed = 0;
    game->player.isOnCrocodile = 0;
    return 0;
}


int isPlayerOnGrass(Game *game){
    if (game->player.cords.y == LINES - 1 || game->player.cords.y == LINES - 2) {
        return 1;
    }
    return 0;

}


int isPlayerOnDen(Game *game) {
    
    for (int i = 0; i < 5; i++) {

        //da cambiare e implementare l'array closedDen
        if (game->player.cords.x == COLS)  {
            return 1;
        }
    }
    return 0;
}


//funzione per il movimento delle granate (da rivedere)


//TODO

void moveGrenade(Grenade *grenade, int pipeFd) {

   do
   {
        grenade->cords.x += grenade->speed * grenade->cords.direction;
        grenade->lifeSpan--;

        if (grenade->lifeSpan == 0) {
            grenade->cords.x = -1;
            grenade->cords.y = -1;
            exit(0);
        }
        mvwprintw(stdscr, grenade->cords.y, grenade->cords.x, "-");

        writeData(pipeFd, &grenade->cords, sizeof(Coordinates));

        
        usleep(200000);

    }while (grenade->lifeSpan > 0);
   exit(0);
}

void createGrenade(Player *player, int pipeFd, int direction) {
    
    Grenade grenade;
    grenade.cords.x = player->cords.x;
    grenade.cords.y = player->cords.y;
    grenade.sprite.length = 1;   //da cambiare
    grenade.speed = 1;   

    grenade.lifeSpan = 5;   //da cambiare

    grenade.cords.direction = direction;

    //grenade.cords.source = 0;

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) { 
        srand(time(NULL) + getpid()); 
        moveGrenade(&grenade, pipeFd);
        exit(0); 
    }

}


