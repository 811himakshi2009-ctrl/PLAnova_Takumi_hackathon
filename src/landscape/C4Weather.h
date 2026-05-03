/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 */

/* Controls temperature, wind, and natural disasters */

#ifndef INC_C4Weather
#define INC_C4Weather

#include "landscape/C4Landscape.h"
class C4Weather
{
public:
	C4Weather();
	~C4Weather();
public:
	int32_t Season,YearSpeed,SeasonDelay;
	int32_t Wind,TargetWind;
	int32_t Temperature,TemperatureRange,Climate;
	int32_t NoGamma;
public:
	void Default();
	void Clear();
	void Execute();
	void SetClimate(int32_t iClimate);
	void SetSeason(int32_t iSeason);
	void SetTemperature(int32_t iTemperature);
	void Init(bool fScenario);
	void SetWind(int32_t iWind);
	int32_t GetWind(int32_t x, int32_t y);
	int32_t GetTemperature();
	int32_t GetSeason();
	int32_t GetClimate();
	void SetSeasonGamma();    // set gamma adjustment for season
	void CompileFunc(StdCompiler *pComp);
};
extern C4Weather Weather;

#endif
