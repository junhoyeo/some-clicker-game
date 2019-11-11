#pragma once

#ifndef _GRADIENT_GENERATOR_INF_
#define _GRADIENT_GENERATOR_INF_

#include <Windows.h>

typedef struct _Gradient {
  COLORREF startColor, endColor;
	COLORREF* colors;

	// void (*initialize)(struct _Gradient*, COLORREF, COLORREF);
	void (*getColors)(struct _Gradient*, int);
} Gradient;

#endif
