#pragma once

#ifndef _GRADIENT_GENERATOR_
#define _GRADIENT_GENERATOR_

#include <Windows.h>
#include "GradientGeneratorIntf.h"
#include "GradientGeneratorImpl.h"

Gradient createGradient(COLORREF startColor, COLORREF endColor) {
	Gradient gradient;
	gradient.startColor = startColor;
	gradient.endColor = endColor;
	gradient.colors = NULL;
	gradient.getColors = _gradient_getColors;
	return gradient;
}

#endif
