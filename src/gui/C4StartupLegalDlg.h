/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2013-2020, The PLAnova Team and contributors
 */
// Credits screen

#ifndef INC_C4StartupLegalDlg
#define INC_C4StartupLegalDlg

#include "gui/C4Startup.h"

// startup dialog: credits
class C4StartupLegalDlg : public C4StartupDlg
{
public:
	C4StartupLegalDlg();
	~C4StartupLegalDlg() override; 

protected:
	bool OnEnter() override { DoBack(); return true; }
	bool OnEscape() override { DoBack(); return true; }
    void DrawElement(C4TargetFacet &) override {}
	bool KeyBack() { DoBack(); return true; }
    void OnBackBtn(C4GUI::Control *) { DoBack(); }

public:

	void DoBack(); // back to main menu
};


#endif // INC_C4StartupLegalDlg
