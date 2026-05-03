/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2012-2016, The PLAnova Team and contributors
 */

// Do not include C4Include.h - this file tests whether
// c4script.h is useable without that.
#include "../../include/c4script/c4script.h"

#include <cstdio>
#include <cstring>
#include <getopt.h>

int usage(const char *argv0)
{
	fprintf(stderr, "Usage:\n%s -e <script>\n%s <file>\n", argv0, argv0);
	return 1;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return usage(argv[0]);

	bool check = false;
	char *runstring = nullptr;

	while (true)
	{
		static option long_options[] =
		{
			{"check", no_argument, nullptr, 'c'},
			{"execute", required_argument, nullptr, 'e'},
			{nullptr, 0, nullptr, 0}
		};

		int option_index;
		int c = getopt_long(argc, argv, "ce:", long_options, &option_index);
		if (c == -1) break;
		switch (c)
		{
		case 'c':
			check = true;
			break;
		case 'e':
			runstring = optarg;
			break;
		default:
			return usage(argv[0]);
		}
	}

	if (runstring)
	{
		if (argc - optind != 0)
			return usage(argv[0]);
		if (check)
			return c4s_checkstring(runstring);
		else
			return c4s_runstring(runstring);
	}
	else
	{
		if (argc - optind != 1)
			return usage(argv[0]);
		if (check)
			return c4s_checkfile(argv[optind]);
		else
			return c4s_runfile(argv[optind]);
	}
}
