#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

inline void hideConsoleCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 100;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(CONSOLE_OUTPUT, &cursorInfo);
}

inline void disableConsoleResize() {
	LONG windowLong = GetWindowLong(WINDOW_HANDLE, GWL_STYLE);
	SetWindowLong(WINDOW_HANDLE, GWL_STYLE, windowLong & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

inline void disableConsoleSelection() {
	DWORD prevConsoleMode;
	GetConsoleMode(CONSOLE_INPUT, &prevConsoleMode);
	SetConsoleMode(
		CONSOLE_INPUT,
		ENABLE_EXTENDED_FLAGS | (prevConsoleMode & ~ENABLE_QUICK_EDIT_MODE)
	);
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
	hideConsoleCursor();
	disableConsoleResize();
	disableConsoleSelection();
	resizeConsole(SCREEN_HEIGHT, SCREEN_WIDTH);
	updateColor(0, 15);
	system("cls");
}
