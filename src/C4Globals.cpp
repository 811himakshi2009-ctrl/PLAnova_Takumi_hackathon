/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* Global interdependent objects */

#include "C4Include.h"
#include "game/C4Application.h"
#include "script/C4Aul.h"
#include "editor/C4Console.h"
#include "object/C4DefList.h"
#include "game/C4FullScreen.h"
#include "game/C4GraphicsSystem.h"
#include "game/C4Game.h"
#include "object/C4GameObjects.h"
#include "c4group/C4LangStringTable.h"
#include "gui/C4MouseControl.h"
#include "network/C4Network2.h"
#include "script/C4PropList.h"
#include "script/C4StringTable.h"

#ifdef _DEBUG
C4Set<C4PropList *> C4PropList::PropLists;
#endif
C4Set<C4PropListNumbered *> C4PropListNumbered::PropLists;
C4Set<C4PropListScript *> C4PropListScript::PropLists;
std::vector<C4PropListNumbered *> C4PropListNumbered::ShelvedPropLists;
int32_t C4PropListNumbered::EnumerationIndex = 0;
C4LangStringTable C4LangStringTable::system_string_table;
C4StringTable  Strings;
C4AulScriptEngine ScriptEngine;
C4Application  Application;
C4Console      Console;
C4FullScreen   FullScreen;
C4MouseControl MouseControl;
C4GameObjects  Objects;
C4DefList      Definitions;
// make sure C4Game reference members are initialized before Game because otherwise they're acccessed in C4Game::Default before initialization
C4GraphicsSystem GraphicsSystem;
C4Game         Game;
C4Network2     Network;

