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

#define FILE_PATH							"core/exit.c"

#include "./exit.h"
#include <stdio.h>
#include <stdarg.h>


ID("abnormal termination routines");


void
ls_fatal_ex(const char *func, const char *file, ls_nword_t line, ls_nword_t exit_code, const char *fmt, ...) {
	va_list vl;
	va_start(vl, fmt);

	fputs(
		"A fatal error occured in libserum. This usually means a\n"
		"critical condition was met and the most sensible option\n"
		"was to terminate completely.\n\n", stderr
	);

	if (func || file || line) {
		fprintf(stderr,
			"    Function: %s\n"
			"    File: %s\n"
			"    Line: %u\n\n",
			(func ? func : "unspecified"),
			(file ? file : "unspecified"),
			line
		);
	}

	if (fmt) {
		fputs("Message:\n    ", stderr);
		vfprintf(stderr, fmt, vl);
	}

	fputs("\n", stderr);

	exit(64 | (exit_code & 0x3F));
}
