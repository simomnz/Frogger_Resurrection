
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
    strncpy(addr.sun_path, SOCKET_PATH, 2);  /* Nome del socket (utilizziamo "strncpy" e non "strcpy per problemi di vulnerabilità" ) */ 


    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {  /* Nel caso il binding del socket fallisca */
        perror("Errore nel bind del socket");
        close(sockfd);   /* Chiudo il socket */
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

