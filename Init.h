#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define SCREEN_HEIGHT 50
#define SCREEN_WIDTH 60

HANDLE CONSOLE_INPUT, CONSOLE_OUTPUT;
HWND WINDOW_HANDLE;

inline void updateHandles() {
	CONSOLE_INPUT = GetStdHandle(STD_INPUT_HANDLE);
	CONSOLE_OUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	WINDOW_HANDLE = GetConsoleWindow();
}

inline void resizeConsole(int height, int width) {
	char command[100];
	sprintf_s(command, 100, "mode con cols=%d lines=%d", width, height);
	system(command);
}

inline void updateColor(int fontColor, int bgColor) {
	int color = (bgColor & 0xF) << 4 | fontColor & 0xF;
	SetConsoleTextAttribute(CONSOLE_OUTPUT, color);
}

inline void initWindow() {
	updateHandles();
	resizeConsole(SCREEN_HEIGHT, SCREEN_WIDTH);
	updateColor(0, 15);
	system("cls");
}
