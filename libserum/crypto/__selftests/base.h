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


#ifndef __LS_CRYPTO_SELFTESTS_BASE_H
#define __LS_CRYPTO_SELFTESTS_BASE_H




#include "../../core/setup.h"




#ifdef __cplusplus
extern "C" {
#endif

	/*!
	 * \brief lscst_set_logging
	 * \param enabled
	 */
	LSAPI void lscst_set_logging(const ls_bool_t enabled);

	/*!
	 * \brief lscst_launch
	 * \return
	 */
	LSAPI ls_result_t lscst_launch(void);

	/*!
	 * \brief lscst_log
	 * \param result
	 * \param algorithm
	 * \param index
	 * \param source
	 * \param data_expected
	 * \param data_found
	 * \param data_size
	 */
	LSAPI void lscst_log(const ls_result_t result, const char *const algorithm, const size_t index, const char *const source, const uint8_t *const data_expected, const uint8_t *const data_found, const size_t data_size);

#ifdef __cplusplus
}
#endif




#endif
