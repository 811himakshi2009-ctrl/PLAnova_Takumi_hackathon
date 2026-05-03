/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 *
 * Licensed under the ISC license.
 */

/* This header is included first from every source file. It serves three purposes:
   - PlatformAbstraction.h
   - Common utility functionality that's used everywhere
   - Speeding up the compilation by precompiling this header
All of our headers are designed to be used with C4Include.h included before and
don't need to include this file or any of the files it includes. */

#ifndef INC_C4Include
#define INC_C4Include

#include "platform/PlatformAbstraction.h"

constexpr bool DEBUGREC_SCRIPT = true;
constexpr int DEBUGREC_START_FRAME = 0;
constexpr bool DEBUGREC_PXS = true;
constexpr bool DEBUGREC_MATSCAN = true;
constexpr bool DEBUGREC_MENU = true;
constexpr bool DEBUGREC_OCF = true;
constexpr bool DEBUGREC_RECRUITMENT = false;

// solidmask debugging
constexpr bool SOLIDMASK_DEBUG = false;

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <math.h>

#include "C4Prototypes.h"
#include "lib/C4Log.h"
#include "lib/C4Real.h"
#include "lib/Standard.h"
#include "lib/StdBuf.h"
#include "platform/StdFile.h"

#include "c4group/C4Language.h"
#include "config/C4Config.h"
#include "config/C4Reloc.h"
#include "game/C4Game.h"

#endif // INC_C4Include
