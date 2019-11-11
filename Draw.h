#pragma once

#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define GetRValue(rgb) ((BYTE)(rgb))
#define GetGValue(rgb) ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb) ((BYTE)((rgb) >> 16))

COLORREF hexToColor(int hex) {
	int red = hex / 0x10000;
	int green = (hex / 0x100) % 0x100;
	int blue = hex % 0x100;
	return RGB(red, green, blue);
}

void printColor(COLORREF color) {
  printf("(r: %02d, g: %02d, b: %02d)\n", GetRValue(color), GetGValue(color), GetBValue(color));
}

void setPixel(int x, int y, COLORREF color) {
	HDC context = GetDC(WINDOW_HANDLE);
	SetPixel(context, y, x, color);
	ReleaseDC(WINDOW_HANDLE, context);
}

// void setPoint(int gridX, int gridY, COLORREF color) {
// 	int rowStart = gridX * POINT_WIDTH;
// 	int colStart = gridY * POINT_WIDTH;
// 	for (int row = rowStart; row < rowStart + POINT_WIDTH; row++) {
// 		for (int col = colStart; col < colStart + POINT_WIDTH; col++) {
// 			setPixel(row, col, color);
// 			// printf("(%d, %d) ", row, col);
// 		}
// 	}
// }

HBITMAP loadImage(const char* filePath) {
	return (HBITMAP)LoadImage(NULL, filePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void loadBMP(HDC context, HDC memdc, HBITMAP image) {
   BITMAP bitmap;
   HDC bitmapDC = CreateCompatibleDC(context);

   GetObject(image, sizeof(bitmap), &bitmap);
   SelectObject(bitmapDC, image);
   BitBlt(memdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, bitmapDC, 0, 0, SRCCOPY);

   DeleteDC(bitmapDC);
}

void drawImage(int x, int y, HBITMAP image, int height, int width) {
	HDC context = GetDC(WINDOW_HANDLE);
	HDC memdc = CreateCompatibleDC(context);
	HBITMAP bitmap = CreateCompatibleBitmap(context, width, height);

	SelectObject(memdc, bitmap);

	loadBMP(context, memdc, image);

	StretchBlt(context, x, y, width, height, memdc, 0, 0, width, height, SRCCOPY);

	DeleteDC(memdc);
	DeleteObject(bitmap);
	ReleaseDC(WINDOW_HANDLE, context);
}
