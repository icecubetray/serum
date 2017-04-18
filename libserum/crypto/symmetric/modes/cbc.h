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

#ifndef __LS_CRYPTO_SYMMETRIC_MODES_CBC_H
#define __LS_CRYPTO_SYMMETRIC_MODES_CBC_H


#include "../../../core/stdincl.h"
#include "../../../core/math.h"
#include "../rijndael.h"


typedef struct ls_cbc {
	uint8_t iv[16];
	uint8_t xor[16];
	void *cipher_data;
	ls_result_t(*cipher_encrypt)(void *data, void *block);
	ls_result_t(*cipher_decrypt)(void *data, void *block);
	size_t block_size;
} ls_cbc_t;

#ifdef __cplusplus
extern "C" {
#endif

	LSAPI ls_result_t ls_cbc_init(ls_cbc_t *cbc, size_t block_size, void *cipher_data, ls_result_t(*cipher_encrypt)(void *data, void *block), ls_result_t(*cipher_decrypt)(void *data, void *block));

	LSAPI ls_result_t ls_cbc_encrypt(ls_cbc_t *cbc, uint8_t *block);
	LSAPI ls_result_t ls_cbc_decrypt(ls_cbc_t *cbc, uint8_t *block);

#ifdef __cplusplus
}
#endif


#endif