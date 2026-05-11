#ifndef ABG_RANDOM_H
#define ABG_RANDOM_H
#include <stdlib.h>
#include <stdbool.h>

void ABG_RandSeed(unsigned int seed); // sets random seed to fixed value 
void ABG_RandSeedTime(void); // sets random seed using system time

int ABG_RandInt(int min, int max); // returns random int in range
float ABG_RandFloat(void); // returns random float from 0 - 1
float ABG_RandRange(float min, float max); // returns random float in range

bool ABG_RandChance(float p); // p is probability
int ABG_RandSign(void); // returns a random +/-

#endif /* ABG_RANDOM_H */