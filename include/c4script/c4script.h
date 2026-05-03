/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2012-2016, The PLAnova Team and contributors
 */

#ifndef C4SCRIPTSTANDALONE_H
#define C4SCRIPTSTANDALONE_H

#ifdef __cplusplus
extern "C" {
#endif

int c4s_runfile(const char *filename);
int c4s_runstring(const char *script);

int c4s_checkfile(const char *filename);
int c4s_checkstring(const char *script);

#ifdef __cplusplus
}
#endif

#endif // C4SCRIPTSTANDALONE_H
