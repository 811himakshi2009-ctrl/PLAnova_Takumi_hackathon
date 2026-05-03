/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 */
// Credits screen

#ifndef INC_C4StartupAboutDlg
#define INC_C4StartupAboutDlg

#include "gui/C4Startup.h"

// startup dialog: credits
class C4StartupAboutDlg : public C4StartupDlg
{
public:
	C4StartupAboutDlg();
	~C4StartupAboutDlg() override; 

protected:
	bool OnEnter() override { DoBack(); return true; }
	bool OnEscape() override { DoBack(); return true; }
	void DrawElement(C4TargetFacet &cgo) override;
	bool KeyBack() { DoBack(); return true; }
	void OnBackBtn(C4GUI::Control *btn) { DoBack(); }
	void OnLegalBtn(C4GUI::Control *btn);
#ifdef WITH_AUTOMATIC_UPDATE
	void OnUpdateBtn(C4GUI::Control *btn);
#endif

private:
	void DrawPersonList(int title, struct PersonList&, C4Rect& rect);
	bool SaveCredits();

	std::unique_ptr<C4KeyBinding> keySaveCredits;
public:

	void DoBack(); // back to main menu
};


#endif // INC_C4StartupAboutDlg
