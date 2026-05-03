/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2011-2016, The PLAnova Team and contributors
 */
#include "C4Include.h"
#include "graphics/C4DrawT.h"
#include "lib/StdMeshMaterial.h"

CStdNoGfx::CStdNoGfx()
{
	Default();
}

bool CStdNoGfx::RestoreDeviceObjects()
{
	Log("Graphics disabled.");
	MaxTexSize = 2147483647;
	return true;
}

bool CStdNoGfx::PrepareMaterial(StdMeshMatManager& mat_manager, StdMeshMaterialLoader& loader, StdMeshMaterial& mat)
{
	mat.BestTechniqueIndex=0; return true;
}
