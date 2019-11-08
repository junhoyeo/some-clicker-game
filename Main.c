#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include "Init.h"
#include "Mouse.h"
#include "Utils.h"
#include "Draw.h"
#include "Resources.h"

Mouse createMouse() {
	Mouse mouse = MOUSE;
	mouse.updatePosition(&mouse);
	return mouse;
}

int main() {
	initWindow();

	Mouse mouse = createMouse();

	// int height, width;
	// readBMP(TEST_IMAGE, width, height);
	// printf("iw: %d, ih: %d\n", width, height);

	printf("w: %3d, h: %3d\n", WINDOW_WIDTH, WINDOW_HEIGHT);
	setPoint(0, 0, hexToColor(0x7F00FF));
	setPoint(0, 1, hexToColor(0x0000FF));

	// for(int h = 0; h < 10; h++) {
	// 	for(int w = 0; w < 10; w++)
	// 		setPixel(10 + h, 100 + w, hexToColor(0x7F00FF));
	// }

	while(1) {
	//  gotoxy(0, 1);
	// 	mouse.updatePosition(&mouse);
	// 	printf("x: %3d, y: %3d\n", mouse.x, mouse.y);
		Sleep(50);
	}
}
