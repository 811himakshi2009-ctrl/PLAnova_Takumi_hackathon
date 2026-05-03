/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2010-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* A convenient way to (de)serialize object pointers */

#ifndef INC_C4ObjectPtr
#define INC_C4ObjectPtr

// An enumerable C4Object pointer
class C4ObjectPtr
{
public:
	// For use with mkNamingAdapt because simply 0 becomes 0 (the int)
	// which makes correct template deduction fail. This constant is a
	// denumerated null pointer which can be repeatedly denumerated.
	static const C4ObjectPtr Null;

	C4ObjectPtr() = default; // uninitialized

	C4ObjectPtr(C4Object* pObj)
#ifndef NDEBUG
			: fDenumerated(true)
#endif
	{
		data.ptr = pObj;
	}

	void CompileFunc(StdCompiler* pComp);
	void DenumeratePointers();

	bool operator!() const { assert(fDenumerated); return !data.ptr; }
	bool operator==(C4Object* other) const { assert(fDenumerated); return data.ptr == other; }
	bool operator==(const C4ObjectPtr& other) const { assert(fDenumerated == other.fDenumerated); return data.ptr == other.data.ptr; }
	bool operator!=(C4Object* other) const { assert(fDenumerated); return data.ptr != other; }
	bool operator!=(const C4ObjectPtr& other) const { assert(fDenumerated == other.fDenumerated); return data.ptr != other.data.ptr; }

	C4ObjectPtr operator=(C4Object* object)
	{
#ifndef NDEBUG
		fDenumerated = true;
#endif
		data.ptr = object;
		return *this;
	}

	C4Object& operator*() const { assert(fDenumerated); return *data.ptr; }
	C4Object* operator->() const { assert(fDenumerated); return data.ptr; }
	operator C4Object*() const { assert(fDenumerated); return data.ptr; }

protected:
#ifndef NDEBUG
	bool fDenumerated;
#endif

	union
	{
		C4Object* ptr;
		intptr_t nptr; // needs to have same size as ptr for operator== to work when enumerated
	} data;
};

#endif
