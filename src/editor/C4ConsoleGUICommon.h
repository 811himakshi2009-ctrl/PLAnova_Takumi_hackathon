/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2005, Günther Brammer
 * Copyright (c) 2010-2016, The PLAnova Team and contributors
 *
 *
 *
 */

// To be directly included by platform-specific implementations

C4ConsoleGUI::C4ConsoleGUI()
{
	state = new C4ConsoleGUI::State(this);
}

C4ConsoleGUI::~C4ConsoleGUI() {delete state;}

#define DEFINE_STANDARD_DLG_METHODS(cls)\
cls::cls()\
{\
	state = new cls::State(this);\
	Default();\
}\
\
cls::~cls()\
{\
	Clear();\
	delete state;\
}\

DEFINE_STANDARD_DLG_METHODS(C4ToolsDlg)

void C4ToolsDlg::Clear()
{
	state->Clear();
	Console.ToolsDlgClose();
	Active = false;
}

void C4ToolsDlg::Default()
{
	Active = false;
	Tool = SelectedTool = C4TLS_Brush;
	Grade = C4TLS_GradeDefault;
	ModeIFT = true;
	SCopy("Earth",Material);
	SCopy("earth",Texture);
	ModeBack = false;
	SCopy("Tunnel", BackMaterial);
	SCopy("tunnel", BackTexture);
	state->Default();
}
