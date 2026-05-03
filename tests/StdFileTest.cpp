/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2019, The PLAnova Team and contributors
 *
 *
 *
 */

#include <C4Include.h>
#include "platform/StdFile.h"

#include <gtest/gtest.h>

TEST(StdFileTest, IsWildcardStringTest)
{
	EXPECT_TRUE(IsWildcardString("ab*cde"));
	EXPECT_TRUE(IsWildcardString("abcd?e"));
	EXPECT_TRUE(IsWildcardString("[abc]de"));
	EXPECT_FALSE(IsWildcardString("foobar"));
}

TEST(StdFileTest, WildcardMatchTest)
{
	EXPECT_TRUE(WildcardMatch("abc*", "abcdefg"));
	EXPECT_FALSE(WildcardMatch("abc*", "Xabcdefg"));
	EXPECT_TRUE(WildcardMatch("a?c*g", "abcdefg"));
	EXPECT_TRUE(WildcardMatch("a[1-9]?", "a5b"));
	EXPECT_TRUE(WildcardMatch("a[abc][A-Z]", "acX"));
	EXPECT_TRUE(WildcardMatch("[[]", "["));
	EXPECT_TRUE(WildcardMatch("[[-]", "-"));
}
