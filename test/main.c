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

#define FILE_PATH "main.c"

#include <libserum/core/stdincl.h>
#include <libserum/debug/log.h>
#include <libserum/debug/memdump.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include <libserum/core/time.h>
#include <libserum/crypto/symmetric/rijndael.h>
#include <libserum/crypto/symmetric/modes/cbc.h>


int main(int argc, char *argv[], char *env[]) {
	register unsigned int i;
	for (i = 0; i < 64; ++i) {
		printf("%02u %02u\n", LS_MATH_ROUND_BLOCK_INCL(16, i), LS_MATH_ROUND_BLOCK_EXCL(16, i));
	}

	uint8_t key[32];
	memset(key, 0xF0, sizeof(key));

	ls_rijndael_t rijndael;
	if (!ls_rijndael_init(&rijndael, key, sizeof(key)).success) {
		return 1;
	}

	ls_cbc_t cbc;
	ls_cbc_init(&cbc, 16, &rijndael, ls_rijndael_encrypt_block, ls_rijndael_decrypt_block);


	uint8_t block[16];
	memset(block, 0x69, sizeof(block));

	uint8_t iv[16];
	memset(iv, 0xBA, sizeof(iv));

	puts("old:");
	ls_memdump(block, sizeof(block));
	for (i = sizeof(iv); i--;) {
		block[i] = (block[i] ^ iv[i]);
	}
	ls_rijndael_encrypt_block(&rijndael, (void*)block);

	ls_memdump(block, sizeof(block));

	ls_rijndael_decrypt_block(&rijndael, (void*)block);
	for (i = sizeof(iv); i--;) {
		block[i] = (block[i] ^ iv[i]);
	}

	ls_memdump(block, sizeof(block));

	puts("\nnew:");
	ls_memdump(block, sizeof(block));
	ls_cbc_encrypt(&cbc, block);
	ls_memdump(block, sizeof(block));
	memcpy(cbc.xor, cbc.iv, cbc.block_size);
	ls_cbc_decrypt(&cbc, block);
	ls_memdump(block, sizeof(block));

	if (!ls_rijndael_clear(&rijndael).success) {
		return 4;
	}

	fgetc(stdin);
	return 0;
}
