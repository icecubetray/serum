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


#include "./hash_registry.h"

#include "./hashing/md5.h"
#include "./selftests/hashing/md5.h"




FILEID("Registry of hash functions.");




const struct lsreg_hash __hash_registry[] = {
	{ /* Fill up 0th index. */ },
	{
		.meta = {
			.selftest = (lssig_cst_case)lscst_hashing_md5min,
			.flags = 0,
			.name = "MD5",
			.maintainer = "icecubetray"
		},

		.ctx_size = sizeof(struct ls_md5_data),
		.block_size = LS_MD5_BLOCK_SIZE,
		.digest_size = LS_MD5_DIGEST_SIZE,

		.init = (lssig_hash_init)ls_md5_init,
		.clear = NULL,
		.update = (lssig_hash_update)ls_md5_update,
		.finish = (lssig_hash_finish)ls_md5_finish
	}
};

const size_t __hash_registry_size = sizeof(__hash_registry);
const size_t __hash_registry_count = (sizeof(__hash_registry) / sizeof(*__hash_registry));
