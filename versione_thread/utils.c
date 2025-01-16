#include "utils.h"



// TODO, variabile contatore produttori attivi (quando i coccodrilli o la rana sparano i produttori aumentano), implementare funzione di produce e consume data,last but not least implementare gpt2 per l'IA dei coccodrilli
void writeData(const void *data, size_t dim) {
    const char *src = (const char *)data;

    for (size_t i = 0; i < dim; i++) {
        // Wait until there is at least one empty slot in the buffer
        sem_wait(&semEmpty);

        // Lock the buffer to safely update shared state
        pthread_mutex_lock(&bufferMutex);

        // Place one byte into the buffer
        buffer[tail] = src[i];
        tail = (tail + 1) % BUFFER_SIZE; // wrap around if needed

        // Unlock
        pthread_mutex_unlock(&bufferMutex);

        // Signal that there is one more full slot
        sem_post(&semFull);
    }
}

// Consumer-like "readData" function — reads `dim` bytes into `data`.
void readData(void *data, size_t dim) {
    char *dst = (char *)data;

    for (size_t i = 0; i < dim; i++) {
        // Wait until there is at least one full slot available
        sem_wait(&semFull);

        // Lock the buffer to safely update shared state
        pthread_mutex_lock(&bufferMutex);

        // Read one byte from the buffer
        dst[i] = buffer[head];
        head = (head + 1) % BUFFER_SIZE; // wrap around if needed

        // Unlock
        pthread_mutex_unlock(&bufferMutex);

        // Signal that there is one more empty slot
        sem_post(&semEmpty);
    }
}
