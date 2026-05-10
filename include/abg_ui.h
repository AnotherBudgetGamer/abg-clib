#ifndef ABG_UI_H
#define ABG_UI_H

#include <stdbool.h>
#include "raylib.h"

typedef struct {
    float x;
    float y;
    float w;
    float h;
} ABG_Rect;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} ABG_Color;

typedef struct {
    ABG_Rect rect;
    float border;
    float padding;
    const char *title;
} ABG_Window;

typedef struct {
    ABG_Rect rect;
    float padding;
} ABG_Panel;

typedef struct {
    ABG_Rect rect;
    const char *text;
} ABG_Button;

bool ABG_RectContainsPoint(ABG_Rect rect, float x, float y);
ABG_Rect ABG_RectInset(ABG_Rect rect, float amount);
ABG_Rect ABG_RectMove(ABG_Rect rect, float dx, float dy);
ABG_Rect ABG_RectFromSize(float x, float y, float w, float h);

Rectangle ABG_ToRaylibRect(ABG_Rect rect);
void ABG_DrawRect(ABG_Rect rect, Color color);
void ABG_DrawRectLines(ABG_Rect rect, Color color);

#endif /* ABG_UI_H */