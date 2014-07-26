/*
 * This file is part of Kugaru.
 *
 * Copyright (C) 2003, 2010 - Wolfire Games
 * Copyright (C) 2014 Victor A. Santos
 *
 * Kugaru is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Kugaru is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Kugaru.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef WINDEFS_H
#define WINDEFS_H
#ifdef WIN32


#include <stdio.h>
#include <float.h>

// disable warnings about double to float conversions
#pragma warning(disable:4305)
#pragma warning(disable:4244)

// disable warnings about boolean to int conversions
#pragma warning(disable:4800)

// disable warning about unreferenced local variables
#pragma warning(disable:4101)

typedef bool Boolean;


struct Point
{
	short v;
	short h;
};

typedef signed char SInt8;
typedef unsigned int UInt32;


#include "Random.h"


void CopyCStringToPascal( const char* src, unsigned char dst[256]);
void CopyPascalStringToC( const unsigned char* src, char* dst);


typedef struct AbsoluteTime
{
    unsigned long   hi;
    unsigned long   lo;
} AbsoluteTime;

AbsoluteTime UpTime();		// NOTE: returns time since app started, not system start

typedef long Duration;

enum
{
    durationMicrosecond             = -1,
    durationMillisecond             = 1,
    durationSecond                  = 1000,
    durationMinute                  = 1000 * 60,
    durationHour                    = 1000 * 60 * 60,
    durationDay                     = 1000 * 60 * 60 * 24,
    durationForever                 = 0x7FFFFFFF,
    durationImmediate               = 0,
};

Duration AbsoluteDeltaToDuration( AbsoluteTime& a, AbsoluteTime& b);


inline bool isnormal( double x)
{
	int ret = _fpclass( x);
	return (ret == _FPCLASS_NN || ret == _FPCLASS_PN);
}

typedef unsigned int uintptr_t;


// fix file names to use '/' instead of ':'
char* ConvertFileName( const char* orgfilename);
char* ConvertFileName( const char* orgfilename, const char* junk);


#define fopen( a, b) fopen( ConvertFileName( a), b);

inline float abs( float f)
{
	if (f < 0)
		return -f;
	return f;
}

inline double abs( double f)
{
	if (f < 0)
		return -f;
	return f;
}


#endif
#endif
