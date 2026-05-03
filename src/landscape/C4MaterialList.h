/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* A primitive list to store one amount value per mapped material */

#ifndef INC_C4MaterialList
#define INC_C4MaterialList

#include "landscape/C4Landscape.h"

class C4MaterialList
{
public:
	C4MaterialList();
	~C4MaterialList();
public:
	int32_t Amount[C4MaxMaterial];
public:
	void Default();
	void Clear();
	void Reset();
	int32_t Get(int32_t iMaterial);
	void Add(int32_t iMaterial, int32_t iAmount);
	void Set(int32_t iMaterial, int32_t iAmount);
};

#endif // INC_C4MaterialList
