/*
* PLAnova, http://www.planova.org
*
* Copyright (c) 2016, The PLAnova Team and contributors
*/

#ifndef INC_ErrorHandler
#define INC_ErrorHandler

#include "script/C4Aul.h"
#include <gmock/gmock.h>

class ErrorHandler : public C4AulErrorHandler
{
public:
	ErrorHandler()
	{
		::ScriptEngine.RegisterErrorHandler(this);
	}
	MOCK_METHOD1(OnError, void(const char*));
	MOCK_METHOD1(OnWarning, void(const char*));
};

#endif
