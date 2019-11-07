#include <stdio.h>
#include "Init.h"
#include "Mouse.h"
#include "Utils.h"

Mouse createMouse() {
	Mouse mouse = MOUSE;
	mouse.updatePosition(&mouse);
	return mouse;
}

int main() {
	initWindow();

	Mouse mouse = createMouse();

	printf("w: %3d, h: %3d\n", WINDOW_WIDTH, WINDOW_HEIGHT);

	while(1) {
		gotoxy(0, 1);
		mouse.updatePosition(&mouse);
		printf("x: %3d, y: %3d\n", mouse.x, mouse.y);
		Sleep(50);
	}
}
