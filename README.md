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

## ~~[deprecated] updatePointWidth~~
[BitmapLoader](./BitmapLoader) 문서를 참고하세요.

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

## Draw.h
픽셀 따위를 화면에 그립니다.

## hexToColor
16진수 컬러 코드 `hex`를 받아 `COLORREF`로 변환합니다.

## setPixel
`(x, y)`에 `color`의 색을 가진 픽셀을 표시합니다.

```c
#include <stdio.h>
#include "Draw.h"

int main() {
  for(int h = 0; h < 10; h++)
    for(int w = 0; w < 10; w++)
      setPixel(10 + h, 100 + w, hexToColor(0x7F00FF));
}
```

## ~~[deprecated] setPoint~~
[BitmapLoader](./BitmapLoader) 문서를 참고하세요.

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
