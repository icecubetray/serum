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


#ifndef __LS_CRYPTO_SELFTESTS_ASSERT_H
#define __LS_CRYPTO_SELFTESTS_ASSERT_H
#if (LS_EXPORTING)




#include "../../core/setup.h"

#include "../hash.h"




#ifdef __cplusplus
extern "C" {
#endif

	/*!
	 * \brief lscst_hash_assert
	 * \param algorithm
	 * \param data
	 * \param data_size
	 * \param iterations
	 * \param digest
	 * \param out_digest
	 * \param digest_size
	 * \return
	 */
	LSAPI ls_result_t lscst_hash_assert(ls_crypto_algo_t algorithm, const uint8_t *const restrict data, const size_t data_size, const size_t iterations, const uint8_t *const restrict digest, uint8_t *const restrict out_digest, const size_t digest_size);

#ifdef __cplusplus
}
#endif




#endif
#endif
