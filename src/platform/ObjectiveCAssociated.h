/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2010-2016, The PLAnova Team and contributors
 */
 
#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

typedef
#ifdef __OBJC__
	id
#else
	void*
#endif
	ObjCPtr;

class ObjectiveCAssociated {
public:
	ObjCPtr _objectiveCObject;
public:
	ObjectiveCAssociated(): _objectiveCObject(nullptr) {}
#ifdef __OBJC__
	void setObjectiveCObject(id obj) { _objectiveCObject = obj; }
	template<class T> inline T* objectiveCObject() { return (T*)_objectiveCObject; }
#endif
};
