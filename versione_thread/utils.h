#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#include "struct.h"

Coordinates readData();

void writeData(Coordinates data);

void initSemaphore();
