#pragma once

#ifndef _BITMAP_LOADER_INTF_
#define _BITMAP_LOADER_INTF_

#include <stdbool.h>
#include <Windows.h>

typedef struct _Bitmap {
	unsigned int width, height;
	unsigned char* pixels;

	bool (*initialize)(struct _Bitmap*, const char *);
	COLORREF (*getPixel)(struct _Bitmap*, int, int);
	void (*terminate)(struct _BItmap*);
} Bitmap;

#endif
