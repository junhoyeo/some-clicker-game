#pragma once

#include <stdio.h>
#include <math.h>
#include <Windows.h>

COLORREF hexToColor(int hex) {
	int red = hex / 0x10000;
	int green = (hex / 0x100) % 0x100;
	int blue = hex % 0x100;
	return RGB(red, green, blue);
}

void setPixel(int x, int y, COLORREF color) {
	HDC context = GetDC(WINDOW_HANDLE);
	SetPixel(context, y, x, color);
	ReleaseDC(WINDOW_HANDLE, context);
}

void setPoint(int gridX, int gridY, COLORREF color) {
	int rowStart = gridX * POINT_WIDTH;
	int colStart = gridY * POINT_WIDTH;
	for (int row = rowStart; row < rowStart + POINT_WIDTH; row++) {
		for (int col = colStart; col < colStart + POINT_WIDTH; col++) {
			setPixel(row, col, color);
			// printf("(%d, %d) ", row, col);
		}
	}
}
