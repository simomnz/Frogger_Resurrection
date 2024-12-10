#pragma once
#include <stdlib.h>
#include <sys/socket.h>  
#include <sys/un.h>       /* per i socket unix */


#define SOCKET_PATH "/tmp/socket_game"



int createSocket();

