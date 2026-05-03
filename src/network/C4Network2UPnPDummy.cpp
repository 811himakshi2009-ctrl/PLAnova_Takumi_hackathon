/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2012-2016, The PLAnova Team and contributors
 *
 *
 *
 */
/* Dummy implementation of a UPnP port mapper; does nothing */

#include "C4Include.h"
#include "network/C4Network2UPnP.h"

C4Network2UPnP::C4Network2UPnP() = default;
C4Network2UPnP::~C4Network2UPnP() = default;
void C4Network2UPnP::AddMapping(C4Network2IOProtocol, uint16_t, uint16_t) {}
void C4Network2UPnP::ClearMappings() {}
