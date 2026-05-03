/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2015, The PLAnova Team and contributors
 */

/* Issue #1263: Drawing Line = 1 objects without vertices results in array OOB */

func Initialize()
{
	// Drawing this object should not crash
	var line = CreateObjectAbove(LineDummy, 100, 100, NO_OWNER);
}
