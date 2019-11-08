#pragma once

#ifndef _BITMAP_LOADER_IMPL_
#define _BITMAP_LOADER_IMPL_

#include <stdbool.h>
#include <Windows.h>
#include "BitmapLoaderIntf.h"

bool _bitmap_initialize(Bitmap* self, const char *filePath) {
    FILE *filePointer = fopen(filePath, "rb");

    if(filePointer) {
        // 초기화
        self = malloc(sizeof(Bitmap));
        self->width = 0;
        self->height = 0;
        self->pixels = NULL;

        // 파일 헤더를 읽음
        unsigned char fileHeader[54] = {0};
        fread(fileHeader, sizeof(unsigned char), 54, filePointer);

        // 파일 헤더에서 높이, 넓이를 가져옴
        self->height = *(unsigned int *) & fileHeader[22];
        self->width = *(unsigned int *) & fileHeader[18];
        printf("im.height: %d, im.width: %d\n", self->height, self->width);

        // 파일 크기 계산 (1픽셀은 R, G, B의 3바이트)
        unsigned int size = 3 * self->width * self->height;

        // 파일 크기대로 메모리 할당
        self->pixels = malloc(size);

        // 픽셀 불러오기
        fread(self->pixels, sizeof(unsigned char), size, filePointer);

        // 파일 포인터 해제
        fclose(filePointer);

        for(unsigned int i = 0; i < size; i += 3) {
          unsigned char tmp = self->pixels[i];
          self->pixels[i] = self->pixels[i + 2];
          self->pixels[i + 2] = tmp;
        }

        return true;
    }
    return false;
}

COLORREF _bitmap_getPixel(Bitmap* self, int x, int y) {
    int offset = (x * self->width + y);
    return RGB(
        self->pixels[3 * offset],
        self->pixels[3 * offset + 1],
        self->pixels[3 * offset + 2],
    );
}

void _bitmap_terminate(Bitmap* self) {
    if(self) {
        self->width = 0;
        self->height = 0;

        if (self->pixels)
            free(self->pixels);
    }
}

#endif
