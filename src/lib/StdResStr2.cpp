/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2010-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* Load strings from a primitive memory string table */

#include "C4Include.h"

const int ResStrMaxLen = 4096;
static char strResult[ResStrMaxLen + 1];
const char *LoadResStrNoAmp(const char *id)
{
	const char * str = LoadResStr(id);
	char * cpd = strResult;
	for (const char * cps = str; *cps; ++cps, ++cpd)
	{
		if (*cps == '&')
			--cpd;
		else
			*cpd = *cps;
	}
	*cpd = 0;
	return strResult;
}
