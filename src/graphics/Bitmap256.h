/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 1998-2000, Matthes Bender
 * Copyright (c) 2009-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* A structure for handling 256-color bitmap files */

#ifndef BITMAP256_H_INC
#define BITMAP256_H_INC

#ifdef _WIN32
#include "platform/C4windowswrapper.h"
#else
#pragma pack(push,2)
typedef struct tagBITMAPFILEHEADER
{
	WORD  bfType;
	DWORD bfSize;
	WORD  bfReserved1;
	WORD  bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#pragma pack(pop)
typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize;
	int32_t biWidth;
	int32_t biHeight;
	WORD  biPlanes;
	WORD  biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	int32_t biXPelsPerMeter;
	int32_t biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;
typedef struct tagRGBQUAD
{
	BYTE  rgbBlue;
	BYTE  rgbGreen;
	BYTE  rgbRed;
	BYTE  rgbReserved;
} RGBQUAD,*LPRGBQUAD;
#endif

#pragma pack( push, def_pack , 1)

class C4BMPInfo
{
public:
	void Default();
public:
	BITMAPFILEHEADER Head = BITMAPFILEHEADER();
	BITMAPINFOHEADER Info = BITMAPINFOHEADER();
	void Set(int iWdt, int iHgt, int iBitDepth);

	int FileBitsOffset();
};

class C4BMP256Info : public C4BMPInfo
{
public:
	RGBQUAD Colors[256] = {};
public:
	void Default();
	void Set(int iWdt, int iHgt, CStdPalette *);
	bool Valid();

	int FileBitsOffset();
};

#pragma pack( pop, def_pack )

#endif // BITMAP256_H_INC
