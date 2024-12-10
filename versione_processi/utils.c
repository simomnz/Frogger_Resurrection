#include "utils.h"
#include <stdlib.h>

void readData(int pipefd, void *data, size_t dim) {
    int check = read(pipefd, data, dim);
    if (check < 0) {
        perror("Read from pipe went wrong");
        return -1;
    }
}
// TODO sostituire tutte le read e write con queste
void writeData(int pipefd, void *data, size_t dim) {
    int check = write(pipefd, data, dim);
    if (check < 0) {
        perror("Write in pipe went wrong");
        return -1;
    }
}
