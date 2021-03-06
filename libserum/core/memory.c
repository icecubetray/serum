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


#include "./memory.h"

#include <string.h>
#include <inttypes.h>




FILEID("Memory-related routines.");




static const char fmt_normal[] = "%0*"PRIXPTR": ";
static const char fmt_ansi[] = "\033[0;36m%0*"PRIXPTR"\033[0m: \033[0;37m";


ls_result_t
ls_memory_dump_ex(const void *const src, const size_t size, const unsigned int columns, const unsigned int columnsize, FILE *const dest, const ls_bool_t ansi) {
#if (LS_SANITY)
	if (src == NULL || dest == NULL) {
		return_e(LS_E_NULL);
	}

	if (size < 1) {
		return_e(LS_E_NOOP);
	}

	if (columns < 1 || columnsize < 1) {
		return_e(LS_E_INVALID);
	}
#endif


	const uint8_t *src8 = src;
	const char *const pfmt = (ansi ? fmt_ansi : fmt_normal);
	const size_t pfmt_sz = ((sizeof(void*) << 1) + (ansi ? 18 : 0) + 2);

	ls_result_t result = LS_E_SUCCESS;


	size_t i, word, column;
	for (i = size, word = column = 0; i--;) {
		if (column == 0) {
			if ((size_t)fprintf(dest, pfmt, (int)(sizeof(void*) << 1), (uintptr_t)src8) != pfmt_sz) {
				result = LS_E_IO_WRITE;
				break;
			}
		}

		if (fprintf(dest, "%02X", *src8++) != 2) {
			// We expect to write 2 characters, and we're strict about this.
			result = LS_E_IO_WRITE;
			break;
		}

		if (++word == columnsize) {
			word = 0;

			if (++column == columns) {
				column = 0;

				if (fputs(LS_EOL, dest) == EOF) {
					result = LS_E_IO_WRITE;
					break;
				}
			} else {
				if (fputs(" ", dest) == EOF) {
					result = LS_E_IO_WRITE;
					break;
				}
			}
		}
	}


	if (ansi && fputs("\033[0m", dest) == EOF) {
		return_e(LS_E_IO_WRITE);
	}

	if (word != 0 || column != 0) {
		if (fputs(LS_EOL, dest) == EOF) {
			return_e(LS_E_IO_WRITE);
		}
	}

	if (fflush(dest) != 0) {
		return_e(LS_E_IO_FLUSH);
	}


	return result;
}


ls_result_t
ls_memory_dump(const void *const src, const size_t size) {
	return ls_memory_dump_ex(src, size, 16, 1, stdout, true);
}




char*
ls_memory_to_c_array(const void *const data, const size_t size) {
	// 6: '0xXX, ', 2: '{ ', 1: '\0'
	char *const str = malloc((6 * size) + 2 + 1), *strp = str;
	if (str == NULL) {
		return NULL;
	}

	strcpy(strp, "{ ");
	strp += 2;

	register size_t i;
	const uint8_t *const ptr = data;
	for (i = 0; i < size; ++i) {
		if (i > 0) {
			strcpy(strp, ", ");
			strp += 2;
		}

		snprintf(strp, (4 + 1), "0x%02X", ptr[i]);
		strp += 4;
	}

	strcpy(strp, " }");
	strp = NULL;

	return str;
}




void*
ls_memory_free(void *const target) {
	if (target != NULL) {
		free(target);
	}
	return NULL;
}


void
ls_memory_clear(volatile void *const target, const size_t size) {
	if (target && size) {
		memset((void*)target, 0x00, size);
		*(volatile char *const)target = *(volatile char *const)target;
	}
}


void*
ls_memory_clear_free(volatile void *const target, const size_t size) {
	ls_memory_clear(target, size);
	return ls_memory_free((void *const)target);
}
