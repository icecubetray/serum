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


#include "./state.h"




FILEID("MT-safe state object.");




ls_result_t
ls_state_init_ex(ls_state_t *const state, const unsigned int value) {
	if (state == NULL) {
		ls_debug("NULL encountered.");
		return_e(LS_E_NULL);
	}

	const ls_result_t result = ls_mutex_init(&state->__lock);
	if (result != LS_E_SUCCESS) {
		return result;
	}

#if (LS_PTHREADS)
	if (pthread_cond_init(&state->__cond, NULL) != 0) {
		return_e(LS_E_FAILURE);
	}
#elif (LS_WTHREADS)
#	error TODO
#else
	LS_COMPILER_LOG("State unsupported.");
	return_e(LS_E_UNSUPPORTED);
#endif

	state->value = value;
	return LS_E_SUCCESS;
}

ls_result_t
ls_state_init(ls_state_t *const state) {
	return ls_state_init_ex(state, 0);
}


ls_result_t
ls_state_clear(ls_state_t *const state) {
	if (state == NULL) {
		ls_debug("NULL encountered.");
		return_e(LS_E_NULL);
	}

	const ls_result_t result = ls_mutex_clear(&state->__lock);
	if (result != LS_E_SUCCESS) {
		return result;
	}

#if (LS_PTHREADS)
	if (pthread_cond_destroy(&state->__cond) != 0) {
		return_e(LS_E_FAILURE);
	}
#elif (LS_WTHREADS)
#	error TODO
#else
	return_e(LS_E_UNSUPPORTED);
#endif

	state->value = 0;
	return LS_E_SUCCESS;
}




ls_result_t
ls_state_set(ls_state_t *const state, const unsigned int value) {
	if (state == NULL) {
		ls_debug("NULL encountered.");
		return_e(LS_E_NULL);
	}

	LS_MUTEX_ACQUIRE_OR_ERROR(&state->__lock);
	state->value = value;
	LS_MUTEX_RELEASE_OR_ERROR(&state->__lock);

	return LS_E_SUCCESS;
}


ls_result_t
ls_state_get(ls_state_t *const restrict state, unsigned int *const restrict value) {
	if (state == NULL) {
		ls_debug("NULL encountered.");
		return_e(LS_E_NULL);
	}

	LS_MUTEX_ACQUIRE_OR_ERROR(&state->__lock);
	const unsigned int val = state->value;
	LS_MUTEX_RELEASE_OR_ERROR(&state->__lock);

	*value = val;
	return LS_E_SUCCESS;
}
