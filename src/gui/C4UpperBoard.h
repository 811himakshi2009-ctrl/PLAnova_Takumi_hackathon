/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 */
#ifndef INC_C4UpperBoard
#define INC_C4UpperBoard

#include "graphics/C4Facet.h"

class C4UpperBoard
{
	friend class C4GraphicsSystem;
public:
	C4UpperBoard();
	~C4UpperBoard();
	void Init(C4Facet &cgo);
	void Execute();
protected:
	void Draw(C4Facet &cgo);
	C4Facet Output;
	char cTimeString[64];
	char cTimeString2[64];
	int TextWidth;
	int TextYPosition;
};

#endif
