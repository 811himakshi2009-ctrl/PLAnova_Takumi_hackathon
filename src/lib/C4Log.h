/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* Log file handling */

#ifndef INC_C4Log
#define INC_C4Log

bool OpenLog();
bool OpenExtraLogs();
bool CloseLog();

bool Log(const char *szMessage);
bool LogSilent(const char *szMessage);
bool LogF(const char *strMessage, ...) GNUC_FORMAT_ATTRIBUTE;
bool LogSilentF(const char *strMessage, ...) GNUC_FORMAT_ATTRIBUTE;
bool DebugLog(const char *strMessage);
bool DebugLogF(const char *strMessage ...) GNUC_FORMAT_ATTRIBUTE;
bool ShaderLog(const char *strMessage);
bool ShaderLogF(const char *strMessage ...) GNUC_FORMAT_ATTRIBUTE;

bool LogFatal(const char *szMessage); // log message and store it as a fatal error
void ResetFatalError();               // clear any fatal error message
const char *GetFatalError();          // return message that was set as fatal error, if any

size_t GetLogPos(); // get current log position;
bool GetLogSection(size_t iStart, size_t iLength, StdStrBuf &rsOut); // re-read log data from file

// Used to print a backtrace after a crash
int GetLogFD();

#endif
