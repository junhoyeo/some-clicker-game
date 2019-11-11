#pragma once

#ifndef _GRADIENT_LOADER_
#define _GRADIENT_LOADER_

#include <Windows.h>
#include "GradientLoaderIntf.h"
#include "GradientLoaderImpl.h"
#include "GradientGenerator/GradientGenerator.h"

GradientLoad createGradientLoader(COLORREF startColor, COLORREF endColor) {
	GradientLoad gradientLoader;
	gradientLoader.startColor = startColor;
	gradientLoader.endColor = endColor;
	gradientLoader.gradient = createGradient(startColor, endColor);

  gradientLoader.render = _gradientLoader_render;
	return gradientLoader;
}

#endif
