#include "utils.h"

#define BUFFER_SIZE 35


Coordinates buffer[BUFFER_SIZE];
pthread_mutex_t writeBufferMutex;
pthread_mutex_t readBufferMutex;

//questi partono rispettivamente da: BUFFER_SIZE, 0
sem_t semEmpty, semFull;


//senza extern forse
short tail = 0;
short head = 0;


void initSemaphore() {
    if(sem_init(&semEmpty, 0, BUFFER_SIZE) != 0) {
        perror("Couldn't init semEmpty (sium)");
        exit(-1);
    }

    if(sem_init(&semFull, 0, 0) != 0) {
        perror("Couldn't init semfull (sium)");
        exit(-1);
    };
}


//TODO, variabile contatore produttori attivi (quando i coccodrilli o la rana sparano i produttori aumentano), implementare funzione di produce e consume data
void writeData(Coordinates data) {

    // Wait until there is at least one empty slot in the buffer
    while (sem_wait(&semEmpty) != 0) {
        // waiting for the buffer
    }
    

    // Entering critics section
    pthread_mutex_lock(&writeBufferMutex);
    
    // Place one byte into the buffer
    buffer[tail] = data;
    tail = (tail + 1) % BUFFER_SIZE; // wrap around if needed

    // Unlock
    pthread_mutex_unlock(&writeBufferMutex);

    // this slot is full (daaaaaaaaaaaaaaaaamn)
    while (sem_post(&semFull)) {
        // waiting
    }
    
    
}

Coordinates readData() {
    
    Coordinates msg;

    
    // Wait until there is at least one full slot available
    while (sem_wait(&semFull) != 0) {
        // waiting for the buffer
    }
    

    // Lock the buffer to safely update shared state
    pthread_mutex_lock(&readBufferMutex);
    // Read one byte from the buffer
    msg = buffer[head];
    head = (head + 1) % BUFFER_SIZE; // wrap around if needed

    // Unlock
    pthread_mutex_unlock(&readBufferMutex);

    // Signal that there is one more empty slot
    while (sem_post(&semEmpty) != 0) {
        // waiting
    }

    return msg;
}
