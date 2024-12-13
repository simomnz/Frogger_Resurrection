
#include "socket.h"





int createSocket() {

    int sockfd;  
    struct sockaddr_un addr;  
    
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);  /* Creazione del socket */

    if (sockfd < 0) {                        /* Nel caso la creazione del socket fallisca */
        perror("Errore nella create del socket");
        exit(EXIT_FAILURE);
    }

    addr.sun_family = AF_UNIX;  /* Indirizzo locale */ ///
    //manunz uno di quelli
    ///da controllare e capire
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) -1 ); /* Copio il path del socket */
    addr.sun_path[sizeof(addr.sun_path) - 1] = '\0'; /* Termino la stringa */

    unlink(SOCKET_PATH); /* Rimuove il file socket se esiste già (evita errori non previsti nel controllo del binding) */

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {  /* Nel caso il binding del socket fallisca */
        perror("Errore nel bind del socket");
        close(sockfd);   /* Chiudo il socket */
        exit(EXIT_FAILURE);
    }
    return sockfd;
}




void recvPlayerCords(Player *player, int sockfd) { 

    Coordinates cords;
    ssize_t bytes = recv(sockfd, &cords, sizeof(Coordinates), 0);  /* Ricezione delle cordinate dal server */

    if (bytes < 0) {  /* Nel caso la ricezione delle cordinate fallisca */
        perror("Errore nella ricezione delle cordinate dal server");
        close(sockfd);  /* Chiudo il socket */
        exit(EXIT_FAILURE);
    }

    //cambiare nome alle variabili per evitare confusione?
    player->cords.x = cords.x;
    player->cords.y = cords.y;


}
 


void sendPlayerCords(Player *player, int sockfd) 
{
    Coordinates cords;
    cords.x = player->cords.x;
    cords.y = player->cords.y;

    ssize_t bytes = send(sockfd, &cords, sizeof(Coordinates), 0);  /* Invio delle cordinate al server */

    if (bytes < 0) {  /* Nel caso l'invio delle cordinate fallisca */
        perror("Errore nell'invio delle cordinate al server");
        close(sockfd);  /* Chiudo il socket */
        exit(EXIT_FAILURE);
    }
} 



 


