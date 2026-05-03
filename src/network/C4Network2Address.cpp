/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2010-2016, The PLAnova Team and contributors
 *
 *
 *
 */

#include "C4Include.h"
#include "network/C4Network2Address.h"

#ifndef _WIN32
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#endif

// *** C4Network2Address

void C4Network2Address::CompileFunc(StdCompiler *pComp)
{
	// Clear
	if (pComp->isDeserializer())
	{
		addr.Clear();
	}

	// Write protocol
	StdEnumEntry<C4Network2IOProtocol> Protocols[] =
	{
		{ "UDP", P_UDP },
		{ "TCP", P_TCP },

		{ nullptr, P_NONE },
	};
	pComp->Value(mkEnumAdaptT<uint8_t>(eProtocol, Protocols));
	pComp->Separator(StdCompiler::SEP_PART2); // ':'

	pComp->Value(mkDefaultAdapt(addr, C4NetIO::addr_t()));
}

StdStrBuf C4Network2Address::toString() const
{
	switch (eProtocol)
	{
	case P_UDP: return FormatString("UDP:%s", addr.ToString().getData());
	case P_TCP: return FormatString("TCP:%s", addr.ToString().getData());
	default:  return StdStrBuf("INVALID");
	}
}

bool C4Network2Address::operator == (const C4Network2Address &addr2) const
{
	return eProtocol == addr2.getProtocol() && addr == addr2.getAddr();
}


