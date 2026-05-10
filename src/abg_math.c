#include "abg_math.h"

float ABG_ClampFloat(float v, float min, float max) {
    if (max < min) {
        float temp = min;
        min = max;
        max = temp;
    }

    if (v < min) {
        return min;
    }

    if (v > max) {
        return max;
    }

    return v;
}

int ABG_ClampInt(int v, int min, int max) {
    if (max < min) {
        int temp = min;
        min = max;
        max = temp;
    }

    if (v < min) {
        return min;
    }

    if (v > max) {
        return max;
    }

    return v;
}

float ABG_LerpFloat(float v0, float v1, float t) {
    return v0 + t * (v1 - v0);
}

float ABG_LerpFloatClamped(float v0, float v1, float t) {
    t = ABG_ClampFloat(t, 0.0f, 1.0f);
    return v0 + t * (v1 - v0);
}

int ABG_LerpInt(int v0, int v1, float t) {
    return (int)(v0 + t * (float)(v1 - v0));
}

int ABG_LerpIntClamped(int v0, int v1, float t) {
    t = ABG_ClampFloat(t, 0.0f, 1.0f);
    return (int)(v0 + t * (float)(v1 - v0));
}

float ABG_InvLerpFloat(float v0, float v1, float v) {
    if (ABG_FloatEquals(v0, v1, ABG_EPSILON)) {
        return 0.0f;
    }

    return (v - v0) / (v1 - v0);
}

float ABG_MinFloat(float a, float b) {
    return (a < b) ? a : b;
}

int ABG_MinInt(int a, int b) {
    return (a < b) ? a : b;
}

float ABG_MaxFloat(float a, float b) {
    return (a > b) ? a : b;
}

int ABG_MaxInt(int a, int b) {
    return (a > b) ? a : b;
}

float ABG_AbsFloat(float v) {
    return (v < 0) ? -v : v;
}

float ABG_RemapFloat(float v, float inMin, float inMax, float outMin, float outMax) {
    float t = ABG_InvLerpFloat(inMin, inMax, v);
    return ABG_LerpFloat(outMin, outMax, t);
}

float ABG_RemapFloatClamped(float v, float inMin, float inMax, float outMin, float outMax) {
    float t = ABG_InvLerpFloat(inMin, inMax, v);
    t = ABG_ClampFloat(t, 0.0f, 1.0f);

    return ABG_LerpFloat(outMin, outMax, t);
}

bool ABG_FloatEquals(float a, float b, float epsilon) {
    return ABG_AbsFloat(a - b) <= epsilon;
}

float ABG_SafeDivideFloat(float numerator, float denominator, float fallback) {
    if (ABG_AbsFloat(denominator) <= ABG_EPSILON) {
        return fallback;
    }

    return numerator / denominator;
}