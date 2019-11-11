#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "Init.h"
#include "Mouse.h"
#include "Utils.h"
#include "Draw.h"
#include "Resources.h"
#include "GradientGenerator/GradientGenerator.h"

Mouse createMouse() {
	Mouse mouse = MOUSE;
	mouse.updatePosition(&mouse);
	return mouse;
}

int main() {
	initWindow();

	Mouse mouse = createMouse();

	printf("w: %3d, h: %3d\n", WINDOW_WIDTH, WINDOW_HEIGHT);

	HBITMAP testBmp = loadImage(TEST_IMAGE);
	drawImage(WINDOW_WIDTH / 2 - 35, WINDOW_HEIGHT / 2 - 32, testBmp, 70, 65);

	gotoxy(0, 5);
	Gradient testGradient = createGradient(hexToColor(0x84FAB0), hexToColor(0x8FD3F4));
	testGradient.getColors(&testGradient, 15);
	for(int i = 0; i < 15; i++)
		printColor(testGradient.colors[i]);

	while(1) {
		gotoxy(0, 1);
		mouse.updatePosition(&mouse);
		printf("x: %3d, y: %3d\n", mouse.x, mouse.y);
		Sleep(50);
	}
}
