#pragma once
#include <Windows.h>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 480

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
