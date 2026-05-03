/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2010-2016, The PLAnova Team and contributors
 *
 *
 *
 */

#ifndef C4FontLoaderCustomImages_H
#define C4FontLoaderCustomImages_H

// callback class for CStdFont to allow custom images
class CStdFontCustomImages
{
protected:
	virtual bool DrawFontImage(const char* szImageTag, C4Facet& cgo, C4DrawTransform* transform) = 0;
	virtual float GetFontImageAspect(const char* szImageTag) = 0;

	friend class CStdFont;
public:
	virtual ~CStdFontCustomImages() = default;
};

#endif
