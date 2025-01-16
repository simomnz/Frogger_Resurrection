#include "utils.h"


/* Function to read data from a pipe */
void readData(int pipefd, void *data, size_t dim) {
    int check = read(pipefd, data, dim);
    if (check < 0) {
        perror("Read from pipe went wrong");
        exit(-1);
    }
}

/* Function to write data to a pipe */
void writeData(int pipefd, void *data, size_t dim) {
    int check = write(pipefd, data, dim);
    if (check < 0) {
        perror("Write in pipe went wrong");
        exit(-1);
    }
}
