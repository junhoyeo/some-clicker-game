#pragma once

#ifndef _GRADIENT_LOADER_INTF_
#define _GRADIENT_LOADER_INTF_

#include <Windows.h>
#include "GradientGenerator/GradientGenerator.h"

typedef struct _GradientLoad {
  COLORREF startColor, endColor;
  Gradient gradient;

	void (*render)(struct _GradientLoad*, int, int, int, int, int);
} GradientLoad;

#endif
