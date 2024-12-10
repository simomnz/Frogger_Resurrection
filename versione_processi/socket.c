
#include "socket.h"




int createSocket() {

    int sockfd;  
    struct sockaddr_un addr;  
    
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);  /* Creazione del socket */

    if (sockfd == -1) {                        /* Nel caso la creazione del socket fallisca */
        perror("Errore nella create del socket");
        exit(EXIT_FAILURE);
    }

    addr.sun_family = AF_UNIX;  /* Indirizzo locale */ 



    ///da controllare e capire
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) -1 ); /* Copio il path del socket */
    addr.sun_path[sizeof(addr.sun_path) - 1] = '\0'; /* Termino la stringa */

    unlink(SOCKET_PATH); /* Rimuove il file socket se esiste già (evita errori non previsti nel controllo del binding) */

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {  /* Nel caso il binding del socket fallisca */
        perror("Errore nel bind del socket");
        close(sockfd);   /* Chiudo il socket */
        exit(EXIT_FAILURE);
    }
    return sockfd;
}




char recvPlayerInput() { 

    //da implementare

}
 

//void sendPlayerInput(char input) {} 

    //da capire


