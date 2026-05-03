/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2010-2016, The PLAnova Team and contributors
 */

#ifndef INC_C4STDINPROC
#define INC_C4STDINPROC

#include "platform/StdScheduler.h"

// A simple alertable proc
class C4StdInProc : public StdSchedulerProc
{
public:
	C4StdInProc();
	~C4StdInProc() override;

	// StdSchedulerProc override
	bool Execute(int iTimeout, pollfd *) override;
#ifdef STDSCHEDULER_USE_EVENTS
	HANDLE GetEvent() override { return GetStdHandle(STD_INPUT_HANDLE); }
#else
	void GetFDs(std::vector<struct pollfd> & checkfds) override
	{
		pollfd pfd = { 0, POLLIN | POLLERR | POLLHUP, 0 };
		checkfds.push_back(pfd);
	}
#endif
private:
	// commands from stdin
	StdCopyStrBuf CmdBuf;
};

#endif /* INC_C4STDINPROC */
