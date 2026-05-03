/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 */

/* Core component of a folder */

#ifndef INC_C4Folder
#define INC_C4Folder

class C4FolderHead
{
public:
	int32_t Index;                      // Folder index in scenario selection dialog
public:
	void Default();
	void CompileFunc(StdCompiler *pComp);
};

class C4Folder
{
public:
	C4Folder();
public:
	C4FolderHead Head;
public:
	void Default();
	bool Load(C4Group &hGroup);
	void CompileFunc(StdCompiler *pComp);
protected:
	bool Compile(const char *szSource);
};

#endif // INC_C4Folder
