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

#ifndef __LS_CORE_RESULT_H
#define __LS_CORE_RESULT_H


#include <stdint.h>

#include "./bool.h"


typedef struct ls_result {		// bitrg
	uint32_t system : 1;	// 00-01
	uint32_t critical : 1;	// 01-02
	uint32_t _reserved1 : 6;	// 02-08

	uint32_t code : 16;	// 08-24

	uint32_t param : 4;	// 24-28
	uint32_t _reserved2 : 3;	// 28-31
	uint32_t success : 1;	// 31-32
} ls_result_t;


#define LS_RESULT_PRINTF_FORMAT				"sys=%c crit=%c code=%u param=%u success=%c"
#define LS_RESULT_PRINTF_PARAMS(result)		((result).system ? 'y' : 'n'),((result).critical ? 'y' : 'n'),((result).code),((result).param),((result).success ? 'y' : 'n')
#define LS_RESULT_PRINTF(result)			printf(LS_RESULT_PRINTF_FORMAT"\n", LS_RESULT_PRINTF_PARAMS(result))


#define LS_RESULT_CODE_SUCCESS				0x0000	// Success, no error
#define LS_RESULT_CODE_NULL					0x0001	// Null pointer
#define LS_RESULT_CODE_MISC					0x0002	// Misc. error
#define LS_RESULT_CODE_SIZE					0x0003	// Size invalid
#define LS_RESULT_CODE_ACCESS				0x0004	// Access denied
#define LS_RESULT_CODE_DESCRIPTOR			0x0005	// File/socket descriptor invalid
#define LS_RESULT_CODE_ALLOCATION			0x0006	// Allocation failure
#define LS_RESULT_CODE_EARLY_EXIT			0x0007	// Early exit (e.g. of a read operation)
#define LS_RESULT_CODE_LOCK					0x0008	// Lock failure
#define LS_RESULT_CODE_UNSUPPORTED			0x0009	// Unsupported operation
#define LS_RESULT_CODE_DATA					0x000A	// Data invalid
#define LS_RESULT_CODE_FUNCTION				0x000B	// Function execution within function failed
#define LS_RESULT_CODE_CLOSE				0x000C	// Close failure
#define LS_RESULT_CODE_INITIALIZATION		0x000D	// Initialization failure
#define LS_RESULT_CODE_TIMEOUT				0x000E	// Operation timed-out
#define LS_RESULT_CODE_CHECK				0x000F	// Check failure
#define LS_RESULT_CODE_WRITE				0x0010	// Write failure
#define LS_RESULT_CODE_READ					0x0011	// Read failure
#define LS_RESULT_CODE_INDEX				0x0012	// Index invalid


#define LS_RESULT_SA(_system, _critical, _code, _param, _success)	\
	((ls_result_t){							\
		.system		= (!!(_system)),		\
		.critical	= (!!(_critical)),		\
		._reserved1	= 0,					\
		.code		= (_code),				\
		.param		= (_param),				\
		._reserved2	= 0,					\
		.success	= (!!(_success))		\
	})

#if DEBUG
#	include "../debug/log.h"
static ls_result_t LS_ATTR_USED __LS_RESULT_PRINT(ls_result_t ret, char const *const func, char const *const file, uint32_t const line) {
	_ls_logf(func, file, line, "%08X (" LS_RESULT_PRINTF_FORMAT ")", (*(uint32_t*)(&ret)), LS_RESULT_PRINTF_PARAMS(ret));
	return ret;
}
#	define LS_RESULT(_system, _critical, _code, _param, _success)	\
	__LS_RESULT_PRINT(LS_RESULT_SA(_system, _critical, _code, _param, _success), __func__, FILE_PATH, __LINE__)
#else
#	define LS_RESULT						LS_RESULT_SA
#endif

#define LS_RESULT_SUCCESS_CODE(code)		LS_RESULT(true, false, (code), 0      , true )
#define LS_RESULT_SUCCESS					LS_RESULT_SUCCESS_CODE(LS_RESULT_CODE_SUCCESS)
#define LS_RESULT_ERROR(code)				LS_RESULT(true, false, (code), 0      , false)
#define LS_RESULT_ERROR_PARAM(code,param)	LS_RESULT(true, false, (code), (param), false)
#define LS_RESULT_ERROR_CRIT(code)			LS_RESULT(true, true , (code), 0      , false)
#define LS_RESULT_ERROR_CRIT_PARAM(code,param) \
											LS_RESULT(true, true , (code), (param),false)

#define LS_RESULT_CHECK_NULL(var, param)	if (!(var)) { return LS_RESULT_ERROR_PARAM(LS_RESULT_CODE_NULL, (param)); }
#define LS_RESULT_CHECK_SIZE(var, param)	if (!(var)) { return LS_RESULT_ERROR_PARAM(LS_RESULT_CODE_SIZE, (param)); }

#define LS_RESULT_CHECK_INDEX(var, param, lti, gti)	\
											if (((var) < (lti)) || ((var) > (gti))) { return LS_RESULT_ERROR_PARAM(LS_RESULT_CODE_INDEX, (param)); }


#endif
