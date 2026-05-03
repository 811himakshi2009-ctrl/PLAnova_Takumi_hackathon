/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* Some old constants and references */

#ifndef INC_C4Physics
#define INC_C4Physics

const int StableRange=10;
const int AttachRange=5;
const int CornerRange=AttachRange+2;

#define GravAccel ::Landscape.GetGravity()

extern const C4Real HitSpeed1,HitSpeed2,HitSpeed3,HitSpeed4;
extern const C4Real FloatFriction;
extern const C4Real RotateAccel;
extern const C4Real DefaultGravAccel;

#endif
