#pragma once

#ifndef _BITMAP_LOADER_
#define _BITMAP_LOADER_

#include "BitmapLoaderIntf.h"
#include "BitmapLoaderImpl.h"

Bitmap DEFAULT_BITMAP = {
  0, 0,
  NULL,
  _bitmap_initialize,
  _bitmap_getPixel,
  _bitmap_terminate,
};

#endif
