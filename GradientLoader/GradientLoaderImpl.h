#pragma once

#ifndef _GRADIENT_LOADER_IMPL_
#define _GRADIENT_LOADER_IMPL_

#include <Windows.h>
#include "GradientGenerator/GradientGenerator.h"
#include "GradientLoaderIntf.h"
#include "Draw.h"

void _gradientLoader_render(GradientLoad* self, int x, int y, int height, int width, int size) {
	HDC context = GetDC(WINDOW_HANDLE);
  int rectHeight = (int)(height / size);
	self->gradient.getColors(&self->gradient, size);

  for(int i = 0; i < size; i++) {
    HBRUSH brush = CreateSolidBrush(self->gradient.colors[i]);
    renderRect(context, brush, x, y + (rectHeight * i), rectHeight, width);
  }
	ReleaseDC(WINDOW_HANDLE, context);
}

#endif
