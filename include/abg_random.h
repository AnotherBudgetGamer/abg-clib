#ifndef ABG_RANDOM_H
#define ABG_RANDOM_H

int ABG_RandomInt(int min, int max);
float ABG_RandomFloat(float min, float max);

// p = probability
bool ABG_RandomChance(float p);

// returns a random +/-
int ABG_RandomSign(void);

#endif /* ABG_RANDOM_H */
