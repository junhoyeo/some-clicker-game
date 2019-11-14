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
#include "ImageLayer/ImageLayer.h"
// #include "GradientLoader/GradientLoader.h"

Mouse createMouse() {
	Mouse mouse = MOUSE;
	mouse.updatePosition(&mouse);
	return mouse;
}

int main() {
	// Sleep(100);
	initWindow();

	Mouse mouse = createMouse();

	ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
	imageLayer.initialize(&imageLayer);

	Image images[3] = {
		{PLAYER_1, WINDOW_WIDTH / 2 - 35, WINDOW_HEIGHT / 2 - 32, 5},
		{BUTTON_1, 0, WINDOW_HEIGHT - 30, 2},
		{BUTTON_2, 2, WINDOW_HEIGHT - 30, 2},
	};

	imageLayer.imageCount = 3;
	imageLayer.images = images;
	imageLayer.transparentColor = RGB(255, 63, 245);

	imageLayer.renderAll(&imageLayer);

	printf("w: %3d, h: %3d\n", WINDOW_WIDTH, WINDOW_HEIGHT);

	// GradientLoad testGradient = createGradientLoader(hexToColor(0x84FAB0), hexToColor(0x8FD3F4));
	// testGradient.render(&testGradient, 0, 0, WINDOW_HEIGHT, WINDOW_WIDTH, 25);

	// HBITMAP testBmp = loadImage(TEST_IMAGE);
	// drawImage(WINDOW_WIDTH / 2 - 35, WINDOW_HEIGHT / 2 - 32, testBmp, 70, 65);

	while(1) {
		gotoxy(0, 1);
		mouse.updatePosition(&mouse);
		printf("x: %3d, y: %3d\n", mouse.x, mouse.y);
		Sleep(50);
	}
}
