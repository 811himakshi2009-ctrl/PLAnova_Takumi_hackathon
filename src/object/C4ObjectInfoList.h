/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* Dynamic list for crew member info */

#ifndef INC_C4ObjectInfoList
#define INC_C4ObjectInfoList

#include "object/C4Id.h"

class C4ObjectInfoList
{
public:
	C4ObjectInfoList();
	~C4ObjectInfoList();
protected:
	C4ObjectInfo *First;
public:
	int32_t iNumCreated; // number of new defs created during this round
public:
	void Default();
	void Clear();
	void Evaluate();
	void DetachFromObjects();
	int32_t Load(C4Group &hGroup);
	bool Add(C4ObjectInfo *pInfo);
	bool Save(C4Group &hGroup, bool fSavegame, bool fStoreTiny, C4DefList *pDefs);
	C4ObjectInfo* New(C4ID n_id, C4DefList *pDefs);
	C4ObjectInfo* GetIdle(C4ID c_id, C4DefList &rDefs);
	C4ObjectInfo* GetIdle(const char *szByName);
	C4ObjectInfo *GetFirst() { return First; }
	bool IsElement(C4ObjectInfo *pInfo);
	void Strip(C4DefList &rDefs);
public:
	void MakeValidName(char *sName);
	bool NameExists(const char *szName);
protected:
	C4ObjectInfo *GetLast();
	C4ObjectInfo *GetPrevious(C4ObjectInfo *pInfo);
};


#endif
