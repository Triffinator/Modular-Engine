#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <memory>
#include <functional>

// Types

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::array;
using std::vector;
using std::map;
using std::function;

typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

// Inline Functions

#define TYPEID(T)					(typeid(T).hash_code())

#define __SAFE_DELETE(p, func)	\
	if (p != NULL)				\
	{							\
		func;					\
		(p) = NULL;				\
	}

template<typename T> inline void SAFE_DELETE(T*& p) { __SAFE_DELETE(p, delete p) }
template<typename T> inline void SAFE_DELETE_ARRAY(T*& p) { __SAFE_DELETE(p, delete[] p) }
template<typename T> inline void SAFE_FREE(T*& p) { __SAFE_DELETE(p, free(p)) }
template<typename T> inline void SAFE_CLOSE(T*& p) { __SAFE_DELETE(p, fclose(p)) }

#define __ZEROMEM(Destination, Length) \
	memset((Destination), 0, (Length))

template<typename T> inline void ZEROMEM(T*& p) { __ZEROMEM(p, sizeof(*p)); }
template<typename T> inline void ZEROMEM_ARRAY(T& p) { __ZEROMEM(p, sizeof(p)); }
template<typename T> inline void ZEROMEM_REF(T& p) { __ZEROMEM(&p, sizeof(p)); }

template<typename T> inline T MIN(const T& x, const T& y)
{
    return x < y ? x : y;
}
template<typename T> inline T MAX(const T& x, const T& y)
{
    return x > y ? x : y;
}

template<typename T> inline T CLAMP(const T& v, const T& min, const T& max)
{
    return (v > max) ? max : ((v < min) ? min : v);
}

template<typename T> inline T& CLAMP_S(T& v, const T& min, const T& max)
{
    return (v > max) ? (v = max) : ((v < min) ? (v = min) : v);
}