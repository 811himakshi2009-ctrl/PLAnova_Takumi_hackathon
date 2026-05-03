/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2012-2016, The PLAnova Team and contributors
 *
 *
 *
 */
/* Interface to a UPnP port mapper */

#ifndef INC_C4Network2Upnp
#define INC_C4Network2Upnp

#include "network/C4Network2IO.h"

class C4Network2UPnP
{
	class C4Network2UPnPP *p;
public:
	C4Network2UPnP();
	//noncopyable
	C4Network2UPnP(const C4Network2UPnP&) = delete;
	C4Network2UPnP& operator=(const C4Network2UPnP&) = delete;
	~C4Network2UPnP();

	void AddMapping(enum C4Network2IOProtocol protocol, uint16_t intport, uint16_t extport);
	void ClearMappings();
};

#endif
