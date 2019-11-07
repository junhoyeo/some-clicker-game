## Init.h
화면을 초기화합니다.

### updateHandles
콘솔 입출력 핸들과, 윈도우 핸들을 업데이트합니다.

### hideConsoleCursor
콘솔 커서를 숨깁니다.

### disableConsoleResize
사용자가 직접 콘솔 윈도우 크기를 변경하지 못하도록 합니다.

### disableConsoleSelection
Quick Edit mode를 비활성화해서, 클릭해도 텍스트가 선택되지 않도록 합니다.

### resizeConsole
주어진 `height`와 `width`만큼 콘솔 윈도우의 크기를 변경합니다.

### updateColor
`fontColor`와 `bgColor`에 주어진 오프셋을 이용해서 폰트 색과 배경 색을 변경합니다.

### initWindow
위에 있는 함수들을 순차적으로 실행합니다. `SCREEN_HEIGHT`, `SCREEN_WIDTH`로 윈도우 크기를 조정합니다.
배경색을 흰색으로, 텍스트 색을 검정색으로 설정한 뒤 `system("cls")`를 이용해 화면을 지우기 때문에, 흰색 배경으로 스크린이 초기화되게 됩니다.

```c
#include "Init.h"

#define SCREEN_HEIGHT 50
#define SCREEN_WIDTH 60

int main() {
  initWindow();
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
