/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 *
 *
 *
 */
// user-customizable multimedia package Extra.ocg

#ifndef INC_C4Extra
#define INC_C4Extra

#include "c4group/C4Group.h"

class C4Extra
{
public:
	C4Extra();
	~C4Extra();

	bool Init();      // init extra group, using scneario presets
	bool InitGroup(); // open extra group

	std::vector<std::unique_ptr<C4Group>> ExtraGroups; // extra.ocg root folders

protected:
	bool LoadDef(C4Group &hGroup, const char *szName); // load preset for definition
};

#endif
