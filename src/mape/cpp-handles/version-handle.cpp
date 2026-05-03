/*
 * mape - C4 Landscape.txt editor
 *
 * Copyright (c) 2005-2009, Armin Burgmeier
 */

#include "C4Version.h"
#include "mape/cpp-handles/version-handle.h"

extern "C" {

const char* c4_version_get()
{
  return C4VERSION;
}

} /* extern "C" */
