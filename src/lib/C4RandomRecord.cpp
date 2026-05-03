/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 */

#include "C4Include.h"
#include "lib/C4Random.h"
#include "control/C4Record.h"

void RecordRandom(uint32_t range, uint32_t val)
{
	RandomCount++;
	if (Config.General.DebugRec)
	{
		// next pseudorandom value
		C4RCRandom rc;
		rc.Cnt=RandomCount;
		rc.Range=range;
		rc.Val=val;
		AddDbgRec(RCT_Random, &rc, sizeof(rc));
	}
}
