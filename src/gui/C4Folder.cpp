/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 */

/* Core component of a folder */

#include "C4Include.h"
#include "gui/C4Folder.h"

#include "c4group/C4Group.h"
#include "c4group/C4Components.h"


//================= C4FolderHead ====================

void C4FolderHead::Default()
{
	Index = 0;
}

void C4FolderHead::CompileFunc(StdCompiler *pComp)
{
	pComp->Value(mkNamingAdapt(Index,                     "Index",                0));
}

//=================== C4Folder ======================

C4Folder::C4Folder()
{
	Default();
}

void C4Folder::Default()
{
	Head.Default();
}

bool C4Folder::Load(C4Group &hGroup)
{
	char *pSource;
	// Load
	if (!hGroup.LoadEntry(C4CFN_FolderCore, &pSource, nullptr, 1)) return false;
	// Compile
	if (!Compile(pSource)) { delete [] pSource; return false; }
	delete [] pSource;
	// Success
	return true;
}

void C4Folder::CompileFunc(StdCompiler *pComp)
{
	pComp->Value(mkNamingAdapt(Head, "Head"));
}

bool C4Folder::Compile(const char *szSource)
{
	Default();
	return CompileFromBuf_LogWarn<StdCompilerINIRead>(*this, StdStrBuf(szSource), C4CFN_FolderCore);
}

