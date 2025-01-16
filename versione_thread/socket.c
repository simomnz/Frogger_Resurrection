#include "socket.h"

/*
 ▗▄▄▖ ▗▄▖  ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▄▄▄▖
▐▌   ▐▌ ▐▌▐▌   ▐▌▗▞▘▐▌     █  
 ▝▀▚▖▐▌ ▐▌▐▌   ▐▛▚▖ ▐▛▀▀▘  █  
▗▄▄▞▘▝▚▄▞▘▝▚▄▄▖▐▌ ▐▌▐▙▄▄▖  █  
 
*/


// int createSocket() {

//     int sockfd;  
//     struct sockaddr_un addr;  
    
//     sockfd = socket(AF_UNIX, SOCK_STREAM, 0);  /* Creazione del socket */

//     if (sockfd < 0) {                        /* Nel caso la creazione del socket fallisca */
//         perror("Errore nella create del socket");
//         exit(EXIT_FAILURE);
//     }

//     addr.sun_family = AF_UNIX;  /* Indirizzo locale */ ///
//     //manunz uno di quelli
//     ///da controllare e capire
//     strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) -1 ); /* Copio il path del socket */
//     addr.sun_path[sizeof(addr.sun_path) - 1] = '\0'; /* Termino la stringa */

//     unlink(SOCKET_PATH); /* Rimuove il file socket se esiste già (evita errori non previsti nel controllo del binding) */

//     if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {  /* Nel caso il binding del socket fallisca */
//         perror("Errore nel bind del socket");
//         close(sockfd);   /* Chiudo il socket */
//         exit(EXIT_FAILURE);
//     }
//     return sockfd;
// }

int startServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt error");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind error");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen error");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept error");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    return new_socket;
}

int connectToServer() {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
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
    player->cords = cords;
    
}
 


void sendPlayerCords(Player *player, int sockfd) {
    Coordinates cords;
    cords = player->cords;
    

    ssize_t bytes = send(sockfd, &cords, sizeof(Coordinates), 0);  /* Invio delle cordinate al server */

    if (bytes < 0) {  /* Nel caso l'invio delle cordinate fallisca */
        perror("Errore nell'invio delle cordinate al server");
        close(sockfd);  /* Chiudo il socket */
        exit(EXIT_FAILURE);
    }
} 



 


