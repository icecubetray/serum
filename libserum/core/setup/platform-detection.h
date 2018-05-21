/******************************************************************************
**                                                                           **
**   The MIT License                                                         **
**                                                                           **
**   Copyright 2017-2018 icecubetray                                         **
**                                                                           **
**   Permission is hereby granted, free of charge, to any person             **
**   obtaining a copy of this software and associated documentation files    **
**   (the "Software"), to deal in the Software without restriction,          **
**   including without limitation the rights to use, copy, modify, merge,    **
**   publish, distribute, sublicense, and/or sell copies of the Software,    **
**   and to permit persons to whom the Software is furnished to do so,       **
**   subject to the following conditions:                                    **
**                                                                           **
**   The above copyright notice and this permission notice shall be          **
**   included in all copies or substantial portions of the Software.         **
**                                                                           **
**   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,         **
**   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF      **
**   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  **
**   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    **
**   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    **
**   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       **
**   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  **
**                                                                           **
******************************************************************************/


#ifndef __LS_CORE_SETUP_PLATFORM_DETECTION_H
#define __LS_CORE_SETUP_PLATFORM_DETECTION_H




#include <limits.h>

#ifdef CHAR_BIT
#	if (CHAR_BIT != 8)
#		error Currently only platforms with 8-bit characters are supported.
#	endif

#	define LS_BITS_BYTE						CHAR_BIT
#	define LS_BITS_WORD						(LS_BITS_BYTE << 1)
#	define LS_BITS_DWORD					(LS_BITS_BYTE << 2)
#	define LS_BITS_QWORD					(LS_BITS_BYTE << 3)
#else
#	error Missing preprocessor definition: CHAR_BIT
#endif




#define LS_ID_X86							1
#define LS_ID_X64							2
#define LS_ID_ARM							3

#ifndef LS_ID_ARCH
#	if (defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386))
#		define LS_ID_ARCH					LS_ID_X86
#	elif (defined(__amd64) || defined(__amd64__) || defined(__x86_64) || defined(__x86_64__) || defined(__ppc64__) || defined(_M_X64) || defined(_M_AMD64))
#		define LS_ID_ARCH					LS_ID_X64
#	elif (defined(__arm) || defined(__arm__) || defined(__thumb__) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__ARMCC_VERSION) || defined(__CC_ARM))
#		define LS_ID_ARCH					LS_ID_ARM

#		if (defined(__ARM_ARCH_2__))
#			define LS_ARCH_ARM_VERSION		2
#		elif (defined(__ARM_ARCH_3__))
#			define LS_ARCH_ARM_VERSION		3
#		elif (defined(__ARM_ARCH_4__))
#			define LS_ARCH_ARM_VERSION		4
#		elif (defined(__ARM_ARCH_5__))
#			define LS_ARCH_ARM_VERSION		5
#		elif (defined(__ARM_ARCH_6__))
#			define LS_ARCH_ARM_VERSION		6
#		elif (defined(__ARM_ARCH_7__))
#			define LS_ARCH_ARM_VERSION		7
#		elif (defined(__ARM_ARCH_8__))
#			define LS_ARCH_ARM_VERSION		8
#		elif (defined(__ARM_ARCH))
#			define LS_ARCH_ARM_VERSION		__ARM_ARCH
#		endif

#		if (defined(__aarch64__))
#			define LS_ARCH_BITS				64
#		else
#			define LS_ARCH_BITS				32
#		endif
#	endif
#endif

#if (LS_ID_ARCH == LS_ID_X86)
#	define LS_X86							1
#elif (LS_ID_ARCH == LS_ID_X64)
#	define LS_X64							1
#elif (LS_ID_ARCH == LS_ID_ARM)
#	define LS_ARM							1
#else
#	error Unknown architecture.
#endif




#define LS_ID_LINUX							1
#define LS_ID_WINDOWS						2
#define LS_ID_MAC							3

#ifndef LS_ID_OS
#	if (defined(__gnu_linux__) || defined(__linux__) || defined(linux))
#		define LS_ID_OS						LS_ID_LINUX
#	elif (defined(_WIN32))
#		define LS_ID_OS						LS_ID_WINDOWS
#	elif (defined(__APPLE__) && defined(__MACH__))
#		define LS_ID_OS						LS_ID_MAC
#	endif
#endif

#if (LS_ID_OS == LS_ID_LINUX)
#	define LS_LINUX							1
#elif (LS_ID_OS == LS_ID_WINDOWS)
#	define LS_WINDOWS						1
#elif (LS_ID_OS == LS_ID_MAC)
#	define LS_MAC							1
#else
#	error Unknown operating system.
#endif




#define LS_ID_LITTLE_ENDIAN					1
#define LS_ID_BIG_ENDIAN					2

#ifndef LS_ID_ENDIAN
#	if (defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__) || defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__))
#		define LS_ID_ENDIAN					LS_ID_BIG_ENDIAN
#	elif (defined(__BYTE_ORDER__))
#		if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#			define LS_ID_ENDIAN				LS_ID_BIG_ENDIAN
#		elif (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#			define LS_ID_ENDIAN				LS_ID_LITTLE_ENDIAN
#		else
#			error Unsupported endianness.
#		endif
#	else
#		define LS_ID_ENDIAN					LS_ID_LITTLE_ENDIAN
#	endif
#endif

#if (LS_ID_ENDIAN == LS_ID_BIG_ENDIAN)
#	define LS_BIG_ENDIAN					1
#elif (LS_ID_ENDIAN == LS_ID_LITTLE_ENDIAN)
#	define LS_LITTLE_ENDIAN					1
#else
#	error Unknown endianness.
#endif




#define LS_ID_GCC							1
#define LS_ID_LLVM							2
#define LS_ID_MSC							3
#define LS_ID_MINGW							4
#define LS_ID_TCC							5

#ifndef LS_ID_COMPILER
#	if (defined(__llvm__) || defined(__clang__))
#		define LS_ID_COMPILER				LS_ID_LLVM
#	elif (defined(__GNUC__))
#		define LS_ID_COMPILER				LS_ID_GCC
#	elif (defined(__MINGW32__))
#		define LS_ID_COMPILER				LS_ID_MINGW
#	elif (defined(_MSC_VER))
#		define LS_ID_COMPILER				LS_ID_MSC
#	elif (defined(__TINYC__))
#		define LS_ID_COMPILER				LS_ID_TCC
#	endif
#endif

#if ((LS_ID_COMPILER == LS_ID_GCC) || (LS_ID_COMPILER == LS_ID_LLVM))
#	if (LS_ID_COMPILER == LS_ID_GCC)
#		define LS_GCC						1
#	else
#		define LS_LLVM						1
#	endif
#elif (LS_ID_COMPILER == LS_ID_MINGW)
#	define LS_MINGW							1
#elif (LS_ID_COMPILER == LS_ID_MSC)
#	define LS_MSC							1
#elif (LS_ID_COMPILER == LS_ID_TCC)
#	define LS_TCC							1
#endif

#if (defined(_UCRT))
#	define LS_UCRT							1
#endif




#endif
