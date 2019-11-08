#pragma once

#include <stdio.h>
#include <Windows.h>

COLORREF hexToColor(int hex) {
	int red = hex / 0x10000;
	int green = (hex / 0x100) % 0x100;
	int blue = hex % 0x100;
	return RGB(red, green, blue);
}

void setPixel(int x, int y, COLORREF color) {
	HDC context = GetDC(WINDOW_HANDLE);
	SetPixel(context, x, y, color);
	ReleaseDC(WINDOW_HANDLE, context);
}
