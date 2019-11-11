#pragma once

#include <Windows.h>
#include "GradientGeneratorIntf.h"

void _gradient_initialize(Gradient* self, COLORREF startColor, COLORREF endColor) {
  self->startColor = startColor;
  self->endColor = endColor;
}

void _gradient_getColors(Gradient* self, int size) {
  self->colors = malloc(size);
  int start[3] = {
    GetRValue(self->startColor),
    GetGValue(self->startColor),
    GetBValue(self->startColor),
  };
  int end[3] = {
    GetRValue(self->endColor),
    GetGValue(self->endColor),
    GetBValue(self->endColor),
  };
  float alpha = 0.0;

  for(int i = 0; i < size; i++) {
    alpha += (1.0 / size);
		int red = (int)(start[0] * alpha + (1 - alpha) * end[0]);
		int green = (int)(start[1] * alpha + (1 - alpha) * end[1]);
		int blue = (int)(start[2] * alpha + (1 - alpha) * end[2]);
    self->colors[i] = RGB(red, green, blue);
  }
}
