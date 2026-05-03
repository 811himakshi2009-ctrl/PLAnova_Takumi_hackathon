/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2013, The PLAnova Team and contributors
 *
 *
 *
 */

#include <C4Include.h>
#include "script/C4StringTable.h"

#include <gtest/gtest.h>

TEST(C4StringTableTest, SanityTests)
{
	EXPECT_FALSE(Strings.FindString("Apfelmus"));
	C4String * str = Strings.RegString("Apfelmus");
	ASSERT_TRUE(str);
	EXPECT_TRUE(Strings.FindString("Apfelmus"));
	str->IncRef();
	str->DecRef();
	EXPECT_FALSE(Strings.FindString("Apfelmus"));
}

class C4ValueNumbers;
class C4PropList;
class C4AulFunc;
class C4Object;
class C4ValueArray;
class C4Def;
class C4Effect;
struct C4AulParSet;
class C4AulScriptFunc;
#include "script/C4Value.h"

TEST(C4StringTableTest, ComparisonOperators)
{
	C4String * str1 = Strings.RegString("Käsebrot");
	C4String * str2 = Strings.RegString("Apfelmus");
	C4Value v1(str1);
	C4Value v2(str2);
	C4Value v3(str1);
	EXPECT_NE(v1, v2);
	EXPECT_EQ(v1, v3);
}
