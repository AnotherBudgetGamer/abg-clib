#include "abg_ui.h"

bool ABG_RectContainsPoint(ABG_Rect rect, float x, float y) {
    return (
        x >= rect.x &&
        x <= rect.x + rect.w &&
        y >= rect.y &&
        y <= rect.y + rect.h
    );
}

ABG_Rect ABG_RectInset(ABG_Rect rect, float amount) {
    rect.x += amount;
    rect.y += amount;
    rect.w -= amount * 2.0f;
    rect.h -= amount * 2.0f;

    if (rect.w < 0.0f) rect.w = 0.0f;
    if (rect.h < 0.0f) rect.h = 0.0f;

    return rect;
}

ABG_Rect ABG_RectMove(ABG_Rect rect, float dx, float dy) {
    rect.x += dx;
    rect.y += dy;

    return rect;
}

ABG_Rect ABG_RectFromSize(float x, float y, float w, float h) {
    ABG_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    return rect;
}

Rectangle ABG_ToRaylibRect(ABG_Rect rect) {
    return (Rectangle){
        rect.x,
        rect.y,
        rect.w,
        rect.h
    };
}

void ABG_DrawRect(ABG_Rect rect, Color color) {
    DrawRectangleRec(ABG_ToRaylibRect(rect), color);
}

void ABG_DrawRectLines(ABG_Rect rect, Color color) {
    DrawRectangleLinesEx(ABG_ToRaylibRect(rect), 2.0f, color);
}