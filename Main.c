#include <stdio.h>
#include "Init.h"
#include "Mouse.h"

Mouse createMouse() {
	Mouse mouse = MOUSE;
	mouse.updatePosition(&mouse);
	return mouse;
}

int main() {
	initWindow();

	Mouse mouse = createMouse();

	while(1) {
		mouse.updatePosition(&mouse);
		printf("x: %d, y: %d\n", mouse.x, mouse.y);
		Sleep(50);
		system("cls");
	}
}
