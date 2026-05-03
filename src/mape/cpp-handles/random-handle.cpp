/*
 * mape - C4 Landscape.txt editor
 *
 * Copyright (c) 2005-2009, Armin Burgmeier
 */

#include "C4Include.h"
#include "lib/C4Random.h"
#include "mape/cpp-handles/random-handle.h"

extern "C" {

void c4_random_handle_seed(unsigned int seed)
{
  FixedRandom(seed);
}

} // extern "C"
