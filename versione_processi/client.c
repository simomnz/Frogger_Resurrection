#include "socket.h"
// #include "player.h"
// #include "sprite.h"

#define GAME_LINES 69
#define RIGHT 1
#define LEFT -1

#define FROG_HEIGHT 4
#define FROG_LENGTH 7


#define DEN_LENGTH 7
#define DEN_HEIGHT 4

#define GRENADE_LENGTH 3
#define GRENADE_HEIGHT 2

#define SHIELD_LENGHT 13
#define SHIELD_HEIGHT 6

#define GRENAD_LEFT_SOURCE 201
#define GRENAD_RIGHT_SOURCE 203


void movePlayer(Player *player, int sockfd) {
    usleep(1000);
    // Coordinates message;
    int counterGrenade = 500;
    initscr();   
    nodelay(stdscr, TRUE);   
    noecho();       
    cbreak();
    mousemask(ALL_MOUSE_EVENTS, NULL);
    keypad(stdscr, TRUE);  
    //player->cords.type = 'f';
    while (1) {
        counterGrenade++;
        //readData(gameToPlayerFd, &player->cords, sizeof(Coordinates));
        recvPlayerCords(player, sockfd);
        int input = getch();

        // TODO add cooldown to flag
        player->cords.flag = 0;
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
                if(counterGrenade >= 500) {
                    player->cords.flag = 1;
                    counterGrenade = 0;
                }
                break;
            default: 
                
                //continue;
        }
        flushinp();
        
        if(player->cords.y < 0 + FROG_HEIGHT) {
            player->cords.y = 0 + FROG_HEIGHT;
        } else if (player->cords.y > GAME_LINES - 1) {
            player->cords.y = GAME_LINES - 1;
        }

        //la funzione dovrebbe successivamente chiamare sendPlayerCords per inviare l'input al server   
        
        //writeData(pipeFd, &player->cords, sizeof(Coordinates));
        sendPlayerCords(player, sockfd);
        
    }
}

int main() {
    // gcc client.c socket.o -lncurses -o client
    int sockfd = connectToServer();
    Player player;
    movePlayer(&player, sockfd);
    close(sockfd);
    endwin();
    return 0;
}
