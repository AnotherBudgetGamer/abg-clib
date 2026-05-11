#include "abg_random.h"

#include <time.h>

void ABG_RandSeed(unsigned int seed) {
    srand(seed);
}

void ABG_RandSeedTime(void) {
    srand((unsigned int)time(NULL));
}

int ABG_RandInt(int min, int max) {
    if (max < min) {
        int temp = min;
        min = max;
        max = temp;
    }

    int r = max - min + 1;
    return min + rand() % r;
}

float ABG_RandFloat(void) {
    return (float)rand() / (float)RAND_MAX;
}

float ABG_RandRange(float min, float max) {
    if (max < min) {
        float temp = min;
        min = max;
        max = temp;
    }

    return min + ABG_RandFloat() * (max - min);
}

bool ABG_RandChance(float p) {
    if (p <= 0.0f) {
        return false;
    }

    if (p >= 1.0f) {
        return true;
    }

    return ABG_RandFloat() < p;
}

int ABG_RandSign(void) {
    return ABG_RandInt(0, 1) == 0 ? -1 : 1;
}