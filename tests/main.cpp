/*
 * PLAnova, http://www.planova.org
 *
 * This file is ineligible for copyright and therefore in the public domain,
 * because it does not reach the required threshold of originality.
 *
 *
 * for the above reference.
 */

/* Runs all available tests. */

#include <gtest/gtest.h>

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
