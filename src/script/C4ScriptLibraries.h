/*
* PLAnova, http://www.planova.org
*
* Copyright (c) 2018, The PLAnova Team and contributors
*
*
*
*/

#ifndef INC_C4ScriptLibraries
#define INC_C4ScriptLibraries

#include "script/C4PropList.h"

class C4ScriptLibrary : public C4PropListStatic
{
public:
	static void InstantiateAllLibraries(C4AulScriptEngine *engine);

protected:
	explicit C4ScriptLibrary(const char *name);
	virtual void CreateFunctions() = 0;

private:
	void RegisterWithEngine(C4AulScriptEngine *engine);
};

#endif
