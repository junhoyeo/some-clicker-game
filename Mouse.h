#pragma once

#ifndef _MOUSE_
#define _MOUSE_

#include <stdio.h>
#include <Windows.h>

typedef struct _Mouse {
    int x, y;
    void (*updatePosition)(struct _Mouse*);
} Mouse;

inline void _updatePosition(Mouse* self) {
    POINT cursor;
    GetCursorPos(&cursor);
    ScreenToClient(WINDOW_HANDLE, &cursor);
    self -> x = cursor.x;
    self -> y = cursor.y;
}

const Mouse MOUSE = {
    0, 0,
    _updatePosition,
};

#endif
