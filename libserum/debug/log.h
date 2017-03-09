/*******************************************************************************
**                                                                            **
**   The MIT License                                                          **
**                                                                            **
**   Copyright 2017 icecubetray                                               **
**                                                                            **
**   Permission is hereby granted, free of charge, to any person              **
**   obtaining a copy of this software and associated documentation files     **
**   (the "Software"), to deal in the Software without restriction,           **
**   including without limitation the rights to use, copy, modify, merge,     **
**   publish, distribute, sublicense, and/or sell copies of the Software,     **
**   and to permit persons to whom the Software is furnished to do so,        **
**   subject to the following conditions:                                     **
**                                                                            **
**   The above copyright notice and this permission notice shall be           **
**   included in all copies or substantial portions of the Software.          **
**                                                                            **
**   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          **
**   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       **
**   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   **
**   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY     **
**   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,     **
**   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE        **
**   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                   **
**                                                                            **
********************************************************************************
**
**  Notes:
**    -
**
*/

#ifndef __LS_DEBUG_LOG_H
#define __LS_DEBUG_LOG_H


#include "../core/integers.h"
#include "../core/lsapi.h"
#include "../core/identification.h"

#include "../core/errstr.h"

#include <stdarg.h>


#define ls_log_e(s)							ls_log(s)
#define ls_log_w(s)							ls_log(s)
#define ls_log_i(s)							ls_log(s)
#define ls_log_v(s)							ls_log(s)

#if DEBUG
#	define ls_log_d(s)						ls_log(s)
#else
#	define ls_log_d(s)
#endif


#ifdef __cplusplus
extern "C" {
#endif

	void ls_log(const char *const str);
	void ls_logf(const char *const fmt, ...);

#ifdef __cplusplus
}
#endif


#endif