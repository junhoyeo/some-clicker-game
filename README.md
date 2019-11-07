## Init.h
화면을 초기화합니다.

```c
#include <stdio.h>

int main() {
  initWindow();
  // SCREEN_HEIGHT, SCREEN_WIDTH로 윈도우 크기를 조정
  // 흰색 배경으로 스크린이 초기화됨
}
```

## Utils.h

### gotoxy
커셔를 원하는 위치로 이동시킵니다.

```c
#include <stdio.h>
#include "Utils.h"

int main() {
  gotoxy(0, 0);
  printf("hello");
}
```

## Mouse.h

```c
#include <stdio.h>
#include "Mouse.h"
#include "Utils.h"

Mouse createMouse() {
  Mouse mouse = MOUSE;
  mouse.updatePosition(&mouse);
  return mouse;
}

int main() {
  Mouse mouse = createMouse();
  // 마우스 객체 생성

  while(1) {
    gotoxy(0, 0);
    mouse.updatePosition(&mouse);
    // 마우스 위치 업데이트

    printf("x: %d, y: %d\n", mouse.x, mouse.y);
    // 변경된 x, y좌표 확인

    Sleep(50);
  }
}
```
