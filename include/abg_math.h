#ifndef ABG_MATH_H
#define ABG_MATH_H
#include <stdbool.h>

#define ABG_EPSILON 0.00001f

float ABG_ClampFloat(float v, float min, float max);
int ABG_ClampInt(int v, int min, int max);

float ABG_LerpFloat(float v0, float v1, float t);
float ABG_LerpFloatClamped(float v0, float v1, float t);

int ABG_LerpInt(int v0, int v1, float t);
int ABG_LerpIntClamped(int v0, int v1, float t);

float ABG_InvLerpFloat(float v0, float v1, float v);

float ABG_MinFloat(float a, float b);
int ABG_MinInt(int a, int b);

float ABG_MaxFloat(float a, float b);
int ABG_MaxInt(int a, int b);

float ABG_AbsFloat(float v);

float ABG_RemapFloat(float v, float inMin, float inMax, float outMin, float outMax);
float ABG_RemapFloatClamped(float v, float inMin, float inMax, float outMin, float outMax);

bool ABG_FloatEquals(float a, float b, float epsilon);

float ABG_SafeDivideFloat(float numerator, float denoninator, float fallback);


#endif /* ABG_MATH_H */
