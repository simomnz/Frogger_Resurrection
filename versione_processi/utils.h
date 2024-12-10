#pragma once
#include <stdlib.h>

void readData(int pipefd, void *data, size_t dim);

void writeData(int pipefd, void *data, size_t dim);