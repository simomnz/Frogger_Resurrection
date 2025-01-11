#pragma once
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include "utils.h"

void readData(int pipefd, void *data, size_t dim);

void writeData(int pipefd, void *data, size_t dim);
