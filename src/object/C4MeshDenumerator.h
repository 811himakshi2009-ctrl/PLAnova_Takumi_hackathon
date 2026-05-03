/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 */

#ifndef INC_C4MeshDenumerator
#define INC_C4MeshDenumerator

#include "lib/StdMesh.h"
#include "object/C4ObjectPtr.h"

// Helper struct to serialize an object's mesh instance with other object's mesh instances attached
class C4MeshDenumerator : public StdMeshInstance::AttachedMesh::Denumerator
{
private:
	C4Def* Def{nullptr}; // Set if a definition mesh was attached
	C4ObjectPtr Object; // Set if an instance mesh was attached

public:
	C4MeshDenumerator(): Object(nullptr) {}
	C4MeshDenumerator(C4Def* def): Def(def), Object(nullptr) {}
	C4MeshDenumerator(C4Object* object): Def(nullptr), Object(object) {}

	C4Object* GetObject() { return Object; }

	void CompileFunc(StdCompiler* pComp, StdMeshInstance::AttachedMesh* attach) override;
	void DenumeratePointers(StdMeshInstance::AttachedMesh* attach) override;
	bool ClearPointers(C4Object* pObj) override;
};

extern const StdMeshInstance::AttachedMesh::DenumeratorFactoryFunc C4MeshDenumeratorFactory;

#endif
