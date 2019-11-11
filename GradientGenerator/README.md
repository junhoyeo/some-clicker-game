# GradientGenerator
[스택오버플로우](https://stackoverflow.com/questions/3080421/javascript-color-gradient#answer-32257791)에 소개된 `generateColor` 함수의 C 구현체

## 예시 코드

```c
Gradient testGradient = createGradient(hexToColor(0x84FAB0), hexToColor(0x8FD3F4));
testGradient.getColors(&testGradient, 15);
for(int i = 0; i < 15; i++)
  printColor(testGradient.colors[i]);
```
