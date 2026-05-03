/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* Network-safe random number generator */

#include "C4Include.h"
#include "lib/C4Random.h"

#include <random>

#include <pcg/pcg_random.hpp>

int RandomCount = 0;

static pcg32 SeededRng()
{
	pcg_extras::seed_seq_from<std::random_device> seed_source;
	return pcg32(seed_source);
}

static pcg32 RandomRng, UnsyncedRandomRng = SeededRng();

void FixedRandom(uint64_t seed)
{
	RandomRng.seed(seed);
	RandomCount = 0;
}

uint32_t Random()
{
	uint32_t result = RandomRng();
	RecordRandom(UINT32_MAX, result);
	return result;
}

uint32_t Random(uint32_t iRange)
{
	if (!iRange) return 0u;
	uint32_t result = RandomRng(iRange);
	RecordRandom(iRange, result);
	return result;
}

uint32_t UnsyncedRandom()
{
	return UnsyncedRandomRng();
}

uint32_t UnsyncedRandom(uint32_t iRange)
{
	if (!iRange) return 0u;
	return UnsyncedRandomRng(iRange);
}

uint32_t SeededRandom(uint64_t iSeed, uint32_t iRange)
{
	if (!iRange) return 0;
	pcg32 rng(iSeed);
	return rng(iRange);
}

