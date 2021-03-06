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


#ifndef __LS_CORE_SETUP_PLATFORM_SETUP_H
#define __LS_CORE_SETUP_PLATFORM_SETUP_H




#include "./platform-detection.h"




#if (!LS_WINDOWS || LS_DOXYGEN)
#	/*! \hideinitializer \brief OS EOL sequence. */
#	define LS_EOL							"\n"
#	/*! \hideinitializer \brief OS EOL length. */
#	define LS_EOL_SIZE						1
#else
#	define LS_EOL							"\r\n"
#	define LS_EOL_SIZE						2
#endif

#if (LS_DOXYGEN)
#	/*! \brief Logs a compiler message (compiler dependent). */
#	define LS_COMPILER_LOG(mesg)
#
#	/*! \brief Attribute to mark for export (compiler dependent). */
#	define LS_EXPORT
#
#	/*! \brief Attribute to mark for import (compiler dependent). */
#	define LS_IMPORT
#
#	/*! \brief Attribute to prevent export (compiler dependent). */
#	define LS_INTERNAL
#
#	/*! \brief Attribute: nonnull (compiler dependent). */
#	define LS_ATTR_NONNULL
#
#	/*! \brief Attribute: nonnull (compiler dependent). */
#	define LS_ATTR_NONNULL_EX(...)
#
#	/*! \brief Attribute: pure (compiler dependent). */
#	define LS_ATTR_PURE
#
#	/*! \brief Attribute: const (compiler dependent). */
#	define LS_ATTR_CONST
#
#	/*! \brief Attribute: used (compiler dependent). */
#	define LS_ATTR_USED
#
#	/*! \brief Attribute: noreturn (compiler dependent). */
#	define LS_ATTR_NORETURN
#
#	/*! \brief Attribute: always_inline (compiler dependent). */
#	define LS_ATTR_FORCE_INLINE
#
#	/*! \brief Attribute: threadlocal (compiler dependent). */
#	define LS_ATTR_THREADLOCAL
#
#	/*! \brief Attribute/keyword: forced inline (compiler dependent). */
#	define LS_FORCE_INLINE
#elif (LS_GCC || LS_LLVM)
#	define __LS_ATTR(x)						__attribute__((x))
#
#	include "./macros.h"
#	define LS_COMPILER_LOG(mesg)			_Pragma(LS_MKSTR(message mesg))
#
#	define LS_EXPORT						__LS_ATTR(visibility("default"))
#	define LS_IMPORT
#	define LS_INTERNAL						__LS_ATTR(visibility("hidden"))
#
#	define LS_ATTR_NONNULL					__LS_ATTR(nonnull)
#	define LS_ATTR_NONNULL_EX(...)			__LS_ATTR(nonnull (__VA_ARGS__))
#	define LS_ATTR_PURE						__LS_ATTR(pure)
#	define LS_ATTR_CONST					__LS_ATTR(const)
#	define LS_ATTR_USED						__LS_ATTR(used)
#	define LS_ATTR_NORETURN					__LS_ATTR(noreturn)
#	define LS_ATTR_FORCE_INLINE				__LS_ATTR(always_inline)
#	define LS_ATTR_THREADLOCAL				__thread
#
#	define LS_FORCE_INLINE					inline LS_ATTR_FORCE_INLINE
#
#	define restrict							__restrict__
#elif (LS_MSC || LS_MINGW)
#	define __LS_ATTR(x)						__declspec(x)
#
#	define LS_COMPILER_LOG(mesg)			__pragma(message(mesg))
#
#	define LS_EXPORT						__LS_ATTR(dllexport)
#	define LS_IMPORT						__LS_ATTR(dllimport)
#	define LS_INTERNAL
#
#	define LS_ATTR_NONNULL
#	define LS_ATTR_NONNULL_EX(...)
#	define LS_ATTR_PURE
#	define LS_ATTR_CONST
#	define LS_ATTR_USED
#	define LS_ATTR_NORETURN					__LS_ATTR(noreturn)
#	define LS_ATTR_FORCE_INLINE				__forceinline
#	define LS_ATTR_THREADLOCAL				__LS_ATTR(thread)
#
#	define LS_FORCE_INLINE					LS_ATTR_FORCE_INLINE
#
#	define restrict							__restrict
#
#	include "./special-treatment-for-windows.h"
#elif (LS_TCC)
#	define __LS_ATTR(x)						__attribute__((x))
#
#	define LS_COMPILER_LOG(mesg)
#
#	if (LS_WINDOWS)
#		define LS_EXPORT					__LS_ATTR(dllexport)
#	else
#		define LS_EXPORT
#	endif
#	define LS_IMPORT
#	define LS_INTERNAL
#
#	define LS_ATTR_NONNULL
#	define LS_ATTR_NONNULL_EX(...)
#	define LS_ATTR_PURE						__LS_ATTR(pure)
#	define LS_ATTR_CONST
#	define LS_ATTR_USED						__LS_ATTR(used)
#	define LS_ATTR_NORETURN
#	define LS_ATTR_FORCE_INLINE				__always_inline
#	define LS_ATTR_THREADLOCAL				__LS_ATTR(__thread)
#
#	define LS_FORCE_INLINE					inline LS_ATTR_FORCE_INLINE
#
#	ifdef __cplusplus
#		define restrict						__restrict__
#	endif
#endif




#if (LS_INLINE_NOT_A_HINT)
#	define inline							LS_FORCE_INLINE
#endif




#endif
