/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 *
 *
 *
 */
/* Implemention of NewGfx - without gfx */

#ifndef INC_StdNoGfx
#define INC_StdNoGfx

#include "graphics/C4Draw.h"

class CStdNoGfx : public C4Draw
{
public:
	CStdNoGfx();
	bool UpdateClipper() override { return true; }
	bool OnResolutionChanged(unsigned int, unsigned int) override { return true; }
	bool PrepareMaterial(StdMeshMatManager& mat_manager, StdMeshMaterialLoader& loader, StdMeshMaterial& mat) override;
	bool PrepareRendering(C4Surface *) override { return true; }
	bool EnsureMainContextSelected() override { return true; }
	bool PrepareSpriteShader(C4Shader& shader, const char* name, int ssc, C4GroupSet* pGroups, const char* const* additionalDefines, const char* const* additionalSlices) override { return true; }
	void FillBG(DWORD dwClr=0) override { }
	void PerformMesh(StdMeshInstance &, float, float, float, float, DWORD, C4BltTransform* pTransform) override { }
	bool RestoreDeviceObjects() override;
	bool InvalidateDeviceObjects() override { return true; }
	bool DeviceReady() override { return true; }

	void PerformMultiPix(C4Surface *, const C4BltVertex *, unsigned int, C4ShaderCall*) override {}
	void PerformMultiLines(C4Surface *, const C4BltVertex *, unsigned int, float, C4ShaderCall*) override {}
	void PerformMultiTris(C4Surface *, const C4BltVertex *, unsigned int, const C4BltTransform *, C4TexRef *, C4TexRef *, C4TexRef *, DWORD, C4ShaderCall*) override {}
};

#endif
